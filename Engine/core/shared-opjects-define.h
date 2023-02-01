
#ifdef FISH_PLATFORM_WINDOWS
#ifdef FISH_BUILD_DLL
#define FISH_SO_API __declspec(dllexport)
#else
#define FISH_SO_API __declspec(dllimport)
#endif
#endif

#ifdef FISH_PLATFORM_Linux
#define FISH_SO_API
#endif
