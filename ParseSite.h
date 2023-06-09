#define CURL_STATICLIB
#pragma once

#include <curl/curl.h>
#include <nlohmann/json.hpp>
#include <iostream>

namespace Parser
{

	using namespace nlohmann;	// ��� json

	std::string WEATHER_URL = "https:\//www.gismeteo.ru/weather-perm-4476/now/";	// ������ ������� ����� ������
	std::string SERVER_URL = "http:\//g95888pd.beget.tech/";						// ������ ��� ������ � ���������
	std::string TEMPERATURE_PARSER = "0";											// ������������� ���������� ����� � �����
	std::string TEMPERATURE_USER = "0";												// ����������� ������������
	std::string TEMPERATURE_ROOM = "0";												// ����������� � �������
	std::string PNagr = "0";
	std::string error = "0";

	std::string tmpHotWater, tmpColdWater, pomp, rasxVozd, rasxGaza, davlVod, davlGaza, rasxGazaMonth, Adress, Pochta;

	namespace files
	{
		std::string postPS = "getPC.php";
		std::string getPS = Adress + ".json";
		std::string getM = "newM.json";
	};

	size_t write_data(void* ptr, size_t size, size_t nmemb, std::string* data) {
		data->append((char*)ptr, size * nmemb);
		return size * nmemb;
	}

	// ��������� html �� ������
	std::string get_data_from_site(std::string url) { 
		CURL* curl;
		CURLcode response;
		std::string data = "";
		curl = curl_easy_init();
		if (curl)
		{	
			curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
			curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_data);
			curl_easy_setopt(curl, CURLOPT_WRITEDATA, &data);
			response = curl_easy_perform(curl);
			if (response != CURLE_OK) {
				std::cerr << "Error: " << curl_easy_strerror(response) << std::endl;
				return "";
			}
		
			curl_easy_cleanup(curl);
			if (url == WEATHER_URL)
			{
				std::cout << url << " GET: " << "Parsing temperature = " << TEMPERATURE_PARSER << std::endl;
			}
			else std::cout << url <<" GET: " << data << std::endl;
		}
		return data;
	};

	// ������ �� ������ json �����
	int post_data_to_site(std::string file, json data) {
		CURLcode ret;
		CURL* hnd;
		struct curl_slist* slist1;
		std::string jsonstr = data.dump();

		slist1 = NULL;
		slist1 = curl_slist_append(slist1, "Content-Type: application/json");

		hnd = curl_easy_init();
		if (hnd)
		{
			curl_easy_setopt(hnd, CURLOPT_URL, (SERVER_URL + file).c_str());
			curl_easy_setopt(hnd, CURLOPT_NOPROGRESS, 1L);
			curl_easy_setopt(hnd, CURLOPT_POSTFIELDS, jsonstr.c_str());
			curl_easy_setopt(hnd, CURLOPT_USERAGENT, "Mozilla/5.0");
			curl_easy_setopt(hnd, CURLOPT_HTTPHEADER, slist1);
			curl_easy_setopt(hnd, CURLOPT_POSTFIELDSIZE, jsonstr.size());
			curl_easy_setopt(hnd, CURLOPT_MAXREDIRS, 50L);
			curl_easy_setopt(hnd, CURLOPT_CUSTOMREQUEST, "POST");
			curl_easy_setopt(hnd, CURLOPT_TCP_KEEPALIVE, 1L);

			ret = curl_easy_perform(hnd);
			if (ret != CURLE_OK) {
				std::cerr << "Error: " << curl_easy_strerror(ret) << std::endl;
				return 0;
			}
			std::cout << SERVER_URL + file << " POST: " << jsonstr << std::endl;
			curl_easy_cleanup(hnd);
			curl_slist_free_all(slist1);
			return 1;
		} return 0;
	};

	// ��������� ����������� � ���������� TEMPERATURE_PARSER
	std::string parse_temperature(std::string data) {
		if (data == "") return "0";
		int pos = data.find("<span class=\"sign\">");
		if ('-' == data[pos + 19])
		{
			int pos_end = data.find("</span>", pos + 27);
			return "-" + data.substr(pos + 27, pos_end - pos - 27);
		}
		else if ('+' == data[pos + 19])
		{
			int pos_end = data.find("</span>", pos + 27);
			return data.substr(pos + 27, pos_end - pos - 27);
		}
		else return "0";
	};

	// ����� get_data_from_site � parse_temperature
	void Parsing() {
		std::string data = get_data_from_site(WEATHER_URL);
		TEMPERATURE_PARSER = parse_temperature(data);
	};

	void ParsingUserTemperature()
	{
		try {
			std::string data = get_data_from_site(SERVER_URL + files::getM);

			json js = json::parse(data);
			TEMPERATURE_USER = js[Pochta];
		}
		catch (...)
		{
			TEMPERATURE_USER = "25";
		}
	}

	void ParsingRoomTemperature()
	{
		try {
			std::string data1 = Parser::get_data_from_site(SERVER_URL + files::getPS);
			json datajs = json::parse(data1);
			TEMPERATURE_ROOM = datajs["tempKomn"];
			tmpHotWater = datajs["tempGor"];
			tmpColdWater = datajs["tempXol"];
			error = datajs["error"];
			PNagr = datajs["PNagr"];
			pomp = datajs["pomp"];
			rasxVozd = datajs["rasxVozd"];
			rasxGaza = datajs["rasxGaza"];
			davlVod = datajs["davlVod"];
			davlGaza = datajs["davlGaza"];
			rasxGazaMonth = datajs["rasxGazaMes"];
		}
		catch (...)
		{
			TEMPERATURE_ROOM = "0";
			tmpHotWater = "0";
			tmpColdWater = "0";
			error = "0";
			PNagr = "0";
			pomp = "0";
			rasxVozd = "0";
			rasxGaza = "0";
			davlVod = "0";
			davlGaza = "0";
			rasxGazaMonth = "0";
		}
	}

}

