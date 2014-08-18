#include <stdio.h>
#include <math.h>

// Vr = R * C * w * Vs * sqrt(1/(R^2*C^2*w^2 + 1))

int main() {
    double Vs, R, C, w;
    int num_examples;
    scanf("%lf %lf %lf %d", &Vs, &R, &C, &num_examples);
    for (int i=0; i < num_examples; ++i) {
        scanf("%lf", &w);
        printf("%.3f\n", R * C * w * Vs * sqrt(1.0 / (R*R*C*C*w*w + 1)));
    }

    return 0;
}
