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

