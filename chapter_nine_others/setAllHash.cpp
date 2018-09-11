#include <iostream>
#include <unordered_map>

using namespace std;

template <class key,class val>
class MyHash{
private:
	unsigned long long cur;
	pair<unsigned long long,val> setAllVal;
	unordered_map<key,pair<unsigned long long,val>> hash;
public:
	MyHash():cur(0),setAllVal(0,-1){}
	void put(key k,val v){
		hash[k] = make_pair(++cur,v);
	}
	val get(key k){
		if(hash.find(k) != hash.end()){
			if(hash[k].first < setAllVal.first){
				return setAllVal.second;
			}else{
				return hash[k].second;
			}
		}else{
			put(k,0);
			return 0;
		}
	}
	void setAll(val v){
		setAllVal = make_pair(++cur,v);
	}
	bool hasKey(key k){
		return hash.find(k) != hash.end();
	}
};

int main(int argc, char const *argv[])
{
	MyHash<int,int> hash;
	hash.put(1,1);
	hash.put(2,2);
	hash.put(3,3);
	hash.put(4,4);
	hash.put(4,5);
	hash.put(5,6);
	for(int i = 1; i <= 5; ++i){
		cout << hash.get(i) << endl;
	}
	hash.setAll(-1);
	hash.put(6,7);
	hash.put(7,8);
	hash.put(8,9);
	for(int i = 1; i <= 8; ++i){
		cout << hash.get(i) << endl;
	}
	return 0;
}