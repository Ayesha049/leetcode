class Solution {
    public int compareVersion(String v1, String v2) {
        String [] s1 = v1.split("\\.");
        String [] s2 = v2.split("\\.");
        List<Integer> l1 = new ArrayList();
        List<Integer> l2 = new ArrayList();
        for(int i=0;i<s1.length;i++) {
            l1.add(Integer.parseInt(s1[i]));
        }
        while(l1.size() > 0 && l1.get(l1.size() - 1) == 0) {
            l1.remove(l1.size() - 1);
        }
        // System.out.println(l1);
        for(int i=0;i<s2.length;i++) {
            l2.add(Integer.parseInt(s2[i]));
        }
        while(l2.size() > 0 && l2.get(l2.size() - 1) == 0) {
            l2.remove(l2.size() - 1);
        }
        // System.out.println(l2);
        int max = Math.max(l1.size(),l2.size());
        // System.out.println(max);
        for(int i=0;i<max;i++) {
            int num1 = l1.size() <= i ? 0 : l1.get(i);
            int num2 = l2.size() <= i ? 0 : l2.get(i);
            // System.out.println("num1 : " + num1);
            // System.out.println("num2 : " +num2);
            if(num1 > num2) {
                return 1;
            } else if(num1 < num2) {
                return -1;
            }
        }
        return 0;
    }
}