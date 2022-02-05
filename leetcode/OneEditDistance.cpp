// Given two strings s and t, return true if they are both one edit distance apart, otherwise return false.

// A string s is said to be one distance apart from a string t if you can:

// Insert exactly one character into s to get t.
// Delete exactly one character from s to get t.
// Replace exactly one character of s with a different character to get t.

// Constraints:

// 0 <= s.length, t.length <= 104
// s and t consist of lowercase letters, uppercase letters, and digits.

class Solution {
public:
    bool isOneEditDistance(string s, string t) {
      // want to make sure s is the smaller string
      if(s.size() > t.size())
      {
        return isOneEditDistance(t, s);
      }
      
      if(t.size() - s.size() > 1 )
      {
        // only allow one error
        return false;
      }
      
      for(size_t i =0 ; i < s.size(); ++i)
      {
        if(s[i] != t[i])
        {
          // if they are the same length
          if(s.size() == t.size())
          {
            //ass
            //ads
            return s.substr(i+1).compare(t.substr(i+1)) == 0;
          }else{
            // else in a different length 
            //asd
            //asfd
            return s.substr(i).compare( t.substr(i+1)) == 0;
          }
        }
        
      }
      //asd
      //asdf
      return ((s.size() + 1 )== t.size());
    }
};