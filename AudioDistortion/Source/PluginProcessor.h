/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin processor.

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include <juce_audio_utils/juce_audio_utils.h>
#define _USE_MATH_DEFINES
#include <cmath>


//==============================================================================
/**
*/
class CMLS_HW2AudioProcessor  : public juce::AudioProcessor
{
public:
    //==============================================================================
    CMLS_HW2AudioProcessor();
    ~CMLS_HW2AudioProcessor() override;

    //==============================================================================
    void prepareToPlay (double sampleRate, int samplesPerBlock) override;
    void releaseResources() override;

   #ifndef JucePlugin_PreferredChannelConfigurations
    bool isBusesLayoutSupported (const BusesLayout& layouts) const override;
   #endif

    void processBlock (juce::AudioBuffer<float>&, juce::MidiBuffer&) override;

    //==============================================================================
    juce::AudioProcessorEditor* createEditor() override;
    bool hasEditor() const override;

    //==============================================================================
    const juce::String getName() const override;

    bool acceptsMidi() const override;
    bool producesMidi() const override;
    bool isMidiEffect() const override;
    double getTailLengthSeconds() const override;

    //==============================================================================
    int getNumPrograms() override;
    int getCurrentProgram() override;
    void setCurrentProgram (int index) override;
    const juce::String getProgramName (int index) override;
    void changeProgramName (int index, const juce::String& newName) override;

    //==============================================================================
    void getStateInformation (juce::MemoryBlock& destData) override;
    void setStateInformation (const void* data, int sizeInBytes) override;
    
    // SETTERS
    void set_slider_value(int slider_number, float val);
    void set_distortion_type(int dist_type);

    // LOW-PASS FILTER
    class LowPassFilter : public juce::IIRFilter
    {
    private:
        juce::IIRCoefficients coefficients;
    public:
        void updateCoefficients (const double sample_rate, const double low_pass_frequency) noexcept
        {
            //jassert (low_pass_frequency > 0);

            //double tan_half_wc = tan (low_pass_frequency / 2.0);

            this->coefficients = juce::IIRCoefficients::makeLowPass(sample_rate, low_pass_frequency);
            //coefficients = IIRCoefficients (/* b0 */ tan_half_wc,
            //                                /* b1 */ tan_half_wc,
            //                                /* b2 */ 0.0,
            //                                /* a0 */ 0.0,
            //                                /* a1 */ 0.0,
            //                                /* a2 */ 0.0);

            this->setCoefficients (this->coefficients);
        }
    };

    juce::OwnedArray<LowPassFilter> filters;
    void updateFilters();

private:
    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (CMLS_HW2AudioProcessor)
    
    // Custom variables
    float slider_value[5];
    /* 0: input gain (dB)
     * 1:
     * 2:
     * 3:
     * 4: output gain (dB)
     */


    int distortion_type;
    /* 1: Hard Clipping
     * 2: Soft Clipping
     * 3: Exponential Soft Clipping
     * 4: Full Wave Rectifier
     * 5: Half Wave Rectifier
     * 6: Tube Saturation
     * 7: Even Harmonic Distortion
     * 8: Odd Harmonic Distortion
     * 9: Intermodulation Distortion
     * 10: Slew Rate & Overshoot Distortion
     * 11: Phase Distortion
     */
};
