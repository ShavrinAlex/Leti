;   ?祡??? ?ணࠬ??  横?? ???.ࠡ. ?? ???樯????
;        "?࣠??????? ? ?㭪樮??஢???? ???"
;        ????: ?ᯮ?짮????? ?_????.80?87
;
;      ?????  ?????????

EOFLine  EQU  '$'      ; ??।?????? ᨬ???쭮? ????⠭??
                       ;     "????? ??ப?"

; ?⥪  ?ணࠬ??

AStack    SEGMENT  STACK
          DW 12 DUP(?)     ; ?⢮????? 12 ᫮? ??????
AStack    ENDS

; ?????? ?ணࠬ??

DATA      SEGMENT

;  ??४⨢? ???ᠭ?? ??????

A         DQ   1.6E+1
B         DQ   0.8e+1
Res       DQ    ?
DATA      ENDS

; ??? ?ணࠬ??

CODE      SEGMENT
          ASSUME CS:CODE, DS:DATA, SS:AStack

; ???楤??? ?????? ??ப? - ?.?. ?ਣ??????
WriteMsg  PROC  NEAR
          mov   AH,9
          int   21h  
          ret
WriteMsg  ENDP

;---------------------------------------------------
;          PUBLIC  Feccent

;  ???????
Feccent   PROC  NEAR
          fld   A         ; ????. ?  ? FP-?⥪ 
          Fmul  A         ; a*a  ?  FP -?⥪
          fld   B         ; b  ?  FP -?⥪
          fmul  B         ; b*b  ?  FP -?⥪
          fsubp ST(1),ST  ; a*a-b*b  ?  FP -?⥪ ? ?᢮???????? ST(1)
          fsqrt           ; sqrt(ST(0))
          fdiv  A         ; (a*a-b*b)/a ? FP-?⥪ 
          fst   res       ;  ????. १-? ? res
          ret
Feccent   ENDP
;-------------------------------

; ???????? ???楤???
Main      PROC  FAR
          push  DS          ;???࠭???? ?????? ??砫? PSP ? ?⥪?
          sub   AX,AX       ;??? ??᫥???饣? ????⠭??????? ??
          push  AX          ;??????? ret, ????????饩 ???楤???.
          mov   AX,DATA             ; ????㧪? ᥣ???⭮??
          mov   DS,AX               ; ॣ????? ??????.
          xor   ax,ax
          call  Feccent             ; ????᫥??? ???業?????????
;         mov   DX,SI
;         call  WriteMsg                 ;  ?뢮? ?? ??࠭
                                         ;  
          ret                            ; ??室 ? DOS ?? ???????,
                                         ; ???-?? ? 1-?? ᫮?? PSP.
Main      ENDP
CODE      ENDS
          END Main
