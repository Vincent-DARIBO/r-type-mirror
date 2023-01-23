#include <iostream>
#include <boost/asio.hpp>
#include <boost/array.hpp>

struct Data {
    int x;
    std::string y;
};

void handle_send(const boost::system::error_code& error, std::size_t bytes_transferred) {
    if (!error) {
        std::cout << "Data sent successfully" << std::endl;
    } else {
        std::cout << "Error sending data: " << error.message() << std::endl;
    }
}

int main() {
    boost::asio::io_service io_service;

    boost::asio::ip::udp::socket socket(io_service);
    boost::asio::ip::udp::endpoint endpoint = boost::asio::ip::udp::endpoint(boost::asio::ip::address::from_string("127.0.0.1"), 8888);
    socket.open(endpoint.protocol());
    socket.bind(endpoint);

    Data data;
    data.x = 5;
    data.y = "test";

    boost::asio::streambuf send_buffer;
    std::ostream send_stream(&send_buffer);
    send_stream << data.x << data.y;

    socket.async_send_to(boost::asio::buffer(send_buffer.data()), endpoint, handle_send);

    io_service.run();

    return 0;
}
