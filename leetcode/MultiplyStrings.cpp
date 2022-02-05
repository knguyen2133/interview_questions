// Given two non-negative integers top and bottom represented as strings, return the product of top and bottom, also represented as a string.
// Note: You must not use any built-in BigInteger library or convert the inputs to integer directly.
//     2 5
//     2 5
// --------
//   1 2 5         1,2,5
// (5 )0 0         5,0,0
//   6 2 5

class Solution
{
private:
    vector<int> multiplySingle(const string &top, const string &bottom, const int index)
    {
        vector<int> multiply_line;
        multiply_line.clear();

        int carry_over = 0;
        for (size_t i = 0; i < index; ++i)
        {
            multiply_line.push_back(0);
        }
        //cast a loop that will iterate top and stuff the multiply line
        for (size_t i = 0; i < top.size(); ++i)
        {
            int product = (top[i] - '0') * (bottom[index] - '0') + carry_over;
            // account for carryovers!
            int result = product % 10;
            carry_over = product / 10;
            multiply_line.push_back(result);
        }

        if (carry_over)
        {
            multiply_line.push_back(carry_over);
        }

        // For creating a fixed 2d array
        const auto rows = top.size() + bottom.size();
        for (size_t i = multiply_line.size(); i < rows; ++i)
        {
            multiply_line.push_back(0);
        }

        return multiply_line;
    }

    // To avoid overflow, immediately convert to string
    string addLines(vector<vector<int>> &sum_storage)
    {
        string sum_str = "";
        int carry_over = 0;
        for (size_t i = 0; i < sum_storage[0].size(); ++i)
        {
            size_t sum = 0;
            for (size_t j = 0; j < sum_storage.size(); ++j)
            {
                sum += sum_storage[j][i];
            }
            sum += carry_over;
            carry_over = sum / 10;
            sum = sum % 10;
            sum_str.push_back(sum + '0');
        }

        // flip the number back to regular, sometimes there is a 0 in the front
        reverse(sum_str.begin(), sum_str.end());
        if (sum_str[0] == '0')
        {
            sum_str = sum_str.substr(1, sum_str.size());
        }
        return sum_str;
    }

public:
    string multiply(string top, string bottom)
    {
        if (top == "0" || bottom == "0")
        {
            return "0";
        }
        vector<vector<int>> sum_storage;
        // reverse the strings to be able to solve them elementary format
        reverse(top.begin(), top.end());       // top
        reverse(bottom.begin(), bottom.end()); // bottom

        // cast a loop to past in the top and an index of the bottom
        // per increment pass in the index to represent the padded zeros
        for (size_t i = 0; i < bottom.size(); ++i)
        {
            sum_storage.push_back(multiplySingle(top, bottom, i));
        }

        return addLines(sum_storage);
    }
};