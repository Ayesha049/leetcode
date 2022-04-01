class Solution {
public:
    template<typename T>
    void swap(T &a, T &b)
    {
        T temp = a;
        a = b;
        b = temp;
    }
    
    void reverseString(vector<char>& s) {
        int len = s.size();
        for(int i=0;i<len/2;i++)
        {
            swap(s[i],s[len-1-i]);
        }
    }
};