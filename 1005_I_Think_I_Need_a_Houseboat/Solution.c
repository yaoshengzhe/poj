#include <stdio.h>

#define PI 3.1415926535897

int main() {
    int n;
    double x, y;
    scanf("%d", &n);
    for (int i=0; i < n; ++i) {
        scanf("%lf %lf", &x, &y);
        printf("Property %d: This property will begin eroding in year %d.\n",
               i+1, (int)(PI * (x * x + y * y) / 100 + 1));
    }
    printf("END OF OUTPUT.\n");
    return 0;
}
