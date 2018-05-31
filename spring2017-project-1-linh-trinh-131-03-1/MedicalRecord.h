#ifndef MedicalRecord_h
#define MedicalRecord_h

#pragma once
#include <string>
#include <stdexcept>

#include "Baby.h"

using namespace std;

class MedicalRecord 
{
public:
	// default constructor
	MedicalRecord() 
	{	
	size = 1000000;//size 1 million array
        babynames = new string[size]; // dynamic array for baby names
        babyweights = new int[size];  // dynamic array for corresponding weight
	nName = 0;
	lowWeight = 0;
	}

	// destructor
	~MedicalRecord() 
	{
		//Deletes allocated memory for the arrays
		delete[] babynames;
        	delete[] babyweights;
	}

	// Load information from a text file with the given filename.
	void buildMedicalRecordfromDatafile(string filename) 
	{
		ifstream myfile(filename);

		if (myfile.is_open()) 
		{
			cout << "Successfully opened file " << filename << endl;
			string name;
			int weight;
			while (myfile >> name >> weight) 
			{
				//cout << name << " " << weight << endl;
				Baby b(name, weight);
				addEntry(b);
			}
			myfile.close();
		}
		else
			throw invalid_argument("Could not open file " + filename);
	}

	// return the most frequently appearing name in the text file
	string mostPopularName() 
	{
		string popular; //will store the current most popular name through the list
        	int topcount =1; //default number of names is 1 
		      //also to reset counter every loop
      	  for (int i = 0; i < countbabies; i++)
	  {
            int nameCount = 0; // initial count will be 0 
            string temp = babynames[i]; //starting from the first name 
            nameCount++; // adds the 1 to the intial 0
            for(int j= i+1; j < countbabies; j++)
	    {
                if (babynames[j]== temp)
		{//equal names through the list
                    nameCount++; // adds one point to the count
                    if (nameCount > topcount)//if the name appears more than the last most popular
                    {
                        popular = temp;//sets it to the current most popular
                        topcount = nameCount;//with the corresponding amount of times it appeared
                    }
                }
            }
            
        }
        return popular; // returns the most popular name
	}

	// return the number of baby records loaded from the text file
	int numberOfBirths() {
		return countbabies; 
	}

	// return the number of babies who had birth weight < 2500 grams
	int numberOfBabiesWithLowBirthWeight() {
	for (int i= 0; i < countbabies; i++)// gonna go through all the babies
        {
            if (babyweights[i] < 2500){//if there is a baby with a weight less than 2500
                lowWeight++; // adds to the counter
            }
        }
        return lowWeight;//returns total amount 
	}

	// return the number of babies who have the name contained in string s
	int numberOfBabiesWithName(string s) {
	for(int i=0; i < countbabies; i++)//goes through all the babies names
	{
            if (babynames[i] == s)//if it occurs
            {nName++;}//add one to the counter
        }
        
        
        return nName; //return number of times it occurred 
	}

private:
	// update the data structure with information contained in Baby object
	void addEntry(Baby b) {
	//note count babies starts at 0
	babynames[countbabies] = b.getName();// sets the name from the baby class to the array
        babyweights[countbabies] = b.getWeight();//same as name but for weight
        ++countbabies;// adds a number to amount of babies each time its accessed
	}

	// Add private member variables for your data structure along with any 
	// other variables required to implement the public member functions
	int size;
        int *babyweights;
        string *babynames;
        int countbabies = 0;
        int nName;
        int lowWeight;
};
#endif /* MedicalRecord_h */
