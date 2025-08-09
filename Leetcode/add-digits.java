class Solution {
    public int addDigits(int num) {
        int ans = 0;
        for(int i = 0; i<10; i++) {
            if(num == 0) break;

            ans += num%10;
            num /= 10;

            if(ans >= 10) {
                ans = ans%10 + ans/10;
            }
        }

        return ans;

    }
}

// https://leetcode.com/problems/add-digits/solutions/

// https://leetcode.com/problems/add-digits/solutions/1754049/easy-o-1-explanation-with-example/

// ======================================

// https://leetcode.com/problems/add-digits/submissions/943178194/

class Solution1 {

    public int addDigits(int num) {
        
        if (num == 0) return 0;
        return num % 9 == 0 ? 9 : num % 9;
    }
}