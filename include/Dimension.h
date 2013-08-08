#ifndef DIMENSION_H
#define DIMENSION_H

/**
 * Contains information about the dimension of an element.
 */
class Dimension {
	private:
		unsigned short width;
		unsigned short height;
	
	public:
		Dimension() : width(0), height(0) { }
		Dimension(unsigned short width_, unsigned short height_) : width(width_), height(height_) { }
		Dimension(const Dimension &dimension);
		
		void setWidth(unsigned short width);
		unsigned short getWidth() const;

		void setHeight(unsigned short height);
		unsigned short getHeight() const;

		const char *toString() const;
};

#endif

