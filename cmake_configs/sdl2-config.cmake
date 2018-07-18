# sdl2 cmake project-config input for ./configure scripts

set(prefix "${CMAKE_CURRENT_LIST_DIR}") 
if(${CMAKE_SIZEOF_VOID_P} MATCHES 8)
    set(SDL2_PATH "${prefix}")
else()
    set(SDL2_PATH "${prefix}")
endif()
set(SDL2_INCLUDE_DIRS "${SDL2_PATH}/include/SDL2")
#set(SDL2_LIBRARIES "${SDL2_PATH}/lib/libSDL2main.a;${SDL2_PATH}/lib/libSDL2.a")
set(SDL2_LIBRARIES "-L${SDL2_PATH}/lib  -lmingw32 -lSDL2main -lSDL2  -mwindows")# "${SDL2_PATH}/lib/libSDL2.a;${SDL2_PATH}/lib/libSDL2main.a")
set(SDL2_BINARIES "${SDL2_PATH}/bin/SDL2.dll")

string(STRIP "${SDL2_LIBRARIES}" SDL2_LIBRARIES)
