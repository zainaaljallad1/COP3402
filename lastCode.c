#include <stdio.h>
#include <stdlib.h>

/*Zaina Aljallad - 3486788
COP 3402
P-machine */

#define MAX_STACK_HEIGHT 2000;
#define MAX_CODE_LENGTH 500;
#define MAX_LEXI_LEVELS 3;


typedef struct Instruction
{
    int op; //opcode
    unsigned int r; //reg
    unsigned int l; //L
    int m; //M

}Instruction;

typedef struct Stack
{
   int *array;
   int sp;
   int bp;
   int pc;
	int prevpc; 
   int length;


} Stack;


int base(Instruction *i, Stack *s)
{
    int b1 = 0;
    if (i->l > 3)
        i->l = 3;
    b1 = s->bp;
    while (i->l > 0)
    {
        b1 = s->array[b1 + 1];
        i->l -= 1;
    }
    return b1;
}

void lit(Stack *s, Instruction *i, int *reg)
{
   reg[i->r] = i->m;
	s->prevpc = s->pc; 
   s->pc += 1;

}
void rtn(Stack *s, Instruction *i)
{
   int temp = 0;
s->prevpc = s->pc; 
   s->sp = s->bp - 1;
   temp = s->sp + 3;
   s->bp = s->array[temp];
   temp = s->sp + 4;
   s->pc = s->array[temp];

}

void lod(Stack *s, Instruction *i, int *reg, int lex)
{
   int temp = lex + i->m;
   reg[i->r] = s->array[temp];
	s->prevpc = s->pc; 
   s->pc += 1;

}

void sto (Stack *s, Instruction *i, int *reg, int lex)
{
    //use i->l without function?
   int temp = lex + i->m;
   s->array[temp] = reg[i->r];
	s->prevpc = s->pc; 
	s->pc += 1; 


}
void cal (Stack *s, Instruction *i, int **ar, int lex, int j)
{
	int temp; 
	s->prevpc = s->pc; 
	s->pc = s->pc + 1; 	
		
   temp = s->sp + 1;
   s->array[temp] = 0;
	ar[j][0] = 0;

   temp = s->sp + 2; 
   s->array[temp] = lex;
	ar[j][1] = s->array[temp];

   temp = s->sp + 3; 
   s->array[temp] = s->bp;
   ar[j][2] = s->array[temp];

	temp = s->sp + 4;
   s->array[temp] = s->pc;
	ar[j][3] = s->array[temp];
  
	temp = s->sp + 1; 
   s->bp = temp;
   s->pc = i->m;
}
void inc (Stack *s, Instruction *i)
{
   s->prevpc = s->pc; 
   s->sp = s->sp + i->m;
   s->pc += 1;

}
void jmp(Stack *s, Instruction *i)
{
	s->prevpc = s->pc; 
   s->pc = i->m;
}
void jpc(Stack *s, Instruction *i, int *reg)
{
	s->prevpc = s->pc; 
    if(reg[i->r] == 0)
        s->pc = i->m;

}
void neg(Stack *s, Instruction *i, int *reg)
{
	int temp = base(i, s); 	
   reg[i->r] = -(temp);
}
void add(Stack *s, Instruction *i, int *reg)
{
    reg[i->r] = reg[i->m] + reg[i->l];
}
void sub(Stack *s, Instruction *i, int *reg)
{
    reg[i->r] = reg[i->l] - reg[i->m];


}
void mul(Stack *s, Instruction *i, int *reg)
{
    int temp = 0;
    temp = reg[i->l] * reg[i->m];
    reg[i->r] = temp;

}

void divi(Stack *s, Instruction *i, int *reg)
{
    int temp = reg[i->l] / reg[i->m];
    reg[i->r] = temp;

}
void odd(Stack *s, Instruction *i, int *reg)
{
    reg[i->r] = i->r % 2;
}
void mod(Stack *s, Instruction *i, int *reg)
{
    int temp = 0;
    temp = reg[i->l] % reg[i->m];
    reg[i->r] = temp;
}
void eql(int *reg, Instruction *i)
{
	reg[i->r] = (reg[i->l] == reg[i->m]); 
}
void neq (int *reg, Instruction *i)
{
	reg[i->r] = (reg[i->l] != reg[i->m]); 
}
void lss (int *reg, Instruction *i)
{
	reg[i->r] = (reg[i->l] < reg[i->m]); 
} 
void leq (int *reg, Instruction *i)
{
	reg[i->r] = (reg[i->l] <= reg[i->m]); 
}
void gtr (int *reg, Instruction *i)
{
	reg[i->r] = (reg[i->l] > reg[i->m]); 
}
void geq (int *reg, Instruction *i)
{
	reg[i->r] = (reg[i->l] >= reg[i->m]); 
}
void print(Stack *s, Instruction *i, int **ar, int *reg, char *str, int counter, int j)
{
	int x = 0, k, temp = s->pc;
	
	if (counter == 0) 
	{
		printf("Factorial Stack Trace:\n"); 
	
		printf("Inital Values\t pc bp sp  Stack\n");
		
	}
	
	printf("%d %s %d %d %d \t %d  %d  %d   " 
				,s->prevpc ,str, i->r, i->l, i->m, s->pc, s->bp, s->sp);
		
	for(k = 0; k < 7; k++)
			printf("%d ", s->array[k]);

	if(ar != NULL) 
	{
		
		for(k = 0; k < j; k++) 
		{
			printf("| "); 

			for(x = 0; x < 4; x++)
				printf("%d " , ar[k][x]);
		}
				
	}
	printf("\nRF: ");
	for(x = 0; x < 8; x++)
	{
		if(x != 7) 
			printf("%d, " , reg[x]);
		else
			printf("%d" , reg[x]); 
	} 

	printf("\n");
}

int main (void)
{
	FILE *fp = fopen("input.txt", "r"); 
	int HALT = 0, j = 0, lex, counter = 0, x, rows = 500, cols = 4, temp = 0;
   int *reg = (int *) calloc(8, sizeof(int));
 	int **ar = NULL; 

	Stack *s = malloc(sizeof(Stack));
	s->length = MAX_STACK_HEIGHT;
	s->array = calloc(s->length, sizeof(Stack));

   Instruction *i = malloc(sizeof(Instruction));

	if(ar == NULL) 
	{
		ar = malloc(sizeof(int *) * rows); 
		for(x = 0; x < cols; x++)
			ar[x] = malloc(sizeof(int) * cols); 
	}
	
   s->sp = 0;
   s->bp = 1;
   s->pc = 0;
s->prevpc = s->pc; 
	
	do { 
		fscanf(fp, "%d %d %d %d", &(i->op), &(i->r), &(i->l), &(i->m));
   
		switch (i->op)    
		{               
			case (1):                  
				lit(s, i, reg);          
				print(s, i, ar, reg, "lit", counter, j);           
				break;               
			case (2):
				rtn(s, i);
				print(s, i, ar, reg, "rtn", counter, j);
				break;
			case (3):
				lex = base(i, s);;
				lod(s, i, reg, lex);
				print(s, i, ar, reg, "lod", counter, j);
				break;
			case (4):
				lex =  base(i, s);
				sto(s, i, reg, lex);
				print(s, i, ar, reg, "sto", counter, j);
				break;
			case (5):	
				lex = base(i, s);
				cal(s, i, ar, lex , j);
				print(s, i, ar, reg, "cal", counter, j);
				j++;
				break;
			case (6):
				inc(s, i); 
				print(s, i, ar, reg, "inc", counter, j);
				break;
			case (7):
				jmp(s, i);
				print(s, i, ar, reg, "jmp", counter, j);
				break;
			case (8):
				jpc(s, i, reg);
				print(s, i, ar, reg, "jpc", counter, j);
				break;
			case (9):
				switch (i->m)
				{
					case (1):
						for(x = 0; x < 8; x++)
							printf("%d " , reg[x]); 
						printf("\n"); 
						break;
					case (2):
						scanf("%d", &reg[i->r]);
						break;
					case (3):
						for(x = 0; x < 8; x++)
							temp += reg[x]; 
						printf("Factorial Output: %d\n", temp); 
						HALT = 1;
						break;
				}
				break; 
			case (10):
				neg(s, i, reg);
				print(s, i, ar, reg, "neg", counter, j);
				break;
			case (11):
				add(s, i, reg);
				print(s, i, ar, reg, "add", counter, j);
				break;
			case (12):
				sub(s, i, reg);
				print(s, i, ar, reg, "sub", counter, j);
				break;
			case (13):
				mul(s, i, reg);
				print(s, i, ar, reg, "mul", counter, j);
				break;
			case (14):
				divi(s, i, reg);
				print(s, i, ar, reg, "div", counter, j);
				break;
			case (15):
				odd(s, i , reg);
				print(s, i, ar, reg, "odd", counter, j);
				break;
			case (16):
				mod(s, i, reg);
				print(s, i, ar, reg, "mod", counter, j);
				break; 
			case(17):
				eql(reg, i); 
				print(s, i, ar, reg, "eql", counter, j);
				break;
			case(18):
				neq(reg, i);
				print(s, i, ar, reg, "neq", counter, j); 
				break;
			case(19):
				lss(reg, i); 
				print(s, i, ar, reg, "lss", counter, j);
				break;
			case(20):
				leq(reg, i); 
				print(s, i, ar, reg, "leq", counter, j);
				break;
			case(21):
				gtr(reg, i); 
				print(s, i, ar, reg, "gtr", counter, j);
				break;
			case(22):
				geq(reg, i); 
				print(s, i, ar, reg, "geq", counter, j);
				break; 
		}
		counter++;
	}
	while (HALT == 0);

	return 0;
}