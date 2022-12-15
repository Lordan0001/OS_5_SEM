// OS06_02.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <windows.h>
#include <process.h>
#include <bitset>

int main()
{
    DWORD pid = GetCurrentProcessId();
    DWORD tid = GetCurrentThreadId();

    for (int i = 0; i < 100000; i++) {
        std::cout << "\nPID:\t" << pid << "\nTID:\t" << tid;
        Sleep(1000);
    }
}

