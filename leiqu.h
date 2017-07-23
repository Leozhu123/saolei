#include<stdio.h>
#include<stdlib.h>
#include<time.h> 
class leiqu{
	int size,boom_number;
	int mark_count;
	int map[102][102],user_in[102][102];
	public:
		int mark(int x,int y);
		int open(int x,int y);
		int display();
		int input();
		void init(int size1,int boom_number1);
		void dfs(int i,int j);
};
