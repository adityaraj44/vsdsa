int compress(vector<char> &chars)
{

    int i = 0;
    int ansIndex = 0;

    while (i < chars.size())
    {
        int j = i + 1;
        while (j < chars.size() && chars[i] == chars[j])
        {
            j++;
        }
        // store old char
        chars[ansIndex++] = chars[i];

        int count = j - i;
        if (count > 1)
        {
            // converting counting into single digit
            string cnt = to_string(count);
            for (char ch : cnt)
            {
                chars[ansIndex++] = ch;
            }
        }
        i = j;
    }
    return ansIndex;
}