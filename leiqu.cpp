#include "leiqu.h"
#include <iostream>
using namespace std;
int random(int a){
	return rand()% a +1;
}	
void leiqu::init(int size1,int boom_number1){
    size=size1;boom_number=boom_number1; 	
	mark_count=0;
	srand((int)time(NULL));
	for (int i=0;i<=100;i++)
		for (int j=0;j<=100;j++){
			map[i][j]=0;user_in[i][j]=0;
		}	
	int count=0;
	while(count<boom_number){
		int x=random(size);
		int y=random(size);
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
	for (int i=1;i<=size;i++){
		for (int j=1;j<=size;j++){
			switch(user_in[i][j]){
				case 0: cout<<". ";
						break;
				case 1: cout<<map[i][j]<<' ';
						break;
				case 2:	cout<<"@ ";
						break;
			}	
		}
		cout<<endl;
	}	
}	

int leiqu::input(){
	char ch;
	int x,y;	
	bool tmp=false;
go3:
	cin>>ch;
	switch(ch){
		case 'M' :
			cin>>x>>y;
			user_in[x][y]=2;
			mark_count++;
			if (mark_count==boom_number){
				for (int i=1;i<=size;i++)
					for (int j=1;j<=size;j++){
						if ((map[i][j]==-1) && !(user_in[i][j]==2)) tmp=true;
					}
				if (tmp) return 2;
                if (!tmp) return 1;
			}	
			break;
					
		case 'O' :
		
		default: goto go3;
	}	
	return 0;
}	
