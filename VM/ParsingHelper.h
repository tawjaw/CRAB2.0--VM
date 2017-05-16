#pragma once

#include <string>
#include <fstream>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cassert>
#include <sstream>
#include <iterator>
#include <algorithm>
#include <stdio.h>
#include <ctype.h>

// Case insensitive strings (eg: aDD == Add) 
// This is used for parsing program text files
// Stolen from: Herb Suter - http://www.gotw.ca/gotw/029.htm

struct ci_char_traits : public std::char_traits<char>
	// just inherit all the other functions
	//  that we don't need to override
{
	static bool eq(char c1, char c2)
	{
		return toupper(c1) == toupper(c2);
	}
	static bool ne(char c1, char c2)
	{
		return toupper(c1) != toupper(c2);
	}
	static bool lt(char c1, char c2)
	{
		return toupper(c1) <  toupper(c2);
	}

	static int compare(const char* s1,
		const char* s2,
		size_t n) {
#if defined(PLATFORM_OSX)
		return strcasecmp(s1, s2);
#else
		return _memicmp(s1, s2, n);
#endif
		// if available on your compiler,
		//  otherwise you can roll your own
	}

	static const char*
		find(const char* s, int n, char a) {
		while (n-- > 0 && toupper(*s) != toupper(a)) {
			++s;
		}
		return s;
	}
	
	

};



typedef std::basic_string<char, ci_char_traits> ci_string;
typedef std::basic_ifstream<char, ci_char_traits> ci_ifstream;
typedef std::basic_istringstream<char, ci_char_traits> ci_istringstream;
typedef std::basic_stringstream<char, ci_char_traits> ci_stringstream;
typedef std::basic_istream<char, ci_char_traits> ci_istream;

std::ostream& operator<<(std::ostream& os, const ci_string& str);

