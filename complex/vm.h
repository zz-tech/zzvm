
#ifndef vm_h
#define vm_h

#define SIGNATURES "bytecode@zzvm"

/** Registers */
typedef enum {
    A, B, C, D, E, F, I, J, // GENERAL PURPOSE
    EX,                     // EXCESS
    EXA,                    // MORE EXCESS
    IP,                     // INSTRUCTION POINTER
    SP,                     // STACK POINTER
    REGISTER_SIZE
} Registers;

#endif
