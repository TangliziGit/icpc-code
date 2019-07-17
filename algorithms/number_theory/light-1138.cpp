// binary search
// [f(m)<n, f(m)=n, f(m)>n]
// [l,      r,      r] (find min r)
// [l,      l,      r] (find max l)
//
// Attention:
// 1. make sure the initial value of l and r.
// 2. whlie (l<r-1).
// 3. l <= mid < r.
// 4. check if r(l) is the answer.

#include <cstdio>
long long find(long long n){
    long long ans=0;
    while (n){
        ans+=n/5; n/=5;
    }return ans;
}

long long search(long long n){
    long long l=1, r=5e8;
    while (l<r-1){
        long long mid=(r+l)/2, m=find(mid);
        if (m>=n) r=mid;
        else l=mid;
    }
    if (find(r)==n) return r;
    else return -1;
}

int main(void){
    int T; long long n;

    scanf("%d", &T);
    for (int cnt=1; cnt<=T; cnt++){
        scanf("%lld", &n);
        long long ans=search(n);
        if (ans>0) printf("Case %d: %lld\n", cnt, ans);
        else printf("Case %d: impossible\n", cnt);
    }

    return 0;
}
