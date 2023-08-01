class Solution {
public:
    int largestVariance(string s) {
        vector<int> v (26,0);
        int ans =0 ;
        for(int i = 0 ; i<s.length(); i++){
            v[s[i]-'a']++;
        }
        for(char ch1 = 'a' ; ch1<='z'; ch1++){
            for(char ch2 = 'a'; ch2<='z' ; ch2++){
                if(ch1==ch2 || v[ch1-'a']==0 || v[ch2-'a']==0){
                    continue;
                }
                for(int i =1 ;i<=2;i++){
                    int count1 =0; 
                    int count2= 0;
                    for(int i = 0; i<s.length();i++){
                        if(s[i]==ch1){
                            count1++;
                        }
                        if(s[i]==ch2){
                            count2++;
                        }
                        if(count1<count2){
                            count1=0;
                            count2=0;
                        }
                        if(count1>0 && count2>0){
                            ans= max(ans, count1-count2);
                        }
                    }
                    reverse(s.begin() , s.end());
                }
            }
        }
        return ans;
    }
};
