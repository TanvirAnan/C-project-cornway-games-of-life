#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#define rowcount 5
#define colcount 5
int livecellchecking(int arr1[][colcount],int arrlen,int j1,int k1)
{
    int sum=0,j2,j3;
    if(j1>0&&j1!=rowcount)
        {
            j2=j1-1;
            j3=j1+2;
        }
    else if(j1==0)
        {
            j2=j1;
            j3=j1+2;
        }
    else if(j1==rowcount)
       {
           j2=j1-1;
           j3=j1+1;
       }
    for(;j2<j3;j2++)
    {
        int k2,k3;
          if(k1>0&&k1!=colcount)
        {
            k2=k1-1;
            k3=k1+2;
        }
    else if(k1==0)
        {
            k2=k1;
            k3=k1+2;
        }
    else if(k1==colcount)
       {
           k2=k1-1;
           k3=k1+1;
       }
        for(;k2<k3;k2++)
        {
            sum=sum+arr1[j2][k2];
        }
    }
    if(sum==3||sum==4)
        return 1;
    else
        return 0;
}
int deadcellchecking(int arr1[][colcount],int arrlen,int j1,int k1)
{
    int sum=0,j2,j3;
    if(j1>0&&j1!=rowcount)
        {
            j2=j1-1;
            j3=j1+2;
        }
    else if(j1==0)
        {
            j2=j1;
            j3=j1+2;
        }
    else if(j1==rowcount)
       {
           j2=j1-1;
           j3=j1+1;
       }
    for(;j2<j3;j2++)
    {
        int k2,k3;
          if(k1>0&&k1!=colcount)
        {
            k2=k1-1;
            k3=k1+2;
        }
    else if(k1==0)
        {
            k2=k1;
            k3=k1+2;
        }
    else if(k1==rowcount)
       {
           k2=k1-1;
           k3=k1+1;
       }
        for(;k2<k3;k2++)
        {
            sum=sum+arr1[j2][k2];
        }
    }
    if(sum==3)
        return 0;
    else
        return 1;
}
int main ()
{
    int arr[rowcount][colcount]={0};
    int arr1[rowcount][colcount];
    for(;;)
    {
        int i,j;
        scanf("%d %d",&i,&j);
        arr[i][j]=1;
        if(i<0||j<0)
            break;

    }
    int gen;
    scanf("%d",&gen);
    for(int i=0;i<gen;i++)
    {
       for(int p=0;p<rowcount;p++)
       {
           for(int q=0;q<colcount;q++)
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
                res=livecellchecking(arr1,rowcount,a,b);
                  if(res==1)
                   {
                     arr[a][b]=1;
                     printf("0");
                   }
                  else
                  {
                     arr[a][b]=0;
                     printf(".");

                  }

             }
           else
             {
                res=deadcellchecking(arr1,rowcount,a,b);
                   if(res==1)
                    {
                      arr[a][b]=0;
                      printf(".");
                    }
                   else
                      {
                        arr[a][b]=1;
                        printf("0");
                      }

             }
         }
         printf("\n");
        }




   }
}