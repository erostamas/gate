link_directories(/usr/lib/erostamas/)

add_library(gate_library STATIC
    Gate.cc
    StringCommandAdapter.cc
)

target_link_libraries(gate_library
    boost_log
    boost_thread
    boost_system
)

add_executable(gate
    main.cc)

target_link_libraries(gate
    gate_library
    et_logging
    et_command_processor
    et_config
    et_udp)

INSTALL(TARGETS gate
	DESTINATION /usr/bin/
	PERMISSIONS OWNER_READ OWNER_EXECUTE GROUP_READ GROUP_EXECUTE WORLD_READ WORLD_EXECUTE
)
