#include "sort.h"

FILE* openFile(char* filename, char* type) {
    FILE *f;
    f = fopen(filename, type);
    if(f == NULL) {
        printf("Cannot open file %s\n", filename);
        exit(1);
    }
    return f;
}

int* allocateArray() {
    int *array;
    array = (int*) malloc((MAX_LENGHT+1)* sizeof(int));
    if(array == NULL) {
        printf("Cannot allocate memory\n");
        exit(2);
    }
    return array;
}

int main() {
    int *array;
    FILE *fin, *fout;

    fin = openFile("random.txt", "r+");
    fout = openFile("result.txt", "w+");

    array = allocateArray();

    int i;

    for(i = 0; i < MAX_LENGHT; i++) {
        fscanf(fin, "%d", &array[i]);
    }

    // bubbleSort(array, MAX_LENGHT);
    // selectionSort(array, MAX_LENGHT);
    mergeSort(array, 0, MAX_LENGHT);
    // quickSort(array, 0, MAX_LENGHT);

    for(i = 0; i < MAX_LENGHT; i++) {
        fprintf(fout, "%d\n", array[i]);
    }

    free(array);
    fclose(fin);
    fclose(fout);

    return 0;
}