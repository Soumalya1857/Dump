
vector<vector<string>> group(vector<string> &strs)
{vector<vector<string>>output;  /// the first vector tht i used here is return type here
        
    
    if(strs.size()==0)
        return output;
    
    unordered_map<string,vector<string>>s;    //created mapping for all 
    
    for(string x:strs)
    {
     string key=x; //as we need again define tht x again for sort as its implace in c++
      sort(key.begin(),key.end());
        //now i need to plot these values back to the map 's'
      s[key].push_back(x);  
    }
    
    for(auto a:s)
    {
     //now we will iterate and return the values to the return type vector OUTPUT
        output.push_back(a.second);
    }
         
    return output;
    }