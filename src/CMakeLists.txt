rock_library(mls_to_text
    SOURCES Dummy.cpp
    HEADERS Dummy.hpp)

rock_executable(mls_to_text_bin Main.cpp
    DEPS mls_to_text)

