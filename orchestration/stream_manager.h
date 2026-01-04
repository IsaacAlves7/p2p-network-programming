// stream_manager.h
#pragma once
#include "cache_manager.h"
#include "p2p_client.h"

class StreamManager {
public:
    std::vector<char> getChunk(const std::string& chunkId);

private:
    CacheManager cache;
    P2PClient p2p;
};
