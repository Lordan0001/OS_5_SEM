#include <iostream>
#include <windows.h>
#include <process.h>
using namespace std;

int main()
{
    for (int i = 0; i < 10000; i++) {
        Sleep(1000);
        cout << _getpid()  << endl;
    }
   
}