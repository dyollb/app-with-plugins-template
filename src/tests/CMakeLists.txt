add_test(NAME test_app COMMAND myapp)

if(MSVC)
    set_property(TEST test_app PROPERTY
        ENVIRONMENT "PATH=${BOOST_LIBRARYDIR}")
endif()
