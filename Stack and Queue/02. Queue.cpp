#include <bits/stdc++.h>
using namespace std;

struct data
{
    int n;

    data(){
        n = 0;
    }

    data(int _n){
        n = _n;
    }
};

struct Queue
{
    int head = 0, tail = 0, capacity = 5; // Read 4
    data ara[5];


    void enqueue(int _x){
        if ((head) == (tail + 1)%capacity)
            cout << "Overflow" << endl;
            
        else{
            data x(_x);
            
            ara[tail] = x;
            if (tail == capacity-1)
                tail = 0;
            else tail = tail + 1;
        }
    }

    data dequeue(){
        data x = ara[head];

        if(head == capacity-1)
            head = 0;
        else head = head + 1;

        return x;
    }

    void disp(){
        cout << " : h " << head << " t " << tail << ": ";
        
        if( head < tail){
            for(int i=head; i < tail; i++){
                cout << ara[i].n << " ";
            }
        }
        else{

            for(int i=head; i < (capacity); i++){
                cout << ara[i].n << " ";
            }
            for(int i=0; i < tail; i++){
                cout << ara[i].n << " ";
            }
        }
        cout << endl;
    }
};



int main()
{
    Queue s;
    s.disp();

    s.enqueue(1); s.enqueue(2); s.enqueue(3); s.enqueue(4); s.enqueue(5);
    s.disp();

    s.dequeue();
    s.disp();

    // s.dequeue(); s.dequeue(); s.dequeue();
    // s.disp();

    s.enqueue(6); s.enqueue(7);
    s.disp();

    return 0;
}