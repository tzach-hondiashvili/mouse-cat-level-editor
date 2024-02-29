#pragma once
#include <vector> 
#include "button.h" 

class ToolBox {
public:
    ToolBox();
    void fillTools();
    const std::vector <Button> getTools() const;

private:
    std::vector <Button> m_tools; // Use a vector to store the tools in the toolbox
};