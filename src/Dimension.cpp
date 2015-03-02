#include "Dimension.h"

#include <sstream>
using std::ostringstream;

Dimension::Dimension( const Dimension& dimension ) {
	w = dimension.w;
	h = dimension.h;
}

string Dimension::toString() const {
	ostringstream oss;
	oss << "Dimension [ w: " << w << ", h: " << h << " ]";
	return oss.str();
}

