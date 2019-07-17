#include <set>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxn=500;
set<int> vis;
long long num[maxn], nsize=1;
void init(int idx){
    if (idx>=450) return;
    if (vis.count(num[idx]*2)==false){num[nsize++]=num[idx]*2; vis.insert(num[idx]*2);}
    if (vis.count(num[idx]*3)==false){num[nsize++]=num[idx]*3; vis.insert(num[idx]*3);}
    init(idx+1);
}

int main(void){
    int n, cnt=0, a, b;

    num[0]=1; init(0);
    sort(num, num+nsize);
    scanf("%d%d", &a, &b);
    for (int i=0; i<nsize; i++){
        if (num[i]>b) break;
        if (num[i]>=a) cnt++;
    }printf("%d\n", cnt);

    return 0;
}
