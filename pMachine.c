#include <stdio.h>
#include <stdlib.h> 


#define MAX_STACK_HEIGHT 2000
#define MAX_CODE_LENGTH 500
#define MAX_LEXI_LEVELS 3

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
	s->bp = s->bp -1;
	s->sp = s->bp;
	s->bp = s->array[(s->sp + 3)];
	s->pc = s->array[(s->sp + 4)]; 
}

//m is data address
//calculate base
void lod (Stack *s, ISA *i, int *reg) {
	reg[i->r] = s->array[base(l, bp) + i->m]; 
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
		printf(reg[i->r]); 
	case (2):
	case (3): 
}





int main (void) {

	ISA *i; 
	Stack *s; 
	int len = s->length; 

	s->sp = 0; 
	s->bp = 1; 
	s->pc = 0; 
	i->r = 0; 
	
	s->array = (int *) calloc (len, sizeof(int)); 

} 