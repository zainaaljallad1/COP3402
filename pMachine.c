#include <stdio.h>
#include <stdlib.h> 

typedef struct ISA {
	int op; //opcode
	int r; //register [0 - 15] 
	int l; //lexographical level or a register ? 
	int m; // depends (is arithemtic and logic inst. for add, mul, etc)
}ISA; 

typedef struct Stack {
	int *array; 
	int sp; //stack pointer
	int bp; //base pointer
	int pc; // program counter
	int prevPC; 
	int length; 
}Stack; 


InstructionRegister - IR 


PM/0 has 24 instructions 
FORMAT: OP R L M 


/*Load register into array and update stack*/
//m refers to a #
void lit (Stack *s, ISA *i, int *reg) {
	reg[i->r] = i->m; 
	s->prevpc = s->pc
	s->pc += 1; 
}

int rtn (Stack *s) {
}

//m is data address
void lod (Stack *s, ISA *i, int *reg) {
}


//m is data adress
void sto (Stack *s, ISA *i, int *reg) {
}

//m is a program address
void cal (Stack *s, ISA *i, int *reg) {
}


//m is a #
void inc (Stack *s, ISA *i, int *reg) {
}

//m is a program address
void jmp (Stack *s, ISA *i, int *reg) {
}

//m is a program address
void jpc (Stack *s, ISA *i, int *reg) {
}

void sio (Stack *s, ISA *i, int *reg, int n) {
	switch (n)

	case (1):
		printf(reg[i->r]
	case (2):
	case (3): 
}





int main (void) {

	

} 