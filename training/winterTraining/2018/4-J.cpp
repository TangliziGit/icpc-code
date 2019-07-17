#include <cstring>
#include <cstdio>
struct Node{
    bool end;
    int next[2];
}node[1<<8];
int cnt=1, size=1;
bool insert(char *x, int pos){
    if (*x=='\n'){
        node[pos].end=true;
        if (node[pos].next[0] || node[pos].next[1]) return true;
        return false;
    }
    if (node[pos].end) return true;
    if (node[pos].next[*x-'0']==0) node[pos].next[*x-'0']=size++;
    return insert(x+1, node[pos].next[*x-'0']);
}

int main(void){
    char str[255];
    bool flag=false;

    memset(node, 0, sizeof(node));
    while (fgets(str, sizeof(str), stdin)){
        if (str[0]=='0' || str[0]=='1'){
            if (flag) continue;
            else flag=insert(str, 0);
        }else{
            if (flag) printf("Set %d is not immediately decodable\n", cnt++);
            else printf("Set %d is immediately decodable\n", cnt++);
            memset(node, 0, sizeof(Node)*(size));
            flag=false; size=1;
        }
    }

    return 0;
}
