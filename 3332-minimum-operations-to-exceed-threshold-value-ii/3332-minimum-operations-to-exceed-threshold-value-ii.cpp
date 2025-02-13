class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        priority_queue<double,vector<double>,greater<double>>pq;
        for(int &num:nums){pq.push(num);}
        int op=0;
        while(pq.size()>1){
            double x = pq.top();
            pq.pop();
            double y = pq.top();
            pq.pop();
            if(x>=k){return op;}
            double n = 2*(double)min(x,y)+(double)max(x,y);
            pq.push(n);
            ++op;
        }
        return op;
    }
};
