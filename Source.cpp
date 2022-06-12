#include <iostream>

using namespace std;

void Katalan() {
	int n;
	unsigned long ans;
	cout << "¬ведите длину последовательности: ";
	cin >> n;
	__asm {
		MOV eax, 1 // ¬ EAX будет факториал, на это число мы будем умножать все остальные.
		CMP n, 0 //проверка на ноль
		JE endd
       
		MOV ecx, n
		CALL factCycle //EAX=n!

		MOV ans, eax

		MOV eax, n
		ADD eax, 1   //n+1
		MOV n, eax
		MOV eax, 1 // ¬ EAX будет факториал, на это число мы будем умножать все остальные.
		MOV ecx, n
		CALL factCycle //EAX=(n+1)!

		MUL ans
		MOV ans, eax
		
		MOV eax, n
		SUB eax, 1  //n-1
		MOV n, eax
		ADD eax, n   //2*n
		MOV n, eax
		MOV eax, 1 // ¬ EAX будет факториал, на это число мы будем умножать все остальные.
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

	cout << "\nответ: "<<ans;
}

void Katalan2() {
	int n;
	double sum2 = 0;
	double sum1 = 0;
	double sum0 = 0;
	double sum = 0;
	cout << "¬ведите длину последовательности: ";
	cin >> n;
	__asm {

		CMP n, 0 //проверка на ноль
		JE endd





	////factCycle:
	////	    
	////		CMP ecx, 0
	////		JNE ecxnull
	////		MOV sum0, 0
	////		MOV sum1, 1
	////		JMP endfactCycle
	////	ecxnull:
	////	    
	////	    MOV eax,sum2
	////	    MUL sum1
	////	    ADD sum0, eax
	////		MOV sum0,eax

	////    endfactCycle:
	////	    ADD ecx, 1
	////	    CMP ecx,subn
	////	    JNE factCycle
	//LOOP factCycle
		//MOV ebx, 1 //(n - 1) - i=0 перва€ итераци€
		//MOV ecx, 0 //(n - 1) - i=0 перва€ итераци€
		//summa:
		//
		////MOV ecx, n
		//CMP ecx, 0 //проверка на ноль if (n == 0)
		//JE nnull

		//

		//	nnull :
		//MOV ebx, 1
		//	notsumma:
  //      ADD sum, ebx //sum=1

		//    forr:
  //     //i-- i
		//MOV eax, n
		//SUB eax, 1  //n-1
		//MOV ecx, eax //n=n-1 
		//MOV ebx, 0 //ebx=0
		//CALL summaa

		////-->

		//MOV eax, ebx
		//MUL sum      //eax=sum*ebx (so(i))
		//ADD sum, eax //sum=sum*ebx (so(i))

		//MOV eax, n
		//SUB eax, 1  //n-1
		//MOV n, eax //n=n-1 
		//MOV ecx, eax //ecx=n-1
		//CMP ecx, 0
		//JNE forr

		//	summaa:

		//MOV eax, n
		//SUB eax, 1  //n-1
		//MOV n, eax //n=n-1

		//MOV eax, ebx
		//MOV ecx, n
		//CMP ecx, 0
		//JNE summaa
		//RET
		//JMP notsumma

			endd:
		//MOV sum, 1		
//---------------------------------
	};

	cout << "\nответ: " << sum;
}

void Katalan3() {
	int n=15;
	long sum = 1;
	cout << "¬ведите длину последовательности: ";
	cin >> n;
	__asm {

		CMP n, 0 //проверка на ноль
		JE endd

		XOR ecx, ecx
   
summa:
		INC ecx
		MOV eax, ecx
		MOV ebx, 4
		MUL ebx    //4n
		SUB eax, 2 //4n-2

		MOV ebx, ecx
		INC ebx      //можно заменить на ADD ebx, 1 ;n+1
		MUL sum      //(4n-2)*sum
		DIV ebx      //(4n-2)*sum/(n+1) eax/ebx

		//MUL sum
		/*CMP sum,1*/
		MOV sum, eax

		
		CMP ecx, n
		JNE summa
endd:
	};

	cout << "\nответ: " << sum;
}

int main() {
	setlocale(0,"");
	//Katalan();
	//Katalan2();//C(N + 1) = C(N + 1) + C(I) * C(N - I) не работает
	Katalan3();//c=2*(2*i-1)*c/(i+1)
	return 0;
}