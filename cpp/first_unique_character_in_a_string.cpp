# Approach
Create a hashmap which will contain the record of the frequency of alphabets that occured. Then iterate over the string and update the frequency in jthe map. after insertion again iterate over the string and return the first index in the string whose occurence frequency is 1. If nothing found return -1.

# Complexity
- Time complexity:
`O(n)` Because we are iterating over the string 2 times.

- Space complexity:
`O(1)` Because English alphabet contains 26 letters

# Code
```
class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char,int>m;
        int idx=0;
        for(int i=0;i<s.length();i++)
        {
                m[s[i]]++;
        }
        for(int i=0;i<s.length();i++)
        {
            if(m[s[i]]==1)
            {
                return i;
            }
        }
        return -1;
        
    }
};
```
