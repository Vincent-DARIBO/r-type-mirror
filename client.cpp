#include <iostream>
#include <boost/asio.hpp>
#include <boost/archive/binary_iarchive.hpp>
#include <boost/archive/binary_oarchive.hpp>
#include <boost/serialization/access.hpp>
#include <sstream>

const int PORT = 8080;

struct Data
{
    int a;
    float b;
    std::string c;

    template <typename Archive>
    void serialize(Archive &ar, const unsigned int version)
    {
        ar &a;
        ar &b;
        ar &c;
    }
};

class Client
{
public:
    Client(boost::asio::io_context &io_context) : socket_(io_context, boost::asio::ip::udp::endpoint(boost::asio::ip::udp::v4(), 0)) {}

    void send_data(const Data &data);
    void receive_data();

private:
    boost::asio::ip::udp::socket socket_;
    boost::asio::ip::udp::endpoint sender_endpoint_;
    char data_[1024];
};

void Client::send_data(const Data &data)
{
    std::ostringstream oss;
    boost::archive::binary_oarchive oa(oss);
    oa << data;

    socket_.send_to(boost::asio::buffer(oss.str()), boost::asio::ip::udp::endpoint(boost::asio::ip::address_v4::loopback(), PORT));
}

void Client::receive_data()
{
    socket_.async_receive_from(boost::asio::buffer(data_, 1024), sender_endpoint_, [this](const boost::system::error_code &ec, std::size_t length)
    {
        if (!ec && length > 0)
        {
            Data received_data;
            std::istringstream iss(std::string(data_, length));
            boost::archive::binary_iarchive ia(iss);
            ia >> received_data;
            std::cout << "Received data: " << received_data.a << " " << received_data.b << " " << received_data.c << std::endl;
        }
        else
        {
            std::cerr << "Error: " << ec.message() << std::endl;
        }
    });
}

int main()
{
    try
    {
        boost::asio::io_context io_context;
        Client client(io_context);

        Data data;
        data.a = 10;
        data.b = 3.14f;
        data.c = "Hello from client";
        client.send_data(data);

        Data received_data;
        client.receive_data();
        std::cout << "Received Data From Server: " << received_data.a << " " << received_data.b << " " << received_data.c << std::endl;
        io_context.run();
    }
    catch (std::exception &e)
    {
        std::cerr << "Exception: " << e.what() << std::endl;
    }
    return 0;
}