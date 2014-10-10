#pragma once

/**
 * Contains information about the dimension of an element.
 */
class Dimension {
	public:
		unsigned short w;
		unsigned short h;

		Dimension() : w( 0 ), h( 0 ) {}
		Dimension( unsigned short w_, unsigned short h_ ) : w( w_ ), h( h_ ) {}
		Dimension( const Dimension& dimension );
		
		const char* toString() const;
};

