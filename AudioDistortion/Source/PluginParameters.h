#ifndef PLUGINPARAMETERS_H
#define PLUGINPARAMETERS_H

#endif // PLUGINPARAMETERS_H

enum distortion_type
{
    hard_clipping = 1,
    soft_clipping,
    exponential_soft_clipping,
    full_wave_rectifier,
    half_wave_rectifier,
    intermodulation_distortion,
    slew_rate_distortion,
    tube_saturation,
    even_harmonic_distortion,
    odd_harmonic_distortion,
    phase_distortion
};


/*
Types of sliders:
    0 -> dB (-24, +24)
    1 -> normalized (0, 1)
    2 -> Hz (20, 20k)
    3 -> Audio lin (-1, 1)
    4 -> Audio dB (-80, +6)
*/
enum slider_type
{
    input_gain_slider = 0,
    normalized_slider,
    low_pass_slider,
    audio_linear_slider,
    output_gain_slider
};
