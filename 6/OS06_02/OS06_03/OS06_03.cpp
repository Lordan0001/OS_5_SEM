#include <iostream>
#include <Windows.h>

#define KB (1024)
#define PG (4 * KB)

int main()
{
    int pages = 256;
    int countItems = pages * PG / sizeof(int);

    LPVOID xmemaddr = VirtualAlloc(NULL, pages * PG, MEM_COMMIT, PAGE_READWRITE);
    int* arr = (int*)xmemaddr;

    for (int i = 0; i < countItems; i++) {
        arr[i] = i;
    }


    //Б C1 193dec
    //Е C5 197dec
    //Л CB 203dec
    // page = 193
    //смещение = 3164
    //adress 193 * PG(4096) + 3164 = 793 692 (0C1C5C)
    //0x004C2DBD


    system("pause");

}

