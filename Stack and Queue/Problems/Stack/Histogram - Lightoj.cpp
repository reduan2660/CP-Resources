#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define ll long long
#define FOR(i,n) for (long long i = 0; i < n; i++)
#define FORR(i,n) for (long long i = n-1; i >= 0; i--)
#define cinI(a) scanf("%lld", &a)
#define cinII(a, b) scanf("%lld %lld", &a, &b)
#define cinIII(a, b, c) scanf("%lld %lld %lld", &a, &b, &c)

#define pii pair<long long, long long>
#define vi  vector<long long>
#define qi  queue<long long>
#define pb  push_back


int main()
{
    ll testcases; cinI(testcases);
    for(ll tc = 1; tc <= testcases; tc++){

        ll n; cinI(n);
        int v[n], l[n], r[n];
        stack<ll> ls, rs;
        FOR(i, n){
            cinI(v[i]);
        }

        FOR(i, n){
            while(1){
                if(ls.empty()){ 
                    l[i] = -1; 
                    ls.push(i);
                    break;
                }
                else if(v[ls.top()] < v[i]){ 
                    l[i] = ls.top(); 
                    ls.push(i);
                    break;
                }
                else ls.pop();
            }
        }

        FORR(i, n){
            while(1){
                if(rs.empty()){ 
                    r[i] = n; 
                    rs.push(i);
                    break;
                }
                else if(v[rs.top()] < v[i]){ 
                    r[i] = rs.top(); 
                    rs.push(i);
                    break;
                }
                else rs.pop();
            }
        }

        ll maxArea = 0, area;

        FOR(i, n){
            area = v[i] * (r[i] -1  - l[i]);

            maxArea = max(maxArea, area);
        }


        printf("Case %lld: %lld\n", tc, maxArea);

        // for(auto x: l) cout << x << " ";
        // cout << endl;
        // for(auto x: r) cout << x << " ";
        // cout << endl << endl;
    }
    return 0;
}