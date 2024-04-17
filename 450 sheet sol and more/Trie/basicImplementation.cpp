class TrieNode
{
public:
    char data;
    TrieNode *children[26];
    bool isTerminal;

    TrieNode(char ch)
    {
        this->data = ch;
        for (int i = 0; i < 26; i++)
        {
            children[i] = NULL;
        }
        isTerminal = false;
    }
};

class Trie
{
    TrieNode *root;

public:
    /** Initialize your data structure here. */
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

    bool searchWordUtil(TrieNode *root, string word)
    {
        if (word.length() == 0)
        {
            return root->isTerminal;
        }

        int index = word[0] - 'a';
        TrieNode *child;
        if (root->children[index] != NULL)
        {
            child = root->children[index];
        }
        else
        {
            return false;
        }

        // recursion
        return searchWordUtil(child, word.substr(1));
    }
    /** Returns if the word is in the trie. */
    bool searchWord(string word)
    {
        return searchWordUtil(root, word);
    }

    bool startsWithUtil(TrieNode *root, string prefix)
    {
        if (prefix.length() == 0)
        {
            return true;
        }
        int index = prefix[0] - 'a';
        TrieNode *child;
        if (root->children[index] != NULL)
        {
            child = root->children[index];
        }
        else
        {
            return false;
        }

        // recursion
        return startsWithUtil(child, prefix.substr(1));
    }
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix)
    {
        return startsWithUtil(root, prefix);
    }

    void deleteWord(string word)
    {
        if (searchWord(word) == true)
        {
            int index = word[0] - 'A';
            TrieNode *temp = root->children[index];
            root->children[index] = NULL;
            delete temp;
        }
        else
            return;
    }
};
