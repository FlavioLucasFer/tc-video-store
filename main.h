#include <iostream>
#include <list>
#include "lib.h"
#include "client.h"
#include "video_collection.h"
#include "video_interface.h"
#include "client_collection.h"
#include "client_interface.h"

#define PRINT_MAIN_MENU \
	PRINTLN(" WELCOME TO VIDEO STORE"); \
	PRINT("\n"); \
	PRINTLN(" 1. Client Management"); \
	PRINTLN(" 2. Collection Management"); \
	PRINTLN(" 3. See billing"); \
	PRINTLN(" 4. Close");

#define INVALID_MENU_OPTION PRINTLN(" Invalid option. Please, type a valid option!")

#define GET_MENU_ENTRY(VAR, MAX_VALUE) \
	do { \
		PRINT("\n Choice: "); \
		GET_INPUT(VAR); \
		if (VAR > 0 && VAR <= MAX_VALUE) { \
			break; \
		} \
		INVALID_MENU_OPTION; \
	} while (true);

enum class state_t
{
	MAIN_MENU,
	CLIENT_MENU,
	VIDEO_MENU,
	SEE_BILLING,
	CLOSE,
	PANIC,
};

#define MAIN_MENU_STATE state_t::MAIN_MENU
#define CLIENT_MENU_STATE state_t::CLIENT_MENU
#define VIDEO_MENU_STATE state_t::VIDEO_MENU
#define SEE_BILLING state_t::SEE_BILLING
#define CLOSE_STATE state_t::CLOSE
#define PANIC_STATE state_t::PANIC
