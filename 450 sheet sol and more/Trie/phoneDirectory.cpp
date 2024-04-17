class Solution
{
public:
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

        void printSuggestions(TrieNode *curr, vector<string> &temp, string prefix)
        {
            if (curr->isTerminal)
            {
                temp.push_back(prefix);
                // no return because this is terminal for only one word. there can be more child
            }

            for (char ch = 'a'; ch <= 'z'; ch++)
            { // search for any char between a and z that is child of curr
                TrieNode *next = curr->children[ch - 'a'];

                if (next != NULL)
                {
                    // push in prefix the characters found
                    prefix.push_back(ch);
                    printSuggestions(next, temp, prefix);
                    // remove when backtracking to obtain other suggestions
                    prefix.pop_back();
                }
            }
        }

        vector<vector<string>> getSuggestions(string s)
        {
            // prev node to help find the curr char of query string. It tells that if the current char is present or not.
            TrieNode *prev = root;
            string prefix = "";

            vector<vector<string>> output;
            for (int i = 0; i < s.size(); i++)
            {
                char lastCh = s[i];
                prefix.push_back(s[i]);

                TrieNode *curr = prev->children[lastCh - 'a'];

                if (curr == NULL)
                {
                    break;
                }
                else
                {
                    vector<string> temp;
                    printSuggestions(curr, temp, prefix);
                    output.push_back(temp);
                    temp.clear();
                    prev = curr;
                }
            }
            int remaining = s.size() - output.size();
            for (int i = 0; i < remaining; i++)
            {
                output.push_back({"0"});
            }
            return output;
        }
    };

    vector<vector<string>> displayContacts(int n, string contact[], string s)
    {
        Trie *t = new Trie();

        // insert in trie
        for (int i = 0; i < n; i++)
        {
            t->insert(contact[i]);
        }

        return t->getSuggestions(s);
    }
};