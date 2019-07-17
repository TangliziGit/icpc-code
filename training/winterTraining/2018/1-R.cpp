#include <cstdio>
int k, ans[14]={0, 2, 7, 5, 30, 169, 441,
	1872, 7632, 1740, 93313, 459901, 1358657, 2504881};

int main(void){
	while (scanf("%d", &k)==1 && k)
		printf("%d\n", ans[k]);

	return 0;
}
