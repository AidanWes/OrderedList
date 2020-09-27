/*
 * A node class that prepares for defining linked list
 * 
 * Author Aidan Wesloskie
 */

#include <cstdlib>
#ifndef NODE_H
#define NODE_H

template<class T>
class Node
{
    public:
        //Basic node constructor
        Node(T d = T(), Node* l = NULL){data = d; link = l;}
        
        //Sets the data for a specfic node
        void setData(T d){data = d;}
        
        //Sets the new link of the node
        void setLink(Node* l){link = l;}
        
        //Returns the data of the node
        T getData(){return data;}
        
        //Returns the link of the node
        Node* getLink(){return link;}
        const Node* getLink()const{return link;}
    private:
        T data; //Info in the node
        Node* link; //What the node is linked to
};


#endif /* NODE_H */

