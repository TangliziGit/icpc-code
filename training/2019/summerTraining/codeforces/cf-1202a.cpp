#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxn=1e5+20;
char x[maxn], y[maxn];

int main(void){
    int T;

    scanf("%d", &T);
    while (T--){
        scanf("%s\n%s", x, y);

        int idxy=strlen(y)-1, idxx=strlen(x)-1;
        while (idxy>=0 && y[idxy]!='1') idxy--; idxx=strlen(x)-1-(strlen(y)-1-idxy);
        while (idxx>=0 && x[idxx]!='1') idxx--;
        idxx=strlen(x)-1-idxx;
        idxy=strlen(y)-1-idxy;
        printf("%d\n", idxx-idxy);
    }

    return 0;
}
