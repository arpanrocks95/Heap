#include <iostream>
#include <string>
#include <queue>
#include <unordered_map>
using namespace std;

struct Node
{
    char ch;
    int freq;
    struct Node * left;
    struct Node * right;
};

Node * newNode(char ch,int freq ,Node * left,Node* right){
    Node * temp = (Node *) malloc(sizeof(Node));
    temp->ch = ch;
    temp->freq = freq;
    temp->left = left;
    temp->right = right;
    return temp;
}

struct comp {
    bool operator()(Node * left ,Node * right) {return left->freq > right->freq;}
};

void encode (Node * root,string str,unordered_map  <char ,string > & huffmanCode){
    if(root == NULL) return;
    if(!root->left && !root->right) huffmanCode[root->ch] = str;
    encode(root->left,str + '0',huffmanCode);
    encode(root->right,str + '1',huffmanCode);
}

void decode(Node * root,int &index,string str){
    if(root == NULL) return;
    if(!root->left && !root->right) {cout << root->ch;return;}
    index++;
    if(str[index] == '0') decode(root->left,index,str);
    else decode(root->right,index,str);
}

void buildHuffmanTree(string text){
    unordered_map <char,int> freq;
    for(char ch : text) freq[ch]++;
//for(auto ch: freq) cout << ch.first << " " << ch.second << "\n";
    priority_queue<Node*, vector<Node*>, comp> pq;
    for(auto pair:freq) pq.push(newNode(pair.first,pair.second,NULL,NULL));

    while (pq.size() != 1){
        Node * left = pq.top();pq.pop();
        Node * right = pq.top();pq.pop();
  //      cout << left->ch <<" : " << left->freq << " , "<<right->ch << " : " <<right->freq << "\n";
        int sumOfFreq = left->freq + right->freq;
        pq.push(newNode('\0',sumOfFreq,left,right));
    }

    Node * root = pq.top();
    unordered_map <char,string> huffmancode;
    encode(root,"",huffmancode);

    cout << "Huffmancodes are : \n";
    for(auto &i : huffmancode) cout << i.first << " : " << i.second << "\n";

    cout <<"Original String was : "<<text<<"\n";

    string str = "";
    for(auto &i : text) str += huffmancode[i] ;
    cout << "\nEncoded string is :\n" << str << '\n';

    int index = -1;
    cout << "\nDecoded string is: ";
    while (index < (int)str.size() - 2) {
        decode(root, index, str);
    }
}
// Huffman coding algorithm
int main()
{
    string text = "Huffman coding is a data compression algorithm.";

    buildHuffmanTree(text);

    return 0;
}