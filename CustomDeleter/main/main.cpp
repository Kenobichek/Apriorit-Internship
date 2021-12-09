// Написать custom deleter для std::unique_ptr 
// тремя различными способами, закрывающий socket.


#include <iostream>
#include <Windows.h>

class Functor {
public:
    void operator()(SOCKET* pSocket){
        std::cout << "delete 1\n";
        delete pSocket;
    }
};

void delSocket(SOCKET* pSocket){
    std::cout << "delete 2\n";
    delete pSocket;
}

auto delSocket_anonim = [](SOCKET* pSocket) {
    std::cout << "delete 3\n";
    delete pSocket;
};

int main() {

    std::unique_ptr<SOCKET, Functor> p1(new SOCKET);

    std::unique_ptr<SOCKET, void(*)(SOCKET*)> p2(new SOCKET, delSocket);

    std::unique_ptr<SOCKET, decltype(delSocket_anonim)> p3(new SOCKET, delSocket_anonim);

    return 0;
}