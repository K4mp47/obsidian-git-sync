#include <iostream>
#include <iomanip>
#include <vector>
#include <complex>
#include <random>

// sottolineo che per le funzioni occorre capire se radice = altezza 0 oppure 1

struct Node
{
    int key;
    char color;
    Node *left, *right, *parent;
};

class Tree
{
    Node *root;

private:
    void del(Node *x)
    {
        // remove node x
        if (x == nullptr)
        {
            del(x->left);
            del(x->right);
            delete x;
        }
    }

    void printTree(Node *node, int depth) const
    {
        if (node == nullptr)
            return;

        // Print right subtree first
        printTree(node->right, depth + 1);

        // Print current node with indentation
        std::cout << std::setw(4 * depth) << "" << node->key << node->color << std::endl;

        // Print left subtree
        printTree(node->left, depth + 1);
    }

    Node *insertAux(Node *x, int key)
    {
        if (x == nullptr)
        {
            x = new Node{key, 'n', nullptr, nullptr, nullptr};
        }
        else if (key < x->key)
        {
            x->left = insertAux(x->left, key);
            x->left->parent = x;
        }
        else if (key > x->key)
        {
            x->right = insertAux(x->right, key);
            x->right->parent = x;
        }
        return x;
    }

    Node *buildBst(std::vector<int> arr, int inf, int sup, Node *x)
    {
        if (inf > sup)
            return nullptr;
        int med = (inf + sup) / 2;
        Node *r = new Node{arr[med], (std::random_device{}() % 2 == 0) ? 'n' : 'b', nullptr, nullptr, nullptr};
        r->parent = x;
        r->left = buildBst(arr, inf, med - 1, r);
        r->right = buildBst(arr, med + 1, sup, r);
        return r;
    }

    int isCompleteAux(Node *x)
    {
        if (x == nullptr)
            return 0;
        return isCompleteAux(x->left) + isCompleteAux(x->right) + 1;
    }

    int sameColorsAux(Node *x, int &b, int &n)
    {
        int bt = 0, nt = 0;
        if (x == nullptr)
            return 0;
        if (x->color == 'n')
            nt++;
        else
            bt++;
        int l = sameColorsAux(x->left, bt, nt);
        int r = sameColorsAux(x->right, bt, nt);
        b += bt;
        n += nt;
        return l + r + ((bt == nt) ? 1 : 0);
    }

    int intermediAux(Node *r, int totb, int &nodes)
    {
        if (r == nullptr)
            return 0;
        int l = intermediAux(r->left, r->key + totb, nodes);
        int l2 = intermediAux(r->right, r->key + totb, nodes);
        if ((l + l2) == totb)
            nodes++;
        return l + l2 + r->key;
    }

public:
    Tree() : root(nullptr) {}
    Tree(int key) : root(new Node{key, 'n', nullptr, nullptr, nullptr}) {}
    Tree(Node *x) : root(x) {}
    Tree(std::vector<int> arr)
    {
        // root = buildBst(arr, 0, arr.size() - 1, nullptr);
        root = buildBst(arr, 0, arr.size() - 1, nullptr);
    }
    ~Tree()
    {
        // delete all nodes
        del(this->root);
    }

    Node *getRoot()
    {
        return root;
    }

    int height(Node *x)
    {
        if (x == nullptr)
            return 0;
        int hl = height(x->left);
        int hr = height(x->right);
        return 1 + ((hl > hr) ? hl : hr);
    }

    bool isComplete()
    {
        int h = height(root);
        int nodes = isCompleteAux(root);

        std::cout << h << " " << nodes << std::endl;

        return pow(h, 2) - 1 == nodes;
    }

    Node *search(Node *x, int key)
    {
        // search for key
        if (x == nullptr || key == x->key)
            return x;
        if (key < x->key)
            return search(x->left, key);
        else
            return search(x->right, key);
    }
    Node *search(int key)
    {
        return search(root, key);
    }

    Node *minimun(Node *x)
    {
        // find the node with the smallest key
        while (x->left != nullptr)
            x = x->left;
        return x;
    }
    Node *minimun()
    {
        return minimun(root);
    }

    Node *maximum(Node *x)
    {
        // find the node with the largest key
        while (x->right != nullptr)
            x = x->right;
        return x;
    }
    Node *maximum()
    {
        return maximum(root);
    }

    Node *successor(Node *x)
    {
        if (x->right != nullptr)
            return minimun(x->right);
        Node *y = x->parent;
        while (y != nullptr && x == y->right)
        {
            x = y;
            y = y->parent;
        }
    }

    Node *predecessor(Node *x)
    {
        if (x->left != nullptr)
            return maximum(x->left);
        Node *y = x->parent;
        while (y != nullptr && x == y->left)
        {
            x = y;
            y = y->parent;
        }
    }

    void insert(int key)
    {
        root = insertAux(root, key);
    }

    void inorderTreeWalk(Node *x)
    {
        if (x != nullptr)
        {
            inorderTreeWalk(x->left);
            std::cout << x->color << " ";
            inorderTreeWalk(x->right);
        }
    }

    void print()
    {
        for (int i = 0; i < 20; ++i)
            std::cout << "-";
        std::cout << std::endl;
        printTree(root, 0);
        std::cout << std::endl;
        for (int i = 0; i < 20; ++i)
            std::cout << "-";
        std::cout << std::endl;
    }

    int sameColors(Node *x)
    {
        int b = 0, n = 0;
        return sameColorsAux(x, b, n);
    }

    int intermedi(Node *r)
    {
        int nodes = 0;
        intermediAux(r, 0, nodes);
        return nodes;
    }
};

void merge(std::vector<int> &arr, int inf, int med, int sup)
{
    int n1 = med - inf + 1;
    int n2 = sup - med;
    std::vector<int> L(n1), R(n2);
    for (int i = 0; i < n1; i++)
        L[i] = arr[inf + i];
    for (int i = 0; i < n2; i++)
        R[i] = arr[med + 1 + i];

    int i = 0;
    int j = 0;
    int k = inf;

    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergesort(std::vector<int> &arr, int inf, int sup)
{
    if (inf < sup)
    {
        int med = (inf + sup) / 2;
        mergesort(arr, inf, med);
        mergesort(arr, med + 1, sup);
        merge(arr, inf, med, sup);
    }
}

int finder(Node *x, int key)
{
    if (x == nullptr)
        return 0;
    if (x->key == key)
        return 1;
    if (key < x->key)
        return 1 + finder(x->left, key);
    return 1 + finder(x->right, key);
}

int heightFinder(Tree t, Node *x)
{
    return finder(t.getRoot(), x->key);
}

int alzettaNodi(Node *x, int k)
{
    if (x == nullptr)
        return 0;
    if (k == 0)
        return 1;
    return alzettaNodi(x->left, k - 1) + alzettaNodi(x->right, k - 1);
}

std::vector<int> cercaPari(Node *x)
{
    if (x == nullptr)
        return {};
    std::vector<int> numsp;
    std::vector<int> l = cercaPari(x->left);
    if (x->key % 2 == 0)
        numsp.push_back(x->key);
    std::vector<int> r = cercaPari(x->right);
    l.insert(l.end(), numsp.begin(), numsp.end());
    l.insert(l.end(), r.begin(), r.end());
    return l;
}

Tree copiaPari(Tree t)
{
    auto buildBST = [](const std::vector<int> &arr, int inf, int sup, Node *x, auto &self) -> Node *
    {
        if (inf > sup)
            return nullptr;
        int med = (inf + sup) / 2;
        Node *r = new Node{arr[med], (std::random_device{}() % 2 == 0) ? 'n' : 'b', nullptr, nullptr, nullptr};
        r->parent = x;
        r->left = self(arr, inf, med - 1, r, self);
        r->right = self(arr, med + 1, sup, r, self);
        return r;
    };

    std::vector<int> numsp = cercaPari(t.getRoot());
    return Tree(buildBST(numsp, 0, numsp.size() - 1, nullptr, buildBST));
}

void mergemod(std::vector<int> &arr, int inf, int med, int sup)
{
    int n1 = med - inf + 1;
    int n2 = sup - med;
    std::vector<int> L(n1), R(n2);
    for (int i = 0; i < n1; i++)
        L[i] = arr[inf + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[med + 1 + j];
    
    int i = 0, j = 0, k = inf;
    while (i < n1 && j < n2)
    {
        if ((L[i] % 3) <= (R[j] % 3))
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergesortmod(std::vector<int> &arr, int inf, int sup)
{
    if (inf < sup)
    {
        int med = (inf + sup) / 2;
        mergesortmod(arr, inf, med);
        mergesortmod(arr, med + 1, sup);
        mergemod(arr, inf, med, sup);
    }
}

int main()
{
    std::vector<int> arr = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15};
    std::vector<int> arr2 = {20, 14, 6, 5, 8, 9, 7, 4, 2, 15, 18, 19, 16, 21, 22};
    std::vector<int> arr3 = {20, 14, 6, 5, 8, 9, 7, 4, 2, 15, 18, 19, 16, 21, 22};

    mergesort(arr2, 0, arr2.size() - 1);

    mergesortmod(arr3, 0, arr3.size() - 1);

    for( auto num : arr3)
        std::cout << num << " ";
    std::cout << std::endl;

    // for (int i = 0; i < arr2.size(); i++)
    // {
    //     std::cout << arr2[i] << " ";
    // }
    // Tree t(arr2);
    // // t.insert(16);
    // t.inorderTreeWalk(t.getRoot());

    // std::cout << "Tree: " << std::endl;
    // t.print();
    // std::cout << t.intermedi(t.getRoot()) << std::endl;
    // std::cout << finder(t.getRoot(), 16) << std::endl;
    // std::cout << alzettaNodi(t.getRoot(), finder(t.getRoot(), 16)) << std::endl;

    // Tree t2 = copiaPari(t);
    // t2.print();
    // Tree t3(arr);
    // t3.print();
    // return 0;
}