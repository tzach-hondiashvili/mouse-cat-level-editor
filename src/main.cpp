#include <cstdlib>
#include "consts.h"
#include "window.h"

int main()
{
	auto editor = Window();
	
	editor.runEditor();

	return EXIT_SUCCESS;
}
