#include <stdlib.h>
#include <stdio.h>

#include "disc.h"

struct disc * new_disc(int radius, int center) {
    struct disc * this_disc = malloc(sizeof(struct disc));

    if (!this_disc) {
        return NULL;
    }
    this_disc->left = center - radius;
    this_disc->right = center + radius;
    return this_disc;
}

void destroy_disc(struct disc * self) {
    free(self);
}

void print_disc(struct disc * self) {
    printf("(%d, %d)", self->left, self->right);
}
