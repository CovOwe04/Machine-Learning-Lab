#pragma once

/// @file KNNClassifier.h
/// @brief KNNClassifier Header file Library
/// @details The methods here represent different characteristics and behaviours of KNNClassifier which are all dummy functions
/// @author Owen Covach
/// @date 14/4/2023

#include "PhoneOrientation.h"

/// <summary>
/// @class KNNClassifier KNNClassifier.h "KNNClassifier.h"
/// @brief A KNNClassifier class (derived class) that inherited from the PhoneOrientation class (Base Class) that has a public access specififers 
/// @details This class overrides the abstract class functions to use for its own class
/// @author Owen Covach
/// @date 14/4/2023
/// </summary>

class KNNClassifier:public PhoneOrientation
{

public:

	/// <summary>
	/// @brief A dummy function that just prints the name of the function, in this case, "learnOrientation()"
	/// @details This function hasnt been implemented yet, thus it will only print the name of the function if it is called
	/// @param takes a string which is the name of a text file
	/// @return void (nothing)
	/// @author Owen Covach
	/// @date 14/4/2023
	/// </summary>
	void learnOrientation(std::string);

	/// <summary>
	/// @brief A dummy function that just prints the name of the function, in this case, "predictOrientation()"
	/// @details This function hasnt been implemented yet, thus it will only print the name of the function if it is called
	/// @param takes 3 floats which are input by the user (in the range of -1 -> 1)
	/// @return void (nothing)
	/// @author Owen Covach
	/// @date 14/4/2023
	/// </summary>
	void predictOrientation(float, float, float);

	/// <summary>
	/// @brief A dummy function that just prints the name of the function, in this case, "learnOrientation()"
	/// @details This function hasnt been implemented yet, thus it will only print the name of the function if it is called
	/// @param takes a string which is the name of a text file
	/// @return void (nothing)
	/// @author Owen Covach
	/// @date 14/4/2023
	/// </summary>
	void predictOrientation(std::string);
};