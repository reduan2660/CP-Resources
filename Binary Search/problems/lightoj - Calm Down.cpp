// https://lightoj.com/problem/calm-down

#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
double pi = acos(-1);

// AC
double bisection(double R, double n)
{
    double begin=0, end=R, r;
    double rs, rl, a, b, A, B;
    if(n == 1) return R;
    if(n == 2) return R/2.0;

    while(end-begin >= .00000001){
        r = (begin+end)/2.0;

        A = (2.0*pi) / n;
        B = (pi - A)/2.0;

        a = 2.0*r;
        b = rs = a * ( sin(B) / sin(A) );
        rl = rs + r;

        if(rl == R) break;
        else if(rl > R) end = r;
        else begin = r;
    }

    return r;
}

// AC
double solve(double R, double n)
{
    return (R * sin(pi / n * 1.0)) / (1 + sin(pi / n * 1.0));
}

int main()
{
    int T; cin >> T;

    for(int t=1; t<=T; t++){

        double r;
        int n;
        cin >> r >> n;

        double res = bisection(r,n);
        // double res = solve(r,n);
        printf("Case %d: %.6lf\n", t, res);
    }
    return 0;
}