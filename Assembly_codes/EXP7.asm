DATA SEGMENT
    SEG1 DB 1H,2H,3H
    DATA ENDS

EXTRA SEGMENT
    SEG2 DB ?
    EXTRA ENDS  

CODE SEGMENT
    ASSUME: DS:DATA, ES:EXTRA
    START:
    MOV AX,DATA
    MOV DS,AX
    MOV AX,EXTRA
    MOV ES,AX
    
    LEA SI,SEG1
    LEA DI,SEG2
    MOV CX,03H   
    
    X: MOV AH,DS:[SI]
    MOV ES:[DI],AH
    
    INC SI
    INC DI
    DEC CX
    JNZ X
    
    CODE ENDS
END START