#include<stdio.h>
#include<stdlib.h>
#include<string.h>

long long int input_cnic();
int check_cnic(long long int cnic);
void sign_up();
void sign_in();
void functions();
void how_to_play();
void game_frame();
void play_game();
void one_player(int);
void easy_level();
void medium_level(int);
void hard_level(int);
int win_check();
void two_player(int);
void score_fun();
void update_score(int);
void all_score();
int my_score();
void clear_score();
void go_back();
void clear_frame();

char frame[9]={ [0 ... 8] = ' '};
long long int account;

int main()
{
	int choice;
	system("color 4E");
	printf("\n\n\t\t\t\t\t\tTIC\tTAC\tTOE\n\t\t\t\t\t\t_____________________\n\n\t\t\t\t\t       ......THE  GAME......\n\n\n\n\n");
	printf("\t\t\t\t\t\t1.\tSIGN UP\n\n\t\t\t\t\t\t2.\tSIGN IN\n\n\t\t\t\t\t\t3.\tEXIT\n\n\t\t");
	printf("\t\t\t\tSelect..   ");
	scanf("%d",&choice);
	if(choice==1)
	{
		system("cls");
		sign_up();
	}
	else if(choice==2)
	{
		system("cls");
		sign_in();
	}
	else if(choice==3)
	{
		exit(1);
	}
	system("CLS");
	functions();
}

long long int input_cnic()
{
	long long int cnic=0;
	int ch=0;
	while(1)
	{
		ch=getch();
		if(ch>=48&&ch<=57)
		{
			if(cnic<999999999999)
			{
				printf("%c",ch);
			    cnic= cnic*10 + (ch-48);
			}
			if(cnic>9999 && cnic<=99999 || cnic>99999999999 && cnic<=999999999999)
			printf("-");
		}
		
		if(ch==8)
			{
				cnic=cnic/10;   //when we use backspace.
				printf("%c%c%c",8,32,8); //for using backspace.
			}
		
		if(ch==13)
		break;
	}
	cnic=cnic%10000000000000;
	if(cnic<999999999999)
	{
		while(1)
		{
			printf("\n\n\t\t\t\t\t  Invalid Number..  \n\n\t\t\t\t\tPlease Enter Valid Number");
			getch();
			system("cls");
			main();
			if(cnic<9999999999999)
			break;
		}
	}
	return cnic;
}

int check_cnic(long long int cnic)
{
	FILE *fp;
	long long int cnic1;
	fp=fopen("cnic.txt","r");
	if(fp==NULL)
	{
		printf("ERROR!");
		exit(1);
	}
	else
	{
		while(fscanf(fp,"%llu",&cnic1) != EOF)
		{
			if(cnic==cnic1)
		    {
			    return 0;  // 0 means same CNIC.
		    }
		    else
		    continue;
		}
	}
	return 1;  // 1 means different CNIC.
	fclose(fp);
}

void sign_up()
{
	printf("\n\n\t\t\t\t\t\tWELCOME TO SIGN UP PAGE\n");
	printf("________________________________________________________________________________________________________________________");
	long long int cnic;
	int result;
	FILE *fp;
	fp=fopen("cnic.txt","a");
	printf("\n\n\n\t\t\t\t\tEnter CNIC No: for Registration: \n\n\t\t\t\t\t");
	cnic=input_cnic();
	result=check_cnic(cnic);
	if(result==0)  //0 means cnic already in used.
	{
		printf("\n\n\t\t\t\t\tCnic already in use!\n\n\t\t\t\t\tTry Different");
		getch();
		system("cls");
		sign_up();
	}
	else if(result==1)  //1 means cnic used different.
	{
		fprintf(fp,"%llu\n",cnic);
		printf("\n\n\t\t\t\t\tREGISTERED SUCCESSFULLY! \n");
		printf("\t\t\t\t\tPRESS ANY KEY TO SIGN IN YOUR ACCOUNT..");
		account=cnic;
		update_score(0);
		getch();
		fclose(fp);
		system("cls");
		sign_in();
	}
}

void sign_in()
{
	printf("\n\n\t\t\t\t\t\tWELCOME TO SIGN IN PAGE\n");
	printf("________________________________________________________________________________________________________________________");
	FILE *fp;
	long long int cnic;
	int result;
	fp=fopen("cnic.txt","r");
	if(fp==NULL)
	{
		printf("ERROR! SIGNING IN..");
		exit(1);
	}
	else
	{
		printf("\n\n\n\n\n\t\t\t\t\t  Enter CNIC No: to Login..\n\n\t\t\t\t\t  ");
		cnic=input_cnic();
		result=check_cnic(cnic);
		if(result==0)
		{
			system("cls");
			printf("\n\n\n\n\t\t\t\t\t\t W E L C O M E\n\n\t\t\t\t\t\t      T O\n\n\t\t\t\t\t\tT H E\tG A M E");
			getch();
			account=cnic;
			system("cls");
			functions();
		}
		else if(result==1)
		{
			printf("\n\n\n\n\n\t\t\t\t\t  Sorry! Entered CNIC Not Found.\n\t\t\t\t\t  TRY AGAIN ");
			getch();
			system("cls");				
			sign_in();
		}
	}
}

void functions()
{
	int i,choice,player,score,level;
	char ch;
	printf("\n\n\t\t\t\t\t\tTIC\tTAC\tTOE\n\t\t\t\t\t\t_____________________\n\n\t\t\t\t\t       ......THE  GAME......\n\n\n\n\n");
	printf("\n\n\t\t\t\t1.\t\tHow To Play\n\n\t\t\t\t2.\t\tPlay Game\n\n\t\t\t\t3.\t\tScore Board\n\n\t\t\t\t4.\t\tLog Off");
	printf("\n\n\t\t\t\tSelect Option: ");
	scanf("%d",&choice);
    while(1)
	{
		if(choice!=1&&choice!=2&&choice!=3&&choice!=4)
		{
	     	printf("\n\n\t\t\t\tERROR! INVALID CHOICE.\n\t\t\t\tTRY AGAIN.");
			scanf("%d",&choice);
		}
		else 
		break;
	}
	if(choice==1)
	{
		system("CLS");
		how_to_play();
	}
	
	else if(choice==2)
	{
		system("CLS");
		play_game();
	}
	
	else if(choice==3)
	{
		system("cls");
		score_fun();
	}
	
	else if(choice==4)
	{
		system("CLS");
		printf("\n\n\tDo you really want to Logged Off your Account? y/n:\t");
		fflush(stdin);
		scanf("%c",&ch);
		if(ch=='y'||ch=='Y')
		{
			system("cls");
			main();
		}
		else 
		{
			system("CLS");
			functions();
		}
	}
}

void how_to_play()
{
	char frame_2d[3][3]={{'1','2','3'},{'4','5','6'},{'7','8','9'}};
	printf("\n\n");
	printf("\t\t\tI N S T R U C T I O N S\n");
	printf("\t\t\t_______________________\n\n\n");
	printf("1.  The game is played on a grid that's 3 by 3 squares.\n");
	int i;
	printf("\n\n");
	for(i=0;i<5;i++)
	{
		if(i==3)
		printf("\t\t%c\t|\t   %c\t\t|\t%c\n",frame_2d[0][0],frame_2d[0][1],frame_2d[0][2]);
		else
		printf("\t\t\t|\t\t\t|\n");
	}
	printf("\t    ");
	for(i=0;i<50;i++)
	{
		printf("_");
	}
	printf("\n");
	for(i=0;i<5;i++)
	{
		if(i==3)
		printf("\t\t%c\t|\t   %c\t\t|\t%c\n",frame_2d[1][0],frame_2d[1][1],frame_2d[1][2]);
		else
		printf("\t\t\t|\t\t\t|\n");
	}
	printf("\t    ");
	for(i=0;i<50;i++)
	{
		printf("_");
	}
	printf("\n");
	for(i=0;i<5;i++)
	{
		if(i==3)
		printf("\t\t%c\t|\t   %c\t\t|\t%c\n",frame_2d[2][0],frame_2d[2][1],frame_2d[2][2]);
		else
		printf("\t\t\t|\t\t\t|\n");
	}
	printf("\n2.  Positions are set like this. The player put their symbol in an empty symbol when it is his/her turn.\n");
	printf("\n3.  To unlock the new levels try to get the highest score.");
	printf("\n\n\n\n\t\t\tH O W  T O  W I N\n");
	printf("\t\t\t_________________\n\n");
	printf("=> To beat the player (or at least tie), you need to make use of a little bit of strategy. Strategy means figuring out what you need to do to win.\n");
	printf("\n=> The game is won when 3 small Tic Tac Toe games are won in a row, either horizontal, vertical, or diagonal.\n");
	printf("\n=> It's possible that the Ultimate Tic Tac Toe game ends in a draw. If there are no three big squares in a row that are owned by the same player, it's a draw.");
	getch();
	go_back();
}

void game_frame()
{
	int user_score=my_score(),i;
	system("cls");
	printf("\n\n\t\t\t\t\t\tTIC\tTAC\tTOE\n\t\t\t\t\t\t_____________________\n\n\t\t\t\t\t       ......THE  GAME......\n");
    printf("________________________________________________________________________________________________________________________\n\n\n\n");
	printf("\t\tScore: %d\n",user_score);
	printf("\t\t__________");
	printf("\n");
	for(i=0;i<5;i++)
	{
		if(i==3)
		printf("\t\t\t\t%c\t|\t\t   %c\t\t\t|\t%c\n",frame[0],frame[1],frame[2]);
		else
		printf("\t\t\t\t\t|\t\t\t\t\t|\n");
	}
	printf("\t\t    ");
	for(i=0;i<80;i++)
	{
		printf("_");
	}
	printf("\n");
	for(i=0;i<5;i++)
	{
		if(i==3)
		printf("\t\t\t\t%c\t|\t\t   %c\t\t\t|\t%c\n",frame[3],frame[4],frame[5]);
		else
		printf("\t\t\t\t\t|\t\t\t\t\t|\n");
	}
	printf("\t\t    ");
	for(i=0;i<80;i++)
	{
		printf("_");
	}
	printf("\n");
	for(i=0;i<5;i++)
	{
		if(i==3)
		printf("\t\t\t\t%c\t|\t\t   %c\t\t\t|\t%c\n",frame[6],frame[7],frame[8]);
		else
		printf("\t\t\t\t\t|\t\t\t\t\t|\n");
	}
}

void play_game()
{	
    int mode;
    while(1)
    {
    	printf("\n\n\t\t\t\t\t\tTIC\tTAC\tTOE\n\t\t\t\t\t\t_____________________\n\n\t\t\t\t\t       ......THE  GAME......\n");
    	printf("________________________________________________________________________________________________________________________");
    	printf("\n\n\t1.\tOne Player\n\n\t2.\tTwo Player\n\n\t3.\tBack\n\n");
    	printf("\t   \tSelect Mode:  ");
	    scanf("%d",&mode);
	    if(mode!=1&&mode!=2&&mode!=3)
	    {
	    	system("cls");
		    continue;
	    }
	    else
	    break;
	}
	if(mode==1)
	{
		clear_frame();
		one_player(1);
	}
	else if(mode==2)
	{
		clear_frame();
		two_player(1);
	}
	else if(mode==3)
	{
		system("CLS");
		functions();
	}
}

char computer,user;
char name1[30], name2[10]="Computer";
int position,level;
void one_player(int a)
{
	printf("\n\n\t\t\t\t\t\tTIC\tTAC\tTOE\n\t\t\t\t\t\t_____________________\n\n\t\t\t\t\t       ......THE  GAME......\n");
    printf("________________________________________________________________________________________________________________________");
	int yourscore;
	yourscore=my_score();
	char ch;
	system("CLS");
	if(a==1)
	{
		system("cls");
	    if(yourscore>=0&&yourscore<=4)
	    {
		    printf("\n\n\t\t\t\t\t\tTIC\tTAC\tTOE\n\t\t\t\t\t\t_____________________\n\n\t\t\t\t\t       ......THE  GAME......\n");
            printf("________________________________________________________________________________________________________________________");
		    printf("\n\n\n\n\t\t1.\tEASY LEVEL\n\n\t\t  \tMEDIUM LEVEL (LOCKED)\n\n\t\t  \tHARD LEVEL (LOCKED)\n\n\t\t2.\tFor Back");
	        printf("\n\n   \t\tLevel?..  ");
	        scanf("%d",&level);
	        if(level==2)
	        {
		        system("CLS");
		        play_game();
	        }
	        else if(level!=1)
	        {
	    	    system("cls");
	    	    one_player(1);
		    }
	    }
	    if(yourscore>=5&&yourscore<=10)
	    {
		    printf("\n\n\t\t\t\t\t\tTIC\tTAC\tTOE\n\t\t\t\t\t\t_____________________\n\n\t\t\t\t\t       ......THE  GAME......\n");
            printf("________________________________________________________________________________________________________________________");
		    printf("\n\n\n\n\t\t1.\tEASY LEVEL\n\n\t\t2.\tMEDIUM LEVEL\n\n\t\t  \tHARD LEVEL (LOCKED)\n\n\t\t3.\tFor Back");
	        printf("\n\n   \t\tLevel?..  ");
	        scanf("%d",&level);
	        if(level==3)
	        {
		        system("CLS");
		        play_game();
	        }
	        else if(level!=1&&level!=2)
	        {
	    	    system("cls");
	    	    one_player(1);
		    }
	    }
	    if(yourscore>=16)
 	    {
		    printf("\n\n\t\t\t\t\t\tTIC\tTAC\tTOE\n\t\t\t\t\t\t_____________________\n\n\t\t\t\t\t       ......THE  GAME......\n");
            printf("________________________________________________________________________________________________________________________");
		    printf("\n\n\n\n\t\t1.\tEASY LEVEL\n\n\t\t2.\tMEDIUM LEVEL\n\n\t\t3.\tHARD LEVEL\n\n\t\t4.\tFor Back");
	        printf("\n\n   \t\tLevel?..  ");
	        scanf("%d",&level);
	        if(level==4)
	        {
		        system("CLS");
		        play_game();
	        }
	        else if(level!=1&&level!=2&&level!=3)
	        {
	    	    system("cls");
	    	    one_player(1);
		    }
	    }
		system("cls");
		printf("\n\n\t\t\t\t\t\tTIC\tTAC\tTOE\n\t\t\t\t\t\t_____________________\n\n\t\t\t\t\t       ......THE  GAME......\n");
        printf("________________________________________________________________________________________________________________________");
	    printf("\n\n\n\tEnter your name: ");
	    fflush(stdin);
	    gets(name1);
	    fflush(stdin);
	    printf("\n\n\tSelect any one: 'X'  or  'O':  ");
	    scanf("%c",&user);
	    if(user!='X'&&user!='x'&&user!='O'&&user!='o')
	    {
		    while(1)
	        {
		        printf("\n\n\tInvalid choice. Try Again");
		        printf("\n\n\tSelect any any one: 'X'  or  'O':  ");
		        fflush(stdin);
 	            scanf("%c",&user);
 	            if(user!='X'&&user!='x'&&user!='O'&&user!='o')
 	            continue;
 	            else 
		        break;
	        }
	    }
	    if(user=='X'||user=='x')
	    {
		    if(user=='X')
		    computer='O';
		
		    else if(user=='x')
		    computer= 'o';
	    }
	    else if(user=='O'||user=='o')
	    {
		    if(user=='O')
		    computer='X';
		
		    else if(user=='o')
		    computer= 'x';
	    }
	    printf("\n\n\t%s= %c\n\t%s= %c\n\n",name1,user,name2,computer);
	    printf("\tPress any key to start game..");
	    getch();
	    system("CLS");
	    printf("\n\n\n\n\t\t\t\tL O A D I N G..\n\t\t\t\t");
	    int i;
	    for(i=0;i<35;i++)
		{
			if(i>=0&&i<=18)
			{
				printf("|");
				Sleep(120);
			}
			else if(i>=19&&i<=34)
			{
				printf("|");
				Sleep(50);
			}
		}
	    a--;
	}
	system("CLS");
	int win=0,i,key;
	for(i=1;i<=5;i++)
	{
		if(level==1)
		{
			easy_level();
			system("CLS");
		}
		if(level==2)
		{
			medium_level(i);
			system("CLS");
		}
		if(level==3)
		{
			hard_level(i);
			system("CLS");
		}
		game_frame();
		win=win_check();
		if(win==1)
		{
			system("color 1E");
			printf("\t\t\t\t*.......... S O R R Y! .............*\n");
	        printf("\t\t\t\t*....... Y O U    L O S T ..........*\n");
	        printf("\t\t\t\t*....... T H E    G A M E ..........*\n");
			getch();
			getch();
	        system("CLS");
			clear_frame();
			printf("\n\n\tPress 0 to Play Again And 1 to Go Back...");
			scanf("%d",&key);
			system("color 4E");
			if(key==0)
			one_player(0);
			else
			one_player(1);
		}
		if(i==5)
		{
			system("color 3F");
			printf("\t\t\t\t*......        G A M E     ........*\n");
	        printf("\t\t\t\t *......       D R A W      ......*\n");
	        printf("\t\t\t\t  *......  N I C E   T R Y   ....*\n");
			getch();
	        system("CLS");
			clear_frame();
			printf("\n\n\tPress 0 to Play Again and 1 to Go Back...");
			scanf("%d",&key);
			system("color 4E");
			if(key==0)
			one_player(0);
			else
			one_player(1);
		}
		printf("\n\n\t%s enter for position of %c: ",name1,user);
		scanf("%d",&position);
		if(position==0)
		go_back();
		if(position>=1&&position<=9)
		{
			while(1)
			{
				if(frame[position-1]==' ')
			    {
				    frame[position-1]=user;
				    break;
			    }
			    else 
			    {
			    	printf("Sorry %s! Invalid move. Try Again\n",name1);
			        printf("\nDear %s enter for position of %c: ",name1,user);
		            scanf("%d",&position);
				}
			}
		}
	    system("CLS");
	    game_frame();
	    win=win_check();
	    if(win==1)
	    {
	    	if(level==1)
	    	yourscore++;
	    	if(level==2)
	    	yourscore+=2;
	    	if(level==3)
	    	yourscore+=4;
	    	system("color 2F");
	    	printf("\n\n\n\n");
	    	printf("\t\t\t\t*******************************************\n");
        	printf("\t\t\t\t*............CONGRATULATIONS!.............*\n");
	        printf("\t\t\t\t*..............YOU   WINS ................*\n");
	        printf("\t\t\t\t*..........Your New Score:  %d............*\n",yourscore);
	        printf("\t\t\t\t*******************************************\n");
	        if(yourscore==5)
	        {
	        	printf("\t\t\t\t!!   C O N G R A T U L A T I O N S   !!\n");
	        	printf("\t\t\t\t<<   YOU HAVE UNLOCKED MEDIUM LEVEL  >>\n");
	        	printf("\t\t\t\t<<        YOU  PLAYED  WELL          >>\n\n");
	        	printf("\t\t\t  Note:- Now your Score will Increase by 2 in Medium Level.");
	        	
			}
			if(yourscore==16||yourscore==17)
	        {
	        	printf("\t\t\t\t!!   C O N G R A T U L A T I O N S   !!\n");
	        	printf("\t\t\t\t<<    YOU HAVE UNLOCKED HARD LEVEL   >>\n");
	        	printf("\t\t\t\t<<        YOU  PLAYED  WELL          >>\n\n");
	        	printf("\t\t\t  Note:- Now your Score will Increase by 4 in Hard Level.");
			}
			getch();
			system("cls");
            update_score(yourscore);
			clear_frame();
			printf("\n\n\tPress 0 to Play Again and 1 to Go Back...");
			scanf("%d",&key);
			system("color 4E");
			if(key==0)
			one_player(0);
			else
			one_player(1);
		}
	}
}

void easy_level()
{
	int comp;
	while(1)
	{
	    srand((unsigned) time(NULL));
	    comp=rand()%9;
	    if(frame[comp]==' ')
        {
	        frame[comp]=computer;
		    break;
	    }
	}
}

void medium_level(int position)
{
	int comp;
	if(position>=1 && position<=3)
	{
		while(1)
	    {
	        srand((unsigned) time(NULL));
	        comp=rand()%7+2;
	        if(frame[comp]==' ')
	        {
		        frame[comp]=computer;
		 	    break;
		    }
	    }
	}
	if(position==4 || position==5)
	{
		while(1)
	    {
	        srand((unsigned) time(NULL));
	        comp=rand()%9;
	        if(frame[comp]==' ')
	        {
		        frame[comp]=computer;
		 	    break;
		    }
	    }
	}
}

void hard_level(int position)
{
	int comp;
	if(position%2==0)
	{
		while(1)
		{
		    srand((unsigned) time(NULL));
		    comp=rand()%6+3;
		    if(frame[comp]==' ')
		    {
			    frame[comp]=computer;
				break;
			}
		}
	}
	if(position%2!=0)
	{
		while(1)
		{
		    srand((unsigned) time(NULL));
		    comp=rand()%9;
		    if(frame[comp]==' ')
		    {
			    frame[comp]=computer;
				break;
			}
		}
	}
}

char user1[30], user2[30], player1, player2;
void two_player(int a)
{
	system("CLS");
	printf("\n\n\t\t\t\t\t\tTIC\tTAC\tTOE\n\t\t\t\t\t\t_____________________\n\n\t\t\t\t\t       ......THE  GAME......\n");
    printf("________________________________________________________________________________________________________________________");
    int option,i=0;
    if(a==1)
	{
	    printf("\n\n\n\t\t\t1.\tStart Game\n\n\t\t\t2.\tBack to Main Menu");
	    printf("\n\n\t\t\t\tSelect Option:\t");
	    scanf("%d",&option);
	    if(option==1)
 	    {
		    printf("\n\n\n\n\t\t\t\tLOADING!\n\t\t\t\t");
	        for(i=1;i<20;i++)
	        {
		       printf("\xB2");
		       Sleep(50);
	        }
	    }
	    else
	    {
		   system("CLS");
		   play_game();
	    }
	    system("CLS");
	    printf("\n\nEnter your name [Player 1]: ");
	    fflush(stdin);
	    gets(user1);
	    printf("\nEnter your name [Player 2]: ");
	    gets(user2);
	    printf("\n\nSelect any one [Player 1]: 'X'  or  'O':  ");
	    scanf("%c",&player1);
	    if(player1!='X'&&player1!='x'&&player1!='O'&&player1!='o')
	    {
		   while(1)
	        {
		        printf("Sorry! Invalid choice. Try again\n\n");
		        printf("Select any any one: 'X'  or  'O':  ");
		        fflush(stdin);
 	            scanf("%c",&player1);
 	            if(player1!='X'&&player1!='x'&&player1!='O'&&player1!='o')
 	            continue;
 	            else 
		        break;
	        }
	    }
	    if(player1=='X'||player1=='x')
	    {
		    if(player1=='X')
		    player2='O';
		
		    else if(player1=='x')
		    player2= 'o';
	    }
	    else if(player1=='O'||player1=='o')
	    {
		    if(player1=='O')
		    player2='X';
		
		    else if(player1=='o')
		    player2= 'x';
	    }
	    printf("\n%s= %c\n%s= %c\n\n",user1,player1,user2,player2);
	    printf("Press any key to start game..");
	    getch();
    }
	system("CLS");
	int win=0,position,key;
	i=0;
	while(win!=1)
	{
		game_frame();
		printf("\n\n\t%s enter for position of %c: ",user1,player1);
		scanf("%d",&position);
		if(position==0)
		go_back();
		if(position>=1&&position<=9)
		{
			while(1)
			{
				if(frame[position-1]==' ')
			    {
				    frame[position-1]=player1;
				    break;
			    }
			    else 
			    {
			    	printf("Sorry %s! Invalid move. Try Again\n",user1);
			        printf("\nDear %s enter for position of %c: ",user1,player1);
		            scanf("%d",&position);
				}
			}
		}
	    system("CLS");
		game_frame();
		win=win_check();
	    if(win==1)
	    {
	    	system("color 2F");
	    	printf("\n\n\n");
	    	printf("\t\t\t\t_________________________________________________________\n\n");
        	printf("\t\t\t\t*............C O N G R A T U L A T I O N S!.............*\n\n");
	        printf("\t\t\t\t*..................%s   WINS............................*\n\n",user1);
	        printf("\t\t\t\t___________________________________________________________\n");
	        getch();
	        clear_frame();
	        printf("\n\n\tPress 0 to Play Again and 1 to Go Back...");
			scanf("%d",&key);
			system("color 4E");
			if(key==0)
			two_player(0);
			else
			two_player(1);
		}
		if(i==4)
		{
			system("color 3F");
			printf("\t\t\t\t*......        G A M E     ........*\n");
	        printf("\t\t\t\t *......       D R A W      ......*\n");
	        printf("\t\t\t\t  *......  BOTH PLAYED WELL   ....*\n");
			getch();
	        system("CLS");
			clear_frame();
			printf("\n\n\tPress 0 to Play Again and 1 to Go Back...");
			scanf("%d",&key);
			system("color 4E");
			if(key==0)
			two_player(0);
			else
			two_player(1);
		}
		printf("\n\n\t%s enter for Position of %c: ",user2,player2);
		scanf("%d",&position);
		if(position==0)
		go_back();
		if(position>=1&&position<=9)
		{
			while(1)
			{
				if(frame[position-1]==' ')
			    {
				    frame[position-1]=player2;
				    break;
			    }
			    else 
			    {
			    	printf("Sorry %s! Invalid move. Try Again\n",user2);
			        printf("\nDear %s enter for position of %c: ",user2,player2);
		            scanf("%d",&position);
				}
			}
		}
		system("CLS");
		game_frame();
		win=win_check();
	    if(win==1)
	    {
	    	system("color 2F");
	    	printf("\n\n\n");
	    	printf("\t\t\t\t_________________________________________________________\n\n");
        	printf("\t\t\t\t*............C O N G R A T U L A T I O N S!.............*\n\n");
	        printf("\t\t\t\t*..................%s   WINS............................*\n\n",user1);
	        printf("\t\t\t\t___________________________________________________________\n");
	        getch();
	        clear_frame();
	        printf("\n\t\tPress 1 to Play Again and 0 to Go Back.\n\t\t");
	        scanf("%d",&key);
	        system("color 4E");
	        system("CLS");
	        printf("\n\n\tPress 0 to Play Again and 1 to Go Back...");
			scanf("%d",&key);
			system("color 4E");
			if(key==0)
			two_player(0);
			else
			two_player(1);
		}
		system("CLS");
		i++;
	}
}

int win_check()
{
	if(((frame[0]=='x')||(frame[0]=='X'))&&((frame[1]=='x')||(frame[1]=='X'))&&((frame[2]=='x')||(frame[2]=='X')))
	return 1;
	
	if(((frame[3]=='x')||(frame[3]=='X'))&&((frame[4]=='x')||(frame[4]=='X'))&&((frame[5]=='x')||(frame[5]=='X')))
	return 1;
	
	if(((frame[6]=='x')||(frame[6]=='X'))&&((frame[7]=='x')||(frame[7]=='X'))&&((frame[8]=='x')||(frame[8]=='X')))
	return 1;
	
	if(((frame[0]=='x')||(frame[0]=='X'))&&((frame[3]=='x')||(frame[3]=='X'))&&((frame[6]=='x')||(frame[6]=='X')))
	return 1;
	
	if(((frame[1]=='x')||(frame[1]=='X'))&&((frame[4]=='x')||(frame[4]=='X'))&&((frame[7]=='x')||(frame[7]=='X')))
	return 1;
	
	if(((frame[2]=='x')||(frame[2]=='X'))&&((frame[5]=='x')||(frame[5]=='X'))&&((frame[8]=='x')||(frame[8]=='X')))
	return 1;
	
	if(((frame[0]=='x')||(frame[0]=='X'))&&((frame[4]=='x')||(frame[4]=='X'))&&((frame[8]=='x')||(frame[8]=='X')))
	return 1;
	
	if(((frame[2]=='x')||(frame[2]=='X'))&&((frame[4]=='x')||(frame[4]=='X'))&&((frame[6]=='x')||(frame[6]=='X')))
	return 1;

	if(((frame[0]=='o')||(frame[0]=='O'))&&((frame[1]=='o')||(frame[1]=='O'))&&((frame[2]=='o')||(frame[2]=='O')))
	return 1;
	
	if(((frame[3]=='o')||(frame[3]=='O'))&&((frame[4]=='o')||(frame[4]=='O'))&&((frame[5]=='o')||(frame[5]=='O')))
	return 1;
	
	if(((frame[6]=='o')||(frame[6]=='O'))&&((frame[7]=='o')||(frame[7]=='O'))&&((frame[8]=='o')||(frame[8]=='O')))
	return 1;
	
	if(((frame[0]=='o')||(frame[0]=='O'))&&((frame[3]=='o')||(frame[3]=='O'))&&((frame[6]=='o')||(frame[6]=='O')))
	return 1;
	
	if(((frame[1]=='o')||(frame[1]=='O'))&&((frame[4]=='o')||(frame[4]=='O'))&&((frame[7]=='o')||(frame[7]=='O')))
	return 1;
	
	if(((frame[2]=='o')||(frame[2]=='O'))&&((frame[5]=='o')||(frame[5]=='O'))&&((frame[8]=='o')||(frame[8]=='O')))
	return 1;
	
	if(((frame[0]=='o')||(frame[0]=='O'))&&((frame[4]=='o')||(frame[4]=='O'))&&((frame[8]=='o')||(frame[8]=='O')))
	return 1;
	
	if(((frame[2]=='o')||(frame[2]=='O'))&&((frame[4]=='o')||(frame[4]=='O'))&&((frame[6]=='o')||(frame[6]=='O')))
	return 1;
	
	return 0;
}

void score_fun()
{
	int choice;
	printf("\n\n\t\t1.\tMy Score\n\n\t\t2.\tAll Player Scores\n\n\t\t3.\tClear All Scores\n\n\t\t4.\tGo back");
	printf("\n\n\t\t  \tEnter Choice: ");
	scanf("%d",&choice);
	if(choice==1)
	{
	   	system("cls");
	   	my_score();
	   	go_back();
	}
	else if(choice==2)
	{
		system("cls");
		all_score();
		go_back();
	}
	else if(choice==3)
	{
		clear_score();
		system("cls");
		printf("\n\n\n\t\t\tDELETING ALL SCORES..\n\t\t\t");
		int i;
		for(i=0;i<35;i++)
		{
			if(i>=0&&i<=18)
			{
				printf("|");
				Sleep(100);
			}
			else if(i>=19&&i<=34)
			{
				printf("|");
				Sleep(50);
			}
		}
		printf("\n\n\t\tScores Cleared Successfully!\n\n\t");
		go_back();
	}
	else if(choice==4)
	{
		go_back();
	}
}

void update_score(int myscore)
{
	FILE *fp;
	fp=fopen("score.txt","a");
	fprintf(fp,"%llu:\t%d\n",account,myscore);
	fclose(fp);
}

void all_score()
{
	long long int cnic;
	int score;
	FILE *fp;
	fp=fopen("score.txt","r");
	if(fp==NULL)
	{
		printf("File not found!");
		exit(1);
	}
	else
	{
		while(fscanf(fp,"%llu:\t%d\n",&cnic,&score) != EOF)
		{
			printf("\n\n\t%llu:\t%d",cnic,score);
		}
	}
	fclose(fp);
}

int my_score()
{
	long long int cnic;
	int a[100]={ [0 ... 99]=0 }, i=0, j, k, temp, highest=0,score;
	FILE *fp;
	fp=fopen("score.txt","r");
	if(fp==NULL)
	{
		printf("FILE MISSING!");
		exit(1);
	}
	else
	{
		while(fscanf(fp,"%llu:\t%d\n",&cnic,&score) != EOF)
		{
			if(cnic==account)
			{
				a[i]=score;
				i++;
			}
		}
	}
	for(j=0;j<i;j++)
	{
		for(k=j+1;k<i;k++)
		{
			if(a[j]<a[k])
			{
				temp=a[j];
				a[j]=a[k];
				a[k]=temp;
			}
		}
	}
	printf("\n\n\tYour high score= %d",a[0]);
	highest=a[0];
	fclose(fp);
	return highest;
}

void clear_score()
{
	char password[10],ch,choice;
	int i=0;
	printf("\n\n\t\tADMINISTRATOR PERMISSION REQUIRED.");
	printf("\n\n\t\tPlease Enter Password.");
	printf("\n\n\t\t");
	while(1)
	{
		ch=getch();
		
		if(ch==13)
		break;
		
		if(ch==8)
		{
			if(i==0)
			{
				system("cls");
				score_fun();
			}
			else
			printf("%c%c%c",8,32,8);
		}
		
		else
		{
			printf("*");
			password[i]=ch;
		}
		i++;
	}
	if(strcmp(password,"cleardata")==0)
	{
		printf("\n\n\tDo you really want to Clear All Saved Scores? y/n:\t");
		fflush(stdin);
		scanf("%c",&choice);
		if(choice=='y'||choice=='Y')
		{
			system("cls");
			FILE *fp;
	        fp=fopen("score.txt","w");
	        fclose(fp);
		}
		else 
		{
			system("CLS");
			score_fun();
		}
	}
	else
	{
		printf("\n\n\t\tPassword Does not Match.");
		printf("\n\n\t\tTry Again!");
		getch();
		system("cls");
		clear_score();
	}
}

void go_back()
{
	int back;
	printf("\n\n\n\n\t\tPress 0 for Main Menu: ");
	scanf("%d",&back);
	if(back==0)
	{
		system("CLS");
		functions();
	}
	else
	{
		while(1)
		{
			printf("\n\n\t\tPlease enter 0: ");
			scanf("%d",&back);
			if(back==0)
			{
				system("CLS");
				functions();
			}
		}
	}
}

void clear_frame()
{
	int i;
	for(i=0;i<9;i++)
	{
		frame[i]=' ';
	}
}
