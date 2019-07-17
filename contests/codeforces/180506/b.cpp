#include <cstdio>

int main(void){
    int n, max=-1, maxidx=0;
    char str[110];

    scanf("%d%s", &n, str);
    for (int i=0; i<n-1; i++){
        int cnt=0;
        for (int j=0; j<n-1; j++){
            if (str[j]==str[i] && str[j+1]==str[i+1]) cnt++;
        }
        if (cnt>max){
            max=cnt;
            maxidx=i;
        }
    }printf("%c%c\n", str[maxidx], str[maxidx+1]);

    return 0;
}
