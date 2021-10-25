//����� ���������� ������� A. � ������� A �������� 1 ������ �� ���������, 2 �� ������������� � �.�.�
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <iomanip>
#include <locale>
#include <conio.h>
using namespace std;

int main() {
	int n, m, result;		// ����������� �������
	setlocale(LC_ALL, "Russian");
	int **A ;	// �������

	cout << "������� ����������� ������� N=";
	cin >> n;
	cout << "������� ����������� ������� M=";
	cin >> m;
	A = new int* [n];	//��������� ������ ��� ����� �������
	for (int i = 0; i < n; i++)
		A[i] = new int[m];
	//for (int j = 0; j < m; j++)
		//A[j] = new int[m];
	cout << "" << endl;
	cout << "������� �������" << endl;
	for (int i = 0; i < n; i++)	//������ ������� � ����������
		for (int j = 0; j < m; j++)
			//cin >> A[i][j];
			A[i][j] = rand() % 10;
	cout << "" << endl;
	cout << "����" << endl;
	for (int i = 0; i < n; i++)    //������ ������� �� ����� 
	{
		for (int j = 0; j < m; j++)
			cout << setw(5) << A[i][j];
		cout << endl;
	}
	int y = 4;//������ ��������
	__asm
	{
		lea  ebx, y// ��������� �������� ������
		mov esi, n// ESI ����� ��������� ���������� �����,  ��������������� �������

		mov ecx, n// �������� � ECX ���������� �����
		L1 :
		mov edi, 0// ��������� �������� �������� � ������

		mov eax, 0// EAX ����� ��������� ����� ��������� ������
		mov edx, m// �������� � EDX ���������� ��������

		L2 : 
		add eax, [ebx][edi]//�������� � eax �������  ������ �������[ ]
		xchg eax, [ebp][edi] //������������ ���������
	    mov [ebp][edi], eax //�������� � ����� ������ - eax

		add edi, type y// ���������� � �������� �������� � ������ ������ ��������
		dec edx// ��������� �� 1 ������� ����������� �����

		cmp edx, 0// ���������� EDX � ����, ������� ������� �� ����������� �����
		jne L2// ���� EDX �� ����� 0, �� ��������� � ������ �����

		L3 :
		mov eax, m// ��������� � EAX ���������� ��������� � ������

		imul eax, type y// �������� ���������� ��������� � ������ �� ������ ��������

		add ebx, eax// ���������� � �������� ������ ������, �� ����, ������� �� ������ ��������� ������
		cmp     ebx, ebp//������� ���� ���� op1 < op2
		jb      L1// ������� � ����� L1
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
	cout << "�����" << endl;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
			cout << setw(5) << A[i][j]; //������ �� ����� ��������������� �������
		cout << endl;
	}
	system("pause");
	return 0;

}