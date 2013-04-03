#pragma once
#include "Node.h"

namespace MetaStorey {
class MP3Node :
	public Node
{
public:
	explicit MP3Node(str filePath);
	virtual ~MP3Node(void);


	virtual std::shared_ptr<std::istream> GetMetaData();
protected:
	str GetPath();
private:
};


}