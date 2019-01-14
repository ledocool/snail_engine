set(prefix "${CMAKE_CURRENT_LIST_DIR}") 
SET(searchat "${prefix}"
                            "${prefix}/include")

FIND_PATH(GLM_INCLUDE_DIRS "glm/glm.hpp"
    PATHS ${searchat})


