/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

CMLS_HW2AudioProcessorEditor::CMLS_HW2AudioProcessorEditor (CMLS_HW2AudioProcessor& p)
    : AudioProcessorEditor (&p), audioProcessor (p)
{
    // GUI appearance and settings
    
    // Combo box
    addAndMakeVisible (textLabel);
    textLabel.setFont (textFont);
    // add items to the combo-box
    addAndMakeVisible (typesOfDistortionMenu);

    for (i=0; i<N_OPTIONS; i++)
    {
        typesOfDistortionMenu.addItem (optns[i], i+1);
    }

    typesOfDistortionMenu.onChange = [this] { styleMenuChanged(); };
    typesOfDistortionMenu.setSelectedId (1);
    
    renderSliders();
}

CMLS_HW2AudioProcessorEditor::~CMLS_HW2AudioProcessorEditor()
{
}

void CMLS_HW2AudioProcessorEditor::paint (juce::Graphics& g)
{
    // (Our component is opaque, so we must completely fill the background with a solid colour)
    g.fillAll (getLookAndFeel().findColour (juce::ResizableWindow::backgroundColourId));
}

// Position the GUI elements in the main window
void CMLS_HW2AudioProcessorEditor::resized()
{
    // Combo box
    textLabel.setBounds (10, 10, getWidth() - 20, 20);
    typesOfDistortionMenu.setBounds (10, 40, getWidth() - 20, 20);

    // Sliders
    int j=0;
    for (i=0; i<N_SLIDERS; i++)
    {
        if (isVisible[i])
        {
            slider[i].setBounds(100, 100+j*50, getWidth()-110, 20);
            label[i].setBounds(10, 100+j*50, getWidth()-110, 20);
            j++;
        }
    }
}


// Change the value for each slider that is modified in the GUI
void CMLS_HW2AudioProcessorEditor::sliderValueChanged(juce::Slider* currentSlider)
{
    for(i=0; i<N_SLIDERS; i++)
    {
        if (currentSlider == &slider[i])
        {
            audioProcessor.set_slider_value(i, currentSlider->getValue());
        }
    }
    
}

// Takes care of showing the right sliders for each distortion type
void CMLS_HW2AudioProcessorEditor::styleMenuChanged()
{
    audioProcessor.set_distortion_type(typesOfDistortionMenu.getSelectedId());
    switch (typesOfDistortionMenu.getSelectedId())
    {
        case hard_clipping: {
            int isVisibleNew[5] = {true, true, false, true, true};
            int newType[5] = {input_gain_slider, normalized_slider, 0, low_pass_slider, output_gain_slider};
            int newLabel[5] = {0, 2, 0, 5, 1};
            int newDefault[5] = {0, 1, 0, 2000, 0};
            std::copy(isVisibleNew, isVisibleNew + 5, isVisible);
            std::copy(newType, newType + 5, sliderType);
            std::copy(newLabel, newLabel+ 5, whichLabel);
            std::copy(newDefault, newDefault +5, default_value);
        }; break;
        case soft_clipping:  {
            int isVisibleNew[5] = {true, true, true, true, true};
            int newType[5] = {input_gain_slider, normalized_slider, normalized_slider, low_pass_slider, output_gain_slider};
            int newLabel[5] = {0, 3, 4, 5, 1};
            int newDefault[5] = {0, 1, 1, 2000, 0};
            std::copy(isVisibleNew, isVisibleNew + 5, isVisible);
            std::copy(newType, newType + 5, sliderType);
            std::copy(newLabel, newLabel+ 5, whichLabel);
            std::copy(newDefault, newDefault +5, default_value);
        }; break;
        case exponential_soft_clipping:  {
            int isVisibleNew[5] = {true, false, false, true, true};
            int newType[5] = {input_gain_slider, 0, 0, low_pass_slider, output_gain_slider};
            int newLabel[5] = {0, 0, 0, 5, 1};
            int newDefault[5] = {0, 0, 0, 2000, 0};
            std::copy(isVisibleNew, isVisibleNew + 5, isVisible);
            std::copy(newType, newType + 5, sliderType);
            std::copy(newLabel, newLabel+ 5, whichLabel);
            std::copy(newDefault, newDefault +5, default_value);
        }; break;
        case full_wave_rectifier:  {
            int isVisibleNew[5] = {true, false, false, true, true};
            int newType[5] = {input_gain_slider, 0, 0, low_pass_slider, output_gain_slider};
            int newLabel[5] = {0, 0, 0, 5, 1};
            int newDefault[5] = {0, 0, 0, 2000, 0};
            std::copy(isVisibleNew, isVisibleNew + 5, isVisible);
            std::copy(newType, newType + 5, sliderType);
            std::copy(newLabel, newLabel+ 5, whichLabel);
            std::copy(newDefault, newDefault +5, default_value);
        }; break;
        case half_wave_rectifier:  {
            int isVisibleNew[5] = {true, false, false, true, true};
            int newType[5] = {input_gain_slider, 0, 0, low_pass_slider, output_gain_slider};
            int newLabel[5] = {0, 0, 0, 5, 1};
            int newDefault[5] = {0, 0, 0, 2000, 0};
            std::copy(isVisibleNew, isVisibleNew + 5, isVisible);
            std::copy(newType, newType + 5, sliderType);
            std::copy(newLabel, newLabel+ 5, whichLabel);
            std::copy(newDefault, newDefault +5, default_value);
        }; break;
        /*case tube_saturation:  {
            int isVisibleNew[5] = {1, 0, 0, 0, 1};
            int newType[5] = {input_gain_slider, 0, 0, 0, 4};
            int newLabel[5] = {0, 0, 0, 0, 1};
            int newDefault[5] = {0, 0, 0, 0, 0};
            std::copy(isVisibleNew, isVisibleNew + 5, isVisible);
            std::copy(newType, newType + 5, sliderType);
            std::copy(newLabel, newLabel+ 5, whichLabel);
            std::copy(newDefault, newDefault +5, default_value);
        }; break;*/
        /*case even_harmonic_distortion:  {
            int isVisibleNew[5] = {1, 0, 0, 0, 1};
            int newType[5] = {input_gain_slider, 0, 0, 0, 4};
            int newLabel[5] = {0, 0, 0, 0, 1};
            int newDefault[5] = {0, 0, 0, 0, 0};
            std::copy(isVisibleNew, isVisibleNew + 5, isVisible);
            std::copy(newType, newType + 5, sliderType);
            std::copy(newLabel, newLabel+ 5, whichLabel);
            std::copy(newDefault, newDefault +5, default_value);
        }; break;*/
        /*case odd_harmonic_distortion:  {
            int isVisibleNew[5] = {1, 0, 0, 0, 1};
            int newType[5] = {input_gain_slider, 0, 0, 0, 4};
            int newLabel[5] = {0, 0, 0, 0, 1};
            int newDefault[5] = {0, 0, 0, 0, 0};
            std::copy(isVisibleNew, isVisibleNew + 5, isVisible);
            std::copy(newType, newType + 5, sliderType);
            std::copy(newLabel, newLabel+ 5, whichLabel);
            std::copy(newDefault, newDefault +5, default_value);
        }; break;*/
        case intermodulation_distortion:  {
            int isVisibleNew[5] = {true, false, false, true, true};
            int newType[5] = {input_gain_slider, 0, 0, low_pass_slider, output_gain_slider};
            int newLabel[5] = {0, 0, 0, 5, 1};
            int newDefault[5] = {0, 0, 0, 2000, 0};
            std::copy(isVisibleNew, isVisibleNew + 5, isVisible);
            std::copy(newType, newType + 5, sliderType);
            std::copy(newLabel, newLabel+ 5, whichLabel);
            std::copy(newDefault, newDefault +5, default_value);
        }; break;
        case slew_rate_and_overshoot_distortion: {
            int isVisibleNew[5] = {true, true, false, true, true};
            int newType[5] = {input_gain_slider, normalized_slider, 0, low_pass_slider, output_gain_slider};
            int newLabel[5] = {0, 6, 0, 5, 1};
            int newDefault[5] = {0, 1, 0, 2000, 0};
            std::copy(isVisibleNew, isVisibleNew + 5, isVisible);
            std::copy(newType, newType + 5, sliderType);
            std::copy(newLabel, newLabel+ 5, whichLabel);
            std::copy(newDefault, newDefault +5, default_value);
        };  break;
        /*case phase_distortion:  {
            int isVisibleNew[5] = {1, 0, 0, 0, 1};
            int newType[5] = {input_gain_slider, 0, 0, 0, 4};
            int newLabel[5] = {0, 0, 0, 0, 1};
            int newDefault[5] = {0, 0, 0, 0, 0};
            std::copy(isVisibleNew, isVisibleNew + 5, isVisible);
            std::copy(newType, newType + 5, sliderType);
            std::copy(newLabel, newLabel+ 5, whichLabel);
            std::copy(newDefault, newDefault +5, default_value);
        }; break;*/
        default:  {
            int isVisibleNew[5] = {true, false, false, true, true};
            int newType[5] = {input_gain_slider, 0, 0, output_gain_slider, output_gain_slider};
            int newLabel[5] = {0, 0, 0, 5, 1};
            int newDefault[5] = {0, 0, 0, 2000, 0};
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

    setSize (400, 100+j*50);
}

void CMLS_HW2AudioProcessorEditor::allInvisible()
{
    for (i=0; i<N_SLIDERS; i++)
    {
        slider[i].setVisible(false);
    }
}
