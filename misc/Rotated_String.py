#   abcdef   defabc
# How do you know if these string are ordered respectively and letters are unique

def check_strings(str_a: str, str_b: str) -> bool:
    while i < len(str_b)-1:
        if ( str_b[i] == str_a [0] )
            for( j in str_a):
                if (str_b[i % len(str_b)-1] != j):
                    print("almost the same word")
                    return false;
            return true;
    print("two completely different words ")
    return false;