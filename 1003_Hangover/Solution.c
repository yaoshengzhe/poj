#include <stdio.h>

int main() {
    float num;
    while (1) {
        scanf("%f", &num);
        if (num == 0.00f) {
            break;
        } else {
            int cards = 1;
            double sum = 0;
            for (; ; ++cards) {
                sum += 1.0/(1+cards);
                if (sum > num) {
                    break;
                }
            }
            printf("%d card(s)\n", cards);
        }
    }
    return 0;
}
