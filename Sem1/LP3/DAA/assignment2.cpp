#include<iostream>
#include<vector>
#include<unordered_map>
#include<queue>

using namespace std;

class Node{
    public:
    Node *left;
    Node *right;

    char data;
    int freq;

    Node(char data,int freq){
        this->data = data;
        this->freq = freq;
        this->left = NULL;
        this->right = NULL;
    }
};

class Compare{
    public:
    bool operator()(Node *&a, Node *&b){
        return a->freq > b->freq;
    }
};

class Huffman{
    Node *root = NULL;
    unordered_map<char,string> huffmanCodes;

    public:

    void buildTree(string text){
        unordered_map<char,int> mpp;
        for(auto ch: text){
            mpp[ch]++;
        }
        priority_queue<Node*,vector<Node*>,Compare> pq;
        for(auto it: mpp){
            pq.push(new Node(it.first,it.second));
        }

        while(pq.size() > 1){
            Node *l = pq.top();
            pq.pop();
            Node *r = pq.top();
            pq.pop();

            int sum = l->freq;
            if(r!=NULL){
                sum += r->freq;
            }
            Node *rNode = new Node('\0',sum);
            rNode->left = l;
            rNode->right = r;
            pq.push(rNode);
        }

        root = pq.top();

        generateCode(root,"");
    }

    void generateCode(Node *root,string code){
        if(root == NULL) return;
        if(root->left == NULL && root->right == NULL){
            huffmanCodes[root->data] = code;
            return;
        }
        generateCode(root->left,code + "0");
        generateCode(root->right,code + "1");
    }

    string encode(string text){
        string ans;
        for(char ch: text){
            ans += huffmanCodes[ch];
        }

        return ans;
    }

    string decode(string text){
        string ans;
        Node *temp = root;

        for(char bit: text){
            if(bit == 0){
                temp = temp->left;
            }
            else{
                temp = temp->right;
            }
            if(temp->left == NULL && temp->right == NULL){
                ans += temp->data;
                temp = root;
            }
        }
        return ans;
    }

    void printCodes(){
        for(auto it: huffmanCodes){
            if(it.first == ' '){
                cout<<"Space    : "<<it.second<<endl;
            }
            else{
                cout<<it.first<<" : "<<it.second<<endl;
            }
        }
    }
};

int main(){
    string input;
    cout<<"Enter string: \n";
    getline(cin,input);

    Huffman h;
    h.buildTree(input);

    cout<<"Table: \n";
    h.printCodes();
    cout<<endl;

    cout<<"Enter text to encode : ";
    string enc;
    getline(cin,enc);
    string encodedString=h.encode(enc);
    cout<<"Encoded string : "<<encodedString<<endl;
    cout<<endl;

    string dec;
    cout<<"Enter string to decode : ";
    getline(cin,dec);
    string decodedString=h.decode(dec);
    cout<<"Decoded string : "<<decodedString<<endl;
    cout<<endl;

    return 0;
}