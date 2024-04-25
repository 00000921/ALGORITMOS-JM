#include "reader.hpp"
using namespace std;

struct Node
{
    Agent data;
    Node *left;
    Node *right;
    Node *parent;

    Node(Agent val)
    {
        data = val;
        left = nullptr;
        right = nullptr;
        parent = nullptr;
    }
};

Node *root = nullptr;

Node *TreeSearch(Node *node, float data)
{
    if (node == nullptr || data == node->data.getId())
    {
        return node;
    }

    if (data < node->data.getId())
    {
        return TreeSearch(node->left, data);
    }
    else
    {
        return TreeSearch(node->right, data);
    }

    return nullptr;
}

Node *TreeSearch2(Node *node, float data)
{
    while (node != nullptr)
    {
        if (data == node->data.getId())
        {
            return node;
        }
        else if (data < node->data.getId())
        {
            node = node->left;
        }
        else
        {
            node = node->right;
        }
    }

    return nullptr;
}

void insert(Agent dataObj)
{
    Node *node = new Node(dataObj);

    Node *x = root;
    Node *y = nullptr;

    while (x != nullptr)
    {
        y = x;
        if (node->data.getId() < x->data.getId())
        {
            x = x->left;
        }
        else
        {
            x = x->right;
        }
    }

    node->parent = y;

    if (y == nullptr)
    {
        root = node;
    }
    else if (node->data.getId() < y->data.getId())
    {
        y->left = node;
    }
    else
    {
        y->right = node;
    }
}

void inOrder(Node *node)
{

    if (node == nullptr)
    {
        return;
    }

    inOrder(node->left);

    cout << node->data.getCode() << " " << node->data.getId() << " " << node->data.getKeyphrase() << " " << node->data.getCountry() << " " << node->data.getDeadDropLong() << " " << node->data.getDeadDropLat() << " " << node->data.getDaysSinceLastContact() << endl;

    inOrder(node->right);
}

void preOrder(Node *node)
{
    if (node == nullptr)
    {
        return;
    }

    cout << node->data.getCode() << " " << node->data.getId() << " " << node->data.getKeyphrase() << " " << node->data.getCountry() << " " << node->data.getDeadDropLong() << " " << node->data.getDeadDropLat() << " " << node->data.getDaysSinceLastContact() << endl;

    preOrder(node->left);
    preOrder(node->right);
}

void postOrder(Node *node)
{
    if (node == nullptr)
    {
        return;
    }

    postOrder(node->left);
    postOrder(node->right);

    cout << node->data.getCode() << " " << node->data.getId() << " " << node->data.getKeyphrase() << " " << node->data.getCountry() << " " << node->data.getDeadDropLong() << " " << node->data.getDeadDropLat() << " " << node->data.getDaysSinceLastContact() << endl;
}

Node *TreeMin(Node *node)
{
    if (node == nullptr)
    {
        return nullptr;
    }

    while (node->left != nullptr)
    {
        node = node->left;
    }

    return node;
}

Node *TreeMax(Node *node)
{
    if (node == nullptr)
    {
        return nullptr;
    }

    while (node->right != nullptr)
    {
        node = node->right;
    }

    return node;
}

Node *TreeSuccessor(Node *node)
{
    if (node == nullptr)
    {
        return nullptr;
    }

    if (node->right != nullptr)
    {
        return TreeMin(node->right);
    }
    else
    {
        Node *ancestor = node->parent;
        while (ancestor != nullptr && node == ancestor->right)
        {
            node = ancestor;
            ancestor = ancestor->parent;
        }
        return ancestor;
    }
}

Node *TreePredecessor(Node *node)
{
    if (node == nullptr)
    {
        return nullptr;
    }

    if (node->left != nullptr)
    {
        return TreeMax(node->left);
    }
    else
    {
        Node *ancestor = node->parent;
        while (ancestor != nullptr && node == ancestor->left)
        {
            node = ancestor;
            ancestor = ancestor->parent;
        }
        return ancestor;
    }
}

void Transplant(Node *u, Node *v)
{
    if (u->parent == nullptr)
    {
        root = v;
    }
    else if (u == u->parent->left)
    {
        u->parent->left = v;
    }
    else
    {
        u->parent->right = v;
    }

    if (v != nullptr)
    {
        v->parent = u->parent;
    }
}

void Delete(float data)
{
    Node *node = TreeSearch(root, data);

    if (node == nullptr)
    {
        cout << endl;
        cout << "El dato no existe";
        return;
    }

    if (node->left == nullptr)
    {
        Transplant(node, node->right);
    }
    else if (node->right == nullptr)
    {
        Transplant(node, node->left);
    }
    else
    {
        Node *y = TreeMin(node->right);

        if (y != node->right)
        {
            Transplant(y, y->right);
            y->right = node->right;
            y->right->parent = y;
        }

        Transplant(node, y);
        y->left = node->left;
        y->left->parent = y;
    }

    cout << endl;
    cout << "Dato eliminado";

    delete node;
}

void foundSuccessor(float data)
{

    Node *result = TreeSearch2(root, data);

    if (result == nullptr)
    {
        cout << "El sucesor, no existe";
    }
    else
    {
        Node *result2 = TreeSuccessor(result);
        cout << "El sucesor es: " << result2->data.getCode() << " " << result2->data.getId() << " " << result2->data.getKeyphrase() << " " << result2->data.getCountry() << " " << result2->data.getDeadDropLong() << " " << result2->data.getDeadDropLat() << " " << result2->data.getDaysSinceLastContact() << endl;
    }
}

void foundPredecessor(float data)
{

    Node *result = TreeSearch2(root, data);

    if (result == nullptr)
    {
        cout << "El sucesor, no existe";
    }
    else
    {
        Node *result2 = TreePredecessor(result);
        cout << "El sucesor es: " << result2->data.getCode() << " " << result2->data.getId() << " " << result2->data.getKeyphrase() << " " << result2->data.getCountry() << " " << result2->data.getDeadDropLong() << " " << result2->data.getDeadDropLat() << " " << result2->data.getDaysSinceLastContact() << endl;
    }
}

void foundMin()
{
    Node *result = TreeMin(root);
    cout << "El dato minimo es: " << result->data.getCode() << " " << result->data.getId() << " " << result->data.getKeyphrase() << " " << result->data.getCountry() << " " << result->data.getDeadDropLong() << " " << result->data.getDeadDropLat() << " " << result->data.getDaysSinceLastContact() << endl;
}

void foundMax()
{
    Node *result = TreeMax(root);
    cout << "El dato maximo es: " << result->data.getCode() << " " << result->data.getId() << " " << result->data.getKeyphrase() << " " << result->data.getCountry() << " " << result->data.getDeadDropLong() << " " << result->data.getDeadDropLat() << " " << result->data.getDaysSinceLastContact() << endl;
}

void showInOrder()
{
    inOrder(root);
}

void showPreOrder()
{
    preOrder(root);
}

void showPostOrder()
{
    postOrder(root);
}

void CallRecursiveSearch(float data)
{

    Node *result = TreeSearch(root, data);

    if (result == nullptr)
    {
        cout << "El dato no existe";
    }
    else
    {
        cout << result->data.getId();
    }
}

void CallSearch(float data)
{

    Node *result = TreeSearch2(root, data);

    if (result == nullptr)
    {
        cout << "El dato no existe";
    }
    else
    {
        cout << "El dato encontrado es: " << result->data.getCode() << " " << result->data.getId() << " " << result->data.getKeyphrase() << " " << result->data.getCountry() << " " << result->data.getDeadDropLong() << " " << result->data.getDeadDropLat() << " " << result->data.getDaysSinceLastContact() << endl;
    }
}
