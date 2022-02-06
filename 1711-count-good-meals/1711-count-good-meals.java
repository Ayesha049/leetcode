class Solution {
    public int countPairs(int[] deliciousness) {
        long out=0;
        long mod=1000000007;
        HashMap<Integer,Integer>map=new HashMap<Integer,Integer>();
        for(int num:deliciousness){
            for(int i=0;i<31;i++){
                int powerof2= 1<<i;
                int req=powerof2-num;
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