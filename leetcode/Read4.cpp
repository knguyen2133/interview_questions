/**
 * The read4 API is defined in the parent class Reader4.
 *     int read4(char *buf4);
 */

class Solution
{
public:
    /**
     * @param buf Destination buffer
     * @param n   Number of characters to read
     * @return    The number of actual characters read
     */
    int read(char *buf, int n)
    {
        int actual = 0;
        char temp[4];
        int read_char = 4;
        while (actual < n && read_char == 4)
        {
            read_char = read4(temp);
            for (int i = 0; i < read_char; ++i)
            {
                if (actual == n)
                {
                    return actual;
                }
                buf[actual] = temp[i];
                ++actual;
            }
        }
        return actual;
    }
};