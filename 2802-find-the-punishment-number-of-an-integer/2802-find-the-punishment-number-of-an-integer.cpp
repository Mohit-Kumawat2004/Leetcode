class Solution {
public:
    int num;
    string s;

    bool rec(int i=0,int rem=0,int sm=0){
        if(i==s.size())
            return sm+rem==num;
     
        rem=rem*10+s[i]-'0';
        return rec(i+1,0,sm+rem)|rec(i+1,rem,sm);
    }

    int punishmentNumber(int n) {
        int ans=0;
        for(int i=1;i<=n;i++){
            num=i,s=to_string(i*i);

            ans+=rec()*i*i;
        }

        return ans;
    }
};