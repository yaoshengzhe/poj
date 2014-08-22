#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 100

typedef struct Node {
    char val;
    struct Node *left;
    struct Node *right;
} Node;


Node *trie_new(char val) {
    Node *p = (Node *)malloc(sizeof(Node));
    p->val = val;
    p->left = p->right = NULL;
    return p;
}

int is_leaf(Node *p) {
    return p != NULL && p->left == NULL && p->right == NULL;
}

int trie_add(Node *root, char buf[MAX_LEN]) {
    char *p = &buf[0];
    Node *cur = root;
    while (*p != '\0') {
        if (*p == '0') {
            if (cur->left == NULL) {
                cur->left = trie_new('0');
            } else if (is_leaf(cur->left)) {
                return -1;
            }
            cur = cur->left;
        } else {
            if (cur->right == NULL) {
                cur->right = trie_new('1');
            } else if (is_leaf(cur->right)) {
                return -1;
            }
            cur = cur->right;
        }
        p++;
    }
    return 0;
}

void trie_destroy(Node *node) {
    if (node != NULL) {
        trie_destroy(node->left);
        trie_destroy(node->right);
        free(node);
    }
}

int main() {
    int idx = 1;
    char buf[MAX_LEN];
    Node root;
    root.left = root.right = NULL;

    while (1) {
        if (scanf("%s", buf) == EOF) {
            break;
        }

        if (buf[0] == '9') {
            printf("Set %d is immediately decodable\n", idx);
            trie_destroy(root.left);
            trie_destroy(root.right);
            root.left = root.right = NULL;
            idx++;
        } else {
            if (trie_add(&root, buf) == -1) {
                printf("Set %d is not immediately decodable\n", idx);
                do {
                    scanf("%s", buf);
                } while (buf[0] != '9');
                trie_destroy(root.left);
                trie_destroy(root.right);
                root.left = root.right = NULL;
                idx++;
            }
        }

    }
    return 0;
}
