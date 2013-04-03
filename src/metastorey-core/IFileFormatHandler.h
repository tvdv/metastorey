#pragma once
#include <memory>
#include "config.h"
#include "Node.h"

namespace MetaStorey {

class IFileFormatHandler
{

public:
		typedef enum {
			Yes,
			No,
			DeferToNextHandler, //next handler is checked.
		} ValidReturnValue;

		IFileFormatHandler(void);
		virtual ~IFileFormatHandler(void);


		// determines whether a file found in the file system represnts a valid node
		//  if, for example, meta data is stored in a file, then that file should return No
		virtual ValidReturnValue IsFileValidNode(str path)=0;

		//helper function, returns the extension (no "."). Or an empty string if there is extension
		static str GetFileExtesnion(str path);


		virtual std::shared_ptr<Node> CreateNode(str path)=0;

};

}