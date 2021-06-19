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

int countofsubsetdiff(int *arr,int n,int diff)
{
    int sum=0;
    for(int i=0;i<n;i++)
    sum+=arr[i];   
    
    int s1=(diff+sum)/2;

    cout <<countofsum(arr,s1,n);
}

int main()
{
    int arr[]={1,1,2,3};
    int n=sizeof(arr)/sizeof(arr[0]);
    countofsubsetdiff(arr,n,5);
}
// target sum is equivalent to this , we have to add sign before each array elemnet
// which further equates to this problem
// form two subset whose diff is given number(sum)
// no need to write any code for that