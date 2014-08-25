#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 100

typedef struct Dna {
    int inversion;
    char seq[MAX_LEN];
} Dna;

static int dna_cmp(const void *a, const void *b) {
    return ((Dna *)a)->inversion - ((Dna *)b)->inversion;
}


void my_merge(char *arr, int start, int mid, int end, char buf[MAX_LEN], int *total_inv) {
    int i, j, k;
    i = start;
    j = mid;
    k = 0;
    while (i < mid && j < end) {
        if (arr[i] <= arr[j]) {
            buf[k++] = arr[i++];
        } else {
            buf[k++] = arr[j++];
            (*total_inv) += (mid - i);
        }
    }
    while (i < mid) {
        buf[k++] = arr[i++];
    }
    while (j < end) {
        buf[k++] = arr[j++];
    }
    strncpy(arr + start, buf, end - start);
}

void my_mergesort(char *arr, int start, int end, char buf[MAX_LEN], int *total_inv) {
    if (end - start == 1) {
        return ;
    }

    if (start < end) {
        int mid = start + (end - start) / 2;
        my_mergesort(arr, start, mid, buf, total_inv);
        my_mergesort(arr, mid, end, buf, total_inv);
        my_merge(arr, start, mid, end, buf, total_inv);
    }
}

int calc_inversion(char *seq, int len) {
    int total_inv = 0;
    char buf[MAX_LEN];
    char seq_copy[MAX_LEN];
    strcpy(seq_copy, seq);
    my_mergesort(seq_copy, 0, len, buf, &total_inv);
    return total_inv;
}

int main() {
    int m, n;
    scanf("%d %d", &m, &n);
    Dna records[MAX_LEN] = {0};

    for (int i=0; i < n; ++i) {
        scanf("%s", records[i].seq);
        records[i].inversion = calc_inversion(records[i].seq, m);
        // printf("%s => inversion: %d\n", records[i].seq, records[i].inversion);
    }

    qsort((void *)&records[0], n, sizeof(Dna), dna_cmp);

    for (int i=0; i < n; ++i) {
        printf("%s\n", records[i].seq);
    }

    return 0;
}
