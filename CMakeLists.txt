cmake_minimum_required(VERSION 3.16)

project(desafio2 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(desafio2 main.cpp
    redsocial.h
    redsocial.cpp
    monitorderecursos.h
    monitorderecursos.cpp
    foto.h
    foto.cpp
<<<<<<< HEAD
    album.h
    album.cpp)
=======
    foto.cpp)
>>>>>>> 7da305b02ca2c379b786eb54d4df1488ebe9084b

include(GNUInstallDirs)
install(TARGETS desafio2
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
