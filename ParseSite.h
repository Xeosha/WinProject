#define CURL_STATICLIB
#pragma once

#include <curl/curl.h>
#include <nlohmann/json.hpp>
#include <iostream>

namespace Parser
{

	using namespace nlohmann;	// дл€ json

	size_t write_data(void* ptr, size_t size, size_t nmemb, std::string* data) {
		data->append((char*)ptr, size * nmemb);
		return size * nmemb;
	}

	std::string WEATHER_URL = "https:\//www.gismeteo.ru/weather-perm-4476/now/";	// откуда парсить темпу погоды
	std::string SERVER_URL = "http:\//x958887o.beget.tech/";						// ссылка дл€ работы с ардуинкой
	std::string TEMPERATURE_PARSER = "0";											// обновл€юща€с€ переменна€ темпы в ѕерми

	namespace files
	{
		std::string postPS = "getPC.php";
		std::string getPS = "new.json";
	};

	ref class ParseSite
	{
	private:
	public:
		// получение html по ссылке
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
					std::cout << "GET: " << "Parsing temperature = " << TEMPERATURE_PARSER << std::endl;
				}
				else std::cout << "GET: " << data << std::endl;
			}
			return data;
		};

		// залить на сервер json файла
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
				std::cout << "POST: " << jsonstr << std::endl;
				curl_easy_cleanup(hnd);
				curl_slist_free_all(slist1);
				return 1;
			} return 0;
		};

		// запарсить температуру в переменную TEMPERATURE_PARSER
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
				return "+" + data.substr(pos + 27, pos_end - pos - 27);
			}
			else return "0";
		};

		// вызов get_data_from_site и parse_temperature
		void Parsing() {
			std::string data = get_data_from_site(WEATHER_URL);
			TEMPERATURE_PARSER = parse_temperature(data);
		};

		~ParseSite() {};
	};
}

