#include <string>
#include <inttypes.h>


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

class client_t
{
	public:
		inline client_t (std::string name, std::string email, std::string phoneNumber)
		{
			this->name = name;
			this->email = email;
			this->phone_number = phone_number;
		}
		
		inline std::string toString ()
		{
			return std::to_string(this->id) + " - " + this->name;
		}
		
	GETTER_SETTER_ENCAP(uint64_t, id);
	GETTER_SETTER_ENCAP(std::string, name);
	GETTER_SETTER_ENCAP(std::string, email);
	GETTER_SETTER_ENCAP(std::string, phone_number);
};

