#include <iostream>

using namespace std;
struct domino
{
  int first;
  int second;
};

bool correct(domino *mas, int n){
    for (int i(0); i<n-1; i++)
        if (mas[i].second!= mas[i+1].first) return false;
    return true;

}
int main()
{
    int n;
    cin>>n;
    domino *mas = new domino[n];
    for (int i(0); i<n ; i++)
        cin>>mas[i].first>>mas[i].second;
        for (int i(0); i<n ; i++)
        cout<<i<<" "<<mas[i].first<<" "<<mas[i].second<<endl;
        cout<<correct(mas, n)<<endl;

    delete mas;
    return 0;
}
