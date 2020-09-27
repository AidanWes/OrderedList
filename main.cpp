/*
 * Main class to test the Salesperson class
 * 
 * @author Aidan Wesloskie
 */

#include "SalesPerson.h"
#include <fstream>
#include <iomanip>
#include <algorithm>
#include <vector>

using namespace std;
using namespace sales;

int main(int argc, char** argv) {
    
    //Variables for files and elements of the files
    ifstream inFile; inFile.open("sales.txt");
    ofstream outFile; outFile.open("output.txt");
    string first, last, year, id, spacer;
    int numOfSales, salesIn;
    vector<SalesPerson> roster;
    
    //Asks how many sales will be displayed per salesperson
    cout << "Enter the number of sales you want from each salesperson:\n";
    cin >> numOfSales;
    cout << "\n";

    //Reads through the input file
    while(!inFile.eof())
    {
        //Pulls data from the first line of the sales person
        getline(inFile, year, ' ');
        getline(inFile, id, ' ');
        getline(inFile, first, ' ');
        getline(inFile, last, ' ');
        getline(inFile, spacer, '\n');
        
        //List to store all sales values for salesperson
        OrderedList<float>* list = new OrderedList<float>;

        //Pulls in second line and breaks it into individual components
        //then places them into the list
        string secondLine;
        getline(inFile, secondLine);
        istringstream iss(secondLine);
        while(iss >> salesIn) 
            list->insert(salesIn);

        //Compiles all data into a salesperson object
        SalesPerson *current = new SalesPerson(stod(id), first, last, list, numOfSales, stod(year));

        //Scans through all salespersons and tries to find one with a similar duplicate
        for(vector<SalesPerson>::iterator it = roster.begin(); it != roster.end(); it++)
            //If it does, the sales data from the old salesperson is transferred to the new
            //one and the old salesperson object is deleted
            if(*current == *it)
            {
                current->setSales(*current->getSales() + *it->getSales());
                roster.erase(it--);
            }
        //Adds salesperson
        roster.push_back(*current);
    }
    //Sorts the roster based on salesperson ID
    sort(roster.begin(), roster.end());
        
    //Sends all the data to the output
    for(vector<SalesPerson>::iterator it = roster.begin(); it != roster.end(); it++)
        outFile << *it << endl;
    outFile << endl;
        
    //Cleans up files
    inFile.close(); outFile.close();
    cout << "SUCCESS DATA COMPILED\n";

return 0;
}

