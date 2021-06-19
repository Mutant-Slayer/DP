#include <iostream>
using namespace std;

bool subsetsumproblem(int *num,int n,int sum)
{
    bool K[n+1][sum+1];

    for (int i = 0; i <= n; i++) { 
        for (int j = 0; j <= sum; j++) { 
            if (i == 0 &&j!=0 ) 
                K[i][j] = false; 
            else if(j==0) K[i][j]=true;
            else if (num[i - 1] <= j) 
                K[i][j] = ( K[i - 1][j - num[i - 1]])|| (K[i - 1][j]); 
            else
                K[i][j] = K[i - 1][j]; 
        } 
    } 
  
    return K[n][sum]; 

}

int main()
{
    int num[]={1,3,5,8};
    int n=sizeof(num)/sizeof(num[0]);

    cout <<subsetsumproblem(num,n,6);
}