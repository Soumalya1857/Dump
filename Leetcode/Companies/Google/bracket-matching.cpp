/**
 * @file bracket-matching.cpp
 * 
 * Problem statement is given an equation with nested brackets (string) with Variables, solve the equation
 * Ex: Simpler version - No nested brackets
 * (A+B) - (B+C) + A = 2*A -C
 * 
 * next step => nested brackets are allowed
 * 
 * @author your name (you@domain.com)
 * 
 */

#include<bits/stdc++.h>
#define null '*'
using namespace std;
/**
 * @brief 
 * need to identify the sign before a bracket opens or ( sign
 * if there's no sign before a ( => add one
 * 
 * 
 * @param equation string
 * @return string 
 */

// (A+B) - (B+C) + A 

// +(+A +B) - (+B + C) + A => actually don't need this intermediate representation

// +A +B -B -C + A


char calculateFinalSign(char currentSign, char signOutofBracket){
    if(currentSign == '+' && signOutofBracket == '+') return '+';
    else if(currentSign == '+' && signOutofBracket == '-') return '-';
    else if(currentSign == '-' && signOutofBracket == '+') return '-';
    else if(currentSign == '-' && signOutofBracket == '-') return '+';
    else return null;
}

/**
 * @brief 
 * stack =>  -
 * currentSign = -
 * map=> 
 * A = 1 1 -1
 * B = -1 -1 -1 +1
 * C = 1 1 1
 * 
 * (A - (B-C - (A-B) + B) + C) + C - (A-B)
 * => (A-B+C+A-B-B+C+C-A+B) 
 * => A -2B + 3C
 * 
 * @param equation 
 * @return string 
 */

string solve_with_nested_brackets(string equation){

    stack<char> sign; // what is the perceived sign for that particular variable
    sign.push('+');
    char currentSign = '+';
    unordered_map<char, int> count;

    string result = "";

    currentSign = '+';
    for(int i=0; i<equation.length(); i++){
        if(equation[i] == ' ') continue;

        if(equation[i] == '+' || equation[i] == '-'){
            currentSign = equation[i];
        }

        if(equation[i] == '('){
            sign.push(calculateFinalSign(currentSign, sign.top()));
            currentSign = '+';
        }

        if(equation[i] >= 'A' && equation[i] <= 'Z'){
            char finalSign = calculateFinalSign(currentSign, sign.top());
            if(finalSign == '+'){
                count[equation[i]] += 1;
            }else{
                count[equation[i]] -= 1;
            }
        }

        if(equation[i] == ')'){
            sign.pop();
            currentSign = '+';
        }
    }

    for(auto it = count.begin(); it!= count.end(); it++){
        if(it->second != 0){
            if(it->second > 0) result += '+';
            result += to_string(it->second);
            result += it->first;
            result += " ";
        }
   }

   return result;
}

string solve_with_no_nested_brackets(string equation){

    string result = "";

   stack<pair<char,char>> s; // sign, character

   char signOutofBracket = null;
   char currentSign = null;

   for(int i=0; i<equation.length(); i++){

        if(equation[i] == ' '){
            continue;
        }

        if(equation[i] == '+' || equation[i] == '-'){
            signOutofBracket = equation[i];
        }

        if(equation[i] == '('){
            if(signOutofBracket == null){
                signOutofBracket = '+';
            }
            if(currentSign == null){
                currentSign = '+';
            }

            i++;

            while(equation[i] != ')' ){
                if(equation[i] >= 'A' && equation[i] <= 'Z'){
                    char sign = calculateFinalSign(currentSign, signOutofBracket);
                    s.push(make_pair(sign, equation[i]));
                } else if(equation[i] == '+' || equation[i] == '-'){
                    currentSign = equation[i];
                }

                i++;
            }

            currentSign = null;
            signOutofBracket = null; // resetting the values
        }

        if(equation[i] >= 'A' && equation[i] <= 'Z'){
            s.push(make_pair(signOutofBracket, equation[i]));
            signOutofBracket = null;
        }
   }
    

   unordered_map<char, int> mp;

   while(!s.empty()){
        char sign = s.top().first;
        char val = s.top().second;
        s.pop();

        if(sign == '+') mp[val] += 1;
        else mp[val] -= 1;
   }

   for(auto it = mp.begin(); it!= mp.end(); it++){
        if(it->second != 0){
            if(it->second > 0) result += '+';
            result += to_string(it->second);
            result += it->first;
            result += " ";
        }
   }

   return result;
}

int main(){

    string equation = "(A+B)-(B+C)+A - (-G-I) +(-K+G+H-B) + (H)";
    cout << solve_with_no_nested_brackets(equation) << endl;


    string equation2 = "C + (E-U) - (A - (B-C - (A-B) + B) + C) + C - (A-B)";
    cout << solve_with_nested_brackets(equation) << endl;
    return 0;
}