#include <stdio.h>
#include <stdlib.h>
#include<windows.h>

char a[]={'1','2','3','4','5','6','7','8','9'};
int ca[9];
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
void gotoxy(int x,int y)
{
	COORD pos;
	pos.X=x;
	pos.Y=y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),pos);
}
void head(void)
{
	gotoxy(0,0);
	printf("______________________________________________________________________________________________________________________");
	gotoxy(48,2);
	printf("T I C     T A C     T O E");
	gotoxy(69,4);
	printf("DEVELOPED BY- Vaibhav Haswani");
	gotoxy(0,5);
	printf("_______________________________________________________________________________________________________________________");
	gotoxy(3,7);
	printf("PLAYER 1 SYMBOL- X");
	gotoxy(3,9);
	printf("PLAYER 2 SYMBOL- O");
	
}
void load(void)
{
	int i,j;
	gotoxy(48,12);
	printf("L O A D I N G . . .");
 for(i=1;i<=100;i++)
	 {
	 for(j=1;j<=20000000;j++);
	 for(j=1;j<=20000000;j++);
	 gotoxy(10+i,14);
	 printf("%c",177);
	 gotoxy(70,12);
	 printf("(%d%%)",i);
    }
}
void screen()
{
    
	gotoxy(56,12);
	printf("|         |");
	gotoxy(56,13);
	printf("|         |");
    gotoxy(50,14);
	printf("  %c   |    %c    |   %c  ",a[0],a[1],a[2]);
	gotoxy(56,15);
	printf("|         |");
	gotoxy(46,16);
	printf("_______________________________");
	  
	gotoxy(56,17);
	printf("|         |");
	gotoxy(56,18);
	printf("|         |");
    gotoxy(50,19);
	printf("  %c   |    %c    |   %c  ",a[3],a[4],a[5]);
	gotoxy(56,20);
	printf("|         |");
	gotoxy(46,21);
	printf("_______________________________");
	gotoxy(56,22);
	printf("|         |");
	 gotoxy(50,23);
	printf("  %c   |    %c    |   %c  ",a[6],a[7],a[8]);
	gotoxy(56,24);
	printf("|         |");
   
	gotoxy(56,25);
	printf("|         |");


}
void replacer(int,int);
int check(int opt);
void result(void);
int reschk(void);




int main(void) {
	
	system("color f5");
	int i;
	int opt;
	char ch;
	
	do{
	load();
	system("cls");
	head();
	screen();
	
	
	for(i=1;i<=9;i++)
	{
		
		if(i%2==0)
		{
			re:
			gotoxy(48,30);
			printf("                                 ");
			gotoxy(48,30);
			printf("PLAYER 2: Enter Position-");
			scanf("%d",&opt);
			if(opt>0&&opt<10)
			{
				int k=check(opt);
				if(k==0)
				{
				ca[i]=opt;
				replacer(opt,i);
				screen();
			    }
			    else{
			    	gotoxy(48,32);
			    	printf("WARNING:Position Already Taken..\n");
			    	goto re;
				}
			}
			else
			{
			gotoxy(48,32);
			printf("WARNING:Enter valid choice..\n");
			goto re;
		    }
		}
		else
		{
			re1:
				gotoxy(48,28);
		     	printf("                                 ");
				gotoxy(48,28);
				printf("PLAYER 1: Enter Position-");
				scanf("%d",&opt);
				if(opt>0&&opt<10)
				{
				int k=check(opt);
				if(k==0)
				{
				ca[i]=opt;
				replacer(opt,i);
				screen();
			    }
			    else{
			    	gotoxy(48,32);
			    	printf("WARNING:Position Already Taken..\n");
			    	goto re1;
				}
				}
				else
				{
					gotoxy(48,32);
					printf("WARNING:Enter valid choice..\n");
					goto re1;
				}
		}
		int res=reschk();
		if(res==1)
		break;
		
	}
	
	result();
	system("pause");
	system("cls");
	int i;
	int n=49;
	for(i=0;i<9;i++)
	{
	a[i]=n;
	n++;
    }
    for(i=0;i<9;i++)
    ca[i]=0;
	gotoxy(48,4);
	printf("PLAY AGAIN? (y/n)");
	ch=getch();
	system("cls");
  }while(ch=='y');
    printf("BYE BYE!"); 
    exit(1);
	return 0;
}
void replacer(int opt,int pl){
	opt--;
	if(pl%2==0)
	{
		a[opt]='O';
	}
	else
	{
		a[opt]='X';
	}
	
	
}
int check(int opt){
	int i,j=0;
	for(i=0;i<9;i++)
	{
		if(ca[i]==opt){
			j=1;
			break;
		}
	}
	if(j==1)
	return 1;
	else return 0;
}
void result(void)
{
	if(a[0]=='X'&&a[1]=='X'&&a[2]=='X' || a[2]=='X'&&a[5]=='X'&&a[8]=='X' || a[6]=='X'&&a[7]=='X'&&a[8]=='X' || a[0]=='X'&&a[3]=='X'&&a[6]=='X' || a[1]=='X'&&a[4]=='X'&&a[7]=='X' || a[0]=='X'&&a[8]=='X'&&a[4]=='X' ||a[4]=='X'&&a[2]=='X'&&a[6]=='X')
	{
		gotoxy(48,36);
		printf("<<< CONGO! PLAYER 1 WINS >>>\n");
	}
	else if(a[0]=='O'&&a[1]=='O'&&a[2]=='O' || a[2]=='O'&&a[5]=='O'&&a[8]=='O' || a[6]=='O'&&a[7]=='O'&&a[8]=='O' || a[0]=='O'&&a[3]=='O'&&a[6]=='O' || a[1]=='O'&&a[4]=='O'&&a[7]=='O' || a[0]=='O'&&a[8]=='O'&&a[4]=='O' ||a[4]=='O'&&a[2]=='O'&&a[6]=='O')
	{
		gotoxy(48,36);
		printf("<<< CONGO! PLAYER 2 WINS >>>\n");
	}
	else
	{
	gotoxy(44,36);
	printf("NO ONE WINS!! BETTER LUCK NEXT TIME!\n");
	}
}
int reschk(void)
{
	if(a[0]=='X'&&a[1]=='X'&&a[2]=='X' || a[2]=='X'&&a[5]=='X'&&a[8]=='X' || a[6]=='X'&&a[7]=='X'&&a[8]=='X' || a[0]=='X'&&a[3]=='X'&&a[6]=='X' || a[1]=='X'&&a[4]=='X'&&a[7]=='X' || a[0]=='X'&&a[8]=='X'&&a[4]=='X' ||a[4]=='X'&&a[2]=='X'&&a[6]=='X')
	return 1;
	else if(a[0]=='O'&&a[1]=='O'&&a[2]=='O' || a[2]=='O'&&a[5]=='O'&&a[8]=='O' || a[6]=='O'&&a[7]=='O'&&a[8]=='O' || a[0]=='O'&&a[3]=='O'&&a[6]=='O' || a[1]=='O'&&a[4]=='O'&&a[7]=='O' || a[0]=='O'&&a[8]=='O'&&a[4]=='O' ||a[4]=='O'&&a[2]=='O'&&a[6]=='O')
	return 1;
	else
	return 0;
	
}
