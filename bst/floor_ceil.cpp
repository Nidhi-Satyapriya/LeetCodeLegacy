class Solution {
public:
    vector<int> floorCeilOfBST(TreeNode* root, int key) {
        int floor = -1, ceil = -1;
        TreeNode* curr = root;

        // Find ceil
        while (curr) {
            if (curr->data == key) {
                ceil = curr->data;
                break;
            }
            if (curr->data > key) {
                ceil = curr->data;
                curr = curr->left;
            } else {
                curr = curr->right;
            }
        }

        curr = root;

        // Find floor
        while (curr) {
            if (curr->data == key) {
                floor = curr->data;
                break;
            }
            if (curr->data < key) {
                floor = curr->data;
                curr = curr->right;
            } else {
                curr = curr->left;
            }
        }

        return {floor, ceil};
    }
};
