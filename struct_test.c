#include <stdio.h>

typedef struct {
    int x;
    int y;
} Point;

void set_point(Point p, int x, int y) {
    p.x = x;
    p.y = y;
}

void print_point(Point *p) {
    printf("(%d, %d)\n", p->x, p->y);
}

int main() {
    Point p;
    set_point(p, 1, 2);
    print_point(&p);
    return 0;
}