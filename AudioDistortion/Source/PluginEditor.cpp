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
    
        // Combo box
    addAndMakeVisible (textLabel);
    textLabel.setFont (textFont);
    // add items to the combo-box
    addAndMakeVisible (typesOfDistortionMenu);

    for (i=0; i<N_OPTIONS; i++) {
        typesOfDistortionMenu.addItem (optns[i], i+1);
    }

    typesOfDistortionMenu.onChange = [this] { styleMenuChanged(); };
    typesOfDistortionMenu.setSelectedId (1);
    
    renderSliders();
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

    // Sliders
    int j=0;
    for (i=0; i<N_SLIDERS; i++) {
        if (isVisible[i]) {
            slider[i].setBounds(100, 100+j*50, getWidth()-110, 20);
            label[i].setBounds(10, 100+j*50, getWidth()-110, 20);
            j++;
        }
    }

    // Combo box
    textLabel.setBounds (10, 10, getWidth() - 20, 20);
    typesOfDistortionMenu.setBounds (10, 40, getWidth() - 20, 20);
    
    // Debug Label
    debugLabel.setBounds(10, 100+j*50+20, getWidth()-110, 20);
}


// GUI-called functions
void CMLS_HW2AudioProcessorEditor::sliderValueChanged(juce::Slider* currentSlider)
{
    //debugLabel.setText (juce::String(currentSlider->getValue()), juce::dontSendNotification);
    
    for(i=0; i<N_SLIDERS; i++) {
        if (currentSlider == &slider[i]) {
            audioProcessor.set_slider_value(i, currentSlider->getValue());
        }
    }
    
}

void CMLS_HW2AudioProcessorEditor::styleMenuChanged()
{
    debugLabel.setText (juce::String(typesOfDistortionMenu.getSelectedId()), juce::dontSendNotification);
    audioProcessor.set_distortion_type(typesOfDistortionMenu.getSelectedId());
    switch (typesOfDistortionMenu.getSelectedId())
    {
        case 1: {
            int isVisibleNew[5] = {1, 1, 0, 0, 1};
            int newType[5] = {4, 1, 0, 0, 4};
            int newLabel[5] = {0, 2, 0, 0, 1};
            int newDefault[5] = {0, 1, 0, 0, 0};
            std::copy(isVisibleNew, isVisibleNew + 5, isVisible);
            std::copy(newType, newType + 5, sliderType);
            std::copy(newLabel, newLabel+ 5, whichLabel);
            std::copy(newDefault, newDefault +5, default_value);
        }; break;
        case 2:  {
            int isVisibleNew[5] = {1, 1, 1, 0, 1};
            int newType[5] = {4, 1, 1, 0, 4};
            int newLabel[5] = {0, 3, 4, 0, 1};
            int newDefault[5] = {0, 1, 1, 0, 0};
            std::copy(isVisibleNew, isVisibleNew + 5, isVisible);
            std::copy(newType, newType + 5, sliderType);
            std::copy(newLabel, newLabel+ 5, whichLabel);
            std::copy(newDefault, newDefault +5, default_value);
        }; break;
        case 3:  {
            int isVisibleNew[5] = {1, 0, 5, 0, 1};
            int newType[5] = {4, 0, 0, 0, 4};
            int newLabel[5] = {0, 0, 0, 0, 1};
            int newDefault[5] = {0, 0, 0, 0, 0};
            std::copy(isVisibleNew, isVisibleNew + 5, isVisible);
            std::copy(newType, newType + 5, sliderType);
            std::copy(newLabel, newLabel+ 5, whichLabel);
            std::copy(newDefault, newDefault +5, default_value);
        }; break;
        case 4:  {
            int isVisibleNew[5] = {1, 0, 0, 0, 1};
            int newType[5] = {4, 0, 0, 0, 4};
            int newLabel[5] = {0, 0, 0, 0, 1};
            int newDefault[5] = {0, 0, 0, 0, 0};
            std::copy(isVisibleNew, isVisibleNew + 5, isVisible);
            std::copy(newType, newType + 5, sliderType);
            std::copy(newLabel, newLabel+ 5, whichLabel);
            std::copy(newDefault, newDefault +5, default_value);
        }; break;
        case 5:  {
            int isVisibleNew[5] = {1, 0, 0, 0, 1};
            int newType[5] = {4, 0, 0, 0, 4};
            int newLabel[5] = {0, 0, 0, 0, 1};
            int newDefault[5] = {0, 0, 0, 0, 0};
            std::copy(isVisibleNew, isVisibleNew + 5, isVisible);
            std::copy(newType, newType + 5, sliderType);
            std::copy(newLabel, newLabel+ 5, whichLabel);
            std::copy(newDefault, newDefault +5, default_value);
        }; break;
        case 6:  {
            int isVisibleNew[5] = {1, 0, 0, 0, 1};
            int newType[5] = {4, 0, 0, 0, 4};
            int newLabel[5] = {0, 0, 0, 0, 1};
            int newDefault[5] = {0, 0, 0, 0, 0};
            std::copy(isVisibleNew, isVisibleNew + 5, isVisible);
            std::copy(newType, newType + 5, sliderType);
            std::copy(newLabel, newLabel+ 5, whichLabel);
            std::copy(newDefault, newDefault +5, default_value);
        }; break;
        case 7:  {
            int isVisibleNew[5] = {1, 0, 0, 0, 1};
            int newType[5] = {4, 0, 0, 0, 4};
            int newLabel[5] = {0, 0, 0, 0, 1};
            int newDefault[5] = {0, 0, 0, 0, 0};
            std::copy(isVisibleNew, isVisibleNew + 5, isVisible);
            std::copy(newType, newType + 5, sliderType);
            std::copy(newLabel, newLabel+ 5, whichLabel);
            std::copy(newDefault, newDefault +5, default_value);
        }; break;
        case 8:  {
            int isVisibleNew[5] = {1, 0, 0, 0, 1};
            int newType[5] = {4, 0, 0, 0, 4};
            int newLabel[5] = {0, 0, 0, 0, 1};
            int newDefault[5] = {0, 0, 0, 0, 0};
            std::copy(isVisibleNew, isVisibleNew + 5, isVisible);
            std::copy(newType, newType + 5, sliderType);
            std::copy(newLabel, newLabel+ 5, whichLabel);
            std::copy(newDefault, newDefault +5, default_value);
        }; break;
        case 9:  {
            int isVisibleNew[5] = {1, 0, 0, 0, 1};
            int newType[5] = {4, 0, 0, 0, 4};
            int newLabel[5] = {0, 0, 0, 0, 1};
            int newDefault[5] = {0, 0, 0, 0, 0};
            std::copy(isVisibleNew, isVisibleNew + 5, isVisible);
            std::copy(newType, newType + 5, sliderType);
            std::copy(newLabel, newLabel+ 5, whichLabel);
            std::copy(newDefault, newDefault +5, default_value);
        }; break;
        case 10: {
            int isVisibleNew[5] = {1, 0, 0, 0, 1};
            int newType[5] = {4, 0, 0, 0, 4};
            int newLabel[5] = {0, 0, 0, 0, 1};
            int newDefault[5] = {0, 0, 0, 0, 0};
            std::copy(isVisibleNew, isVisibleNew + 5, isVisible);
            std::copy(newType, newType + 5, sliderType);
            std::copy(newLabel, newLabel+ 5, whichLabel);
            std::copy(newDefault, newDefault +5, default_value);
        };  break;
        case 11:  {
            int isVisibleNew[5] = {1, 0, 0, 0, 1};
            int newType[5] = {4, 0, 0, 0, 4};
            int newLabel[5] = {0, 0, 0, 0, 1};
            int newDefault[5] = {0, 0, 0, 0, 0};
            std::copy(isVisibleNew, isVisibleNew + 5, isVisible);
            std::copy(newType, newType + 5, sliderType);
            std::copy(newLabel, newLabel+ 5, whichLabel);
            std::copy(newDefault, newDefault +5, default_value);
        }; break;
        default:  {
            int isVisibleNew[5] = {1, 0, 0, 0, 1};
            int newType[5] = {4, 0, 0, 0, 4};
            int newLabel[5] = {0, 0, 0, 0, 1};
            int newDefault[5] = {0, 0, 0, 0, 0};
            std::copy(isVisibleNew, isVisibleNew + 5, isVisible);
            std::copy(newType, newType + 5, sliderType);
            std::copy(newLabel, newLabel+ 5, whichLabel);
            std::copy(newDefault, newDefault +5, default_value);
        }; break;
    }
    renderSliders();
}

void CMLS_HW2AudioProcessorEditor::renderSliders()
{
    allInvisible();

    // Sliders
    int j=0;
    for (i=0; i<N_SLIDERS; i++)
    {
        int st = sliderType[i];
        if (isVisible[i]==1)
        {
            j++;
            addAndMakeVisible(slider[i]);
            addAndMakeVisible(label[i]);
        }
        
        slider[i].setRange(limits[st][0], limits[st][1], limits[st][2]);
        slider[i].setTextValueSuffix(suffix[st]);
        slider[i].addListener(this);
        audioProcessor.set_slider_value(i, default_value[i]);
        slider[i].setValue(default_value[i]);
        slider[i].setSkewFactor(skew_value[st], false);
        slider[i].setDoubleClickReturnValue(true, default_value[i]);
        
        label[i].setText(label_text[whichLabel[i]] , juce::dontSendNotification);
        label[i].attachToComponent (&slider[i], true);
    }

    // LPF cutoff frequency
    // TODO
    
    // Debug Label
    debugLabel.setText ("Debug Label", juce::dontSendNotification);
    addAndMakeVisible(debugLabel);

    setSize (400, 100+j*50);
}

void CMLS_HW2AudioProcessorEditor::allInvisible()
{
    for (i=0; i<N_SLIDERS; i++)
    {
        slider[i].setVisible(false);
    }
}
