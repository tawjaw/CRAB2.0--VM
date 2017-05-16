#include "common.h"
#include "ParsingHelper.h"


namespace crab {

	std::string cleanNumber(double f)
	{
		if (ceilf(f) == f)
			return std::to_string((int)f);
		else
		{

			std::stringstream ss;
			if (f > 10000)
			{

				ss << std::scientific << std::setprecision(5) << f;
				return ss.str();
			}
			else
			{
				ss << std::fixed << std::setprecision(2) << f;
				return ss.str();
			}
		}
	}
}