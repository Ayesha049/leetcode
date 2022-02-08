class Solution {
    public int addDigits(int num) {
        while(num>9) {
            String s = Integer.toString(num);
            num = 0;
            for(int i=0;i<s.length();i++) {
                num += (int) (s.charAt(i) - '0');
            }
        }
        return num;
    }
}