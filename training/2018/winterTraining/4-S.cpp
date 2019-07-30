#include <cstdio>
#include <cstring>
const int hashSize=int(4e5), idxSize=int(1.6e7);
struct Data{
    int value, next, cnt;
    Data(int value=0, int next=-1, int cnt=0):
        value(value),next(next),cnt(cnt) {}
}data[idxSize];
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
        for (int i=head[key]; i!=-1; i=data[i].next)
            if (data[i].value==num) return data[i].cnt;
        return 0;
    }
    int insert(int num){
        int key=hash(num);
        for (int i=head[key]; i!=-1; i=data[i].next)
            if (data[i].value==num) {data[i].cnt++; return i;}
        data[size]=Data(num, head[key], 1);
        return head[key]=size++;
    }
};
int n;

int main(void){
    while (scanf("%d", &n)==1){
        int tmp[4000+5][4];
        for (int i=0; i<n; i++)
            scanf("%d%d%d%d", &tmp[i][0], &tmp[i][1], &tmp[i][2], &tmp[i][3]);

        Hash hash;
        for (int i=0; i<n; i++)
            for (int j=0; j<n; j++)
                hash.insert(tmp[i][2]+tmp[j][3]);

        int ans=0;
        for (int i=0; i<n; i++)
            for (int j=0; j<n; j++) ans+=hash.find(-tmp[i][0]-tmp[j][1]);
        printf("%d\n", ans);
    }

    return 0;
}
