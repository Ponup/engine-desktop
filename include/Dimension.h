#pragma once

#include <string>
using std::string;

/**
 * Contains information about the size of an element.
 */
class Dimension {

public:
	unsigned short w;
	unsigned short h;

	Dimension() : w( 0 ), h( 0 ) {}
	Dimension( unsigned short w, unsigned short h ) : w( w ), h( h ) {}
	Dimension( const Dimension& dimension );
	
	string toString() const;
};

