#pragma once

/// @file Node.h
/// @brief Node Header file Library
/// @details This file contains the Node structure attributes. This will be used for a linked list to store the phone gravity vectors
/// @author Owen Covach
/// @date 14/4/2023

/// <summary>
/// @class Node Node.h "Node.h"
/// @brief A Node struct that has public attributes for a linked list
/// @details This struct defines a node that a linked list will use
/// @author Owen Covach
/// @date 14/4/2023
/// </summary>

typedef struct Node {

	/// @brief A member variable that is the x gravity vector for a phone orientation (temporary float value) that will be compared to learned data
	float x;

	/// @brief A member variable that is the y gravity vector for a phone orientation (temporary float value) that will be compared to learned data
	float y;

	/// @brief A member variable that is the z gravity vector for a phone orientation (temporary float value) that will be compared to learned data
	float z;

	/// @brief A member variable that is the label of a phone orientation (temporary int value) that will be compared to learned data
	int label;

	/// @brief A member variable that is a pointer to the next node of a linked list ( linked list)
	struct Node* next;

}NODE;