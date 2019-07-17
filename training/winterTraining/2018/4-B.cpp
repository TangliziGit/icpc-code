// dfs TLE
#include <cstdio>
int f, v, map[105][105];
void dfs(int fptr, int vptr, int total, int &max){
    if (fptr==f && total>max) max=total;
    if (fptr==f) return;

    for (int i=vptr, prev=-51; i<v+fptr-f+1; i++){
        if (map[fptr][i]<=prev) continue;
        dfs(fptr+1, i+1, total+map[fptr][i], max);
        prev=map[fptr][i];
    }
}

int main(void){
    while (scanf("%d%d", &f, &v)==2){
        for (int i=0; i<f; i++)
            for (int j=0; j<v; j++)
                scanf("%d", &map[i][j]);
        int max=-50*100-5; dfs(0, 0, 0, max);
        printf("%d\n", max);
    }

    return 0;
}
