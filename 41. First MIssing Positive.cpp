class Solution
{
public:
    int firstMissingPositive(vector<int> &nums)
    {
        int res = 1;
        priority_queue<int, vector<int>, greater<int>> pq;
        for (int i = 0; i < nums.size(); i++)
        {
            pq.push(nums[i]);
        }
        while (pq.empty() == false)
        {
            if (pq.top() == res)
            {
                res++;
            }
            pq.pop();
        }
        return res;
    }
};