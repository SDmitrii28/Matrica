//«Дана квадратная матрица A. В матрице A заменить 1 строку на последнюю, 2 на предпоследнюю и т.д.»
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <iomanip>
#include <locale>
#include <conio.h>
using namespace std;

int main() {
	int n, m, result;		// размерность матрицы
	setlocale(LC_ALL, "Russian");
	int **A ;	// матрица

	cout << "Введите размерность матрицы N=";
	cin >> n;
	cout << "Введите размерность матрицы M=";
	cin >> m;
	A = new int* [n];	//выделение памяти под новую матрицу
	for (int i = 0; i < n; i++)
		A[i] = new int[m];
	//for (int j = 0; j < m; j++)
		//A[j] = new int[m];
	cout << "" << endl;
	cout << "Введите матрицу" << endl;
	for (int i = 0; i < n; i++)	//Чтение матрицы с клавиатуры
		for (int j = 0; j < m; j++)
			//cin >> A[i][j];
			A[i][j] = rand() % 10;
	cout << "" << endl;
	cout << "было" << endl;
	for (int i = 0; i < n; i++)    //печать матрицы на экран 
	{
		for (int j = 0; j < m; j++)
			cout << setw(5) << A[i][j];
		cout << endl;
	}
	int y = 4;//размер элемента
	__asm
	{
		lea  ebx, y// Начальное смещение строки
		mov esi, n// ESI будет содержать количество строк,  удовлетворяющих условию

		mov ecx, n// Загрузка в ECX количества строк
		L1 :
		mov edi, 0// Начальное смещение элемента в строке

		mov eax, 0// EAX будет содержать сумму элементов строки
		mov edx, m// Загрузка в EDX количества столбцов

		L2 : 
		add eax, [ebx][edi]//помещаем в eax операнд  адреса матрицы[ ]
		xchg eax, [ebp][edi] //перестановку операндов
	    mov [ebp][edi], eax //помещаем в адрес памяти - eax

		add edi, type y// Прибавляем к смещению элемента в строке размер элемента
		dec edx// Уменьшаем на 1 счётчик внутреннего цикла

		cmp edx, 0// Сравниваем EDX с нулём, счетчик прохода по внутреннему циклу
		jne L2// Если EDX не равно 0, то переходим к началу цикла

		L3 :
		mov eax, m// Загружаем в EAX количество элементов в строке

		imul eax, type y// Умножаем количество элементов в строке на размер элемента

		add ebx, eax// Прибавляем к смещению размер строки, то есть, переход на начало следующей строки
		cmp     ebx, ebp//Переход если ниже op1 < op2
		jb      L1// переход к метке L1
	}

	for (int i = 0; i < n / 2; i++) 
	{
		for (int j = 0; j < m; j++) 
		{
			result = A[i][j];
			A[i][j] = A[n - i - 1][j];
			A[n - i - 1][j] = result;
		}
	}
	cout << "" << endl;
	cout << "стало" << endl;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
			cout << setw(5) << A[i][j]; //печать на экран преобразованной матрицы
		cout << endl;
	}
	system("pause");
	return 0;

}