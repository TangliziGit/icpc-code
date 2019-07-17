#include <map>
#include <cstdio>
#include <string>
#include <cstring>
using namespace std;

int main(void){
    int n, m;
    char str[255];
    map<string, int> red, blue;

    scanf("%d", &n);
    for (int i=0; i<n; i++){
        scanf("%s", str);
        string s(str);
        if (red.count(s)==false) red[s]=0;
        red[s]++;
    }
    scanf("%d", &m);
    for (int i=0; i<m; i++){
        scanf("%s", str);
        string s(str);
        if (blue.count(s)==false) blue[s]=0;
        blue[s]++;
    }

    int ma=0;
    for (map<string, int>::iterator it=red.begin(); it!=red.end(); it++){
        if (blue.count(it->first)) ma=max(ma, it->second-blue[it->first]);
        else ma=max(ma, it->second);
    }printf("%d\n", ma);

    return 0;
}
