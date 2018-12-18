#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
void input_matrix(char**matrix,char*s,int n);
int count_word(char*s,int n);
int count_longest(char*s,int n,int word);
void delete_row(char**a,int&m, int n,int i);
int deleting(char**matrix,int&m,int n);
bool is_same_rows(char**a,int m,int n,int i,int k);
int main()
{
    const int Size=200;
    char*s=new char[Size];
    gets(s);
    int _size=strlen(s);
    int words=count_word(s,_size);
    int letters=count_longest(s,_size,words);
    char**matrix=new char*[words];
      for(int i(0);i<words;i++)
        matrix[i]=new char[letters];
    input_matrix(matrix,s,_size);
    cout<<deleting(matrix,words,letters);
    return 0;
}
int count_word(char*s,int n)
{
    int counter=0;
    bool b=true;
    for(int i(0);i<n;i++)
    {
        if(isalpha(s[i]))
        {
            if(b){
            counter++;
            b=false;}
        }
        else b=true;
    }
    return counter;
}
int count_longest(char*s,int n,int word)
{
   int sum=0,summax=0;
   for(int i(0);i<n;i++)
   {
       if(isalpha(s[i]))
       {
           sum++;
       }
       else if(s[i]==' ')
       {
           if(sum>summax)
            summax=sum;
           sum=0;
       }
   }
   return summax;
}
void input_matrix(char**matrix,char*s,int n)
{
   int im=0,jm=0;
       for(int i(0);i<n;i++)
       {
           if(s[i]!=' ')
           {matrix[im][jm]=s[i];jm++;}
           else {im++;jm=0;}
       }
}
void delete_row(char**a,int&m, int n,int i)
{
    for(int k(i);k<m;k++)
        if(k+1<m)
    for(int j(0);j<n;j++)
         a[k][j]=a[k+1][j];
    m--;
}
bool is_same_rows(char**a,int m,int n,int i,int k)
{
    bool flag=true;
    for(int j(0);j<n;j++)
        if(a[i][j]!=a[k][j])
        flag=false;
        if(flag) return true; return false;
}
int deleting(char**matrix,int&m,int n)
{
    for(int i(0);i<m;i++)
        for(int k(0);k<m;k++)
        if(i!=k)
    {
        if(is_same_rows(matrix,m,n,i,k))
        {delete_row(matrix,m,n,k);}
    }
    return m;
}
