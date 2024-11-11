class Solution {
public:
    int getSum(int a, int b) {
        // we have to reutrn sum of two integer 
        int sum = a ^ b;
        int carry = a & b;
        return sum + (carry<<1);
    }
};