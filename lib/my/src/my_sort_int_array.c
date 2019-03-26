/*
** EPITECH PROJECT, 2018
** my_sort_int_array.c
** File description:
** sort array
*/

int *check(int i, int *array)
{
    int temp;

    if (array[i] > array[i + 1]) {
        temp = array[i + 1];
        array[i + 1] = array[i];
        array[i] = temp;
    }
    return (array);
}

void my_sort_int_array(int *array, int size)
{
    int i;
    int j;

    for (i = 0; i < size - 1; i++) {
        for (j = 0; j < size - 1 - i; j++) {
            array = check(i, array);
        }
    }
}