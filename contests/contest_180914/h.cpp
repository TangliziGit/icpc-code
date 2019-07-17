#include <cstdio>
#include <string>
#include <cstring>
using namespace std;
string tostr[20]={"rat","ox","tiger","rabbit","dragon","snake","horse","sheep","monkey","rooster","dog","pig"};
int main(void){
    int T;
    char input[2][100];

    scanf("%d", &T);
    while (T--){
        scanf("%s%s", input[0], input[1]);
        string in[2];
        in[0]=input[0]; in[1]=input[1];

        int st, ed;
        for (int i=0; i<12; i++)
            if (tostr[i]==in[0]) st=i;
        for (int i=0; i<12; i++)
            if (tostr[i]==in[1]) ed=i;
        if (ed<=st) ed+=12;
        printf("%d\n", ed-st);
    }

    return 0;
}
