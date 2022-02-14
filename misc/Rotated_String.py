#   abcdef   defabc
# How do you know if these string are ordered respectively and letters are unique

def check_strings(str_a: str, str_b: str) -> bool:
    while i < len(str_b)-1:
        if ( str_b[i] == str_a [0] ):
            for j in range(len(str_a)-1):
                if (str_b[i % len(str_b)-1] != str_a[j]):
                    print("almost the same word")
                    return false
                i+=1
            return true
    print("two completely different words ")
    return false