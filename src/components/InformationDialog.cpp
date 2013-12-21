#include "components/InformationDialog.h"

#include <SDL_gfxPrimitives.h>

#include "FontManager.h"
#include "SurfaceUtil.h"

InformationDialog::InformationDialog(Surface *screen_, string message) : screen(screen_) {
	quit = false;

	font = FontManager::getFont("FreeSansBold", 14);
	font->setColor(Color(0, 0, 0));
				
	Text messageText(message, font);

	unsigned int windowWidth = 20 + messageText.getDimension().getWidth() + 20;
	unsigned int windowHeight = 20 + messageText.getDimension().getHeight() + 20 + 50 + 20;
	
	windowDimension = Dimension(windowWidth, windowHeight);
	
	boxRGBA(screen->toSDL(), 0, 0, 800, 600, 0, 0, 0, 150);
	
	screen->flip();
	
	window = new Surface(screen_, windowDimension);
	window->clean();
	
	messageText.draw(Point(20, 20), window);
	
	ButtonSkin *skinNormal = new ButtonSkin("resources/images/widgets/button_left.png", "resources/images/widgets/button_center.png", "resources/images/widgets/button_right.png");
	ButtonSkin *skinOver = new ButtonSkin("resources/images/widgets/button-over_left.png", "resources/images/widgets/button-over_center.png", "resources/images/widgets/button-over_right.png");
	
	button = new Button("Ok", font, skinNormal, skinOver);
		
	Point buttonPos;
	
	int winCenter = (windowWidth >> 1) - (button->getDimension().getWidth() >> 1);
	buttonPos = Point(winCenter, windowDimension.getHeight() - 50);
	button->setPosition(buttonPos);
	
	windowPosition = SurfaceUtil::drawCentered(window, screen);
	
	sensAreas.addArea(Area(button->getPosition() + windowPosition, button->getDimension()));

	update();
}

InformationDialog::~InformationDialog() {
	//delete font;
		
	delete button;
	
	delete window;
}

void InformationDialog::show() {
	SDL_Event event;
	while(!quit) {
		while(SDL_PollEvent(&event))
			handleEvents(event);
		update();
	}
}

void InformationDialog::update() {
	button->draw(window);
	SurfaceUtil::drawCentered(window, screen);
	screen->flip();
}

void InformationDialog::handleEvents(SDL_Event event) {
	if(event.type == SDL_MOUSEMOTION) {
		SDL_MouseMotionEvent motion = event.motion;
		int resolved = sensAreas.resolve(motion.x, motion.y);
		if(resolved != -1) {
			button->setState(STATE_OVER);
		} else {
			button->setState(STATE_NORMAL);
		}
	} else 
	if(event.type == SDL_MOUSEBUTTONDOWN) {
		SDL_MouseButtonEvent button = event.button;
		int resolved = sensAreas.resolve(button.x, button.y);
		if(resolved != -1) {
			quit = true;
		}
	} else
	if(event.type == SDL_KEYDOWN) {
		if(event.key.keysym.sym == SDLK_ESCAPE) {
			quit = true;
		} else
		if(
			event.key.keysym.sym == SDLK_RETURN ||
			event.key.keysym.sym == SDLK_SPACE
		) {
			quit = true;
		}
	}
}

