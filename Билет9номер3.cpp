#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
void change(char*s,int&n);
int main()
{
    const int Size=100;
    char*s=new char[Size];
    gets(s);
    int n=strlen(s);
    change(s,n);
    for(int i(0);i<n;i++)
        cout<<s[i];
    return 0;
}
void change(char*s,int&n)
{
    for(int i(0);i<n;i++)
        if(s[i]=='x')
    {
        for(int j(n);j>=i;j--)
            s[j]=s[j-1];
        n++;
        s[i]='k';s[i+1]='s';
        break;
    }
}
