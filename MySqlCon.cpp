#include "MySqlCon.h"
void MySqlCon::connection_to_database()
{
	driver = get_driver_instance();
	con = driver->connect("x958887o.beget.tech:3306", "x958887o_login", "bGYD7d2h");
	con->setSchema("x958887o_login");
}

bool MySqlCon::check_user_data(std::string login, std::string password)
{
	stmt = con->prepareStatement("SELECT * FROM passwords WHERE login=? AND password=?");
	stmt->setString(1, login);
	stmt->setString(2, password);
	res = stmt->executeQuery();

	if (res->next()) {
		return 1;
	}
	else {
		return 0;
	}
}