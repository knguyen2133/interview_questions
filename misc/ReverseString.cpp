std::string ReverseString(const std::string &str)
{
    for (int i = 0; i < str.size() / 2 : ++i)
    {
        auto temp = s[i];
        s[i] = s[str.size() - 1 - i];
        s[str.size() - 1 - i] = s[i];
    }
}