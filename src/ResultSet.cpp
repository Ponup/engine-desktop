#include "ResultSet.h"

#include <stdio.h>
#include <string.h>
#include <sqlite3.h>

ResultSet::ResultSet(char **data, int rowsNum, int colsNum) {
	this->data = data;
	this->rowsNum = rowsNum;
	this->colsNum = colsNum;
}

ResultSet::~ResultSet() {
	sqlite3_free_table(data);
	data = NULL;
}

int ResultSet::columnCount() const {
	return colsNum;
}

char* ResultSet::getColumn(int index) const {
	if (index < colsNum) {
		return data[index];
	} else {
		return NULL;
	}
}

unsigned int ResultSet::rowsCount() const {
	return rowsNum;
}

const char *ResultSet::getString(int row, int column) const {
	return data[ ( ( row + 1 ) * colsNum ) + column ];
}

int ResultSet::getInt(int row, int column) const {
	int result = 0;
	sscanf( data[ ( ( row + 1 ) * colsNum ) + column ], "%d", &result );
	return result;
}

