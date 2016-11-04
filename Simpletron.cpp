
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>

using namespace std;
class Simpletron
{

private:
	int accumulator;
	int mem[1000];
	string instruction[100];
	int ic = 0;
	int current_op_code;
	int current_mem_location;
	int num_intructions;

public:

	int getIC()
	{
		return ic;
	}

	int getNumInstructions()
	{
		return num_intructions;
	}


	void readInFile()
	{
		ifstream file; 
		file.open("example2.sml");
		int i = 0;
		// load our instructions
		while (!file.eof())
		{
			string current_line = ""; 
			getline(file, current_line);
			// grab substring (- the plus)
			
			current_line = current_line.substr(1, current_line.size() - 1);
			instruction[i] = current_line;
			num_intructions++;
			i++;
		}

		file.close();
	}

	int fetch()
	{
		ic++;
		return 1;
	}

	int decode()
	{
		string current_instruction = instruction[ic];
		
		string op_code = current_instruction.substr(0, 2);
		string mem_location = current_instruction.substr(2, 3);

		// Convert current op code and mem location from string to global variables
		current_op_code = stoi(op_code);
		current_mem_location = stoi(mem_location);

		return 1;
	}

	int execute()
	{
		string input = "";
		switch (current_op_code)
		{
			// read in line
			case 10:
				// print this for aesthetics 
				cout << "Input thing >>";
				// get line from user
				getline(cin, input);
				mem[current_mem_location] = stoi(input);
				break;

			case 11:
				cout << "Answer: ";
				cout << mem[current_mem_location];
				break;

			// load
			case 20:
				accumulator = mem[current_mem_location];
				break;

			// store
			case 21:
				mem[current_mem_location] = accumulator;
				break;

			// Add
			case 30:
				accumulator += mem[current_mem_location];
				break;

			// branch
			case 40:
				ic = mem[current_mem_location] -1;
				break;

			//branch negative
			case 41:
				if (accumulator < 0)
				{
					ic = mem[current_mem_location] -1;
				}
				break;

			//branch zero
			case 42:
				if (accumulator == 0)
				{
					ic = mem[current_mem_location] -1;
				}
				break;

			// Halt
			case 43:
				system("pause");
				
				break;

		}

		return 1;
	}



};