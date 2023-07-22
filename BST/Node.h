template<class T>
class Node{
public:
    T value;
    Node<T>* left;
    Node<T>* right;
    Node(T item, Node<T>*l = NULL, Node<T>*r = NULL)
    {
        value = item;
        left = l;
        right = r;
    }
};