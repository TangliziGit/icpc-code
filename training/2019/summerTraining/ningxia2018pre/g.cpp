// WA
// but thought is right
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int maxn=1e5+20;
const double eps=1e-6;
LL dis[maxn], sum[maxn];
LL que[maxn], siz;
int n, nq;
pair<LL, LL> q[maxn];

inline LL K(int i){return n-i;}
inline LL B(int i){return dis[i];}
double insX(int a, int b){
    return (B(b)-B(a))/(double)(K(a)-K(b));
}

void maintain(void){
    siz=0;
    for (int i=1; i<n; i++){
        while (siz-2>=0 && insX(i, que[siz-1])<=insX(que[siz-2], que[siz-1]))
            siz--;
        que[siz++]=i;
    }
}

bool cmpQ(const pair<LL, LL> &a, const pair<LL, LL> &b){
    return a.second<b.second;
}

int main(void){
    int T;

    scanf("%d", &T);
    while (T--){
        scanf("%d%d", &n, &nq);
        for (int i=1; i<n; i++) scanf("%lld", &dis[i]);
        for (int i=1; i<n-1; i++) scanf("%lld", &sum[i]);

        for (int i=n-2; i>=1; i--) sum[i]+=sum[i+1];
        for (int i=1; i<n-1; i++) dis[i]+=sum[i];
        for (int i=0; i<nq; i++) {scanf("%lld", &q[i].second); q[i].first=i;}
        sort(q, q+nq, cmpQ);

        maintain();
        LL ans[maxn];
        for (int i=0, ptr=0; i<nq; i++){
            while (ptr+1<siz && insX(que[ptr], que[ptr+1])<=q[i].second)
                ptr++;
            ans[q[i].first]=B(que[ptr])+K(que[ptr])*q[i].second;
        }

        for (int i=0; i<nq; i++)
            printf("%lld%c", ans[i], " \n"[i==nq-1]);
    }

    return 0;
}
