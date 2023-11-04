#include<bits/stdc++.h>
using namespace std;

int targetNumber(int num){
    return num + num % 10;
}

int check(int num){
    if(num%5 == 0) return 3; // 3rd type

    if(num == 1 || num == 2 || num == 4 || num == 8) return 1;
    if(num == 3 || num == 6 || num == 7 || num == 9) return 2;
    num = num + num % 10;
    num /= 10;
    if(num%2 == 1) return 2;
    else return 1;
}

void solve(int n, vector<int>& arr){
    // group a , group b or group5
    if ( n==1) {cout << "YES\n"; return;}

    int groupA = 0, groupB = 0, group5 = 0;
    vector<int>group; // for 5th group

    for(int i=0;i<n;i++){
        int control = check(arr[i]);
        if(control == 1) groupA++;
        else if(control == 2) groupB++;
        else if (control == 3) group.push_back(arr[i]);
    }

    cout << "groupA: " << groupA << " groupB: " << groupB << " group5: "<< group.size() << endl;

    if(group.size() >= 1 && (groupA || groupB)!=0) {cout << "NO\n"; return;};
    if(group.size() !=0 && groupA == 0 && groupB == 0) {
        int target = targetNumber(group[0]);
        for(int i=1; i<group.size(); i++){
            if(target != targetNumber(group[i])){
                cout << "NO\n";
                return;
            }
        }
        cout << "YES\n"; return;
    }

    if ( groupA == 0 && groupB != 0) {cout << "YES\n"; return; };
    if ( groupB == 0 && groupA != 0) { cout << "YES\n"; return; } ;


}

int main(){

    int tc;
    cin >> tc;
    while(tc--){
        int n;
        cin >> n;
        vector<int> arr(n);
        for(int i=0;i<n;i++) cin >> arr[i];
        solve(n, arr);
    }
    return 0;
}

// https://codeforces.com/problemset/problem/1714/E

/*Let's see which remainders modulo 10 change into which ones.

If the array contains a number divisible by 10, then it cannot be changed. 
If there is a number that has a remainder of 5 modulo 10, then it can only be replaced once.

Thus, if the array contains a number divisible by 5, 
then we apply this operation to all elements of the array once and check that all its elements are equal.

The remaining odd balances (1,3,7,9) immediately turn into even ones. 
The even remainders (2,4,6,8) change in a cycle, while the array element increases by 20 in 4 operations. 
Thus, we will apply the operation to each element of the array until its remainder modulo 10 becomes, f
or example, 2, and then check that the array does not contain both remainders 2 and 12 modulo 20.*/

// by solution
