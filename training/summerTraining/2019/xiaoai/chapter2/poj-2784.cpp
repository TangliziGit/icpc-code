#include <cstdio>
#include <cstring>
#include <algorithm>
#define debug(x) printf("%s = %d\n", #x, x)
using namespace std;
const int maxn=1e3+20, maxe=maxn*maxn*2,
		maxk=8+5, INF=0x3f3f3f3f;
struct Edge{
	int from, to, dis;
	Edge(int from, int to, int dis)
		:from(from), to(to), dis(dis) {}
	Edge(){}
	bool operator < (const Edge &e){
		return dis<e.dis;
	}
}edges[maxe];
int siz, n, q;
int pre[maxn];
int kases[maxk][maxn], cost[maxk], num[maxk];
int px[maxn], py[maxn];

void addEdge(int from, int to, int dis){
	edges[siz++]=Edge(from, to, dis);
}

int dis(int from, int to){
	return (px[from]-px[to])*(px[from]-px[to])+
		(py[from]-py[to])*(py[from]-py[to]);
}

int find(int x){
	return (pre[x]==x)?x:(pre[x]=find(pre[x]));
}

void join(int a, int b){
	a=find(a); b=find(b);
	if (a==b) return;
	pre[a]=b;
}

void use(int idx){
	for (int i=0; i<num[idx]; i++)
		join(kases[idx][i], kases[idx][0]);
}

int kruskal(void){
	// cnt optimize
	int sum=0;
	for (int i=0; i<siz; i++){
		Edge &e=edges[i];

		if (find(e.from)==find(e.to))
			continue;
		sum+=e.dis;
		join(e.from, e.to);
	}return sum;
}

int solve(void){
	int ans=INF;
	sort(edges, edges+siz);
	for (int kase=0; kase<(1<<q); kase++){
		int sum=0;
		for (int i=0; i<=n; i++) pre[i]=i;
		for (int i=0; i<q; i++)
			if (kase & (1<<i)) use(i), sum+=cost[i];

		ans=min(ans, kruskal()+sum);
	}return ans;
}

int main(void){
	while (scanf("%d%d", &n, &q)==2){
		siz=0;
		for (int i=0; i<q; i++){
			scanf("%d%d", &num[i], &cost[i]);
			for (int j=0; j<num[i]; j++)
				scanf("%d", &kases[i][j]);
		}

		for (int from=1; from<=n; from++){
			scanf("%d%d", &px[from], &py[from]);
			for (int to=1; to<from; to++)
				addEdge(from, to, dis(from, to));
		}
		printf("%d\n", solve());
	}

	return 0;
}
