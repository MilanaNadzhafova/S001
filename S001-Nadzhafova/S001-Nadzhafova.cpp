#include <iostream>

int main()
{
    std::cout << "Enter your strings\n";
    char one[256]; //1 строка
    char two[256]; // 2 строка
    char three[] = "%s";

    char itog[514];
    __asm
    {
        //1 строка
        lea esi, one //копирование адреса 
        push esi // помещение в стек индекс источника
        lea ecx, three
        push ecx
        call scanf //вызов ввода с консоли
        add esp, 8
        mov ecx, -1
        dec esi

        //2 строка
        lea esi, two
        push esi
        lea ecx, three
        push ecx
        call scanf
        add esp, 8
        mov ecx, -1
        dec esi //декремент индекса источника

        //соединение
        lea esi, [one]
        lea edi, [itog]
        b1:
        lodsb //для загрузки байтных значений 
            stosb //сохранение значений аккумулятора
            cmp al, 0
            jnz b1 //переход на начало цикла при условии, что al = 0
            lea esi, [two]
            dec edi //декремент индекса приемника

            b2 :
        lodsb
            stosb
            cmp al, 0
            jnz b2

    }

    std::cout << itog;

}

