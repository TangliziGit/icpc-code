#include <cstdio>
#include <string>
#include <map>
using namespace std;
const int wlen=15;
// struct cmp{
// 	bool operator ()(const char *a, const char *b){
// 		// std::strcmp(a, b), but is it right?
// 		return std::strcmp(a, b);
// 	}
// };

int input(char *str){
	char ch=0, len=0;
	while (scanf("%c", &ch)==1){
		if (ch=='E') return 0;
		if (ch==' ' || ch<'a' || ch>'z') break;
		str[len++]=ch;
	}str[len]=0;
	return ch;
}

int main(void){
	// map<char *, char *, cmp> dict;
	map<string, string> dict;
	char str[wlen], nstr[wlen];

	scanf("%s", str);	//START
	while (scanf("%s", str) && str[0]!='E'){
		scanf("%s", nstr);
		dict[string(nstr)]=string(str);
	}

	char end;
	scanf("%s%*c", str);	//START, and '\n'
	while (end=input(str)){
		string s=str;
		if (dict.count(s)) printf("%s", dict[s].c_str());
		else printf("%s", str);
		printf("%c", end);
	}

	return 0;
}