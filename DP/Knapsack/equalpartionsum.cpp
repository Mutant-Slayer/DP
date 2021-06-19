#include<iostream>
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

bool equalsumpartition(int *arr,int n)
{
    int sum=0;
    
    for(int i=0;i<n;i++)
    sum+=arr[i];
    
    if(sum%2!=0)
    return false;
    else 
    {
        sum/=2;
        return subsetsumproblem(arr,n,sum);
    }
}

int main()
{
    int arr[]={1,5,10,4};
    int n=sizeof(arr)/sizeof(arr[0]);
    cout <<equalsumpartition(arr,n);
}