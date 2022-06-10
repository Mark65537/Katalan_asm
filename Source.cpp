#include <iostream>

using namespace std;

void Katalan() {
	int n=0,
		ans=1;
	cout << "������� ����� ������������������: ";
	//cin >> n;
	__asm {
		MOV eax, 1 // � EAX ����� ���������, �� ��� ����� �� ����� �������� ��� ���������.
		CMP n, 0 //�������� �� ����
		JE endd
       
		MOV ecx, n
		CALL factCycle //EAX=n!

		MOV ans, eax

		MOV eax, n
		ADD eax, 1   //n+1
		MOV n, eax
		MOV eax, 1 // � EAX ����� ���������, �� ��� ����� �� ����� �������� ��� ���������.
		MOV ecx, n
		CALL factCycle //EAX=(n+1)!

		MUL ans
		MOV ans, eax
		
		MOV eax, n
		SUB eax, 1  //n-1
		MOV n, eax
		ADD eax, n   //2*n
		MOV n, eax
		MOV eax, 1 // � EAX ����� ���������, �� ��� ����� �� ����� �������� ��� ���������.
		MOV ecx, n
		CALL factCycle //EAX=(2*n)!

		DIV ans
		JMP endd

		factCycle :
		   MUL ecx
		LOOP factCycle
		RET

		endd:
		   MOV ans, eax
	};

	cout << "�����: "<<ans;
}

int main() {
	setlocale(0,"");
	Katalan();
	return 0;
}