#include <iostream>
#include <boost/asio.hpp>
#include <boost/array.hpp>
#include <vector>
#include <thread>

#include <chrono>

using namespace boost::asio;

// Structure de données à envoyer
struct Data
{
    int a;
    float b;
    char c[20];
};

int main()
{
    io_service service;
    ip::udp::endpoint endpoint(ip::udp::v4(), 8080);
    ip::udp::socket socket(service, endpoint);

    std::vector<ip::udp::endpoint> connected_clients;
    boost::array<char, sizeof(Data)> recv_buf;

    while (true)
    {
        ip::udp::endpoint sender_endpoint;
        size_t len = socket.receive_from(buffer(recv_buf), sender_endpoint);

        bool client_found = false;
        for (auto &endpoint : connected_clients)
        {
            if (endpoint == sender_endpoint)
            {
                // std::cout << "sender endpoint " << sender_endpoint << std::endl;
                //  Décoder les données binaires reçues
                Data data;
                std::memcpy(&data, recv_buf.data(), sizeof(Data));

                std::cout << "Received data from " << endpoint << " : " << data.a << ", " << data.b << ", " << data.c << std::endl;
                client_found = true;
                break;
            }
        }

        if (!client_found)
        {
            std::cout << "New client connected from: " << sender_endpoint << std::endl;
            connected_clients.emplace_back(sender_endpoint);
        }
    }
    return 0;
}
