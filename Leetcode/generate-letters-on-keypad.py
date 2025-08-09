class Solution:
    
    def makeCombination(self, digits, output, res):
        if(len(digits) == 0): 
            output.append(res)
            return
        
        if(digits[0] == '2'):
            
            self.makeCombination(digits[1:], output, res+'a')
            self.makeCombination(digits[1:], output, res+'b')
            self.makeCombination(digits[1:], output, res+'c')
            
        if(digits[0] == '3'):
            
            self.makeCombination(digits[1:], output, res+'d')
            self.makeCombination(digits[1:], output, res+'e')
            self.makeCombination(digits[1:], output, res+'f')
        
        if(digits[0] == '4'):
            
            self.makeCombination(digits[1:], output, res+'g')
            self.makeCombination(digits[1:], output, res+'h')
            self.makeCombination(digits[1:], output, res+'i')
        
        if(digits[0] == '5'):
            
            self.makeCombination(digits[1:], output, res+'j')
            self.makeCombination(digits[1:], output, res+'k')
            self.makeCombination(digits[1:], output, res+'l')
        
        if(digits[0] == '6'):
            
            self.makeCombination(digits[1:], output, res+'m')
            self.makeCombination(digits[1:], output, res+'n')
            self.makeCombination(digits[1:], output, res+'o')
        
        if(digits[0] == '7'):
            
            self.makeCombination(digits[1:], output, res+'p')
            self.makeCombination(digits[1:], output, res+'q')
            self.makeCombination(digits[1:], output, res+'r')
            self.makeCombination(digits[1:], output, res+'s') 
        
        if(digits[0] == '8'):
            
            self.makeCombination(digits[1:], output, res+'t')
            self.makeCombination(digits[1:], output, res+'u')
            self.makeCombination(digits[1:], output, res+'v')
        
        if(digits[0] == '9'):
            
            self.makeCombination(digits[1:], output, res+'w')
            self.makeCombination(digits[1:], output, res+'x')
            self.makeCombination(digits[1:], output, res+'y')
            self.makeCombination(digits[1:], output, res+'z') 
        
    
    def letterCombinations(self, digits: str) -> List[str]:
        if(len(digits) == 0): return ""
        
        output = []
        res = ""
        self.makeCombination(digits, output, res)
        return output
        
# question: https://leetcode.com/problems/letter-combinations-of-a-phone-number
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        