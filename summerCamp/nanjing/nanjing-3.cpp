#include <cstdio>
#include <cstring>
int a, b, c;
char str[120], ans[500];

bool digit(char x) {return '0' <= x && x <= '9';}
bool lower(char x) {return 'a' <= x && x <= 'z';}

bool same(char x, char y) {
    if (digit(x) && digit(y)) return true;
    if (lower(x) && lower(y)) return true;
    return false;
}

char convert(char x) {
    if (digit(x) && a != 3) return x;
    if (a == 1) return x;
    if (a == 2) return x+'A'-'a';
    if (a == 3) return '*';
    return '*';
}

int main(void) {
    scanf("%d%d%d", &a, &b, &c);
    scanf("%s", str);

    int size = 0, len = strlen(str);
    for (int i=0; i<len; i++) {
        if (str[i] != '-') ans[size++] = str[i];
        else {
            if (!(i+1<len && i-1 >=0 && str[i+1] - str[i-1] > 0 
                && same(str[i-1], str[i+1]))) {
                ans[size++] = str[i];
            } else {
                int start = str[i-1]+1, end = str[i+1], step = 1;
                if (c == 2) {start=str[i+1]-1; end=str[i-1]; step=-1;}
                for (char j=start; j!=end; j+=step) {
                    char ch = convert(j), cnt=b;
                    while (cnt --> 0) ans[size++] = ch;
                }
            }
        }
    }
    ans[size] = 0;
    printf("%s\n", ans);

    return 0;
}
