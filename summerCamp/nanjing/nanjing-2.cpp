#include <cstdio>
#include <cstring>

int main(void) {
    char str[100];

    fgets(str, sizeof(str), stdin);
    for (int i=0; str[i]!='\n' && str[i]!=0; i++)
        printf("%c", str[i]);
    for (int i=strlen(str)-1-(str[strlen(str)-1]=='\n'); i>=0; i--)
        printf("%c", str[i]);

    return 0;
}
