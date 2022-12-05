bool backspaceStringCompare(string S, string T)
{
    stack<char> stackS;
    for (int i = 0; i < S.size(); i++)
    {
        if (S[i] == '#')
        {
            if (!stackS.empty())
            {
                stackS.pop();
            }
        }
        else
        {
            stackS.push(S[i]);
        }
    }
    stack<char> stackT;
    for (int i = 0; i < T.size(); i++)
    {
        if (T[i] == '#')
        {
            if (!stackT.empty())
            {
                stackT.pop();
            }
        }
        else
        {
            stackT.push(T[i]);
        }
    }
    return stackS == stackT;
}