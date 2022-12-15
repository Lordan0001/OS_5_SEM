
#include <iostream>
#include <windows.h>
#include <process.h>
using namespace std;

int main()
{
    DWORD pid = GetCurrentProcessId();
    DWORD tid = GetCurrentThreadId();

    for (int i = 0; i < 10000; i++) {
        Sleep(1000);
        cout << "PID = " << pid << "\t TID = " << tid<< endl;
    }

}

//PowerShell ISE: get-process
// (get-process OS04_01).Threads
//и монитор ресурсов открой