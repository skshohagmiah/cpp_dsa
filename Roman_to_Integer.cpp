#include <string>
class Solution {
public:
    int romanToInt(string s) {
        int number = 0;
        unordered_map<char, int> romanToIntMap = {
            {'I', 1},   {'V', 5},   {'X', 10},  {'L', 50},
            {'C', 100}, {'D', 500}, {'M', 1000}};

        for (int i = 0; i < s.size(); i++) {
            if (romanToIntMap[s[i]] < romanToIntMap[s[i + 1]]) {
                number -= romanToIntMap[s[i]];
            } else {
                number += romanToIntMap[s[i]];
            }
        }

        return number;
    }
};