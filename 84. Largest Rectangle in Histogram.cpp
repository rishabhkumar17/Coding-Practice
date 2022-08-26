class Solution
{
public:
    int largestRectangleArea(vector<int> &heights)
    {

        int ans = 0;
        heights.push_back(0);
        vector<int> index;

        for (int i = 0; i < heights.size(); i++)
        {
            while (index.size() > 0 && heights[index.back()] >= heights[i])
            {
                int height = heights[index.back()];
                index.pop_back();

                int sidx = index.size() > 0 ? index.back() : -1;
                if (height * (i - sidx - 1) > ans)
                    ans = height * (i - sidx - 1);
            }
            index.push_back(i);
        }
        return ans;
    }
};