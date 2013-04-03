#include "Node.h"


namespace MetaStorey {


Node::Node(str nodeId)
	:m_NodeId(nodeId)
{
}


Node::~Node(void)
{

}

str Node::GetNodeId()
{
	return m_NodeId;
}

}