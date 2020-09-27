/*
 * Author: Aidan Wesloskie
 * 
 * Header file for the OrderedList class
 */

#include "Node.h"
#include "node_iterator.h"
#include <iostream>
#ifndef ORDEREDLIST_H
#define ORDEREDLIST_H

template<class Item>
class OrderedList
{
    public:
        typedef node_iterator<Item> iterator;
        
        OrderedList();
        OrderedList(const OrderedList &o);
       ~OrderedList();
       
       iterator begin(){return iterator(first);}
       iterator end(){return iterator(NULL);}
       
       /**
        * Takes in an input of a type item to remove from the list
        * 
        * PreCondition: Requires a parameter of what item to remove from the list
        * 
        * PostCondition: Deletes the chosen item from the list
        */
        void remove(Item item);
        
        /**
        * Takes in an input of a type item to add to the list, and will place
        * it in its ordered position
        * 
        * PreCondition: Requires a parameter of what item to add to the list
        * 
        * PostCondition: Places the desired item into its correct position
        */
        void insert(Item item);
        
        /**
        * Takes in an input of an index and returns the item found at that index
        * 
        * PreCondition: Requires a parameter of what index to search at
        * 
        * PostCondition: Returns the item data at the selected index
        */
        Item get(int index) const;
        
        /**
        * Finds if the list has any elements inside of it
        */
        bool isEmpty(){return size == 0;}
        
        /**
         * Returns the largest elements of the list, the amount of elements are 
         * specified by the user
         * 
         * PreCondition: how many elements the user wants to have
         * 
         * PostCondition: A new ordered list with the k largest elements
         * from that list
         */
        OrderedList<Item>* kLargest(int length);
        
        /**
         * Adds the two ordered lists together and sorts them correctly
         * 
         * PreCondition: two ordered lists using the '+' operator
         * 
         * PostCondition: Returns a new OrderedList object with the
         * combined elements from the other two lists
         */
        OrderedList<Item>* operator+(const OrderedList<Item>& o) const;
        
        /**
         * Outputs the list
         */
        friend std::ostream& operator<<(std::ostream& out, const OrderedList &o)
        {
             out << "[";
             int count = 0;
             if(o.size != 0)
                for(Node<Item>* current = o.first; current != NULL; current = current->getLink())
                {
                    if(count != o.size-1)
                        out << current->getData() << ", ";
                    else
                        out << current->getData();
                    count++;
                }
             else
                 out << " ";
             out << "]";
             return out;
         }
    private:
        Node<Item>* first;
        Node<Item>* last;
        int size; //Number of items in list
};

#include "OrderedList.template"
#endif /* ORDEREDLIST_H */