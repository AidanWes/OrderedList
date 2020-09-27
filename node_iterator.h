/* 
 * Author: Aidan Wesloskie
 * 
 * 
 */

#ifndef NODE_ITERATOR_H
#define NODE_ITERATOR_H


#include <iterator>
#include <cstdlib>
#include "Node.h"

template<class T>
class node_iterator:public 
std::iterator<std::forward_iterator_tag, T>
{
    public:
        node_iterator(Node<T>* initial = NULL){current = initial;}
        T operator*(){return current->getData();}
        node_iterator& operator++() //Prefix
        {
            current = current->getLink();
            return *this;
        }
        
        node_iterator& operator++(int) //Postfix
        {
            node_iterator original(current);
            current = current->getLink();
            return original;
        }
        
        bool operator==(const node_iterator& target)
        {
            return current == target.current;
        }
        
        bool operator!=(const node_iterator& target)
        {
            return current != target.current;
        }
    private:
        Node<T>* current;
};

#endif /* NODE_ITERATOR_H */

