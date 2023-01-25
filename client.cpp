#include <iostream>
#include <boost/asio.hpp>
#include <boost/array.hpp>
#include <chrono>
#include <thread>

using namespace boost::asio;

struct Data
{
    int a;
    float b;
    char c[20];
};

int main()
{
    io_service service;
    ip::udp::endpoint endpoint(ip::udp::v4(), 0);
    ip::udp::socket socket(service, endpoint);
    ip::udp::endpoint server_endpoint(ip::address::from_string("127.0.0.1"), 8080);

    while (true) {
        Data data;
        data.a = 1;
        data.b = 3.14f;
        std::strcpy(data.c, "Salut!");
        boost::array<char, sizeof(Data)> send_buf;
        std::memcpy(send_buf.data(), &data, sizeof(Data));
        socket.send_to(buffer(send_buf), server_endpoint);
        std::cout << "Sent data: " << data.a << ", " << data.b << ", " << data.c << std::endl;
        std::this_thread::sleep_for(std::chrono::seconds(2));
    }
    return 0;
}
