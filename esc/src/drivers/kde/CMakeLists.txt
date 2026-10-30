cmake_minimum_required(VERSION 3.20)

project(kde)

set(SOURCES
    ./kde.c
    ./kde_helper.c
)

add_library(${PROJECT_NAME}
    STATIC
    ${SOURCES}
)

set(DEVICE_LPC1768
    ${LSM_SOURCE_DIR}/devices/lpc1768/HAL
    ${LSM_SOURCE_DIR}/devices/lpc1768/core
)

target_include_directories(${PROJECT_NAME} SYSTEM PUBLIC
    ${LSM_SOURCE_DIR}/src/drivers/kde
    ${LSM_SOURCE_DIR}/devices/lpc1768/HAL
    ${LSM_SOURCE_DIR}/devices/lpc1768/core
)

# local_delay_ms() sleeps via vTaskDelay once the scheduler is running
target_link_libraries(${PROJECT_NAME}
    freertos_kernel
)
