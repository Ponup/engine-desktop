#pragma once

class ResultSet {
	
private:
	char **data;
	int rowsNum;
	int colsNum;

public:
	ResultSet(char ** data, int rowsNum, int colsNum);
	~ResultSet();
	
	int columnCount() const;
	char *getColumn(int index) const;
	unsigned int rowsCount() const;
	const char *getString(int row, int column) const;
	int getInt(int row, int column) const;
};

