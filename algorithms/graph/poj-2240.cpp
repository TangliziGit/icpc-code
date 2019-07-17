#include <map>
#include <queue>
#include <vector>
#include <string>
#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
const int maxn=35, INF=0x3f3f3f3f;
const double eps=1e-6;
struct Edge{
    int from, to;
    double rate;
};
map<string, int> words;
vector<Edge> edges;
vector<int> G[maxn+5];

inline void addEdge(int from, int to, double rate){
    edges.push_back((Edge){from, to, rate});
    G[from].push_back(edges.size()-1);
    // edges.push_back(Edge{to, from, 1/rate});
    // G[to].push_back(edges.size()-1);
}

inline bool equal(const double &a, const double &b){
    return ((a-b<=eps) && (b-a<=eps));
}

bool Bellman(int st, int n){
    double dist[maxn+5];
    bool inq[maxn+5]={false};
    int cnt[maxn+5]={0};
    queue<int> que;
    
    for (int i=0; i<=maxn; i++) dist[i]=0;//(double)INF;
    dist[st]=1.0; inq[st]=true;
    que.push(st);

    while (que.size()){
        int from=que.front(); que.pop();
        inq[from]=false;

        for (int i=0; i<G[from].size(); i++){
            Edge &e=edges[G[from][i]];
            int &to=e.to; double nrate=dist[from]*e.rate;

            if (dist[to]>nrate || equal(dist[to], nrate)) continue;
            dist[to]=nrate;

            if (inq[to]) continue;
            inq[to]=true;
            que.push(to);

            if (++cnt[to]>=n) return true;
        }
    }return false;
}

void init(void){
    for (int i=0; i<=maxn; i++) G[i].clear();
    edges.clear();
    words.clear();
}

int main(void){
    int n, m, cnt=1;
    double rate;
    string name, from, to;

    while (scanf("%d", &n)==1 && n){
        init();
        for (int i=1; i<=n; i++){
            cin >> name;
            words[name]=i;
        }// scanf("%d", &m);
        cin >> m;

        // for (map<string, int>::iterator it=words.begin(); it!=words.end(); it++){
        //     cout << it->first << " " << it->second;
        // }

        for (int i=0; i<m; i++){
            cin >> from >> rate >> to;
            addEdge(words[from], words[to], rate);
        }

        bool flg=false;
        for (int i=1; i<=n; i++)
            if (Bellman(i, n)){
                printf("Case %d: Yes\n", cnt++);
                flg=true;
                break;
            }
        if (!flg) printf("Case %d: No\n", cnt++);
    }

    return 0;
}
