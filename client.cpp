#include <iostream>
#include <cstring>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <thread>

#define PORT 12345
#define BUFFER_SIZE 1024

void receive_messages(int sock) {
    char buffer[BUFFER_SIZE];
    while (true) {
        memset(buffer, 0, BUFFER_SIZE);
        int valread = read(sock, buffer, BUFFER_SIZE);
        if (valread <= 0) break;
        std::cout << buffer << std::endl;
    }
}

int main() {
    int sock = 0;
    struct sockaddr_in serv_addr;

    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        std::cerr << "Socket creation error" << std::endl;
        return -1;
    }

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);

    if (inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr) <= 0) {
        std::cerr << "Invalid address / Address not supported" << std::endl;
        return -1;
    }

    if (connect(sock, (struct sockaddr*)&serv_addr, sizeof(serv_addr)) < 0) {
        std::cerr << "Connection failed" << std::endl;
        return -1;
    }

    // Input name
    std::string name;
    std::cout << "Enter your name: ";
    std::getline(std::cin, name);
    send(sock, name.c_str(), name.size(), 0);

    // Start thread to receive server messages
    std::thread(receive_messages, sock).detach();

    while (true) {
        std::string msg;
        std::getline(std::cin, msg);
        send(sock, msg.c_str(), msg.size(), 0);
    }

    close(sock);
    return 0;
}
