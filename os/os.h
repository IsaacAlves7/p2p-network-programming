// os.h
#pragma once
#include <string>

class OS {
public:
    static std::string getCacheDirectory();
    static void sleepMs(int ms);
};
