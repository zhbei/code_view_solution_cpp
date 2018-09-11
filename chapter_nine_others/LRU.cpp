#include <unordered_map>
#include <list>
#include <iostream>

using namespace std;


class LRUCache {
private:
	int capacity;
	int cur;
	list<pair<int,int>> cache;
	unordered_map<int,list<pair<int,int>>::iterator> idx;  
    void updateToHead(list<pair<int,int>>::iterator i){
        pair<int,int> tmp = *i;
        cache.erase(i);
        cache.insert(cache.begin(),tmp);
        idx[tmp.first] = cache.begin();
    }
public:
	LRUCache(int k):capacity(k),cur(0){};
	void put(int k, int v){
        if(idx.find(k) != idx.end()){
            idx[k]->second = v;
            updateToHead(idx[k]);
            return;
        }
		if(capacity > cur){
			cache.insert(cache.begin(),make_pair(k,v));
			idx[k] = cache.begin();
			++cur;
		}else{
			list<pair<int,int>>::iterator del = --cache.end();
            cache.erase(del);
			idx.erase(del->first);
			cache.insert(cache.begin(),make_pair(k,v));
			idx[k] = cache.begin();
		}
	}
	int get(int k){
		if(idx.find(k) == idx.end()){
			return -1;
		}else{
            updateToHead(idx[k]);
			return idx[k]->second;
		}
	}
};

