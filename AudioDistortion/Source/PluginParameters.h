#ifndef PLUGINPARAMETERS_H
#define PLUGINPARAMETERS_H

#endif // PLUGINPARAMETERS_H

enum distortion_type {
    hard_clipping = 1,
    soft_clipping,
    exponential_soft_clipping,
    full_wave_rectifier,
    half_wave_rectifier,
    tube_saturation,
    even_harmonic_distortion,
    odd_harmonic_distortion,
    intermodulation_distortion,
    slew_rate_and_overshoot_distortion,
    phase_distortion
};
