#pragma once

/// @file PhoneOrientation.h
/// @brief PhoneOrientation Header file Library
/// @details This file contains a PhoneOrientation class which has pure virtual functions. Other classes will inherit from this class.
/// @author Owen Covach
/// @date 14/4/2023

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cmath>

/// <summary>
/// @class PhoneOrientation PhoneOrientation.h "PhoneOrientation.h"
/// @brief An Abstract Class called PhoneOrientation since this class contains atleast one pure virtual function (a function that does not have a definition) 
/// @details This class declares the learning and predicting functions that will be inherited by other child classes
/// @author Owen Covach
/// @date 14/4/2023
/// </summary>

class PhoneOrientation
{
public:
	
	/// <summary>
	/// @brief A pure virtual member for learnOrientation which does not have a body 
	/// @details It is used to represent general concepts in this case is learnOrientation that will be used as a base class for concrete classes to learn (e.g: NNClassifier). In addition, pure specifier (= 0) is assigned after the function declaration.
	/// @param takes a string which is the name of a text file
	/// @return void (nothing)
	/// @author Owen Covach
	/// @date 14/4/2023
	/// </summary>
	virtual void learnOrientation(std::string) = 0;

	/// <summary>
	/// @brief A pure virtual member for predictOrientation which does not have a body 
	/// @details It is used to represent general concepts in this case is predictOrientation that will be used as a base class for concrete classes to predict (e.g: NNClassifier). In addition, pure specifier (= 0) is assigned after the function declaration.
	/// @param takes 3 floats which are input by the user (in the range of -1 -> 1)
	/// @return void (nothing)
	/// @author Owen Covach
	/// @date 14/4/2023
	/// </summary>
	virtual void predictOrientation(float, float, float) = 0;

	/// <summary>
	/// @brief A pure virtual member for predictOrientation which does not have a body 
	/// @details It is used to represent general concepts in this case is predictOrientation that will be used as a base class for concrete classes to predict (e.g: NNClassifier). In addition, pure specifier (= 0) is assigned after the function declaration.
	/// @param takes a string which is the name of a text file
	/// @return void (nothing)
	/// @author Owen Covach
	/// @date 14/4/2023
	/// </summary>
	virtual void predictOrientation(std::string) = 0;
};