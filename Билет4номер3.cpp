#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;
void change_Big(char*s);
bool check(char*s1,char*s2);
int main()
{
     const int Size=100;
    char*s1=new char[Size];
    char*s2=new char[Size];
    cout<<check(s1,s2);
    return 0;
}
void change_Big(char*s)
{
    for (int i(0);i<strlen(s);i++)
    {
        if((int)s[i]>=65 && (int)s[i]<=90)
            s[i]=(char)((int)s[i]+32);
    }
}
bool check(char*s1,char*s2)
{
    change_Big(s1); change_Big(s2);
    gets(s1);
    gets(s2);
    const int Size_arr=27;
    int*arr_s1=new int[Size_arr];
    int*arr_s2=new int[Size_arr];
    if(strlen(s1)!=strlen(s2)) return false;
    else
    {for(int i(0);i<strlen(s1);i++)
        {
        arr_s1[i]=0;arr_s2[i]=0;
        }
    for(int i(0);i<strlen(s1);i++)
    {
        arr_s1[s1[i]-97]++;
    }
    for(int i(0);i<strlen(s2);i++)
    {
        arr_s2[s2[i]-97]++;
    }
    for(int i(0);i<strlen(s1);i++)
        if(arr_s1[i]==arr_s2[i])
        return true;
        else return false;
    }
}
