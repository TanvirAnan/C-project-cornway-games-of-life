#include <stdio.h>

#define DEADCELL '.'
#define LIVECELL '0'

#define ROW 20
#define COL 60

int main(void)
{
  int i,j;
  char main[ROW][COL];

  for(i=0;i<ROW;i++)
  {
    for(j=0;j<COL;j++)
    {
      main[i][j]= DEADCELL;
      printf("%c", main[i][j]);
    }
    printf("\n");
  }

  while((i>=0)&&(j>=0))
  {
      scanf("%d %d", &i, &j);
      main[i][j]= LIVECELL;
  }

  for(i=0;i<ROW;i++)
  {
    for(j=0;j<COL;j++)
    {
      printf("%c", main[i][j]);
    }
    printf("\n");
  }

  printf("%d", countNeighbors(5,5,main));
  return 0;
}

// Function for counting neighbors

 int countNeighbors(int x, int y, char main[][y]);

 int countNeighbors(int x, int y,char main[][y])
 {
   int sum=0;

   for(int i=x-1; i<x+2; i++)
   {
    for(int j=y-1; j<y+2; j++)
    {
       if(main[i][j]== LIVECELL)
       {
           sum += 1;
       }
    }
   }
   if(main[x][y]== LIVECELL)
   {
     sum -= 1;
   }

   return sum;
 }









