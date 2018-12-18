#include <iostream>
#include <stdio.h>

using namespace std;
//у вхідному тексті знайти цифру, що зустрічається найчастіше

int find_char(){
    FILE *my;
    my = fopen("my.txt", "r");
    if(my==NULL) perror("error");
    else{
    int *number = new int[10];
    for (int i(0); i<10; i++)
        number[i] = 0;
    do
    {

        int b=fgetc(my);

    if(b>='0' && b<='9') number[b-48]++;
    }while(!feof(my));
    int max_char(0), max_number(number[0]);
    for (int i(1); i<10; i++){
        if (number[i]> max_number){max_char = i; max_number = number[i];}

    }
    fclose(my);
    return max_char;}
}


int main()
{
    cout<<find_char()<<endl;

    return 0;
}
