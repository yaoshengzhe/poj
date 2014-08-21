#include <stdio.h>

void init(long *tree_num, long *acc_num, long n) {
    tree_num[0] = tree_num[1] = 1;
    int i = 2;
    for ( ;; ++i) {
        for (int j=0; j < i; ++j) {
            tree_num[i] += tree_num[j] * tree_num[i - j - 1];
        }
        // printf("%d: %ld\n", i, tree_num[i]);
        if (tree_num[i] > n) {
            break;
        }
    }
    for (int k=1; k < i; ++k) {
        acc_num[k] = acc_num[k - 1] + tree_num[k];
    }
}

int find_node_num(long n, long *acc_num) {
    int i = 0;
    for (; acc_num[i] < n; ++i);
    return i;
}

void print_tree(int node_num, long kth, long *tree_num) {
    if (node_num == 0) {
        return;
    }

    int left_num = 0;
    int right_num = node_num - 1;

    while (tree_num[left_num] * tree_num[right_num] < kth) {
        kth -= tree_num[left_num] * tree_num[right_num];
        left_num++;
        right_num--;
    }

    // printf("#num = %d, #left = %d, # right = %d ", node_num, left_num, right_num);
    // printf("k = %ld\n", kth);

    long left_state = (kth-1) / tree_num[right_num] + 1;
    long right_state = ( (kth-1) % tree_num[right_num]) + 1;

    if (left_num > 0) {
        printf("(");
        print_tree(left_num, left_state, tree_num);
        printf(")");
    }

    printf("X");

    if (right_num > 0) {
        printf("(");
        print_tree(right_num, right_state, tree_num);
        printf(")");
    }

}

int main() {
    long n = 0;
    long tree_num[100] = {0};
    long acc_num[100] = {0};
    init(tree_num, acc_num, 500000000);
    while (1) {
        scanf("%ld", &n);
        if (n == 0) {
            break;
        }

        int node_num = find_node_num(n, acc_num);
        print_tree(node_num, n - acc_num[node_num - 1], tree_num);
        printf("\n");
    }
    return 0;
}
