class Solution {
    
    int[] x = {-1,1,0,0};//up,down,left,right
    int[] y = {0,0,-1,1};
    public boolean hasValidPath(int[][] grid) {
        
        boolean[][] v = new boolean[grid.length][grid[0].length];
        Queue<State> q = new LinkedList<>();
        
        q.offer(new State(0,0));
        v[0][0] = true;
        
        while(!q.isEmpty()) {
            State s = q.poll();
            if(s.r == grid.length-1 && s.c == grid[0].length-1)  return true;
          
            for(int d=0;d<4;d++) {
                if(canMove(v,grid,s.r,s.c,d)) {
                    int r = s.r+x[d];
                    int c = s.c+y[d];
                    q.offer(new State(r,c));
                    v[r][c] = true;
                }
            }
                                            
        }
        return false;
    }


    boolean canMove(boolean[][] v,int[][] grid,int ri,int ci,int d) {
        int r=ri+x[d],c=ci+y[d];
        if(r<0||r>=v.length||c<0||c>=v[0].length||v[r][c]) return false;
        
        int type = grid[ri][ci];
        int nextType = grid[r][c];
        if(type ==1) {
            if (d==3) //right
               if(nextType ==1 || nextType==3 || nextType==5 ) return true;
           if (d==2) //left
               if(nextType ==1 || nextType==4 || nextType==6 ) return true;
        } 
        if (type ==2) {
            if (d==1) //down
                 if(nextType ==2 || nextType==5 || nextType==6 ) return true;
            if (d==0) //up
                 if(nextType ==2 || nextType==3 || nextType==4 ) return true;
        }
        if (type ==3) {
            if (d==2) //left
                 if(nextType ==1 || nextType==4 || nextType==6 ) return true;
            if (d==1) //down
                 if(nextType ==2 || nextType==5 || nextType==6 ) return true;
        }
        if (type ==4) {
            if (d==3) //r
                 if(nextType ==1 || nextType==3 || nextType==5 ) return true;
            if (d==1) //d
                 if(nextType ==2 || nextType==5 || nextType==6 ) return true;
        }
        if (type ==5) {
            if (d==0) //u
                 if(nextType ==2 || nextType==3 || nextType==4 ) return true;
            if (d==2) //l
                 if(nextType ==1 || nextType==4 || nextType==6 ) return true;
        }
        if (type ==6) {
            if (d==0) //u
                 if(nextType ==2 || nextType==3 || nextType==4 ) return true;
            if (d==3) //r
                 if(nextType ==1 || nextType==3 || nextType==5 ) return true;
        }
        return false;
    }
    
    class State {
        int r,c;
        public State(int r, int c) {
            this.r=r;this.c=c;
        }
    }
        
}


// https://leetcode.com/problems/check-if-there-is-a-valid-path-in-a-grid/submissions/