// return true for little(0x), false for big(0x)
bool FindEndianess()
{
    int x = 1;

    char *y = (char *)&x;
    return (y[0] == 0);
}