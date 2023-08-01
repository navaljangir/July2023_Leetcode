class Solution {
public:
int getMax(string answerKey , int k , char ans){
    int j =0 ; 
    int maxi =0;
        for(int i = 0 ; i<answerKey.length();i++){
                if(answerKey[i]!=ans){
                    k--;
                }
                while(k<0){
                    if(answerKey[j]==ans){
                        j++;
                    }else{
                    j++;
                    k++;
                    }
                }
            maxi= max(maxi , i-j+1);
        }
        return maxi;
}
    int maxConsecutiveAnswers(string answerKey, int k) {
        int trueMax= getMax(answerKey , k , 'T');
        int falseMax = getMax(answerKey , k ,' F');
        return max(trueMax , falseMax);
    }
};
