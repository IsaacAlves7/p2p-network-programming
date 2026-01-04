// cache_manager.cpp
#include "cache_manager.h"
#include "os.h"
#include <fstream>

bool CacheManager::hasChunk(const std::string& chunkId) {
    std::ifstream file(OS::getCacheDirectory() + chunkId, std::ios::binary);
    return file.good();
}

std::vector<char> CacheManager::loadChunk(const std::string& chunkId) {
    std::ifstream file(OS::getCacheDirectory() + chunkId, std::ios::binary);
    return std::vector<char>(
        std::istreambuf_iterator<char>(file),
        std::istreambuf_iterator<char>()
    );
}

void CacheManager::storeChunk(const std::string& chunkId, const std::vector<char>& data) {
    std::ofstream file(OS::getCacheDirectory() + chunkId, std::ios::binary);
    file.write(data.data(), data.size());
}
