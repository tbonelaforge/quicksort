#include <stdio.h>
#include <stdlib.h>

#include "quicksort.h"

/*
void print_array(int * a, int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
}
*/

int main() {
    int i;
    printf("About to sort the array: 2,1,1,2,3,1\n");

    int test[] = {
        2,
        1,
        1,
        2,
        3,
        1
    };
    int n = 6;
    quicksort(test, 6);
    printf("The sorted array is:\n");
    for (i = 0; i < n; i++) {
        printf("%d\n", test[i]);
    }

    printf("Constructing a 100,000 element list\n");
    int * big_test = malloc(100003 * sizeof(int));
    for (i = 0; i < 100003; i++) {
        big_test[i] = -1;
    }
    //    big_test[100000] = 5;
    big_test[0] = 5;
    //    big_test[100001] = 3;
    big_test[1] = 3;
    //    big_test[100002] = 3;
    big_test[2] = 3;
    //    printf("Before sorting, the list looks like:\n");
    printf("About to sort the big_test arrayz.\n");
    //    print_array(big_test, 100003);
    printf("Sorting the big list...\n");
    quicksort(big_test, 100003);
    //    printf("After sorting the big list, it looks like:\n");
    printf("Done sorting the big_test: min = %d, max = %d\n", big_test[0], big_test[100002]);
    //    print_array(big_test, 100003);
}
