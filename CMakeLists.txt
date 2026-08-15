cmake_minimum_required(VERSION 3.10)
project(JogoSFML)

# 1. Avisa o CMake para procurar os cabeçalhos (.hpp) dentro da pasta include
include_directories(include)

# 2. Encontra a SFML no sistema
find_package(SFML 2.6 COMPONENTS graphics window system REQUIRED)

# 3. Cria o executável apontando para os arquivos dentro da pasta src/
file(GLOB SOURCES "src/*.cpp")
add_executable(jogo ${SOURCES})


# 4. Linka as bibliotecas da SFML
target_link_libraries(jogo sfml-graphics sfml-window sfml-system)

# 5. COPIA SEGURA: Copia a pasta assets inteira para dentro da build
file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/assets DESTINATION ${CMAKE_CURRENT_BINARY_DIR})
