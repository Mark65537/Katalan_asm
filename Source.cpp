#include <iostream>

using namespace std;

void Katalan() {
	int n,ans;
	cout << "������� ����� ������������������: ";
	cin >> n;
	__asm {
		
		MOV eax, n
		ADD eax, n   //2*n
		MOV n, eax
		MOV eax, 1 // � EAX ����� ���������, �� ��� ����� �� ����� �������� ��� ���������.
		MOV ecx, n
		JMP factCycle //EAX=(2*n)!




		factCycle :
		   MUL ecx
		LOOP factCycle

		MOV ans, eax
	};

	cout << "�����: "<<ans;
}

int main() {
	setlocale(0,"");
	Katalan();
	return 0;
}