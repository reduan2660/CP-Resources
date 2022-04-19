// https://lightoj.com/problem/best-picnic-ever
// Approach: for each node you can reach all the cities that people live in, res += 1

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


int main()
{
    ll testcases, u, v, x; getI(testcases);
    for(ll tc = 1; tc <= testcases; tc++){

        ll k, n, m; getIII(k, n, m);
        
        vi dest;
        while(k--){
            getI(x);
            dest.pb(x);
        }

        vi adj[n+1];
        while(m--){
            getII(u,v);
            adj[v].pb(u);
        }

        ll res = 0;
        bool vis[n+1];
        for(ll s = 1; s<=n; s++){

            memset(vis, false, sizeof(vis));
            qi q; q.push(s); vis[s] = true;

            while(!q.empty()){
                ll parent = q.front(); q.pop();

                for(ll child: adj[parent]){

                    if(!vis[child]){
                        vis[child] = true;
                        q.push(child);
                    }
                }
            }

            ll cnt=0;
            for(ll d: dest){
                if(vis[d]) cnt++;
                else break;
            }
            if(cnt == dest.size()) res++;
        }
        
        printf("Case %lld: %lld\n", tc, res);
    }
    return 0;
}