set(PROJ_SRC
    main.cpp
    logger.cpp
    meta.cpp
)

find_package (Threads)

add_executable(logger ${PROJ_SRC})

target_link_libraries(logger ${CMAKE_THREAD_LIBS_INIT})
