// https://lightoj.com/problem/expanding-rods
// https://raihankhan.github.io/2021-04-26-expanding-rods-loj-1137/
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;
#define F(i,R) for (long long i = 0; i < R; i++)

int main()
{
    int t; cin >> t;
    for(int tc = 1; tc <= t; tc++){
        double l, n, c; cin >> l >> n >> c;
        double ld = (1.0 + n*c)*l;
        double a = l/2.0;
        double beg=0, end=l/2.0, h, r, theta, l_t;

        while(end-beg >= 0.0000001){
            h = (beg+end)/2.0;
            r = (h/2.0) + (l*l)/(8.0*h);
            theta = 2.0*asin( a/r );
            l_t = r*theta;

            // !!! Doesnt Work
            // if(ld==l_t) break;
            // else if(ld < l_t) end = h;
            // else beg = h;

            if(l_t >= l) end = h;
            else beg = h;
        }

        printf("Case %d: %.7lf\n", tc, h);
    }
    return 0;
}