#include <cstring>
#include <cstdio>

int main(void){
    char in[105];
    int T;

    scanf("%d", &T);
    while (T--){
        scanf("%s", in);

        int ans[300];
        int head=150, end=151, len=strlen(in), zptr=0;
        int xma=in[0]-'0', xmi=in[0]-'0', i=0;
        while (i<len){
            if (in[i]=='0'){
                bool zero=false;
                int min=10, mi=-1;
                for (int idx=i; idx<len; idx++){
                    if (!zero && in[idx]=='0') continue;
                    else if (zero && in[idx]=='0') break;
                    else if (in[idx]!='0'){
                        zero=true;
                        if (min>=in[idx]-'0') {min=in[idx]-'0'; mi=idx;}
                    }
                }

                if (zero){
                    if (head+1>=end || min<=ans[head+1]){
                        for (; in[i]=='0'; i++) ans[head--]=in[i]-'0';
                        for (; i<len && in[i]!='0'; i++){
                            if (i!=mi) ans[end++]=in[i]-'0';
                            else ans[head--]=in[i]-'0';
                        }
                    }else{
                        for (; in[i]=='0'; i++) ans[end++]=in[i]-'0';
                        for (; i<len && in[i]!='0'; i++)
                            ans[end++]=in[i]-'0';
                    }
                }else for (; i<len; i++) ans[end++]=0;
            }else {
                if (head+1>=end) ans[head--]=in[i]-'0';
                else for (int ptr=head+1; ptr<end; ptr++){
                    if (ans[ptr]>in[i]-'0'){
                        ans[head--]=in[i]-'0';
                        break;
                    }else if (ans[ptr]<in[i]-'0' || ptr==end-1){
                        ans[end++]=in[i]-'0';
                        break;
                    }
                }
                i++;
            }
        }

        int ptr=head+1;
        while (ptr<end) printf("%d", ans[ptr++]);
        printf("\n");
    }

    return 0;
}
