#include <cstdio>
#include <set>
using namespace std;
const int maxn=50;
set<int> num[maxn+5];
int n;
double check(int a, int b){
    int common=0, size=num[b].size()+num[a].size();
    for (set<int>::iterator it=num[a].begin(); it!=num[a].end(); it++){
        if (num[b].count(*it)) common++;
    }return common/(double)(size-common);
}

int main(void){
    scanf("%d", &n);
    for (int i=0, m; i<n; i++){
        scanf("%d", &m);
        for (int j=0, inpt; j<m; j++){
            scanf("%d", &inpt);
            num[i].insert(inpt);
        }
    }

    int m=0;
    scanf("%d", &m);
    for (int i=0, a, b; i<m; i++){
        scanf("%d%d", &a, &b);
        printf("%0.2f%%\n", check(a-1, b-1)*100);
    }

    return 0;
}
