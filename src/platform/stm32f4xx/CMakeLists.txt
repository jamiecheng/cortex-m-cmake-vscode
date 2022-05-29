set(INCLUDE_DIRS ${INCLUDE_DIRS} 
${CMAKE_CURRENT_LIST_DIR} 
${CMAKE_CURRENT_LIST_DIR}/stm32f4xx_hal_driver/Inc 
${CMAKE_CURRENT_LIST_DIR}/CMSIS/Device/ST/STM32F4xx/Include 
${CMAKE_CURRENT_LIST_DIR}/CMSIS/Include)

# add src of platform and hal seperately just for readability
set(SRC_FILES ${SRC_FILES} 
${CMAKE_CURRENT_LIST_DIR}/startup_stm32f446xx.s 
${CMAKE_CURRENT_LIST_DIR}/system_stm32f4xx.c 
${CMAKE_CURRENT_LIST_DIR}/stm32f4xx_hal_driver/Src/stm32f4xx_hal.c
${CMAKE_CURRENT_LIST_DIR}/stm32f4xx_hal_driver/Src/stm32f4xx_hal_cortex.c)

# the hal lib
set(SRC_FILES ${SRC_FILES} 
${CMAKE_CURRENT_LIST_DIR}/system.c)
