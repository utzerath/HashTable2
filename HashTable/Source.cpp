#include <string>
#include <iostream>
#include <sstream>
#include "Hashing.h"
#include <fstream>
#include <vector>
using namespace std;



int main()
{

	ifstream txt("Text.txt");

	if (!txt) {
		cout << "File not found\n";
		exit(2);
	}
	hashing hash;
	string script;
	while (txt >> script)
	{
		hash.insert(script);
		
	}
	

	hash.display();                  
	cout << hash.find("through");
	


}