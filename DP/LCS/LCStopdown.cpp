#include<bits/stdc++.h>
using namespace std;

int lcs( string X, string Y, int m, int n )  
{  
    int L[m + 1][n + 1];  
    int i, j;  
      
    
    for (i = 0; i <= m; i++)  
    {  
        for (j = 0; j <= n; j++)  
        {  
        if (i == 0 || j == 0)  
            L[i][j] = 0;  
      
        else if (X[i - 1] == Y[j - 1])  
            L[i][j] = L[i - 1][j - 1] + 1;  
      
        else
            L[i][j] = max(L[i - 1][j], L[i][j - 1]);  
        }  
    }  
          
    return L[m][n];  

    /*
        for printing

        while(i>0 || j>0)
        {
            if( X[i-1]== Y[j-1] )
            s.push_back(X[i-1]);
            else{
                if( L[i-1][j] > L[i][j-1]  )
                    j--;
                else i--;
            }
        }

        reverse.s;
        return s;
        
        shortest common supersequence is just (m+n)-LCS
        or
        (AUB) = A + B -(A intersection B)
    */

    /*
        minimum no of deletion and insertion to convert string a to b

        m+n - 2*LCS
    */

    /*
        longest palindromic subsequence(LPS)

        LCS ( string a, reverse of string a)

    */

    /*
        minimum no of deletion or insertion(both are same) in a string to make it a palindrome

        a.length()-LPS
    */

    /*
        sequence pattern matching

        LCS (string a, string b)== min (m,n);
    */

}  
  


int main()  
{  
    string X,Y;
    cin >>X;
    cin >>Y;  
      
    int m = X.size();  
    int n = Y.size();  
      
    cout << "Length of LCS is " 
         << lcs( X, Y, m, n );  
      
    return 0;  
}  

