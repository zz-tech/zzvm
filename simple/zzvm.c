
#include <stdio.h>
#include <stdbool.h>

bool running = true;
int ip = 0;
int sp = -1;

int stack[256];

typedef enum {
   PSH,
   ADD,
   POP,
   HLT
} InstructionSet;

const int program[] = {
    PSH, 15,
    PSH, 26,
    ADD,
    POP,
    HLT
};

int fetch() {
    return program[ip];
}

int next() {
    return program[++ip];
}

void eval(int instr) {
    switch (instr) {
        case HLT: {
            running = false;
            printf("done\n");
            break;
        }
        case PSH: {
    	    sp++;
	        stack[sp] = next();
	        break;
        }
        case POP: {
	        int val_popped = stack[sp--];
	        printf("popped %d\n", val_popped);
	        break;
	    }
	    case ADD: {
	        // first we pop the stack and store it as a
	        int a = stack[sp--];
	    
	        // then we pop the top of the stack and store it as b
	        int b = stack[sp--];

	        // we then add the result and push it to the stack
	        int result = b + a;
	        sp++; // increment stack pointer **before**
	        stack[sp] = result; // set the value to the top of the stack

	        // all done!
	        break;
	    }
    }
}

int main(void) {
    while (running) {
        eval(fetch());
        ip++; // increment the ip every iteration
    }
}
