#ifndef __TC_VIDEO_STORE_VIDEO__
#define __TC_VIDEO_STORE_VIDEO__

#include "lib.h"
#include "client.h"

uint16_t generate_video_id ();

class video_t
{
	OO_ENCAPSULATE_RO(uint16_t, id);
	OO_ENCAPSULATE(std::string, name);
	OO_ENCAPSULATE(double, price);
	OO_ENCAPSULATE(std::string, director);
	OO_ENCAPSULATE(std::string, cast);
	OO_ENCAPSULATE(std::string, duration);
	OO_ENCAPSULATE(std::string, category);
	OO_ENCAPSULATE(client_t*, client);

	public:
		inline video_t (
			std::string name, 
			double price,
			std::string director = "", 
			std::string cast = "", 
			std::string duration = "", 
			std::string category = ""
		)
		{
			this->id = generate_video_id();
			this->name = name;
			this->director = director;
			this->cast = cast;
			this->duration = duration;
			this->category = category;
			this->price = price;
			this->client = nullptr;
		}
		
	public:
		std::string to_string ();
		
		inline bool is_avaliable()
		{
			return this->client == nullptr;
		}
};

#endif
