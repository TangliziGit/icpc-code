#include <cstdio>
#include <algorithm>
using namespace std;
int a[int(2e5)+5];

int main(void){
    int n, k;

    scanf("%d%d", &n, &k);
    for (int i=0; i<n; i++) scanf("%d", &a[i]);
    sort(a, a+n);
    
    k--;
    if (k<=-1){
        if (a[0]==1) printf("-1\n");
        else printf("1\n");
    }else if (a[k]==a[k+1]) printf("-1\n");
    else printf("%d\n", a[k]);

    return 0;
}
