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