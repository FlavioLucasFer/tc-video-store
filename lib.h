#include <string>
#include <iostream>
#include <inttypes.h>

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
