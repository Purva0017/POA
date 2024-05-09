DATA SEGMENT
    arr DB 2,1,5,8
    len DW $-arr
    addition DB ?
    avg DB ?
DATA ENDS

CODE SEGMENT
    start:
        MOV AX, DATA
        MOV DS, AX
        
        LEA SI, arr
        MOV CX, len   
        MOV AX, 00H 
        
        CLC
        
     sum_loop:
        MOV BX, [SI]
        ADC AX, BX
        
        INC SI
        DEC CX
        JNZ sum_loop 
        
        MOV addition, AH
        
        MOV CX, len
        
        
        DIV CX   
        
        MOV avg, AH  
      
        HLT
    END start
CODE ENDS