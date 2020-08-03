class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        reverse(digits.begin(), digits.end());
        int carry = 0;
        bool flag = false;
        
        digits[0] = digits[0] + 1;
        if(digits[0] == 10)
        {
            digits[0] = 0;
            carry = 1;
            if(digits.size() == 1) flag = true;
            for(int i=1;i<digits.size();i++)
            {
                digits[i] = digits[i] + carry;
                carry = 0;
                if(digits[i] == 10)
                {
                    digits[i] = 0;
                    carry = 1;
                    if(i == digits.size()-1) flag = true;
                }
                
            }
            if(flag) digits.push_back(1);
        }
        
        reverse(digits.begin(), digits.end());
        return digits;        
    }
};

