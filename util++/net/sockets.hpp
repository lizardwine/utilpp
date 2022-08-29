#include <arpa/inet.h>
#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <unistd.h>
#include <iostream>

using namespace std;
typedef int Socket;


class client{
    private:
        int sock, client_fd;
        struct sockaddr_in serv_addr;

    public:
        client(string, int);
        bool Connect();
        void Send(string);
        string Recv(int);
        void Close();
};

client::client(string ip,int port){
    if ((this->sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        printf("\n Socket creation error \n");
        
    }
    this->serv_addr.sin_family = AF_INET;
    this->serv_addr.sin_port = htons(port);
    if (inet_pton(AF_INET, ip.c_str(), &this->serv_addr.sin_addr)
        <= 0) {
        printf("\nInvalid address/ Address not supported \n");
    
    }

     
  
}
bool client::Connect(){
    if ((this->client_fd = connect(this->sock, (struct sockaddr*)&this->serv_addr, sizeof(this->serv_addr)))
        < 0) {
        return false;
    } 
    return true;
}
void client::Send(string data){
    send(this->sock, data.c_str(), strlen(data.c_str()), 0);

}
string client::Recv(int buffer){
    int valread;
    char buf[buffer];
    valread = read(this->sock, buf, buffer);
    string bufstr = "";
    bufstr += buf;
    return bufstr.substr(0,valread);
}
void client::Close(){
    close(this->client_fd);
}

class server{
    private:
        string ip;
        struct sockaddr_in address;
        int port, server_fd, opt = 1,addrlen = sizeof(address);
    public:
        Socket Accept();
        void Close_socket(int);
        void Shutdown();
        bool Bind();
        string Recv(Socket,int);
        void Send(Socket,string);
        server(string, int);

};
server::server(string ip, int port){
    this->ip = ip;
    this->port = port;
    if ((this->server_fd = socket(AF_INET, SOCK_STREAM, 0))
        == 0) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }
    if (setsockopt(this->server_fd, SOL_SOCKET,
                   SO_REUSEADDR | SO_REUSEPORT, &this->opt,
                   sizeof(this->opt))) {
        perror("setsockopt");
        exit(EXIT_FAILURE);
    }
    this->address.sin_family = AF_INET;
    this->address.sin_addr.s_addr = INADDR_ANY;
    this->address.sin_port = htons(port);
}
bool server::Bind(){
    // Forcefully attaching socket to the port 8080
    if (bind(this->server_fd, (struct sockaddr*)&this->address,
             sizeof(this->address))
        < 0) {
        perror("bind failed");
        return false;
    }
    if (listen(this->server_fd, 3) < 0) {
        perror("listen");
        return false;
    }
    return true;
}
Socket server::Accept(){
    int new_socket;
    if ((new_socket
         = accept(this->server_fd, (struct sockaddr*)&this->address,
                  (socklen_t*)&this->addrlen))
        < 0) {
        perror("accept");
        exit(EXIT_FAILURE);
    }
    return new_socket;
}
string server::Recv(Socket socket,int buffer_size){
    char buffer[buffer_size];
    int valread = read(socket, buffer, buffer_size);
    string result = "";
    result += buffer;
    return result.substr(0,valread);
}
void server::Send(Socket socket, string data){
    send(socket, data.c_str(), strlen(data.c_str()), 0);
}
void server::Close_socket(Socket socket){
    close(socket);
}
void server::Shutdown(){
    shutdown(this->server_fd, SHUT_RDWR);
}
