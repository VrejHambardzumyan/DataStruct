#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

class TrieNode {
public:
    bool isEndOfWord;
     unordered_map<char, TrieNode*> children;

    TrieNode() {
        isEndOfWord = false;
    }

    ~TrieNode() {
        for (auto& pair : children) {
            delete pair.second;
        }
    }
};

class Trie {
private:
    TrieNode* root;

    bool deleteHelper(TrieNode* node, const  string& word, int depth) {
        if (!node) return false;

        if (depth == word.size()) {
            if (!node->isEndOfWord) return false;
            node->isEndOfWord = false;

            return node->children.empty();
        }

        char ch = word[depth];
        TrieNode* child = node->children[ch];
        if (!child) return false;

        bool shouldDeleteChild = deleteHelper(child, word, depth + 1);

        if (shouldDeleteChild) {
            delete child;
            node->children.erase(ch);

            return !node->isEndOfWord && node->children.empty();
        }

        return false;
    }

public:
    Trie() {
        root = new TrieNode();
    }

    ~Trie() {
        delete root;
    }

    void insert(const  string& word) {
        TrieNode* node = root;
        for (char ch : word) {
            if (!node->children.count(ch)) {
                node->children[ch] = new TrieNode();
            }
            node = node->children[ch];
        }
        node->isEndOfWord = true;
    }

    bool search(const  string& word) const {
        TrieNode* node = root;
        for (char ch : word) {
            if (!node->children.count(ch)) return false;
            node = node->children.at(ch);
        }
        return node->isEndOfWord;
    }

    bool startsWith(const  string& prefix) const {
        TrieNode* node = root;
        for (char ch : prefix) {
            if (!node->children.count(ch)) return false;
            node = node->children.at(ch);
        }
        return true;
    }

    bool deleteWord(const  string& word) {
        return deleteHelper(root, word, 0);
    }
};
int main() {
    Trie trie;
    trie.insert("hello");
    trie.insert("hell");
    trie.insert("he");

     cout <<  boolalpha;
     cout << "Search 'hello': " << trie.search("hello") << "\n";

    trie.deleteWord("hello");
     cout << "Search 'hello' after delete: " << trie.search("hello") << "\n";
     cout << "Search 'hell': " << trie.search("hell") << "\n";
     cout << "Search 'he': " << trie.search("he") << "\n";

    trie.deleteWord("he");
    cout << "Search 'he' after delete: " << trie.search("he") << "\n";
    cout << "Prefix 'he': " << trie.startsWith("he") << "\n";

}