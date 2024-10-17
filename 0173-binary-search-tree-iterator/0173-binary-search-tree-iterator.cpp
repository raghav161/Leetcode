class BSTIterator {
public:
    stack<TreeNode*> myStack;
    void pushAll(TreeNode *node) {
        while(node)
        {
            myStack.push(node);
            node = node->left;
        }
    }

    BSTIterator(TreeNode *root) {
        pushAll(root);
    }

    bool hasNext() {
        return !myStack.empty();
    }

    int next() {
        TreeNode *tmpNode = myStack.top();
        myStack.pop();
        pushAll(tmpNode->right);
        return tmpNode->val;
    }
};