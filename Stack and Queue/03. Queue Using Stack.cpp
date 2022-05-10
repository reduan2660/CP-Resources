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
            return ara[top];
    }

    void disp(){
        for(int i=0;i < top; i++){
            cout << ara[i].n << " ";
        }
    }

    void rdisp(){
        for(int i=top-1;i >= 0; i--){
            cout << ara[i].n << " ";
        }
    }
};

struct Queue
{
    Stack stack1, stack2;

    void enqueue(int _x)
    {
        stack1.push(_x);
    }

    data dequeue()
    {
       if(stack2.empty()){
           
            while(! stack1.empty()){
                data x = stack1.pop();
                stack2.push(x.n);
            }
        }
        return stack2.pop();
    }

    void disp()
    {
        cout << " : ";
        stack2.rdisp(); stack1.disp();
        cout << endl;
    }

};

int main()
{
    Queue q;
    q.enqueue(1); q.enqueue(2); q.enqueue(3);
    q.disp();

    q.dequeue();
    q.disp();

    return 0;
}