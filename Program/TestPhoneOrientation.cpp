
// Owen Covach (Team Leader)
// Group Number: 10
// ----------------------------------------
// PROG71020 - Winter 2023
// Lab 08-9 - April 14/2023
// ----------------------------------------

#include "TestPhoneOrientation.h"

// this function tests the data that was learned to see if it was stored properly
void testPhoneOrientation::testOrientation(std::string fileName, NODE* head)
{
	// declare an input file variable
	std::ifstream fin;

	// open the given file as a read file
	fin.open(fileName);
	if (fin.is_open())
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
			if (this->getLabel() == 7)
			{
				std::cout << "Invalid data found..." << std::endl << std::endl;
			}
			else
			{
				// create a temp head node to traverse through and not edit original head pointer
				NODE* temp = head;

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

				// checks if the calculated nearest label matches the actual label
				if (this->getLabel() == nearestLabel)
					std::cout << "Matched! - testLabel: " << nearestLabel << ", nearest label: " << this->getLabel() << std::endl;
				else
					std::cout << "Not Matched... - testLabel: " << nearestLabel << ", nearest label: " << this->getLabel() << std::endl;

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