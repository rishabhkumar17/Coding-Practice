#include <bits/stdc++.h>
using namespace std;

class Stack
{
private:
    int *arr;
    int size;
    int t;

public:
    Stack()
    {
        size = 1000000;
        t = -1;
        arr = new int[size];
    }

    void push(int x);
    void pop();
    int top();
    bool empty();
};

void Stack::push(int x)
{
    t++;
    arr[t] = x;
}

void Stack::pop()
{
    if (t == -1)
    {
        t = -1;
    }
    else
    {
        t--;
    }
}

int Stack::top()
{
    return arr[t];
}

bool Stack::empty()
{
    return t == -1;
}

class minStack
{

    int min = -1;
    Stack st;

public:
    int findMin()
    {
        if (st.empty())
        {
            return -1;
        }
        return min;
    }

    void push(int val)
    {
        if (st.empty())
        {
            min = val;
            st.push(val);
        }
        else if (val < min)
        {

            st.push(2 * val - min);
            min = val;
        }
        else
            st.push(val);
    }

    void pop()
    {
        if (st.empty())
        {
            min = -1;
        }
        int t = st.top();
        st.pop();
        if (t < min)
        {
            min = 2 * min - t;
        }
    }
};

int main()
{
    int n, m, t;
    cin >> t;

    minStack S;

    while (t--)
    {
        int ch;
        cin >> ch;
        if (ch == 1)
        {
            cin >> n;
            S.push(n);
        }
        else if (ch == 2)
            S.pop();
        else
            cout << S.findMin() << endl;
    }
}
