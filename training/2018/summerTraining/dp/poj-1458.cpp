#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxn=1e3+20;

int main(void){
    char str[maxn], in[maxn];
    int dp[maxn];

    while (scanf("%s%s", str, in)==2){
        int n=strlen(in);
        memset(dp, 0, sizeof(dp));
        for (int i=0; i<n; i++){
            dp[i]=1;
            for (int j=i; j>=0; j--) if (str[j]==in[i]){
                dp[i]=max(dp[i], dp[j]+1);
            }
        }printf("%d\n", dp[n-1]);
    }

    return 0;
}
