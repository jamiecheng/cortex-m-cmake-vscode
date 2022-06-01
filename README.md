# Cortex-M CMake
 When developing general purpose embedded systems it can be quite overwheling to use different IDEs for different vendor mcu's. They are often slow, not modern, and bloated with unneccesary tools. This 'template' aims to provide a minimalistic portable framework for Cortex-M microcontrollers. It uses CMAKE and the ARM toolchain and does not depend on external tools. It is up to the developer what editor and debugger to use.

 ## Requirements
 - ARM GNU Toolchain
 - CMAKE

 ### Optional
 - VSCode, with the following extenstions:
    - C/C++
    - CMake Tools
    - Cortex-Debug

 ## Current platforms in development
 - STM32f4xx
