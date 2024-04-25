#ifndef BINARYSEARCHTREE_HPP
#define BINARYSEARCHTREE_HPP

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

Node *TreeSearch(Node *node, string keyphrase)
{
    if (node == nullptr || keyphrase == node->data.getKeyphrase())
    {
        return node;
    }

    if (keyphrase < node->data.getKeyphrase())
    {
        return TreeSearch(node->left, keyphrase);
    }
    else
    {
        return TreeSearch(node->right, keyphrase);
    }

    return nullptr;
}

Node *TreeSearch2(Node *node, string keyphrase)
{
    while (node != nullptr)
    {
        if (keyphrase == node->data.getKeyphrase())
        {
            return node;
        }
        else if (keyphrase < node->data.getKeyphrase())
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
        if (node->data.getKeyphrase() < x->data.getKeyphrase())
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
    else if (node->data.getKeyphrase() < y->data.getKeyphrase())
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

    cout << node->data.getKeyphrase() << " " << node->data.getId() << " " << node->data.getCode() << " " << node->data.getCountry() << " " << node->data.getDeadDropLong() << " " << node->data.getDeadDropLat() << " " << node->data.getDaysSinceLastContact() << endl;

    inOrder(node->right);
}

void preOrder(Node *node)
{
    if (node == nullptr)
    {
        return;
    }

    cout << node->data.getKeyphrase() << " " << node->data.getId() << " " << node->data.getCode() << " " << node->data.getCountry() << " " << node->data.getDeadDropLong() << " " << node->data.getDeadDropLat() << " " << node->data.getDaysSinceLastContact() << endl;

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

    cout << node->data.getKeyphrase() << " " << node->data.getId() << " " << node->data.getCode() << " " << node->data.getCountry() << " " << node->data.getDeadDropLong() << " " << node->data.getDeadDropLat() << " " << node->data.getDaysSinceLastContact() << endl;
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

void Delete(string keyphrase)
{
    Node *node = TreeSearch(root, keyphrase);

    if (node == nullptr)
    {
        cout << "La palabra no existe" << endl;
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

    cout << "Palabra eliminada: " << keyphrase << endl;
    delete node;
}

void foundSuccessor(string keyphrase)
{
    Node *result = TreeSearch2(root, keyphrase);

    if (result == nullptr)
    {
        cout << "La palabra no existe" << endl;
    }
    else
    {
        Node *result2 = TreeSuccessor(result);
        if (result2 != nullptr)
        {
            cout << "El sucesor es: " << result2->data.getKeyphrase() << " " << result2->data.getId() << " " << result2->data.getCode() << " " << result2->data.getCountry() << " " << result2->data.getDeadDropLong() << " " << result2->data.getDeadDropLat() << " " << result2->data.getDaysSinceLastContact() << endl;
        }
        else
        {
            cout << "No hay sucesor para esta palabra" << endl;
        }
    }
}

void foundPredecessor(string keyphrase)
{
    Node *result = TreeSearch2(root, keyphrase);

    if (result == nullptr)
    {
        cout << "La palabra no existe" << endl;
    }
    else
    {
        Node *result2 = TreePredecessor(result);
        if (result2 != nullptr)
        {
            cout << "El predecesor es: " << result2->data.getKeyphrase() << " " << result2->data.getId() << " " << result2->data.getCode() << " " << result2->data.getCountry() << " " << result2->data.getDeadDropLong() << " " << result2->data.getDeadDropLat() << " " << result2->data.getDaysSinceLastContact() << endl;
        }
        else
        {
            cout << "No hay predecesor para esta palabra" << endl;
        }
    }
}

void foundMin()
{
    Node *result = TreeMin(root);
    if (result != nullptr)
    {
        cout << "La palabra mínima es: " << result->data.getKeyphrase() << " " << result->data.getId() << " " << result->data.getCode() << " " << result->data.getCountry() << " " << result->data.getDeadDropLong() << " " << result->data.getDeadDropLat() << " " << result->data.getDaysSinceLastContact() << endl;
    }
    else
    {
        cout << "El árbol está vacío" << endl;
    }
}

void foundMax()
{
    Node *result = TreeMax(root);
    if (result != nullptr)
    {
        cout << "La palabra máxima es: " << result->data.getKeyphrase() << " " << result->data.getId() << " " << result->data.getCode() << " " << result->data.getCountry() << " " << result->data.getDeadDropLong() << " " << result->data.getDeadDropLat() << " " << result->data.getDaysSinceLastContact() << endl;
    }
    else
    {
        cout << "El árbol está vacío" << endl;
    }
}

void CallSearch(string keyphrase)
{
    Node *result = TreeSearch2(root, keyphrase);

    if (result == nullptr)
    {
        cout << "La palabra no existe" << endl;
    }
    else
    {
        cout << "La palabra encontrada es: " << result->data.getKeyphrase() << " " << result->data.getId() << " " << result->data.getCode() << " " << result->data.getCountry() << " " << result->data.getDeadDropLong() << " " << result->data.getDeadDropLat() << " " << result->data.getDaysSinceLastContact() << endl;
    }
}

// Función para realizar la búsqueda de palabras que comienzan con un prefijo
void AutocompleteHelper(Node *node, string prefix)
{
    if (node == nullptr)
    {
        return;
    }

    if (node->data.getKeyphrase().find(prefix) == 0)
    {
        cout << node->data.getKeyphrase() << " " << node->data.getId() << " " << node->data.getCode() << " " << node->data.getCountry() << " " << node->data.getDeadDropLong() << " " << node->data.getDeadDropLat() << " " << node->data.getDaysSinceLastContact() << endl;
    }

    if (prefix < node->data.getKeyphrase())
    {
        AutocompleteHelper(node->left, prefix);
    }

    AutocompleteHelper(node->right, prefix);
}

#endif
