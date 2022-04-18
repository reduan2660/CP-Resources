// https://lightoj.com/problem/farthest-nodes-in-a-tree
// https://www.shafaetsplanet.com/?p=604 2nd code is helpful

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
#define pb  push_back

const int LIM = 30009;
long long int n;
vector<pii> vec[LIM];

void clr()
{
    FOR(i, LIM){
        vec[i].clear();
    }
}

ll maxdistance(ll i, ll n, bool return_node)
{
    bool vis[n]; memset(vis, false, sizeof(vis));
    ll d[n];    memset(d, 0, sizeof(d));

    queue<ll> q;
    q.push(i);
    vis[i] = 1;
    ll max_distance = 0, max_distance_node=-1;
    while(!q.empty()){
        ll u = q.front(); q.pop();

        FOR(i, vec[u].size()){
            pii v = vec[u][i];

            if(vis[v.first] == 0){
                vis[v.first] = 1;
                d[v.first] = v.second + d[u];
                q.push(v.first);

                if(d[v.first] > max_distance){
                    max_distance = d[v.first];
                    max_distance_node = v.first;
                }
            }

        }
    }
    
    if(return_node) return max_distance_node;
    else return max_distance;
}

int main()
{
    ll testcases, u, v, w; getI(testcases);
    for(ll tc = 1; tc <= testcases; tc++){
        clr();
        getI(n);
        FOR(i, n-1){
            getIII(u, v, w);
            vec[u].pb(pii(v,w));
            vec[v].pb(pii(u,w));
        }

        ll farthest_from_root = maxdistance(0, n, true);
        ll dist = maxdistance(farthest_from_root, n, false);

        printf("Case %lld: %lld\n", tc, dist);
    }
    return 0;
}