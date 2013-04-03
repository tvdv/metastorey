#pragma once
#include <string>
#include <memory>
#include "config.h"

namespace MetaStorey {

// Represents the storage of a blob of data and its associated blob of meta data
class Node
{
public:
	
	virtual ~Node(void);

	str GetNodeId();

	virtual std::shared_ptr<std::istream> GetMetaData()=0;

protected:
	Node(str nodeId);
private:
	Node(void);

	str m_NodeId;

};


}