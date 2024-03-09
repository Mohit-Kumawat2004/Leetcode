class Solution
{
    public:
  
    vector<long long> nextLargerElement(vector<long long> arr, int n){

    
        stack<long long>st;           //empty stack
        vector<long long> arr2(n);          //result array
        for(int i=n-1;i>=0;i--)             //reverse array solving problem
        {
            while(!st.empty() && st.top()<=arr[i])      //if not empty and top is less than number then delete 
                    st.pop();         //delete all small numbers
                    
            if(st.empty())          //if empty add -1
               arr2[i]=-1;
            else
               arr2[i]=st.top();                   //add next greater element to the result array
               
            
            st.push(arr[i]);       //after that push elements of old array to the stack
        }
         return arr2;             //return result array
        
    }
};
