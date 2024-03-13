#include <iostream>
#include <string>

using namespace std;

struct Node 
{
    char data;
    int frequency;
    Node* left;
    Node* right;
    
    Node(char d, int freq) : data(d), frequency(freq), left(nullptr), right(nullptr) {}
};

struct MinHeapNode 
{
    Node* node;
    MinHeapNode* next;
    MinHeapNode(Node* n) : node(n), next(nullptr) {}
};

class MinHeap 
{
private:
    //MinHeapNode* head;
    
public:
    MinHeap() : head(nullptr) {}
    MinHeapNode* head;
    
    void push(Node* newNode) 
    {
        MinHeapNode* newNodePtr = new MinHeapNode(newNode);
        if (!head || newNode->frequency < head->node->frequency) 
        {
            newNodePtr->next = head;
            head = newNodePtr;
        } 
        else 
        {
            MinHeapNode* current = head;
            while (current->next && current->next->node->frequency <= newNode->frequency) 
            {
                current = current->next;
            }
            newNodePtr->next = current->next;
            current->next = newNodePtr;
        }
    }
    
    Node* pop() 
    {
        if (!head) return nullptr;
        MinHeapNode* temp = head;
        head = head->next;
        Node* poppedNode = temp->node;
        delete temp;
        return poppedNode;
    }
    
    bool isEmpty() 
    {
        return head == nullptr;
    }
};

Node* buildHuffmanTree(char data[], int freq[], int size) 
{
    MinHeap minHeap;
    for (int i = 0; i < size; ++i) 
    {
        minHeap.push(new Node(data[i], freq[i]));
    }
    
    while (!minHeap.isEmpty() && minHeap.head->next) 
    {
        Node* left = minHeap.pop();
        Node* right = minHeap.pop();
        
        Node* parent = new Node('$', left->frequency + right->frequency);
        parent->left = left;
        parent->right = right;
        
        minHeap.push(parent);
    }
    
    return minHeap.pop();
}

void generateCodes(Node* root, string code, string codes[]) 
{
    if (!root) return;
    
    if (root->data != '$') 
    {
        codes[root->data - 'a'] = code;
    }
    
    generateCodes(root->left, code + "0", codes);
    generateCodes(root->right, code + "1", codes);
}

void huffmanCodes(char data[], int freq[], int size) 
{
    Node* root = buildHuffmanTree(data, freq, size);
    string codes[26];
    
    generateCodes(root, "", codes);
    
    cout << "Character code-word:" << endl;
    for (int i = 0; i < size; ++i) 
    {
        cout << data[i] << " " << codes[data[i] - 'a'] << endl;
    }
}

int main() 
{
    char data[] = {'a', 'b', 'c', 'd', 'e', 'f'};
    int freq[] = {5, 9, 12, 13, 16, 45};
    int size = sizeof(data) / sizeof(data[0]);
    
    huffmanCodes(data, freq, size);
    
    return 0;
}
