#include<iostream>
using namespace std;

int countofsum(int *arr,int sum,int n)
{
    int K[n+1][sum+1];

    for (int i = 0; i <= n; i++) { 
        for (int j = 0; j <= sum; j++) { 
            if (i == 0 &&j!=0 ) 
                K[i][j] = 0; 
            else if(j==0) K[i][j]=1;
            else if (arr[i - 1] <= j) 
                K[i][j] = ( K[i - 1][j - arr[i - 1]])+ (K[i - 1][j]); 
            else
                K[i][j] = K[i - 1][j]; 
        } 
    } 
  
    return K[n][sum];
}

int main()
{
    int arr[]={2,3,5,8};
    int n=sizeof(arr)/sizeof(arr[0]);
    cout <<countofsum(arr,10,4);
}