//#include <iostream>
//#include <ctime>
//#include <Windows.h>
//
//DWORD WINAPI A();
//DWORD WINAPI B();
//
//void LockSemaph();
//void UnlockSemaph();
//
//int check = 0;
//
//int main() {
//	DWORD AId = NULL, BId = NULL;
//	HANDLE hA = CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)A, NULL, 0, &AId);
//	HANDLE hB = CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)B, NULL, 0, &BId);
//
//	WaitForSingleObject(hA, INFINITY);	
//	WaitForSingleObject(hB, INFINITY);
//	CloseHandle(hA); 
//	CloseHandle(hB);
//
//	system("pause");
//	return 0;
//}
//
//DWORD WINAPI A() {
//	int start = clock();
//
//	LockSemaph();
//	for (int i = 0; i < 5; i++) {
//		std::cout << "A:" << i << ", time: " << clock() - start << std::endl;
//	}
//	UnlockSemaph();
//
//	return 0;
//}
//
//DWORD WINAPI B() {
//	int start = clock();
//
//	LockSemaph();
//	for (int i = 0; i < 5; i++) {
//		std::cout << "B:" << i << ", time: " << clock() - start << std::endl;
//	}
//	UnlockSemaph();
//
//	return 0;
//}
//
//void LockSemaph() {
//	_asm {
//	CriticalSection:
//		lock bts check, 0;
//		jc CriticalSection
//	}
//}
//
//void UnlockSemaph() {
//	_asm lock btr check, 0
//}




#include <iostream>
#include <ctime>
#include <Windows.h>

using namespace std;

DWORD WINAPI A();
DWORD WINAPI B();

void EnterCriticalSectionAssem();
void LeaveCriticalSectionAssem();

int check = 0;

int main() {
	DWORD AId = NULL, BId = NULL;
	HANDLE hA = CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)A, NULL, 0, &AId);
	HANDLE hB = CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)B, NULL, 0, &BId);

	WaitForSingleObject(hA, INFINITY);
	WaitForSingleObject(hB, INFINITY);

	CloseHandle(hA); CloseHandle(hB);

	system("pause");
	return 0;
}

DWORD WINAPI A() {
	int start = clock();

	EnterCriticalSectionAssem();
	for (int i = 0; i < 5; i++) {
		cout << "A:" << i << ", time: " << clock() - start << endl;
	}
	LeaveCriticalSectionAssem();

	return 0;
}

DWORD WINAPI B() {
	int start = clock();

	EnterCriticalSectionAssem();
	for (int i = 0; i < 5; i++) {
		cout << "B:" << i << ", time: " << clock() - start << endl;
	}
	LeaveCriticalSectionAssem();

	return 0;
}

void EnterCriticalSectionAssem() {
	//Префикс lock, помещенный перед командой, устанавливает сигнал на линии LOCK системной шины и запрещает доступ к шине другим процессорам на время выполнения данной команды.
	//Команда BTS сохраняет значение бита, из первого операнда со смещением, указанным вторым операндом, во флаге CF, а затем устанавливает этот бит в 1.
	//нулевой бит в чек выставляем в 1 = вход в секцию
	_asm {
	CriticalSection:
		lock bts check, 0;
		jc CriticalSection
	}
}

void LeaveCriticalSectionAssem() {
	//Команда BTR сохраняет значение бита, из первого операнда со смещением, указанным вторым операндом, во флаге CF, а затем обнуляет этот бит.
	//нулевой бит в чек сбрасываем в 0 = выход из секции
	_asm lock btr check, 0
}