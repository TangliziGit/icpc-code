#include <cstdio>
#include <cstring>
int data[100000+5][11], maxt;
bool vis[100000+5][11];
int max(int a, int b){
    if (a>b) return a;
    return b;
}

int dp(int time, int pos){
    if (time>maxt || pos<0 || pos>10) return 0;
    if (vis[time][pos]) return data[time][pos];

    int maxd=max(max(dp(time+1, pos-1), dp(time+1, pos)), dp(time+1, pos+1));
    data[time][pos]+=maxd;
    vis[time][pos]=true;
    return data[time][pos];
}

int main(void){
    int n, time, pos;

    while (scanf("%d", &n)==1 && n){
        maxt=0;
        memset(data, 0, sizeof(data));
        memset(vis, false, sizeof(vis));

        for (int i=0; i<n; i++){
            scanf("%d%d", &pos, &time);
            data[time][pos]++;
            maxt=max(maxt, time);
        }
        printf("%d\n", dp(0, 5));
    }

    return 0;
}
