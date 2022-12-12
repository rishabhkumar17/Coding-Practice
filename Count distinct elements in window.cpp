vector<int> countDistinctElements(int n, int b, vector<int> a){
        if(b > n) {
            return {};
        }
        unordered_map<int, int> mp;
        int count = 0;
        for(int i=0; i<b; i++) {
            if(mp[a[i]] == 0) {
                count++;
            }
            mp[a[i]]++;
        }
        vector<int> ans;
        ans.push_back(count);
        for(int i=b; i<n; i++) {
            if(mp[a[i-b]] == 1) {
                count--;
            }
            mp[a[i-b]]--;
            if(mp[a[i]] == 0) {
                count++;
            }
            mp[a[i]]++;
            ans.push_back(count);
        }

        return ans;
}