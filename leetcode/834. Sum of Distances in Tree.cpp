class Solution {
public:
    vector<int> sumOfDistancesInTree(int N, vector<vector<int>>& edges) {
        vector<vector<int>> tree(N);
        for (auto v : edges) {
            tree[v[0]].push_back(v[1]);
            tree[v[1]].push_back(v[0]);
        }
        vector<int> count(N), res(N);
        dfs1(tree, 0, -1, count, res);
        dfs2(tree, 0, -1, count, res);
        return res;
    }
    
    void dfs1(vector<vector<int>> &tree, int curr, int pre, vector<int> &count, vector<int> &res) {
        for (int i : tree[curr]) {
            if (i == pre) continue;
            dfs1(tree, i, curr, count, res);
            count[curr] += count[i];
            res[curr] += count[i] + res[i];
        }
        ++count[curr];
    }
    
    void dfs2(vector<vector<int>> &tree, int curr, int pre, vector<int> &count, vector<int> &res) {
        for (int i : tree[curr]) {
            if (i == pre) continue;
            res[i] = res[curr] - count[i] + count.size() - count[i];
            dfs2(tree, i, curr, count, res);
        }
    }
};

/*
https://www.cnblogs.com/grandyang/p/11520804.html

count[root] = sum(count[i]) + 1  // i the children of root, usual tree, not neighbor

res[root] = sum(res[i]) + sum(count[i])  // i is the neighbor of root
for every node in substree of i, dist(root, node) = dist(i, node) + 1, and there are count[i] nodes (include i)

dfs1 is a postorder traversal:
虽然现在还没有更新所有的 res[i]，但是有一个结点的 res 值是正确的，就是整个树的根结点，这个真正的 res[root] 值是正确的！

dfs2 is a preorder traversal:
res[i] = res[root] - count[i] + N - count[i]
此以结点i为根结点的子树的总结点个数为 count[i]，而这 count[i] 个结点之前在算 res[root] 时是到根结点 root 的距离，
但是现在只要计算到结点i的距离，所以这 count[i] 个结点的距离都少了1，
而其他所有的结点，共 N - count[i] 个，离结点i的距离比离 root 结点的距离都增加了1
*/