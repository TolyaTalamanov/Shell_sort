file(GLOB app_list relative "${cmake_current_source_dir}" *.cpp)
foreach(app_filename ${app_list})
    get_filename_component(app ${app_filename} NAME_WE)
    add_executable(${app} ${app_filename})
    target_link_libraries(${app} ${LIBRARY})
endforeach()


