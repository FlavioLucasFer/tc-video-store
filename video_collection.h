#ifndef __TC_VIDEO_STORE_VIDEO_COLLECTION__
#define __TC_VIDEO_STORE_VIDEO_COLLECTION__

#include <list>
#include <inttypes.h>
#include "lib.h"
#include "video.h"

class video_collection_t
{
	OO_ENCAPSULATE_RO(double, billing);

	private:
		std::list<video_t> videos;
		
	public:
		video_t* get_video_by_id (uint_t id);
		void add (video_t video);
		void remove (uint16_t id);
		void update (uint16_t id, std::string name, double price, std::string director, std::string cast, std::string duration, std::string category);
		bool rent (uint16_t id, client_t& client);
		bool return_video (uint16_t id);
		void list ();
		void list_rented ();
		void list_avaliable ();

	
	void operator << (const video_t video)
	{
		this->add(video);
	}
};

#endif
