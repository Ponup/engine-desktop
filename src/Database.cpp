#include "Database.h"

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdarg.h>

#include <stdexcept>
using std::runtime_error;

Database Database::database;

void Database::init(const char *dbName) {
	database = Database(dbName);
}

Database &Database::getInstance() {	
	return database;
}

Database::Database() {
	db = NULL;
}

Database::Database(const char *dbName) {
	sqlite3_open(dbName, &db);
	if(sqlite3_errcode(db) != SQLITE_OK) {
		throw std::runtime_error(sqlite3_errmsg(db));
	}
}

Database::Database(const Database &dataBase) {
	this->db = dataBase.toSQLite();
}

Database::~Database() {
	if(db) {
		//sqlite3_close(db);
	}
}

sqlite3 *Database::toSQLite() const {
	return db;
}

void Database::update(const char *sql, ...) {
	char query[100];

	va_list params;
	va_start(params, sql);
	vsprintf(query, sql, params);
	va_end(params);

	char *errorMessage;
	int rc = sqlite3_exec(db, query, NULL, NULL, &errorMessage);
	if (rc != SQLITE_OK) {
		fprintf(stderr, "Database::execute error: %s\n", errorMessage);
	}
}

ResultSet &Database::execute(const char *sql, ...) throw(runtime_error) {
	char query[512];
	memset(query, '\0', 512);

	va_list params;
	va_start(params, sql);
	vsprintf(query, sql, params);
	va_end(params);

	char **result = NULL;
	int rowsNum, colsNum;
	char *errorMessage = (char *)malloc(sizeof(char) * 100);

	int rc = sqlite3_get_table(db, query, &result, &rowsNum, &colsNum, &errorMessage);
	if (rc != SQLITE_OK) {
		throw runtime_error(errorMessage);
	}

	ResultSet *rs = new ResultSet(result, rowsNum, colsNum);
	return *rs;
}
