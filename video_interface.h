#ifndef __TC_VIDEO_STORE_VIDEO_INTERFACE__
#define __TC_VIDEO_STORE_VIDEO_INTERFACE__

#include "lib.h"
#include "video_collection.h"
#include "client_collection.h"

enum class video_interface_state_t
{
	MENU,
	CREATE,
	LIST,
	LIST_AVALIABLE,
	LIST_RENTED,
	UPDATE,
	DELETE,
	RENT,
	RETURN,
};

#define	VIDEO_INTERFACE_MENU_STATE video_interface_state_t::MENU
#define VIDEO_INTERFACE_CREATE_STATE video_interface_state_t::CREATE
#define VIDEO_INTERFACE_LIST_STATE video_interface_state_t::LIST
#define VIDEO_INTERFACE_LIST_AVALIABLE_STATE video_interface_state_t::LIST_AVALIABLE
#define VIDEO_INTERFACE_LIST_RENTED_STATE video_interface_state_t::LIST_RENTED
#define VIDEO_INTERFACE_UPDATE_STATE video_interface_state_t::UPDATE
#define VIDEO_INTERFACE_DELETE_STATE video_interface_state_t::DELETE
#define VIDEO_INTERFACE_RENT_STATE video_interface_state_t::RENT
#define VIDEO_INTERFACE_RETURN_STATE video_interface_state_t::RETURN

#define PRINT_VIDEO_INTERFACE_MENU \
	PRINTLN(" COLLECTION MANAGEMENT"); \
	PRINT("\n"); \
	PRINTLN(" 1. List all"); \
	PRINTLN(" 2. List avaliable only"); \
	PRINTLN(" 3. List rented only"); \
	PRINTLN(" 4. Create"); \
	PRINTLN(" 5. Update"); \
	PRINTLN(" 6. Delete"); \
	PRINTLN(" 7. Rent"); \
	PRINTLN(" 8. Return"); \
	PRINTLN(" 9. Go back");

inline video_t* get_video_by_id (video_collection_t& video_collection)
{
	unsigned int id;
	PRINT("\n Video ID: ");
	GET_INPUT(id);
	video_t* video = video_collection.get_video_by_id(id);

	if (video == nullptr) {
		CLEAR_CONSOLE;
		PRINTLN(" Video not found!\n");
		return nullptr;
	} 

	PRINTLN("\n " + video->get_name());
	PRINTLN(" $" + std::to_string(video->get_price()));
	PRINTLN(" " + video->get_director());
	PRINTLN(" " + video->get_cast());
	PRINTLN(" " + video->get_duration());
	PRINTLN(" " + video->get_category());

	return video;
}

namespace video_interface
{
	void create (video_collection_t& video_collection);
	void update (video_collection_t& video_collection);
	void remove (video_collection_t& video_collection);
	void list (video_collection_t& video_collection);
	void list_avaliable (video_collection_t& video_collection);
	void list_rented (video_collection_t& video_collection);
	void rent (video_collection_t& video_collection, client_collection_t& client_collection);
	void return_video (video_collection_t& video_collection);
}

#endif
