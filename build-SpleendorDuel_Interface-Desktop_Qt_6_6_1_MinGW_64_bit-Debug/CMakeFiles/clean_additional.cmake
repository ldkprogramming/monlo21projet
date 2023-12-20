# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\SpleendorDuel_Interface_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\SpleendorDuel_Interface_autogen.dir\\ParseCache.txt"
  "SpleendorDuel_Interface_autogen"
  )
endif()
