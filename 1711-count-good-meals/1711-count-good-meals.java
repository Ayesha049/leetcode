class Solution {
    public int countPairs(int[] deliciousness) {
        long out=0;
        long mod=1000000007;
        HashMap<Integer,Integer>map=new HashMap<Integer,Integer>();
        List<Integer> list = new ArrayList();
        int base = 1;
        list.add(base);
        for(int i=0;i<=20;i++) {
            base*=2;
            list.add(base);
        }
        for(int num:deliciousness){
            for(int pow:list){
                int req=pow-num;
                if(map.containsKey(req)){
                   out+=map.get(req); 
                   out%=mod;
                }
            }
            map.put(num,map.getOrDefault(num,0)+1);
        }
        return (int)out;
    }
}