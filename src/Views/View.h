#pragma once

#include <input.h>

class View
{
public:
	virtual int HandleInput(int focus, const Input& input);
	virtual int Display();
};
