class Solution {
    public String simplifyPath(String path) {
        String [] paths = path.split("/");
        Stack<String> st = new Stack<>();
        for(String s : paths) {
            if(s.length() > 0) {
                if(s.equals("..")) {
                    if(st.size() > 0) {
                        st.pop();
                    }
                } else if(!s.equals(".")) {
                    st.push(s);
                }
            }
        }
        StringBuilder ans = new StringBuilder("/");
        List<String> list = new ArrayList<>();
        while(!st.empty()) {
            list.add(st.pop());
        }
        for(int i=list.size()-1;i>=0;i--) {
            ans.append(list.get(i));
            if(i!=0) {
                ans.append("/");
            }
        }
        return ans.toString();
    }
}