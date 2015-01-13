#include <stdio.h>
#include <stdlib.h>

#include "quicksort.h"
#include <stdio.h>

#include "binary_search.h"
#include "sortable.h"
#include "disc.h"


struct disc ** make_discs(int * radii, int how_many_radii) {
    struct disc ** discs = malloc(how_many_radii * sizeof(struct disc *));
    int i;
    int radius;
    struct disc * this_disc = NULL;

    if (!discs) {
        return NULL;
    }
    for (i = 0; i < how_many_radii; i++) {
        radius = radii[i];
        this_disc = new_disc(radius, i);
        if (!this_disc) {
            free(discs);
            return NULL;
        }
        discs[i] = this_disc;
    }
    return discs;
}

void destroy_discs(struct disc ** discs, int how_many_discs) {
    int i;

    for (i = 0; i < how_many_discs; i++) {
        destroy_disc(discs[i]);
    }
    free(discs);
}

void print_discs(struct disc ** discs, int how_many_discs) {
    int i;

    for (i = 0; i < how_many_discs; i++) {
        print_disc(discs[i]);
        printf("\n");
    }
}

int max(int a, int b) {
    if (a > b) {
        return a;
    }
    return b;
}

int count_intersections_at_i(struct sortable sorted_discs, int i) {
    struct disc * disc_i = sorted_discs.elements[i];
    struct disc target = {
        disc_i->right,
        disc_i->right
    };
    int j = binary_search(&sorted_discs, &target);

    return max(j - i, 0);
}

int compare_discs(void * a, void *b) {
    struct disc * disc_a = a;
    struct disc * disc_b = b;

    if (disc_a->left < disc_b->left) {
        return -1;
    } else if (disc_a->left > disc_b->left) {
        return 1;
    }
    return 0;
}

struct sortable sort_discs(struct disc ** discs, int how_many_discs) {
    struct sortable sorted_discs = {
        (void **) discs,
        how_many_discs,
        &compare_discs
    };

    quicksort(&sorted_discs);
    return sorted_discs;
}

int solution(int A[], int n) {
    struct disc ** discs = make_discs(A, n);
    struct sortable sorted_discs;
    int count = 0;
    int this_count;
    int i;

    sorted_discs = sort_discs(discs, n);
    for (i = 0; i < n; i++) {
        print_disc(sorted_discs.elements[i]);
        this_count = count_intersections_at_i(sorted_discs, i);
        count += this_count;
    }
    destroy_discs(discs, n);
    return count;
}

int main() {
    int A[] = {1, 5, 2, 1, 4, 0};
    int n = 6;

    printf("about to try and compute the disc intersections...\n");
    int answer = solution(A, n);
    printf("Got the answer: %d\n", answer);
}
