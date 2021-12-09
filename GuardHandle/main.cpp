// Написать собственный guard, управляющий дескриптором, 
// полученным в результате вызова функции Win32 API CreateFile.

#define WIN32_LEAN_AND_MEAN             // Exclude rarely-used stuff from Windows headers

#include <windows.h>
#include <fileapi.h>
#include <iostream>

class GuardHandle {
public:
    explicit GuardHandle(HANDLE& h) : h_(h) {};
    ~GuardHandle() {
        CloseHandle(h_);
    }
private:
    HANDLE& h_;
};

int main() {
	HANDLE h = CreateFileA("tmp.txt",   // name of the write
        GENERIC_WRITE,                  // open for writing
        0,                              // do not share
        NULL,                           // default security
        CREATE_NEW,                     // create new file only
        FILE_ATTRIBUTE_NORMAL,          // normal file
        NULL);

    if (h != INVALID_HANDLE_VALUE) {
        GuardHandle guard(h);
    }
    else {
        DWORD err = GetLastError();
        std::cout << "Error: " << err;
        return 1;

    }
}