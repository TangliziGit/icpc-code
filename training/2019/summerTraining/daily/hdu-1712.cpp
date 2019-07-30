#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxt=100+20, maxg=100+20;
int ng, nt;
int dp[maxt], val[maxg][maxt];

int main(void){
	while (scanf("%d%d", &ng, &nt)==2 && ng){
		for (int i=0; i<ng; i++)
			for (int t=0; t<nt; t++) scanf("%d", &val[i][t]);

		memset(dp, 0, sizeof(dp));
		for (int group=0; group<ng; group++)
			for (int time=nt; time>0; time--)
				for (int k=1; k<=time; k++)
					dp[time]=max(dp[time], dp[time-k]+val[group][k-1]);

		printf("%d\n", dp[nt]);
	}

	return 0;
}
