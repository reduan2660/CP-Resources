// https://www.hackerrank.com/challenges/poisonous-plants/problem?isFullScreen=true&h_r=next-challenge&h_v=zen&h_r=next-challenge&h_v=zen

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


int main()
{
    string s = "";
    stack<string> st;
    st.push(s);
    ll n, top=0; cinI(n);
    FOR(x, n){

        int op; cin >> op;
        // cout << op << " ";
        if(op == 1){
            string stemp; cin >> stemp;
            
            s = s.append(stemp);
            st.push(s);
        }
        else if(op == 2){
            ll l; cinI(l);

            s = s.substr(0, max(0, int(s.size() - l)));
            st.push(s);
        }
        else if(op == 3){
            ll i; cinI(i);
            cout << st.top()[i-1] << endl;
        }
        else if(op == 4){

            if(!st.empty()){
                // cout << s <<  " - ";
                st.pop();
                if(!st.empty()) s = st.top();
                // cout << s << " ---------------" << endl;
            }
        }
    }

    return 0;
}