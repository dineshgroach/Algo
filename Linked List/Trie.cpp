// If have to use Trie via global declaration
class Trie {
public:
    Trie *child[26];
    bool isEnd = false;
    Trie()
    {
        for(int i = 0; i < 26; i++)
        {
            child[i] = NULL;
        }
    }

    void insert(string& s)
    {
        Trie* Node = this;
        for(char& c:s)
        {
            if(!Node->child[c-'a'])
            {
                Node->child[c-'a'] = new Trie();
            }
            Node = Node->child[c-'a'];
        }
        Node->isEnd = true;
    }
};
// Declaration be like
Trie* trie = new Trie();
// Trie Implementation in classes using C++
struct Node
{
    Node* links[26];
    int endsWith = 0;
    int startPrefix = 0;

    bool isContains(char ch)
    {
        return (links[ch-'a']!=NULL);
    }

    void put(char ch,Node* node)
    {
        links[ch-'a'] = node;
    }

    Node* get(char ch)
    {
        return links[ch-'a'];
    }

    void increaseEnd()
    {
        endsWith++;
    }

    void increasePrefix()
    {
        startPrefix++;
    }

    void deleteEnd()
    {
        endsWith--;
    }

    void decreasePrefix()
    {
        startPrefix--;
    }

    int getPrefix()
    {
        return startPrefix;
    }

    int getEnd()
    {
        return endsWith;
    }
};

class Trie{
    private:
    Node* root;
    public:

    Trie(){
        root = new Node();
    }

    void insert(string &word){
        Node* node = root;
        for(int i = 0;i < word.size();i++)
        {
            if(!node->isContains(word[i]))
            {
                node->put(word[i],new Node());
            }
            node = node->get(word[i]);
            node->increasePrefix();
        }
        node->increaseEnd();
    }

    int countWordsEqualTo(string &word){
        Node* node = root;
        for(int i = 0;i < word.size();i++)
        {
            if(node->isContains(word[i]))
            {
                node = node->get(word[i]);
            }
            else
            {
                return 0;
            }
        }
        return node->getEnd();
    }

    int countWordsStartingWith(string &word){
        Node* node = root;
        for(int i = 0;i < word.size();i++)
        {
            if(node->isContains(word[i]))
            {
                node = node->get(word[i]);
            }
            else
            {
                return 0;
            }
        }
        return node->getPrefix();
    }

    void erase(string &word){
        Node* node = root;
        for(int i = 0;i < word.size();i++)
        {
            if(node->isContains(word[i]))
            {
                node = node->get(word[i]);
                node->decreasePrefix();
            }
            else
            {
                return;
            }
        }
        node->deleteEnd();
    }
};
