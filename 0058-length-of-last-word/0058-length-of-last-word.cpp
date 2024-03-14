class Solution {
public:
    int lengthOfLastWord(string s) { 
        int cnt = 0;
        for(int i=s.size()-1;i>=0;--i)
        {
            if(s[i] == ' ' && cnt > 0) 
                return cnt;
            if(s[i] != ' ') 
                cnt++;
        }
        return cnt;
    }
};

       //Another approach using length and tail
        /*int len = 0;
        int tail = s.length() - 1;
        while (tail >= 0 && s[tail] == ' ') 
            tail--;
        while (tail >= 0 && s[tail] != ' ') 
        {
            len++;
            tail--;
        }
        return len;*/