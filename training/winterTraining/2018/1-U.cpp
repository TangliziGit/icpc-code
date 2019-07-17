#include <cstdio>
long long m;
int t, u, f, d;

int main(void){
	while (scanf("%lld%d%d%d%d", &m, &t, &u, &f, &d)==5 && m){
		int flat=2*f, unflat=u+d, dis=0;
		char tmp[5];
		for (int i=0; i<t; i++){
			scanf("%s", tmp);
			if (m<=0) continue;

			if (tmp[0]=='f' && (m-=flat)>=0) dis++;
			else if ((m-=unflat)>=0) dis++;
		}printf("%d\n", dis);
	}

	return 0;
}