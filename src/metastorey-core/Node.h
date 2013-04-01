#pragma once

#include <string>

namespace MetaStorey {

// Represents the storage of a blob of data and its associated blob of meta data
class Node
{
public:
	Node(void);
	virtual ~Node(void);

	std::string GetNodeId();
private:


	std::string m_NodeId;

};


}