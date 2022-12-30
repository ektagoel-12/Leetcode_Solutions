# Approach
Create 2 hashmaps which will keep the record of the frequency of characters of both the strings. Then iterate over the string to be checked and compare the frequency of all characters in both the hashmaps. If the frequency is different then return false. Else at the end return true.
# Complexity
- Time complexity:
$$O(n)$$ where n is the length of the string

- Space complexity:
$$O(1)$$

# Code
```
class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char,int>m1,m2;
        if(s.length()!=t.length()) return false;
        for(int i=0;i<s.length();i++)
        {
            m1[s[i]]++;
        }
        for(int i=0;i<t.length();i++)
        {
            m2[t[i]]++;
        }
        for(int i=0;i<t.length();i++)
        {
            if(m1[t[i]]!=m2[t[i]])
            {return false;}
        }
        return true;
    }
};
```
