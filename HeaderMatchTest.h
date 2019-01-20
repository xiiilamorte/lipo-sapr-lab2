#include <cppunit/extensions/TestFactoryRegistry.h>
#include <cppunit/ui/text/TextTestRunner.h>
#include <cppunit/extensions/HelperMacros.h>

class HeaderMatchTest : public CppUnit::TestCase
{
	public:
		void TestConstructor();
		void TestGetHeadersCount();
		
		CPPUNIT_TEST_SUITE( HeaderMatchTest );
		CPPUNIT_TEST( TestConstructor );
		CPPUNIT_TEST( TestGetHeadersCount );
		CPPUNIT_TEST_SUITE_END();
};