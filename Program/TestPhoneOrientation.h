#pragma once

/// @file TestPhoneOrientation.h
/// @brief TestPhoneOrientation Header file Library
/// @details The methods here represent different characteristics and behaviours of TestPhoneOrientation
/// @author Owen Covach
/// @date 14/4/2023

#include "NNClassifier.h"
#include "Node.h"

/// <summary>
/// @class testPhoneOrientation testPhoneOrientation.h "testPhoneOrientation.h"
/// @brief A testPhoneOrientation class (derived class) that inherited from the NNClassifier class (Parent Class) that has a public access specififers 
/// @details This class inherits the NNClassifier class functions as well as adds a new test function
/// @author Owen Covach
/// @date 14/4/2023
/// </summary>

class testPhoneOrientation:public NNClassifier {

public:
		
	/// <summary>
	/// void testOrientation(std::string, NODE*)
	/// @brief A function that tests the learned data retrieved from the "learnOrientation()" function
	/// @details This function tests all the learned data to make sure the program as learned the right data properply
	/// @param takes a string which is the name of a text file, as well as a node pointer which stores th head of the linked list of learned data
	/// @return void (nothing)
	/// @author Owen Covach
	/// @date 14/4/2023
	/// </summary>
	void testOrientation(std::string, NODE*);
};