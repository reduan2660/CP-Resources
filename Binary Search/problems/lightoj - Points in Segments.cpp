// https://lightoj.com/problem/points-in-segments

#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;
#define F(i,R) for (long long i = 0; i < R; i++)

int main()
{
    ll T; cin >> T;
    for(int t=1; t<=T; t++){
        ll n,q; cin >> n >> q;
        
        ll ara[n+1]; F(i, n) cin >> ara[i];

        printf("Case %d:\n", t);
        while(q--){
            ll a, b; cin >> a >> b;
            if((a<ara[0] && b < ara[0]) || (a>ara[n-1] && b>ara[n-1])) cout << 0 << endl;
            
            else{
                ll li = upper_bound(ara, ara+n, b) - ara;
                ll ri = lower_bound(ara, ara+n, a) - ara;

                cout << li - ri << endl;
            }
        }
    }
    return 0;
}