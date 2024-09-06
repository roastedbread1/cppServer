#include <iostream>
#include <cpprest/http_listener.h>
#include <thread>
#include <chrono>

using namespace web;
using namespace web::http;
using namespace web::http::experimental::listener;

class OkAPI {
public:
    OkAPI(const std::string& address) : m_listener(address) {
        m_listener.support(methods::GET, std::bind(&OkAPI::handle_get, this, std::placeholders::_1));
    }

    void start() {
        m_listener.open().then([this]() {
            std::cout << "Listening on: " << m_listener.uri().to_string() << std::endl;
        }).wait();
    }

    void handle_get(http_request request) {
        // Print "OK" to the console
        std::cout << "OK" << std::endl;

        request.reply(status_codes::OK, "");
    }

private:
    http_listener m_listener;
};

int main() {
    const std::string address = "http://0.0.0.0:8080";
    OkAPI api(address);
    api.start();

    
    while (true) {
        std::this_thread::sleep_for(std::chrono::seconds(1)); 
    }

    return 0;
}