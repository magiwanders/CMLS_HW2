/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "PluginProcessor.h"

//==============================================================================
/**
*/
class CMLS_HW2AudioProcessorEditor  : public juce::AudioProcessorEditor, private juce::Slider::Listener
{
public:
    CMLS_HW2AudioProcessorEditor (CMLS_HW2AudioProcessor&);
    ~CMLS_HW2AudioProcessorEditor() override;

    //==============================================================================
    void paint (juce::Graphics&) override;
    void resized() override;

private:
    // This reference is provided as a quick way for your editor to
    // access the processor object that created it.
    CMLS_HW2AudioProcessor& audioProcessor;
    
    // GUI declarations
    juce::Slider clipSlider;
    juce::Label textLabel { {}, "The quick brown fox jumps over the lazy dog." };
    juce::Font textFont   { 12.0f };
    juce::ComboBox styleMenu;
    
    // GUI-called functions
    void sliderValueChanged(juce::Slider* slider) override;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (CMLS_HW2AudioProcessorEditor)
};
