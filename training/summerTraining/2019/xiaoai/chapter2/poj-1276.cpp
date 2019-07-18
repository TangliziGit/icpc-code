#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxw=1e5+20, maxn=10+5;
int total, n;
int dp[maxw], cash[maxn], num[maxn];

void compKnap(int cost, int val){
	for (int i=cost; i<=total; i++)
		dp[i]=max(dp[i], dp[i-cost]+val);
}

void zeroKnap(int cost, int val){
	for (int i=total; i>=cost; i--)
		dp[i]=max(dp[i], dp[i-cost]+val);
}

int main(void){
	while (scanf("%d%d", &total, &n)==2){
		for (int i=0; i<n; i++)
			scanf("%d%d", &num[i], &cash[i]);

		memset(dp, 0, sizeof(dp));
		for (int i=0; i<n; i++){
			if (cash[i]*num[i]>total)
				compKnap(cash[i], cash[i]);
			else{
				for (int k=1; k<num[i]; k*=2){
					zeroKnap(cash[i]*k, cash[i]*k);
					num[i]-=k;
				}
				zeroKnap(cash[i]*num[i], cash[i]*num[i]);
			}
		}

		for (int i=total; i>=0; i--) if (dp[i]==i){
			printf("%d\n", dp[i]);
			break;
		}
	}

	return 0;
}
