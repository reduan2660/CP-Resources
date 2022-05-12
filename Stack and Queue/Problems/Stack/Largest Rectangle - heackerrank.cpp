#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'largestRectangle' function below.
 *
 * The function is expected to return a LONG_INTEGER.
 * The function accepts INTEGER_ARRAY h as parameter.
 */

long largestRectangle(vector<int> h) {
    long n = h.size();
    
    stack<long> ls, rs;
    long l[n], r[n];

    for(long i=0; i<n;i++){
        while(1){
            if(ls.empty()){
                ls.push(i);
                l[i] = -1;
                break;
            }
            else if(h[ls.top()] < h[i]){
                l[i] = ls.top();
                ls.push(i);
                break;
            }
            else ls.pop();
        }
    }

    for(long i=n-1; i>=0;i--){
        while(1){
            if(rs.empty()){
                rs.push(i);
                r[i] = n;
                break;
            }
            else if(h[rs.top()] < h[i]){
                r[i] = rs.top();
                rs.push(i);
                break;
            }
            else rs.pop();
        }
    }

    long maxArea=0, area = 0;
    for(long i=0; i<n; i++){
        area = h[i] * (r[i] -1 - l[i]);
        // cout << h[i] <<" " << l[i] << " " << r[i] << " " << area << endl;
        maxArea = max(maxArea, area);
    }

    cout << maxArea << endl;
    return maxArea;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string n_temp;
    getline(cin, n_temp);

    int n = stoi(ltrim(rtrim(n_temp)));

    string h_temp_temp;
    getline(cin, h_temp_temp);

    vector<string> h_temp = split(rtrim(h_temp_temp));

    vector<int> h(n);

    for (int i = 0; i < n; i++) {
        int h_item = stoi(h_temp[i]);

        h[i] = h_item;
    }

    long result = largestRectangle(h);

    fout << result << "\n";

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}

vector<string> split(const string &str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}
