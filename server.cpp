#include <iostream>
#include <thread>
#include <memory>
#include <boost/asio.hpp>

using namespace boost::asio;
using boost::asio::ip::udp;


const int PORT = 8080;

class Server
{
public:
    Server(io_context &io_context) : socket_(io_context, udp::endpoint(udp::v4(), PORT))
    {
        do_receive();
    }

private:
    void do_receive();
    void do_send(std::size_t length);

    udp::socket socket_;
    udp::endpoint sender_endpoint_;
    std::vector<udp::endpoint> clients;
    char data_[1024];
};

void Server::do_receive()
{
    {
        socket_.async_receive_from(
            boost::asio::buffer(data_, 1024), sender_endpoint_,
            [this](boost::system::error_code ec, std::size_t length)
            {
                if (std::find(clients.begin(), clients.end(), sender_endpoint_) == clients.end())
                {
                    clients.push_back(sender_endpoint_);
                    std::cout << "New client connected: " << sender_endpoint_ << std::endl;
                }
                if (!ec && length > 0)
                {
                    std::thread([this, length]()
                                { do_send(length); })
                        .detach();
                }
                do_receive();
            });
    }
}

void Server::do_send(std::size_t length)
{
    for (int i = 0; i != clients.size(); i++)
    {
        socket_.send_to(boost::asio::buffer(data_, length), clients[i]);
        std::cout << "Send data from server to client[" << i << "]" << std ::endl;
    }
}

int main()
{
    try
    {
        io_context io_context;
        Server server(io_context);
        io_context.run();
    }
    catch (std::exception &e)
    {
        std::cerr << "Exception: " << e.what() << std::endl;
    }
    return 0;
}