#include<bits/stdc++.h>
using namespace std;



pair<bool,int> isPossible(string s, unordered_map<char, int> &t, int window){

    unordered_map<char, int> freq;

    for(int i=0; i<s.length(); i++){

        if(i<window){
            freq[s[i]]++;
            continue;
        }

        bool flag = true;

        for(auto entry : t){
            char ch = entry.first;
            int occur = entry.second;

            if(freq[ch] < occur){
                flag = false;
                break;
            }
        }

        if(flag == true) return make_pair(true, i-window+1);



        freq[s[i]]++;
        freq[s[i-window]]--;
    }


    return make_pair(false, NULL);


}


string minSubstring(string s, string t){

    int low = 0, high = s.length();
    unordered_map<char, int> mp;

    for(char ch : t){
        mp[ch]++;
    }

    while(low < high){
        int mid = (low + high)/2;

        pair<bool, int> present = isPossible(s, mp, mid);

        if(present.first == true){
            minWindow = min(minWindow, mid);
            currStartIndex = present.second;
            high = mid - 1;
        }else{
            low = mid+1;
        }
    }

}


int pow(int base, int power){

    if(power == 1) return base;
    int result = 1;

    while(power > 1){
        if(power % 2 == 0) result *= base;

        power /= 2;
        result *= result;
    }

    return result;
}

int main(){

}