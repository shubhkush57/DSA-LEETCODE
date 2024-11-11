class Solution {
public:
    int getSum(int a, int b) {
        // we have to reutrn sum of two integer 
        if(b == 0)return a;
        int sum = a ^ b;
        int carry = (a & b)<<1;
        return getSum(sum,carry);
    }
};