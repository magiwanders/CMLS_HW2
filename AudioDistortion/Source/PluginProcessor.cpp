/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin processor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
CMLS_HW2AudioProcessor::CMLS_HW2AudioProcessor()
#ifndef JucePlugin_PreferredChannelConfigurations
     : AudioProcessor (BusesProperties()
                     #if ! JucePlugin_IsMidiEffect
                      #if ! JucePlugin_IsSynth
                       .withInput  ("Input",  juce::AudioChannelSet::stereo(), true)
                      #endif
                       .withOutput ("Output", juce::AudioChannelSet::stereo(), true)
                     #endif
                       )
#endif
{
}

CMLS_HW2AudioProcessor::~CMLS_HW2AudioProcessor()
{
}

//==============================================================================
const juce::String CMLS_HW2AudioProcessor::getName() const
{
    return JucePlugin_Name;
}

bool CMLS_HW2AudioProcessor::acceptsMidi() const
{
   #if JucePlugin_WantsMidiInput
    return true;
   #else
    return false;
   #endif
}

bool CMLS_HW2AudioProcessor::producesMidi() const
{
   #if JucePlugin_ProducesMidiOutput
    return true;
   #else
    return false;
   #endif
}

bool CMLS_HW2AudioProcessor::isMidiEffect() const
{
   #if JucePlugin_IsMidiEffect
    return true;
   #else
    return false;
   #endif
}

double CMLS_HW2AudioProcessor::getTailLengthSeconds() const
{
    return 0.0;
}

int CMLS_HW2AudioProcessor::getNumPrograms()
{
    return 1;   // NB: some hosts don't cope very well if you tell them there are 0 programs,
                // so this should be at least 1, even if you're not really implementing programs.
}

int CMLS_HW2AudioProcessor::getCurrentProgram()
{
    return 0;
}

void CMLS_HW2AudioProcessor::setCurrentProgram (int index)
{
}

const juce::String CMLS_HW2AudioProcessor::getProgramName (int index)
{
    return {};
}

void CMLS_HW2AudioProcessor::changeProgramName (int index, const juce::String& newName)
{
}

//==============================================================================
void CMLS_HW2AudioProcessor::prepareToPlay (double sampleRate, int samplesPerBlock)
{
    // Low pass filter initialization
    // (one for each input channel)
    filters.clear();
    for (int i = 0; i < getTotalNumInputChannels(); ++i)
    {
        LowPassFilter* filter;
        filters.add (filter = new LowPassFilter());
    }
    updateFilters();
}

void CMLS_HW2AudioProcessor::releaseResources()
{
    // When playback stops, you can use this as an opportunity to free up any
    // spare memory, etc.
}

#ifndef JucePlugin_PreferredChannelConfigurations
bool CMLS_HW2AudioProcessor::isBusesLayoutSupported (const BusesLayout& layouts) const
{
  #if JucePlugin_IsMidiEffect
    juce::ignoreUnused (layouts);
    return true;
  #else
    // This is the place where you check if the layout is supported.
    // In this template code we only support mono or stereo.
    // Some plugin hosts, such as certain GarageBand versions, will only
    // load plugins that support stereo bus layouts.
    if (layouts.getMainOutputChannelSet() != juce::AudioChannelSet::mono()
     && layouts.getMainOutputChannelSet() != juce::AudioChannelSet::stereo())
        return false;

    // This checks if the input layout matches the output layout
   #if ! JucePlugin_IsSynth
    if (layouts.getMainOutputChannelSet() != layouts.getMainInputChannelSet())
        return false;
   #endif

    return true;
  #endif
}
#endif

void CMLS_HW2AudioProcessor::processBlock (juce::AudioBuffer<float>& buffer, juce::MidiBuffer& midiMessages)
{
    juce::ScopedNoDenormals noDenormals;
    auto totalNumInputChannels  = getTotalNumInputChannels();
    auto totalNumOutputChannels = getTotalNumOutputChannels();

    // In case we have more outputs than inputs, this code clears any output
    // channels that didn't contain input data
    for (auto i = totalNumInputChannels; i < totalNumOutputChannels; ++i)
        buffer.clear (i, 0, buffer.getNumSamples());

    // For each channel...
    for (int channel = 0; channel < totalNumInputChannels; ++channel)
    {
        float* channelData = buffer.getWritePointer (channel);
        float out;
        // For each sample of the channel...
        for (int sample = 0; sample < buffer.getNumSamples(); ++sample)
        {
            // Step 1: apply the input gain
            float inputGainDB = slider_value[0];
            float inputGain = powf(10.0f, inputGainDB / 20.0f);

            float prev = 0;
            if (sample>0)
                prev = channelData[sample-1] * inputGain;
            const float in = channelData[sample] * inputGain;
            if (sample<buffer.getNumSamples()-1)
                const float next = channelData[sample+1] * inputGain;

            // Step 2: apply the distortion that has been selected by the user
            switch (distortion_type)
            {
                // Hard clipping
                //  1 -> Threshold (0, 1)
                case hard_clipping:
                {
                    float threshold = slider_value[1];
                    if (in > threshold)
                        out = threshold;
                    else if (in < -threshold)
                        out = -threshold;
                    else
                        out = in;
                    break;
                }
                // Soft clipping
                //  1 -> Threshold 1 (0, 1)
                //  2 -> Threshold 2 (0, 1)
                case soft_clipping:
                {
                    float threshold1 = slider_value[1];
                    float threshold2 = slider_value[2];
                    if (in > threshold2)
                        out = 1.0f;
                    else if (in > threshold1)
                        out = 1.0f - powf (2.0f - 3.0f * in, 2.0f) / 3.0f;
                    else if (in < -threshold2)
                        out = -1.0f;
                    else if (in < -threshold1)
                        out = -1.0f + powf (2.0f + 3.0f * in, 2.0f) / 3.0f;
                    else
                        out = 2.0f * in;
                    out *= 0.5f;
                    break;
                }
                // Exponential soft clipping
                case exponential_soft_clipping:
                {
                    if (in > 0.0f)
                        out = 1.0f - expf (-in);
                    else
                        out = -1.0f + expf (in);
                    break;
                }
                // Full wave rectifier
                case full_wave_rectifier:
                {
                    out = fabsf (in);
                    break;
                }
                // Half wave rectifier
                case half_wave_rectifier:
                {
                    if (in > 0.0f)
                        out = in;
                    else
                        out = 0.0f;
                    break;
                }
                // Intermodulation distortion
                case intermodulation_distortion:
                {
                    out = powf(in, 2);
                }
                // Slew rate distortion
                case slew_rate_distortion:
                {
                    float max_slew_rate = slider_value[1];
                    if (in-prev>max_slew_rate)
                        out = prev+max_slew_rate;
                    else if (in-prev<-max_slew_rate)
                        out = prev-max_slew_rate;
                    else
                        out=in;
                }
            }

            // Step 3: apply the lowpass filter
            // This is both to avoid aliasing and give a further parameter to control
            float filtered = filters[channel]->processSingleSampleRaw (out);

            // Step 4: apply the output gain
            float outputGainDB = slider_value[4];
            float outputGain = powf(10.0f, outputGainDB / 20.0f);
            channelData[sample] = filtered * outputGain;
        }
        updateFilters();
    }

}

//==============================================================================

void CMLS_HW2AudioProcessor::updateFilters()
{
    double low_pass_frequency = slider_value[3];
    //std::cout << "slider_value[3]" << slider_value[3] << std::endl;

    for (int i = 0; i < filters.size(); ++i)
    {
        filters[i]->updateCoefficients (getSampleRate(), low_pass_frequency);
    }
}

//==============================================================================



//==============================================================================
bool CMLS_HW2AudioProcessor::hasEditor() const
{
    return true; // (change this to false if you choose to not supply an editor)
}

juce::AudioProcessorEditor* CMLS_HW2AudioProcessor::createEditor()
{
    return new CMLS_HW2AudioProcessorEditor (*this);
}

//==============================================================================
void CMLS_HW2AudioProcessor::getStateInformation (juce::MemoryBlock& destData)
{
    // You should use this method to store your parameters in the memory block.
    // You could do that either as raw data, or use the XML or ValueTree classes
    // as intermediaries to make it easy to save and load complex data.
}

void CMLS_HW2AudioProcessor::setStateInformation (const void* data, int sizeInBytes)
{
    // You should use this method to restore your parameters from this memory block,
    // whose contents will have been created by the getStateInformation() call.
}

//==============================================================================
// This creates new instances of the plugin..
juce::AudioProcessor* JUCE_CALLTYPE createPluginFilter()
{
    return new CMLS_HW2AudioProcessor();
}


// SETTERS implementation 

void CMLS_HW2AudioProcessor::set_slider_value(int slider_number, float val)
{
    slider_value[slider_number] = val;
}

void CMLS_HW2AudioProcessor::set_distortion_type(int dist_type)
{
    distortion_type = dist_type;
    std::cout << "dist_type: " << dist_type << std::endl;
    std::cout << "distortion_type: " << distortion_type << std::endl;
    //cout
}
