class Solution {
public:
    bool buddyStrings(string s, string goal) {
        if(s.length()!=goal.length()){
            return false;
        }
        if(s==goal){
            unordered_map<char , int> mp;
            for(int i=0 ; i<s.length();i++){
                mp[s[i]-'a']++;
            }
            for(auto i : mp){
                if(i.second>=2){
                    return true;
                }
            }
            return false;
        }
        map<char ,int > sTrack;
        map<char , int> goalTrack;
        for(int i=0 ; i <s.length();i++){
            sTrack[s[i]-'a']++;
            goalTrack[goal[i]-'a']++;
        }
        if(sTrack!=goalTrack){
            return false;
        }
        int indexEqualCount= 0 ;
        for(int i = 0; i<s.length();i++){
            if(s[i]==goal[i]){
                indexEqualCount++;
            }
        }
        if(indexEqualCount==s.length()-2){
            return true;
        }
        return false;
    }
};
