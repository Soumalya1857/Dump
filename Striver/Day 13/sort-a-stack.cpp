
/*The structure of the class is
class SortedStack{
public:
	stack<int> s;
	void sort();
};
*/

   void insert(stack<int> &s, int temp)
   {
    //   while(!s.empty())
    //   {
    //       if(s.top() <= temp) 
    //       {
    //           s.push(temp);
    //           return;
    //       }
    //       else
    //       {
    //           int top = s.top();
    //           s.pop();
    //           insert(temp);
    //       }
    //   }
    
        if(s.empty() || s.top() <= temp) 
        {
            s.push(temp);
            return;
        }
        
        int val = s.top(); s.pop();
        insert(s, temp);
        s.push(val);
   }


/* The below method sorts the stack s 
you are required to complete the below method */
void SortedStack :: sort()
{
   //Your code here
   if(s.size() == 1) return;
   if(!s.empty())
   {
       int temp = s.top(); s.pop();
       sort();
       
    //   if(s.empty()) s.push(temp);
    //   else
    //   {
    //       if(s.top() <= temp) s.push(temp);
    //     //   else
    //     //   {
    //     //       int top = s.top(); s.pop();
    //     //       s.push(temp);
    //     //       s.push(top);
    //     //   }
    //   }
    
    
        // now insert temp in sorted stack
        insert(s, temp);
   }
       
 }
 // prb: https://practice.geeksforgeeks.org/problems/sort-a-stack/1#
 // soln: https://www.youtube.com/watch?v=MOGBRkkOhkY