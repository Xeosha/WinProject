#include "MySqlCon.h"
void MySqlCon::connection_to_database()
{
	driver = get_driver_instance();
	con = driver->connect("g95888pd.beget.tech:3306", "g95888pd_login", "GtP1bySF");
	con->setSchema("g95888pd_login");
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

std::vector < std::string> MySqlCon::ConnectComboBox()
{
	stmt = con->prepareStatement("SELECT house FROM users");
	res = stmt->executeQuery();

	std::vector<std::string> arr;
	while(res->next())
	{
		arr.push_back(res->getString("house"));
	}
	return arr;
}

std::string MySqlCon::GetMailUser(std::string house)
{
	stmt = con->prepareStatement("SELECT mail FROM users WHERE house=?");
	stmt->setString(1, house);
	res = stmt->executeQuery();

	if (res->next())
		return res->getString("mail");
	return "";

}

void MySqlCon::add_house_user(std::string house)
{
	stmt = con->prepareStatement("INSERT INTO users (house, mail) VALUES (?, DEFAULT)");
	stmt->setString(1, house);
	stmt->execute();
}

void MySqlCon::del_house_user(std::string house)
{
	stmt = con->prepareStatement("DELETE FROM users WHERE house = ?");
	stmt->setString(1, house);
	stmt->execute();
}

