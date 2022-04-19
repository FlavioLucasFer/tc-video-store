#include "collection.h"

video_t collection_t::find_video_by_id (uint16_t id)
{
	std::list<video_t>::iterator it = this->videos.begin();
	
	for (unsigned int i = 0; i < this->videos.size(); i++) {
		video_t video = *it;
		
		if (video.get_id() == id)
			return video;
		
		it++;
	}
	
	throw "not found";
}

void collection_t::add_video (video_t video)
{
	this->videos.push_back(video);
}

void collection_t::remove_video (uint16_t id)
{
	this->videos.remove_if([id] (video_t& video) {
		return video.get_id() == id;
	});
}



