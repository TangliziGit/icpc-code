#include <cmath>
#include <cstdio>
#include <algorithm>
using namespace std;
long long n, k, num[int(1e5)+5];
bool solve(long long mid){
    long long time=0;
    for (int i=n-1; i>=0; i--){
        if (num[i]<=mid) break;
        time+=ceil((num[i]-mid)/(float)(k-1));
        if (time>mid) return false;
    }return true;
}

long long search(long long max){
    sort(num, num+n);
    long long x=1, y=max;
    while (x<y){
        long long mid=x+(y-x)/2;
        if (solve(mid)) y=mid;
        else x=mid+1;
    }return y;
}

int main(void){
    while (scanf("%lld", &n)==1){
        long long max, ans;
        for (int i=0; i<n; i++){
            scanf("%lld", &num[i]);
            if (max<num[i] || i==0) max=num[i];
        }
        scanf("%lld", &k);
        if (k==1) printf("%lld\n", max);
        else printf("%lld\n", search(max));
    }

    return 0;
}
