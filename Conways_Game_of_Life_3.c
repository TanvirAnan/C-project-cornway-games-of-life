#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#define rowcount 20
#define colcount 60

int countingNeighbors(int arr1[][colcount],int arrlen,int r, int c)
{
    int sum=0,r1,r3; // r= current row, r1= previous row, r3= next row
    if(r>0 && r!=rowcount-1) // middle rows
        {
            r1=r-1;
            r3=r+1;
        }
    else if(r==0) // first row
        {
            r1=r;
            r3=r+1;
        }
    else if(r==rowcount-1) // last row
        {
           r1=r-1;
           r3=r;
        }

  for(  ;r1<=r3; r1++)
   {
    int c1,c3;  // c= current column, c1= previous column, c3= next column
    if(c>0 && c!=colcount-1) // middle columns
       {
         c1=c-1;
         c3=c+1;
       }
    else if(c==0) // first column
       {
         c1=c;
         c3=c+1;
       }
    else if(c==colcount-1) // last column
       {
         c1=c-1;
         c3=c;
       }

    for(  ;c1<=c3; c1++)
       {
         sum=sum+arr1[r1][c1]; //sum includes the current cell too
       }
   }

   return sum;
}

int liveCellChecking(int arr1[][colcount],int arrlen,int r,int c) //called if current cell is live
{
    int sum=countingNeighbors(arr1,rowcount,r,c);
    if(sum==3||sum==4)
        return 1;
    else
        return 0;
}

int deadCellChecking(int arr1[][colcount],int arrlen,int r,int c) //called if current cell is dead
{
    int sum=countingNeighbors(arr1,rowcount,r,c);
    if(sum==3)
        return 0;
    else
        return 1;
}

int main(void)
{
    int arr[rowcount][colcount]={0};
    int arr1[rowcount][colcount];
    int i,j;

    while((i>=0)&&(j>=0))
    {
      scanf("%d %d", &i, &j);
      arr[i][j]= 1;
    }

  int gen;
  scanf("%d",&gen);

  for(int i=0;i<gen;i++)
    {
       for(int p=0; p<rowcount; p++)
       {
         for(int q=0; q<colcount; q++)
          {
           arr1[p][q]=arr[p][q];
          }
       }

       for(int a=0;a<rowcount;a++)
       {
         for(int b=0;b<colcount;b++)
         {
          int res;
          if(arr1[a][b]==1)
             {
              res=liveCellChecking(arr1,rowcount,a,b);
              if(res==1)
               {
                arr[a][b]=1;
                printf("O"); // 'O' --> alive
               }
              else
               {
                arr[a][b]=0;
                printf("."); // '.' --> dead

               }
             }
          else
             {
              res=deadCellChecking(arr1,rowcount,a,b);
              if(res==1)
               {
                arr[a][b]=0;
                printf(".");
               }
              else
               {
                arr[a][b]=1;
                printf("O");
               }

             }
         }
         printf("\n");
        }
        system("cls");
        getchar();
   }
   return 0;
}





