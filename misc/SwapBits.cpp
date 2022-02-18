 //Swap even and odd bits of a 32 bit integer
uint32_t SwapBits(uint32_t test)
{
    even_mask = 0xAAAAAAAA;
    uint32_t temp = 0;
    temp = ((test & even_mask) >> 1) | ((test & ~even_mask) << 1);
    return temp;
}