
// Owen Covach (Team Leader)
// Group Number: 10
// ----------------------------------------
// PROG71020 - Winter 2023
// Lab 08-9 - April 14/2023
// ----------------------------------------

#include "NNClassifier.h"
#include "TestPhoneOrientation.h"

// this function reads a file, and sets attributes of a NNClassifier object 
void setAttributes(std::ifstream& fin, NNClassifier& orientation)
{
	// get one full line from the file
	std::string line;
	getline(fin, line);

	// set the line as a istream
	std::istringstream issLine(line);

	std::string data;

	// dissect each value from the line
	getline(issLine, data, ',');
	orientation.setX(stof(data));

	getline(issLine, data, ',');
	orientation.setY(stof(data));

	getline(issLine, data, ',');
	orientation.setZ(stof(data));

	// if there is no label, this doesnt cause an issue
	getline(issLine, data);
	orientation.setLabel(stoi(data));

	// checks values to make sure all values are within the range
	if (orientation.getX() < -1 || orientation.getX() > 1 ||
		orientation.getY() < -1 || orientation.getY() > 1 ||
		orientation.getZ() < -1|| orientation.getZ() > 1)
	{
		// this label value is the "error" label
		orientation.setLabel(7);
	}
}

// this function takes the NNClassifier and prints the neccessary values.
std::ofstream& operator<< (std::ofstream& fout, NNClassifier& orientation)
{
	// print the gravity vector values, label is predicted therefore it isnt printed by the object
	fout << orientation.x << ",";
	fout << orientation.y << ",";
	fout << orientation.z << ",";
	return fout;
}