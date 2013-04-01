#include <algorithm>
#include <boost/algorithm/string.hpp>
#include "MP3Handler.h"

namespace MetaStorey {

MP3Handler::MP3Handler(void)
{
}


MP3Handler::~MP3Handler(void)
{
}


MP3Handler::ValidReturnValue MP3Handler::IsFileValidNode(str path)
{
	auto ext=boost::to_upper_copy(GetFileExtesnion(path));

	if (ext.empty())
	{
		return DeferToNextHandler;
	}

	if (ext.compare(L"MP3")==0)
	{
		return Yes;
	}

	return DeferToNextHandler;
}

}