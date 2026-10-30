
# Consider dependencies only in project.
set(CMAKE_DEPENDS_IN_PROJECT_ONLY OFF)

# The set of languages for which implicit dependencies are needed:
set(CMAKE_DEPENDS_LANGUAGES
  "ASM"
  )
# The set of files for implicit dependencies of each language:
set(CMAKE_DEPENDS_CHECK_ASM
  "/home/vuk/Documents/BTP/alex test/pwm_sync/esc/devices/lpc1768/startup.S" "/home/vuk/Documents/BTP/alex test/pwm_sync/esc/build/CMakeFiles/program.elf.dir/devices/lpc1768/startup.S.obj"
  )
set(CMAKE_ASM_COMPILER_ID "GNU")

# Preprocessor definitions for this target.
set(CMAKE_TARGET_DEFINITIONS_ASM
  "LFS_DEFINES=lfs_defines.h"
  )

# The include file search paths:
set(CMAKE_ASM_TARGET_INCLUDE_PATH
  "../config"
  "../src/app"
  "../src/middleware/mav"
  "../src/drivers/bms/."
  "../src/middleware/FreeRTOS/include"
  "../src/middleware/FreeRTOS/portable/GCC/ARM_CM3"
  "../src/drivers/motor/."
  "../src/drivers/sd/."
  "../src/drivers/ad7705/."
  "../src/libs/ring/."
  "../src/libs/sbus/."
  "../src/libs/stat/."
  "mavlink"
  "mavlink/lisum"
  "../src/middleware/mav/."
  "../src/middleware/tl/."
  "../src/middleware/tl/uart_tl/."
  "../src/middleware/tl/udp_tl/."
  "../src/middleware/udp/."
  "../src/middleware/lfs/."
  "../src/middleware/lfs/./littlefs"
  "../devices/lpc1768/HAL"
  "../devices/lpc1768/core"
  "../devices/lpc1768/drivers"
  "../src/drivers/ak09915c/."
  "../src/drivers/anpp/."
  "../src/drivers/epos/."
  "../src/libs/canopen/."
  "../src/drivers/kde"
  "../src/drivers/icm42688p/."
  "../src/drivers/ms5607/."
  "../src/drivers/ms5611/."
  "../src/drivers/ubx/."
  "../src/libs/Fusion/./Fusion/Fusion"
  "../src/libs/xbus/."
  "ulog"
  "../src/middleware/ulog/."
  )

# The set of dependency files which are needed:
set(CMAKE_DEPENDS_DEPENDENCY_FILES
  "/home/vuk/Documents/BTP/alex test/pwm_sync/esc/src/app/main.c" "CMakeFiles/program.elf.dir/src/app/main.c.obj" "gcc" "CMakeFiles/program.elf.dir/src/app/main.c.obj.d"
  "/home/vuk/Documents/BTP/alex test/pwm_sync/esc/src/app/task_bridge.c" "CMakeFiles/program.elf.dir/src/app/task_bridge.c.obj" "gcc" "CMakeFiles/program.elf.dir/src/app/task_bridge.c.obj.d"
  "/home/vuk/Documents/BTP/alex test/pwm_sync/esc/src/app/task_mav.c" "CMakeFiles/program.elf.dir/src/app/task_mav.c.obj" "gcc" "CMakeFiles/program.elf.dir/src/app/task_mav.c.obj.d"
  "/home/vuk/Documents/BTP/alex test/pwm_sync/esc/src/app/task_work.c" "CMakeFiles/program.elf.dir/src/app/task_work.c.obj" "gcc" "CMakeFiles/program.elf.dir/src/app/task_work.c.obj.d"
  "/home/vuk/Documents/BTP/alex test/pwm_sync/esc/src/middleware/lfs/littlefs/lfs.c" "CMakeFiles/program.elf.dir/src/middleware/lfs/littlefs/lfs.c.obj" "gcc" "CMakeFiles/program.elf.dir/src/middleware/lfs/littlefs/lfs.c.obj.d"
  "/home/vuk/Documents/BTP/alex test/pwm_sync/esc/src/middleware/lfs/littlefs/lfs_util.c" "CMakeFiles/program.elf.dir/src/middleware/lfs/littlefs/lfs_util.c.obj" "gcc" "CMakeFiles/program.elf.dir/src/middleware/lfs/littlefs/lfs_util.c.obj.d"
  )

# Targets to which this target links.
set(CMAKE_TARGET_LINKED_INFO_FILES
  "/home/vuk/Documents/BTP/alex test/pwm_sync/esc/build/devices/lpc1768/CMakeFiles/lpc1768.dir/DependInfo.cmake"
  "/home/vuk/Documents/BTP/alex test/pwm_sync/esc/build/src/drivers/ak09915c/CMakeFiles/ak09915c.dir/DependInfo.cmake"
  "/home/vuk/Documents/BTP/alex test/pwm_sync/esc/build/src/drivers/anpp/CMakeFiles/anpp.dir/DependInfo.cmake"
  "/home/vuk/Documents/BTP/alex test/pwm_sync/esc/build/src/drivers/bms/CMakeFiles/bms.dir/DependInfo.cmake"
  "/home/vuk/Documents/BTP/alex test/pwm_sync/esc/build/src/drivers/epos/CMakeFiles/epos.dir/DependInfo.cmake"
  "/home/vuk/Documents/BTP/alex test/pwm_sync/esc/build/src/drivers/kde/CMakeFiles/kde.dir/DependInfo.cmake"
  "/home/vuk/Documents/BTP/alex test/pwm_sync/esc/build/src/drivers/icm42688p/CMakeFiles/icm42688p.dir/DependInfo.cmake"
  "/home/vuk/Documents/BTP/alex test/pwm_sync/esc/build/src/drivers/motor/CMakeFiles/motor.dir/DependInfo.cmake"
  "/home/vuk/Documents/BTP/alex test/pwm_sync/esc/build/src/drivers/ms5607/CMakeFiles/ms5607.dir/DependInfo.cmake"
  "/home/vuk/Documents/BTP/alex test/pwm_sync/esc/build/src/drivers/ms5611/CMakeFiles/ms5611.dir/DependInfo.cmake"
  "/home/vuk/Documents/BTP/alex test/pwm_sync/esc/build/src/drivers/sd/CMakeFiles/sd.dir/DependInfo.cmake"
  "/home/vuk/Documents/BTP/alex test/pwm_sync/esc/build/src/drivers/ubx/CMakeFiles/ubx.dir/DependInfo.cmake"
  "/home/vuk/Documents/BTP/alex test/pwm_sync/esc/build/src/drivers/ad7705/CMakeFiles/ad7705.dir/DependInfo.cmake"
  "/home/vuk/Documents/BTP/alex test/pwm_sync/esc/build/src/libs/canopen/CMakeFiles/canopen.dir/DependInfo.cmake"
  "/home/vuk/Documents/BTP/alex test/pwm_sync/esc/build/src/libs/Fusion/CMakeFiles/Fusion.dir/DependInfo.cmake"
  "/home/vuk/Documents/BTP/alex test/pwm_sync/esc/build/src/libs/ring/CMakeFiles/ring.dir/DependInfo.cmake"
  "/home/vuk/Documents/BTP/alex test/pwm_sync/esc/build/src/libs/sbus/CMakeFiles/sbus.dir/DependInfo.cmake"
  "/home/vuk/Documents/BTP/alex test/pwm_sync/esc/build/src/libs/stat/CMakeFiles/stat.dir/DependInfo.cmake"
  "/home/vuk/Documents/BTP/alex test/pwm_sync/esc/build/src/libs/xbus/CMakeFiles/xbus.dir/DependInfo.cmake"
  "/home/vuk/Documents/BTP/alex test/pwm_sync/esc/build/src/middleware/FreeRTOS/CMakeFiles/freertos_kernel.dir/DependInfo.cmake"
  "/home/vuk/Documents/BTP/alex test/pwm_sync/esc/build/src/middleware/mav/CMakeFiles/mav.dir/DependInfo.cmake"
  "/home/vuk/Documents/BTP/alex test/pwm_sync/esc/build/src/middleware/tl/CMakeFiles/tl.dir/DependInfo.cmake"
  "/home/vuk/Documents/BTP/alex test/pwm_sync/esc/build/src/middleware/tl/uart_tl/CMakeFiles/uart_tl.dir/DependInfo.cmake"
  "/home/vuk/Documents/BTP/alex test/pwm_sync/esc/build/src/middleware/tl/udp_tl/CMakeFiles/udp_tl.dir/DependInfo.cmake"
  "/home/vuk/Documents/BTP/alex test/pwm_sync/esc/build/src/middleware/lfs/CMakeFiles/lfs.dir/DependInfo.cmake"
  "/home/vuk/Documents/BTP/alex test/pwm_sync/esc/build/src/middleware/udp/CMakeFiles/udp.dir/DependInfo.cmake"
  "/home/vuk/Documents/BTP/alex test/pwm_sync/esc/build/src/middleware/ulog/CMakeFiles/ulog.dir/DependInfo.cmake"
  "/home/vuk/Documents/BTP/alex test/pwm_sync/esc/build/src/middleware/FreeRTOS/portable/CMakeFiles/freertos_kernel_port.dir/DependInfo.cmake"
  )

# Fortran module output directory.
set(CMAKE_Fortran_TARGET_MODULE_DIR "")
