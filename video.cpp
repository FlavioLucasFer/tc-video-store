#include "video.h"

uint16_t generate_video_id ()
{
	static uint16_t id = 1;
	return id++;
}

std::string video_t::to_string ()
{
	return std::to_string(this->id) + " - " + this->name + " / $" + std::to_string(this->price);
}

