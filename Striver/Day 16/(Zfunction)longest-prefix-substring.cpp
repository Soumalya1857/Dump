class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        
//         int size = s.length();
//         int low = 0, high = size-1;
        
//         while(low <= high)
//         {
//             int mid = (low+high)>>1;
//             if(isPossible(s,mid))
//             {
                
//             }
//         }
        
        // kmp algo
        // probably can be done with Robin karp also
        
        // calculate lps[0....s.length()]
        
        vector<int> lps(s.length(),0);
        int i=0,j=0;
        
        lps[0] = 0; // by defination
        /*
        while(i<s.length())
        {
           
           j = lps[i-1]; // (upto 0...i-1 how much lps i have got...s[j] will point to the next char)
                        // ex: ABCDABC => we are at index 5(i.e B) and lps[i-1] will be 1
                        // we are assigning j to 1 => s[j] is pointing to B and we are also going to match B
            
            if(s[i] == s[j]) {j++; lps[i]=j; i++;}
            
            // not matched ABCDAC => lps[4(A)] = 1 and the next char doesn't match with index 1
            else {
                while(j != 0 && s[i]!=s[j])
                    j = lps[j-1]; // so lets say the string abcdab abcdab c
                                    // the lps would be     000012 123456 3
                                    // how will we get the last 3?
                                    // so last e our i will be at c and j will be at 6th index i.e a
                                    // clearly not a match...so now we want to move back to the part where we
                                    // last got the 
            }
        }
        */
        
        i=1; // https://www.youtube.com/watch?v=GTJr8OvyEVQ&t=498s
        while(i<s.length())
        {
           if(s[i] == s[j])
            {
                // put whatever the value is stored in j and +1
                lps[i] = j+1;
                j++;
                i++;
            }
            else 
            {
                if(j != 0) // we have some string matched and now getting a mismatch
                            // start comparing with last matched data + 1
                {
                    j = lps[j-1]; // index is 0based so no need to +1 => automatically point to next char which needs
                                    // to be matched;
                }
                else
                {
                    // we haven't match anything previously
                    lps[i] = 0;
                    i++;
                }
            }
        }
        
        // for(int i=0;i<s.length();i++) cout << lps[i] << " ";
        // cout << "\n";
        
        int len = lps[s.length()-1];
        // If there exist a suffix which is also prefix AND
        // Length of the remaining substring divides total
        // length, then str[0..n-len-1] is the substring that
        // repeats n/(n-len) times (Readers can print substring
        // and value of n/(n-len) for more clarity.
        
      
        if(len>0 && s.length() % (s.length()-len) == 0) return true;
        else return false;
        
    }
};