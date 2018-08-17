

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int *list_generator(int length)
{
    int *array;
    time_t t;

    array = (int *)malloc(sizeof(int) * length);
    srand((unsigned) time(&t));

    for (int i = 0; i < length; i++) {     // fill array
        array[i] = i;
        // printf("%d,", array[i]);
    }
    // printf("\n done with population \n");
    // printf("here is the final array\n");

    for (int i = 0; i < length; i++) {    // shuffle array
        int temp = array[i];
        int randomIndex = rand() % length;

        array[i]           = array[randomIndex];
        array[randomIndex] = temp;
    }

    return (array);
}

int main()
{
    int * arr;
    int length = 10;

    arr = list_generator(length);

    for (int i = 0; i < length; i++) {    // print array
        printf("%d,",arr[i]);
    }
    printf("\n");
}