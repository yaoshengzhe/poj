#include <stdio.h>

#define MAX_LEN 200

int max(int a, int b) {
    return a > b ? a : b;
}

void init(int s[][256]) {
    s['A']['A'] = 5; s['A']['C'] = -1; s['A']['G'] = -2; s['A']['T'] = -1; s['A']['-'] = -3;
    s['C']['A'] = -1; s['C']['C'] = 5; s['C']['G'] = -3; s['C']['T'] = -2; s['C']['-'] = -4;
    s['G']['A'] = -2; s['G']['C'] = -3; s['G']['G'] = 5; s['G']['T'] = -2; s['G']['-'] = -2;
    s['T']['A'] = -1; s['T']['C'] = -2; s['T']['G'] = -2; s['T']['T'] = 5; s['T']['-'] = -1;
    s['-']['A'] = -3; s['-']['C'] = -4; s['-']['G'] = -2; s['-']['T'] = -1;
}

int similarity(char *a, int a_len, char *b, int b_len, int score[][256]) {
    int s[MAX_LEN][MAX_LEN] = {0};
    for (int j=0; j < b_len; ++j) {
        s[0][j+1] = s[0][j] + score['-'][b[j]];
    }
    for (int i=0; i < a_len; ++i) {
        s[i+1][0] = s[i][0] + score[a[i]]['-'];
    }

    for (int i=0; i < a_len; ++i) {
        for (int j=0; j < b_len; ++j) {
            s[i+1][j+1] = max(s[i][j+1] + score[a[i]]['-'],
                              max(s[i+1][j] + score['-'][b[j]], s[i][j] + score[a[i]][b[j]]));
        }
    }
    return s[a_len][b_len];
}

int main() {
    int n;
    char a[MAX_LEN];
    char b[MAX_LEN];
    int a_len;
    int b_len;
    int score[256][256] = {0};
    init(score);
    scanf("%d", &n);
    for (int i=0; i < n; ++i) {
        scanf("%d", &a_len);
        scanf("%s", a);
        scanf("%d", &b_len);
        scanf("%s", b);
        printf("%d\n", similarity(a, a_len, b, b_len, score));
    }
    return 0;
}
