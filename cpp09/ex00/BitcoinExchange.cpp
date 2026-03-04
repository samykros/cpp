#include "BitcoinExchange.hpp"

#include <fstream>
#include <iostream>
#include <sstream>
#include <cstdlib>

BitcoinExchange::BitcoinExchange(const std::string& dbPath) {
	loadDatabase(dbPath);
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& other) : _rates(other._rates) {}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& other) {
	if (this != &other)
		_rates = other._rates;
	return *this;
}

BitcoinExchange::~BitcoinExchange() {}

void BitcoinExchange::processInputFile(const std::string& inputPath) const {
	std::ifstream in(inputPath.c_str());
	if (!in.is_open()) {
		std::cerr << "Error: could not open file." << std::endl;
		return;
	}

	std::string line;
	if (!std::getline(in, line))
		return;

	while (std::getline(in, line)) {
		if (line.empty())
			continue;

		std::string::size_type sep = line.find('|');
		if (sep == std::string::npos) {
			std::cerr << "Error: bad input => " << line << std::endl;
			continue;
		}

		std::string date = line.substr(0, sep);
		std::string valueStr = line.substr(sep + 1);

		// trim spaces
		while (!date.empty() && (date[0] == ' ' || date[0] == '\t'))
			date.erase(0, 1);
		while (!date.empty() && (date[date.size() - 1] == ' ' || date[date.size() - 1] == '\t'))
			date.erase(date.size() - 1, 1);
		while (!valueStr.empty() && (valueStr[0] == ' ' || valueStr[0] == '\t'))
			valueStr.erase(0, 1);
		while (!valueStr.empty() && (valueStr[valueStr.size() - 1] == ' ' || valueStr[valueStr.size() - 1] == '\t'))
			valueStr.erase(valueStr.size() - 1, 1);

		if (!isValidDate(date)) {
			std::cerr << "Error: bad input => " << date << std::endl;
			continue;
		}

		double value;
		if (!isValidValue(valueStr, value)) {
			continue;
		}

		std::map<std::string, double>::const_iterator it = _rates.lower_bound(date);
		if (it == _rates.end()) {
			if (_rates.empty()) {
				std::cerr << "Error: no data." << std::endl;
				continue;
			}
			--it;
		} else if (it->first != date) {
			if (it == _rates.begin()) {
				std::cerr << "Error: bad input => " << date << std::endl;
				continue;
			}
			--it;
		}

		double result = value * it->second;
		std::cout << date << " => " << value << " = " << result << std::endl;
	}
}

void BitcoinExchange::loadDatabase(const std::string& dbPath) {
	std::ifstream db(dbPath.c_str());
	if (!db.is_open()) {
		std::cerr << "Error: could not open database." << std::endl;
		return;
	}

	std::string line;
	if (!std::getline(db, line))
		return;

	while (std::getline(db, line)) {
		if (line.empty())
			continue;
		std::string::size_type sep = line.find(',');
		if (sep == std::string::npos)
			continue;
		std::string date = line.substr(0, sep);
		std::string rateStr = line.substr(sep + 1);

		double rate = std::atof(rateStr.c_str());
		_rates[date] = rate;
	}
}

bool BitcoinExchange::isValidDate(const std::string& date) {
	if (date.size() != 10)
		return false;
	if (date[4] != '-' || date[7] != '-')
		return false;

	for (std::size_t i = 0; i < date.size(); ++i) {
		if (i == 4 || i == 7)
			continue;
		if (date[i] < '0' || date[i] > '9')
			return false;
	}

	int year, month, day;
	std::istringstream ys(date.substr(0, 4));
	std::istringstream ms(date.substr(5, 2));
	std::istringstream ds(date.substr(8, 2));
	if (!(ys >> year) || !(ms >> month) || !(ds >> day))
		return false;
	if (month < 1 || month > 12)
		return false;
	if (day < 1 || day > 31)
		return false;
	return true;
}

bool BitcoinExchange::isValidValue(const std::string& valueStr, double& value) {
	std::istringstream ss(valueStr);
	if (!(ss >> value)) {
		std::cerr << "Error: bad input => " << valueStr << std::endl;
		return false;
	}
	char c;
	if (ss >> c) {
		std::cerr << "Error: bad input => " << valueStr << std::endl;
		return false;
	}
	if (value < 0) {
		std::cerr << "Error: not a positive number." << std::endl;
		return false;
	}
	if (value > 1000) {
		std::cerr << "Error: too large a number." << std::endl;
		return false;
	}
	return true;
}


