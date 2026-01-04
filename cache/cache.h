// cache_manager.h
#pragma once
#include <string>
#include <vector>

class CacheManager {
public:
    bool hasChunk(const std::string& chunkId);
    std::vector<char> loadChunk(const std::string& chunkId);
    void storeChunk(const std::string& chunkId, const std::vector<char>& data);
};
