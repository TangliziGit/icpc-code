#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int main(void){
    char str[2][int(1e3)+5];

    while (scanf("%s%s", str[0], str[1])==2){
        int dp[int(1e3)+5][int(1e3)+5]={0}, len[2]={strlen(str[0]), strlen(str[1])};
        for (int i=1; i<=len[0]; i++){
            for (int j=1; j<=len[1]; j++){
                if (str[0][i-1]==str[1][j-1]) dp[i][j]=dp[i-1][j-1]+1;
                else dp[i][j]=max(dp[i-1][j], dp[i][j-1]);
            }
        }printf("%d\n", dp[len[0]][len[1]]);
    }

    return 0;
}
