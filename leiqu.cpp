#include "leiqu.h"
#include <iostream>
using namespace std;
int random(int a){
	return rand()% a +1;
}	
void leiqu::init(int size1,int boom_number1){
    size=size1;boom_number=boom_number1; 	
	srand((int)time(NULL));
	for (int i=0;i<=100;i++)
		for (int j=0;j<=100;j++)
			map[i][j]=0;
	int count=0;
	while(count<boom_number){
		int x=random(size);
		int y=random(size);
		cout<<x<<' '<<y<<endl;
		if (map[x][y]==0){
			map[x][y]=-1;
			count++;
		}	
	}
	for (int i=1;i<=size;i++)
		for (int j=1;j<=size;j++){
			if (map[i][j] == -1) continue;
			if (map[i][j-1]==-1) map[i][j]++;
			if (map[i][j+1]==-1) map[i][j]++;
			if (map[i-1][j]==-1) map[i][j]++;
			if (map[i+1][j]==-1) map[i][j]++;
			if (map[i-1][j-1]==-1) map[i][j]++;
			if (map[i+1][j-1]==-1) map[i][j]++;
			if (map[i-1][j+1]==-1) map[i][j]++;
			if (map[i+1][j+1]==-1) map[i][j]++;
		}	
}	

int leiqu::display(){
}	

int leiqu::input(){
}	
