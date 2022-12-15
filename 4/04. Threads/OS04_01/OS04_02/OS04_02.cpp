#include <iostream>
#include <Windows.h>
#include <iostream>

using namespace std;

DWORD WINAPI OS04_02_T1() {
    DWORD pid = GetCurrentProcessId();
    DWORD tid = GetCurrentThreadId();

    for (int i = 0; i < 50; ++i) {

        cout << "\nPID = " << pid << ", TID = " << tid << "\tT1"<<endl;
        Sleep(1000);
    }

    return 0;
}

DWORD WINAPI OS04_02_T2() {
    DWORD pid = GetCurrentProcessId();
    DWORD tid = GetCurrentThreadId();

    for (int i = 0; i < 125; ++i) {

        cout << "\nPID = " << pid << ", TID = " << tid << "\tT2" << endl;
        Sleep(1000);
    }

    return 0;
}

int main() {
    DWORD pid = GetCurrentProcessId();
    DWORD tid = GetCurrentThreadId();

    DWORD childId_T1, childId_T2 = NULL;

    HANDLE hChild1 = CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)OS04_02_T1, NULL, 0, &childId_T1);
    HANDLE hChild2 = CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)OS04_02_T2, NULL, 0, &childId_T2);

    for (int i = 0; i < 100; ++i) {

       cout << "\nPID = " << pid << ", PT TID = " << tid<<endl ;
       Sleep(1000);
    }

    WaitForSingleObject(hChild1, INFINITE);
    WaitForSingleObject(hChild2, INFINITE);

    CloseHandle(hChild1);
    CloseHandle(hChild2);

    return 0;
}