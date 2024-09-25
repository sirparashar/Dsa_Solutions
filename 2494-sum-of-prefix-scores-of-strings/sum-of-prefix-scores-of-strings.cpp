

// Define the TrieNode class
class TrieNode {
public:
    unordered_map<char, TrieNode*> children;  // To store child nodes for each character
    int counts;  // To keep track of the count of words passing through each node

    TrieNode() {
        counts = 0;
    }

    // Method to insert a word into the Trie
    void insert(const string& word) {
        TrieNode* curr = this;
        for (char c : word) {
            if (curr->children.find(c) == curr->children.end()) {
                curr->children[c] = new TrieNode();  // Create a new node if character not found
            }
            curr = curr->children[c];
            curr->counts++;  // Increment count at each node as the word passes through
        }
    }

    // Method to search for the prefix score of a word
    int search(const string& word) {
        int res = 0;
        TrieNode* curr = this;
        for (char c : word) {
            curr = curr->children[c];
            res += curr->counts;  // Add counts at each node to the result
        }
        return res;
    }
};

// Define the Solution class
class Solution {
public:
    vector<int> sumPrefixScores(vector<string>& words) {
        TrieNode* root = new TrieNode();  // Create a new Trie root
        vector<int> res;

        // Insert each word into the Trie
        for (const string& word : words) {
            root->insert(word);
        }

        // Calculate the prefix score for each word
        for (const string& word : words) {
            res.push_back(root->search(word));
        }

        return res;
    }
};


