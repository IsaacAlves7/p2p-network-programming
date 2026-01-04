// os_macos.cpp
#ifdef __APPLE__
#include "os.h"
#include <unistd.h>

std::string OS::getCacheDirectory() {
    return std::string(getenv("HOME")) + "/Library/Caches/Spotify/";
}

void OS::sleepMs(int ms) {
    usleep(ms * 1000);
}
#endif
