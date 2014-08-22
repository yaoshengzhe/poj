#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 100

void print_indent(int indent) {
    while (indent > 0) {
        printf("|");
        for (int i=0; i < 5; ++i) {
            printf(" ");
        }
        indent -= 5;
    }
}

static int str_compare(const void *a, const void *b) {
    return strcmp(*(const char **)a, *(const char **)b);
}

int print_data_set(char data[][MAX_LEN], int offset, int len, int indent) {
    char *files[MAX_LEN];
    int file_len = 0;

    while (offset < len) {
        if (data[offset][0] == 'd') {
            print_indent(indent + 5);
            printf("%s\n", data[offset]);
            offset = print_data_set(data, offset + 1, len, indent + 5);
        } else if (data[offset][0] == 'f') {
            files[file_len++] = &(data[offset++]);
        } else if (data[offset][0] == ']') {
            break;
        }
    }
    // printf("qsort: start\n");
    qsort(files, file_len, sizeof(char*), str_compare);
    // printf("qsort: end\n");

    for (int i=0; i < file_len; ++i) {
        print_indent(indent);
        printf("%s\n", files[i]);
    }
    return offset + 1;
}

int main() {
    int idx = 1;
    char buf[MAX_LEN];
    char data[MAX_LEN][MAX_LEN];
    int line = 0;
    while (1) {
        scanf("%s", buf);
        if (strcmp("*", buf) == 0) {
            printf("DATA SET %d:\nROOT\n", idx);
            // printf("len: %d\n", line);
            print_data_set(data, 0, line, 0);
            printf("\n");
            line = 0;
            idx++;
        } else if (strcmp("#", buf) == 0) {
            break;
        } else {
            strcpy(data[line++], buf);
        }
    }

    return 0;
}
