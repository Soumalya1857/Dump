class Solution {

    public void solve(int[] nums, int index, List<Integer> list, List<List<Integer>> result) {
        if (index == nums.length){
            result.add(new ArrayList<>(list));
            return;
        }

        // not consider
        solve(nums, index+1, list, result);

        // consider
        list.add(nums[index]);
        solve(nums, index+1, list, result);
        list.remove(list.size() - 1);
    }

    public List<List<Integer>> subsets(int[] nums) {
        List<List<Integer>> result = new ArrayList<>();
        List<Integer> list = new ArrayList<>();
        solve(nums, 0, list, result);
        return result;
    }
}

// https://leetcode.com/problems/subsets/submissions/1922553375/
// https://leetcode.com/problems/subsets/description/