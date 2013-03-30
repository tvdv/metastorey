#pragma once
#include <vector>
#include <memory>
#include "Node.h"

class IRepository
{
public:
	IRepository(void);
	virtual ~IRepository(void);

	virtual std::vector<std::shared_ptr<Node>> GetNodes()=0;

	//TODO: Add method for creating nodes
};

