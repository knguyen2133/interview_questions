void *memcopy(void *dst,const void *src, size_t n ){
    long misaligned = 0x3;
    // deal with long ( this also handles os sizes )
    long* p_ldst = ( long* )dst;
    long* p_lsrc = ( long* )src;
    
    // Verify alignment:
    // To be misalign is when addresses have binary marks before 0x4
    if( !(dst & misaligned) && !(src & misaligned) )
    {
        // long copy
        while( n > 4 )
        {
            (*p_ldst)++ = (*p_lsrc)++; 
            n -= 4;
        }
    }

    // deal with bits at the end; short copy
    char* p_dst = (char*)p_ldst;
    char* p_src = (char*)p_lsrc;
    
    while( n > 0 ){
        (*p_dst)++ = (*p_src)++;
        n -= 1;
    }

    return dst;
}