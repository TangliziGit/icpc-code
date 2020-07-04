#include <map>
#include <string>
#include <cstdio>
#include <algorithm>
using namespace std;
const int nmax = 1e3 + 10, mmax = 1e6 + 10;
struct Edge {
    int from, to;
    float dis;
    Edge(int from, int to, float dis):
        from(from), to(to), dis(dis) {}
    Edge() {}
    bool operator < (const Edge &x) const {
        return dis < x.dis;
    }
}edges[mmax];

map<string, int> dic;
int n, m, esize;
int pre[nmax];

int find(int x) {
    return (x == pre[x])?x:(pre[x]=find(pre[x]));
}

double Krus(void) {
    sort(edges, edges+esize);

    double ans = 0;
    int cnt = 0;
    for (int i=0; i<m && cnt<n-1; i++) {
        Edge &e = edges[i];
        if (find(e.from) == find(e.to)) continue;
        pre[find(e.to)] = find(e.from);
        ans += e.dis;
        cnt++;
    }

    return (cnt<n-1)?-1:ans;
}

int main(void) {
    double length, dis;
    char name[30], name2[30];
    int from, to;

    while (scanf("%lf", &length) == 1) {
        scanf("%d", &n);
        for (int i=1; i<n+1; i++) pre[i] = i;
        for (int i=0; i<n; i++) {
            scanf("%s", name);
            dic[string(name)] = dic.size()+1;
        }

        scanf("%d", &m);
        for (int i=0; i<m; i++) {
            scanf("%s%s%lf", name, name2, &dis);
            from = dic[string(name)];
            to = dic[string(name2)];
            edges[esize++] = Edge(from, to, dis);
        }

        double ans = Krus();
        if (ans < 0 || ans >= length) printf("Not enough cable\n");
        else printf("Need %.1lf miles of cable\n", ans);
    }

    return 0;
}
