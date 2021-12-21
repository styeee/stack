#include <iostream>
using namespace std;
#include <any>

class stack
{
    struct node
    {
        any value;
        node*prev;
    };
    node*self=0;
public:
    void push(const any i)
    {
        self=new node{i,self};
    }

    const any pop()
    {
        if(!self)return 0;
        node*p=self->prev;
        const any v=self->value;
        delete self;
        self=p;
        return v;
    }

     template<typename t>
    const t pop()
    {
        if(!self)return 0;
        node*p=self->prev;
        const any v=self->value;
        delete self;
        self=p;
        return any_cast<const t>(v);
    }
};

int main()
{
    stack s;
    s.push(3);
    s.push(7);
    cout<<s.pop<int>();

    return 0;
}