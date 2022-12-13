int longestPalindrome(int n, string s) {
    unordered_map<char, int> mp;
    for(auto i : s) {
        mp[i]++;
    }
    int result = 0;
    bool oddCount = false;
    for(auto i : mp) {
        if(i.second % 2 == 0) {
            result += i.second;
        }
        else {
            oddCount = true;
            result += i.second - 1;
        }
    }
    if(oddCount) result++;
    return result;
}