CC = g++

main:
	$(CC) -o VideoStore main.cpp client.cpp video.cpp client_collection.cpp video_collection.cpp
