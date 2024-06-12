class Solution {
    public int[][] merge(int[][] intervals) {
        Arrays.sort(intervals, (a,b)->Integer.compare(a[0],b[0]));
        LinkedList<int[]> merged = new LinkedList<>();
        for(int[] interval : intervals)
        {
            if(merged.isEmpty() || merged.getLast()[1] < interval[0])
            {
                // no overlapping possible
                merged.add(interval);
            }
            else{
                merged.getLast()[1] = Math.max(merged.getLast()[1], interval[1]);
            }
        }

        return merged.toArray(new int[merged.size()][]);

    }
}
// ques: https://leetcode.com/problems/merge-intervals/
// soln: https://www.youtube.com/watch?v=hVl2b3bLzBw&list=PLgUwDviBIf0rPG3Ictpu74YWBQ1CaBkm2&index=6

// https://www.youtube.com/watch?v=n7uwj04E0I4&t=0s

class Solution{
	public:

		bool static compare(vector<int>& a, vector<int>& b){
			if(a[0] < b[0]){
				return true;
            } else if(a[0] == b[0]){
                return a[1] < b[1];
            }

        return false;
        }
		vector<vector<int>> merge(vector<vector<int>>& intervals) {

			sort(intervals.begin(), intervals.end(), compare);

			int endOfInterval = intervals[0][1];
			int startOfInterval = intervals[0][0];

			vector<vector<int>> ans;
			for(int i=1; i<intervals.size(); i++){

				int start = intervals[i][0];
				int end = intervals[i][1];

				if(start > endOfInterval){
					vector<int> temp{startOfInterval, endOfInterval};
					ans.push_back(temp);
					startOfInterval = start;
					endOfInterval = end;
                } else if(start <= endOfInterval){
                    endOfInterval = max(end, endOfInterval);
                }


            }

            ans.push_back(vector<int>{startOfInterval, endOfInterval});

            return ans;

        }

};

