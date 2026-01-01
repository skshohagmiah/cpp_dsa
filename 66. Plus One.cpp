class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {

        int n = digits.size();

        // start from last digit
        for (int i = n - 1; i >= 0; i--) {

            if (digits[i] < 9) {
                digits[i]++;
                return digits;   // no carry needed
            }

            // digit is 9
            digits[i] = 0;
        }

        // if we are here, all digits were 9
        digits.insert(digits.begin(), 1);
        return digits;
    }
};
