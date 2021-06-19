#include <bits/stdc++.h>
using namespace std;

int t[101][101];

int MCM(int *A,int i,int j)
{
    int ans=INT_MAX,temp=0;
    
    if(i>=j)
    return 0;
    
    if(t[i][j]!=-1)
    return t[i][j];
    else{
    
        for(int k=i;k<=j-1;k++)
        {
            temp= MCM(A,i,k)+MCM(A,k+1,j)+A[i-1]*A[k]*A[j];
        
            ans=min(temp,ans);
        }
        t[i][j]= ans;
    }
    return t[i][j];
}

int main() {
	
	memset(t,-1,sizeof(t));
	
	int n;
	cin >>n;
	
	int A[n];
	
	for(int i=0;i<n;i++)
	cin >>A[i];
	
	cout <<MCM(A,1,n-1);
	return 0;
}