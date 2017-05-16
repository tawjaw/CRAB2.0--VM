#include "ParsingHelper.h"

	std::ostream & operator<<(std::ostream & os, const ci_string & str)
	{
		return os.write(str.data(), str.size());

	}
