#pragma once
#include <mysql_connection.h>
#include <cppconn/driver.h>
#include <cppconn/statement.h>
#include <cppconn/prepared_statement.h>


ref class MySqlCon
{
private:
	sql::Driver* driver;
	sql::Connection* con;
	sql::PreparedStatement* stmt;
	sql::ResultSet* res;

public:
	void connection_to_database();										// ����������� � ��
	bool check_user_data(std::string login, std::string password);		// �������� �� ����� / ������
	~MySqlCon()
	{
		delete res;
		delete stmt;
		delete con;
	}
};

