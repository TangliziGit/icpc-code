#include <cstdio>
#include <algorithm>
int l, n, m, dis[int(5e4)+5];
bool solve(int mid){
    int cnt=0, prev=0;
    for (int i=0; i<=n; i++){
        int idis=dis[i]-prev;
        if (idis<mid) cnt++;
        else prev=dis[i];
    }return cnt<=m;
}

int search(int min, int max){
    int x=min, y=max;
    while (y>x){
        int mid=x+(y-x+1)/2;
        if (solve(mid)) x=mid;
        else y=mid-1;
    }return y;
}

int main(void){
    while (scanf("%d%d%d", &l, &n, &m)==3){
        for (int i=0; i<n; i++) scanf("%d", &dis[i]);
        dis[n]=l;
        std::sort(dis, dis+n+1);
        printf("%d\n", search(0, l));
    }

    return 0;
}
