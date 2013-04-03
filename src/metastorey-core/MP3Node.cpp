#include "MP3Node.h"

 #include <id3/tag.h>
namespace MetaStorey {

MP3Node::MP3Node(str filePath)
	: Node(filePath)
{
}


MP3Node::~MP3Node(void)
{
}


str MP3Node::GetPath()
{
	return GetNodeId();
}

std::shared_ptr<std::istream> MP3Node::GetMetaData()
{
	//TODO FINISH HERE: Conversion to ascii or utf-8? what does ifstream (used by id3lib) accept??
	//ID3_Tag tag(GetPath());

	return std::shared_ptr<std::istream>(NULL);
	
}
}