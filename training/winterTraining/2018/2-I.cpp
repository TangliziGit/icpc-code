#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int tar;
char vis[15];
inline bool cmp(const int &a, const int &b){
    return a>b;
}

inline int func(char *path){
    int re=(path[0]-'A'+1)-(path[1]-'A'+1)*(path[1]-'A'+1)+
        (path[2]-'A'+1)*(path[2]-'A'+1)*(path[2]-'A'+1)-
        (path[3]-'A'+1)*(path[3]-'A'+1)*(path[3]-'A'+1)*(path[3]-'A'+1)+
        (path[4]-'A'+1)*(path[4]-'A'+1)*(path[4]-'A'+1)*(path[4]-'A'+1)*(path[4]-'A'+1)-
        tar;
    return re==0;
}

bool dfs(int depth, char *path, const int &vsize){
    if (depth==5 && func(path)){
        path[depth]=0;
        return true;
    }else if (depth==5) return false;

    for (int i=0; i<vsize; i++){
        if (vis[i]==0) continue;
        path[depth]=vis[i]; vis[i]=0;
        if (dfs(depth+1, path, vsize)) return true;
        vis[i]=path[depth];
    }return false;
}

int main(void){
    while (scanf("%d%s", &tar, vis)==2 && tar){
        char path[10], vsize=strlen(vis);
        sort(vis, vis+vsize, cmp);
        if (dfs(0, path, vsize)) printf("%s\n", path);
        else printf("no solution\n");
    }

    return 0;
}
