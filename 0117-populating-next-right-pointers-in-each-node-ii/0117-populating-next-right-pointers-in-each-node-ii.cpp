/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) 
    {
        if(root==NULL) 
            return root;
        queue<Node*> nodes;
        nodes.push(root);
        Node *cur;
        while(!nodes.empty())
        {
            int size = nodes.size();            
            while(size--)
            {
                cur = nodes.front();
                nodes.pop();
                if(!nodes.empty())
                    cur->next = nodes.front();
                if(cur->left)
                    nodes.push(cur->left);
                if(cur->right)
                    nodes.push(cur->right);
                if(size==0)
                    cur->next=NULL;
            }
        }
        return root;
    }
};