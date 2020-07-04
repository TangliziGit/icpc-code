#include <queue>
#include <cstdio>
#include <cstring>
#include <utility>
#include <algorithm>
using namespace std;
typedef pair<int, int> Node;
const int pmax = 10000;
bool isPrime[pmax];
int pow[10];

void findPrimes(void) {
    memset(isPrime, true, sizeof(isPrime));
    isPrime[1] = false;
    for (int i=2; i<pmax; i++) if (isPrime[i]) {
        for (int j= (i<<1); j<pmax; j+=i)
            isPrime[j] = false;
    }
}

int solve(int start, int end) {
    bool vis[pmax];
    int pre[pmax];
    queue<Node> que;
    que.push(Node(start, 0));
    memset(vis, false, sizeof(vis));
    vis[start] = true;

    while (que.size()) {
        Node x = que.front(); que.pop();
        if (x.first == end) return x.second;

        int &from = x.first, cost = x.second+1;
        for (int d=0; d<4; d++) {
            int base = from - ((from/pow[d]) % 10)*pow[d];

            for (int xx=(d==0); xx<=9; xx++) {
                int to = base + xx*pow[d];
                if (to/pow[3] == 0) continue;
                if (to == from) continue;
                if (vis[to]) continue;
                if (!isPrime[to]) continue;
                vis[to]=true;
                pre[to]=from;
                que.push(Node(to, cost));
            }
        }
    }

    return -1;
}

int main(void) {
    int T, a, b;

    pow[0]=1;
    for (int i=1; i<5; i++) pow[i]=10*pow[i-1];
    findPrimes();

    scanf("%d", &T);
    while (T--) {
        scanf("%d%d", &a, &b);
        printf("%d\n", solve(a, b));
    }

    return 0;
}
