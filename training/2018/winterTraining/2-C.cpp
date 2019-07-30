#include <cstdio>
#include <string>
#include <map>
using namespace std;

int main(void){
    // int default 0
    map<string, map<string, int> > table;
	int T, n;

    scanf("%d", &T);
    while (T--){
        int value;
        char kind[255], home[255];
        scanf("%d", &n);
        for (int i=0; i<n; i++){
            scanf("%s%s%d", kind, home, &value);
            table[home][kind]+=value;
        }
        
        map<string, map<string, int> >::iterator it;
        map<string, int>::iterator i;
        for (it=table.begin(); it!=table.end(); it++){
            printf("%s\n", it->first.c_str());
            for (i=it->second.begin(); i!=it->second.end(); i++)
                printf("   |----%s(%d)\n", i->first.c_str(), i->second);
        }
    }
}
