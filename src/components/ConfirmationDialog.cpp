#include "components/ConfirmationDialog.h"

#include <SDL_gfxPrimitives.h>

#include "FontManager.h"
#include "SurfaceUtil.h"

ConfirmationDialog::ConfirmationDialog(Surface *screen_, const char *message) : screen(screen_) {
	currentOption = 0;
	
	selected = DIALOG_CANCEL;
	quit = false;

	font.load("resources/fonts/FreeSansBold.ttf", 14);
	font.setColor(Color(0, 0, 0));
				
	Text messageText(message, &font);

	unsigned int windowWidth = 20 + messageText.getDimension().getWidth() + 20;
	unsigned int windowHeight = 20 + messageText.getDimension().getHeight() + 20 + 50 + 20;
	
	windowDimension = Dimension(windowWidth, windowHeight);
	
	boxRGBA(screen->toSDL(), 0, 0, 800, 600, 0, 0, 0, 150);
	
	screen->flip();
	
	window = new Surface(screen_, windowDimension);
	window->clean();
	
	messageText.draw(Point(20, 20), window);
	
	ButtonSkin skinNormal("resources/images/widgets/button_left.png", "resources/images/widgets/button_center.png", "resources/images/widgets/button_right.png");
	ButtonSkin skinOver("resources/images/widgets/button-over_left.png", "resources/images/widgets/button-over_center.png", "resources/images/widgets/button-over_right.png");
	
	buttons[0] = new Button("Yes", &font, &skinNormal, &skinOver);
	buttons[1] = new Button("No", &font, &skinNormal, &skinOver);
		
	Point buttonPos[2];
	
	int winCenter = (windowWidth >> 2) - (buttons[0]->getDimension().getWidth() >> 1);
	buttonPos[0] = Point(winCenter, windowDimension.getHeight() - 50);
	
	winCenter = ((windowWidth >> 2) * 3) - (buttons[1]->getDimension().getWidth() >> 1);
	buttonPos[1] = Point(winCenter, windowDimension.getHeight() - 50);

	buttons[0]->setPosition(buttonPos[0]);
	buttons[1]->setPosition(buttonPos[1]);
	
	windowPosition = SurfaceUtil::drawCentered(window, screen);
	
	sensAreas.addArea(Area(buttons[0]->getPosition() + windowPosition, buttons[0]->getDimension()));
	sensAreas.addArea(Area(buttons[1]->getPosition() + windowPosition, buttons[1]->getDimension()));

	update();
}

ConfirmationDialog::~ConfirmationDialog() {
	delete buttons[0];
	delete buttons[1];
	delete window;
}

int ConfirmationDialog::showGetSelected() {
	SDL_Event event;
	while(!quit) {
		while(SDL_PollEvent(&event))
			handleEvents(event);
		update();
	}

	return selected;	
}

void ConfirmationDialog::update() {
	for(int x = 0; x < 2; x++) {
		if(x == currentOption) {
			buttons[x]->setState(STATE_OVER);
		} else {
			buttons[x]->setState(STATE_NORMAL);
		}
		buttons[x]->draw(window);
	}
	
	SurfaceUtil::drawCentered(window, screen);
	screen->flip();
}

void ConfirmationDialog::handleEvents(SDL_Event event) {
	if(event.type == SDL_MOUSEMOTION) {
		SDL_MouseMotionEvent motion = event.motion;
		int resolved = sensAreas.resolve(motion.x, motion.y);
		if(resolved != -1) {
			currentOption = resolved;
		}
	} else 
	if(event.type == SDL_MOUSEBUTTONDOWN) {
		SDL_MouseButtonEvent button = event.button;
		int resolved = sensAreas.resolve(button.x, button.y);
		if(resolved != -1) {
			selected = resolved;
			quit = true;
		}
	} else
	if(event.type == SDL_KEYDOWN) {
		if(event.key.keysym.sym == SDLK_ESCAPE) {
			selected = -1;
			quit = true;
		}
		if(
			event.key.keysym.sym == SDLK_LEFT ||
			event.key.keysym.sym == SDLK_RIGHT ||
			event.key.keysym.sym == SDLK_TAB
		) {
			currentOption = currentOption ? 0 : 1;
		} else
		if(
			event.key.keysym.sym == SDLK_RETURN ||
			event.key.keysym.sym == SDLK_SPACE
		) {
			selected = currentOption;
			quit = true;
		}
	}
}

