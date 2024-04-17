// create a mask to make all 1s of N to 0 and add that 1s to mask. Now ~ the number and & with mask to remove unnecessay 1s
int onesComplement(int N)
{
    int m = N;
    int mask = 0;

    if (m == 0)
    {

        return 1;
    }

    while (m != 0)
    {
        mask = (mask << 1) | 1;
        m = m >> 1;
    }
    int ans = (~N) & mask;

    return ans;
}
