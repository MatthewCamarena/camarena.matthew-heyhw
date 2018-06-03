# Baby Stats Project
This project was designed to introduce the concept of data structures. 
From a small and large text file full of baby names, and their respective weights included, we were assigned to store them in any data structure we knew. where we would be able to quickly compute the following: most popular name, number of births, number of babies with low birth weight, and the total number of babies from any given name.

## Documentation Contributers
Camarena Matthew camarena.matthew@csu.fullerton.edu
Haowen-Yong 

# Summary

## Baby class
The Baby class has two constructors: the default constructor and a parameterized constructor.
The default constructor takes no arguments while initializing variables for the name and weight of the baby. The parameterized constructor requires a string variable and an int variable, which would be the name and weight respectively.
This class also has two functions, both of which are getter methods: getWeight() and getName(). Both can be used to get the information of the specific baby the user is looking for.

## Medical Record class
The class medical record is used to store data of the babies.  most popular name, number of births, number of babies with low birth weight, and the total number of babies from any given name.

The Medical Record construction class intializes two arrays and allocates memory for up to 1 million elements each. It also initializes the number of times a name has appeared, as well as the number of low weight babies to 0. The total baby count starts at 0. An addEntry function with the baby class variable as the parameter uses the baby's names and weight to update the data structure with a new baby and total baby count.

A deconstructor was created to deleted the allocated memory on exit of the program, to free the unused memory.

The medical record class has a function that reads from a text file given the name as a parameter. It opens the file and assigns the variables name and weight to the baby class, and calls the addEntry function passing the two variables.

# How to build and run
