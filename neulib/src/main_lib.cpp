#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "..\include\main_lib.h"


namespace neulib
{
	bool checkIfStringIsValidNumber(const std::string value)
	{
		if (value.empty())
			return false;

		int digitsInString = 0;
		int stringLength = value.length();

		for (int i = 0; i < stringLength; i++)
		{
			if (!(isdigit(value.at(i)) || (value.at(i) == '-')))
			{
				return false;
			}
			else
			{
				digitsInString++;
			}
		}

		if (digitsInString == value.length())
		{
			return true;
		}
		else
			return false;
	}

	std::string getTextFromFile(const std::string& fileName) {

		std::string inputText;
		std::string line;

		std::ifstream input;

		input.open(fileName, std::ios_base::in);

		while (std::getline(input, line)) {
			inputText = inputText + "\n" + line;
		}

		input.close();

		return  inputText;
	}

	void addTextToFile(const std::string& text, const std::string& fileName) {

		std::ofstream output;

		output.open(fileName, std::ios_base::out | std::ios_base::app);

		if (output.is_open()) {
			output << text;
			output.close();
			std::cout << std::endl << "Text written to File" << std::endl;
		}

		else {
			std::cout << "Error by Opening File" << std::endl;
		}
	}

	void log(std::string logText)
	{
		std::cout << logText << std::endl;
	}

	std::vector<std::string> getLinesFromFile(const std::string& fileName)
	{
		std::ifstream input;
		input.open(fileName, std::ios::in);

		std::vector<std::string> loadedStrings;
		std::string line;

		while (std::getline(input, line)) {

			loadedStrings.push_back(line);
			//std::cout << line << std::endl;
		}

		return loadedStrings;
	}

	std::vector<int> splitStringIntoValues(std::string string, std::string seperator) {
		
		std::vector<int> values;
		
		size_t pos = 0;
		std::string token;

		while ((pos = string.find(seperator)) != std::string::npos)
		{
			token = string.substr(0, pos);
			//std::cout << token << std::endl;
			values.push_back(atoi(token.c_str()));

			string.erase(0, pos + seperator.length());
		}

		values.push_back(atoi(string.c_str()));
		
		return values;
	}

	std::vector<std::string> splitStringIntoStrings(std::string string, std::string seperator)
	{
		std::vector<std::string> values;

		size_t pos = 0;
		std::string token;

		while ((pos = string.find(seperator)) != std::string::npos)
		{

			token = string.substr(0, pos);
			//std::cout << token << std::endl;
			values.push_back(token);

			string.erase(0, pos + seperator.length());
		}

		values.push_back(string);

		return values;
	}


}// namespace neulib

