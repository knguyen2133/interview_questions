class Solution
{
public:
    bool validPalindrome(string s)
    {
        for (size_t i = 0, j = s.size() - 1; i < j; ++i, --j)
        {
            if (s[i] != s[j])
            {
                size_t i_left = i;
                size_t j_left = j - 1;
                size_t i_right = i + 1;
                size_t j_right = j;
                // shift left
                while ((i_left < j_left) && (s[i_left] == s[j_left]))
                {
                    ++i_left;
                    --j_left;
                }
                // shift right
                while ((i_right < j_right) && (s[i_right] == s[j_right]))
                {
                    ++i_right;
                    --j_right;
                }
                return (i_left >= j_left || i_right >= j_right);
            }
        }
        // never had a problem with the word
        return true;
    }
};