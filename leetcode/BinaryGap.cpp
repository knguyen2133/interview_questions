class Solution
{
public:
    int binaryGap(int n)
    {
        int gap = 0, last = -1;
        // loop through the number binary
        for (int i = 0; i < 32; ++i)
        {
            if ((n >> i) % 2)
            {
                if (last != -1)
                {
                    gap = max(gap, i - last);
                }
                last = i;
            }
        }
        return gap;
    }
};