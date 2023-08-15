#include <stdio.h>
#include <stdlib.h>

int *intersect(const int a[], const int b[]) {
    size_t i, j, count = 0, aSize = 0, bSize = 0;

    while (a[aSize] != '\0') aSize++;
    while (b[bSize] != '\0') bSize++;

    size_t cSize = (aSize > bSize) ? aSize : bSize;

    int *c = (int*) malloc (sizeof(int) * (cSize + 1));

    if (c == NULL) {
        printf("Memory allocation failed!\n");
        return c;
    }

    for (i = 0; i < aSize; i++) {
        for (j = 0; j < bSize; j++) {
            if (a[i] == b[j]) {
                c[count++] = a[i];
                break;
            }
        }
    }
    c[count] = '\0';

    return c;
}

int main() {
    int a[] = {8, 3, 1, 5, '\0'};
    int b[] = {5, 3, 4, 6, 9, '\0'};

    int *c = intersect(a, b);

    int count = 0;
    while (c != NULL && c[count] != '\0')
        printf("%d ", c[count++]);

    free(c);
    return 0;
}
