DATA SEGMENT
    ARR DB 3,2,1,5,6,7,9,4
    LEN DW $-ARR
    MAX DB ?
    MIN DB ?
    DATA ENDS

CODE SEGMENT
    ASSUME DS:DATA CS:CODE
    START:
    MOV AX,DATA
    MOV DS,AX
    
    LEA SI,ARR 
    MOV AL,ARR[SI]
    MOV MAX,AL
    MOV MIN,AL
              
    MOV CX,LEN
    REPEAT:
    MOV AL,ARR[SI]
    CMP MIN,AL
    JL CHECKMAX
    
    MOV MIN,AL
    CHECKMAX:
    CMP MAX,AL
    JG DONE
    MOV MAX,AL
    
    DONE:
    INC SI
    LOOP REPEAT
                  
    MOV AH,4CH
    INT 21H
    CODE ENDS
END START