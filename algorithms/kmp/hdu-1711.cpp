#include <cstdio>
const int maxn=1e6, maxm=1e4;
int pattern[maxm+5], in[maxn+5], next[maxm+5];
void kmppre(int m){
	next[0]=next[1]=0;
	for (int i=1; i<m; i++){
		int j=next[i];
		while (j && pattern[j]!=pattern[i]) j=next[j];
		next[i+1]=(pattern[i]==pattern[j]?j+1:0);
	}
}

int kmp(int n, int m){
	kmppre(m);
	for (int i=0, j=0; i<n; i++){
		while (j && in[i]!=pattern[j]) j=next[j];
		if (pattern[j]==in[i]) j++;
		if (j==m) return i-m+2;
	}return -1;
}

int main(void){
	int T, n, m;

	scanf("%d", &T);
	while (T--){
		scanf("%d%d", &n, &m);
		for (int i=0; i<n; i++) scanf("%d", &in[i]);
		for (int i=0; i<m; i++) scanf("%d", &pattern[i]);
		printf("%d\n", kmp(n, m));
	}

	return 0;
}
