// Given a string s, find the length of the longest substring without repeating
// characters.

// Time Complexity : O(n)
// Space Complexity : O(m)
#include <algorithm>

class Solution
{
    // abcabcbb = 3
    // pwwke w = 4 3
public:
    int lengthOfLongestSubstring(string s)
    {
        std::map<char, int> character_positions;
        size_t maxLen{0};
        for (size_t left = 0, right = 0; right < s.size(); ++right)
        {
            // if s[right] is in this map, update left to be in a position where all
            // characters are unique again
            if (character_positions.find(s[right]) != character_positions.end())
            {
                left = (character_positions[s[right]] > left)
                           ? character_positions[s[right]]
                           : left;
            }
            maxLen = (maxLen > (right - left + 1)) ? maxLen : (right - left + 1);
            character_positions[s[right]] = right + 1;
        }
        return maxLen;
    }
};