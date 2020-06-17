
#include<bits/stdc++.h>
using namespace std;

// string validIPAddress(string IP) {
//         int n = IP.length();
//         string neither = "Neither", v4 = "IPV4", v6 = "IPV6";
//         int i,j, countDot = 0, countColon = 0;
//         bool flag = false;
//         for(i=0;i<n;i++)
//         {
//             if(IP[i] == '.'){ flag = true; countDot++;} // corresponds IPV4
//             else if(IP[i] == ':'){flag = false; countColon++;}// corresponds IPV6
//         }
        
//         if(countDot == 3 && countColon == 0)
//         {
//             // check IPV4
//             j=0;
//             for(i=0;i<3;i++)
//             {
//                 // make number
//                 int countDigit = 0, number=0;
//                 while(IP[j]!= '.' || IP[j]!= '\0')
//                 {
//                     if(IP[j]=='-') return "Neither\n";// negative number
//                     countDigit++;
//                     number = number*10 + (IP[j]-'0');
//                     cout << "j: "<< j << "  IP[j]: "<< ((IP[j]-'0')) << endl;
//                     cout << "Number: " << number << endl; 
                    
//                     j++;
//                 }
//                 if(countDigit > 3) return "Neiher\n";
//                 else if(number > 255) return "Neither\n";
//                 j++;
//             }
//             return "IPV4\n";
//         }
//         else if(countDot == 0 && countColon == 7)
//         {
//             // check IPV6 validity
//             bool dummy = false;
//             return "Ja baba horibol\n";
//         }
//         else
//         {
//             return "Neither";
//         }
//         return neither;
//     }



// string validIPAddress(string IP) {

//     int n = IP.length();
//     int i,j;
//     int countDot = 0, countColon = 0;
//     for(i=0;i<n;i++)
//     {
//         if(IP[i] == '.') countDot++;
//         if(IP[i] == ':') countColon++;
//         if(IP[i] == '-') return "Neither";
//     }
//     //cout << countDot << " "  << countColon << endl;

//     if(countDot == 3 && countColon == 0)
//     {
//         // go for IP check
//         j=0;
//         for(i=0;i<4;i++)
//         {
//             int num = 0,countDigit = 0;
//             while(true)
//             {
//                 if(IP[j] == '.') break;
//                 if(IP[j] == '.') break;
//                 if(IP[j] == '-') break;
//                 if(IP[j] == '\0') break;
//                 if(countDigit == 0 && (IP[j]-'0') == 0) return "Neither";
//                 num = num*10 + (IP[j]-'0');
//                 j++;
//                 countDigit++;
//             }
//             if(num > 255 || num < 0) return "Neither";
//             if(IP[j] == '-') return "Neither";
//             if(countDigit > 3) return "Neither";
//             if(IP[j] == '\0') break;
//             j++;
//         }
//         return "IPV4";
//     }
//     else if(countDot == 0 && countColon == 7)
//     {
//         // go for IPV6
//         int spaceBTColon = 0;
//         for(i=0;i<n;i++)
//         {
            
//             if((IP[i] >= '0'&& IP[i] <='9') || (IP[i] >= 'a' && IP[i] <='f') || (IP[i] >= 'A'&& IP[i] <='F') || IP[i] == ':')
//             {
//                 if(IP[i] == ':')
//                 {
//                     // we need to check the space b/t 2 : should be 4
//                     //cout << spaceBTColon << endl;
//                     if(spaceBTColon == 4) spaceBTColon = 0;
//                     else if(spaceBTColon > 4) return "Neither";
//                     else 
//                     {
//                         // leading zeros can be truncated
//                         if(spaceBTColon == 0) return "Neither";
//                         if(spaceBTColon == 1) 
//                         {
//                             int x = i-1;
//                             if(IP[x] != '0') return "Neither";
//                             else 
//                             {
//                                 spaceBTColon = 0;
//                                 continue;
//                             }
                            
//                         }
//                         else
//                         {
//                             spaceBTColon = 0;
//                             return "Neither";
//                         }   
//                     }
//                 }
//                 else spaceBTColon++;
//             }
//             else return "Neither";
            
//         }
//         return "IPV6";
//     }
//     return "Neither";

// }


string validIPAddress(string IP) {

    int n = IP.length();
    int i,j;
    int countDot = 0, countColon = 0;
    for(i=0;i<n;i++)
    {
        if(IP[i] == '.') countDot++;
        if(IP[i] == ':') countColon++;
        if(IP[i] == '-') return "Neither";
    }
    //cout << countDot << " "  << countColon << endl;

    if(countDot == 3 && countColon == 0)
    {
        // go for IP check
        j=0;
        for(i=0;i<4;i++)
        {
            long long int num = 0,countDigit = 0;
            while(true)
            {
                if(IP[j] == '.') break;
                if(IP[j] == '.') break;
                if(IP[j] == '-') break;
                if(IP[j] == '\0') break;
                if(countDigit == 0 && (IP[j]-'0') == 0 && IP[j+1]!='.') return "Neither";
                num = num*10 + (IP[j]-'0');
                if(num > 255 || num < 0) return "Neither"; 
                j++;
                countDigit++;
            }
            if(num > 255 || num < 0) return "Neither";
            if(IP[j] == '-') return "Neither";
            if(countDigit > 3 || countDigit == 0) return "Neither";
            if(IP[j] == '\0') break;
            j++;
        }
        return "IPv4";
    }
    else if(countDot == 0 && countColon == 7)
    {
        // go for IPV6
        int spaceBTColon = 0;
        int colon = 0;
        for(i=0;i<=IP.length();i++)
        {
               
            if((IP[i] >= '0'&& IP[i] <='9') || (IP[i] >= 'a' && IP[i] <='f') || (IP[i] >= 'A' && IP[i] <='F') || IP[i] == ':'|| IP[i] == '\0')
            {   //cout << "iphere: " << IP[i] << endl;
                if(IP[i] == ':' || IP[i] == '\0')
                {
                    // we need to check the space b/t 2 : should be 4
                    //cout << spaceBTColon << endl;
                    colon++;
                    //cout << colon << " coloooooooon\n";
                    //cout << "space: " << spaceBTColon << endl;
                    if(spaceBTColon <= 4 && spaceBTColon != 0) spaceBTColon = 0;
                    else if(spaceBTColon > 4) return "Neither";
                    else 
                    {
                        // leading zeros can be truncated
                        if(spaceBTColon == 0) return "Neither";
                        if(spaceBTColon == 1) 
                        {
                            int x = i-1;
                            if(IP[x] != '0') return "Neither";
                            else 
                            {
                                spaceBTColon = 0;
                                continue;
                            }
                            
                        }
                        else
                        {
                            spaceBTColon = 0;
                            return "Neither";
                        }   
                    }
                }
                else /*cout << "ip: " << (IP[i]) << endl,*/spaceBTColon++;
                //cout << colon << " coloooooooon\n";
                //cout << "space: " << spaceBTColon << endl;
                // if(colon == 7)
                // {
                    
                //     if(spaceBTColon > 4) return "Neitheras";
                //     else 
                //     {
                //         // leading zeros can be truncated
                //         //if(spaceBTColon == 0) return "Neitheraw";
                //         if(spaceBTColon == 1) 
                //         {
                //             int x = i-1;
                //             if(IP[x] != '0') return "Neithersdf";
                //             else 
                //             {
                //                 spaceBTColon = 0;
                //                 continue;
                //             }
                            
                //         }
                //         else
                //         {
                //             spaceBTColon = 0;
                //             return "Neithersdv";
                //         }   
                //     }
                // }
    
                
            }
            else return "Neither";
            
        }
        return "IPv6";
    }
    return "Neither";

}

    int main()
    {
        

        string s11 = "192.0.0.1";
        cout << validIPAddress(s11) << endl;
        return 0;
    }