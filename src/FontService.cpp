#include "FontService.h"

#include <SDL_ttf.h>

void FontService::init() throw (std::runtime_error) {
	if( -1 == TTF_Init() )
	{
		throw runtime_error( TTF_GetError() );
	}	
}

void FontService::destroy() {
	TTF_Quit();
}

