#include <cstring>
#include <cstdio>
struct Node{
    int cnt;
    Node *next[26];
    Node(int cnt=0):cnt(cnt){
        memset(next, NULL, sizeof(next));
    }
}root;
void insert(char *str){
    Node *ptr=&root;
    for (int i=0, len=strlen(str); i<len-1; i++){
        // printf("%c\n", str[i]);
        Node *&tmp=ptr->next[str[i]-'a'];
        if (tmp==NULL) tmp=new Node(1);
        else tmp->cnt++;
        ptr=tmp;
    }
}

int find(char *str){
    Node *ptr=&root;
    for (int i=0, len=strlen(str); i<len; i++)
        if ((ptr=ptr->next[str[i]-'a'])==NULL) return 0;
    return ptr->cnt;
}

int main(void){
    char str[15];

    while (fgets(str, sizeof(str), stdin) && str[0]!='\n')
        insert(str);
    while (scanf("%s", str)==1) printf("%d\n", find(str));

    return 0;
}
