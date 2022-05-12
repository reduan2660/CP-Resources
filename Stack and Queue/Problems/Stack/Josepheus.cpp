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

int josephusList(vi v, int k, int index)
{
    if(v.size() == 1) return v[0];

    index = (index + k) % v.size();
    v.erase(v.begin() + index);

    return josephusList(v, k, index);

}

int josephusRec(int n, int k)
{
    return n > 1 ? ((josephusRec(n - 1, k) + (k - 1)) % n) + 1: 1;
}

int josephusRep(int n, int k)
{
    int res = 0;
    FOR(i,n){
        res = (res + k) % (i + 1);
    }
    return res + 1;
    
}


int main()
{
    int n=14, k=2, index = 0;

    vi person;
    FOR(i,n) person.push_back(i+1);

    cout << josephusList(person, k-1, index) << " "<<  josephusRec(n, k) << " " <<josephusRep(n, k) << endl;
    return 0;
}