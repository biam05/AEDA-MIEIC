cmake_minimum_required(VERSION 3.10)
project(aeda1920_fp02_sol)

set(CMAKE_CXX_STANDARD 11)

#add_subdirectory(lib/googletest-master)
#include_directories(lib/googletest-master/googletest/include)
#include_directories(lib/googletest-master/googlemock/include)


add_executable(aeda1920_fp02_sol Tests/main.cpp Tests/tests.cpp Tests/Condomino.cpp Tests/Habitacao.cpp Tests/Servico.cpp Tests/Servico.h Tests/Condominio.cpp Tests/Condominio.h Tests/PrestadorServicoLimpeza.cpp Tests/PrestadorServicoLimpeza.h Tests/CondomiX.cpp Tests/CondomiX.h Tests/PedidoPrestacaoServico.cpp Tests/PedidoPrestacaoServico.h Tests/utils.cpp Tests/utils.h Tests/Excecoes.h)

#target_link_libraries(aeda1920_fp02_sol gtest gtest_main)

# Doxygen Build
find_package(Doxygen)
if(DOXYGEN_FOUND)
    set(BUILD_DOC_DIR "${CMAKE_SOURCE_DIR}/docs/output")
    if(NOT EXISTS "${BUILD_DOC_DIR}")
        file(MAKE_DIRECTORY "${BUILD_DOC_DIR}")
    endif()

    set(DOXYGEN_IN "${CMAKE_CURRENT_SOURCE_DIR}/docs/Doxyfile")
    set(DOXYGEN_OUT "${CMAKE_CURRENT_BINARY_DIR}/Doxyfile")
    configure_file("${DOXYGEN_IN}" "${DOXYGEN_OUT}" @ONLY)

    message("Doxygen build started")
    add_custom_target(Doxygen ALL
            COMMAND "${DOXYGEN_EXECUTABLE}" "${DOXYGEN_OUT}"
            WORKING_DIRECTORY "${CMAKE_CURRENT_BINARY_DIR}"
            COMMENT "Generating API documentation with Doxygen"
            VERBATIM)
else(DOXYGEN_FOUND)
    message("Doxygen needs to be installed to generate the documentation.")
endif(DOXYGEN_FOUND)