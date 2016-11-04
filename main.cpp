#include "Simpletron.cpp"

void main()
{

	Simpletron *simply = new Simpletron();
	simply->readInFile();

	while (simply->getIC() < simply->getNumInstructions())
	{
		simply->decode();
		simply->execute();
		simply->fetch();
	}

}

