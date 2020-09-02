#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

// Complete the journeyToMoon function below.
int journeyToMoon(int n, vector<vector<int>> astronaut) {

    
   //cout << "n: " << n << "\n"; 
    
    
    vector<unordered_set<int>> s;
    unordered_set<int> first;
    first.insert(astronaut[0][0]);
    s.push_back(first);
    bool done = false;
    
    //bool visited[n] = {false};
    
    for(unsigned int i=0;i<astronaut.size();i++)
    {
        int fi = astronaut[i][0];
        int se = astronaut[i][1];
        done = false;
     
        for(unsigned int j=0;j<s.size();j++)
        {
            if(s[j].find(fi) != s[j].end())
            {
                s[j].insert(se);
                done = true;
                break;
            }
            else if(s[j].find(se) != s[j].end())
            {
                s[j].insert(fi);
                done = true;
                break;
            }
        }
        if(!done)
        {
            unordered_set<int> newSet;
            newSet.insert(fi);
            newSet.insert(se);
            s.push_back(newSet);
        }
        
    }
    
    int num = s.size();
    int total = 0;
    vector<int> di;
    for(int i=0;i<num;i++) di.push_back(s[i].size()),total += s[i].size();//,cout << s[i].size() << "\n";
    int remain = n - total;
    //cout << "n: " << n << "\n";
    //cout << "remain: " << remain << "\n";
    //if(remain == 0) remain = 1;
    for(int i=0;i<remain;i++) di.push_back(1);
    
    num = di.size();
    //cout << "num: " << num << endl;
    //cout << "di: ";
    //for(int i=0;i<num;i++) cout << di[i] << " ";
    //cout << "\n";
    
    int ans = 0;
    for(int i=0;i<num;i++)
    {
        for(int j = i+1;j<num;j++)
        {
            ans += di[i]*di[j];
        }
    }
    
    return ans;
    
    
    // vector<vector<int>> graph;
    // for(int i=0;i<astronaut.size();i++)
    // {
    //     int fi = astronaut[0];
    //     int se = astronaut[1];
    //     graph[fi].push(se);
    //     graph[se].push(fi);
    // }
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string np_temp;
    getline(cin, np_temp);

    vector<string> np = split_string(np_temp);

    int n = stoi(np[0]);

    int p = stoi(np[1]);

    vector<vector<int>> astronaut(p);
    for (int i = 0; i < p; i++) {
        astronaut[i].resize(2);

        for (int j = 0; j < 2; j++) {
            cin >> astronaut[i][j];
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    int result = journeyToMoon(n, astronaut);

    fout << result << "\n";

    fout.close();

    return 0;
}

vector<string> split_string(string input_string) {
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [] (const char &x, const char &y) {
        return x == y and x == ' ';
    });

    input_string.erase(new_end, input_string.end());

    while (input_string[input_string.length() - 1] == ' ') {
        input_string.pop_back();
    }

    vector<string> splits;
    char delimiter = ' ';

    size_t i = 0;
    size_t pos = input_string.find(delimiter);

    while (pos != string::npos) {
        splits.push_back(input_string.substr(i, pos - i));

        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }

    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

    return splits;
}
