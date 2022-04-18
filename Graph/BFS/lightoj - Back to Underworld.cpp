// https://lightoj.com/problem/back-to-underworld
// Tutorial Followed: https://github.com/lightoj-dev/problem-tutorials/blob/main/1009/en.md
// Tried this problem to learn bfs for the first time <3.. Basically copied mentioned tutorial ( which is great btw )

#include <bits/stdc++.h>
using namespace std;


#define endl '\n'
#define ll long long
#define FOR(i,n) for (long long i = 0; i < n; i++)
#define getI(a) scanf("%lld", &a)
#define getII(a, b) scanf("%lld %lld", &a, &b)


#define pb push_back

const long long LIM = 20009;
vector<int> vec[LIM];
bool visited[LIM] = {};
bool n_t[LIM] = {};

void clr()
{
    memset(visited, false, sizeof(visited));
    memset(n_t, false, sizeof(n_t));

    FOR(i, LIM) vec[i].clear();
}

ll bfs(ll x)
{
    ll vam = 0, lyk = 0;
    queue<ll> q;

    q.push(x); visited[x] = 1; n_t[x] = 1;
    ++lyk;

    while(!q.empty()){
        ll u = q.front();
        q.pop();

        FOR(i, vec[u].size()){
            ll v = vec[u][i];

            if(visited[v] == 0){
                q.push(v);
                visited[v] = 1;

                if(n_t[u] == 1){
                    n_t[v] = 0;
                    ++vam;
                }
                else{
                    n_t[v] = 1;
                    ++lyk;
                }
            }
        }
    }

    return max(lyk, vam);

}


int main()
{
    ll testcases, n, u, v; getI(testcases);
    for(ll tc = 1; tc <= testcases; tc++){
        clr();
        getI(n);
        while(n--){
            getII(u, v);

            vec[u].pb(v); vec[v].pb(u);
        }

        ll res = 0;

        FOR(i, LIM){
            if(visited[i] == 0 and !vec[i].empty()){
                res += bfs(i);
            }
        }

        printf("Case %lld: %lld\n", tc, res);
    }
    return 0;
}