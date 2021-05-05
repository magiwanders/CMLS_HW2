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
    // Use this method as the place to do any pre-playback
    // initialisation that you need..
    
    // BUFFER INITIALIZATION
    float clip_default = 1.0;
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
    // channels that didn't contain input data, (because these aren't
    // guaranteed to be empty - they may contain garbage).
    // This is here to avoid people getting screaming feedback
    // when they first compile a plugin, but obviously you don't need to keep
    // this code if your algorithm always overwrites all the output channels.
    for (auto i = totalNumInputChannels; i < totalNumOutputChannels; ++i)
        buffer.clear (i, 0, buffer.getNumSamples());

    // This is the place where you'd normally do the guts of your plugin's
    // audio processing...
    // Make sure to reset the state if your inner loop is processing
    // the samples and the outer loop is handling the channels.
    // Alternatively, you can process the samples with the channels
    // interleaved by keeping the same state.
    for (int channel = 0; channel < totalNumInputChannels; ++channel)
    {
        auto* channelData = buffer.getWritePointer (channel);

        // ..do something to the data...
    }
    
    // IMPLEMENTATION
    const float* channelInData = buffer.getReadPointer(0);
    
    float* channelOutDataL = buffer.getWritePointer(0);
    float* channelOutDataR = buffer.getWritePointer(1);
    
    for (int i = 0; i < buffer.getNumSamples(); ++i) {
        float currentSample = channelInData[i];
        //float clip_norm = clip * *std::max_element(channelInData, channelInData+buffer.getNumSamples());
        
        //if (currentSample > clip_norm) {
        //    channelOutDataL[i] = clip_norm; 
        //    channelOutDataR[i] = clip_norm;
        //} else if (currentSample < -clip_norm) {
        //   channelOutDataL[i] = -clip_norm;
        //    channelOutDataR[i] = -clip_norm;
        //} else {
        //   channelOutDataL[i] = currentSample;
        //    channelOutDataR[i] = currentSample;
        //}
        //channelOutDataL[i] = currentSample*clip;
        //channelOutDataR[i] = currentSample*clip;
    }
    
}

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
}