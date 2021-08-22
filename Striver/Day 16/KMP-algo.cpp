class Solution {
    public int strStr(String haystack, String needle) {
        int n1=haystack.length();
        int n2=needle.length();
        if(n2==0)
            return 0;
        if(n1==0||n2>n1)
            return -1;
        int lps[]=new int[n2]; // This is called Longest Prefix which is also a proper suffix.
        //Proper suffix means that in "ABC"- Proper suffixes are "C","BC" and ""(empty). ABC is not included.
        int j=0;
        int i=1;
        while(i<n2){ 
            if(needle.charAt(i)==needle.charAt(j)){
                lps[i]=j+1;
                i++;
                j++;
            }
            else{
                if(j!=0){
                    j=lps[j-1];
                }
                else{
                    lps[i]=0;
                    i++;
                }
            }
        }
        i=0;
        j=0;
		//This is the matching Part. Here we will only backtrack pointer j pointing to the pattern and not pointer i which is pointing to the text.
        while(i<n1&&j<n2){
            if(haystack.charAt(i)==needle.charAt(j)){
                i++;
                j++;
            }
            else{
                if(j!=0){
                    j=lps[j-1];
                }
                else{
                    i++;
                }
            }
        }
        if(j==n2){
            return i-n2;
        }
        return -1;
    }

    // prb: https://leetcode.com/problems/implement-strstr/
    // son: https://leetcode.com/problems/implement-strstr/discuss/690147/knuth-morris-pratt-pattern-searching-algorithm