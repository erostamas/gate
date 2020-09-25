#pragma once

#include "erostamas/CommandProcessor.h"

class Gate {
public:
    Gate();
    ~Gate();

	void run();

protected:
    CommandProcessor _commandProcessor;
    
};