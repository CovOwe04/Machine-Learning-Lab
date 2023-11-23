#pragma once

/// @file NNClassifier.h
/// @brief NNClassifier Header file Library
/// @details The methods here represent different characteristics and behaviours of NNClassifier
/// @author Owen Covach
/// @date 14/4/2023

#include "PhoneOrientation.h"
#include "Node.h"

/// <summary>
/// @class NNClassifier NNClassifier.h "NNClassifier.h"
/// @brief A NNClassifier class (derived class) that inherited from the PhoneOrientation class (Base Class) that has a public access specififers 
/// @details This class overrides the abstract class functions to use for its own class
/// @author Owen Covach
/// @date 14/4/2023
/// </summary>

class NNClassifier:public PhoneOrientation
{
	/// @brief A member variable that is the x gravity vector for a phone orientation (temporary float value) that will be compared to learned data
	float x;

	/// @brief A member variable that is the y gravity vector for a phone orientation (temporary float value) that will be compared to learned data
	float y;

	/// @brief A member variable that is the z gravity vector for a phone orientation (temporary float value) that will be compared to learned data
	float z;

	/// @brief A member variable that is the label of a phone orientation (temporary int value) that will be compared to learned data
	int label;

	/// @brief A member variable that is a pointer to the head of a linked list
	NODE* head;

public:
	/// <summary>
	/// @brief Default Constructor for NNClassifier
	/// @details Initializes an empty object of NNClassifier type
	/// @param takes a string which is the name of a text file, as well as a node pointer which stores th head of the linked list of learned data
	/// @return no return type
	/// @author Owen Covach
	/// @date 14/4/2023
	/// </summary>
	NNClassifier();

	/// <summary>
	/// @fn void setX(float)
	/// @brief Setter function for the x attribute
	/// @details Sets the x attribute of the current object in use
	/// @param takes a float which is the desired value of the object's x attribute
	/// @return void (nothing)
	/// @author Owen Covach
	/// @date 14/4/2023
	/// </summary>
	void setX(float);

	/// <summary>
	/// @fn void setY(float)
	/// @brief Setter function for the y attribute
	/// @details Sets the y attribute of the current object in use
	/// @param takes a float which is the desired value of the object's y attribute
	/// @return void (nothing)
	/// @author Owen Covach
	/// @date 14/4/2023
	/// </summary>
	void setY(float);

	/// <summary>
	/// @fn void setZ(float)
	/// @brief Setter function for the z attribute
	/// @details Sets the z attribute of the current object in use
	/// @param takes a float which is the desired value of the object's z attribute
	/// @return void (nothing)
	/// @author Owen Covach
	/// @date 14/4/2023
	/// </summary>
	void setZ(float);

	/// <summary>
	/// @fn void setLabel(int)
	/// @brief Setter function for the label attribute
	/// @details Sets the label attribute of the current object in use
	/// @param takes an int which is the desired value of the object's label attribute
	/// @return void (nothing)
	/// @author Owen Covach
	/// @date 14/4/2023
	/// </summary>
	void setLabel(int);

	/// <summary>
	/// @fn void setHead(NODE*)
	/// @brief Setter function for the head attribute
	/// @details Sets the head attribute of the current object in use
	/// @param takes a Node pointer which is the desired head pointer of the object's head attribute
	/// @return void (nothing)
	/// @author Owen Covach
	/// @date 14/4/2023
	/// </summary>
	void setHead(NODE*);

	/// <summary>
	/// @fn float getX()
	/// @brief Getter function for the x attribute
	/// @details Gets the x attribute of the current object in use which is a float value
	/// @param void (nothing)
	/// @return returns a float which is the current object's x attribute
	/// @author Owen Covach
	/// @date 14/4/2023
	/// </summary>
	float getX();

	/// <summary>
	/// @fn float getY()
	/// @brief Getter function for the y attribute
	/// @details Gets the y attribute of the current object in use which is a float value
	/// @param void (nothing)
	/// @return returns a float which is the current object's y attribute
	/// @author Owen Covach
	/// @date 14/4/2023
	/// </summary>
	float getY();

	/// <summary>
	/// @fn float getZ()
	/// @brief Getter function for the z attribute
	/// @details Gets the z attribute of the current object in use which is a float value
	/// @param void (nothing)
	/// @return returns a float which is the current object's z attribute
	/// @author Owen Covach
	/// @date 14/4/2023
	/// </summary>
	float getZ();

	/// <summary>
	/// @fn int getLabel()
	/// @brief Getter function for the label attribute
	/// @details Gets the label attribute of the current object in use which is an int value
	/// @param void (nothing)
	/// @return returns an int which is the current object's label attribute
	/// @author Owen Covach
	/// @date 14/4/2023
	/// </summary>
	int getLabel();

	/// <summary>
	/// @fn NODE* getHead()
	/// @brief Getter function for the head attribute
	/// @details Gets the head attribute of the current object in use which is a Node pointer address
	/// @param void (nothing)
	/// @return returns a Node pointer which is the current object's head attribute
	/// @author Owen Covach
	/// @date 14/4/2023
	/// </summary>
	NODE* getHead();

	/// <summary>
	/// @brief A Destructor for NNClassifier Class used to ensure that we free the head member variable.
	/// @details the member variable was dynamically allocated to a space in heap using the new operator. We must free it before we are out of scope. It helps us avoid unneccessary memory leaks and return the resource back to the memory. 
	/// @author Owen Covach
	/// @date 25/3/2023
	/// </summary>
	~NNClassifier();

	/// <summary>
	/// @fn float nearestNeighbour(NODE*)
	/// @brief A function that calculates the distance between 2 nodes (3d points)
	/// @details This function uses an equation to find the distance between 2 given nodes (3d points)
	/// @param takes a Node pointer which changes every time its called
	/// @return returns a float number which is the diistance between 2 nodes (3d points)
	/// @author Owen Covach
	/// @date 14/4/2023
	/// </summary>
	float nearestNeighbour(NODE*);

	/// <summary>
	/// @fn std::string decideOrientationName(int)
	/// @brief A function that decides the name of a given integer label
	/// @details This function uses a switch case to determine which name label to associate with the integer label
	/// @param takes an int which is the nearestLabel integer that was determined by the nearestNeighbour classifier
	/// @return returns a string which is the name label of the integer label
	/// @author Owen Covach
	/// @date 14/4/2023
	/// </summary>
	std::string decideOrientationName(int);
		
	/// <summary>
	/// @fn void learnOrientation(std::string)
	/// @brief A function that learns data from a given text file
	/// @details This function learns information in the form of phone gravity vectors and labels and stores in into a linked list
	/// @param takes a string which is the name of a text file
	/// @return void (nothing)
	/// @author Owen Covach
	/// @date 14/4/2023
	/// </summary>
	void learnOrientation(std::string);

	/// <summary>
	/// @fn void predictOrientation(float, float, float)
	/// @brief A function that predicts the orientation label of data from user input values
	/// @details This function predicts the phone's orientation based on the data learned and gives it a label and outputs it to  the console
	/// @param takes 3 floats which are input by the user (in the range of -1 -> 1)
	/// @return void (nothing)
	/// @author Owen Covach
	/// @date 14/4/2023
	/// </summary>
	void predictOrientation(float, float, float);

	/// <summary>
	/// @fn void predictOrientation(std::string)
	/// @brief A function that predicts the orientation label of data from a given text file
	/// @details This function predicts the phone's orientation based on the data learned and gives it a label and outputs it to a new result file
	/// @param takes a string which is the name of a text file
	/// @return void (nothing)
	/// @author Owen Covach
	/// @date 14/4/2023
	/// </summary>
	void predictOrientation(std::string);

	/// <summary>
	/// @fn friend void setAttributes(std::ifstream&, NNClassifier&)
	/// @brief A friend function that sets current obejct attributes to data read from a file
	/// @details This function reads a text file of data, and then sets each neccessary attribute to that data as a temporary placeholder
	/// @param takes an input file stream object, as well as an NNClassifier object which will be changed in the function
	/// @return void (nothing)
	/// @author Owen Covach
	/// @date 14/4/2023
	/// </summary>
	friend void setAttributes(std::ifstream&, NNClassifier&);

	/// <summary>
	/// @fn friend std::ofstream& operator<< (std::ofstream&, NNClassifier&)
	/// @brief A friend function that sets current obejct attributes to data read from a file
	/// @details This function reads a text file of data, and then sets each neccessary attribute to that data as a temporary placeholder
	/// @param takes an output file stream object, as well as an NNClassifier object
	/// @return void (nothing)
	/// @author Owen Covach
	/// @date 14/4/2023
	/// </summary>
	friend std::ofstream& operator<< (std::ofstream&, NNClassifier&);
};