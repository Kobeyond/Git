#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

// 定义二叉树的数据结构
struct TreeNode {
    // 定义数据成员: 节点的值, 节点的左右儿子指针
    int val;
    TreeNode *left;
    TreeNode *right;

    // 定义不同参数的构造函数
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int _val) : val(_val), left(nullptr), right(nullptr) {}
    TreeNode(int _val, TreeNode *_left, TreeNode *_right) : val(_val), left(_left), right(_right) {}
};

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> res;
        // 用i1和i2指针限定上下的边界, j1和j2限定左右的边界
        int i1 = 0, i2 = matrix.size() - 1;
        int j1 = 0, j2 = matrix[0].size() - 1;

        while (1) {
            for (int j = j1; j <= j2; j++) res.push_back(matrix[i1][j]); // 上边界(正序)
            if (++i1 > i2) break;
            for (int i = i1; i <= i2; i++) res.push_back(matrix[i][j2]); // 右边界(正序)
            if (--j2 < j1) break;
            for (int j = j2; j >= j1; j--) res.push_back(matrix[i2][j]); // 下边界(逆序)
            if (--i2 < i1) break;
            for (int i = i2; i >= i1; i--) res.push_back(matrix[i][j1]); // 左边界(逆序)
            if (++j1 > j2) break;
        }
        return res;
    }
};
int main() {
    vector<vector<int>> matrix;
    matrix.push_back({1, 2, 3});
    matrix.push_back({5, 6, 7});
    matrix.push_back({9, 10, 11});
    cout << "Input matrix: " << endl;
    for (int i = 0; i < matrix.size(); i++) {
        for (int j = 0; j < matrix[0].size(); j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    Solution* s = new Solution();
    vector<int> res = s->spiralOrder(matrix);
    cout << endl << "Output: " << endl;
    for (int i = 0; i < res.size(); i++) {
        cout << res[i] << " ";
    }
}