/*
 * Basic Salesperson class that tracks a persons
 * ID, first and last name, the sales they made, the number of sales, and the year
 * the data was recorded
 * 
 * @author Aidan Weloskie
 */

#include <string>
#include "OrderedList.h"
using namespace std;
#ifndef SALESPERSON_H
#define SALESPERSON_H

namespace sales
{
    class SalesPerson
    {
    public:

        //Constructor for the SalesPerson class
        SalesPerson(int employeeId, string firstName, string lastName, OrderedList<float>* salesList, int numOfSales, int yearDone)
        {
            id = employeeId;
            first = firstName;
            last = lastName;
            sales = salesList;
            numSales = numOfSales;
            year = yearDone;
        }

        /*
         PostCondition: Returns the id of the salesperson
         */
        int getId()const{return id;}

        /*
         PostCondition: Returns the first name of the salesperson
         */
        string getFirst()const{return first;}

        /*
         PostCondition: Returns the last name of the salesperson
         */
        string getLast()const{return last;}

        /*
         PostCondition: Returns a list of the sales
         */
        OrderedList<float>* getSales()const{return sales;}

        /*
         PreCondition: A new set of values to assign
         PostCondition: Replaces the list with a new one
         */
        void setSales(OrderedList<float>* newSales){sales = newSales;}

        /*
         PostCondition: If the two salesperson IDs are the same it returns true,
         else will return false if they are not the same
         */
        bool operator ==(const SalesPerson &s2)
        {
            if(this->getId() == s2.getId())
            {
                return true;
            }
            return false;
        }

        /*
         PostCondition: Returns true if the the second salesperson is larger than the
         second one, else will return false
         */
        bool operator <(const SalesPerson &s2)
        {
            if(this->getId() < s2.getId())
            {
                return true;
            }
            return false;
        }

        /*
         PostCondition: Outputs salespersons
         */
        friend std::ostream& operator<<(std::ostream& out, const SalesPerson &o)
            {
                 out << o.id << " " 
                     << o.first << " "
                     << o.last << " " 
                     << *(o.sales->kLargest(o.numSales));

                 return out;
             }

    private:
        int id;
        string first;
        string last;
        OrderedList<float>* sales;
        int numSales;
        int year;
    };
}

#endif /* SALESPERSON_H */

