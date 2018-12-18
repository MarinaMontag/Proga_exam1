#include <iostream>
#include <cstdio>
#include <conio.h>
#include <cstring>
#include <string>
using namespace std;
void delete_empty(FILE*my);
int main()
{
    FILE*my=fopen("my.txt","r");
    if(my==NULL) perror("error");
    else
    {
        delete_empty(my);
        fclose(my);
    }
    return 0;
}
void delete_empty(FILE*my)
{
    const int Size=100;
    char*s=new char[Size];
    FILE*new_my=fopen("new.txt","w");
    while(!feof(my))
    {
        fgets(s,Size,my);
        if(s[0]!='\n')
            fputs(s,new_my);
    }
    fclose(new_my);
    fclose(my);
     remove("my.txt");
     rename("new.txt", "my.txt");
}
