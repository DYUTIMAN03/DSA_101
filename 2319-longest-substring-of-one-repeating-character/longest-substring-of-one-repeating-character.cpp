class Solution {
public:

    struct Node {
        int pref, suff, mx;
        char left, right;

        Node() {
            pref = suff = mx = 0;
            left = right = '#';
        }
    };

    vector<Node> tree;
    string s;

    Node merge(Node a, Node b) {

        Node res;

        res.left = a.left;
        res.right = b.right;

        // Initially, maximum is from either side
        res.mx = max(a.mx, b.mx);

        // Prefix
        res.pref = a.pref;

        // Suffix
        res.suff = b.suff;

        // If boundary characters are same,
        // we can join the suffix of left and prefix of right
        if (a.right == b.left) {

            res.mx = max(res.mx, a.suff + b.pref);

            // If entire left part has same character,
            // prefix can extend into right part
            if (a.pref == getLength(a)) {
                res.pref = a.pref + b.pref;
            }

            // If entire right part has same character,
            // suffix can extend into left part
            if (b.suff == getLength(b)) {
                res.suff = b.suff + a.suff;
            }
        }

        return res;
    }

    // Length of a node is pref/suff only if the entire
    // segment contains the same character.
    // We avoid this approach and store length separately below.

    int getLength(Node x) {
        return 0;
    }

    void build(int node, int l, int r) {

        if (l == r) {
            tree[node].pref = 1;
            tree[node].suff = 1;
            tree[node].mx = 1;
            tree[node].left = s[l];
            tree[node].right = s[l];
            return;
        }

        int mid = (l + r) / 2;

        build(node * 2, l, mid);
        build(node * 2 + 1, mid + 1, r);

        tree[node] = mergeNodes(
            tree[node * 2],
            tree[node * 2 + 1],
            l,
            r,
            mid
        );
    }

    Node mergeNodes(Node a, Node b, int l, int r, int mid) {

        Node res;

        res.left = a.left;
        res.right = b.right;

        res.mx = max(a.mx, b.mx);

        res.pref = a.pref;
        res.suff = b.suff;

        if (a.right == b.left) {

            res.mx = max(res.mx, a.suff + b.pref);

            int leftLength = mid - l + 1;
            int rightLength = r - mid;

            if (a.pref == leftLength) {
                res.pref = a.pref + b.pref;
            }

            if (b.suff == rightLength) {
                res.suff = b.suff + a.suff;
            }
        }

        return res;
    }

    void update(int node, int l, int r, int idx, char ch) {

        if (l == r) {
            tree[node].pref = 1;
            tree[node].suff = 1;
            tree[node].mx = 1;
            tree[node].left = ch;
            tree[node].right = ch;
            return;
        }

        int mid = (l + r) / 2;

        if (idx <= mid) {
            update(node * 2, l, mid, idx, ch);
        }
        else {
            update(node * 2 + 1, mid + 1, r, idx, ch);
        }

        tree[node] = mergeNodes(
            tree[node * 2],
            tree[node * 2 + 1],
            l,
            r,
            mid
        );
    }

    vector<int> longestRepeating(
        string s,
        string queryCharacters,
        vector<int>& queryIndices
    ) {

        this->s = s;

        int n = s.size();

        tree.resize(4 * n);

        build(1, 0, n - 1);

        vector<int> ans;

        for (int i = 0; i < queryIndices.size(); i++) {

            int idx = queryIndices[i];
            char ch = queryCharacters[i];

            update(1, 0, n - 1, idx, ch);

            ans.push_back(tree[1].mx);
        }

        return ans;
    }
};