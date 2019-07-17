#include <cstring>
#include <cstdio>
#include <set>
using namespace std;

int main(void){
    char str[int(1e3)+5];
    int n;
    set<int> s;

    scanf("%d", &n);
    for (int i=0; i<n; i++){
        scanf("%s", str);

        int len=strlen(str), tmp=0;
        for (int j=0; j<len; j++)
            tmp=tmp|(1<<(str[j]-'a'));
        s.insert(tmp);
    }

    printf("%lu\n", s.size());

    return 0;
}
