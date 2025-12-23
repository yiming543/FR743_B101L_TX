# cmake files support debug production
include("${CMAKE_CURRENT_LIST_DIR}/rule.cmake")
include("${CMAKE_CURRENT_LIST_DIR}/file.cmake")

set(FR743_B101L_TX_V04_TEST_default_library_list )

# Handle files with suffix (s|as|asm|AS|ASM|As|aS|Asm), for group default-XC8
if(FR743_B101L_TX_V04_TEST_default_default_XC8_FILE_TYPE_assemble)
add_library(FR743_B101L_TX_V04_TEST_default_default_XC8_assemble OBJECT ${FR743_B101L_TX_V04_TEST_default_default_XC8_FILE_TYPE_assemble})
    FR743_B101L_TX_V04_TEST_default_default_XC8_assemble_rule(FR743_B101L_TX_V04_TEST_default_default_XC8_assemble)
    list(APPEND FR743_B101L_TX_V04_TEST_default_library_list "$<TARGET_OBJECTS:FR743_B101L_TX_V04_TEST_default_default_XC8_assemble>")

endif()

# Handle files with suffix S, for group default-XC8
if(FR743_B101L_TX_V04_TEST_default_default_XC8_FILE_TYPE_assemblePreprocess)
add_library(FR743_B101L_TX_V04_TEST_default_default_XC8_assemblePreprocess OBJECT ${FR743_B101L_TX_V04_TEST_default_default_XC8_FILE_TYPE_assemblePreprocess})
    FR743_B101L_TX_V04_TEST_default_default_XC8_assemblePreprocess_rule(FR743_B101L_TX_V04_TEST_default_default_XC8_assemblePreprocess)
    list(APPEND FR743_B101L_TX_V04_TEST_default_library_list "$<TARGET_OBJECTS:FR743_B101L_TX_V04_TEST_default_default_XC8_assemblePreprocess>")

endif()

# Handle files with suffix [cC], for group default-XC8
if(FR743_B101L_TX_V04_TEST_default_default_XC8_FILE_TYPE_compile)
add_library(FR743_B101L_TX_V04_TEST_default_default_XC8_compile OBJECT ${FR743_B101L_TX_V04_TEST_default_default_XC8_FILE_TYPE_compile})
    FR743_B101L_TX_V04_TEST_default_default_XC8_compile_rule(FR743_B101L_TX_V04_TEST_default_default_XC8_compile)
    list(APPEND FR743_B101L_TX_V04_TEST_default_library_list "$<TARGET_OBJECTS:FR743_B101L_TX_V04_TEST_default_default_XC8_compile>")

endif()


# Main target for this project
add_executable(FR743_B101L_TX_V04_TEST_default_image_FguEUHyy ${FR743_B101L_TX_V04_TEST_default_library_list})

set_target_properties(FR743_B101L_TX_V04_TEST_default_image_FguEUHyy PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${FR743_B101L_TX_V04_TEST_default_output_dir})
set_target_properties(FR743_B101L_TX_V04_TEST_default_image_FguEUHyy PROPERTIES OUTPUT_NAME "default")
set_target_properties(FR743_B101L_TX_V04_TEST_default_image_FguEUHyy PROPERTIES SUFFIX ".elf")

target_link_libraries(FR743_B101L_TX_V04_TEST_default_image_FguEUHyy PRIVATE ${FR743_B101L_TX_V04_TEST_default_default_XC8_FILE_TYPE_link})


# Add the link options from the rule file.
FR743_B101L_TX_V04_TEST_default_link_rule(FR743_B101L_TX_V04_TEST_default_image_FguEUHyy)



