#include <cstring>
#include <cstdio>
const int maxn=1e3+10, maxm=1e3+10;
char P[maxm+5], T[maxn+5];
int fail[maxm+5];
void getFail(int m){
	fail[0]=fail[1]=0;
	for (int i=1; i<m; i++){
		int j=fail[i];
		while (j && P[i]!=P[j]) j=fail[j];
		fail[i+1]=(P[i]==P[j]?j+1:0);
	}
}

int mp(int n, int m){
	int ans=0;
	getFail(m);
	for (int i=0, j=0; i<n; i++){
		while (j && P[j]!=T[i]) j=fail[j];
		if (P[j]==T[i]) j++;
		if (j==m){
			ans++;
			j=0;//+=m+1;
		}
	}return ans;
}

int main(void){
	while (scanf("%s", T)==1 && T[0]!='#'){
		scanf("%s", P);
		printf("%d\n", mp(strlen(T), strlen(P)));
	}

	return 0;
}

