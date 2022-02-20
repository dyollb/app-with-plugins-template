macro(install_app exe)

set(APP_NAME ${exe})
set(PLUGIN_NAMES ${ARGN})
set(BUNDLE_DIR "${APP_NAME}")
set(PLUGIN_DIR ${BUNDLE_DIR})
if(APPLE)
    set(PLUGIN_DIR "${BUNDLE_DIR}/${APP_NAME}.app/Contents/Frameworks")
endif()

install(TARGETS ${APP_NAME} ${PLUGIN_NAMES}
    BUNDLE  DESTINATION ${BUNDLE_DIR} COMPONENT Runtime
    LIBRARY DESTINATION ${PLUGIN_DIR} COMPONENT Runtime
)

set(BUNDLE_PLUGINS "")
foreach(plugin ${PLUGIN_NAMES})
    list(APPEND BUNDLE_PLUGINS 
        ${CMAKE_INSTALL_PREFIX}/${PLUGIN_DIR}/${CMAKE_SHARED_LIBRARY_PREFIX}${plugin}${CMAKE_SHARED_LIBRARY_SUFFIX}
    )
endforeach()

set(BUNDLE_LIB_DIRS
    ${CMAKE_LIBRARY_OUTPUT_DIRECTORY}
    ${Boost_LIBRARY_DIRS}
)
configure_file(
    ${CMAKE_CURRENT_SOURCE_DIR}/Bundle.cmake.in
    ${CMAKE_CURRENT_BINARY_DIR}/Bundle.cmake
    @ONLY
)

install(SCRIPT ${CMAKE_CURRENT_BINARY_DIR}/Bundle.cmake)

endmacro()
