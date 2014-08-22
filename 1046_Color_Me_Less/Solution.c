#include <stdio.h>

#define COLOR_SIZE 16

typedef struct Color {
    int r;
    int g;
    int b;
} Color;

void print_color(Color *c) {
    printf("(%d,%d,%d)", c->r, c->g, c->b);
}

long square_dist(Color *a, Color *b) {
    return (a->r - b->r) * (a->r - b->r) +
        (a->g - b->g) * (a->g - b->g) +
        (a->b - b->b) * (a->b - b->b);
}

int get_closest_idx(Color *c, Color mapped[COLOR_SIZE]) {
    long min_dist = 100000000000;
    int closest = 0;
    for (int i=0; i < COLOR_SIZE; ++i) {
        long dist = square_dist(&mapped[i], c);
        if (min_dist > dist) {
            min_dist = dist;
            closest = i;
        }
    }
    return closest;
}

int main() {
    Color c;
    Color mapped[COLOR_SIZE];
    int i = 0;
    while (1) {
        scanf("%d %d %d", &c.r, &c.g, &c.b);
        if (c.r < 0) {
            break;
        }
        if (i < COLOR_SIZE) {
            mapped[i++] = c;
        } else {
            print_color(&c);
            printf(" maps to ");
            print_color(&mapped[get_closest_idx(&c, mapped)]);
            printf("\n");
        }
    }
    return 0;
}
