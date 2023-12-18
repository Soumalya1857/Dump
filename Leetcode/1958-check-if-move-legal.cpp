class Solution {

private: 
    bool isValid(int row, int col){
        if(row >=0 && row<8){
            if(col >=0 && col < 8){
                return true;
            }
        }

        return false;
    }
public:
    struct State{
        int xpos;
        int ypos;
        string dir;
        char color;
        char endColor;
        int length;
    };


    bool checkMove(vector<vector<char>>& board, int rMove, int cMove, char color) {
        unordered_map<string, pair<int,int>> directions;
        directions["n"] = {-1,0};
        directions["s"] = {1,0};
        directions["e"] = {0,1};
        directions["w"] = {0,-1};
        directions["ne"] = {-1,1};
        directions["nw"] = {-1,-1};
        directions["se"] = {1,1};
        directions["sw"] = {1,-1};

        vector<string> directionArr{"n", "s", "e", "w", "ne", "nw", "se", "sw"};

        // which direction, position, colorEndpoint
        stack<State> s;
        for(int i=0; i<8; i++){
            State temp = {rMove, cMove, directionArr[i], color, color,1};
            s.push(temp);
        }


        while(!s.empty()){
            State curr = s.top(); s.pop();

            // cout << "x: " << curr.xpos
            //      << " y: " << curr.ypos
            //      << " dir: " << curr.dir
            //      << " currColor: " << curr.color
            //      << " endColor: " << curr.endColor
            //      << " length: " << curr.length
            //      << endl;

            if(isValid(curr.xpos, curr.ypos) 
                    &&(curr.xpos != rMove || curr.ypos != cMove)
                    && curr.length >= 3 
                    && curr.endColor == curr.color){

                //cout << "++++++++++++++ return true +++++++++++++++\n";
                return true;
            }


            int x = curr.xpos + directions[curr.dir].first;
            int y = curr.ypos + directions[curr.dir].second;

            if(isValid(x,y) && board[x][y] != '.'){
                if(board[x][y] == curr.endColor && curr.length<2){
                    continue;
                }
                State temp = {x,y, curr.dir, board[x][y], curr.endColor, ++curr.length};
                s.push(temp);
            }

        }

        return false;
    }
};

// https://leetcode.com/problems/check-if-move-is-legal/solutions/1390122/trace-in-8-directions/

// a better space optimized approach
bool checkMove(vector<vector<char>>& board, int rMove, int cMove, char color) {
    int dir[10] = {0, 1, 0, -1, 0, 1, 1, -1, -1, 1};
    for (int d = 0; d < 9; ++d)
        for (int x = 1; ; ++x) {
            int i = rMove + x * dir[d], j = cMove + x * dir[d + 1];
            if (i < 0 || j < 0 || i >= 8 || j >= 8 || board[i][j] == '.')
                break;
            if (board[i][j] == color) {
                if (x > 1)
                    return true;
                break;
            }
        }
    return false;
}