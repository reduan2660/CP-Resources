// https://lightoj.com/problem/beehives | Medium

#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define ll long long
#define FOR(i,n) for (long long i = 0; i < n; i++)
#define getI(a) scanf("%lld", &a)
#define getII(a, b) scanf("%lld %lld", &a, &b)

#define getIII(a, b, c) scanf("%lld %lld %lld", &a, &b, &c)
#define pii pair<long long, long long>
#define vi  vector<long long>
#define qi  queue<long long>
#define pb  push_back

const int LIM = 509;
vector<long long> vec[LIM];

void clr()
{
    FOR(i, LIM) vec[i].clear();
}

ll cycleDistance(ll i, ll n)
{
    bool vis[n]; memset(vis, false, sizeof(vis));
    ll d[n];    memset(d, 0, sizeof(d));
    ll parent[n];    memset(parent, -1, sizeof(parent));


    qi q;   q.push(i); 
    vis[i] = 1;

    ll ans = INT_MAX;
    
    while(!q.empty()){
        ll v = q.front(); q.pop();
        FOR(i, vec[v].size()){
            ll u = vec[v][i];

            if(!vis[u]){
                    vis[u] = true;
                    parent[u] = v;
                    d[u] = d[v] + 1;
                    q.push(u);

            }
            else if(parent[v] != u){
                ans = min(ans, d[v] + d[u] + 1);
            }
            
        }
    }
    return ans;
}

int main()
{
    ll testcases, u, v; getI(testcases);
    for(ll tc = 1; tc <= testcases; tc++){
        clr();

        ll n, m; getII(n, m);
        while(m--){
            getII(u, v);
            vec[u].pb(v); vec[v].pb(u);
        }

        ll minD = INT_MAX;;
        FOR(i, n){
            ll d = cycleDistance(i, n);
            // cout << d << endl;
            if(d < minD) minD = d;
        }

        if(minD == INT_MAX)   printf("Case %lld: impossible\n", tc);
        else   printf("Case %lld: %lld\n", tc, minD);

    }
    return 0;
}