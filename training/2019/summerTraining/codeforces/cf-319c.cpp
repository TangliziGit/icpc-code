/*
 * Let dp[i] is No.i tree's cost.
 * Because of b[n]==0, so we just want dp[n].
 * 
 * */
#include <cstdio>
#define debug(x) printf("%s == %d\n", #x, x)
typedef long long LL;
const int maxn=1e5+20;
LL a[maxn], b[maxn], dp[maxn];
LL que[maxn], first, last;

double grad(int i, int j){
    return (-dp[i]+dp[j])/(double)(b[i]-b[j]);
}

int main(void){
    int n;
    while (scanf("%d", &n)==1){
        for (int i=1; i<=n; i++) scanf("%I64d", &a[i]);
        for (int i=1; i<=n; i++) scanf("%I64d", &b[i]);

        first=last=0;
        dp[1]=0; que[last]=1;
        for (int i=2; i<=n; i++){
            while (first<last && grad(que[first], que[first+1])<=a[i]) first++;
            
            int j=que[first];
            dp[i]=dp[j]+a[i]*b[j];
            while (first<last && grad(que[last-1], que[last])>=grad(que[last], i))
                last--;
            que[++last]=i;
        }
        printf("%I64d\n", dp[n]);
    }

    return 0;
}
