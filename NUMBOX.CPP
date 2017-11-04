#include<stdio.h>
#include<conio.h>
#include<iostream.h>
#include<stdlib.h>
#include"graphics.cpp"
#include<time.h>

void message();
void err2();

void main()
{
 //static int a[8]={1,2,3,4,5,6,7,8};
 int r[8],t,tb,flag,i,j,choice,w,move=0;
 long int wait;
 char current[9],tc,lastwiner[80],inchoice;
 static char wins[9]={ '1','2','3','4','5','6','7','8',' '};
 win over(25,10,55,20,LIGHTGREEN), err(25,10,55,20,LIGHTGREEN);

 FILE *lw;  //last winner

  //   gameover(25,i,55,i+20,LIGHTGREEN);
time_t s,f;

 clrscr();

 message();

/////////////////set game
 randomize();

 r[0]=random(8)+1;
 for(i=1;i<8;i++)
  {
   flag=0;
   t=random(8)+1;

   for(j=0;j<i;j++)
    {
     if(t==r[j]) {
		 flag=1;
		 break;
		 }
     else continue ;
     }

    if(flag==0)
	  {
	   r[i]=t;
	  }
    else {
	  i--;
	  }
   }

for(i=0;i<9;i++)
{
current[i]=char(r[i]+48);
if(i==8)  current[i]=' ';
}

time(&s);
//////////////////////////////start game
do{  //game loop
  again:

if(move>=170)
{ textcolor(YELLOW); putch('l'); clrscr();}
 else
 {textcolor(LIGHTCYAN); clrscr();}
 cout<<"                               move:"<<move+1<<"\n";
	  hline();
	  time(&f);

	 printf("\n\nTime since start= %.01f seconds       ",difftime(f,s) );

	  printf("\n\n\n\n\n\n\n                      ");
for(i=0;i<9;i++)
{
cout<<"     "<<current[i];
if( (i+1)%3==0)  printf("\n                      ");
}

for(i=0;i<9;i++)
{
if(current[i]==' ')
  {
    tb=i;
    break;
  }
}


cout<<"\n\n\n    Enter position:";
inchoice=getche();

choice=int(inchoice)-48;

	    //To make positions of squares same as numeric keypad
     if(choice==1)  choice=7;
else if(choice==2)  choice=8;
else if(choice==3)  choice=9;
else if(choice==7)  choice=1;
else if(choice==8)  choice=2;
else if(choice==9)  choice=3;

		   choice--;

if(inchoice=='e'||inchoice=='E'){
 //clrscr();

  over.text("\n\n\n\r\      GAME QUITTED\n\n\n\n\n\r");

	 over.draw();

	 getch();
	 window(1,1,80,25);

	 goto end;
	 }

 if( ! (choice==0||choice==1||choice==2||choice==3||choice==4||choice==5||
	 choice==6||choice==7||choice==8) )

       {
	err.text("\n    ERROR !!!\n\n\r\Enter nos. 1 to 9 to play...or 'e' to quit.\n\n\r\PRESS ANY KEY TO\n\n\r\ CONTINUE...");
	err.draw();  getch();  window(1,1,80,25);  goto again;
       }

///////////////////////verify move
if(tb==0)
{
   if(!(choice==tb+1||
     choice==tb+3
     ))
     {
       err2();
       goto again;
     }
}

else if(tb==1){
  if(!(choice==tb+1||
     choice==tb-1||
     choice==tb+3
     ))
     {
       err2();
       goto again;
     }         }

else if(tb==2){
     if(!(
     choice==tb-1||
     choice==tb+3
     ))
     {
       err2();
       goto again;
     }    }

else if(tb==3){
     if(!(choice==tb+1||
     choice==tb+3||
     choice==tb+-3
     ))
     {
       err2();
       goto again;
     }     }

else if(tb==4){
     if(!(choice==tb+1||
     choice==tb-1||
     choice==tb+3||
     choice==tb+-3
     ))
     {
       err2();
       goto again;
     }   }

else if(tb==5)  {
      if(!(choice==tb-1||
     choice==tb+3||
     choice==tb+-3
     ))
     {
       err2();
       goto again;
     }           }

else if(tb==6) {
      if(!(choice==tb+1||
	   choice==tb+-3
	 ))
     {
       err2();
       goto again;
     }          }

else if(tb==7) {
      if(!(choice==tb+1||
     choice==tb-1||
     choice==tb+-3
     ))
     {
       err2();
       goto again;
     }         }

else if(tb==8){
      if(!(
     choice==tb-1||
     choice==tb+-3
     ))
     {
       err2();
       goto again;
     }         }
//////////////////////////move verified
move++;
if(move==200)
 {
   for(i=14;i>=5;i--)
   {
  win  over(25,i,55,i+10,LIGHTGREEN);
  over.text("\n\n\r\      GAME OVER\n\n\n\n\n\r");
	 over.draw();  for( wait=0;wait<9500000;wait++);
	if(i==5) getch();
	 window(1,1,80,25);
	   clrscr();
    }

	 goto end;
  }
		   //swap
tc=current[tb];
current[tb]=current[choice];
current[choice]=tc;
   w=1;
       //check for win
for(i=0;i<9;i++)
 {
  if(current[i]!=wins[i])
   {
    w=0; break;
   }
  else continue ;
 }
}while(w!=1);  //GAME LOOP FINISHES
      //getch();
   //clrscr();

	     lw=fopen("numbox.lsw","w");

  over.text("\n\n\n\n\r\       CONGRATS!!!\n\n\n\n\r\Enter name: \n\r");
	 over.draw();
	scanf(" %[^\n]",lastwiner);
	fprintf(lw," %s",lastwiner);
	fclose(lw);
	 getch();
	 window(1,1,80,25);

	 goto end;

  end:
  textcolor(WHITE);  //Because textcolor doesn't change unless some
  putch('q');clrscr();//character has been printed , and doesn't change
   }//forever unless screen has been cleared.


void err2()
{
 win err(25,10,55,20,LIGHTGREEN);
	err.text("\n  ERROR !!!\n\n\r\  INVALID MOVE.");
	err.draw();  getch();  window(1,1,80,25);
return;
}

void message()
{
 FILE *lw;
long int wait;
char lsw,lastwiner[80];
 printf("\n\n\n\n\n\n\n\n\n\n\n                    AMITRONIX PRESENTS...");
 for(wait=0;wait<99999999;wait++);
 clrscr();

 fallvert("NUMBERED SQUARES");  for(wait=0;wait<99999999;wait++);
 clrscr();
 cout<<"\nTHE GAME:"
     <<"\n\n You have to make below given arrangement from"
     <<"\n the given random arrangement in at most 200 steps "
     <<"\n by moving the \"blank\"."
     <<"\n\n   1   2   3"
     <<"\n   4   5   6"
     <<"\n   7   8"
     <<"\n\n The \"blank\" can be swapped with elements at positions"
     <<"\n perpendicular to it only."
     <<"\nEnter the position of element to be swapped with \"blank\""
     <<"\nby entring no. 1 to 9.These positions are as shown below:-"
     <<"\n\n7   8   9        SAME  AS\n4   5   6        NUMERIC  KEYPAD\n1   2   3"
     <<"\n\nEntring 'e' will terminate the game"
     <<"\n\nENTER L TO SEE LAST WINNER'S NAME...PRESS ANY OTHER KEY TO CONTINUE...";
     lsw=getch();
     if(lsw=='l'||lsw=='L')
     {
       clrscr();
       lw=fopen("numbox.lsw","r");
       fscanf(lw," %[^\n]",lastwiner);
       fclose(lw);
       cout<< "\n\nLast Winner:  "<<lastwiner;
       getch();
       return;
     }
    else
     clrscr();
 return;
}






