#include<iostream>
using namespace std;

int rodcutting(int *l,int *pr,int n,int len) //similar to unbounded knapsack only name changes
{
    int K[n+1][len+1];

    for (int i = 0; i <= n; i++) { 
        for (int j = 0; j <= len; j++) { 
            if (i == 0 || j == 0) 
                K[i][j] = 0; 
            else if (l[i - 1] <= j) 
                K[i][j] = max( pr[i - 1] + K[i][j - l[i - 1]], K[i - 1][j] ); 
            else                                                                  
                K[i][j] = K[i - 1][j]; 
        } 
    } 
  
    return K[n][len]; 

}

int main()
{
    int l[]={1,2,3};
    int pr[]={2,6,7};
    int n=sizeof(pr)/sizeof(pr[0]);
    cout <<rodcutting(l,pr,n,5);
}