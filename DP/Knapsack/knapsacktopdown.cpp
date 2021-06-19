#include <iostream>
using namespace std;

int knapsacktopdown(int *wt,int *pr,int n,int w)
{
    int K[n+1][w+1];

    for (int i = 0; i <= n; i++) { 
        for (int j = 0; j <= w; j++) { 
            if (i == 0 || j == 0) 
                K[i][j] = 0; 
            else if (wt[i - 1] <= j) 
                K[i][j] = max( pr[i - 1] + K[i - 1][j - wt[i - 1]], K[i - 1][j] ); //a slight change in this code ,make it unbounded knapsack
            else                                                                  //when we include value,we won't exclude it from array so that can be processed again
                K[i][j] = K[i - 1][j]; 
        } 
    } 
  
    return K[n][w]; 

}

int main()
{
    int wt[]={1,1,1};
    int pr[]={ 10,20,30 };
    int w=2; 

    int n=sizeof(wt)/sizeof(wt[0]);
    cout <<knapsacktopdown(wt,pr,n,w);
}
