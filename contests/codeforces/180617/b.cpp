#include <cstdio>
#include <map>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
struct A{
    long long pow, val;
    bool operator < (const A a) const{
        return pow<a.pow;
    }
}a[(int)1e5+20];
long long b[(int)1e5+20];

int main(void){
    int n, m;

    scanf("%d%d", &n, &m);
    for (int i=0; i<n; i++){scanf("%I64d", &a[i].pow); b[i]=a[i].pow;}
    for (int i=0; i<n; i++) scanf("%I64d", &a[i].val);
    sort(a, a+n);

    map<int, long long> ans;// int ans[(int)1e5+20];
    priority_queue<int> que;
    for (int i=0; i<n; i++){
        int p=a[i].pow;
        vector<int> vec;
        ans[p]=a[i].val;
        while (que.size() && vec.size()<m){
            long long x=que.top(); que.pop();
            ans[p]+=x;
            vec.push_back(x);
        }
        for (int i=0; i<vec.size(); i++)
            que.push(vec[i]);
        que.push(a[i].val);
    }

    for (int i=0; i<n; i++)
        printf("%I64d ", ans[b[i]]);
    printf("\n");

    return 0;
}
