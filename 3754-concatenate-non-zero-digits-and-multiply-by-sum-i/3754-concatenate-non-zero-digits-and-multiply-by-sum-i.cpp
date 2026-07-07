class Solution {
public:
    long long sumAndMultiply(int n) {
        string newnumber;
        int sum = 0;
        bool found = false;
        
        while (n > 0) {
            int digit = n % 10;
            n = n / 10;
            if (digit != 0) {
                found = true;
                newnumber = to_string(digit) + newnumber;
                sum += digit;
            }
        }
        
        // FIX 1: Check this BEFORE trying to convert the string.
        // If no non-zero numbers were found, stop here and return 0 safely.
        if (found == false || newnumber.empty()) {
            return 0;
        }
        
        // FIX 2: Changed 'stoii' to 'stoll' (String to Long Long)
        long long mul = stoll(newnumber); 
        long long finalnum = sum * mul;
        
        return finalnum;
    }
};