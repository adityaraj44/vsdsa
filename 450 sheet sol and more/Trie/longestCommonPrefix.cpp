// approach 1 (no trie)
string longestCommonPrefix(vector<string> &arr, int n)
{
    string ans;
    // for traversing all chars of first string
    for (int i = 0; i < arr[0].length(); ++i)
    {
        char ch = arr[0][i];

        bool match = true;

        // for comparing ch with rest of the strings
        for (int j = 1; j < n; j++)
        {
            if (arr[j].size() < i || ch != arr[j][i])
            {
                match = false;
                break;
            }
        }
        if (match == false)
        {
            break;
        }
        else
            ans.push_back(ch);
    }
    return ans;
}

// approach 2 using tries
class TrieNode
{
public:
    char data;
    TrieNode *children[26];
    int childCount;
    bool isTerminal;

    TrieNode(char ch)
    {
        data = ch;
        for (int i = 0; i < 26; i++)
        {
            children[i] = NULL;
        }
        isTerminal = false;
        childCount = 0;
    }
};

class Trie
{
public:
    TrieNode *root;
    Trie()
    {
        root = new TrieNode('\0');
    }

    void insertUtil(TrieNode *root, string word)
    {
        if (word.length() == 0)
        {
            root->isTerminal = true;
            return;
        }

        // assumption word will be in uppercase
        int index = word[0] - 'a';
        TrieNode *child;

        // present
        if (root->children[index] != NULL)
        {
            child = root->children[index];
        }
        else
        {
            // absent
            child = new TrieNode(word[0]);
            root->childCount++;
            root->children[index] = child;
        }

        // recursion
        insertUtil(child, word.substr(1));
    }
    /** Inserts a word into the trie. */
    void insert(string word)
    {
        insertUtil(root, word);
    }

    void lcp(string str, string &ans)
    {
        for (int i = 0; i < str.length(); i++)
        {
            char ch = str[i];

            if (root->childCount == 1)
            {
                ans.push_back(ch);
                // aage badhjao
                int index = ch - 'a';
                root = root->children[index];
            }
            else
                break;

            if (root->isTerminal)
            {
                break;
            }
        }
    }
};

string longestCommonPrefix(vector<string> &arr, int n)
{
    Trie *t = new Trie();
    for (int i = 0; i < n; i++)
    {
        if (arr[i].empty())
        {
            return "";
        }
        t->insert(arr[i]);
    }

    string ans = "";
    string first = arr[0];
    t->lcp(first, ans);
    return ans;
}
