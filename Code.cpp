
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<windows.h>

int width=20,height=20,gameover;
int x,y,fruitX,fruitY,score,flag;
int tailX[100],tailY[100];
int slep=100;
int CountTail=0;
void setup()
{
 gameover=0;
 x=width/2;
 y=height/2;

 label1:
 fruitX=rand()%20;
 if(fruitX==0)
    goto label1;
 label2:
 fruitY=rand()%20;
 if(fruitY==0)
    goto label2;
    score=0;
}
void draw()
{
    int i,j,k;
    system("cls");
     for(i=0;i<width;i++)
    {
      for(j=0;j<height;j++)
      {
        if(i==0||i==height-1||j==0||j==width-1)
        {
           printf("*");
        }
        else
        {
            if(i==x && j==y)
                printf("O");
            else if(i==fruitX&&j==fruitY)
                printf("F");
            else
                {
                  int ch=0;
                  for(k=0;k<CountTail;k++)
                  {
                    if(i==tailX[k] && j==tailY[k])
                    {
                      printf("o");
                      ch=1;
                    }
                  }
                  if(ch==0)
                  printf(" ");
                }
        }
      }
    printf("\n");
    }
    printf("SCORE=%d",score);
    //printf("\n slep=%d",slep);
}
void input()
{

  if(kbhit())
  {
     switch(getch())
     {
     case 'a':                   //aswd
         flag=1;
         break;
     case 'd':
        flag=2;
        break;
     case 'w':
        flag=3;
        break;
     case 's':
        flag=4;
        break;
     case 'x':
         gameover=1;
         break;
     }
  }
}
void MakeLogic()
{
  int i;
  int prevX=tailX[0];
  int prevY=tailY[0];
  int prev2X,prev2Y;
  tailX[0]=x;
  tailY[0]=y;

  for(i=1;i<CountTail;i++)
  {
      prev2X=tailX[i];
      prev2Y=tailY[i];
      tailX[i]=prevX;
      tailY[i]=prevY;
      prevX=prev2X;
      prevY=prev2Y;
  }



  switch(flag)
  {
    case 1:
        y--;
        break;
    case 2:
        y++;
        break;
    case 3:
        x--;
        break;
    case 4:
        x++;
        break;
    default:
        break;
  }
  if(x<=0||x>width-2||y<=0||y>height-2)
   {
       gameover=1;


        Beep(500,400);
        Beep(300,400);
        Beep(400,400);
        Beep(600,400);

   }   for(i=0;i<CountTail;i++)
       {
        if(x==tailX[i]&&y==tailY[i])
        gameover=1;
       }



  if(x==fruitX && y==fruitY)
  {  Beep(500,1000);
     label3:
 fruitX=rand()%20;
 if(fruitX==0)
    goto label3;
 label4:
 fruitY=rand()%20;
 if(fruitY==0)
    goto label4;
    score+=10;
    CountTail++;
    slep-=5;
  }

}
int main()
{  int c;
    label5:
   setup();
   while(!gameover)
   {
       draw();
       input();
       MakeLogic();
       Sleep(slep);
   }

    printf("\nPress Y to continue again: ");
    scanf("%c",&c);
       if(c=='y'||c=='Y')
        {  CountTail=0; slep=100;
          goto label5;
        }

     printf("\nPress Y to continue again: ");
    scanf("%c",&c);
       if(c=='y'||c=='Y')
        {  CountTail=0; slep=100;
          goto label5;
        }


  return(0);
}

