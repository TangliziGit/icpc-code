#include <cstdio>
#include <map>
using namespace std;
int n;
long long path[105];
long long num[105];
map<long long, int> mp;

bool dfs(int depth){
    if (depth==n) {
        for (int i=0; i<n; i++)
            printf("%I64d%c", path[i], " \n"[i==n-1]);
        return true;
    }
    // printf("%d %I64d\n", depth, path[depth-1]);

    long long &numb=path[depth-1];
    if (numb%3==0 && mp.count(numb/3) && mp[numb/3]>0){
        mp[numb/3]--;
        path[depth]=numb/3;
        if (dfs(depth+1)) return true;
        mp[numb/3]++;
    }
    if (mp.count(numb*2) && mp[numb*2]>0){
        mp[numb*2]--;
        path[depth]=numb*2;
        if (dfs(depth+1)) return true;
        mp[numb*2]++;
    }return false;
}

int main(void){
    scanf("%d", &n);
    for (int i=0; i<n; i++){
        scanf("%I64d", &num[i]);
        if (mp.count(num[i])==false) mp[num[i]]=0;
        mp[num[i]]++;
    }
    for (int i=0; i<n; i++){
        path[0]=num[i];
        if (dfs(1)) break;
    }

    return 0;
}
