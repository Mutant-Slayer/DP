#include<iostream>
using namespace std;

int mincoinchange(int *coin,int n,int sum)
{
    int t[n+1][sum+1];

    for(int i=0;i<n+1;i++)
    {
        for(int j=0;j<sum+1;j++)
        {
            if(i==0)
            t[i][j]=INT_MAX-1;
            else if(j==0)
            t[i][j]=0;
        }
    }

    for(int j=1;j<sum+1;j++)
    {
        if(j%coin[0]==0)
        t[1][j]=j/coin[0];
        else t[1][j]=INT_MAX-1;
    }

    for(int i=2;i<n+1;i++)
    {
        for(int j=1;j<sum+1;j++)
        {
            if(coin[i-1]<=j)
            {
                t[i][j]=min(1+t[i-1][j-coin[i-1]],t[i-1][j]);
            }
            else t[i][j]=t[i-1][j];
        }
    }
    return t[n][sum];

}

int main()
{
    int coin[]={25,10,5};
    int n=sizeof(coin)/sizeof(coin[0]);

    cout <<mincoinchange(coin,n,30);
}