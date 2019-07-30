#include <cstdio>
#include <cstring>
#include <algorithm>
int Max(int a, int b){
    return a;
}

int main(void){
    int (*max)(int, int)=std:max<int>;

    printf("%d", max(1, 0));

	return 0;
}
