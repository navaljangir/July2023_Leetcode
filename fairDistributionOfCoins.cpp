class Solution {
public:
    int findMax(vector<int>&v){
        int maxi = INT_MIN;
        for(int i =0 ; i<v.size();i++){
            if(v[i]>maxi){
                maxi = v[i];
            }
        }
        return maxi;
    }
    void solve(int index , int &ans, vector<int>&cookies , vector<int>&cookieBag){
        if(index>=cookies.size()){
            ans = min(ans , findMax(cookieBag));
            return;
        }
        int getCookie = cookies[index];
        for(int i= 0; i<cookieBag.size();i++){
            cookieBag[i] +=getCookie;
            solve(index+1,ans , cookies, cookieBag);
            cookieBag[i]-=getCookie;
        }
    }
    int distributeCookies(vector<int>& cookies, int k) {
        int ans= INT_MAX;
        vector<int> cookieBag(k);
        solve(0 , ans , cookies, cookieBag);
        return ans;
    }
};
