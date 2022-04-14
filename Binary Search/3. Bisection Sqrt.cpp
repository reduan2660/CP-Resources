#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define endl '\n'

int main()
{
    ll n = 100;

    double l=0, r=n, mid;

    while(r-l > 0.000001){
        mid = (l+r)/2.0;

        if(mid*mid < n) l = mid;
        else if(mid*mid > n) r = mid;
        else return mid;
    }

    cout << mid << endl;
    return 0;
}