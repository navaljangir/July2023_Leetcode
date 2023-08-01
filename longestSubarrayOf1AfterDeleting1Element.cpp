class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int prevOneCount =0 ; 
        int zeroCount = 0 ; 
        int nextOneCount =0;
        int maxi = 0; 
        for(int i =0 ; i <nums.size();i++){
                while(i<nums.size() && nums[i]==1){
                    prevOneCount++;
                    i++;
                }
                if(prevOneCount==nums.size()){
                    return prevOneCount-1;
                }
                while(i<nums.size() && nums[i]==0){
                    zeroCount++;
                    i++;
                }
                if(zeroCount!=1){
                    maxi=max(maxi , prevOneCount);
                    prevOneCount=0;
                    zeroCount =0 ; 
                }else{
                    while(i<nums.size() && nums[i]==1){
                        nextOneCount++;
                        i++;
                    }
                    zeroCount=0;
                    maxi= max(maxi , nextOneCount+prevOneCount);
                    prevOneCount = nextOneCount;
                    nextOneCount=0;
                }
                i=i-1;
        }
        
       return maxi;
    }
};
