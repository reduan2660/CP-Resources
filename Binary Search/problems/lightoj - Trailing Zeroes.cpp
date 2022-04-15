// https://lightoj.com/problem/points-in-segments

#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;
#define F(i,R) for (long long i = 0; i < R; i++)

const long long LIMIT = 1e18;

ll factorialPrimePower(ll n, ll b)
{
    ll ans = 0, p=1, d=b;
    while(d<=n){
        ans += floor(n/d);
        p++;
        d = pow(b, p);
    }
    return ans;
}

ll tens(ll q)
{
    // TLE
    // ll x = factorialPrimePower(q, 2);
    // ll y = factorialPrimePower(q, 5);
    // return min(x, y);
    
    // AC: the number of 2s in prime factors is always more than or equal to the number of 5s
    return factorialPrimePower(q, 5);
}


ll search(ll q)
{
    ll l=0, r=LIMIT, mid, n = -1;

    while(l<=r){
        mid = (l+r)/2;

        ll tns = tens(mid);
        if(tns == q){

            if(tens(mid-1) == q) r = mid - 1;
            else{
                n = mid;
                break;
            }
        }
        else if(tns > q) r = mid - 1;
        else l = mid + 1;
    }

    return n;
}

int main()
{
    ll T; cin >> T;
    for(int t=1; t<=T; t++){
        ll q; cin >> q;

        
        ll n = search(q);
        if(n == -1){
            printf("Case %d: impossible\n", t);
        }
        else printf("Case %d: %d\n", t, n);

    }
    return 0;
}