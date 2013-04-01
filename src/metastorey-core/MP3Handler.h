#pragma once
#include "ifileformathandler.h"

namespace MetaStorey {

class MP3Handler :
	public IFileFormatHandler
{
public:
	MP3Handler(void);
	virtual ~MP3Handler(void);


	virtual ValidReturnValue IsFileValidNode(str path);
};


}