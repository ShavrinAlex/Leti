#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/resource.h>

void main()
{
    int priority, pid, i;
    pid=getpid();
    // Цикл для установки приоритета от -100 до 0
    for (i = -100; i < 1; i++)
    {
        // Установка приоритета процесса
        setpriority(PRIO_PROCESS, pid, i);
        // Получение текущего приоритета процесса
        priority = getpriority(PRIO_PROCESS, pid);
        // Если приоритет не соответствует запрошенному, продолжаем цикл
        if (priority != i) continue;
        // Иначе выводим информацию и прерываем цикл
        else
        {
            printf("Нижняя граница = %d\n", priority);
            printf("Запросили %d, получили %d\n", i, priority);
            break;
        }
    }
    // Цикл для установки приоритета от 1 до 99
    for (i = 1; i < 100; i++)
    {
        // Установка приоритета процесса
        setpriority(PRIO_PROCESS, pid, i);
        // Получение текущего приоритета процесса
        priority = getpriority(PRIO_PROCESS, pid);
        // Если приоритет соответствует запрошенному, продолжаем цикл
        if (priority == i) continue;
        // Иначе выводим информацию и прерываем цикл
        else
        {
            printf("Верхняя граница = %d\n", priority);
            printf("Запросили %d, получили %d\n", i, priority);
            break;
        }
    }
}