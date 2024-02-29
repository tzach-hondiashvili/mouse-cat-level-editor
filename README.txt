Mouse and Cat Game - Daniel Dalal & Tzach Hondiashvili

Description:

This is a simple SFML-based game map-editor where a user (you) chooses the map size (x y) and an object from the tool box menu and place them on the map.
The goal is to create a world that is playable and fair. Later on you press "Save" and the map will be saved as Board.txt in "out" folder as a terminal based game.

How to Build:

    Use LMB to select an object from the ToolBox.
    Use LMB to place on the grids. 
    **You can only place 1 "Mouse" on a map**
    Reset the map and open a new one by pressing "Reset". NOTE: Youll need to type rows and cols again.
    Save the map by pressing "Save".
    Delete an object by selecting "Delete" and use LMB to delete object from the grids.	
    Close the game map-editor by pressing "X".	

Run the game using the command: ./oop1_ex03

List of files:
	
	board.cpp & board.h -  
	Implements the functionalities of the Board class, including constructors, methods for accessing the board, creating a new level, handling events, printing the game window, managing textures, and saving the level to a file.
	 
	button.cpp & button.h -
	Implements the functionalities of the Button class, including constructors, methods for setting the location of the button, setting text, creating a rectangular shape representing the button, and creating text for the button.	
	
	tile.cpp & tile.h -
	Implements the functionalities of the Tile class, including constructors, methods for setting and getting the location, size, and texture of the tile, creating a rectangular shape representing the tile, and setting and getting the texture of the tile.
	
	toolbox.cpp & toolbox.h -
	Implements the functionalities of the ToolBox class, including constructors, a method for filling the toolbox with predefined buttons representing various tools, and a method for accessing the buttons.

	window.cpp & window.h -
	Implements the functionalities of the Window class, including constructors, methods for running the level editor, handling user clicks, printing the game window, managing textures, and saving the level to a file.
	
	row.cpp & row.h -
	Implements the functionalities of the Row class, including constructors, destructor, methods for accessing and modifying elements, resizing, and performing deep copy assignment.

Algorithms:

	Deep Copy Implementation:
	Implementing a deep copy constructor and assignment operator in the Row class to ensure proper copying of dynamically allocated memory and prevent shallow copy issues.
	
Object Oriented Design:

	Board Class:
        Manages the game board, handling the placement of mouse, cats, and obstacles, orchestrating the game flow, and ensuring interaction between different elements.

    	Window Class:
        Represents the game window, responsible for running the level editor, printing the game window, managing textures, and saving the level to a file. It interacts with the Board and ToolBox classes during gameplay.

    	Tile Class:
        Represents a tile on the game board, managing its location, size, and texture. It provides methods for setting and getting these properties, as well as creating a rectangular shape representing the tile.

    	Button Class:
        Represents a button in the level editor toolbox, managing its location, size, and text. It provides methods for setting these properties and creating a rectangular shape and text for the button.

    	Row Class:
        Represents a row of tiles on the game board, managing its size and array of tiles. It provides methods for accessing and modifying individual tiles, as well as adding new tiles to the row and checking if the row is empty.

Known Bugs:
	**OPEN TO BETA TESTING** ;)

License

	This project is licensed under the HAC students:
	Daniel Dalal - 211375324
	Tzach Hondiashvili - 212048037

Enjoy the game map-editor! 🐭🐾