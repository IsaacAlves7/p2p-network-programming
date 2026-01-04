// p2p_client.h
#pragma once
#include <string>
#include <vector>

class P2PClient {
public:
    void connectToPeer(const std::string& ip, int port);
    std::vector<char> requestChunk(const std::string& chunkId);
};
