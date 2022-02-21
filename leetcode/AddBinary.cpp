class Solution
{
public:
    string addBinary(string short_str, string long_str)
    {
        if (short_str.empty() && long_str.empty())
        {
            return "0";
        }

        if (short_str.size() > long_str.size())
        {
            return addBinary(long_str, short_str);
        }

        std::reverse(short_str.begin(), short_str.end());
        std::reverse(long_str.begin(), long_str.end());

        // adding
        // iterate off the shorter bianry
        uint8_t carry_over = 0;

        uint8_t original_size = long_str.size();
        for (size_t i = 0; i < long_str.size() || carry_over; ++i)
        {
            uint8_t short_char = (i >= short_str.size()) ? 0 : (short_str[i] - '0');
            uint8_t long_char = (i >= long_str.size()) ? 0 : (long_str[i] - '0');
            size_t sum = short_char + long_char + carry_over;

            carry_over = (sum > 1) ? 1 : 0;
            sum = sum % 2;
            if (i >= original_size)
            {
                long_str.push_back(sum ? '1' : '0');
            }
            else
            {
                long_str[i] = sum ? '1' : '0';
            }
        }

        // re-reverse
        std::reverse(long_str.begin(), long_str.end());
        return long_str;
    }
};