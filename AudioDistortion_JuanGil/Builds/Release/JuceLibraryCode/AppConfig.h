/*

    IMPORTANT! This file is auto-generated each time you run cmake on your
    project - if you alter its contents, your changes may be overwritten!

    Any commented-out settings will assume their default values.

*/

#pragma once

//==============================================================================
// [BEGIN_USER_CODE_SECTION]

// (You can get your own code in this section by calling jucer_appconfig_header)

// [END_USER_CODE_SECTION]

#include "JucePluginDefines.h"

/*
  ==============================================================================

   In accordance with the terms of the JUCE 5 End-Use License Agreement, the
   JUCE Code in SECTION A cannot be removed, changed or otherwise rendered
   ineffective unless you have a JUCE Indie or Pro license, or are using JUCE
   under the GPL v3 license.

   End User License Agreement: www.juce.com/juce-5-licence

  ==============================================================================
*/

// BEGIN SECTION A

#ifndef JUCE_DISPLAY_SPLASH_SCREEN
 #define JUCE_DISPLAY_SPLASH_SCREEN 1
#endif

#ifndef JUCE_REPORT_APP_USAGE
 #define JUCE_REPORT_APP_USAGE 1
#endif

// END SECTION A

#define JUCE_USE_DARK_SPLASH_SCREEN 1

//==============================================================================
#define JUCE_MODULE_AVAILABLE_juce_audio_basics             1
#define JUCE_MODULE_AVAILABLE_juce_audio_devices            1
#define JUCE_MODULE_AVAILABLE_juce_audio_formats            1
#define JUCE_MODULE_AVAILABLE_juce_audio_plugin_client      1
#define JUCE_MODULE_AVAILABLE_juce_audio_processors         1
#define JUCE_MODULE_AVAILABLE_juce_audio_utils              1
#define JUCE_MODULE_AVAILABLE_juce_core                     1
#define JUCE_MODULE_AVAILABLE_juce_data_structures          1
#define JUCE_MODULE_AVAILABLE_juce_events                   1
#define JUCE_MODULE_AVAILABLE_juce_graphics                 1
#define JUCE_MODULE_AVAILABLE_juce_gui_basics               1
#define JUCE_MODULE_AVAILABLE_juce_gui_extra                1

#define JUCE_GLOBAL_MODULE_SETTINGS_INCLUDED 1

//==============================================================================
// juce_audio_devices flags:

#ifndef    JUCE_USE_WINRT_MIDI
 //#define JUCE_USE_WINRT_MIDI
#endif

#ifndef    JUCE_ASIO
 //#define JUCE_ASIO
#endif

#ifndef    JUCE_WASAPI
 //#define JUCE_WASAPI
#endif

#ifndef    JUCE_DIRECTSOUND
 //#define JUCE_DIRECTSOUND
#endif

#ifndef    JUCE_ALSA
 //#define JUCE_ALSA
#endif

#ifndef    JUCE_JACK
 //#define JUCE_JACK
#endif

#ifndef    JUCE_BELA
 //#define JUCE_BELA
#endif

#ifndef    JUCE_USE_ANDROID_OBOE
 //#define JUCE_USE_ANDROID_OBOE
#endif

#ifndef    JUCE_USE_OBOE_STABILIZED_CALLBACK
 //#define JUCE_USE_OBOE_STABILIZED_CALLBACK
#endif

#ifndef    JUCE_USE_ANDROID_OPENSLES
 //#define JUCE_USE_ANDROID_OPENSLES
#endif

#ifndef    JUCE_DISABLE_AUDIO_MIXING_WITH_OTHER_APPS
 //#define JUCE_DISABLE_AUDIO_MIXING_WITH_OTHER_APPS
#endif

//==============================================================================
// juce_audio_formats flags:

#ifndef    JUCE_USE_FLAC
 //#define JUCE_USE_FLAC
#endif

#ifndef    JUCE_USE_OGGVORBIS
 //#define JUCE_USE_OGGVORBIS
#endif

#ifndef    JUCE_USE_MP3AUDIOFORMAT
 //#define JUCE_USE_MP3AUDIOFORMAT
#endif

#ifndef    JUCE_USE_LAME_AUDIO_FORMAT
 //#define JUCE_USE_LAME_AUDIO_FORMAT
#endif

#ifndef    JUCE_USE_WINDOWS_MEDIA_FORMAT
 //#define JUCE_USE_WINDOWS_MEDIA_FORMAT
#endif

//==============================================================================
// juce_audio_plugin_client flags:

#ifndef    JUCE_VST3_CAN_REPLACE_VST2
 #define   JUCE_VST3_CAN_REPLACE_VST2 0
#endif

#ifndef    JUCE_FORCE_USE_LEGACY_PARAM_IDS
 //#define JUCE_FORCE_USE_LEGACY_PARAM_IDS
#endif

#ifndef    JUCE_FORCE_LEGACY_PARAMETER_AUTOMATION_TYPE
 //#define JUCE_FORCE_LEGACY_PARAMETER_AUTOMATION_TYPE
#endif

#ifndef    JUCE_USE_STUDIO_ONE_COMPATIBLE_PARAMETERS
 //#define JUCE_USE_STUDIO_ONE_COMPATIBLE_PARAMETERS
#endif

#ifndef    JUCE_AU_WRAPPERS_SAVE_PROGRAM_STATES
 //#define JUCE_AU_WRAPPERS_SAVE_PROGRAM_STATES
#endif

#ifndef    JUCE_STANDALONE_FILTER_WINDOW_USE_KIOSK_MODE
 //#define JUCE_STANDALONE_FILTER_WINDOW_USE_KIOSK_MODE
#endif

//==============================================================================
// juce_audio_processors flags:

#ifndef    JUCE_PLUGINHOST_VST
 //#define JUCE_PLUGINHOST_VST
#endif

#ifndef    JUCE_PLUGINHOST_VST3
 //#define JUCE_PLUGINHOST_VST3
#endif

#ifndef    JUCE_PLUGINHOST_AU
 //#define JUCE_PLUGINHOST_AU
#endif

#ifndef    JUCE_PLUGINHOST_LADSPA
 //#define JUCE_PLUGINHOST_LADSPA
#endif

#ifndef    JUCE_CUSTOM_VST3_SDK
 //#define JUCE_CUSTOM_VST3_SDK
#endif

//==============================================================================
// juce_audio_utils flags:

#ifndef    JUCE_USE_CDREADER
 //#define JUCE_USE_CDREADER
#endif

#ifndef    JUCE_USE_CDBURNER
 //#define JUCE_USE_CDBURNER
#endif

//==============================================================================
// juce_core flags:

#ifndef    JUCE_FORCE_DEBUG
 //#define JUCE_FORCE_DEBUG
#endif

#ifndef    JUCE_LOG_ASSERTIONS
 //#define JUCE_LOG_ASSERTIONS
#endif

#ifndef    JUCE_CHECK_MEMORY_LEAKS
 //#define JUCE_CHECK_MEMORY_LEAKS
#endif

#ifndef    JUCE_DONT_AUTOLINK_TO_WIN32_LIBRARIES
 //#define JUCE_DONT_AUTOLINK_TO_WIN32_LIBRARIES
#endif

#ifndef    JUCE_INCLUDE_ZLIB_CODE
 //#define JUCE_INCLUDE_ZLIB_CODE
#endif

#ifndef    JUCE_USE_CURL
 //#define JUCE_USE_CURL
#endif

#ifndef    JUCE_LOAD_CURL_SYMBOLS_LAZILY
 //#define JUCE_LOAD_CURL_SYMBOLS_LAZILY
#endif

#ifndef    JUCE_CATCH_UNHANDLED_EXCEPTIONS
 //#define JUCE_CATCH_UNHANDLED_EXCEPTIONS
#endif

#ifndef    JUCE_ALLOW_STATIC_NULL_VARIABLES
 //#define JUCE_ALLOW_STATIC_NULL_VARIABLES
#endif

#ifndef    JUCE_STRICT_REFCOUNTEDPOINTER
 #define   JUCE_STRICT_REFCOUNTEDPOINTER 1
#endif

#ifndef    JUCE_ENABLE_ALLOCATION_HOOKS
 //#define JUCE_ENABLE_ALLOCATION_HOOKS
#endif

//==============================================================================
// juce_events flags:

#ifndef    JUCE_EXECUTE_APP_SUSPEND_ON_BACKGROUND_TASK
 //#define JUCE_EXECUTE_APP_SUSPEND_ON_BACKGROUND_TASK
#endif

//==============================================================================
// juce_graphics flags:

#ifndef    JUCE_USE_COREIMAGE_LOADER
 //#define JUCE_USE_COREIMAGE_LOADER
#endif

#ifndef    JUCE_USE_DIRECTWRITE
 //#define JUCE_USE_DIRECTWRITE
#endif

#ifndef    JUCE_DISABLE_COREGRAPHICS_FONT_SMOOTHING
 //#define JUCE_DISABLE_COREGRAPHICS_FONT_SMOOTHING
#endif

//==============================================================================
// juce_gui_basics flags:

#ifndef    JUCE_ENABLE_REPAINT_DEBUGGING
 //#define JUCE_ENABLE_REPAINT_DEBUGGING
#endif

#ifndef    JUCE_USE_XRANDR
 //#define JUCE_USE_XRANDR
#endif

#ifndef    JUCE_USE_XINERAMA
 //#define JUCE_USE_XINERAMA
#endif

#ifndef    JUCE_USE_XSHM
 //#define JUCE_USE_XSHM
#endif

#ifndef    JUCE_USE_XRENDER
 //#define JUCE_USE_XRENDER
#endif

#ifndef    JUCE_USE_XCURSOR
 //#define JUCE_USE_XCURSOR
#endif

#ifndef    JUCE_WIN_PER_MONITOR_DPI_AWARE
 //#define JUCE_WIN_PER_MONITOR_DPI_AWARE
#endif

//==============================================================================
// juce_gui_extra flags:

#ifndef    JUCE_WEB_BROWSER
 //#define JUCE_WEB_BROWSER
#endif

#ifndef    JUCE_USE_WIN_WEBVIEW2
 //#define JUCE_USE_WIN_WEBVIEW2
#endif

#ifndef    JUCE_ENABLE_LIVE_CONSTANT_EDITOR
 //#define JUCE_ENABLE_LIVE_CONSTANT_EDITOR
#endif

//==============================================================================
#ifndef    JUCE_STANDALONE_APPLICATION
 #if defined(JucePlugin_Name) && defined(JucePlugin_Build_Standalone)
  #define  JUCE_STANDALONE_APPLICATION JucePlugin_Build_Standalone
 #else
  #define  JUCE_STANDALONE_APPLICATION 0
 #endif
#endif
