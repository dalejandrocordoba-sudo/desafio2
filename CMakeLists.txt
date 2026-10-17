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
    album.h
    album.cpp
    mensaje.h
    mensaje.cpp
    listafotos.h
    listafotos.cpp
    listausuarios.h
    listausuarios.cpp
    usuario.h
    usuario.cpp
    listaenteros.h
    listaenteros.cpp
    mensaje.h
    mensaje.cpp)

include(GNUInstallDirs)
install(TARGETS desafio2
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
