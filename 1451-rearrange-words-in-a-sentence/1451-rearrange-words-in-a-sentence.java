class Solution {
    public String arrangeWords(String text) {
        String [] list = text.split(" ");
        Map<Integer,List<String> > map = new HashMap();
        for(int i=0;i<list.length;i++) {
            int length = list[i].length();
            List<String> myList = new ArrayList();
            if(map.containsKey(length)) {
                myList = map.get(length);
                myList.add(list[i].toLowerCase());
                map.put(length, myList);
            } else {
                myList.add(list[i]);
                map.put(length, myList);
            }
        }
        String ans = "";
        
        for (Map.Entry<Integer,List<String>> entry : map.entrySet()) {
            for(int i=0;i<entry.getValue().size();i++) {
                ans += entry.getValue().get(i);
                ans += " ";
            }
            
        }
        ans = ans.substring(0, ans.length() - 1);
        ans = ans.substring(0,1).toUpperCase() + ans.substring(1).toLowerCase();
        return ans;
    }
}