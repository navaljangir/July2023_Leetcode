class Solution {
public:
void solve(int index , vector<vector<int>>&request  , vector<int>&track , int&ans, int count){
    if(index >=request.size()){
        for(int i= 0 ; i<track.size();i++){
            if(track[i]!=0){
                return;
            }
        }
        ans = max(ans , count);
        return;
        
    }
        track[request[index][0]]--;
        track[request[index][1]]++;
        solve(index+1 , request , track , ans , count+1);
         track[request[index][0]]++;
        track[request[index][1]]--;
        solve(index+1 , request , track , ans ,count);
    
}
    int maximumRequests(int n, vector<vector<int>>& requests) {
        vector<int> employees(n);
        int ans = 0; 
        solve(0 , requests, employees , ans , 0);
        return ans;
    }
};
