#include<bits/stdc++.h>
using namespace std;

int lcsub( string X, string Y, int m, int n )  
{  
    int L[m + 1][n + 1];  
    int result=0;

    for (int i=0; i<=m; i++) 
    { 
        for (int j=0; j<=n; j++) 
        { 
            if (i == 0 || j == 0) 
                L[i][j] = 0; 
  
            else if (X[i-1] == Y[j-1]) 
            { 
                L[i][j] = L[i-1][j-1] + 1; 
                result = max(result, L[i][j]); 
            } 
            else L[i][j] = 0; 
        } 
    } 
    return result; 
}  
  


int main()  
{  
    string X,Y;
    cin >>X;
    cin >>Y;  
      
    int m = X.size();  
    int n = Y.size();  
      
    cout << "Length of LCS is " 
         << lcsub( X, Y, m, n );  
      
    return 0;  
}  
