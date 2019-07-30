#include <cstdio>
#include <algorithm>
#include <queue>
using namespace std;
struct Interval{
    int start, end, id;
    Interval(int start=0, int end=0):
        start(start),end(end) {}
    bool operator < (const Interval &a) const{
        return start<a.start;
    }
}cows[int(5e4)+5];

struct Node{
    int value, ptr;
    Node(int value=0, int ptr=0):
        value(value),ptr(ptr) {}
    bool operator < (const Node &a) const{
        return value>a.value;
    }
};

int main(void){
    int n;

    while (scanf("%d", &n)==1 && n){
        for (int i=0; i<n; i++){
            scanf("%d%d", &cows[i].start, &cows[i].end);
            cows[i].id=i;
        }
        sort(cows, cows+n);
        
        priority_queue<Node> que;
        int ans[int(5e4)+5], vis[int(5e4)+5], size=0;
        for (int i=0; i<n; i++){
            if (que.size()==0 || que.top().value>=cows[i].start){
                que.push(Node(cows[i].end, size++));
                ans[cows[i].id]=size;
            }else{
                int ptr=que.top().ptr;
                ans[cows[i].id]=ptr+1;
                que.pop(); que.push(Node(cows[i].end, ptr));
            }
        }
        printf("%d\n", size);
        for (int i=0; i<n; i++) printf("%d\n", ans[i]);
    }

    return 0;
}
