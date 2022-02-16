class Solution
{
public:
    int binaryGap(int n)
    {
        int gap = 0;
        int last_position = -1;
        for (int i = 0; i < 32; ++i)
        {
            if (n >> i % 2)
            {
                if(last_position ==-1)
                gap = (gap > (i - last_position)) ? gap : (i - last_position);
            }
            //everytime one hits then set the last position to i 100101101
            last_position = i;
        }
        return gap;
    }
};