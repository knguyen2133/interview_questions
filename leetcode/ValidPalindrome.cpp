// A phrase is a palindrome if, after converting all uppercase letters into lowercase letters and removing all non-alphanumeric characters, it reads the same forward and backward. Alphanumeric characters include letters and numbers.

// Given a string s, return true if it is a palindrome, or false otherwise.
// a cbbca
class Solution
{
public:
    bool isPalindrome(string s)
    {
        // cast a loop that pinches the string
        for (int i = 0, j = s.size() - 1; i < j; ++i, --j)
        {
            while (i < j && !isalnum(s[i]))
            {
                ++i;
            }
            while (i < j && !isalnum(s[j]))
            {
                --j;
            }

            if (tolower(s[i]) != tolower(s[j]))
            {
                return false;
            }
        }
        return true;
    }
};