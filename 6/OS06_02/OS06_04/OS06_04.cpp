#include <iostream>
#include <Windows.h>
using namespace std;

void HeapInfo(HANDLE pheap)
{
    PROCESS_HEAP_ENTRY phe;
    phe.lpData = NULL;
    while (HeapWalk(pheap, &phe))
    {
        cout << "-- address = " << hex << phe.lpData
            << ", size = " << dec << phe.cbData
            << ((phe.wFlags & PROCESS_HEAP_REGION) ? " R" : "") // начало непрерывной области
            << ((phe.wFlags & PROCESS_HEAP_UNCOMMITTED_RANGE) ? " U" : "") // нераспределенная область
            << ((phe.wFlags & PROCESS_HEAP_ENTRY_BUSY) ? " B" : "") // распределенная область
            << "\n";
    }
    std::cout << "-----------------------------------\n\n";
}

int main()
{
    HANDLE pheap = GetProcessHeap();
    HANDLE heap = HeapCreate(HEAP_NO_SERIALIZE | HEAP_ZERO_MEMORY, 4096, 0);//выделяем

    HeapInfo(heap);

    int size = 300000;
    int* m = new int[size];

    cout << "adress = " << hex << m << ", size = " << dec << size << " \n\n";

    int* mm = (int*)HeapAlloc(heap, HEAP_NO_SERIALIZE | HEAP_ZERO_MEMORY, 300000 * sizeof(int));
    cout << "-adress = " << hex << mm << ", size = " << dec << 300000 << " \n\n";

    HeapInfo(heap);
}

