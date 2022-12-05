class Solution
{
public:
    // Function to find the next greater element for each element of the array.
    vector<long long> nextLargerElement(vector<long long> A, int n)
    {
        // Your code here
        vector<long long> ans(n, -1);
        stack<long long> st;

        for (int i = n - 1; i >= 0; i--)
        {
            while (!st.empty() && A[st.top()] <= A[i])
            {
                st.pop();
            }
            if (!st.empty())
                ans[i] = A[st.top()];

            st.push(i);
        }

        return ans;
    }
};