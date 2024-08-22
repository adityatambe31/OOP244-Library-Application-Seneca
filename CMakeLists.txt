cmake_minimum_required(VERSION 3.28)
project(SenecaLibraryApplication)

set(CMAKE_CXX_STANDARD 11)

add_executable(SenecaLibraryApplication
        Book.cpp
        Book.h
        Date.cpp
        Date.h
        Lib.h
        LibApp.cpp
        LibApp.h
        LibAppMain.cpp
        Menu.cpp
        Menu.h
        Publication.cpp
        Publication.h
        PublicationSelector.cpp
        PublicationSelector.h
        Streamable.cpp
        Streamable.h
        Utils.cpp
        Utils.h)