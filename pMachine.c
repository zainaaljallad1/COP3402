#include <stdio.h>
#include <stdlib.h> 


#define MAX_STACK_HEIGHT 2000
#define MAX_CODE_LENGTH 500
#define MAX_LEXI_LEVELS 3

typedef struct ISA {
	int op; //opcode
	int r; //register [0 - 15] 
	int lex; //lexographical level or a register ? 
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
void lod (Stack *s, ISA *i, int *reg) {
	temp = base(i->lex, s->bp); 
	temp += i->m;
	reg[i->r] = s->array[temp]; 
}


//m is data adress
void sto (Stack *s, ISA *i, int *reg) {
	temp = base (i->lex, s->bp);
	temp += i->m; 
	s->array[temp] = reg[i->r];
}

//m is a program address
void cal (Stack *s, ISA *i, int *reg) {
	s->array[s->sp + 1] = 0;
	//s->array[s->sp + 2] = base
	s->array[s->sp + 3] = s->bp; 
	s->array[s->sp + 4] = s->pc;
	s->bp = s->sp + 1; 
	s->pc = i->m;  
}


//m is a #
void inc (Stack *s, ISA *i, int *reg) {
	s->sp = s->sp + i->m; 
}

//m is a program address
void jmp (Stack *s, ISA *i, int *reg) {
	s->pc = i->m; 
}

//m is a program address
void jpc (Stack *s, ISA *i, int *reg) {
	if (reg[i->r] == 0) 
		s->pc = i->m; 
}

void sio (Stack *s, ISA *i, int *reg, int n) {
	switch (n)

	case (1):
		printf(reg[i->r]); 
	case (2):
	case (3): 
}

int base (ISA *i, Stack *s) {
	int b1;
 	b1 = s->bp; 
	while (i->lex > 0) {
		b1 = s->array[b1 + i->lex]
		i->lex--; 
	} 

	return b1;  
}

void neg (ISA *i, int *reg) {
	reg[i->r] = -reg[i->lex]; 
}

void add (ISA *i, int *reg) {
	reg[i->r] = (reg[i->lex] + reg[i->m]); 	
}

void sub (ISA *i, int *reg) {
	reg[i->r] = (reg[i->lex] - reg[i->m]); 
}

void mul (ISA *i, int *reg) {
	reg[i->r] = (reg[i->lex] * reg[i->m]); 
}

void div (ISA *i, int *reg) {
	reg[i->r] = (reg[i->lex] / reg[i->m]); 
}

int odd (ISA *i, int *reg) {
	if(reg[i->r] % 2 == 0) 
		return 0;
	else 
		return 1;
}
void mod (ISA *i, int *reg) {
	reg[i->r] = (reg[i->lex] % reg[i>m]);
}

void eql (ISA *i, int *reg) {
	reg[i->r] = (reg[i->lex] == reg[i->m]); 
}

void neq (ISA *I, int *reg) {
	if (reg[i->lex] != reg[i->m])
		reg[i->r] = 1; 
	else 
		reg[i->r] = 0; 	
}

void lss (ISA *i, int *reg) {
	if (reg[i->lex] < reg[i->m]) 
		reg[i->r] = 1; 
	else 
		reg[i->r] = 0; 
}

void leq (ISA *i, int *reg) {
	if (reg[i->lex] <= reg[i->m])
		reg[i->r] = 1; 
	else
		reg[i->r] = 0; 
}

void gtr (ISA *i, int *reg) {
	if (reg[i->lex] > reg[i->m])
		reg[i->r] = 1; 
	else 
		reg[i->r] = 0; 
}

void geq (ISA *i, int *reg) {
	if(reg[i->lex] >= reg[i->m])
		reg[i->r] = 1;
	else 
		reg[i->r] = 0; 
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