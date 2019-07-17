#include <cstdio>
#include <cstring>
using namespace std;
const int maxn=5e4+20;
int pnt[maxn*3];
int n, k;

int find(int x){
    return (x==pnt[x])?(x):(pnt[x]=find(pnt[x]));
}

void join(int a, int b){
    // !!!!
    a=find(a); b=find(b);
    if (a==b) return;
    pnt[a]=b;
}

int main(void){
    int t, x, y;
    for (int i=0; i<maxn*3; i++) pnt[i]=i;
    scanf("%d%d", &n, &k);

    int ans=0;
    for (int i=0; i<k; i++){
        scanf("%d%d%d", &t, &x, &y);
        if (x>n || y>n) ans++;
        else if (t==2 && x==y) ans++;
        else if (t==1){
            if (find(x)==find(y+maxn) || find(x)==find(y+maxn*2)) ans++; else{
                join(x, y);
                join(x+maxn, y+maxn);
                join(x+2*maxn, y+2*maxn);
            }
        }else if (t==2){
            if (find(x)==find(y) || find(x)==find(y+maxn)) ans++;
            else{
                join(x, y+2*maxn);
                join(x+maxn, y);
                join(x+2*maxn, y+maxn);
            }
        }
    }
    printf("%d\n", ans);

    return 0;
}
