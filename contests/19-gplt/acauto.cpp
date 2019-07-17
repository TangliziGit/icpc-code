#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <set>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

const int maxn=200+20, maxw=35;//, maxl=2000000+20;
const int ACSize=maxn*maxw, maxitem=128;

struct ACauto{
    int next[ACSize][maxitem], fail[ACSize], cnt[ACSize];
    // node.next[maxitem], node.fail, node.val;
    int root, total;
    int newnode(void){
        for(int pos=0; pos<maxitem; pos++)
            next[total][pos]=-1;
        cnt[total]=0;    // 词尾节点的初始化，不是词尾就赋0或-1
        return total++;
    }
    void init(void){
        total=0;
        root=newnode();
    }
    int getPos(char ch){
        return ch;
    }

    void insert(string buf, int idx){
        int now=root, len=buf.length();
        for(int i=0; i<len; i++){
            int pos=getPos(buf[i]);
            if(next[now][pos]==-1)
                next[now][pos]=newnode();
            now=next[now][pos];
        }
        cnt[now]=idx; // 这里维护词尾节点的值
    }

    void build(void){    // 一般不会改GetFail算法
        queue<int> que;
        fail[root]=root;
        for(int i=0; i<maxitem; i++)
            if(next[root][i]==-1)
                next[root][i]=root;
            else{
                fail[next[root][i]]=root;
                que.push(next[root][i]);
            }

        while(!que.empty()){
            int now=que.front(); que.pop();
            for(int pos=0; pos<maxitem; pos++)
                if(next[now][pos]==-1)
                    next[now][pos]=next[fail[now]][pos];
                else{
                    fail[next[now][pos]]=next[fail[now]][pos];
                    que.push(next[now][pos]);
                }
        }
    }

    void query(string buf, int plen, int idx[]){
        int now=root, len=buf.length();

        for(int i=0; i<len; i++){
            int pos=getPos(buf[i]);
            now=next[now][pos];
            for (int tmp=now; tmp!=root; tmp=fail[tmp]) if (cnt[tmp]){
                idx[i-plen+1]=cnt[tmp];
            }
        }
    }
};

class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        int idx[s.length()], size[s.length()];
        int slen=s.length(), wlen=words[0].length(), wn=words.size();
        memset(idx, 0, sizeof(idx));

        multiset<string> mset;
        ACauto machine;
        machine.init();
        for (int i=0; i<words.size(); i++){
            machine.insert(words[i], i+1);
            mset.insert(words[i]);
            size[i+1]=mset.count(words[i]);
        }
        machine.build();
        machine.query(s, wlen, idx);

        for (int i=0; i<slen; i++)
            printf("%d-%d, ", idx[i], i);
        printf("%d\n", wlen);

        vector<int> ans;
        multiset<int> vis;
        int pre=0, pos=0;
        for (int i=0; i<wlen; i++){
            vis.clear();
            pre=pos=i;
            for (; pos<slen; pos+=wlen) if (idx[pos]){
                while (vis.count(idx[pos])>=size[idx[pos]]){
                    vis.erase(vis.lower_bound(idx[pre])); pre+=wlen;
                    while (!idx[pre]) pre+=wlen;
                }
                vis.insert(idx[pos]);
                while (!idx[pre]) pre+=wlen;
                if (vis.size()==wn) ans.push_back(pre);
            }else{
                while (pre<pos){
                    vis.erase(vis.lower_bound(idx[pre])); pre+=wlen;
                    while (!idx[pre]) pre+=wlen;
                }
            }
        }return ans;
    }
};

int main(void){
    Solution solution;
    vector<string> words;
    string s, tmp;

    cin >> s;
    while (cin >> tmp){
        words.push_back(tmp);
    }

    vector<int> ans=solution.findSubstring(s, words);
    for (int i=0; i<ans.size(); i++)
        printf("%d, ", ans[i]);
    printf("\n");

    return 0;
}
