#pragma once
#include "toolbox.h"

ToolBox::ToolBox()
	:m_tools({})
{

}

void ToolBox::fillTools()
{
	std::vector <std::string> names = { "Cat",
										"Cheese",
										"Door",
										"Gift",
										"Key",
										"Mouse",
									    "Wall",
									    "Reset",
										"Delete",
										"Save"};

	for (int i=0;i<10;i++)
	{
		Button temp = Button();
		temp.setText(names[i]);
		temp.setButtonLocation(i);
		m_tools.push_back(temp);
	}
}

const std::vector <Button> ToolBox::getTools() const
{
	return m_tools;
}