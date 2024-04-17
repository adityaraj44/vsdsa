// this finds the greasted common divisor or the hcf
int gcd(int A, int B)
{
    if (A == 0)
        return B;
    if (B == 0)
        return A;

    while (A != B)
    {
        if (A > B)
        {
            A = A - B;
        }
        else
        {
            B = B - A;
        }
    }
    return A;
}

/*
relation with lcm is: lcm(a,b) * gcd(a,b) = a * b
*/

vector<long long> lcmAndGcd(long long A, long long B)
{
    long long prod = A * B;
    vector<long long> ans;
    if (A == 0)
        return {0, B};
    if (B == 0)
        return {0, A};

    while (A != B)
    {
        if (A > B)
        {
            A = A - B;
        }
        else
        {
            B = B - A;
        }
    }
    long long gcd = A;
    long long lcm = prod / gcd;
    ans.push_back(lcm);
    ans.push_back(gcd);
    return ans;
}