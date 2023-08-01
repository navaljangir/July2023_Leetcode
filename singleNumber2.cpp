class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans = 0 ; 
        for(int i = 0 ; i<32;i++){
            int add = 0;
            for(int j = 0;  j<nums.size();j++){
                if(((nums[j]>>i)&1) ==1){
                add++;
                }
            }
            add = add%3;
            if(add!=0){
                ans = ans | (add)<<i;
            }
        }
        return ans;
    }
};
