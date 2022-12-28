class Twitter
{
public:
    Twitter() = default;
    void postTweet(int userId, int tweetId)
    {
        tweets[userId].emplace_back(++order, tweetId);
    }
    vector<int> getNewsFeed(int userId)
    {                                                 // Multiways method
        typedef pair<size_t, pair<int, size_t>> Pair; // <order, <userId or followeeId, index>>
        vector<int> ret;
        priority_queue<Pair> pq;
        if (tweets.find(userId) != tweets.cend())
            pq.emplace(tweets[userId].back().first, make_pair(userId, tweets[userId].size() - 1));
        if (followers_st.find(userId) != followers_st.cend())
        {
            for (auto f : followers_st[userId])
            {
                if (tweets[f].empty())
                    continue;
                pq.emplace(tweets[f].back().first, make_pair(f, tweets[f].size() - 1));
                if (pq.size() > 10)
                    pq.pop();
            }
        }
        while (ret.size() < 10 && !pq.empty())
        {
            auto &top = pq.top();
            int id = top.second.first, i = top.second.second;
            ret.push_back(tweets[id][i].second);
            pq.pop();
            if (i > 0)
                pq.emplace(tweets[id][i - 1].first, make_pair(id, i - 1));
        }
        return ret;
    }
    void follow(int followerId, int followeeId)
    {
        if (followerId != followeeId)
            followers_st[followerId].insert(followeeId);
    }
    void unfollow(int followerId, int followeeId)
    {
        auto finder = followers_st.find(followerId);
        if (finder == followers_st.end())
            return;
        finder->second.erase(followeeId);
        if (finder->second.empty())
            followers_st.erase(followerId);
    }

private:
    size_t order = 0;
    unordered_map<int, vector<pair<size_t, int>>> tweets; // <userId, vector<pair<order, tweetId>>>
    unordered_map<int, unordered_set<int>> followers_st;  // <followerId, unordered_set<followeeId>>
};