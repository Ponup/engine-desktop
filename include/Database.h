#ifndef DATABASE_H
#define DATABASE_H

#include <sqlite3.h>

#include <stdexcept>
using std::runtime_error;

#include "ResultSet.h"

class Database {
	
private:
	static Database database;
	
	sqlite3 *db;

public:
	Database();
	Database(const char *dbName);
	Database(const Database &dataBase);
	~Database();

	static void init(const char *dbName);
	static Database &getInstance();

	void update(const char *sql, ...);
	ResultSet &execute(const char *sql, ...) throw(runtime_error);
	sqlite3 *toSQLite() const;
};

#endif
