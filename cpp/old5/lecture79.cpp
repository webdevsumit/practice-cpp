#include<iostream>

using namespace std;

class TrieNode {
    public:
        char data;
        TrieNode * children[26];
        bool isTerminal;

        TrieNode(char ch){
            data = ch;
            for(int i=0; i<26; i++){
                children[i] = NULL;
            }
            isTerminal = false; 
        }
};


class Trie {
    public:
    TrieNode * root;

    Trie(){
        root = new TrieNode('\0');
    }
    
    void insertUtil(TrieNode* root, string word){
        // base case
        if(word.length() == 0){
            root->isTerminal = true;
            return;
        }

        // assumption
        int index = word[0] - 'A';
        TrieNode* child;

        if(root -> children[index] != NULL){
            // Present
            child = root->children[index];
        }
        else{
            // absent
            child = new TrieNode(word[0]);
            root->children[index] = child;
        }

        // Recursion
        insertUtil(child, word.substr(1));
    }
    
    void insertWord(string word){
         insertUtil(root, word);
    }

    bool searchUtil(TrieNode* root, string word){
        // base case
        if(word.length() == 0){
            return root->isTerminal;
        }

        int index = word[0] - 'A';
        TrieNode* child;

        if(root ->children[index] != NULL){
            child = root->children[index];
        }else return false;

        // Recursion
        return searchUtil(child, word.substr(1));

    }

    bool searchWord(string word){
        return searchUtil(root, word);
    }

    void removeUtil(TrieNode* root, string word){
        // base case
        if(word.length() == 0){
            root->isTerminal = false;
            return;
        }

        int index = word[0] - 'A';
        TrieNode* child;

        if(root->children[index] != NULL){
            child = root->children[index];
        }else return;

        // cout<< "word : " << word[0] <<endl;

        // Recursion
        removeUtil(child, word.substr(1)); 

    }

    void removeWord(string word){
        removeUtil(root, word);
    }

};

int main(){

    Trie *t = new Trie();
    t->insertWord("ABCE");
    t->insertWord("HKL");
    t->insertWord("SUMIT");

    cout << "Present or not : " << t->searchWord("SUMIT") <<endl;
    t->removeWord("SUMIT");
    cout << "Present or not : " << t->searchWord("SUMIT") <<endl;

    return 0;
}