class Solution {
public:
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        int n = words.size(), m = queries.size();
        vector<int> R(m,0);
        vector<int> wordsBinary(n,0);
        for (int i=0; i<n; ++i) {
            if (isVowel(words[i].front()) && isVowel(words[i].back())) wordsBinary[i] = 1;
        }
        std::partial_sum(wordsBinary.begin(),wordsBinary.end(),wordsBinary.begin());
        for (int i=0; i<m; ++i) {
            int start = queries[i][0], end = queries[i][1];
            int cnt = 0;
            R[i] = (start == 0) ? wordsBinary[end] : wordsBinary[end]-wordsBinary[start-1];
        }
        return R;
    }

    bool isVowel(char c) {
        if (c=='a' || c=='e' || c=='i' || c=='o' || c=='u') return true;
        return false;
    }
};