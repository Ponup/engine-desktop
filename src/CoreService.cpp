#include "CoreService.h"

CoreService::CoreService( Uint32 flags_ ) : flags( flags_ ) {
}

void CoreService::init() throw( runtime_error ) {
	if( SDL_Init( flags ) == -1 ) {
		throw runtime_error( SDL_GetError() );
	}
	
	atexit( SDL_Quit );
}

void CoreService::destroy() {
	SDL_Quit();	
}

