#include<bits/stdc++.h>
using namespace std;

    // bool isPowerOfFour(int num) {
    //     // if even places contains 1 its power of 4
        
    //     // check odd places not contain 1s including 0
        
    //     if(num == 1) return true;
    //     if((num & 1<<0) == 1 ) return false;
        
    //     for(int i= 1; i%2 == 1 && i < 32; i++)
    //     {
    //         if(i==5) cout << (num & (1<<i)) << "\n";
    //         if((num & 1<<i) == 1) { 
    //             cout <<"i : " << i << endl;
    //             return false;
    //         }
    //     }
        
    //     return true;
        
        
    // }


    bool isPowerOfFour(int num)
    {
        return (num > 0) && (num & (num-1) == 0) &&  (0b1010101010101010101010101010101 & num == num);
    }

int main()
{
    int tc;
    cin >> tc;
    while(tc--)
    {
        int num;
        cin >> num;
        cout << isPowerOfFour(num) << endl;
    }
    return 0;
}