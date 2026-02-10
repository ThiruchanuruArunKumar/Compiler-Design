#include <stdio.h>
#include <ctype.h>

int main() {
    FILE *fp = fopen("input.txt", "r");
    char c;

    if (!fp) {
        printf("File not found\n");
        return 0;
    }

    while ((c = fgetc(fp)) != EOF) {

        if (isspace(c))
            continue;

        if (c == '/') {
            char n = fgetc(fp);

            if (n == '/') {
                while ((c = fgetc(fp)) != '\n' && c != EOF);
            }
            else if (n == '*') {
                while ((c = fgetc(fp)) != EOF) {
                    if (c == '*' && fgetc(fp) == '/')
                        break;
                }
            }
        }
    }

    rewind(fp);

    printf("\n--- File Content ---\n");
    while ((c = fgetc(fp)) != EOF) {
        putchar(c);
    }

    fclose(fp);
    return 0;
}
