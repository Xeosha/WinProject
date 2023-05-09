#pragma once
#include <mysql_connection.h>
#include <cppconn/driver.h>
#include <cppconn/statement.h>
#include <cppconn/prepared_statement.h>
#include <vector>


ref class MySqlCon
{
private:
	sql::Driver* driver;
	sql::Connection* con;
	sql::PreparedStatement* stmt;
	sql::ResultSet* res;

public:
	void connection_to_database();										// подключение к БД
	bool check_user_data(std::string login, std::string password);		// проверка на логин / пароль
	~MySqlCon()
	{
		delete res;
		delete stmt;
		delete con;
	}
	std::vector < std::string> ConnectComboBox();
	std::string GetMailUser(std::string house);
	void add_house_user(std::string house);
	void del_house_user(std::string house);
};

