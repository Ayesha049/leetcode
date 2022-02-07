class Solution {
    public String reverseWords(String s) {
        String[] strs = s.split(" ");
        StringBuilder ans = new StringBuilder("");
        for(int i=0;i<strs.length;i++) {
            ans.append(new StringBuilder(strs[i]).reverse());
            if(i<strs.length-1) {
                ans.append(" ");
            }
        }
        return ans.toString();
    }
}