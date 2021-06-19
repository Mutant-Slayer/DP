#include<bits/stdc++.h>
using namespace std;

void scsuper( string X, string Y, int m, int n )  
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
    
    int i=m,j=n;
    string s;
    
    while( i>0 && j>0 )
    {
        if(X[i-1]==Y[j-1])
        {
            s.push_back(X[i-1]);
            i--;
            j--;
        }
        else{
            if( L[i][j-1]>L[i-1][j] )
            {
                s.push_back(Y[j-1]);
                j--;
            }
            else{
                s.push_back(X[i-1]);
                i--;
            }
        }
    }
    
    while(i>0)
    {
        s.push_back(X[i-1]);
        i--;
    }
    while(j>0)
    {
        s.push_back(Y[j-1]);
        j--;
    }
    
    reverse(s.begin(),s.end());
    
    std::cout << s << std::endl;
     
}  
  


int main()  
{  
    string X,Y;
    cin >>X;
    cin >>Y;  
      
    int m = X.size();  
    int n = Y.size();  
      
    scsuper( X, Y, m, n );  
      
    return 0;  
} 