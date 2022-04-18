// https://lightoj.com/problem/guilty-prince
// Alve Reduan

#include <bits/stdc++.h>
using namespace std;


#define endl '\n'
#define ll long long
#define FOR(i,n) for (long long i = 0; i < n; i++)
#define getI(a) scanf("%lld", &a)
#define getII(a, b) scanf("%lld %lld", &a, &b)

#define pii pair<long long, long long>
#define pb push_back

int fw[] = {1,-1,0,0};
int fh[] = {0,0,1,-1};

int main()
{
    ll testcases; getI(testcases);
    for(ll tc = 1; tc <= testcases; tc++){

        ll w, h, wi, hi; getII(w, h);
        char land[h][w];
        getchar();
        FOR(i,h){
            FOR(j, w){
                scanf("%c", &land[i][j]);

                if(land[i][j] == '@'){
                    hi = i; wi = j;
                }
            }
            getchar();
        }

        bool visited[h][w]; memset(visited, false, sizeof(visited));

        queue<pii> q;
        q.push(pii(hi,wi));
        visited[hi][wi] = 1;

        while(!q.empty()){
            pii pos = q.front();
            q.pop();

            FOR(i,4){
                pii newpos = pii(pos.first+fh[i], pos.second+fw[i]);
                if(newpos.first >= 0 and newpos.first < h and newpos.second >= 0 and newpos.second < w and visited[newpos.first][newpos.second] == 0 and land[newpos.first][newpos.second] == '.'){
                    visited[newpos.first][newpos.second] = 1;
                    q.push(newpos);
                }
            }
        }

        ll res = 0;
        FOR(i, h){
            FOR(j, w){
                if(visited[i][j]) res++;
            }
        }

        printf("Case %lld: %lld\n", tc, res);
    }
    return 0;
}