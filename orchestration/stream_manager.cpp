// stream_manager.cpp
#include "stream_manager.h"

std::vector<char> StreamManager::getChunk(const std::string& chunkId) {
    if (cache.hasChunk(chunkId)) {
        return cache.loadChunk(chunkId);
    }

    auto data = p2p.requestChunk(chunkId);

    if (!data.empty()) {
        cache.storeChunk(chunkId, data);
        return data;
    }

    // fallback para servidor central
    return {};
}
