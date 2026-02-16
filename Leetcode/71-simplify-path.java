class Solution {
    public String simplifyPath(String path) {
        LinkedList<String> ll = new LinkedList<>();
        String[] shards = path.split("/");

        for (String shard: shards) {
            //System.out.println(shard);
            if("".equals(shard)) continue;
            if(".".equals(shard)) continue;

            if("..".equals(shard)) {
                //System.out.println(ll.size());
                if(ll.size() > 0){
                    ll.pollLast();
                }
                continue;
            }

            ll.add(shard);
        }

        if(ll.size() == 0) return "/";

        String result = "/";
        // manually track the index as get in ll is n2

        int index = 0;
        for(String shard : ll){
            index++;
            result += shard;
            if(index != ll.size()){
                result += "/";
            }
        }

        return result;
    }
}

// https://leetcode.com/problems/simplify-path/submissions/1921446988/


// slighly optimized version, using StringBuilder and for loop instead of for each loop
class Solution {
    public String simplifyPath(String path) {
         // create a stack
        Stack<String> stack = new Stack<String>();
        

        // Split the input string on "/" as the delimiter
        // and process each portion one by one
        String[] components = path.split("/");
        for (String directory : components) {
            // A no-op for a "." or an empty string
            if (directory.equals(".") || directory.isEmpty()) {
                continue;
            } else if (directory.equals("..")) {
                // If the current component is a "..", then
                // we pop an entry from the stack if it's non-empty
                // since .. means prev
                if (!stack.isEmpty()) {
                    stack.pop();
                }
            } else {
                // Finally, a legitimate directory name, so we add it
                // to our stack
                stack.add(directory);
            }
        }

        // Stich together all the directory names together
        StringBuilder result = new StringBuilder();
        for (String dir : stack) {
            result.append("/");
            result.append(dir);
        }

        return result.length() > 0 ? result.toString() : "/";
    }
}

