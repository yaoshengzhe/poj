#include <stdio.h>
#include <string.h>

static char find_char(char *str);

int encode(char *src, int len, char *dest, char **encode_table) {
    for (int i=0; i < len; ++i) {
        char *p = encode_table[src[i]];
        while (*dest++ = *p++);
        dest--;
    }

    for (int i=0; i < len; ++i) {
        *dest++ = strlen(encode_table[src[i]]) + '0';
    }
    *dest = '\0';
}

void decode(char *src, int len, char *dest) {
    char *start = src;
    char *end = src + len;
    char buf[8];
    while (start < end) {
        int offset = *(--end) - '0';
        strncpy(buf, start, offset);
        buf[offset] = '\0';
        start += offset;
        *dest++ = find_char(buf);
    }
    *dest = '\0';
}

void init_encode_table(char **et) {
    et['A'] = ".-"; et['B'] = "-..."; et['C'] = "-.-."; et['D'] = "-..";
    et['E'] = ".";  et['F'] = "..-."; et['G'] = "--.";  et['H'] = "....";
    et['I'] = ".."; et['J'] = ".---"; et['K'] = "-.-";  et['L'] = ".-..";
    et['M'] = "--"; et['N'] = "-.";   et['O'] = "---";  et['P'] = ".--.";
    et['Q'] = "--.-"; et['R'] = ".-."; et['S'] = "..."; et['T'] = "-";
    et['U'] = "..-"; et['V'] = "...-"; et['W'] = ".--"; et['X'] = "-..-";
    et['Y'] = "-.--"; et['Z'] = "--.."; et['_'] = "..--"; et['.'] = "---.";
    et[','] = ".-.-"; et['?'] = "----";
}

char find_char(char *str) {
    if (strcmp(str, ".-") == 0)         return 'A';
    else if (strcmp(str, "-...") == 0)  return 'B';
    else if (strcmp(str, "-.-.") == 0)  return 'C';
    else if (strcmp(str, "-..") == 0)   return 'D';
    else if (strcmp(str, ".") == 0)     return 'E';
    else if (strcmp(str, "..-.") == 0)  return 'F';
    else if (strcmp(str, "--.") == 0)   return 'G';
    else if (strcmp(str, "....") == 0)  return 'H';
    else if (strcmp(str, "..") == 0)    return 'I';
    else if (strcmp(str, ".---") == 0)  return 'J';
    else if (strcmp(str, "-.-") == 0)   return 'K';
    else if (strcmp(str, ".-..") == 0)  return 'L';
    else if (strcmp(str, "--") == 0)    return 'M';
    else if (strcmp(str, "-.") == 0)    return 'N';
    else if (strcmp(str, "---") == 0)   return 'O';
    else if (strcmp(str, ".--.") == 0)  return 'P';
    else if (strcmp(str, "--.-") == 0)  return 'Q';
    else if (strcmp(str, ".-.") == 0)   return 'R';
    else if (strcmp(str, "...") == 0)   return 'S';
    else if (strcmp(str, "-") == 0)     return 'T';
    else if (strcmp(str, "..-") == 0)   return 'U';
    else if (strcmp(str, "...-") == 0)  return 'V';
    else if (strcmp(str, ".--") == 0)   return 'W';
    else if (strcmp(str, "-..-") == 0)  return 'X';
    else if (strcmp(str, "-.--") == 0)  return 'Y';
    else if (strcmp(str, "--..") == 0)  return 'Z';
    else if (strcmp(str, "..--") == 0)  return '_';
    else if (strcmp(str, ".-.-") == 0)  return ',';
    else if (strcmp(str, "---.") == 0)  return '.';
    else if (strcmp(str, "----") == 0)  return '?';
}

int main() {
    int n;
    char str[200];
    char buf[3000];
    char encode_table[256][8];
    init_encode_table(encode_table);

    scanf("%d", &n);
    for (int i=0; i < n; ++i) {
        scanf("%s", str);
        encode(str, strlen(str), buf, encode_table);
        decode(buf, strlen(buf), str);
        printf("%d: %s\n", i + 1, str);
    }
    return 0;
}
