#include <iostream>

using namespace std;

void Katalan() {
	int n=0,
		ans=1;
	cout << "Введите длину последовательности: ";
	//cin >> n;
	__asm {
		MOV eax, 1 // В EAX будет факториал, на это число мы будем умножать все остальные.
		CMP n, 0 //проверка на ноль
		JE endd
       
		MOV ecx, n
		CALL factCycle //EAX=n!

		MOV ans, eax

		MOV eax, n
		ADD eax, 1   //n+1
		MOV n, eax
		MOV eax, 1 // В EAX будет факториал, на это число мы будем умножать все остальные.
		MOV ecx, n
		CALL factCycle //EAX=(n+1)!

		MUL ans
		MOV ans, eax
		
		MOV eax, n
		SUB eax, 1  //n-1
		MOV n, eax
		ADD eax, n   //2*n
		MOV n, eax
		MOV eax, 1 // В EAX будет факториал, на это число мы будем умножать все остальные.
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

	cout << "ответ: "<<ans;
}

int main() {
	setlocale(0,"");
	Katalan();
	return 0;
}