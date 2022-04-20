// https://lightoj.com/problem/counting-triangles

#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define ll long long
#define FOR(i,n) for (long long i = 0; i < n; i++)
#define FORB(a,b,c) for (long long a = b; a < c; a++)
#define cinI(a) scanf("%lld", &a)
#define cinII(a, b) scanf("%lld %lld", &a, &b)
#define cinIII(a, b, c) scanf("%lld %lld %lld", &a, &b, &c)

#define pii pair<long long, long long>
#define vi  vector<long long>
#define qi  queue<long long>
#define pb  push_back

bool valid_tri(ll a, ll b, ll c)
{
    if(((a+b) > c) and ((b+c)>a) and ((c+a)>b)) return true;
    else return false;
}


int main()
{
    ll testcases; cinI(testcases);
    for(ll tc = 1; tc <= testcases; tc++){

        ll n, x; cinI(n);
        vi l;
        FOR(i, n){
            cinI(x); l.pb(x);
        }

        ll tri = 0;

        // Brute Force - O(n^3) - AC for small 
        // FOR(i, n-2){
        //     FORB(j, i+1, n-1){
        //         FORB(k, j+1, n){
        //             if(l[i] + l[j] > l[k] and l[j] + l[k] > l[i] and  l[k] + l[i] > l[j]) tri++;
        //         }
        //     }
        // }


        // Binary Search
        sort(l.begin(), l.end());
        FOR(i, n-2){
            FORB(j, i+1, n-1){
                
                ll st = j+1, end = n-1, mid, ind, x;
                bool valid_exist = false;
                // finding upper bound for valid triangle
                while(st<=end){
                    mid = (st+end)/2;
                    
                    if(valid_tri(l[i], l[j], l[mid])){
                        if(mid == n-1 or !valid_tri(l[i], l[j], l[mid+1])){
                            valid_exist = true;
                            break;
                        }
                        else st = mid + 1;
                    }
                    else{
                        end=mid-1;
                    }
                }
                if(valid_exist) tri += mid-j;
            }
        }

        printf("Case %lld: %lld\n", tc, tri);
    }
    return 0;
}