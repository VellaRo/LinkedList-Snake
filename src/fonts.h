#ifndef FONTS_H
#define FONTS_H
#ifdef WIN32    // Windows
constexpr const char* ArialFontDatei = 
                       "C:/Windows/Fonts/arial.ttf";
#else
#ifdef __MACH__ // Mac OS X
constexpr const char* ArialFontDatei = 
                       "/Library/Fonts/Arial.ttf";
#else           // alles andere, Linux angenommen
constexpr const char* ArialFontDatei =
                  "/usr/share/fonts/truetype/liberation2/LiberationSans-Regular.ttf";
#endif   // \tts{WIN32}
#endif   // \tts{\_\_MACH\_\_}
#endif   // \tts{FONTS\_H}

