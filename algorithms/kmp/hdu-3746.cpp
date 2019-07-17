#include <cstdio>
#include <cstring>
void getnext(int next[], char str[], int len){
    // point to the nearest prefix substr.
    next[0]=next[1]=0;
    for (int i=1; i<len; i++){
        int j=next[i];
        while (j && str[i]!=str[j]) j=next[j];
        next[i+1]=(str[i]==str[j]?j+1:0);
    }
}

int main(void){
    int T, next[100000+20];
    char str[100000+20];

    scanf("%d", &T);
    while (T--){
        scanf("%s", str);
        getnext(next, str, strlen(str));
        int len=strlen(str), loop=len-next[len];
        
        if (len%loop) printf("%d\n", loop-len%loop);
        else printf("%d\n", (len==loop)?loop:0);
    }

    return 0;
}
