#include <bits/stdc++.h>
using namespace std;
int main()
{
    int col;
    scanf("%d",&col);
    int arr[col];
    for(int i=0;i<col;++i)
    {
        scanf("%d",&arr[i]);
    }
    sort(arr,arr+col);
    for(int i=0;i<col;++i)
    {
        printf("%d ",arr[i]);
    }
    printf("\n");
}
