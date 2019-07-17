#include <cstdio>
#include <cstring>
#include <algorithm>
#include <set>
using namespace std;
const int maxlen=1e4+20;
char str[maxlen], tmp[maxlen];
set<char> cset;

int main(void){
    // scanf("%s%s", str, tmp);
    fgets(str, sizeof(str), stdin);
    fgets(tmp, sizeof(tmp), stdin);

    int tmplen=strlen(tmp), slen=strlen(str);
    for (int i=0; i<tmplen; i++)
        cset.insert(tmp[i]);
    for (int i=0; i<slen; i++)
        if (!cset.count(str[i])) printf("%c", str[i]);

    return 0;
}
