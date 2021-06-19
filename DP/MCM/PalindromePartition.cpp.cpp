#include <bits/stdc++.h>
using namespace std;

int t[101][101];

bool isPali(string x,int i,int j)
{
    if(i==j)
    return true;
    
    if(i>j)
    return true;
    
    while(i<j)
    {
        if(x[i]!=x[j])
        return false;
        i++; j--;
    }
    return true;
}

int PalindromePartition(string x,int i,int j)
{
    if(i>=j)
    return 0;
    
    if(isPali(x,i,j)==true)
    return 0;
    
    int ans=INT_MAX,temp=0;
    
    if(t[i][j]!=-1)
    return t[i][j];
    
    for(int k=i;k<=j-1;k++)
    {
        temp =1+ PalindromePartition(x,i,k)+PalindromePartition(x,k+1,j);
        ans=min(temp,ans);
    }
    return t[i][j]= ans;
    
}

int main()
{
    memset(t,-1,sizeof(t));
    
    string x;
    cin >>x;
    int n=x.size();
    
    std::cout << PalindromePartition(x,0,n-1) << std::endl;
}