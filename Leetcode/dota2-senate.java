class Solution {

    public String solve(String updatedString, int index) {
        if(decideWin(updatedString)) {
            return updatedString.charAt(0) == 'R' ? "Radiant" : "Dire";
        }

        
        for(int j = index; j < updatedString.length() + index; j++){

            int i = (j+updatedString.length()) % updatedString.length();
            if(updatedString.charAt(i) != updatedString.charAt(index)) {
                return solve(updatedString.subStr(0,i) + updatedString.subStr(i+1), index+1);
            }
        }
        
    }
    public String predictPartyVictory(String senate) {
        
    }
}