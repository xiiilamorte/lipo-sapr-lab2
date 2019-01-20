#include <cstdlib>
#include <iostream>		// I/O Stream Library
#include "stdio.h"
#include <string>
#include <pcrecpp.h>	// PCRE library
#include <sstream>		// std::stringstream
#include <algorithm>    // std::find
#include <iterator>		// std::vector::iterator
#include <vector>		// std::vector
#include "HeaderMatch.h"

using namespace std;

HeaderMatch::HeaderMatch()
{
	mainRegexp = "^(.*#include\\s[<\"](\\w+\\/?)+\\.h[>\"])$";
}

int HeaderMatch::GetUniqueHeadersCount()
{
	string input;
	string errorPartString;
	string nullArg;
	pcrecpp::RE mainPattern( mainRegexp );
	
	vector<string>array;
	vector<string>::iterator arrayIterator;
	
	std::cout << std::endl;
	
	while ( !cin.eof() )
	{
		input += cin.get();
		if ( input.find("\n") != -1 )
		{
			pcrecpp::StringPiece piece(input);
				
			if ( mainPattern.Consume(&piece, &errorPartString, &nullArg) )
			{
				if ( std::find(array.begin(), array.end(), errorPartString) == array.end() ) 
				{
					array.push_back(input);
				}
			}
			input = "";
			errorPartString = "";
			std::cin.clear();
		}
	}
	
	return array.size();
}