
// Owen Covach (Team Leader)
// Group Number: 10
// ----------------------------------------
// PROG71020 - Winter 2023
// Lab 08-9 - April 14/2023
// ----------------------------------------

#include "NNClassifier.h"

// default constructor
NNClassifier::NNClassifier()
{
	this->x = 0;
	this->y = 0;
	this->z = 0;
	this->label = 0;
	this->head = new NODE;
	this->head->x = 0;
	this->head->y = 0;
	this->head->z = 0;
	this->head->label = 0;
	this->head->next = nullptr;
}

//****************************************
//			   Setters
void NNClassifier::setX(float x)
{
	this->x = x;
}

void NNClassifier::setY(float y)
{
	this->y = y;
}

void NNClassifier::setZ(float z)
{
	this->z = z;
}

void NNClassifier::setLabel(int label)
{
	this->label = label;
}

void NNClassifier::setHead(NODE* head)
{
	this->head = head;
}
//****************************************


//****************************************
//			   Getters
float NNClassifier::getX()
{
	return this->x;
}

float NNClassifier::getY()
{
	return this->y;
}

float NNClassifier::getZ()
{
	return this->z;
}

int NNClassifier::getLabel()
{
	return this->label;
}

NODE* NNClassifier::getHead()
{
	return this->head;
}
//****************************************


// destructor
NNClassifier::~NNClassifier()
{
	delete this->head;
}

// calculates the distance between the 2 given nodes (3d points)
float NNClassifier::nearestNeighbour(NODE* n)
{
	// distance equation, typecasting to float to avoid data loss
	return (float)sqrt(pow((this->x - n->x), 2) + pow((this->y - n->y), 2) + pow((this->z - n->z), 2));
}

// based on the integer label, it has a name with it, this function decides that
std::string NNClassifier::decideOrientationName(int nearestLabel)
{
	// gets the calculated nearest label and returns a word label for the user to see
	switch (nearestLabel)
	{
	case 1:
		return "Face Up";
		break;

	case 2:
		return "Face Down";
		break;

	case 3:
		return "Portrait";
		break;

	case 4:
		return "Portrait Upside Down";
		break;

	case 5:
		return "Landscape Left";
		break;

	case 6:
		return "Landscape right";
		break;
	default:
		return "Unknown Orientation";
		break;
	}
}

// this function learns data based on a file given
void NNClassifier::learnOrientation(std::string fileName)
{
	// declare an input file variable
	std::ifstream fin;

	// open the given file as a read file
	fin.open(fileName);
	if (fin.is_open())
	{
		// keep looping through file until reach the end of it
		while (!fin.eof())
		{
			// calls the file read function in FileReadWrite.cpp
			setAttributes(fin, *this);

			// checks if there is invalid values
			if (this->label == 7)
			{
				std::cout << "Invalid data found..." << std::endl;
			}
			else
			{
				// create a temp head node to traverse through and not edit original head pointer
				NODE* temp = this->getHead();

				// checks if there was an error creating the temp node
				if (temp != nullptr)
				{
					
					// traverse through the node until reached tail
					while (temp->next != nullptr)
					{
						temp = temp->next;
					}

					// set the node to the current data retrieved
					temp->x = this->getX();
					temp->y = this->getY();
					temp->z = this->getZ();
					temp->label = this->getLabel();

					// initializing an empty node for the next loop through
					temp->next = new NODE;
					temp->next->x = 0;
					temp->next->y = 0;
					temp->next->z = 0;
					temp->next->label = 0;
					temp->next->next = nullptr;

				}
			}
		}

		// close file to avoid errors
		fin.close();
	}
	else
	{
		// in case error occurs with opening file
		std::cout << "can't open file:" << fileName << std::endl;
	}
}

// this function predicts a single point given by the user
void NNClassifier::predictOrientation(float x, float y, float z)
{
	// checks if the input data is invalid or not immediately since its one value only
	if (x < -1 || x > 1 ||
		y < -1 || y > 1 ||
		z < -1 || z > 1)
	{
		std::cout << std::endl << std::endl <<"Data entered is invalid..." << std::endl << std::endl;
		return;
	}

	// declaring prediction variables
	float nearestDistance;
	int nearestLabel = 0;

	// sets each attribute
	this->setX(x);
	this->setY(y);
	this->setZ(z);

	// create a temp head node to traverse through and not edit original head pointer
	NODE* temp = this->head;

	// calculate the distance between the current data to the first trained data
	nearestDistance = nearestNeighbour(temp);

	// traverse through the trained data till end reached
	while (temp != nullptr)
	{
		// calculate the distance between the current data to all the trained data
		if ((nearestNeighbour(temp)) < nearestDistance)
		{
			// if the calculated nearest distance is less than the current then set the prediction variable as that value
			nearestDistance = nearestNeighbour(temp);
			nearestLabel = temp->label;
		}
		// traverse to next node;
		temp = temp->next;
	}

	// print out the predicted labels out to the console for the user to see
	std::cout << std::endl << std::endl << "Predicted label:" << nearestLabel << ", " << decideOrientationName(nearestLabel) << std::endl << std::endl;
}

// this function predicts multiple points given by a text file from the user
void NNClassifier::predictOrientation(std::string fileName)
{
	// declare an input file variable
	std::ifstream fin;

	// open the given file as a read file
	fin.open(fileName);
	if (fin.is_open())
	{
		// declare an output file variable
		std::ofstream fout;

		// open a new file as a write file
		fout.open("Result.txt");
		if (fout.is_open())
		{
			// declaring prediction variables
			float nearestDistance;
			int nearestLabel = 0;

			// keep looping through file until reach the end of it
			while (!fin.eof())
			{
				// calls the file read function in FileReadWrite.cpp
				setAttributes(fin, *this);

				// checks if there is invalid values
				if (this->label	== 7)
				{
					std::cout << "Invalid data found..." << std::endl;
				}
				else
				{
					// create a temp head node to traverse through and not edit original head pointer
					NODE* temp = this->head;

					// calculate the distance between the current data to the first trained data
					nearestDistance = nearestNeighbour(temp);

					// traverse through the trained data till end reached
					while (temp != nullptr)
					{
						// calculate the distance between the current data to all the trained data
						if ((nearestNeighbour(temp)) < nearestDistance)
						{
							// if the calculated nearest distance is less than the current then set the prediction variable as that value
							nearestDistance = nearestNeighbour(temp);
							nearestLabel = temp->label;
						}

						// traverse to next node;
						temp = temp->next;
					}

					// print out the object data (operator<< operator overload in FileReadWrite.cpp) and the predicted labels
					fout << *this << nearestLabel << "," << decideOrientationName(nearestLabel) << std::endl << std::endl;
				}

			}

			// close file to avoid errors
			fout.close();
		}

		// close file to avoid errors
		fin.close();
	}
	else
	{
		// in case error occurs with opening file
		std::cout << "can't open file:" << fileName << std::endl;
	}
}