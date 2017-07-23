#include <iostream>
#include "leiqu.h"
using namespace std;
leiqu lei;
int GameLoop();
int main(){
	cout<<"Welcome to saolei"<<endl;
	cout<<"input a number to set size"<<endl;
	int size;
go1:
	cin>>size;
	if ((size>100) || (size<1)) {
		cout<<"input an another number"<<endl;
		goto go1;
	}   
	cout<<"input a number to set the number of boom"<<endl;
	int boom_number;
go2:
	cin>>boom_number;
	if ((boom_number>size*size) || (boom_number<1)) {
		cout<<"input an another number"<<endl;
		goto go2;
	}
	lei.init(size,boom_number);
	lei.display();
	while(GameLoop()==0);
	return 0;
}
int GameLoop(){
	int t=lei.input();
	lei.display();
	if (t==1) { cout<<"You Win!"; return 1;}
	if (t==2) { cout<<"Game over!"; return 2;}
	if (t==3) {cout<<"exit"; return 3;}
	return 0;
}	
