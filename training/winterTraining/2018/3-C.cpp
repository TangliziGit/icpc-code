#include <cstdio>
#include <string>
#include <map>
using namespace std;

int main(void){
    char line[1024];
    map<string, string> dict;

    while (fgets(line, sizeof(line), stdin) && line[0]!='\n'){
        string str(line);
        int ptr=str.find(" ");
        dict[str.substr(ptr+1, str.length()-ptr-2)]=str.substr(0, ptr);
    }

    while (scanf("%s", line)==1){
        string str(line);
        if (!dict.count(str)) printf("eh\n");
        else printf("%s\n", dict[str].c_str());
    }

    return 0;
}
