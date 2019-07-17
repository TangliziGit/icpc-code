#include <set>
#include <cstdio>

using namespace std;

typedef set<int,greater<int> > IntSet;

int main()
{
IntSet coll;

coll.insert(3);
coll.insert(1);
coll.insert(5);
coll.insert(4);
coll.insert(6);
coll.insert(2);

IntSet::const_iterator it = coll.begin();
for( ;it != coll.end();++it)
{
printf("元素值%d\n", *it);
}

return 0;
}
