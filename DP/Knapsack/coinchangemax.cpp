#include<iostream>
using namespace std;

int coinchange(int *coin,int n,int cval)
{
    int K[n+1][cval+1];

    for (int i = 0; i <= n; i++) { 
        for (int j = 0; j <= cval; j++) { 
            if (i == 0 && j != 0) 
                K[i][j] = 0; 
            else if(j==0)
                K[i][j]=1;
            else if (coin[i - 1] <= j) 
                K[i][j] = ( K[i][j - coin[i - 1]]+ K[i - 1][j] ); 
            else                                                                  
                K[i][j] = K[i - 1][j]; 
        } 
    } 
  
    return K[n][cval];
}

int main()
{
    int coin[]={1,2,3};
    int n=sizeof(coin)/sizeof(coin[0]);
    cout <<coinchange(coin,n,10);
}