#include "leiqu.h"
#include <string>
#include <iostream>
using namespace std;
int random(int a){
	return rand()% a +1;
}	
void leiqu::dfs(int i,int j){
	if ((map[i][j-1]!=-1) && (i>0) && (i<=size) && (j-1>0) && (j-1<=size) && (user_in[i][j-1]==0)){
			user_in[i][j-1]=1;
			if (map[i][j-1]==0) dfs(i,j-1);
	}		
	if ((map[i][j+1]!=-1) && (i>0) && (i<=size) && (j+1>0) && (j+1<=size) && (user_in[i][j+1]==0)){
			user_in[i][j+1]=1;
			if (map[i][j+1]==0) dfs(i,j+1);
	}
	if ((map[i-1][j]!=-1) && (i-1>0) && (i-1<=size) && (j>0) && (j<=size) && (user_in[i-1][j]==0)){
			user_in[i-1][j]=1;
			if (map[i-1][j]==0) dfs(i-1,j);
	}
	if ((map[i+1][j]!=-1) && (i+1>0) && (i+1<=size) && (j>0) && (j<=size) && (user_in[i+1][j]==0)){
			user_in[i+1][j]=1;
			if (map[i+1][j]==0) dfs(i+1,j);
	}
	if ((map[i-1][j-1]!=-1) && (i-1>0) && (i-1<=size) && (j-1>0) && (j-1<=size) && (user_in[i-1][j-1]==0)){
			user_in[i-1][j-1]=1;
			if (map[i-1][j-1]==0) dfs(i-1,j-1);
	}
	if ((map[i+1][j-1]!=-1) && (i+1>0) && (i+1<=size) && (j-1>0) && (j-1<=size) && (user_in[i+1][j-1]==0)){
			user_in[i+1][j-1]=1;
			if (map[i+1][j-1]==0) dfs(i+1,j-1);
	}
	if ((map[i-1][j+1]!=-1) && (i-1>0) && (i-1<=size) && (j+1>0) && (j+1<=size) && (user_in[i-1][j+1]==0)){
			user_in[i-1][j+1]=1;
			if (map[i-1][j+1]==0) dfs(i-1,j+1);
	}
	if ((map[i+1][j+1]!=-1) && (i+1>0) && (i+1<=size) && (j+1>0) && (j+1<=size) && (user_in[i+1][j+1]==0)){
			user_in[i+1][j+1]=1;
			if (map[i+1][j+1]==0) dfs(i+1,j+1);
	}
}	
void leiqu::init(int size1,int bomb_number1){
    size=size1;bomb_number=bomb_number1; 	
	mark_count=0;
	srand((int)time(NULL));
	for (int i=0;i<=100;i++)
		for (int j=0;j<=100;j++){
			map[i][j]=0;user_in[i][j]=0;
		}	
	int count=0;
	while(count<bomb_number){
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
	for (int i=0;i<=size;i++){
		for (int j=0;j<=size;j++){
			if (i==0 && j!=0 ) {
				cout<<j<<' ';
				continue;
			}	
			if (j==0) {
				cout<<(char)(i+64)<<' ';
				continue;
			}	
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
	char ch,ch1;
	int x,y;	
	bool tmp=false;
go3:
	cin>>ch;
	string tmps;
	switch(ch){
		case 'M' :
			cin>>ch1;
			cin>>y;
			x=ch1-64;
			if (!(x>0) && (x<=size) && (y>0) && (y<=size)){
				getline(cin,tmps);
				cout<<"input again";
				goto go3;
			}	
			user_in[x][y]=2;
			mark_count++;
			if (mark_count==bomb_number){
				for (int i=1;i<=size;i++)
					for (int j=1;j<=size;j++){
						if ((map[i][j]==-1) && !(user_in[i][j]==2)) tmp=true;
					}
				if (tmp) return 2;
                if (!tmp) return 1;
			}	
			break;
					
		case 'O' :
			cin>>ch1;
			cin>>y;
			x=ch1-64;
			if (!(x>0) && (x<=size) && (y>0) && (y<=size)){
			    getline(cin,tmps);
				cout<<"input again";
				goto go3;
			}
			if (map[x][y]==-1) return 2;
			user_in[x][y]=1;
			dfs(x,y);
			break;
		case 'E' : 
			return 3;
			break;
		default: 
		    getline(cin,tmps);
			cout<<"input again"<<endl;
			goto go3;
	}	
	return 0;
}	
