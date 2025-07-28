#ifndef LOSER_HPP
#define LOSER_HPP

#include <string>
#include <iostream>
#include <fstream>

class Harl
{
	private:
		void debug( void );
		void info( void );
		void warning( void );
		void error( void );
	public:
		void complain( std::string level );
};

#endif
