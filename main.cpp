#include <cstdlib>
#include <iostream>		// I/O Stream Library
#include "stdio.h"
#include <pcrecpp.h>	// PCRE library
#include <cstring>		// std::string
#include <cppunit/extensions/TestFactoryRegistry.h>
#include <cppunit/ui/text/TextTestRunner.h>
#include <cppunit/extensions/HelperMacros.h>
#include "HeaderMatch/HeaderMatch.h"
#include "HeaderMatchTest/HeaderMatchTest.h"
#include <ctype.h>

using namespace std;

int main(int argc, char* argv[]) {

	CPPUNIT_TEST_SUITE_REGISTRATION( HeaderMatchTest );
	
	if ( argc >= 2 )
	{
		if ( strcmp(argv[1], "-t\n") || strcmp(argv[1], "--test\n") ) 
		{
			CppUnit::Test *test = CppUnit::TestFactoryRegistry::getRegistry().makeTest();
			CppUnit::TextTestRunner runner;
			runner.addTest(test);
			
			runner.run();
			
			exit(0);
		}
	}
	
	HeaderMatch match;
	
	std::cout << match.GetUniqueHeadersCount() << std::endl;
}