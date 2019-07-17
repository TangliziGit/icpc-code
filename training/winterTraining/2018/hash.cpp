#include <cstdio>
#include <cstring>
const int hashSize=int(4e5), idxSize=int(1.6e7);
struct Node{
    int value, next, data;
    Node(int value=0, int next=0, int data=0):
        value(value),next(next),data(data) {}
}node[idxSize];
int head[hashSize];
struct Hash{
    int size;
    Hash(void):size(0) {
        memset(head, -1, sizeof(head));
    }

    int hash(int num){
        return (num+hashSize)%hashSize;
    }
    int find(int num){
        int key=hash(num);
        for (int i=head[key]; i!=-1; i=node[i].next)
            if (node[i].value==num) return node[i].data;
        return 0;
    }
    int insert(int num){
        int key=hash(num), exist=false;
        for (int i=head[key]; i!=-1; i=node[i].next)
            if (node[i].value==num) return ++node[i].data;
        node[size].value=num; node[size].data=1;
        node[size].next=head[key];
        head[key]=size++;
        return 1;
    }
};

int main(void){
    Hash hash;

    for (int i=0; i<100; i++) hash.insert(i%5);
    for (int i=0; i<6; i++) printf("%d:%d\n", i, hash.find(i));

    return 0;
}
