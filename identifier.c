#include <stdio.h>
#include <ctype.h>

int main() {
    char s[30];
    int i = 1;

    scanf("%s", s);

    if (!(isalpha(s[0]) || s[0] == '_'))
        i = 0;

    for (int j = 1; s[j]; j++)
        if (!(isalnum(s[j]) || s[j] == '_'))
            i = 0;

    printf(i ? "Valid Identifier" : "Invalid Identifier");
    return 0;
}
