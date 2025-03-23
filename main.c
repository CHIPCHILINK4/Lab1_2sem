#include <stdio.h>
#include <stdlib.h>
#include <time.h>

char printi(int* b, size_t a) {//выводим массив
    if (b)
    {
        printf("A[%d] = \n", a);
        for (size_t i = 0; i < a; i++)
        {
            printf("%3d ", b[i]);
        }
        printf("\n");
        printf("\n");
        return '1';
    }
    else
    {
        return '0';
    }
}

int* create_and_filling(size_t number_in_the_array, int rangeA, int rangeB) {//создаем массив в куче и инициализируем его с помощью rand
    if (rangeB < rangeA)
    {
        int tmp = 0;
        tmp = rangeA;
        rangeA = rangeB;
        rangeB = tmp;

    }
    int* data = (int*)malloc((sizeof(int) * number_in_the_array));
    //int* data = NULL;
    if (data)
    {
        //printi(siz, ykaz);
        for (size_t i = 0; i < number_in_the_array; i++) // Задаем массив с помощью псевдослучайных чисел
        {
            data[i] = (rand() % (rangeB - rangeA + 1) + rangeA);
        }
        return data;
    }
    return data;
}

char sort(int* data, size_t number_in_the_array) {//шейкерная сортировка
    if (data)
    {
        int j = 0; // параметр циклов
        int i = 0;//параметр циклов

        int tmp = 0; // tmp – переменная для обмена элементов
        int r = 0, l = number_in_the_array - 1;//l – левая граница интервала, r – правая граница интервала
        int lt = r, rt = l;// Rt – индекс текущего обмена ->, Lt – индекс текущего обмена  <-
        while ((rt != r) && (l != lt)) {
            i = lt;
            r = rt;
            while (i < r) {
                if (data[i] > data[i + 1]) {
                    tmp = data[i];
                    data[i] = data[i + 1];
                    data[i + 1] = tmp;
                    tmp = 0;
                    rt = i;
                }
                i = i + 1;
            }
            if (r != rt) {
                i = rt;
                l = lt;
                while (i > l) {
                    if (data[i] < data[i - 1]) {
                        tmp = data[i];
                        data[i] = data[i - 1];
                        data[i - 1] = tmp;
                        tmp = 0;
                        lt = i;
                    }
                    i = i - 1;
                }
            }
        }
        return '1';
    }
    return '0';
}

char cchheecckk(int* data, size_t number_in_the_array) {//простая проверка на упорядоченность
    if (data)
    {
        char flag = '1';
        int i = 0;
        for (; (i < number_in_the_array - 1) && flag == '1'; i++)
        {
            if (data[i] > data[i + 1])
            {
                flag = '0';
            }
            //printf("%3d ", i);
        }
        if (data[i - 1] > data[i])
        {
            flag = '0';
        }
        return flag;
    }
    else
    {
        return '2';
    }
}



int main() {
    int* ptr = NULL;
    size_t size1 = 0;
    int rangeA = 0, rangeB = 0;
    clock_t t;
    printf("Введите size, rangeA и rangeB ");
    int check = scanf_s("%d %d %d", &size1, &rangeA, &rangeB);
    printf("\n");
    if (check && size1 > 0)
    {
        //srand(time(0));//начальная точка для задания псевдослучайных чисел. присвоение этой точке времени
        srand(1);

        ptr = create_and_filling(size1, rangeA, rangeB);



        //-------------------------------------
        if (printi(ptr, size1) == '0')
        {
            printf("err1: PTR IS NULL\n");
        }
        else
        {
            t = clock();
            if (sort(ptr, size1) == '0')
            {
                t = clock() - t;//
                printf("err3: PTR IS NULL\n");
            }
            else
            {
                t = clock() - t;//
                if (printi(ptr, size1) == '0')
                {
                    printf("err1: PTR IS NULL\n");
                }
                else
                {
                    if (cchheecckk(ptr, size1) == '1')
                    {
                        double time_taken = ((double)t) / CLOCKS_PER_SEC;//
                        printf("sort is current\n");
                        printf("%f", time_taken);//
                    }
                    else if (cchheecckk(ptr, size1) == '0')
                    {
                        printf("sort is incurrent\n");
                    }
                    else
                    {
                        printf("err4: PTR IS NULL\n");
                    }
                }
            }

        }
    }
    else
    {
        printf("err0: incurrent values\n");
    }
    free(ptr);
    return 0;
}
