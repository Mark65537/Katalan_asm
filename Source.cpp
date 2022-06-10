#include <iostream>

using namespace std;

void Katalan() {
	int n,ans;
	cout << "Введите длину последовательности: ";
	cin >> n;
	__asm {
		
		MOV eax, n
		ADD eax, n   //2*n
		MOV n, eax
		MOV eax, 1 // В EAX будет факториал, на это число мы будем умножать все остальные.
		MOV ecx, n
		JMP factCycle //EAX=(2*n)!




		factCycle :
		   MUL ecx
		LOOP factCycle

		MOV ans, eax
	};

	cout << "ответ: "<<ans;
}

int main() {
	setlocale(0,"");
	Katalan();
	return 0;
}