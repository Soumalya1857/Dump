 #include<bits/stdc++.h>
 using namespace std;
 
 int preced(char a)
    {
        if(a == '+' || a == '-') return 1;
        else if(a == '*' || a =='/') return 2;
        else return 0;
    }
    
    string turn_postfix(string s)
    {
        stack<char> stk;
        string post = "";
        string :: iterator it;
        stk.push('#');
        
        for(it = s.begin(); it != s.end();it++)
        {
            if(*it == ' ') continue;
            else if(*it >= '0' && *it <= '9') post += *it;
            else if (preced(*it) > preced(stk.top())) stk.push(*it);
            else 
            {
                while(stk.top()!='#' && preced(*it) <= preced(stk.top()))
                {
                    post += stk.top();
                    stk.pop();
                }
                stk.push(*it);
            }
        }
        while(stk.top() != '#') post += stk.top(),stk.pop();
        
        return post;
    }
    int calculate(string s) {
        
        string post = turn_postfix(s);
        cout << post << endl;
        stack<int> stk;
        string :: iterator it;
        int count = 0,check = 0;
        for(it = s.begin(); it != s.end(); it++) if(*it == '+' || *it == '-' || *it == '*' || *it == '/') count++;
        count++;
        cout << "count " << count << endl;
        for(it = s.begin(); it != s.end(); it++)
        {
            bool flag = false;
            if(*it == ' ') continue;
            else
            {
                int num = 0;
                check++;
                while(*it >= '0' && *it <= '9' && it!=s.end())
                {
                    num = num*10 + (*it-'0');
                    it++;
                    flag = true;
                }
                //cout << num << " num" << endl;
                if(flag) stk.push(num),cout << num << " num\n";
                if(check == count) break;
            }
        }
        for(it = post.begin(); it != post.end(); it++)
        {
            if(*it == '+' || *it == '-' || *it == '*' || *it == '/')
            {
                int top = stk.top() ;
                stk.pop();
                int prev = stk.top();
                stk.pop();
                //cout << prev << " " << top << endl;
                if(*it == '+') stk.push(top+prev);
                if(*it == '-') stk.push(prev-top);
                if(*it == '*') stk.push(top*prev);
                if(*it == '/') stk.push(prev/top);
            }
            // else
            // {
            //     int num = 0 ;
            //     // need to tokenize the number 
            //     while(*it >= '0' && *it <= '9')
            //     {
            //         num = num*10 +(int)(*it - '0');
            //         /*if(*(it+1) == '+' || *(it+1) == '-' || *(it+1) == '*' || *(it+1) == '/' ) break;
            //         else*/ it++;
            //     }
            //     cout << num << "  num" << endl;
            //     stk.push(num);
            // }
        }
        int ans = stk.top();
        return ans;    
    }

int main()
{
    string s = "3+5 / 2";
    cout << calculate(s) << endl;
}