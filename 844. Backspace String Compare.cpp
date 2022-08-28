class Solution
{
public:
    bool backspaceCompare(string s, string t)
    {
        stack<char> st, stt;
        for (auto c : s)
        {
            if (c == '#')
            {
                if (!st.empty())
                    st.pop();
            }
            else
            {
                st.push(c);
            }
        }
        for (auto c : t)
        {
            if (c == '#')
            {
                if (!stt.empty())
                    stt.pop();
            }
            else
            {
                stt.push(c);
            }
        }

        return st == stt;
    }
};