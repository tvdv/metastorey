#pragma once
#include "config.h"
#include "node.h"

namespace MetaStorey {

class FileSystemNode :
	public Node
{
public:
	FileSystemNode(void);
	~FileSystemNode(void);


	str GetFileSystemPath();

};

}