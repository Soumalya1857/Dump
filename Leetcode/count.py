# def support( s):
#     if s in "aeiou":
#         return 1
#     else:
#         return 0
        
# def maxVowels( s: str, k: int) -> int:
#     maxi = -1
#     for i in range(len(s)-k+1):
#         print(i)
#         temp = s[i:i+k]
#         cnt = 0
#         for j in range(k):
#             cnt += support(temp[j])

#         print(temp)
#         #if(cnt > maxi): print(temp)    
#         maxi = max(maxi,cnt)
        
#     return maxi

# # "weallloveyou"
# # 7

# print(maxVowels("ibpbhixfiouhdljnjfflpapptrxgcomvnb",33))


class Solution:
    def support(self, s):
        if s in "aeiou":
            return 1
        else:
            return 0
        
    def maxVowels(self, s: str, k: int) -> int:
        maxi = -1
        cnt = 0
        temp = s[:k]
        for i in range(k):
            cnt += self.support(temp[i])
        #bla = cnt
        for i in range(len(s)-k+1):
            
            cnt += self.support(s[i+k-1])
            cnt -= self.support(s[i-1])
            print(s[i:i+k])
            
            maxi = max(maxi,cnt)
        return maxi


# Solution().maxVowels("ibpbhixfiouhdljnjfflpapptrxgcomvnb",33)
#print(Solution().maxVowels("ibpbhixfiouhdljnjfflpapptrxgcomvnb",33))

print(Solution().maxVowels("ramadan",2))