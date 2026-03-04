#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <map>
#include <string>

class BitcoinExchange {
public:
	BitcoinExchange(const std::string& dbPath);
	BitcoinExchange(const BitcoinExchange& other);
	BitcoinExchange& operator=(const BitcoinExchange& other);
	~BitcoinExchange();

	void processInputFile(const std::string& inputPath) const;

private:
	std::map<std::string, double> _rates;

	void loadDatabase(const std::string& dbPath);
	static bool isValidDate(const std::string& date);
	static bool isValidValue(const std::string& valueStr, double& value);
};

#endif

