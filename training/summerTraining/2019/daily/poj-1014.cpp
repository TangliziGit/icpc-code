#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxn=20000*6+50, maxh=6;
int num[maxh];
int dp[maxn], total;

void compKnap(int cost, int val){
	for (int i=cost; i<=total; i++)
		dp[i]=max(dp[i], dp[i-cost]+val);
}

void zeroKnap(int cost, int val){
	for (int i=total; i>=cost; i--)
		dp[i]=max(dp[i], dp[i-cost]+val);
}

int main(void){
	int kase=0;
	while (scanf("%d", &num[0])==1){
		int sum=num[0];
		for (int i=1; i<maxh; i++)
			scanf("%d", &num[i]), sum+=num[i]*(i+1);

		if (sum%2){
			printf("Collection #%d:\nCan't be divided.\n\n", ++kase);
			continue;
		}else if (sum==0)
			break;

		total=sum/2;
		memset(dp, 0, sizeof(dp));
		for (int i=0; i<maxh; i++){
			if (num[i]*(i+1)>total)
				compKnap(i+1, i+1);
			else{
				for (int k=1; k<num[i]; k*=2){
					zeroKnap((i+1)*k, (i+1)*k);
					num[i]-=k;
				}
				zeroKnap((i+1)*num[i], (i+1)*num[i]);
			}
		}

		if (dp[total]!=total)
			printf("Collection #%d:\nCan't be divided.\n\n", ++kase);
		else
			printf("Collection #%d:\nCan be divided.\n\n", ++kase);
	}

	return 0;
}
