#include <cstdio>
#include <algorithm>
#define debug(x) printf("%s = %d\n", #x, x)
using namespace std;
const int maxn=50000+20;
int L, M, N, block[maxn];

int judge(int mid){
	int prev=0, cnt=0;
	for (int i=0; i<=N; i++)
		if (block[i]-prev >= mid)
			prev=block[i];
		else cnt++;

	return cnt<=M;
}

int solve(void){
	int l=1, r=L;

	while (l<r){
		int mid=(l+r)/2;
		if (judge(mid)) l=mid+1;
		else r=mid-1;
	}

	for (int i=min(L, r+5); i>=max(0, l-5); i--)
		if (judge(i)) return i;
	return -1;
}

int main(void){
	while (scanf("%d%d%d", &L, &N, &M)==3){
		for (int i=0; i<N; i++) scanf("%d", &block[i]);
		block[N]=L;
		sort(block, block+N+1);
		printf("%d\n", solve());
	}

	return 0;
}
