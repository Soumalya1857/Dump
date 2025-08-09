class Solution {
    public int findLeastNumOfUniqueInts(int[] arr, int k) {
        Map<Integer, Integer> map = new HashMap<>();
        int length = arr.length;
        
        for(int i=0; i<length; i++) {
            map.put(arr[i], map.getOrDefault(arr[i], 0)+1);
        }
        int start = 1;
        
        Map<Integer, List<Integer>> countMap = new HashMap<>();
        for(Map.Entry<Integer, Integer> entry: map.entrySet()) {
            if(!countMap.containsKey(entry.getValue())) {
                countMap.put(entry.getValue(), new ArrayList<>());
            }
            
            countMap.get(entry.getValue()).add(entry.getKey());
        }
        
        while(k > 0 && start <= length) {
            if(countMap.containsKey(start)) {
                List<Integer> list = countMap.get(start);
                for(int i=0; i<list.size(); i++) {
                    if(k-start >= 0) {
                        map.remove(list.get(i));
                        k -= start;
                    } else {
                        k=0;
                    }
                }
            }
            start++;
        }
        
        return map.size();
    }
}
// prb: https://leetcode.com/problems/least-number-of-unique-integers-after-k-removals/
// soln: https://leetcode.com/problems/least-number-of-unique-integers-after-k-removals/discuss/1377438/Java-O(n)-Time-and-O(n)-Space