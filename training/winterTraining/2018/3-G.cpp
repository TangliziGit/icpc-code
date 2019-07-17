#include <cstdio>
int n, m, money[int(1e5)+5];
int solve(long long mid){
    long long cnt=0, sum=0;
    for (int i=0; i<n; i++){
        if (money[i]+sum>mid){
            sum=money[i];
            cnt++;
        }else sum+=money[i];
    }return cnt+1<=m;
}

long long search(long long min, long long max){
    long long x=min, y=max;
    while (y-x>0){
        long long mid=x+(y-x)/2;
        if (solve(mid)) y=mid;
        else x=mid+1;
    }return y;
}

int main(void){
    while (scanf("%d%d", &n, &m)==2){
        long long max=0, min;
        for (int i=0; i<n; i++){
            scanf("%d", &money[i]);
            max+=money[i];
            if (min<money[i] || i==0) min=money[i];
        }
        printf("%lld\n", search(min, max));
    }

    return 0;
}
