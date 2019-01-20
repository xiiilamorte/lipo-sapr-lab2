#include <pcrecpp.h>	// PCRE library
#include <iostream>		// ifstream/ofstream/fstream
#include "HeaderMatchTest.h"
#include "../HeaderMatch/HeaderMatch.h"

using namespace std;

void HeaderMatchTest::TestConstructor() 
{
	HeaderMatch match;
	const char* errorMessage = "HeaderMatch::HeaderMatch: regular expression isn't defined in constructor!";
	CPPUNIT_ASSERT_MESSAGE(errorMessage, match.mainRegexp != "");
}

void HeaderMatchTest::TestGetHeadersCount() 
{
	const char* errorMessage = "HeaderMatch::getUniqueHeadersCount: amount of unique headers isn't equal to real amount";
	
	HeaderMatch match;
	
	int headersCount = match.GetUniqueHeadersCount();
	
	CPPUNIT_ASSERT_MESSAGE(errorMessage, headersCount == 3);
};