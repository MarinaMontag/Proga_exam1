#include <iostream>

using namespace std;
struct time
{
    int hour;
    int minutes;
    int seconds;
};
int main()
{
    time now,plus_now;
    cin>>now.hour>>now.minutes>>now.seconds;
    plus_now.hour=now.hour;
    plus_now.minutes=now.minutes;
    plus_now.seconds=now.seconds+15;
    if(plus_now.seconds>=60)
    {
        plus_now.seconds-=60;
        plus_now.minutes++;
    }
    if(plus_now.minutes>=60)
    {
        plus_now.minutes-=60;
        plus_now.hour++;
    }
    if(plus_now.hour>=24) plus_now.hour-=24;
    cout<<plus_now.hour<<" "<<plus_now.minutes<<" "<<plus_now.seconds;
    return 0;
}
