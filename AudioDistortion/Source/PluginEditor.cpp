/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
CMLS_HW2AudioProcessorEditor::CMLS_HW2AudioProcessorEditor (CMLS_HW2AudioProcessor& p)
    : AudioProcessorEditor (&p), audioProcessor (p)
{
    // Make sure that before the constructor has finished, you've set the
    // editor's size to whatever you need it to be.
    
    // GUI appearance and settings
    clipSlider.setRange(0.0, 1.0);
    clipSlider.addListener(this);
    addAndMakeVisible(clipSlider);
    setSize (400, 300);
}

CMLS_HW2AudioProcessorEditor::~CMLS_HW2AudioProcessorEditor()
{
}

//==============================================================================
void CMLS_HW2AudioProcessorEditor::paint (juce::Graphics& g)
{
    // (Our component is opaque, so we must completely fill the background with a solid colour)
    g.fillAll (getLookAndFeel().findColour (juce::ResizableWindow::backgroundColourId));
}

void CMLS_HW2AudioProcessorEditor::resized()
{
    // This is generally where you'll want to lay out the positions of any
    // subcomponents in your editor..
    
    // GUI position
    clipSlider.setBounds(100, 50, getWidth()-110, 20);

}


// GUI-called functions
void CMLS_HW2AudioProcessorEditor::sliderValueChanged(juce::Slider* slider) 
{
    if(slider== &clipSlider) 
        {
            audioProcessor.set_clip(clipSlider.getValue());
        }
}
