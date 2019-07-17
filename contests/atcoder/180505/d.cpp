#include <cstdio>
#include <cmath>
#include <set>
using namespace std;
int n, sum, size, prime[6000];
int cvis[55], vis[55], path[55], p[55];
set<int> isprime;

void _prime(void){
    for (int i=2; size<6000; i++){
        bool flg=true;
        for (int mod=2; mod<=sqrt(i)+1 && mod<i; mod++)
            if (i%mod==0) {flg=false; break;}

        if (flg){prime[size++]=i; isprime.insert(i);}
    }printf("done\n");
}

bool check(int depth){
    if (depth==5) {
        int sum=prime[path[p[0]]]+prime[path[p[1]]]+prime[path[p[2]]]+prime[path[p[3]]]+prime[path[p[4]]];
        if (isprime.count(sum)) return false;
        else return true;
    }

    for (int i=0; i<55; i++){
        if (cvis[i]) continue;
        cvis[i]=true; p[depth]=i;
        if (check(depth+1)==false) return false;
        cvis[i]=false;
    }return true;
}

bool dfs(int depth, int range){
    if (depth==59){
        if (check(0)) return true;
        else return false;
    }

    for (int i=0; i<range; i++){
        if (vis[i])  continue;
        vis[i]=true; path[depth]=i;
        if (dfs(depth+1, range)) return true;
        vis[i]=false;
    }return false;
}

int main(void){
    // scanf("%d", &n);
    _prime();
    printf("last %d\n", prime[5999]);

    int range=800;
    if (dfs(0, range)) printf("GET!!\n");
    else printf("None\n");

    for (int i=0; i<55; i++) printf("%d, ", prime[path[i]]);

    return 0;
}
