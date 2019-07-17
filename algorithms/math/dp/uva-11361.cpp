#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxn=10+5, maxk=1e2+20; // when k>=90, no solution.
long long data[maxn][maxk][maxk];
long long _pow10[maxn];
long long a, b, k, len;
char num[maxn];
long long dp(int pos, bool lim, int mod, int sum){
    if (pos==-1 && mod==0 && sum==0) return 1;
    if (pos==-1) return 0;
    if (!lim && data[pos][mod][sum]>=0)             // 2
        return data[pos][mod][sum];

    long long ans=0;
    int end=(lim)?(num[pos]-'0'):9;
    for (int i=0; i<=end; i++)
        ans+=dp(pos-1, lim && i==end, (mod+(long long)i*_pow10[pos])%k, (sum+i)%k);

    if (!lim) data[pos][mod][sum]=ans;
    return ans;
}

void init(void){
    _pow10[0]=1;
    for (int i=1; i<maxn; i++)
        _pow10[i]=_pow10[i-1]*(long long)10;
}

long long solve(long long n){
    sprintf(num, "%lld", n);
    len=strlen(num);
    reverse(num, num+len);                           // 1
    memset(data, -1, sizeof(data));
    return dp(len-1, true, 0, 0);
}

int main(void){
    int T;

    init();
    scanf("%d", &T);
    while (T--){
        scanf("%lld%lld%lld", &a, &b, &k);
        if (k<maxk) printf("%lld\n", solve(b)-solve(a-1));
        else printf("0\n");
    }

    return 0;
}
