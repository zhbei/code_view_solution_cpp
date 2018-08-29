#include <queue>
#include <string>
#include <iostream>

using namespace std;

class Pet{
private:
	string name;
public:
	Pet(string str):name(str){}
	virtual string getName(){
		return name;
	}
};
class Cat : public Pet{
public:
	Cat(string str):Pet(str){

	}
};
class Dog : public Pet
{
public:
	Dog(string str):Pet(str){

	}
};
class dogAndCatQueue
{
private:
	queue<Pet*> buff,allPet;
	bool hasDog, hasCat;
public:
	dogAndCatQueue():hasDog(false),hasCat(false){

	}

	void add(Pet *p){
		allPet.push(p);
		if(dynamic_cast<Dog*>(p) != NULL){
			hasDog = true;
		}else{
			hasCat = true;
		}
	}

	void pollAll(){
		while(!buff.empty()){
			cout << buff.front()->getName() << endl;
			buff.pop();
		}
		while(!allPet.empty()){
			cout << allPet.front()->getName() << endl;
			allPet.pop();
		}
		hasDog = false, hasCat = false;
	}
	void pollDog(){
		if(!buff.empty()){
			Dog *d = dynamic_cast<Dog*>(buff.front());
			if(d != NULL){
				while(!buff.empty()){
					cout << buff.front()->getName() << endl;
					buff.pop();
				}
			}
		}
		while(!allPet.empty()){
			Dog *d = dynamic_cast<Dog*>(allPet.front());
			if(d == NULL){
				buff.push(allPet.front());
			}else{
				cout << d->getName() << endl;
			}
			allPet.pop();
		}
		hasDog = false;
	}
	void pollCat(){
		if(!buff.empty()){
			Cat *c = dynamic_cast<Cat*>(buff.front());
			if(c != NULL){
				while(!buff.empty()){
					cout << buff.front()->getName() << endl;
					buff.pop();
				}
			}
		}
		while(!allPet.empty()){
			Cat *c = dynamic_cast<Cat*>(allPet.front());
			if(c == NULL){
				buff.push(allPet.front());
			}else{
				cout << c->getName() << endl;
			}
			allPet.pop();
		}
		hasCat = false;
	}
	bool isEmpty(){
		return buff.empty() && allPet.empty();
	}
	bool isDogEmpty(){
		return hasDog == false;
	}
	bool isCatEmpty(){
		return hasCat == false;
	}

	
};
int main(int argc, char const *argv[])
{
	dogAndCatQueue dcq;
	Pet *p1 = new Cat("cat1");
	Pet *p2 = new Dog("dog1");
	Pet *p3 = new Dog("dog2");
	Pet *p4 = new Cat("cat2");
	Pet *p5 = new Dog("dog3");
	Pet *p6 = new Cat("cat2");
	Pet *p7 = new Cat("cat4");
	Pet *p8 = new Dog("dog4");
	dcq.add(p1);
	dcq.add(p2);
	dcq.add(p3);
	dcq.add(p4);
	cout << dcq.isDogEmpty() << endl;
	cout << dcq.isCatEmpty() << endl;
	dcq.pollCat();
	cout << dcq.isCatEmpty() << endl;
	dcq.add(p5);
	dcq.pollDog();
	cout << dcq.isDogEmpty() << endl;
	dcq.add(p6);
	dcq.add(p7);
	dcq.add(p8);
	dcq.pollAll();
	cout << dcq.isEmpty() << endl;
	return 0;
}