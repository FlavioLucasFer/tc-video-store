#include <list>
#include <inttypes.h>
#include <iostream>
#include "lib.h"
#include "video.h"

class collection_t
{
	private:
		std::list<video_t> videos;
		
	public:
		video_t find_video_by_id (uint16_t id);
		
	public:
		void add_video (video_t video);
		void remove_video (uint16_t id);
		bool rent_video (uint16_t id);
		bool return_video (uint16_t id);
		void print ();
};

