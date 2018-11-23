cmake_minimum_required(VERSION 3.9)
project(db C)

set(CMAKE_C_STANDARD 99)

add_executable(db main.c)

add_custom_target(spec
        COMMAND bundle exec rspec)