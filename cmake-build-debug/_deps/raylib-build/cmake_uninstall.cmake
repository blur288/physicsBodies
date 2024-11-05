if(NOT EXISTS "/Users/colemusolf/CLionProjects/RaylibTest/cmake-build-debug/install_manifest.txt")
  message(FATAL_ERROR "Cannot find install manifest: /Users/colemusolf/CLionProjects/RaylibTest/cmake-build-debug/install_manifest.txt")
endif()

file(READ "/Users/colemusolf/CLionProjects/RaylibTest/cmake-build-debug/install_manifest.txt" files)
string(REGEX REPLACE "\n" ";" files "${files}")
foreach(file ${files})
  message(STATUS "Uninstalling $ENV{DESTDIR}${file}")
  if(IS_SYMLINK "$ENV{DESTDIR}${file}" OR EXISTS "$ENV{DESTDIR}${file}")
    exec_program(
      "/private/var/folders/_5/329894x528b81rwhyjbrl7dc0000gn/T/AppTranslocation/9318FFEA-F4A5-4378-A1D3-A3EF2E4926D3/d/CLion.app/Contents/bin/cmake/mac/aarch64/bin/cmake" ARGS "-E remove \"$ENV{DESTDIR}${file}\""
      OUTPUT_VARIABLE rm_out
      RETURN_VALUE rm_retval
      )
    if(NOT "${rm_retval}" STREQUAL 0)
      message(FATAL_ERROR "Problem when removing $ENV{DESTDIR}${file}")
    endif()
  else(IS_SYMLINK "$ENV{DESTDIR}${file}" OR EXISTS "$ENV{DESTDIR}${file}")
    message(STATUS "File $ENV{DESTDIR}${file} does not exist.")
  endif()
endforeach()
