# Vendor HAL sources
set(VENDOR_DIR ${CMAKE_CURRENT_LIST_DIR}/vendor)

set(INCLUDE_DIRS ${INCLUDE_DIRS} 
${VENDOR_DIR}/stm32f4xx_hal_driver/Inc 
${VENDOR_DIR}/CMSIS/Device/ST/STM32F4xx/Include 
${VENDOR_DIR}/CMSIS/Include)

set(SRC_FILES ${SRC_FILES} 
${VENDOR_DIR}/stm32f4xx_hal_driver/Src/stm32f4xx_hal.c
${VENDOR_DIR}/stm32f4xx_hal_driver/Src/stm32f4xx_hal_gpio.c
${VENDOR_DIR}/stm32f4xx_hal_driver/Src/stm32f4xx_hal_cortex.c)

# HAL sources
set(INCLUDE_DIRS ${INCLUDE_DIRS} 
${CMAKE_CURRENT_LIST_DIR} )

set(SRC_FILES ${SRC_FILES}
${CMAKE_CURRENT_LIST_DIR}/startup_stm32f446xx.s
${CMAKE_CURRENT_LIST_DIR}/system_stm32f4xx.c 
${CMAKE_CURRENT_LIST_DIR}/system.c
${CMAKE_CURRENT_LIST_DIR}/gpio.c)
