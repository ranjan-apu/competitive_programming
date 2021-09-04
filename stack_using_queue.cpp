#include<iostream>
#include<queue>
using namespace std;
class Stack
{
private:
    int cur;
    queue<int>q1;
    queue<int>q2;
public:
    Stack()
    {
        cur=0;
    }
    void push(int x)
    {
        cur++;
        q2.push(x);
        while(!q1.empty())
        {
            q2.push(q1.front());
            q1.pop();
        }
        queue<int> temp;
        temp=q1;
        q1=q2;
        q2=temp;
    }
    void pop()
    {
        if(q1.empty())
            return;
        cur--;
        q1.pop();
    }
    int top()
    {
        return (q1.front());
    }
    int size()
    {
        return cur;
    }
    void push_one(int x)
    {
        cur++;
        q1.push(x);
        for(int i=0;i<q1.size()-1;i++)
        {
            q1.push(q1.front());
            q1.pop();
        }
    }

};
int main()
{
    Stack s;
    s.push_one(1);
    s.push_one(3);
    s.push_one(9);
    s.push_one(14);
    s.pop();
    s.push_one(657);
    cout<<s.top()<<endl;
    s.pop();
    s.pop();
    cout<<s.top()<<endl;
    return 0;
}
