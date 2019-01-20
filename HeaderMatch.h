/*
ErrorFinder header file.
Includes a definition of pattern of main regular expression
(realization is in constructor in source file)
and realizations of note startings and endings.
*/

class HeaderMatch
{
	public:
		HeaderMatch();
		int GetUniqueHeadersCount();
		char* mainRegexp;
};