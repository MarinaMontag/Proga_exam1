#include <iostream>
#include <cmath>
#include <clocale>
using namespace std;
struct dot
{
    double x;
    double y;
};
double P(dot a,dot b,dot c)
{
    double ab,ac,bc;
    ac=sqrt((a.x-c.x)*(a.x-c.x)+(a.y-c.y)*(a.y-c.y));
    ab=sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
    bc=sqrt((b.x-c.x)*(b.x-c.x)+(b.y-c.y)*(b.y-c.y));
    if(ab+bc>ac && ac+ab>bc && ac+bc>ab)
        {double p=ab+ac+bc;
    return p;}
    else return 0;
}
int main()
{
    setlocale(0,"Rus");
    int n;
    cin>>n;
    dot*mas=new dot[n];
    for(int i(0);i<n;i++)
        cin>>mas[i].x>>mas[i].y;
    cout<<endl;
    double max=P(mas[0],mas[1],mas[2]);
    dot maxa,maxb,maxc;
    for(int i(0);i<n;i++)
        for(int j(0);j<n;j++)
            for(int k(0);k<n;k++)
    {
        if(P(mas[i],mas[j],mas[k])>max)
            {max=P(mas[i],mas[j],mas[k]);
            maxa=mas[i];maxb=mas[j];maxc=mas[k];}
    }
    if (max!=0)
    cout<<"найбольший периметр P="<<max<<" в точках А("<<maxa.x<<" "<<maxa.y<<") В("<<maxb.x<<" "<<maxb.y<<") С("<<maxc.x<<" "<<maxc.y<<")";
    else cout<<"невозможно построить треугольник на заданных точках";
    return 0;
}
