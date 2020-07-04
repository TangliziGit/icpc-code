#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
long long tar;
char str[30];

long long calc(int v, int w, int x, int y, int z) {
    v = str[v] - 'A' + 1;
    w = str[w] - 'A' + 1;
    x = str[x] - 'A' + 1;
    y = str[y] - 'A' + 1;
    z = str[z] - 'A' + 1;
    return v - w*w + x*x*x - y*y*y*y + z*z*z*z*z;
}

int main(void) {
    while (scanf("%lld%s", &tar, str) == 2 && tar) {
        int len = strlen(str);
        sort(str, str+len-1);

        bool flg = false;
        for (int i=len-1; i>=0 && !flg; i--) 
            for (int j=len-1; j>=0 && !flg; j--) if (i != j)
                for (int x=len-1; x>=0 && !flg; x--)  if (i!=x && j!=x)
                    for (int y=len-1; y>=0 && !flg; y--) if (i!=y && j!=y && x!=y)
                        for (int z=len-1; z>=0 && !flg; z--) if (i!=z && j!=z && x!=z && y!=z){

                            long long ans = calc(i, j, x, y, z);
                            if (ans == tar) {
                                printf("%c%c%c%c%c\n", str[i], str[j], str[x], str[y], str[z]);
                                flg = true;
                            }
                        }
        if (!flg)
            printf("no solution\n");
    }

    return 0;
}
