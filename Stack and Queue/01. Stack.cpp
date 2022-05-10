#include <bits/stdc++.h>
using namespace std;

struct data
{
    int n;

    data(){}
    data(int _n){
        n = _n;
    }
};

struct Stack
{
    int top = 0;
    const static int capacity = 5;
    data ara[capacity];

    bool empty(){
        return top == 0;
    }

    void push(int _x){
        if (top == capacity)
            cout << "Stack Oerflow" << endl;
        else{
            data a(_x);

            ara[top] = a;
            top = top + 1;
        }
    }

    data pop(){
        if (top == 0)
            cout << "Underflow" << endl;
        else
            top = top-1;
            return ara[top + 1];
    }

    void disp(){
        cout << " : ";
        
        for(int i=0;i < top; i++){
            cout << ara[i].n << " ";
        }
        cout << endl;
    }
};



int main()
{
    Stack s;
    s.disp();

    s.push(1); s.push(2); s.push(3);
    s.disp();

    s.pop();
    s.disp();

    s.pop(); s.pop(); s.pop();
    return 0;
}