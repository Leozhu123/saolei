#include<stdio.h>
#include<stdlib.h>
#include<time.h> 
class leiqu{
	int size,boom_number;
	int map[102][102],user_in[102][102];
	public:
		leiqu(int size1,int boom_number1);
		int mark(int x,int y);
		int open(int x,int y);
		int display();
		int input();
};