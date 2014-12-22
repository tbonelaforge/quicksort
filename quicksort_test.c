#include <stdio.h>
#include <stdlib.h>

#include "quicksort.h"
#include "binary_search.h"

struct integer {
    int value;
};

int search_for_int(struct sortable * self, int t) {
    int begin = 0;
    int end = self->how_many_elements - 1;
    struct integer target = { t };

    return binary_search(self, begin, end, &target);
}

int compare_integers(void * a, void * b) {
    struct integer * a_integer = a;
    struct integer * b_integer = b;

    if (a_integer->value < b_integer->value) {
        return -1;
    } else if (a_integer->value > b_integer->value) {
        return 1;
    } else {
        return 0;
    }
}

void print_integer(struct integer * this_integer) {
    printf("%d ", this_integer->value);
}

//void print_integers(struct integer ** integers, int n) {
void print_as_integers(void ** structures, int n) {
    struct integer ** integers;
    int i;

    integers = (struct integer **) structures;
    for (i = 0; i < n; i++) {
        print_integer(integers[i]);
        printf("\n");
    }
}

struct integer ** make_integer_structures(int * a, int n) {
    int i;
    struct integer ** integer_structures = malloc(n * sizeof(struct integer *));
    struct integer * new_integer = NULL;

    if (!integer_structures) {
        return NULL;
    }
    for (i = 0; i < n; i++) {
        new_integer = malloc(sizeof(struct integer));
        if (!new_integer) {
            return NULL;
        }
        new_integer->value = a[i];
        integer_structures[i] = new_integer;
    }
    return integer_structures;
}

int main() {
    int i;
    printf("About to sort the array: 4, 2, 2, 4, 6, 2\n");

    int a[] = { 4, 2, 2, 4, 6, 2 };
    int n = 6;
    struct integer ** test_integers = make_integer_structures(a, n);
    struct sortable test = {
        (void **) test_integers,
        n,
        &compare_integers
    };

    printf("About to sort test_integers:\n");
    print_as_integers(test.elements, test.how_many_elements);
    printf("About to call the quicksort function\n");
    quicksort(&test);
    printf("After sorting the integers, they look like:\n");
    print_as_integers(test.elements, test.how_many_elements);

    int search_result;

    printf("About to search for the number 6...\n");
    search_result = search_for_int(&test, 6);
    //    search_result = binary_search(test, 0, 5, 6);
    printf("The search_result is: %d\n", search_result);

    printf("About to search for the number 4...\n");
    //    search_result = binary_search(test, 0, 5, 4);
    search_result = search_for_int(&test, 4);
    printf("The search_result is: %d\n", search_result);

    printf("About to search for the number 2...\n");
    //    search_result = binary_search(test, 0, 5, 2);
    search_result = search_for_int(&test, 2);
    printf("The search_result is: %d\n", search_result);


    printf("About to search for the number 7...\n");
    //    search_result = binary_search(test, 0, 5, 7);
    search_result = search_for_int(&test, 7);
    printf("The search_result is: %d\n", search_result);

    printf("About to search for the number 5...\n");
    //    search_result = binary_search(test, 0, 5, 5);
    search_result = search_for_int(&test, 5);
    printf("The search_result is: %d\n", search_result);

    printf("About to search for the number 3...\n");
    //    search_result = binary_search(test, 0, 5, 3);
    search_result = search_for_int(&test, 3);
    printf("The search_result is: %d\n", search_result);

    printf("About to search for the number 1...\n");
    //    search_result = binary_search(test, 0, 5, 1);
    search_result = search_for_int(&test, 1);
    printf("The search_result is: %d\n", search_result);
}
