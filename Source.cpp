#include <iostream>

using namespace std;

void Katalan() {
	int n;
	unsigned long ans;
	cout << "������� ����� ������������������: ";
	cin >> n;
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

	cout << "\n�����: "<<ans;
}

void Katalan2() {
	int n;
	double sum2 = 0;
	double sum1 = 0;
	double sum0 = 0;
	double sum = 0;
	cout << "������� ����� ������������������: ";
	cin >> n;
	__asm {

		CMP n, 0 //�������� �� ����
		JE endd





	factCycle:
		    
			CMP ecx, 0
			JNE ecxnull
			MOV sum0, 0
			MOV sum1, 1
			JMP endfactCycle
		ecxnull:
		    
		    MOV eax,sum2
		    MUL sum1
		    ADD sum0, eax
			MOV sum0,eax

	    endfactCycle:
		    ADD ecx, 1
		    CMP ecx,subn
		    JNE factCycle
	//LOOP factCycle
		//MOV ebx, 1 //(n - 1) - i=0 ������ ��������
		//MOV ecx, 0 //(n - 1) - i=0 ������ ��������
		//summa:
		//
		////MOV ecx, n
		//CMP ecx, 0 //�������� �� ���� if (n == 0)
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

		//	endd:
		//MOV sum, 1
//---------------------------------
	};

	cout << "\n�����: " << sum;
}

void Katalan3() {
	int n=4;
	long sum = 1;
	cout << "������� ����� ������������������: ";
	//cin >> n;
	__asm {
		/*XOR ecx,ecx*/
		CMP n, 0 //�������� �� ����
		JE endd

		//CMP n, 1 //�������� �� ����
		//JE endd

		MOV ecx, 1

		   summa:
        MOV eax, ecx
		MOV ebx, 4
		MUL ebx    //4n
		SUB eax, 2 //4n-2

		MOV ebx, ecx
		INC ebx      //����� �������� �� ADD ebx, 1 ;n+1
		MUL sum      //(4n-2)*sum
		DIV ebx      //(4n-2)/(n+1) eax/ebx

		MUL sum
		/*CMP sum,1*/
		MOV sum, eax

		INC ecx
		CMP ecx, n
		JNE summa
		
		JMP enddd

			endd :
		MOV sum, 1

		    enddd:
			//---------------------------------
	};

	cout << "\n�����: " << sum;
}

int main() {
	setlocale(0,"");
	//Katalan();
	//Katalan2();
	Katalan3();
	return 0;
}