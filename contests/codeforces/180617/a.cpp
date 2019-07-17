#include <cstdio>
#include <set>
using namespace std;

int main(void){
    int n, m, a[100], vis[20]={0};

    scanf("%d%d", &n, &m);
    for (int i=0; i<n; i++) scanf("%d", &a[i]);
    for (int i=0; i<m; i++){
        int tmp;
        scanf("%d", &tmp);
        vis[tmp]=1;
    }

    for (int i=0; i<n; i++) if (vis[a[i]])
        printf("%d ", a[i]);
    printf("\n");

    return 0;
}
