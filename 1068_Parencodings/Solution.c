#include <stdio.h>
#include <stdlib.h>

void read_int_array(int *arr, int len) {
    for (int i=0; i < len; ++i) {
        scanf("%d", &arr[i]);
    }
}

void print_w_seq(int *arr, int len, int *stack) {

    int s_len = 0;
    int cur_idx = 0;
    int num_left = 0;
    for (int i=0; i < len-1; ++i) {
        while (arr[i] > num_left) {
            stack[s_len++] = cur_idx++;
            num_left++;
        }
        printf("%d ", (cur_idx - stack[s_len-1] + 1) / 2); // num pairs before this right paren
        cur_idx++; // got a right paren
        s_len--;
    }
    if (s_len > 0) {
        printf("%d\n", (cur_idx - stack[s_len-1] + 1) / 2);
    } else {
        printf("1\n");
    }
}

int main() {
    int num_tests;
    int stack[1000];
    int p[1000];
    scanf("%d", &num_tests);
    for (int i=0; i < num_tests; ++i) {
        int len;
        scanf("%d", &len);
        read_int_array(p, len);
        print_w_seq(p, len, stack);
    }
    return 0;
}
