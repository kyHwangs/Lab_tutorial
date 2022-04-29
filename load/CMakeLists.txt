project(load)

find_package(ROOT REQUIRED)

include_directories(
  ${CMAKE_CURRENT_SOURCE_DIR}/include
)
file(GLOB sources
  ${PROJECT_SOURCE_DIR}/src/*.cc
)
file(GLOB headers
  ${PROJECT_SOURCE_DIR}/include/*.hh
)

include(${ROOT_USE_FILE})
add_executable(load load.cc ${sources} ${headers})
target_link_libraries(
  load
  ${ROOT_LIBRARIES}
  ${CMAKE_DL_LIBS}
)

set(
  analysis_SCRIPTS
)

foreach(_script ${analysis_SCRIPTS})
  configure_file(
    ${PROJECT_SOURCE_DIR}/${_script}
    ${PROJECT_BINARY_DIR}/${_script}
    COPYONLY
  )
endforeach()

install(TARGETS load DESTINATION bin)
