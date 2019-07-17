#include <queue>
#include <cstdio>
const int maxn=1e6+20;
struct Item{
    int idx, val;
    Item(){}
    Item(int idx, int val)
        :idx(idx), val(val) {}
}que[maxn];
int n, k, seq[maxn];
int front, tail;

void maxInsert(Item it){
    while (front<tail && que[front].idx+k<=it.idx)
        front++;
    while (front<tail && que[tail-1].val<=it.val)
        tail--;
    que[tail++]=it;
}

void maxQueue(void){
    front=tail=0;
    for (int i=0; i<k-1; i++) maxInsert(Item(i, seq[i]));

    for (int i=k-1; i<n; i++){
        maxInsert(Item(i, seq[i]));
        printf("%d%c", que[front].val, " \n"[i==n-1]);
    }
}

void minInsert(Item it){
    while (front<tail && que[front].idx+k<=it.idx)
        front++;
    while (front<tail && que[tail-1].val>=it.val)
        tail--;
    que[tail++]=it;
}

void minQueue(void){
    front=tail=0;
    for (int i=0; i<k-1; i++) minInsert(Item(i, seq[i]));

    for (int i=k-1; i<n; i++){
        minInsert(Item(i, seq[i]));
        printf("%d%c", que[front].val, " \n"[i==n-1]);
    }
}

int main(void){
    scanf("%d%d", &n, &k);
    for (int i=0; i<n; i++) scanf("%d", &seq[i]);
    minQueue(); maxQueue();

    return 0;
}
