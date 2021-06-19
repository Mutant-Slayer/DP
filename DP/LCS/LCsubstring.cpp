#include<bits/stdc++.h>
using namespace std;

int lcs( string X, string Y, int m, int n )  
{  
    int L[m + 1][n + 1];  

    memset(L,0,sizeof(L));
    
    for (int i = 1; i <= m; i++)  
    {  
        for (int j = 1; j <= n; j++)  
        {  
        if (X[i - 1] == Y[j - 1])  
            L[i][j] = L[i - 1][j - 1] + 1;  
      
        else
            L[i][j] = 0;  
        }  
    }  

    int ans=0;
          
    for(int i=0;i<=n;i++)
    {
        if(L[m][i]>ans)
        ans=L[m][i];
    }  

    return ans;
}  
  


int main()  
{  
    string X,Y;
    cin >>X;
    cin >>Y;  
      
    int m = sizeof(X);  
    int n = sizeof(Y);  
      
    cout << "Length of LCS is " 
         << lcs( X, Y, m, n );  
      
    return 0;  
}  

