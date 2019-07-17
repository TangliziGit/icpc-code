#include <cstring>
#include <cstdio>
#include <queue>
#include <set>
using namespace std;
const int maxn=100000+20;
struct Node{
    int id, next;
    Node(int id=0, int next=0):id(id), next(next) {}
    bool operator < (const Node &a) const{
        return next<a.next;
    }
};

int main(void){
    int n, m, ques[maxn];

    while (scanf("%d%d", &n, &m)==2 && n){
        int pre[maxn], next[maxn];
        memset(pre, -1, sizeof(pre));
        for (int i=0; i<n; i++) scanf("%d", &ques[i]);
        for (int i=n-1; i>=0; i--){
            if (pre[ques[i]]==-1) pre[ques[i]]=n;
            next[i]=pre[ques[i]];
            pre[ques[i]]=i;
        }

        set<Node> table;
        set<int> value;
        for (int i=1; i<=m; i++){
            table.insert(Node(i, pre[i]));
            value.insert(pre[i]);
        }//printf("%d(%d)--\n", i, pre[i]);

        // for (set<Node>::iterator it=table.begin(); it!=table.end(); it++){
        //     printf("%d(%d)++\n", (*it).id, (*it).next);
        // }

        int cnt=0;
        for (int i=0; i<n; i++){
            Node node(ques[i], pre[ques[i]]);
            // printf("%d(%d)\n", ques[i], pre[ques[i]]);
            if (!value.count(pre[ques[i]])){// !table.count(node)){
                cnt++;
                Node mnode=*(table.begin());
                table.erase(mnode);
                value.erase(pre[ques[i]]);
                table.insert(Node(ques[i], next[i]));
                value.insert(next[i]);
                pre[ques[i]]=i;
                // printf("lost! %d\n", next[i]);
                // printf("lost%d drop%d(%d) new%d\n",
                //     ques[i], node.id, node.next, next[i]);
            }else{
                // table.erase(node);
                table.insert(Node(ques[i], next[i]));
                pre[ques[i]]=i;
            }
        }printf("%d\n", cnt);
    }
    
    return 0;
}
