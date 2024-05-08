FACT MACRO F
    UP:
    MUL F
    DEC F
    JNZ UP
    ENDM

DATA SEGMENT
    NUM DW 05H
    RESULT DW ?                 
    DATA ENDS                                       

STACK SEGMENT
    DW 128 DUP(0)
    STACK ENDS

CODE SEGMENT
    START:
    MOV AX,DATA
    MOV DS,AX
    MOV CX,NUM                          
    
    MOV AX,0001H
    FACT NUM    
    MOV RESULT,AX
    CODE ENDS