#pragma once

#include <iostream>

/*

just a own built library from neulii

*/

namespace neulib
{

	/*
		This function checks if the string parameter is a valid number.
	*/
	bool checkIfStringIsValidNumber(const std::string value);

	/*
		reads all text from file and give it back at string
	*/
	std::string getTextFromFile(const std::string& fileName);

	/*
		reads all text from file and give it back at string
	*/
	std::vector<std::string> getLinesFromFile(const std::string& fileName);

	/*
		appends text to file
	*/
	void addTextToFile(const std::string& text, const std::string& fileName);

	/*
		log text to console
	*/
	void log(std::string logText);

	/*
		splits string into individuals by separator
	*/
	std::vector<int> splitStringIntoValues(std::string string, std::string seperator);

	/*
		splits string into substrings
	*/
	std::vector<std::string> splitStringIntoStrings(std::string string, std::string seperator);
	
} //namespace neulib