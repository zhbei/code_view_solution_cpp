#include <iostream>
#include <vector>

using namespace std;



void pathToNums(vector<int> &path){
	//pathToDist
	int size = path.size();
	if(size == 0)return;
	int i = 0;
	while(i < size){
		int last = i,next = path[i];
		path[i] = -1;
		if(next < 0){
			++i;
			continue;
		}

		while(path[next] != next && path[next] > 0){
			int tmp = path[next];
			path[next] = last;
			last = next;
			next = path[next];
		}
	}
	//DistToNums
}
int main(int argc, char const *argv[])
{
	/* code */
	return 0;
}