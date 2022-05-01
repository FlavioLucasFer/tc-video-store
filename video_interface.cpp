#include "video_interface.h"

namespace video_interface
{
	void create (video_collection_t& video_collection)
	{
		std::string name;
		double price;
		std::string director;
		std::string cast;
		std::string duration;
		std::string category;

		PRINT("\n Name: ");
		GET_INPUT(name);
		PRINT(" Price: ");
		GET_INPUT(price);
		PRINT(" Director: ");
		GET_INPUT(director);		
		PRINT(" Cast: ");
		GET_INPUT(cast);
		PRINT(" Duration: ");
		GET_INPUT(duration);
		PRINT(" Category: ");
		GET_INPUT(category);

		video_collection << video_t(name, price, director, cast, duration, category);
		CLEAR_CONSOLE;
		PRINTLN(" Video successfully created!\n");
	}

	void update (video_collection_t& video_collection)
	{
		video_t* video = get_video_by_id(video_collection);

		if (video == nullptr)
			return;

		std::string name;
		std::string price;
		std::string director;
		std::string cast;
		std::string duration;
		std::string category;

		PRINT("\n New name (TYPE '!k' ENTER TO KEEP CURRENT): ");
		GET_INPUT(name);
		PRINT(" New price (TYPE '!k' TO KEEP CURRENT): ");
		GET_INPUT(price);
		PRINT(" New director (TYPE '!k' TO KEEP CURRENT): ");
		GET_INPUT(director);
		PRINT(" New cast (TYPE '!k' TO KEEP CURRENT): ");
		GET_INPUT(cast);
		PRINT(" New duration (TYPE '!k' TO KEEP CURRENT): ");
		GET_INPUT(duration);
		PRINT(" New category (TYPE '!k' TO KEEP CURRENT): ");
		GET_INPUT(category);

		if (name == "!k")
			name = video->get_name();
		if (price == "!k")
			price = std::to_string(video->get_price());
		if (director == "!k")
			director = video->get_director();
		if (cast == "!k")
			cast = video->get_cast();
		if (duration == "!k")
			duration = video->get_duration();
		if (category == "!k")
			category = video->get_category();

		video_collection.update(video->get_id(), name, std::stod(price.c_str()), director, cast, duration, category);

		CLEAR_CONSOLE;
		PRINTLN(" Video successfully updated!\n");
	}

	void remove (video_collection_t& video_collection)
	{
		video_t* video = get_video_by_id(video_collection);

		if (video == nullptr)
			return;
		
		std::string choice;
		PRINT("\n Are you sure you want to delete this video? Y/n ");
		GET_INPUT(choice);
		CLEAR_CONSOLE;

		if (choice != "Y" && choice != "y") 
			return;

		video_collection.remove(video->get_id());
		PRINTLN(" Video successfully deleted! \n");
	}

	void list (video_collection_t& video_collection)
	{
		CLEAR_CONSOLE;
		PRINTLN("\n Videos:\n");
		video_collection.list();
		PRINT("\n");
	}

	void list_avaliable (video_collection_t& video_collection)
	{
		CLEAR_CONSOLE;
		PRINTLN("\n Avaliable videos:\n");
		video_collection.list_avaliable();
		PRINT("\n");
	}

	void list_rented (video_collection_t& video_collection)
	{
		CLEAR_CONSOLE;
		PRINTLN("\n Rented videos:\n");
		video_collection.list_rented();
		PRINT("\n");
	}

	void rent (video_collection_t& video_collection, client_collection_t& client_collection)
	{
		video_t* video = get_video_by_id(video_collection);

		unsigned int client_id;
		PRINT("\n Client ID: ");
		GET_INPUT(client_id);
		client_t* client = client_collection.get_client_by_id(client_id);

		CLEAR_CONSOLE;
		if (client == nullptr) {
			PRINTLN(" Client not found!\n");
			return;
		} 

		if (!video_collection.rent(video->get_id(), *client)) {
			PRINTLN(" Video not found or already rented!");
			return;
		}

		PRINTLN(" Video successfully rented!"); 
	}

	void return_video (video_collection_t& video_collection)
	{
		video_t* video = get_video_by_id(video_collection);

		CLEAR_CONSOLE;
		if (video_collection.return_video(video->get_id()))
			PRINTLN(" Video successfully returned!");
		else
			PRINTLN(" Video not found or not even rented yet!");
	}
}
