#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<windows.h>
#define M 100
//����ȫ�ֱ���
//������
int snick[M][2];
int body_x;
int body_y;
int len;
//������
//��¼ÿ����ͷ��֮ǰ��λ��
int temp_x;
int temp_y;
//���Ʒ���
char der='r';
//����
int beans_x;
int beans_y;

void gotoxy(int x, int y) {  //����ƶ���{x,y}
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD pos ;
	pos.X=x;
	pos.Y=y;
    SetConsoleCursorPosition(handle, pos);
}
void HideCursor(){
	CONSOLE_CURSOR_INFO cursor_info={1,0}; //�ڶ�ֵΪ0��ʾ���ع��
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE),&cursor_info);
}
void inst(){
	
	HideCursor();
	//�߿�
    body_x =20;
	body_y =20;
	//��ͷ
	snick[0][0]=body_x/2;
	snick[0][1]=body_y/2;
	temp_x=snick[0][0];
	len=2;//��β����
	temp_y=snick[0][1];
	//��һ����β
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
	for(i=0;i<body_y;i++){//������
		for(j=0;j<body_x;j++)//������
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
	//���ߵ�β����ǰ�ƶ�����������ǰһ��ֵ��ֵ������һ��ֵ
	//��ǰ�������ֵ��ֵ�����������ֵ
	for(k=len;k>1;k--)
	{
		snick[k][0]=snick[k-1][0];
		snick[k][1]=snick[k-1][1];
	}
	//����ͷλ�ø�ֵ����һ������
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