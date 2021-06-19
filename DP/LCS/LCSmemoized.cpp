#include<iostream>
#include<cstring>
using namespace std;

int t[100][100];

int LCSmemoize(string x,string y,int m,int n)
{   
    if(m==0||n==0)
    return 0;

    if(t[m][n]!=-1)
    return t[m][n];

    if(x[m-1]==y[n-1])
    return t[m][n]=1+LCSmemoize(x,y,m-1,n-1);
    else return t[m][n]= max( LCSmemoize(x,y,m-1,n) ,LCSmemoize(x,y,m,n-1) );
}

int main()
{
    string x="abc";
    string y="ahbgdc";
    int m=x.size();
    int n=y.size();

    memset(t,-1,sizeof(t));

    cout <<LCSmemoize(x,y,m,n);
}
