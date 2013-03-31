#pragma once
#include "config.h"


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
		ValidReturnValue IsFileValidNode(str path);



};