#include<bits/stdc++.h>
using namespace std;

void RobinKarp(string text, string pattern)
{
    int base = 26;
    // prints all the occurences of pattern in text

    // hash of pattern int(ch)
    long long patternHash = 0;
    for(int i=0;i<pattern.length();i++)
    {
        // using base 26
        patternHash += int(pattern[i]) * pow(base,i);
    }


    // calculate first hash for test
    long long rollingHash = 0;
    for(int i=0;i<pattern.length();i++) rollingHash += int(text[i]) * pow(base,i);

    if(rollingHash == patternHash) cout<<"Pattern found from: 0 to " << pattern.length()-1 << endl; 

    for(int i=pattern.length(); i<text.length();i++)
    {
        rollingHash = ((rollingHash - int(text[i-pattern.length()]))/26) + int(text[i])*pow(base,pattern.length()-1);
        if(rollingHash == patternHash) cout<<"Pattern found from: "<< (i-pattern.length()+1) << " to " << i << endl; 
    }
}

int main()
{
    string text = "aaaaa";
    string pattern = "aaa"; // ans will be yes
    RobinKarp(text, pattern);
    return 0;
}