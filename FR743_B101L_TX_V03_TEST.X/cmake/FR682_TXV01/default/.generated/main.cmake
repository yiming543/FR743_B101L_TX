# cmake files support debug production
include("${CMAKE_CURRENT_LIST_DIR}/rule.cmake")
include("${CMAKE_CURRENT_LIST_DIR}/file.cmake")

set(FR682_TXV01_default_library_list )

# Handle files with suffix (s|as|asm|AS|ASM|As|aS|Asm), for group default-XC8
if(FR682_TXV01_default_default_XC8_FILE_TYPE_assemble)
add_library(FR682_TXV01_default_default_XC8_assemble OBJECT ${FR682_TXV01_default_default_XC8_FILE_TYPE_assemble})
    FR682_TXV01_default_default_XC8_assemble_rule(FR682_TXV01_default_default_XC8_assemble)
    list(APPEND FR682_TXV01_default_library_list "$<TARGET_OBJECTS:FR682_TXV01_default_default_XC8_assemble>")
endif()

# Handle files with suffix S, for group default-XC8
if(FR682_TXV01_default_default_XC8_FILE_TYPE_assemblePreprocess)
add_library(FR682_TXV01_default_default_XC8_assemblePreprocess OBJECT ${FR682_TXV01_default_default_XC8_FILE_TYPE_assemblePreprocess})
    FR682_TXV01_default_default_XC8_assemblePreprocess_rule(FR682_TXV01_default_default_XC8_assemblePreprocess)
    list(APPEND FR682_TXV01_default_library_list "$<TARGET_OBJECTS:FR682_TXV01_default_default_XC8_assemblePreprocess>")
endif()

# Handle files with suffix [cC], for group default-XC8
if(FR682_TXV01_default_default_XC8_FILE_TYPE_compile)
add_library(FR682_TXV01_default_default_XC8_compile OBJECT ${FR682_TXV01_default_default_XC8_FILE_TYPE_compile})
    FR682_TXV01_default_default_XC8_compile_rule(FR682_TXV01_default_default_XC8_compile)
    list(APPEND FR682_TXV01_default_library_list "$<TARGET_OBJECTS:FR682_TXV01_default_default_XC8_compile>")
endif()

add_executable(FR682_TXV01_default_image_iNKkEzIG ${FR682_TXV01_default_library_list})

set_target_properties(FR682_TXV01_default_image_iNKkEzIG PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${FR682_TXV01_default_output_dir})
set_target_properties(FR682_TXV01_default_image_iNKkEzIG PROPERTIES OUTPUT_NAME "default")
set_target_properties(FR682_TXV01_default_image_iNKkEzIG PROPERTIES SUFFIX ".elf")

target_link_libraries(FR682_TXV01_default_image_iNKkEzIG PRIVATE ${FR682_TXV01_default_default_XC8_FILE_TYPE_link})


# Add the link options from the rule file.
FR682_TXV01_default_link_rule(FR682_TXV01_default_image_iNKkEzIG)



