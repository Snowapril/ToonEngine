#ifndef TOON_COMMON_PLUGIN_H
#define TOON_COMMON_PLUGIN_H

#ifdef _TOON_EXPORT
#define ToonAPI __declspec(dllexport)
#else 
#define ToonAPI __declspec(dllimport)
#endif

#endif