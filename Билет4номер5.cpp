#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
//підрахувати в тексті загальнукількість коментарів
int comments(FILE*my);
int SIZE_s(char*s);
int main()
{
    FILE*my=fopen("my.txt","r");
    if(my==NULL) perror("error");
    else{
    cout<<comments(my);
    fclose(my);}
    return 0;
}
int comments(FILE*my)
{
    int counter=0;
    const int Size=100;
    char*s=new char[Size];
    while(!feof(my))
    {
    fgets(s,Size,my);
    for(int i(0);i<SIZE_s(s);i++)
        if(i+1<SIZE_s(s))
        if((s[i]=='/' && s[i+1]=='/')||(s[i]=='/' && s[i+1]=='*'))
        counter++;
    }
   return counter;

}
int SIZE_s(char*s)
{
    int i=0;
    while(s[i])
        i++;
    return i;
}
