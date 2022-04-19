// https://www.hackerearth.com/practice/algorithms/graphs/depth-first-search/tutorial/

#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define ll long long
#define FOR(i,n) for (long long i = 0; i < n; i++)
#define cinI(a) scanf("%lld", &a)
#define cinII(a, b) scanf("%lld %lld", &a, &b)
#define cinIII(a, b, c) scanf("%lld %lld %lld", &a, &b, &c)


#define pii pair<long long, long long>
#define vi  vector<long long>
#define qi  queue<long long>
#define pb  push_back

const long long LIM = 100009;
vi adj[LIM];
bool visited[LIM];

void clr(){
    memset(visited, false, sizeof(visited)); // White
    FOR(i, LIM) adj[i].clear();
}

void dfs(int s)
{
    visited[s] = true; // exploring, Grey
    for(ll v: adj[s]){
        if(visited[v] == false){
            dfs(v);
        }
    }
    // setting black isn't necessary in this particular problem
}

int main()
{
    clr();
    ll n, m, u, v, h; cinII(n, m);
    
    while(m--){
        cinII(u, v);
        --u, --v, // 0 indexed
        adj[u].pb(v); 
        adj[v].pb(u);
    }
    
    cinI(h);
    dfs(--h);  // --h because 0 indexed
    
    cout << count(visited, visited+n, false);
    return 0;
}