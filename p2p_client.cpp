// p2p_client.cpp
#include "p2p_client.h"
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

void P2PClient::connectToPeer(const std::string& ip, int port) {
    // socket TCP direto, sem frescura
}

std::vector<char> P2PClient::requestChunk(const std::string& chunkId) {
    // envia ID do chunk
    // recebe bytes
    // retorna buffer bruto
    return {};
}
