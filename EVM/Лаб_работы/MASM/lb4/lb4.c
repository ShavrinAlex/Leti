#include <stdlib.h>
#include <stdio.h>
#include <locale.h>
#include <Windows.h>

#define MAX_STRING_SIZE 80
#define OUTPUT_FILE_NAME "result.txt"


char input_string[MAX_STRING_SIZE + 1];
char output_string[MAX_STRING_SIZE * 6 + 1];

void greeting() {
    printf("Title\n");
    printf("Преобразование введенных во входной строке шестнадцатиричных цифр в двоичную СС, остальные символы входной строки передаются в выходную строку непосредственно.\n");
    printf("Автор: Шаврин Алексей\nгруппа: 1304\n");
}

void read_string() {
    printf("Введите строку для обработки:\n");
    fgets(input_string, MAX_STRING_SIZE + 1, stdin);
}

void string_processing() {
    __asm {
        push ds
        pop es
        mov esi, offset input_string
        mov edi, offset output_string

        iter :
            lodsb
            cmp al, 46h         ; сравнение с кодом символа F в 16-ричной СС
            ja Final            ; if (код символа > F - не подходит) перейти к метке Final
                                ; else проверка на принадлежность диапазону[A, F]

            cmp al, 41h         ; сравнение с кодом символа A в 16-ричной СС
            jae IsChar          ; if (код символа >= кода A - подходит) перейти к метке IsChar
                                ; else (код символа < A - не подходит) проверка на принадлежность к цифрам

            cmp al, 39h         ; сравнение с кодом символа 9-ричной СС
            ja Final            ; if (код символа > 9 - не подходит) перейти на метку Final
                                ; else проверка на принадлежность диапазону[0, 9]

            cmp al, 30h         ; сравнение с кодом символа 0-ричной СС
            jb Final            ; if (код символа < кода 0 - не подходит) перейти к метке Final
                                ; else (код символа >= 0 - подходит) переход к метке IsNum

            IsNum:
                sub al, 30h     ; для представления символа как число в программе
                jmp Convert

            IsChar:
                sub al, 37h     ; для представления символа как число в программе

            Convert:
                ; перевод в 2СС
                mov bl, al
                mov al, ' '     ; отделение от предыдущих символов
                stosb           ; вывод символа пробела перед 2-м представлением числа
                shl bl, 4       ; перевод к 4-х значному 2-му числу
                mov cx, 4       ; 4 итерации, поскольку для представления любого 16 - ричного числа в 2 - м виде необходимо 4 бита
                cnv :
                    shl bl, 1   ; сдвиг регистра bl влево через флаг переноса
                    mov al, 30h ; помещение ASCII - кода цифры 0 в регистр dl
                    adc al, 0   ; прибавление к ASCII - коду нуля с учетом флага переноса
                    stosb       ; запись результата
                    loop cnv    ; продолжение цикла
                mov al, ' '     ; запись символа пробела

            Final:
                stosb           ; запись результата
                mov dl, 0       ; запись символа '\0'
                cmp dl, [esi]   ; проверка на конец строки
                jne iter        ; if (это не конец строки) продолжить обработку
    };
}

void write_result() {
    printf("%s", output_string);
    /*
    FILE *file = fopen(OUTPUT_FILE_NAME, "w");
    if (file != NULL){
        fprintf(file, "%s", output_string);
    }
    fclose(file);
    */
}

int main() {
    setlocale(LC_ALL, "Russian.1251");
    greeting();
    read_string();
    string_processing();
    write_result();
    return 0;
}