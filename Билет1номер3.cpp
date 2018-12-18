#include <iostream>
using namespace std;

int count(int n);
int Pow (int n, int a);
int main()
{
    int i2=0,i5=0,n,length(0),period,number_before_period,before_period;
    int c=10;
    cin>>n;
    int n_temp=n;
    while(n%2==0)
    {
       n/=2;
       i2++;
    }
    while(n%5==0)
    {
        n/=5;
        i5++;
    }
    if(i2>i5) number_before_period=i2;else number_before_period=i5;//число цифр до периода
    before_period=Pow(10,number_before_period)/n_temp;
    if(n!=1)
    {for(int i(1);i<n;i++)
    {
        if(((c-1)%n)==0)
        {length=i;break;}//колличество цифр в периоде
        else c*=10;
    }
    period =((Pow(10,length+number_before_period)-1)/n_temp)-Pow(10,length)*before_period;
    }
    else {period=0; length=1;}
    int new_length = length+number_before_period+3;
    char* s = new char[new_length];
    s[0] = '.';
    int _count = count(before_period);
    int i(1);
    for (; i<=number_before_period -_count; i++){
        s[i] = '0';
    }
    for (; i<=number_before_period; i++){
        s[i] = (before_period/Pow(10, _count-1))+48;
        before_period%=Pow(10, _count-1);
        _count--;
    }
    s[i] = '*'; i++;
    int p_length = length;
    if (period==0) s[new_length-2]=48; else
    for (;i<new_length-1; i++){
        s[i] = (period/Pow(10, p_length-1))+48;
        period%=Pow(10, p_length-1);
        p_length--;
    }
    s[new_length-1] = '*';
    for (int i(0); i<new_length; i++)
        cout<<s[i];
    return 0;
}

int count(int n){
int i(0);
if(!n) return 1;
while(n){
    n /=10;
    i++;
}
return i;
}
int Pow (int n, int a)
{
    int res=1;
    for(int i(0);i<a;i++)
        res*=n;
    return res;
}
