#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int mod=1e9+7;
const int maxn=700+20;
char str[maxn];
int data[maxn][maxn][3][3];
int dp(int l, int r, int stal, int star){
    if (l>r) return 0;
    if (stal!=0 && star!=0) return 0;
    if (data[l][r][stal][star]>=0) return 0;

    int ptr=l+1, dlt=1;
    data[l][r][stal][star]=0;
    while (dlt!=0 && ptr<=r) dlt+=((str[ptr++]==')')?-1:1);
    ptr--;
    for (int i=0; i<3; i++)
        for (int j=0; j<3; j++){
            data[l][r][stal][star]+=dp(l+1, ptr-1, i, j);
            data[l][r][stal][star]%=mod;
        }
    if (stal!=0 || star!=0) data[l][r][stal][star]-=dp(l+1, ptr-1, stal, star);
    data[l][r][stal][star]%=mod;
    data[l][r][stal][star]+=mod;
    data[l][r][stal][star]%=mod;
    data[l][r][stal][star]+=dp(k+1, r);
    return data[l][r][stal][star];
}

int main(void){
    scanf("%s", str);
    memset(data, -1, sizeof(data));

    int ans=0;
    for (int i=0; i<3; i++)
        for (int j=0; j<3; j++)
            ans=(ans+dp(0, strlen(str)-1, i, j))%mod;
    printf("%d\n", ans);

    return 0;
}
