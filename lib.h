#ifndef __LIB__
#define __LIB__

#include <string>
#include <iostream>
#include <inttypes.h>
#include <ncurses.h>

#define PRINT(STR) std::cout << STR
#define PRINTLN(STR) std::cout << STR << std::endl

#define GET_INPUT(VAR) std::cin >> VAR
#define WAIT_KEY_TO_CONTINUE \
	initscr(); \
	addstr("\n PRESS ANY BUTTON TO CONTINUE..."); \
	cbreak(); \
	getch(); \
	endwin();

#define CLEAR_CONSOLE system("clear");

#define GETTER_SETTER_ENCAP_REF(TYPE, VAR) \
	private: \
		TYPE VAR; \
	\
	public: \
		inline TYPE& get_##VAR () \
		{ \
			return this->VAR; \
		} \
		\
		inline void set_##VAR (TYPE& VAR) \
		{ \
			this->VAR = VAR; \
		} 

#define GETTER_SETTER_ENCAP(TYPE, VAR) \
	private: \
		TYPE VAR; \
	\
	public: \
		inline TYPE get_##VAR () \
		{ \
			return this->VAR; \
		} \
		\
		inline void set_##VAR (TYPE VAR) \
		{ \
			this->VAR = VAR; \
		} 
		
#define GETTER_ENCAP(TYPE, VAR) \
	private: \
		TYPE VAR; \
	\
	public: \
		inline TYPE get_##VAR () \
		{ \
			return this->VAR; \
		} 

#endif
