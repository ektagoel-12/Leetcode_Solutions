# Approach
Create a Hashmap for keeping the record of the frequency of alphabets present in `magazine`. After iterating over the magazine and updating the frequencies of characters. Iterate over the `ransomNote` and check the frequency of character from the hashmap , if it is greater than or equal to one then reduce it one less and continue iterating. Otherwise if character found with less frquency present then return false.If the iteration completes it means that characters in magazine are enough. 

# Complexity
- Time complexity:
$$O(n)$$ where n is max( magazine.length() , ransomNote.length() )

- Space complexity:
$$O(1)$$ 

# Code
```
class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char,int>m;
        for(int i=0;i<magazine.length();i++)
        {
            m[magazine[i]]++;
        }
        for(int i=0;i<ransomNote.length();i++)
        {
            if(m[ransomNote[i]]>=1)
            {
                m[ransomNote[i]]--;
            }
            else return false;

        }
        return true;
    }
};
```
