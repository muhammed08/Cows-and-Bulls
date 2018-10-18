
#include <conio.h>
#include <stdio.h>
#include<stdlib.h>
#include<process.h>
#include<string.h>
#include<windows.h>
#include<time.h>
int cop;
int rant(int limit)
{
	srand(time(0));
	long int n= rand(),p;
	p=n%limit;
	return p;

}
struct value
{
	int val,co,bu;
};
typedef struct value value;
int scoreu=0,scorec=0,win=0;
struct user
{
	char name[100];
	int point;
};
typedef struct user user;
user newuser,olduser;
void clr()
{
//clrscr();
	system("cls");
printf("\n\t\t\t\t  COWS AND BULLS");
printf("\n\t\t\t\t  ==============  ");
	return;
}

int cond_check(int i)
{
	int n1,n2,n3,n4;
	n1=i%10;
	if(n1==0)
		return 0;
	i/=10;
	n2=i%10;
	if(n2==0)
		return 0;
	i/=10;
	n3=i%10;
	if(n3==0)
		return 0;
	i/=10;
	n4=i%10;
	if(n4==0)
		return 0;
	if((n1==n2 || n1==n3 || n1==n4 || n2==n3 || n2==n4 ||n3==n4) )
		return 0;
	else
		return 1;

}
int findb(int v1,int v2)
{
	int n1[4],n2[4],b=0;
	int i;
	for(i=0;i<4;i++)
	{
		n1[i]=v1%10;
		v1/=10;
		n2[i]=v2%10;
		v2/=10;
	}
	for(i=0;i<4;i++)
	{
		if(n1[i]==n2[i])
			b++;

	}
	return b;
}
int findc(int v1,int v2)
{
	int n1[4],n2[4],c=0;
	int i,j;
	for(i=0;i<4;i++)
	{
		n1[i]=v1%10;
		v1/=10;
		n2[i]=v2%10;
		v2/=10;
	}
	for(i=0;i<4;i++)
	{
		for( j=0;j<4;j++)

		{
			if(n1[i]==n2[j] && i!=j)
				c++;
		}

	}
	return c;
}

int intersect(int arr[],int key,int l)
{
	int i;
	for( i=0;i<l;i++)
		if(arr[i]==key)
			return 0;

	return 1;
}
int no_of_same(int n1[],int n2[],int total)
{
	int cnt=0,i,j;
	for( i=0;i<4;i++)
	{
		for(j=0;j<4;j++)
		{
			if(n1[i]==n2[j])
				cnt++;

		}
	}
	if(cnt>=total)
		return 1;
	else
		return 0;
}
int same_pos(int n1[],int n2[],int total)
{
	int cnt=0,i;
	for( i=0;i<4;i++)
	{
		if(n1[i]==n2[i])
			cnt++;


	}
	if(cnt>=total)
		return 1;
	else
		return 0;



}
int find_best(int no,value v[],int count)
{
	int n1[4],n2[4],v1=no,v2,i,j,total;

	for( i=0;i<4;i++)
	{
		n1[i]=v1%10;
		v1/=10;
	}

	for( i=0;i<count;i++)
	{
		for(j=0,v2=v[i].val;j<4;j++)
		{
			n2[j]=v2%10;
			v2/=10;
		}
		total=v[i].bu + v[i].co;
		if(no_of_same(n1,n2,total)==0)
			return 0;
		else if(same_pos(n1,n2,v[i].bu)==0)
			return 0;

	}
	return 1;
}

void show1(int i)
	{
		clr();
		if(i==1)
		{
			printf("\n\t->START GAME");
			printf("\n\t   HIGH SCORE");
			printf("\n\t   CREDITS AND CONTACT");
			printf("\n\t   RULES");
			printf("\n\t   SETTINGS");
			printf("\n\t   EXIT");

			printf("\n\n\n\n\n\n\n\n\n\n\n\n\t   use arrow keys and enter");
		}
		else if(i==2)
		{
			printf("\n\t   START GAME");
			printf("\n\t->HIGH SCORE");
			printf("\n\t   CREDITS AND CONTACT");
			printf("\n\t   RULES");
			printf("\n\t   SETTINGS");
			printf("\n\t   EXIT");

			printf("\n\n\n\n\n\n\n\n\n\n\n\n\t   use arrow keys and enter");
		}
		else if(i==3)
		{
			printf("\n\t   START GAME");
			printf("\n\t   HIGH SCORE");
			printf("\n\t->CREDITS AND CONTACT");
			printf("\n\t   RULES");
			printf("\n\t   SETTINGS");
			printf("\n\t   EXIT");

			printf("\n\n\n\n\n\n\n\n\n\n\n\n\t   use arrow keys and enter");

		}
		else if(i==4)
		{
			printf("\n\t   START GAME");
			printf("\n\t   HIGH SCORE");
			printf("\n\t   CREDITS AND CONTACT");
			printf("\n\t->RULES");
			printf("\n\t   SETTINGS");
			printf("\n\t   EXIT");

			printf("\n\n\n\n\n\n\n\n\n\n\n\n\t   use arrow keys and enter");
		}
		else if(i==5)
		{
			printf("\n\t   START GAME");
			printf("\n\t   HIGH SCORE");
			printf("\n\t   CREDITS AND CONTACT");
			printf("\n\t   RULES");
			printf("\n\t->SETTINGS");
			printf("\n\t   EXIT");

			printf("\n\n\n\n\n\n\n\n\n\n\n\n\t   use arrow keys and enter");

		}
		else
		{
			printf("\n\t   START GAME");
			printf("\n\t   HIGH SCORE");
			printf("\n\t   CREDITS AND CONTACT");
			printf("\n\t   RULES");
			printf("\n\t   SETTINGS");
			printf("\n\t->EXIT");

			printf("\n\n\n\n\n\n\n\n\n\n\n\n\t   use arrow keys and enter");

		}
	}

int mainmenu()
{


	int i=1,k;
	char ch;
	view6:
	clr();
	show1(i);
	ch=getch();

	if(ch==13)
	{
		return i;
	}
	else
	{

		ch=getch();
	switch(ch) { // the real value
		case 'H':if(i==1)
			{
				i=6;
				goto view6;
			}
			else
			{
				i--;
				goto view6;
			}
		break;
		case 'P':if(i==6)
			{
				i=1;
				goto view6;
			}
			else
			{
				i++;
				goto view6;
			}
		break;
		default:goto view6;

		}
	}

}
int select_plyer()
{

	int g=1;
	char ch;
	view3:
	clr();
	if(g==1)
	{	printf("\n\tDo you want to start first..?");
		printf("\n\n\t\t->YES");
		printf("\n\t\t   NO");
	}
	if(g==2)
	{
		printf("\n\tDo you want to start first..?");
		printf("\n\n\t\t   YES");
		printf("\n\t\t->NO");

	}

		ch=getch();
		if(ch==13 && g==1)
			return 1;
		if(ch==13 && g==2)
			return 0;
		else
		{

			getch();
			if(g==1)
				g=2;
			else if(g==2)
				g=1;
			goto view3;
		}

}

void start_game()
{
	int v[3024],no;
	int X[3024],Y[3024],temp[3024];
	int i,j,k,m,q;
	int cow,bul;
	int start=1,num,len=0,r,z,count;
	char nameuser[100];
	value va[20];
	win=0;
	scorec=0;
	scoreu=0;
	entername:
	clr();
	printf("\n\n\n\n\tENTER THE PLAYER NAME  :");
	gets(nameuser);
	if(nameuser[0]=='\0')
		goto entername;
	int s=nameuser[0];
	strcpy(newuser.name,nameuser);
	z=select_plyer();
	count=0;
	//clrscr();

	for(i=1234,j=0;i<9877;i++)
	{
		if(cond_check(i)==1)
		{
			v[j]=i;
			j++;
		}


	}
	if(z==1)
	{
		r=rant(3024);
		num=v[r];
		clr();
		goto human_guess;
	}
	else
	{
		r=rant(3024);
		num=v[r];
		start=1;
		clr();
		goto cmp_guess;
	}
	cmp_guess:
	if(start==1)
	{
		r=rant(3024);
		no=v[r];
		printf("\n\n\tCOMPUTER\'S GUESS  :%d",no);
		printf("\n\n\tENTER THE B  :");
		scanf("%d",&bul);
		if(bul==4)
		{
			clr();
			printf("\n\n\n\n\n\t\t\tCOMPUTER WINS...with a score  :%d\n",scoreu);
			printf("\n\n\t\t\tCOMPUTER\'S NUMBER IS %d",num);
			printf("\n\n\n\n\tPRESS ANY KEY TO RETURN TO MAIN MENU....");
			return ;
		}
		printf("\n\tENTER THE C  :");
		scanf("%d",&cow);
		va[count].val=no;
		va[count].bu=bul;
		va[count].co=cow;
		count++;
		
		scoreu++;
		len=0;
		for(j=0;j<3024;j++)
		{
			if(v[j]==no)
				continue;
			if((findc(no,v[j])==cow) && (findb(no,v[j])==bul))
			{

				X[len]=v[j];
				len++;
			}
		}
		start=0;
		goto human_guess;
	}
	else
	{
		r=rant(len);
		no=X[r];
		printf("\n\n\tCOMPUTER\'S GUESS  :%d",no);
		printf("\n\n\tENTER THE B  :");
		scanf("%d",&bul);
		if(bul==4)
		{
			clr();
			printf("\n\n\n\n\n\t\t\tCOMPUTER WINS...with a score  :%d\n",scorec);
			printf("\n\n\t\t\tCOMPUTER\'S NUMBER IS %d",num);
			printf("\n\n\n\n\tPRESS ANY KEY TO RETURN TO MAIN MENU....");
			return ;
		}
		printf("\n\tENTER THE C  :");
		scanf("%d",&cow);
		scoreu++;
		va[count].val=no;
		va[count].bu=bul;
		va[count].co=cow;
		count++;
		i=0;
		for(j=0;j<3024;j++)
		{
			if(v[j]==no)
				continue;
			if((findc(no,v[j])==cow) && (findb(no,v[j])==bul) && find_best(v[j],va,count))
			{
				Y[i]=v[j];
				i++;
			}
		}

		for(j=0;j<len;j++)
		{
			temp[j]=X[j];

		}
		m=0;
		for(j=0;j<len;j++)
		{
			for(k=0;k<i;k++)
			{
				if(temp[j]==Y[k] && (intersect(X,temp[j],m)==1))
				{
					X[m]=temp[j];
					m++;
				}
			}
		}
		len=m;
		if(len==0)
		{
			clr();
			printf("\n\n\n\n\t\t\tYOU VIOLATED THE RULES OF THIS GAME");
			printf("\n\n\t\t\tPRESS ANY KEY TO QUIT...");
			getch();
			exit(0);


		}
		goto human_guess;
	}
	human_guess:
	printf("\n\tUSER\'S GUESS     :");
	q;
	scanf("%d",&q);
	if(num==q)
	{
		clr();
		printf("\n\n\n\n\n\t\t\tUSER WIN ...with a score of :%d",scoreu);
		printf("\n\n\n\n\tPRESS ANY KEY TO RETURN TO MAIN MENU....");
		win=1;
		return;
	}
	printf("\n\t\tB= %d\n\t\tC= %d",findb(q,num),findc(q,num));
	scorec++;
	goto cmp_guess;


}
void high()
{
	FILE *fptr;
	clr();
	fptr=fopen("saved_data.bin","r");
	fread(&olduser,sizeof(olduser),1,fptr);
	if(olduser.point==0)
	{
		printf("\n\n\n\n\n\t\t\tNO ONE HAVE WON THIS GAME..\n");
		printf("\n\t\t\tBE THE FIRST TO WIN THIS GAME....");
		printf("\n\n\n\n\tPRESS ANY KEY TO RETURN TO MAIN MENU...");
		fclose(fptr);
		return;
	}


	

		printf("\n\n\t\t\t\t  HIGH SCORE");
		printf("\n\t\t\t\t  ----------");
		printf("\n\n\tNAME OF PERSON :%s",olduser.name);
		printf("\n\tHIGHEST SCORE  :%d",olduser.point);
		printf("\n\n\n\n\tPRESS ANY KEY TO RETURN TO MAIN MENU...");
		fclose(fptr);
		return;

}
void credit()
{       clr();
	printf("\n\n\n\t\t\t\t  GAME CREDITS");
	printf("\n\t\t\t\t  ------------");
	printf("\n\n\tDESIGN             :MUHAMMED AMEEN");
	printf("\n\tIMPLEMENTATION     :MUHAMMED AMEEN");
	printf("\n\n\n\t\t\t\t  CONTACT INFO");
	printf("\n\t\t\t\t  ------------");
	printf("\n\n\t\tEMAIL  :muhammedameen08gmail.com");
	printf("\n\n\n\n\tPRESS ANY KEY TO RETURN TO MAIN MENU....");
	return;

}
void contact()
{               clr();
	printf("\n\n\n\t\t\t\t   RULES");
	printf("\n\t\t\t\t   -----");
	printf("\n\n\t**First of all...WE ONLY EXPECT VALID INPUT");
	printf("\n\t* The game is commenly known as cows and bulls");
	printf("\n\t* The game is between user and computer");
	printf("\n\t* Both user and computer will guess a number");
	printf("\n\t* The number must satisfy following conditions :");
	printf("\n\t\t1: It should be four digit number");
	printf("\n\t\t2: It must contain \'NON ZERO AND NONREPEATING\' digits");
	printf("\n\t* The winner is the one who find other\'s number first");
	printf("\n\t* B (bulls) :The # of number\'s appearing in same position");
	printf("\n\t* C (cows)  :The # of number\'s' common in both number excluding Bulls");
	printf("\n\n\t\tConsider the example  :");
	printf("\n\t\tLet n1 be 1352 and n2 be 7592");
	printf("\n\t\tHERE B = 1 \n\t\tAND C=1");
	printf("\n\n\n\n\tPRESS ANY KEY TO RETURN TO MAIN MENU....");
	return;
}
void set_back(int opt)
{
	switch(opt)
			{
				case 1:
						system("COLOR 07");
						break;
				case 2:system("COLOR 0A");
						break;
				case 3:system("COLOR 01");
						break;
				case 4:system("COLOR 04");
						break;
				case 5:system("COLOR 06");
						break;
				case 6:system("COLOR 70");
						break;
				case 7:system("COLOR 74");
						break;
				case 8:system("COLOR 7A");
						break;
				case 9:system("COLOR 71");
						break;
			}
		return;
}
void settings()
{
	clr();
	char cha;
	int n;
	char ch[10][40]={"WHITE       BLACK","GREEN       BLACK","BLUE        BLACK","RED         BLACK","YELLOW      BLACK","BLACK       WHITE","RED         WHITE","GREEN       WHITE","BLUE        WHITE","GOTO MAIN MENU..."};
	int opt=1,i;
	do
	{
			clr();
			printf("\n\n\t\t\t\t  SETTINGS");
			printf("\n\t\t\t\t  --------");
			printf("\n\n\t\tCHOOSE THE COLOR COMBINATION");
			printf("\n\n\t\t\t   TEXT COLOR  BACKGROUND COLOR");
			printf("\n\t\t\t   ----------  ----------------\n");
		for(i=0;i<10;i++)
		{
			switch(opt)
			{
				case 1:
						system("COLOR 07");
						break;
				case 2:system("COLOR 0A");
						break;
				case 3:system("COLOR 01");
						break;
				case 4:system("COLOR 04");
						break;
				case 5:system("COLOR 06");
						break;
				case 6:system("COLOR 70");
						break;
				case 7:system("COLOR 74");
						break;
				case 8:system("COLOR 7A");
						break;
				case 9:system("COLOR 71");
						break;
				case 10:set_back(cop);
						break;
			}
			
			if(i!=(opt-1))
			{
				printf("\n\t\t\t   %s",ch[i]);
			}
			else
			{
				printf("\n\t\t\t->%s",ch[i]);
			}
		}
		cha=getch();
		n=cha;
		if(n==13)
		{
			switch(opt)
			{
				case 1:
						system("COLOR 07");
						break;
				case 2:system("COLOR 0A");
						break;
				case 3:system("COLOR 01");
						break;
				case 4:system("COLOR 04");
						break;
				case 5:system("COLOR 06");
						break;
				case 6:system("COLOR 70");
						break;
				case 7:system("COLOR 74");
						break;
				case 8:system("COLOR 7A");
						break;
				case 9:system("COLOR 71");
						break;
				case 10:set_back(cop);
						printf("\n\n\n\n\t\tNO CHANGES MADE");
						printf("\n\nPRESS AY KEY TO RETURN TO MAIN MENU....");
						return;
			}
			cop=opt;
			clr();
			printf("\n\n\n\n\t\tSETTINGS SAVED");
			printf("\n\nPRESS ANY KEY TO RETURN TO MAIN MENU....");
			return;
		}
		else
		{
			cha=getch();
			switch(cha) { // the real value
			case 'H':if(opt==1)
				{
					opt=10;
				}
				else
				{
					opt--;
		
				}
			break;
			case 'P':if(opt==10)
				{
					opt=1;
					
				}
				else
				{
					opt++;
					
				}
				break;

			}	

		}

	}while(1);
}
int main()
{
	cop=rant(9);
	cop++;
	switch(cop)
			{
				case 1:
						system("COLOR 07");
						break;
				case 2:system("COLOR 0A");
						break;
				case 3:system("COLOR 01");
						break;
				case 4:system("COLOR 04");
						break;
				case 5:system("COLOR 06");
						break;
				case 6:system("COLOR 70");
						break;
				case 7:system("COLOR 74");
						break;
				case 8:system("COLOR 7A");
						break;
				case 9:system("COLOR 71");
						break;
				
			}	
	char ex;
	while(1)
	{
		int opt=mainmenu(),n;
		switch(opt)
		{
			case 0:return 0;
					break;
			case 1:start_game();
					ex=getch();
					n=ex;
					if(n == -32)
						getch();
					break;
			case 2:high();
					ex=getch();
					n=ex;
					if(n == -32)
						getch();
					break;
			case 3:credit();
					ex=getch();
					n=ex;
					if(n == -32)
						getch();
					break;
			case 4:contact();
						ex=getch();
						n=ex;
						if(n == -32)
							getch();
					break;
			case 5:settings();
					ex=getch();
						n=ex;
						if(n == -32)
							getch();
					break;
			case 6:return 0;
		}
		
		if(opt==1 && win ==1)
		{
			FILE *fptr;
				fptr=fopen("saved_data.bin","r");
				newuser.point=scoreu;
				fread(&olduser,sizeof(olduser),1,fptr);
				if(olduser.point==0)
				{
					if(scoreu==0)
					{
						printf("\n\n\n\n\n\t\t\tNO ONE HAVE PLAYED THIS GAME..\n");
						printf("\n\t\t\tBE THE FIRST TO PLAY THIS GAME....");
						printf("\n\n\n\n\tPRESS ANY KEY TO RETURN TO MAIN MENU...");
						fclose(fptr);

					}
					else
					{
						fclose(fptr);
						fptr=fopen("saved_data.bin","w");
						fwrite(&newuser,sizeof(newuser),1,fptr);
						fclose(fptr);
					}
				}
				else
				{	
					if(olduser.point > newuser.point)
					{

						fclose(fptr);
						fptr=fopen("saved_data.bin","w");
						fwrite(&newuser,sizeof(newuser),1,fptr);
						fclose(fptr);
					}
				
				}
			
			
		}	
			
		
	}
		
}
