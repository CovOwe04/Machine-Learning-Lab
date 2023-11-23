
// Owen Covach (Team Leader)
// Group Number: 10
// ----------------------------------------
// PROG71020 - Winter 2023
// Lab 08-9 - April 14/2023
// ----------------------------------------


// including all neccessary header files
#include "DummyClassifier.h"
#include "KNNClassifier.h"
#include "NNClassifier.h"
#include "TestPhoneOrientation.h"

int main(void)
{
	// declare a NNclassifier object
	NNClassifier phoneOrientation;

	// train program with given data
	phoneOrientation.learnOrientation("trainingData.txt");

	// declare a test object
	testPhoneOrientation test;

	// test the trained data for accuracy
	test.testOrientation("testingData.txt", phoneOrientation.getHead());

	system("cls"); //remove if you would like to see the testing information

	// initialize a main menu loop
	bool mainMenuLoop = true;

	// output a welcome message
	std::cout << "Welcome to my Machine Learning program!" << std::endl;
	std::cout << "---------------------------------------" << std::endl << std::endl;

	// keep looping until user wants to exit
	while (mainMenuLoop)
	{		
		// display user options
		std::cout << "0. Exit" << std::endl;
		std::cout << "1. NNClassifier" << std::endl;
		std::cout << "2. KNNClassifier" << std::endl;
		std::cout << "3. DummyClassifier" << std::endl << std::endl;
		std::cout << "Please pick an classifier to use:";

		// recieve user input
		int classSelection;
		std::cin >> classSelection;
		std::cout << "---------------------------------------" << std::endl << std::endl;

		//initialize a class menu loop
		bool classMenuLoop = true;

		// check user inputs
		if (classSelection == 1)
		{
			// keep looping until user wants to go back
			while (classMenuLoop)
			{

				// display class menu options
				std::cout << "---------------------------------------" << std::endl << std::endl;
				std::cout << "0. Go Back" << std::endl;
				std::cout << "1. Give User Input Data" << std::endl;
				std::cout << "2. Give File Data" << std::endl << std::endl;
				std::cout << "Please pick an option to use:" << std::endl;

				// recieve user inputs
				int inputSelection;
				std::cin >> inputSelection;
				std::cout << "---------------------------------------" << std::endl;

				// check which option was chosen
				switch (inputSelection)
				{
				case 0:

					// exits the class menu
					classMenuLoop = false;
					break;

				case 1:

					// declare user input "vector" variables
					float x;
					float y;
					float z;

					// recieve user input
					std::cout << std::endl << "Please enter the x value:";
					std::cin >> x;

					std::cout << std::endl << "Please enter the y value:";
					std::cin >> y;

					std::cout << std::endl << "Please enter the z value:";
					std::cin >> z;

					// predict phone orientation into console
					phoneOrientation.predictOrientation(x, y, z);
					break;

				case 2:

					// declare a filename string variable
					std::string fileName;

					// reviece user input
					std::cout << std::endl << "Please enter the file name (eg. 'unknownData.txt') :";
					std::cin >> fileName;

					// predict phone orientation into a file
					phoneOrientation.predictOrientation(fileName);

					// console message to let user know file was created
					std::cout << std::endl<< std::endl << "Result file created!" << std::endl << std::endl;

					break;
				}
			}
		}
		// if the user wants to exit program
		else if (classSelection == 0)
			mainMenuLoop = false;
		else
		{
			// each dummy class doesnt have any actual functionality
			std::cout << "This class has not been implemented yet... /o\\" << std::endl << std::endl;
			std::cout << "---------------------------------------" << std::endl << std::endl;
		}
	}

	// thank you message
	std::cout << "Thank you for using my program!" << std::endl;

	return 0;
}