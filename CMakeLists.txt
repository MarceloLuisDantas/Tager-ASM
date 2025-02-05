cmake_minimum_required(VERSION 3.22.1)
project("TAGER")
add_compile_options(-Wall -Werror)

# Define o diretório das bibliotecas
set(LIBRARY_DIR "${CMAKE_SOURCE_DIR}/libs")
include_directories(${LIBRARY_DIR})

# Test executable
add_executable(
    TagerTest
    test/test.c
    src/Tager.c
)

# Especifica o diretório onde as bibliotecas compartilhadas estão localizadas
target_link_directories(TagerTest PRIVATE ${LIBRARY_DIR})

# Linka as bibliotecas ao executável
target_link_libraries(TagerTest PRIVATE Strings LinkedList Files)