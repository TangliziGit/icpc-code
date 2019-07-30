#include <algorithm>
#include <cstring>
#include <cstdio>
using namespace std;
const int MAX=15000;
int n, px[MAX+5], py[MAX+5], level[MAX+5], data[MAX+5];
int dp(int x){
    if (data[x]!=-1) return data[x];
    data[x]=0;
    for (int i=0; i<x; i++)
        if (px[x]>=px[i] && py[x]>=py[i]) data[x]=max(data[x], dp(i)+1);
    level[data[x]]++;
    return data[x];
}

int main(void){
    while (scanf("%d", &n)==1 && n){
        memset(level, 0, sizeof(level));
        memset(data, -1, sizeof(data));
        for (int i=0; i<n; i++) scanf("%d%d", &px[i], &py[i]);
        for (int i=0; i<n; i++) printf("%d %d\n", i, dp(i));
        for (int i=0; i<n; i++) printf("%d\n", level[i]);
    }

    return 0;
}
