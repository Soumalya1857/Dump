// https://leetcode.com/discuss/interview-question/5131934/google-screening-question


class Solution{

    public:

        vector<int> calDigits(int num){
            vector<int> ans;
            while(num > 0){
                int d = num%10;
                num /= 10;
                ans.push_back(d);
            }

            return ans.reverse();
        }

        vector<int> containedNumbers(vector<int> &arr, int k){
            vector<int> ans;

            int lastVisitedOfPrevVal= -1;

            for(int i=0; i<arr.size(); i++){
                int candidateForCNumber = -1;
                int num = arr[i];
                vector<int> digits = calDigits(num);


                for(int j=0; j<digits.size(); j++){
                    if(j==0){
                        if(digits[0] != lastVisitedOfPrevVal && lastVisitedOfPrevVal != -1){
                            ans.push_back(lastVisitedOfPrevVal);
                            candidateForCNumber = digits[0];
                        } else if(lastVisitedOfPrevVal == -1){
                            candidateForCNumber = digits[0];
                        }
                        continue;
                    }

                    if(digits[j] != candidateForCNumber && digits[i] != lastVisitedOfPrevVal){
                        if(candidateForCNumber != -1){
                           ans.push_back(candidateForCNumber);
                        }


                        candidateForCNumber = digits[j];

                    }
                }

                lastVisitedOfPrevVal = digits[digits.size()-1];
            }

            return ans;
        }
}