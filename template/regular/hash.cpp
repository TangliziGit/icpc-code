#include <ctime>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
using namespace std;
const int hashSize=int(5e3), idxSize=int(1e5);

class Iterator{
public:
    Iterator(void);

    virtual bool operator == (const Iterator &it);
    // virtual Iterator operator ++ (void);
    // virtual Iterator operator -- (void);
    // virtual T operator * (void);
    // virtual T* operator -> (void);
private:
    // T *ptr;
};

template<class Key, class Data>
struct Node{
    Key key;
    Data data;
    Node<Key, Data> *next;

    Node(Key key, Data data):
        key(key), data(data), next(NULL) {}
    Node(Key key, Data data, Node<Key, Data> *next):
        key(key), data(data), next(next) {}
};

template<class Key, class Data>
class NodeList{
public:
    class Iterator; //:virtual ::Iterator;
    NodeList(void):_head(NULL),_size(0) {}

    bool insert(const Key &key, const Data &data){
        Node<Key, Data> *node=new Node<Key, Data>(key, data);
        node->next=_head;
        _head=node;
        _size++;
        return true;
    }
    bool remove(Node<Key, Data> *pre){
        if (pre!=NULL) return _removeNext(pre);
        return _removeHead();
    }

    unsigned long long size(void){
        return _size;
    }
    Node<Key, Data>* head(void){
        return _head;
    }

    NodeList<Key, Data>::Iterator begin(void){
        return Iterator(_head);
    }
    NodeList<Key, Data>::Iterator end(void){
        return Iterator(NULL);
    }

    class Iterator:virtual public ::Iterator{
    public:
        Iterator(Node<Key, Data> *ptr=NULL):ptr(ptr) {}

        // Iterator& operator ++ (void){
        //     if (ptr!=NULL) ptr=ptr->next;
        //     return this;
        // }
        Iterator& operator ++ (void){ // for ++d
            if (ptr!=NULL) ptr=ptr->next;
            return *this;
        }
        // Iterator& operator ++ (int){ // for d++
        //     if (ptr!=NULL) ptr=ptr->next;
        //     return *this;
        // }

        bool operator == (const Iterator &it){
            if (it.ptr==ptr) return true;
            return false;
        }
        bool operator != (const Iterator &it){
            if (it.ptr!=ptr) return true;
            return false;
        }

        Node<Key, Data>& operator * (void){
            return *ptr;
        }
        Node<Key, Data>* operator -> (void){
            return ptr;
        }
    private:
        Node<Key, Data> *ptr;
    };

private:
    Node<Key, Data> *_head;
    unsigned long long _size;

    bool _removeHead(void){
        if (_head==NULL || _size==0) return false;
        Node<Key, Data> *tmp=_head->next;
        if (tmp!=NULL){
            _head=tmp->next;
            delete tmp;
        }else _head=NULL;
        _size--;
        return true;
    }
    bool _removeNext(Node<Key, Data> *pre){
        Node<Key, Data> *node=pre->next;
        if (node!=NULL){
            pre->next=node->next;
            delete node;
        }else pre->next=NULL;
        _size--;
        return true;
    }
};

template<class Key, class Data, class HashFunc>
class HashTable{
public:
    HashTable(void):totalSize(0) {}

    Data* find(const Key &key){
        int hashKey=hash(key);
        for (Node<Key, Data> *node=list[hashKey].head(); node!=NULL; node=node->next)
            if (node->key==key) return &(node->data);
        return NULL;
    }
    bool insert(const Key &key, const Data &data){
        int hashKey=hash(key);
        bool inserted=list[hashKey].insert(key, data);
        if (inserted) totalSize++;
        return inserted;
    }
    bool remove(const Key &key){
        int hashKey=hash(key);
        Node<Key, Data> *pre=NULL;
        for (Node<Key, Data> *node=list[hashKey].head(); node!=NULL; node=node->next){
            if (node->key==key)
                return list[hashKey].remove(pre);
            pre=node;
        }return false;
    }

    unsigned long long size(void){
        return totalSize;
    }
private:
    HashFunc hash;
    unsigned long long totalSize;
    NodeList<Key, Data> list[hashSize];
};

// Keys
struct Point{
    int x, y;
    
    bool operator == (const Point &p){
        return p.x==x && p.y==y;
    }
};

// Datas
// struct Point{
//     int x, y;
// };

// HashFunctions
struct IntHashFunc{
    int operator () (const int &n){
        return (n%hashSize+hashSize)%hashSize;
    }
};

struct PointHashFunc{
    int operator () (const Point &p){
        return ((p.x*p.y)%hashSize+hashSize)%hashSize;
    }
};

struct StringHashFunc{
    int operator () (const string &str){
        int hash=0, len=str.length();
        for (int i=0; i<len; i++) hash=(hash*31+(int)str[i])%hashSize;
        return hash;
    }
};

int main(void){
    NodeList<int, int> list;
    
    for (int i=0; i<5; i++) list.insert(i, i);
    for (NodeList<int, int>::Iterator it=list.begin();it!=list.end();++it){
        cout << it->key << " " << it->data << endl;
    }

    // srand((unsigned)time(NULL));
    // HashTable<int, Point, IntHashFunc> hash;
    // for (int i=0; i<2; i++)
    //     hash.insert(i, Point{rand()%1000-499, rand()%1000-499});
    // hash.remove(0);
    // 
    // for (int i=0; i<5; i++){
    //     Point *p=hash.find(i);
    //     if (p) printf("%d: (%d, %d)\n", i, p->x, p->y);
    //     else printf("%d: none\n", i);
    // }

    // HashTable<Point, Point, PointHashFunc> hash;
    // hash.insert(Point{1, 2}, Point{3, 4});
    // Point *p=hash.find(Point{1, 2});
    // printf("(%d, %d)\n", p->x, p->y);

    // cout << hash.remove(Point{1, 4}) << endl;
    // cout << hash.find(Point{1, 4}) << endl;
    
    // string key("haha"), data("HAHA");
    // HashTable<string, string, StringHashFunc> hash;
    // hash.insert(key, data);
    // cout << *hash.find(string("haha")) << endl;

    return 0;
}
