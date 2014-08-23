#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 100001

int to_tel_num(char *str, int *tel_map) {
    int num = 0;
    while (*str != '\0') {
        if (*str >= '0' && *str <= '9') {
            num = num * 10 + (*str - '0');
        } else if (*str >= 'A' && *str <= 'Y') {
            num = num * 10 + tel_map[*str];
        }
        str++;
    }
    return num;
}

int cmp(const void *a, const void *b) {
    return *(int *)a - *(int *)b;
}

int main() {
    int tel_map[256];
    tel_map['A'] = tel_map['B'] = tel_map['C'] = 2;
    tel_map['D'] = tel_map['E'] = tel_map['F'] = 3;
    tel_map['G'] = tel_map['H'] = tel_map['I'] = 4;
    tel_map['J'] = tel_map['K'] = tel_map['L'] = 5;
    tel_map['M'] = tel_map['N'] = tel_map['O'] = 6;
    tel_map['P'] = tel_map['R'] = tel_map['S'] = 7;
    tel_map['T'] = tel_map['U'] = tel_map['V'] = 8;
    tel_map['W'] = tel_map['X'] = tel_map['Y'] = 9;

    int arr[MAX_LEN];

    char str[100];
    int n;
    scanf("%d", &n);
    for (int i=0; i < n; ++i) {
        scanf("%s", str);
        arr[i] = to_tel_num(str, tel_map);
    }
    arr[n+1] = 0;
    qsort((void*)arr, n, sizeof(int), cmp);

    int no_duplicate = 0;
    int count = 1;
    for (int i=0; i < n+1; ++i) {
        if (arr[i] == arr[i+1]) {
            count++;
        } else {
            if (count > 1) {
                no_duplicate = -1;
                int first_part = arr[i] / 10000;
                printf("%03d-%04d %d\n", first_part, arr[i] % 10000, count);
            }
            count = 1;
        }
    }

    if (no_duplicate == 0) {
        printf("No duplicates.\n");
    }

    return 0;
}
