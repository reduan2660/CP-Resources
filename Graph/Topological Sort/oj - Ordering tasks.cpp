// https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=15&page=show_problem&problem=1246

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
    ll n, m, u, v; 
    while(1){
        getII(n, m);    if(n==0 and m==0) break;

        vi out[n], order;
        ll indeg[n];    memset(indeg, 0, sizeof(indeg));
        while(m--){
            getII(u, v);
            --u; --v; // 0 indexed
            out[u].pb(v);
            indeg[v] += 1;
        }

        
        // Ordering Ok But not the required ordering
        // FOR(i, n){;
        //     if(indeg[i] == 0){
        //         order.pb(i);
        //         for(ll c_node : out[i]){
        //              indeg[c_node] -= 1;
        //         }
        //         out[i].clear();
        //     }
        // }

        qi q;
        
        FOR(i, n){
            if(indeg[i] == 0) q.push(i);
        }

        while(!q.empty()){
            ll u = q.front(); q.pop();
            order.pb(u);

            for(ll v : out[u]){
                indeg[v] -= 1;
                out[u].clear();
                if(indeg[v] == 0) q.push(v);
            }
        }

        FOR(i, n){
            if(i) cout << " ";
            cout << order[i] + 1;
        }
        cout << endl;

    }
    return 0;
}