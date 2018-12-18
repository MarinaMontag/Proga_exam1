#include <iostream>

using namespace std;

struct card
{
    int number;
    char type;
};
bool check(card kozyr,card first,card second)
{
    if(first.number>second.number && first.type==second.type)
    return true;
    else
    if(second.type!=first.type && first.type==kozyr.type)
    return true;
    else return false;
}
int main()
{
    card kozyr;
    cin>>kozyr.type;
    card first;
    cin>>first.type;
    cin>>first.number;
    card second;
    cin>>second.type;
    cin>>second.number;
    cout<<check(kozyr,first,second);
    return 0;
}
