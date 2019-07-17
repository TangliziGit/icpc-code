#include <cstdio>
#include <algorithm>
using namespace std;
int T;
char str[3][10];

int main(void){
	scanf("%d", &T);

	while (T--){
		int vis[15]={0}, w[15]={0};
		for (int counter=0; counter<3; counter++){
			scanf("%s %s %s", str[0], str[1], str[2]);

			if (str[2][0]=='e'){
				for (int i=0; str[0][i]; i++)
					vis[str[0][i]-'A']=vis[str[1][i]-'A']=1;
			}else if (str[2][0]=='u'){
				for (int i=0; str[0][i]; i++){
					int left=str[0][i]-'A', right=str[1][i]-'A';
					if (!vis[left]) w[left]++;
					if (!vis[right]) w[right]--;
				}
			}else if (str[2][0]=='d'){
				for (int i=0; str[0][i]; i++){
					int left=str[0][i]-'A', right=str[1][i]-'A';
					if (!vis[left]) w[left]--;
					if (!vis[right]) w[right]++;
				}
			}
		}
		int max=-1, idx=-1;
		for (int i=0; i<='L'-'A'; i++)
			if (!vis[i] && abs(w[i])>max){max=abs(w[i]); idx=i;}
		printf("%c is the counterfeit coin and it is %s.\n", idx+'A', (w[idx]<0)?"light":"heavy");
	}

	return 0;
}