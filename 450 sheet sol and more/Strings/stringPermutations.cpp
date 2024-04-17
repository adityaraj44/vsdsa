// unique permutations
void solve(string S, int index, map<string, bool> &ans)
{
    if (index >= S.length())
    {
        ans[S] = true;
        return;
    }
    for (int i = index; i < S.length(); i++)
    {
        swap(S[index], S[i]);
        solve(S, index + 1, ans);
        // backtrack
        swap(S[index], S[i]);
    }
}
vector<string> find_permutation(string S)
{
    map<string, bool> ans;
    int index = 0;
    solve(S, index, ans);
    vector<string> v;
    for (auto i : ans)
    {
        v.push_back(i.first);
    }
    return v;
}
// not unique
void solve(string S, int index, vector<string> &ans)
{
    if (index >= S.length())
    {
        ans.push_back(S);
        return;
    }
    for (int i = index; i < S.length(); i++)
    {
        swap(S[index], S[i]);
        solve(S, index + 1, ans);
        // backtrack
        swap(S[index], S[i]);
    }
}
vector<string> find_permutation(string S)
{
    vector<string> ans;
    int index = 0;
    solve(S, index, ans);
    return ans;
}