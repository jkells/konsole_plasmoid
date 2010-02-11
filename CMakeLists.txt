project(plasma-konsole)

find_package(KDE4 REQUIRED)
include (KDE4Defaults)

add_definitions (
	${QT_DEFINITIONS} 
	${KDE4_DEFINITIONS}
)

include_directories (
	${CMAKE_SOURCE_DIR} 
	${CMAKE_BINARY_DIR}
	${KDE4_INCLUDES}
)

set(konsole_SRCS
    konsoleapplet.cpp
)

kde4_add_plugin(plasma_applet_konsole ${konsole_SRCS})
target_link_libraries(plasma_applet_konsole ${KDE4_PLASMA_LIBS} ${KDE4_KIO_LIBS} ${KDE4_KPARTS_LIBS}) 

install(TARGETS plasma_applet_konsole DESTINATION ${PLUGIN_INSTALL_DIR})
install(FILES plasma-konsole-default.desktop DESTINATION ${SERVICES_INSTALL_DIR})
