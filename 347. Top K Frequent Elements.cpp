vector<int> topKFrequent(vector<int> &nums, int k)
{
    unordered_map<int, int> map;
    priority_queue<pair<int, int>> q;
    for (int x : nums)
    {
        map[x]++;
    }
    vector<int> output;
    for (auto x : map)
    {
        q.push(make_pair(x.second, x.first));
    }
    while (q.size() && k)
    {
        output.push_back(q.top().second);
        k--;
        q.pop();
    }
    return output;
}