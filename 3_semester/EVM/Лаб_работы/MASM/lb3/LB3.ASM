;Вариант 3   │   1.4.3 
;
;        / 15-2*i,  при  a>b   │
;  f1 = <                      │
;        \ 3*i+4,  при  a<=b   │
;                              |         / |i1+i2|, при  k=0
;                              │   f3 = <
;                              │         \ min(i1,i2), при  k/=0
;        /-(6*i-4), при  a>b   │
;  f4 = <                      │ 
;        \ 3*(i+2), при  a<=b  |



AStack SEGMENT STACK
    DW 12 DUP(?)
AStack ENDS

DATA SEGMENT
    a DW 6
    b DW 5
    i DW 2
    i1 DW 0
    i2 DW 0
    k DW 0
    res DW 0
DATA ENDS

CODE SEGMENT
    ASSUME CS:CODE, DS:DATA, SS:AStack

Main    PROC FAR
    push DS
    sub AX, AX
    push AX
    mov AX, DATA
    mov DS, AX
                ; запись в регистры i с побитовым сдвигом
    mov CX, i   ; cx = i
    sal CX, 1   ; cx = 2*i
    mov BX, CX  ; bx = 2*i
    add BX, i   ; bx = 3*i
    mov DX, BX  ; dx = 3*i
    sal DX, 1   ; dx = 6*i

                ; вычисление fn1 и fn2
    mov AX, a   ; ax = a
    cmp AX, b   ; сравнение a и b
    jg F1       ; if (a > b) перейти на метку F1
                ; else (a <= b) продолжить

                ; fn1 (a <= b)
    add BX, 4   ; bx = 3*i + 4
                ; fn2 (a <= b)
    mov DX, BX  ; dx = 3*i + 4
    add DX, 2   ; DX = 3*i + 6

    jmp F2

F1:             ; fn1 (a > b)
    mov BX, CX  ; bx = 2*i
    neg BX      ; bx = -2*i
    add BX, 15  ; bx = -2*i + 15
                ; fn2 (a > b)
    neg DX      ; dx = -6*i
    add DX, 4  ; dx = -6*i + 4

F2:             ; вычисление fn3
    mov i1, BX  ; i1 = fn1
    mov i2, DX  ; i2 = fn2

    cmp k, 0
    jz M1       ; if (k == 0) перейти на метку M1
                ; else (k != 0) продлолжить
    cmp BX, DX  ; сравниваем i1 и i2
    jg M2       ; if (i1 > i2) перейти к метку MIN1
                ; else (i1 <= i2) продолжить
    mov res, BX
    jmp E

M1:             ; fn3 (k == 0)
    add DX, BX  ; dx = i1 + i2
    jns M2      ; if (i1 + i2 > 0) переход на метку M2
                ; else (i1 + i2 <= 0) продолжить
    neg DX      ; dx = |i1 + i2|

M2: 
    mov res, DX

E:  
    ret

Main ENDP
CODE ENDS
END MAIN