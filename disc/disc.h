#ifndef _DISC_H_
#define _DISC_H_

struct disc {
    int left;
    int right;
};

struct disc * new_disc(int, int);
void destroy_disc(struct disc *);
void print_disc(struct disc *);

#endif
