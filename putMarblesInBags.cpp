class Solution {
public:
    long long putMarbles(vector<int>& weights, int k) {
        if(k==1){
            return 0;
        }
        priority_queue<int, vector<int> , greater<int>> q;
        priority_queue<int> q2;
        for(int i =0 ; i<weights.size();i++){
            if(i<weights.size()-1){
                q.push(weights[i+1]+weights[i]);
                q2.push(weights[i+1]+weights[i]);
            }
        }
        long long maxi = 0;
        long long mini = 0 ;
        for(int i =0 ; i<k-1;i++){
            maxi+=q2.top();
            q2.pop();
            cout<<q.top()<<" ";
            mini+=q.top();
            q.pop();
        }
        return maxi-mini;
    }
};
