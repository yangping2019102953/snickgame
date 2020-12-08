#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<windows.h>
#define M 100
//定义全局变量
//设置蛇
int snick[M][2];
int body_x;
int body_y;
int len;
//蛇身长度
//记录每次蛇头动之前的位置
int temp_x;
int temp_y;
//控制方向
char der='r';
//豆子
int beans_x;
int beans_y;

void gotoxy(int x, int y) {  //光标移动到{x,y}
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD pos ;
	pos.X=x;
	pos.Y=y;
    SetConsoleCursorPosition(handle, pos);
}
void HideCursor(){
	CONSOLE_CURSOR_INFO cursor_info={1,0}; //第二值为0表示隐藏光标
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE),&cursor_info);
}
void inst(){
	
	HideCursor();
	//边框
    body_x =20;
	body_y =20;
	//蛇头
	snick[0][0]=body_x/2;
	snick[0][1]=body_y/2;
	temp_x=snick[0][0];
	len=2;//蛇尾长度
	temp_y=snick[0][1];
	//第一个蛇尾
	snick[1][0]=snick[0][0]-1;
	snick[1][1]=snick[0][1];  
	snick[2][0]=snick[1][0]-1;
	snick[2][1]=snick[1][1]; 
	der='r';
	beans_x=rand()%(body_x-1);
    beans_y=rand()%(body_y-1);
}
void show(){
gotoxy(0,0);
	int i=0;
	int j=0;
	int k=1;
	for(i=0;i<body_y;i++){//纵坐标
		for(j=0;j<body_x;j++)//横坐标
		{
		
			if(der=='r'){
		    	for(k=len+1;k>=1;k--){              
			       if((snick[k][0]==j)&&(snick[k][1]==i))
				   {
                     printf("*");
					 j++;
				   }
				}
			}
		   else	if(der=='l')
			{
			    for(k=1;k<len+1;k++){              
			        if((snick[k][0]==j)&&(snick[k][1]==i))
					{
                     printf("*");
					 j++;
					}
				}
			}
		   else 
		   {
			   for(k=1;k<len+1;k++){              
			        if((snick[k][0]==j)&&(snick[k][1]==i))
					{
                     printf("*");
					 j++;
					}
				}
		   }

			if(i==0||j==0)
                 printf("#");
			else if((i==body_y-1)||(j==body_x-1))
                 printf("#");
			else if((snick[0][0]==j)&&(snick[0][1]==i))
			{
                 printf("@");
			}
			else if((beans_x==j)&&(beans_y==i))
			{
                 printf("$");
			}
			else
		         printf(" ");
		}
        printf("\n");
	}
	
}
void move(){
	Sleep(500);
	temp_x=snick[0][0]; 
	temp_y=snick[0][1];
	if(der=='u')
	{
		snick[0][1]--;
	}
	else if(der=='d')
	{
		snick[0][1]++;
	}
	else if(der=='l')
	{
		snick[0][0]--;
	}
	else if(der=='r')
	{
		snick[0][0]++;
	}
	int k=0;
	//把蛇的尾巴向前移动，即把蛇身前一个值赋值给后面一个值
	//把前面的蛇身值赋值给后面的蛇身值
	for(k=len;k>1;k--)
	{
		snick[k][0]=snick[k-1][0];
		snick[k][1]=snick[k-1][1];
	}
	//把蛇头位置赋值给第一个蛇身
    snick[1][0]=temp_x;
	snick[1][1]=temp_y;

}
void userinput(){
	char input;
	if(kbhit()!=0)
	{    
		input=getch();
		temp_x=snick[0][0]; 
		temp_y=snick[0][1];
		if(input=='w')
		{
			snick[0][1]=snick[0][1]-1;
			der='u';
		}
		//snick[0][1]=body_y/2-2;
		if(input=='s')
		{
			snick[0][1]=snick[0][1]+1;
			der='d';
		}
		if(input=='a')
		{
			snick[0][0]=snick[0][0]-1;
			der='l';
		}
		if(input=='d')
		{
			snick[0][0]=snick[0][0]+1;
			der='r';
		}
        

	}

}
 void showbeans(){
    if((snick[0][0]==beans_x)&&(snick[0][1]==beans_y))
	{
		 len++;
         beans_x=rand()%(body_x-1);
         beans_y=rand()%(body_y-1);
	}
	
}


int main(){
	inst();
	while(1){
		system("cls");
    	show();
		userinput();
		move();
		showbeans();

	}
    	return 0;
}