set(INCLUDE_DIRS ${INCLUDE_DIRS} ${CMAKE_CURRENT_LIST_DIR}/include)

# Platform periheral selector
if(${PLATFORM} STREQUAL stm32f4xx)
    include(${CMAKE_CURRENT_LIST_DIR}/stm32f4xx/CMakeLists.txt)
endif()