// os_windows.cpp
#ifdef _WIN32
#include "os.h"
#include <windows.h>

std::string OS::getCacheDirectory() {
    char path[MAX_PATH];
    GetTempPathA(MAX_PATH, path);
    return std::string(path) + "SpotifyCache\\";
}

void OS::sleepMs(int ms) {
    Sleep(ms);
}
#endif
