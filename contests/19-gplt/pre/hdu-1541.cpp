#include <cstdio>
#include <cstring>
using namespace std;
#define lowbit(x) ((x)&(-x))
const int maxx=32000+20;
int ans[maxx], tree[maxx], n;

int sum(int x){
    int sum=0;
    for (int i=x; i>0; i-=lowbit(i))
        sum+=tree[i];
    return sum;
}

void add(int x){
    for (int i=x; i<maxx; i+=lowbit(i))
        tree[i]++;
}

int main(void){
    int x, y;

    while (scanf("%d", &n)==1){
        memset(ans, 0, sizeof(ans));
        memset(tree, 0, sizeof(tree));
        for (int i=0; i<n; i++){
            scanf("%d%d", &x, &y); x+=1;
            ans[sum(x)]++;
            add(x);
        }

        for (int i=0; i<n; i++)
            printf("%d\n", ans[i]);
    }

    return 0;
}
