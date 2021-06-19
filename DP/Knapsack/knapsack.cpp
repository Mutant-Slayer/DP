#include <iostream>
#include <cstring>
using namespace std;

int t[100][100];

int knapsack(int *wt,int *pr,int w,int n)
{
    if(n==0||w==0)
    return 0;

    if(t[n][w]!=-1)
    return t[n][w];

    if(w>=wt[n-1])
    return t[n][w]=max(pr[n-1]+knapsack(wt,pr, (w-wt[n-1]) , (n-1) ), knapsack(wt,pr,w,(n-1)) );

    else return t[n][w]=knapsack(wt,pr,w,(n-1));
}

int main()
{
    int wt[]={10,20,30};
    int pr[]={ 60, 100, 120 };  
    memset(t,-1,sizeof(t));

    int n=sizeof(wt)/sizeof(wt[0]);
    int w=50;
    cout <<knapsack(wt,pr,w,n);
    
}