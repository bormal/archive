// https://www.hackerrank.com/challenges/swap-nodes-algo/submissions/code/137710356

#include <bits/stdc++.h>

using namespace std;

typedef vector<vector<int>> Tree;

class Solution 
{
    public:
        Solution(ofstream & fout) : _fout(fout) {}
        void readTree();
        void readQueries();

        void printTree() const;
        void printQueries() const;
        void printInOrder() const;

        void swapNodes();

    private:
        void printSubTree(int link) const;
        void swapNodesQ(int link, int query, int depth);
        bool isNeedSwap(int query, int depth);

        Tree _tree;
        vector<int> _queries;
        ofstream & _fout;
};

bool Solution::isNeedSwap(int query, int depth)
{
    bool result = (depth % query) == 0;
    // cout << "? " << query << " " << depth << " = " << result << endl;
    return result;
}

void Solution::swapNodesQ(int link, int query, int depth)
{
    int index = link - 1;
    // cout << "swapNodesQ " << link << " q: " << query << 
        // " depth " << depth << endl;
    if(link == -1) {
        return;
    }   

    vector<int> node = _tree[index];
    // cout << "node: " << node[0] << " " << node[1] << endl;

    swapNodesQ(node[0], query, depth + 1);
    swapNodesQ(node[1], query, depth + 1);

    if(isNeedSwap(query, depth)) {
    // cout << "=YES= " << index << " q: " << query << " depth " << depth <<endl;
        // printTree();
        int tmp = node[0];
        node[0] = node[1];
        node[1] = tmp;
        _tree[index] = node;
        // printTree();
        // printInOrder();
        // exit(0);
    }
    // else 
    // cout << "no! " << index << " q: " << query << " depth " << depth <<endl;

}

//=============================================
void Solution::swapNodes()
{
    for(auto q : _queries) {
        swapNodesQ(1, q, 1);
        printInOrder();
    }
}
//=============================================
void Solution::printSubTree(int link) const
{
    if(link == -1) {
        return;
    }

    vector <int> node = _tree[link - 1];
    printSubTree(node[0]);
    _fout << link << " ";
    printSubTree(node[1]);
}

//=============================================
void Solution::printQueries() const
{
    for(auto const & q : _queries) {
        cout << q << endl;
    }
}

//=============================================
void Solution::readQueries()
{
    int n;
    cin >> n;
    for(int i = 0; i < n; ++i) {
        int q;
        cin >> q;
        _queries.push_back(q);
    }
}

//=============================================
void Solution::printInOrder() const
{
    printSubTree(1);
    _fout << endl;
}

//=============================================
void Solution::readTree()
{
    int n;
    cin >> n;
    for(int i = 0; i < n; ++i) {
        vector<int> node(2);
        cin >> node[0] >> node[1];
        _tree.push_back(node);
    }
    // cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

//=============================================
void Solution::printTree() const
{
    for(auto const & node: _tree) {
        cout << node[0] << " - " << node[1] << endl;
    }
}

//=============================================
//=============================================
//=============================================

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    Solution s(fout);

    s.readTree();
    // s.printTree();

    s.readQueries();
    // s.printQueries();

    s.swapNodes();
    // s.printInOrder();
 
    return 0;
}
