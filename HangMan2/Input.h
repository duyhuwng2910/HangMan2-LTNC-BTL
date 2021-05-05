#ifndef INPUT_H
#define INPUT_H

#include <SDL.h>

class Inputs {
public:

    const Uint8* keyStates;
	bool quit;
	int mouse_x;
	int mouse_y;

    bool clicked = false;

    bool pressed = false;

	// Returns true if ESC or 'X' button is pressed
	bool check_for_quit(SDL_Event event);

	Inputs();

	void Update();
	// Has the ESC key or 'X' button been pressed?
    bool isKeyDown(int key);
};
#endif // INPUT_H
