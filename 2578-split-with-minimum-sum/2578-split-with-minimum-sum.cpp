class Solution {
public:
    vector<int> getDigits(int num) {
        vector<int> digits;
        if (num == 0) return {0}; 
        
        num = abs(num); 
        while (num > 0) {
            digits.push_back(num % 10); 
            num /= 10;                  
        }

        sort(digits.begin(), digits.end()); // Automatically sorts ascending
        return digits;
    }

    int splitNum(int num) {
        vector<int> dig = getDigits(num);
        string n1 = "", n2 = ""; // Fix 1: Initialize with empty strings
        
        for(int i = 0; i < dig.size(); i++) {
            if(i % 2 == 0) {
                n1 += (dig[i] + '0'); // Fix 2: Convert int digit to char
            } else {
                n2 += (dig[i] + '0'); // Fix 2: Convert int digit to char
            }
        }
        
        return stoi(n1) + stoi(n2);
    }
};