#include<iostream>
#include<vector>
using namespace std;

bool K[100][100];

bool subsetsumproblem(int *num,int n,int sum)
{

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

int minsubsetsumdiff(int *arr,int n)
{
     int sum=0,mn=INT_MAX; vector<int> v;

    for(int i=0;i<n;i++)
    sum+=arr[i];

    K[n+1][sum+1]=subsetsumproblem(arr,n,sum);

    for(int k=0;k<=sum/2;k++)
    {
        if( K[n][k]==true)
        v.push_back(k);
    }

    for(int i=0;i<v.size();i++)
    {
        mn=min(mn,sum-2*v[i]);
    }

    return mn;
}

int main()
{
    int arr[]={1,3,7,20};
    int n=sizeof(arr)/sizeof(arr[0]);
    cout <<minsubsetsumdiff(arr,n);
}