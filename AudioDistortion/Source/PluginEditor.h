/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "PluginProcessor.h"
#include "PluginParameters.h"

#define N_SLIDERS 5
#define N_OPTIONS 7



class CMLS_HW2AudioProcessorEditor  : public juce::AudioProcessorEditor, private juce::Slider::Listener
{
public:
    CMLS_HW2AudioProcessorEditor (CMLS_HW2AudioProcessor&);
    ~CMLS_HW2AudioProcessorEditor() override;

    void paint (juce::Graphics&) override;
    void resized() override;

private:
    CMLS_HW2AudioProcessor& audioProcessor;
    
    // Utility
    int i;
    
    // GUI declarations
    juce::Label label[N_SLIDERS];
    int isVisible[N_SLIDERS] = {1, 1, 1, 1, 1};
    int sliderType[N_SLIDERS] = {input_gain_slider, normalized_slider, low_pass_slider, audio_linear_slider, output_gain_slider};
    int whichLabel[N_SLIDERS] = {0, 1, 2, 3, 4};
    int default_value[N_SLIDERS] = {0, 0, 0, 0, 0};
    juce::Slider slider[N_SLIDERS];
    
    // Characteristics of the 5 slider types
    float limits[5][3] =
    {
        {-24, 24, 0.01},
        {0, 1, 0.001},
        {20, 20000, 1},
        {-1, 1, 0.001},
        {-24, 24, 0.01}
    };
    float skew_value[5] = {1, 0.3, 0.6, 1, 0.5};
    juce::String suffix[5] = {"dB", "", "Hz", "", "dB"};
    juce::String label_text[7] =
    {
        "IN Gain",
        "OUT Gain",
        "Clipping\n"
        "threshold",
        "Positive\n"
        "Threshold\n",
        "Negative\n"
        "Threshold\n",
        "Low-Pass\n"
        "Threshold",
        "Maximum\n"
        "Slew Rate"
    };
    
    juce::Label textLabel { {}, "Select type of distortion:" };
    juce::Font textFont   { 12.0f };
    juce::ComboBox typesOfDistortionMenu;
    juce::String optns[N_OPTIONS] =
    {
        "Hard Clipping", "Soft Clipping", "Exponential Soft Clipping",
        "Full Wave Rectifier", "Half Wave Rectifier",
        "Intermodulation Distortion", "Slew Rate Distortion"};
            /*"Tube Saturation", "Even Harmonic Distortion",
            "Odd Harmonic Distortion", "Phase Distortion"};*/
    
    
    // GUI-called functions
    void sliderValueChanged(juce::Slider* currentSlider) override;
    void styleMenuChanged();
    void renderSliders();
    void allInvisible();

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (CMLS_HW2AudioProcessorEditor)
};
