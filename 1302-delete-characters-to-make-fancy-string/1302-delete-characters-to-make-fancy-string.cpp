class Solution {
public:
     string makeFancyString(string s) {
        //still O(n^2) because the erase function takes O(n) in worst case scene
        //vector.erase(vector.begin() + i);

        int n = s.length();
        vector<char>ans; 
        ans.push_back(s[0]);
        char prev = s[0];
        int count = 1;

        for(int i=1; i<n; i++){
            if(prev!=s[i]) {
                prev = s[i];
                count=1;
                ans.push_back(s[i]);
            }
            else{
                count++;
                if(count<3) {
                    ans.push_back(s[i]);
                }
            }
        }
        // Convert the vector to string
        return string(ans.begin(), ans.end()); 
    }
};