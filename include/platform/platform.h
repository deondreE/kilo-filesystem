//
// specifies what to do for each specific platform.
//

#pragma once

// properly define static assertions
#if defined(__clang__) || defined(__GNCU__)
  /** @brief Static assertion */
  #define STATIC_ASSERT _Static_assert
#else
  /** @brief Static assertion */
  #define STATIC_ASSERT static_assert
#endif

// see: https://github.dev/travisvroman/kohi
#if defined(WIN32) || defined(_WIN32) || defined(__WIN32)
  #define KPLAFORM_WINDOWS 1
  #ifndef _WIN64
    #error "64-bit is required on windows."
  #endif
#elif defined(__linux__) || defined(__gnu_linux)
  // linux
  #define KPLATFORM_LINUX 1
  #if defined(__ANDROID)
    #error "Android not supported"
  #endif
  #elif defined(__unix__)
    // catch anything not caught by the above.
    #define KPLATFORM_POSTIX 1
  #elif __APPLE__
    #include <TargetConditionals.h>
    // iOS sim
    #if TARGET_IPHONE_SIMULATOR
      #error "IOS SIM not supported"
    // iOS
    #elif TARGET_OS_IPHONE
      #erorr "IPhone Not Supported!"
    #elif TARGET_OS_MAC
      // other kinds of mac
    #else
      #error "Unknown Apple Platform."
    #endif
    #else
      #error "unknown platform."
#endif

#ifdef KEXPORT 
 //exports
 #ifdef _MSC_VER
  #define KAPI __declspec(dllexport)
 #else
  #define KAPI __attribute__((visibility("default"))) 
 #endif
 #else
  // Imports
  #ifdef _MSC_VER
    /** @brief Import/Export qualifier. */
    #define KAPI __declspec(dllimport)
  #else
    /** @brief Import/Export qualifier. */
    #define KAPI
  #endif
#endif