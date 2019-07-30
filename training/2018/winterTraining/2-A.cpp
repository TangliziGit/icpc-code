#include <iostream>
#include <string>
#include <map>
using namespace std;

int main(void){
	int n;

	while (cin >> n && n){
		map<string, int> idx;
		int balls[100]={0}, m=0;
		string str, ans;
		for (int i=0; i<n; i++){
			cin >> str;
			if (!idx.count(str)) idx[str]=idx.size();
			balls[idx[str]]++;
		}

		for (map<string, int>::iterator it=idx.begin(); it!=idx.end(); it++)
			if (balls[it->second]>m) {
				m=balls[it->second]; 
				ans=it->first;
			}
		cout << ans << endl;
	}

	return 0;
}