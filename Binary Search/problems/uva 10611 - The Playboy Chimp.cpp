// https://onlinejudge.org/index.php?option=onlinejudge&Itemid=8&page=show_problem&problem=1552

#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
typedef long long ll;

ll maxMin(ll* ara, ll N, ll x)
{
    ll l=0, r=N-1, ind = -1, mid;

    if(x < ara[0]) return ind;

    while(l<=r){
        mid = (l+r) / 2;
        
        ind = mid;
        if(ara[mid] == x){
            if(mid == 0) return -1;
            else if(ara[mid-1] == ara[mid]) r = mid - 1;
            else return --mid;
        }
        else if(ara[mid] < x) l = mid + 1;
        else r = mid -1;
    }

    if(ara[ind] > x) --ind;
    return ind;
}


ll minMax(ll* ara, ll N, ll x)
{
    ll l=0, r=N-1, mid, ind = -1;

    if(ara[r] < x) return ind;
    while (l<=r)
    {
        mid = (l+r)/2;
        ind = mid;

        if(ara[mid] == x){
            if(mid == N-1) return -1;
            else if(ara[mid + 1] == ara[mid]) l = mid+1;
            else return ++mid;
        }

        else if(ara[mid] < x) l = mid + 1;
        else r = mid -1;
    }
    
    if(ara[ind] < x ) ++ind;
    return ind;
}

int main()
{
    ll N; cin >> N;
    ll ara[N];
    for(ll i=0;i<N;i++) cin >> ara[i];

    ll Q; cin >> Q;
    while(Q--){
        ll x; cin >> x;

        ll lbi = maxMin(ara,N,x), ubi = minMax(ara,N,x);

        if(lbi == -1) cout  << "X";
        else cout  << ara[lbi];

        cout << " ";

        if(ubi == -1) cout << "X" << endl;
        else cout << ara[ubi] << endl;   
    }

    return 0;
}