#include <unordered_map>
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <vector>

using namespace std;


template <class TK>
class RandomPool
{
private:
	vector<int> val;
	int size;
	unordered_map<TK,int> idx;
public:
	RandomPool():size(0){
		srand(time(NULL));
	}
	void insert(TK key){
		if(idx.find(key) == idx.end()){
			idx.insert(make_pair(key,size));
			val.push_back(key);
			++size;
		}
	}
	void deleteKey(TK key){
		if(idx.find(key) != idx.end()){
			int po = idx[key];
			idx.erase(key);
			idx[val[size-1]] = po;
			val[po] = val[size-1];
			val.erase(--val.end());
			--size;
		}
	}
	TK getRandom(){
		int n = rand()%size;
		return val[n];
	}
};


int main(int argc, char const *argv[])
{
	RandomPool<int> rp;
	rp.insert(1);
	rp.insert(2);
	rp.insert(3);
	rp.insert(4);
	rp.insert(1);
	rp.deleteKey(2);
	rp.insert(4);
	rp.insert(5);
	rp.insert(6);
	rp.deleteKey(2);
	rp.deleteKey(6);
	rp.insert(7);
	rp.insert(8);
	rp.insert(18);
	rp.insert(28);
	rp.insert(38);
	rp.insert(48);
	vector<int> tmp(100,0);
	for(int i = 0; i < 1000000; ++i){
		++tmp[rp.getRandom()];
	}
	for(int i = 0; i < 100; ++i){
		if(tmp[i] != 0)
			cout << double(tmp[i]) / 1000000 << endl;
	}
	return 0;
}