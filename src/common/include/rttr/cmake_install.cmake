# Install script for directory: C:/Users/User/Desktop/Github/rttr/src/rttr

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "C:/Users/User/Desktop/Github/rttr/install")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "Release")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Is this installation the result of a crosscompile?
if(NOT DEFINED CMAKE_CROSSCOMPILING)
  set(CMAKE_CROSSCOMPILING "FALSE")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/rttr" TYPE FILE PERMISSIONS OWNER_READ FILES "C:/Users/User/Desktop/Github/rttr/src/rttr/access_levels.h")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/rttr" TYPE FILE PERMISSIONS OWNER_READ FILES "C:/Users/User/Desktop/Github/rttr/src/rttr/argument.h")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/rttr" TYPE FILE PERMISSIONS OWNER_READ FILES "C:/Users/User/Desktop/Github/rttr/src/rttr/array_range.h")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/rttr" TYPE FILE PERMISSIONS OWNER_READ FILES "C:/Users/User/Desktop/Github/rttr/src/rttr/associative_mapper.h")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/rttr" TYPE FILE PERMISSIONS OWNER_READ FILES "C:/Users/User/Desktop/Github/rttr/src/rttr/constructor.h")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/rttr" TYPE FILE PERMISSIONS OWNER_READ FILES "C:/Users/User/Desktop/Github/rttr/src/rttr/destructor.h")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/rttr" TYPE FILE PERMISSIONS OWNER_READ FILES "C:/Users/User/Desktop/Github/rttr/src/rttr/enumeration.h")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/rttr" TYPE FILE PERMISSIONS OWNER_READ FILES "C:/Users/User/Desktop/Github/rttr/src/rttr/enum_flags.h")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/rttr" TYPE FILE PERMISSIONS OWNER_READ FILES "C:/Users/User/Desktop/Github/rttr/src/rttr/filter_item.h")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/rttr" TYPE FILE PERMISSIONS OWNER_READ FILES "C:/Users/User/Desktop/Github/rttr/src/rttr/instance.h")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/rttr" TYPE FILE PERMISSIONS OWNER_READ FILES "C:/Users/User/Desktop/Github/rttr/src/rttr/library.h")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/rttr" TYPE FILE PERMISSIONS OWNER_READ FILES "C:/Users/User/Desktop/Github/rttr/src/rttr/method.h")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/rttr" TYPE FILE PERMISSIONS OWNER_READ FILES "C:/Users/User/Desktop/Github/rttr/src/rttr/policy.h")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/rttr" TYPE FILE PERMISSIONS OWNER_READ FILES "C:/Users/User/Desktop/Github/rttr/src/rttr/property.h")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/rttr" TYPE FILE PERMISSIONS OWNER_READ FILES "C:/Users/User/Desktop/Github/rttr/src/rttr/parameter_info.h")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/rttr" TYPE FILE PERMISSIONS OWNER_READ FILES "C:/Users/User/Desktop/Github/rttr/src/rttr/registration")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/rttr" TYPE FILE PERMISSIONS OWNER_READ FILES "C:/Users/User/Desktop/Github/rttr/src/rttr/registration_friend")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/rttr" TYPE FILE PERMISSIONS OWNER_READ FILES "C:/Users/User/Desktop/Github/rttr/src/rttr/registration.h")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/rttr" TYPE FILE PERMISSIONS OWNER_READ FILES "C:/Users/User/Desktop/Github/rttr/src/rttr/registration_friend.h")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/rttr" TYPE FILE PERMISSIONS OWNER_READ FILES "C:/Users/User/Desktop/Github/rttr/src/rttr/sequential_mapper.h")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/rttr" TYPE FILE PERMISSIONS OWNER_READ FILES "C:/Users/User/Desktop/Github/rttr/src/rttr/string_view.h")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/rttr" TYPE FILE PERMISSIONS OWNER_READ FILES "C:/Users/User/Desktop/Github/rttr/src/rttr/rttr_cast.h")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/rttr" TYPE FILE PERMISSIONS OWNER_READ FILES "C:/Users/User/Desktop/Github/rttr/src/rttr/rttr_enable.h")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/rttr" TYPE FILE PERMISSIONS OWNER_READ FILES "C:/Users/User/Desktop/Github/rttr/src/rttr/type")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/rttr" TYPE FILE PERMISSIONS OWNER_READ FILES "C:/Users/User/Desktop/Github/rttr/src/rttr/type.h")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/rttr" TYPE FILE PERMISSIONS OWNER_READ FILES "C:/Users/User/Desktop/Github/rttr/src/rttr/type_list.h")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/rttr" TYPE FILE PERMISSIONS OWNER_READ FILES "C:/Users/User/Desktop/Github/rttr/src/rttr/variant.h")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/rttr" TYPE FILE PERMISSIONS OWNER_READ FILES "C:/Users/User/Desktop/Github/rttr/src/rttr/variant_associative_view.h")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/rttr" TYPE FILE PERMISSIONS OWNER_READ FILES "C:/Users/User/Desktop/Github/rttr/src/rttr/variant_sequential_view.h")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/rttr" TYPE FILE PERMISSIONS OWNER_READ FILES "C:/Users/User/Desktop/Github/rttr/src/rttr/visitor.h")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/rttr" TYPE FILE PERMISSIONS OWNER_READ FILES "C:/Users/User/Desktop/Github/rttr/src/rttr/wrapper_mapper.h")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/rttr/detail/base" TYPE FILE PERMISSIONS OWNER_READ FILES "C:/Users/User/Desktop/Github/rttr/src/rttr/detail/base/core_prerequisites.h")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/rttr/detail/base" TYPE FILE PERMISSIONS OWNER_READ FILES "C:/Users/User/Desktop/Github/rttr/src/rttr/detail/base/version.h")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/rttr/detail/base" TYPE FILE PERMISSIONS OWNER_READ FILES "C:/Users/User/Desktop/Github/rttr/src/rttr/detail/base/version.h")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/rttr/detail/comparison" TYPE FILE PERMISSIONS OWNER_READ FILES "C:/Users/User/Desktop/Github/rttr/src/rttr/detail/comparison/comparable_types.h")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/rttr/detail/comparison" TYPE FILE PERMISSIONS OWNER_READ FILES "C:/Users/User/Desktop/Github/rttr/src/rttr/detail/comparison/compare_array_less.h")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/rttr/detail/comparison" TYPE FILE PERMISSIONS OWNER_READ FILES "C:/Users/User/Desktop/Github/rttr/src/rttr/detail/comparison/compare_array_less_impl.h")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/rttr/detail/comparison" TYPE FILE PERMISSIONS OWNER_READ FILES "C:/Users/User/Desktop/Github/rttr/src/rttr/detail/comparison/compare_array_equal.h")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/rttr/detail/comparison" TYPE FILE PERMISSIONS OWNER_READ FILES "C:/Users/User/Desktop/Github/rttr/src/rttr/detail/comparison/compare_array_equal_impl.h")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/rttr/detail/comparison" TYPE FILE PERMISSIONS OWNER_READ FILES "C:/Users/User/Desktop/Github/rttr/src/rttr/detail/comparison/compare_equal.h")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/rttr/detail/comparison" TYPE FILE PERMISSIONS OWNER_READ FILES "C:/Users/User/Desktop/Github/rttr/src/rttr/detail/comparison/compare_equal_impl.h")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/rttr/detail/comparison" TYPE FILE PERMISSIONS OWNER_READ FILES "C:/Users/User/Desktop/Github/rttr/src/rttr/detail/comparison/compare_less.h")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/rttr/detail/comparison" TYPE FILE PERMISSIONS OWNER_READ FILES "C:/Users/User/Desktop/Github/rttr/src/rttr/detail/comparison/compare_less_impl.h")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/rttr/detail/constructor" TYPE FILE PERMISSIONS OWNER_READ FILES "C:/Users/User/Desktop/Github/rttr/src/rttr/detail/constructor/constructor_invoker.h")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/rttr/detail/constructor" TYPE FILE PERMISSIONS OWNER_READ FILES "C:/Users/User/Desktop/Github/rttr/src/rttr/detail/constructor/constructor_wrapper.h")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/rttr/detail/constructor" TYPE FILE PERMISSIONS OWNER_READ FILES "C:/Users/User/Desktop/Github/rttr/src/rttr/detail/constructor/constructor_wrapper_defaults.h")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/rttr/detail/constructor" TYPE FILE PERMISSIONS OWNER_READ FILES "C:/Users/User/Desktop/Github/rttr/src/rttr/detail/constructor/constructor_wrapper_base.h")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/rttr/detail/conversion" TYPE FILE PERMISSIONS OWNER_READ FILES "C:/Users/User/Desktop/Github/rttr/src/rttr/detail/conversion/std_conversion_functions.h")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/rttr/detail/conversion" TYPE FILE PERMISSIONS OWNER_READ FILES "C:/Users/User/Desktop/Github/rttr/src/rttr/detail/conversion/number_conversion.h")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/rttr/detail/default_arguments" TYPE FILE PERMISSIONS OWNER_READ FILES "C:/Users/User/Desktop/Github/rttr/src/rttr/detail/default_arguments/default_arguments.h")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/rttr/detail/default_arguments" TYPE FILE PERMISSIONS OWNER_READ FILES "C:/Users/User/Desktop/Github/rttr/src/rttr/detail/default_arguments/invoke_with_defaults.h")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/rttr/detail/destructor" TYPE FILE PERMISSIONS OWNER_READ FILES "C:/Users/User/Desktop/Github/rttr/src/rttr/detail/destructor/destructor_wrapper.h")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/rttr/detail/destructor" TYPE FILE PERMISSIONS OWNER_READ FILES "C:/Users/User/Desktop/Github/rttr/src/rttr/detail/destructor/destructor_wrapper_base.h")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/rttr/detail/enumeration" TYPE FILE PERMISSIONS OWNER_READ FILES "C:/Users/User/Desktop/Github/rttr/src/rttr/detail/enumeration/enumeration_helper.h")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/rttr/detail/enumeration" TYPE FILE PERMISSIONS OWNER_READ FILES "C:/Users/User/Desktop/Github/rttr/src/rttr/detail/enumeration/enumeration_wrapper.h")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/rttr/detail/enumeration" TYPE FILE PERMISSIONS OWNER_READ FILES "C:/Users/User/Desktop/Github/rttr/src/rttr/detail/enumeration/enumeration_wrapper_base.h")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/rttr/detail/enumeration" TYPE FILE PERMISSIONS OWNER_READ FILES "C:/Users/User/Desktop/Github/rttr/src/rttr/detail/enumeration/enum_data.h")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/rttr/detail/filter" TYPE FILE PERMISSIONS OWNER_READ FILES "C:/Users/User/Desktop/Github/rttr/src/rttr/detail/filter/filter_item_funcs.h")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/rttr/detail/impl" TYPE FILE PERMISSIONS OWNER_READ FILES "C:/Users/User/Desktop/Github/rttr/src/rttr/detail/impl/argument_impl.h")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/rttr/detail/impl" TYPE FILE PERMISSIONS OWNER_READ FILES "C:/Users/User/Desktop/Github/rttr/src/rttr/detail/impl/array_range_impl.h")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/rttr/detail/impl" TYPE FILE PERMISSIONS OWNER_READ FILES "C:/Users/User/Desktop/Github/rttr/src/rttr/detail/impl/associative_mapper_impl.h")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/rttr/detail/impl" TYPE FILE PERMISSIONS OWNER_READ FILES "C:/Users/User/Desktop/Github/rttr/src/rttr/detail/impl/enum_flags_impl.h")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/rttr/detail/impl" TYPE FILE PERMISSIONS OWNER_READ FILES "C:/Users/User/Desktop/Github/rttr/src/rttr/detail/impl/instance_impl.h")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/rttr/detail/impl" TYPE FILE PERMISSIONS OWNER_READ FILES "C:/Users/User/Desktop/Github/rttr/src/rttr/detail/impl/rttr_cast_impl.h")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/rttr/detail/impl" TYPE FILE PERMISSIONS OWNER_READ FILES "C:/Users/User/Desktop/Github/rttr/src/rttr/detail/impl/sequential_mapper_impl.h")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/rttr/detail/impl" TYPE FILE PERMISSIONS OWNER_READ FILES "C:/Users/User/Desktop/Github/rttr/src/rttr/detail/impl/string_view_impl.h")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/rttr/detail/impl" TYPE FILE PERMISSIONS OWNER_READ FILES "C:/Users/User/Desktop/Github/rttr/src/rttr/detail/impl/wrapper_mapper_impl.h")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/rttr/detail/metadata" TYPE FILE PERMISSIONS OWNER_READ FILES "C:/Users/User/Desktop/Github/rttr/src/rttr/detail/metadata/metadata.h")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/rttr/detail/metadata" TYPE FILE PERMISSIONS OWNER_READ FILES "C:/Users/User/Desktop/Github/rttr/src/rttr/detail/metadata/metadata_handler.h")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/rttr/detail/method" TYPE FILE PERMISSIONS OWNER_READ FILES "C:/Users/User/Desktop/Github/rttr/src/rttr/detail/method/method_accessor.h")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/rttr/detail/method" TYPE FILE PERMISSIONS OWNER_READ FILES "C:/Users/User/Desktop/Github/rttr/src/rttr/detail/method/method_invoker.h")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/rttr/detail/method" TYPE FILE PERMISSIONS OWNER_READ FILES "C:/Users/User/Desktop/Github/rttr/src/rttr/detail/method/method_wrapper.h")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/rttr/detail/method" TYPE FILE PERMISSIONS OWNER_READ FILES "C:/Users/User/Desktop/Github/rttr/src/rttr/detail/method/method_wrapper_base.h")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/rttr/detail/misc" TYPE FILE PERMISSIONS OWNER_READ FILES "C:/Users/User/Desktop/Github/rttr/src/rttr/detail/misc/argument_wrapper.h")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/rttr/detail/misc" TYPE FILE PERMISSIONS OWNER_READ FILES "C:/Users/User/Desktop/Github/rttr/src/rttr/detail/misc/argument_extractor.h")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/rttr/detail/misc" TYPE FILE PERMISSIONS OWNER_READ FILES "C:/Users/User/Desktop/Github/rttr/src/rttr/detail/misc/class_item_mapper.h")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/rttr/detail/misc" TYPE FILE PERMISSIONS OWNER_READ FILES "C:/Users/User/Desktop/Github/rttr/src/rttr/detail/misc/data_address_container.h")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/rttr/detail/misc" TYPE FILE PERMISSIONS OWNER_READ FILES "C:/Users/User/Desktop/Github/rttr/src/rttr/detail/misc/flat_map.h")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/rttr/detail/misc" TYPE FILE PERMISSIONS OWNER_READ FILES "C:/Users/User/Desktop/Github/rttr/src/rttr/detail/misc/flat_multimap.h")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/rttr/detail/misc" TYPE FILE PERMISSIONS OWNER_READ FILES "C:/Users/User/Desktop/Github/rttr/src/rttr/detail/misc/function_traits.h")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/rttr/detail/misc" TYPE FILE PERMISSIONS OWNER_READ FILES "C:/Users/User/Desktop/Github/rttr/src/rttr/detail/misc/iterator_wrapper.h")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/rttr/detail/misc" TYPE FILE PERMISSIONS OWNER_READ FILES "C:/Users/User/Desktop/Github/rttr/src/rttr/detail/misc/misc_type_traits.h")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/rttr/detail/misc" TYPE FILE PERMISSIONS OWNER_READ FILES "C:/Users/User/Desktop/Github/rttr/src/rttr/detail/misc/register_wrapper_mapper_conversion.h")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/rttr/detail/misc" TYPE FILE PERMISSIONS OWNER_READ FILES "C:/Users/User/Desktop/Github/rttr/src/rttr/detail/misc/sequential_container_type_traits.h")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/rttr/detail/misc" TYPE FILE PERMISSIONS OWNER_READ FILES "C:/Users/User/Desktop/Github/rttr/src/rttr/detail/misc/std_type_traits.h")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/rttr/detail/misc" TYPE FILE PERMISSIONS OWNER_READ FILES "C:/Users/User/Desktop/Github/rttr/src/rttr/detail/misc/template_type_trait.h")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/rttr/detail/misc" TYPE FILE PERMISSIONS OWNER_READ FILES "C:/Users/User/Desktop/Github/rttr/src/rttr/detail/misc/template_type_trait_impl.h")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/rttr/detail/misc" TYPE FILE PERMISSIONS OWNER_READ FILES "C:/Users/User/Desktop/Github/rttr/src/rttr/detail/misc/utility.h")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/rttr/detail/parameter_info" TYPE FILE PERMISSIONS OWNER_READ FILES "C:/Users/User/Desktop/Github/rttr/src/rttr/detail/parameter_info/parameter_infos.h")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/rttr/detail/parameter_info" TYPE FILE PERMISSIONS OWNER_READ FILES "C:/Users/User/Desktop/Github/rttr/src/rttr/detail/parameter_info/parameter_infos_compare.h")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/rttr/detail/parameter_info" TYPE FILE PERMISSIONS OWNER_READ FILES "C:/Users/User/Desktop/Github/rttr/src/rttr/detail/parameter_info/parameter_names.h")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/rttr/detail/parameter_info" TYPE FILE PERMISSIONS OWNER_READ FILES "C:/Users/User/Desktop/Github/rttr/src/rttr/detail/parameter_info/parameter_info_wrapper_base.h")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/rttr/detail/parameter_info" TYPE FILE PERMISSIONS OWNER_READ FILES "C:/Users/User/Desktop/Github/rttr/src/rttr/detail/parameter_info/parameter_info_wrapper.h")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/rttr/detail/policies" TYPE FILE PERMISSIONS OWNER_READ FILES "C:/Users/User/Desktop/Github/rttr/src/rttr/detail/policies/prop_policies.h")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/rttr/detail/policies" TYPE FILE PERMISSIONS OWNER_READ FILES "C:/Users/User/Desktop/Github/rttr/src/rttr/detail/policies/meth_policies.h")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/rttr/detail/policies" TYPE FILE PERMISSIONS OWNER_READ FILES "C:/Users/User/Desktop/Github/rttr/src/rttr/detail/policies/ctor_policies.h")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/rttr/detail/property" TYPE FILE PERMISSIONS OWNER_READ FILES "C:/Users/User/Desktop/Github/rttr/src/rttr/detail/property/property_accessor.h")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/rttr/detail/property" TYPE FILE PERMISSIONS OWNER_READ FILES "C:/Users/User/Desktop/Github/rttr/src/rttr/detail/property/property_wrapper.h")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/rttr/detail/property" TYPE FILE PERMISSIONS OWNER_READ FILES "C:/Users/User/Desktop/Github/rttr/src/rttr/detail/property/property_wrapper_base.h")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/rttr/detail/property" TYPE FILE PERMISSIONS OWNER_READ FILES "C:/Users/User/Desktop/Github/rttr/src/rttr/detail/property/property_wrapper_func.h")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/rttr/detail/property" TYPE FILE PERMISSIONS OWNER_READ FILES "C:/Users/User/Desktop/Github/rttr/src/rttr/detail/property/property_wrapper_member_func.h")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/rttr/detail/property" TYPE FILE PERMISSIONS OWNER_READ FILES "C:/Users/User/Desktop/Github/rttr/src/rttr/detail/property/property_wrapper_member_object.h")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/rttr/detail/property" TYPE FILE PERMISSIONS OWNER_READ FILES "C:/Users/User/Desktop/Github/rttr/src/rttr/detail/property/property_wrapper_object.h")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/rttr/detail/registration" TYPE FILE PERMISSIONS OWNER_READ FILES "C:/Users/User/Desktop/Github/rttr/src/rttr/detail/registration/bind_types.h")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/rttr/detail/registration" TYPE FILE PERMISSIONS OWNER_READ FILES "C:/Users/User/Desktop/Github/rttr/src/rttr/detail/registration/bind_impl.h")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/rttr/detail/registration" TYPE FILE PERMISSIONS OWNER_READ FILES "C:/Users/User/Desktop/Github/rttr/src/rttr/detail/registration/register_base_class_from_accessor.h")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/rttr/detail/registration" TYPE FILE PERMISSIONS OWNER_READ FILES "C:/Users/User/Desktop/Github/rttr/src/rttr/detail/registration/registration_impl.h")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/rttr/detail/registration" TYPE FILE PERMISSIONS OWNER_READ FILES "C:/Users/User/Desktop/Github/rttr/src/rttr/detail/registration/registration_executer.h")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/rttr/detail/registration" TYPE FILE PERMISSIONS OWNER_READ FILES "C:/Users/User/Desktop/Github/rttr/src/rttr/detail/registration/registration_manager.h")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/rttr/detail/registration" TYPE FILE PERMISSIONS OWNER_READ FILES "C:/Users/User/Desktop/Github/rttr/src/rttr/detail/registration/registration_state_saver.h")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/rttr/detail/type" TYPE FILE PERMISSIONS OWNER_READ FILES "C:/Users/User/Desktop/Github/rttr/src/rttr/detail/type/accessor_type.h")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/rttr/detail/type" TYPE FILE PERMISSIONS OWNER_READ FILES "C:/Users/User/Desktop/Github/rttr/src/rttr/detail/type/base_classes.h")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/rttr/detail/type" TYPE FILE PERMISSIONS OWNER_READ FILES "C:/Users/User/Desktop/Github/rttr/src/rttr/detail/type/get_create_variant_func.h")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/rttr/detail/type" TYPE FILE PERMISSIONS OWNER_READ FILES "C:/Users/User/Desktop/Github/rttr/src/rttr/detail/type/get_derived_info_func.h")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/rttr/detail/type" TYPE FILE PERMISSIONS OWNER_READ FILES "C:/Users/User/Desktop/Github/rttr/src/rttr/detail/type/type_converter.h")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/rttr/detail/type" TYPE FILE PERMISSIONS OWNER_READ FILES "C:/Users/User/Desktop/Github/rttr/src/rttr/detail/type/type_comparator.h")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/rttr/detail/type" TYPE FILE PERMISSIONS OWNER_READ FILES "C:/Users/User/Desktop/Github/rttr/src/rttr/detail/type/type_data.h")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/rttr/detail/type" TYPE FILE PERMISSIONS OWNER_READ FILES "C:/Users/User/Desktop/Github/rttr/src/rttr/detail/type/type_register.h")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/rttr/detail/type" TYPE FILE PERMISSIONS OWNER_READ FILES "C:/Users/User/Desktop/Github/rttr/src/rttr/detail/type/type_impl.h")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/rttr/detail/type" TYPE FILE PERMISSIONS OWNER_READ FILES "C:/Users/User/Desktop/Github/rttr/src/rttr/detail/type/type_name.h")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/rttr/detail/type" TYPE FILE PERMISSIONS OWNER_READ FILES "C:/Users/User/Desktop/Github/rttr/src/rttr/detail/type/type_string_utils.h")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/rttr/detail/variant" TYPE FILE PERMISSIONS OWNER_READ FILES "C:/Users/User/Desktop/Github/rttr/src/rttr/detail/variant/variant_compare.h")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/rttr/detail/variant" TYPE FILE PERMISSIONS OWNER_READ FILES "C:/Users/User/Desktop/Github/rttr/src/rttr/detail/variant/variant_data.h")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/rttr/detail/variant" TYPE FILE PERMISSIONS OWNER_READ FILES "C:/Users/User/Desktop/Github/rttr/src/rttr/detail/variant/variant_data_converter.h")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/rttr/detail/variant" TYPE FILE PERMISSIONS OWNER_READ FILES "C:/Users/User/Desktop/Github/rttr/src/rttr/detail/variant/variant_data_policy.h")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/rttr/detail/variant" TYPE FILE PERMISSIONS OWNER_READ FILES "C:/Users/User/Desktop/Github/rttr/src/rttr/detail/variant/variant_impl.h")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/rttr/detail/variant_associative_view" TYPE FILE PERMISSIONS OWNER_READ FILES "C:/Users/User/Desktop/Github/rttr/src/rttr/detail/variant_associative_view/variant_associative_view_private.h")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/rttr/detail/variant_associative_view" TYPE FILE PERMISSIONS OWNER_READ FILES "C:/Users/User/Desktop/Github/rttr/src/rttr/detail/variant_associative_view/variant_associative_view_creator.h")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/rttr/detail/variant_associative_view" TYPE FILE PERMISSIONS OWNER_READ FILES "C:/Users/User/Desktop/Github/rttr/src/rttr/detail/variant_associative_view/variant_associative_view_creator_impl.h")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/rttr/detail/variant_sequential_view" TYPE FILE PERMISSIONS OWNER_READ FILES "C:/Users/User/Desktop/Github/rttr/src/rttr/detail/variant_sequential_view/variant_sequential_view_private.h")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/rttr/detail/variant_sequential_view" TYPE FILE PERMISSIONS OWNER_READ FILES "C:/Users/User/Desktop/Github/rttr/src/rttr/detail/variant_sequential_view/variant_sequential_view_creator_impl.h")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/rttr/detail/variant_sequential_view" TYPE FILE PERMISSIONS OWNER_READ FILES "C:/Users/User/Desktop/Github/rttr/src/rttr/detail/variant_sequential_view/variant_sequential_view_creator.h")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/rttr/detail/visitor" TYPE FILE PERMISSIONS OWNER_READ FILES "C:/Users/User/Desktop/Github/rttr/src/rttr/detail/visitor/visitor_iterator.h")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/rttr/detail/visitor" TYPE FILE PERMISSIONS OWNER_READ FILES "C:/Users/User/Desktop/Github/rttr/src/rttr/detail/visitor/create_type_visitor_func.h")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/rttr/detail/visitor" TYPE FILE PERMISSIONS OWNER_READ FILES "C:/Users/User/Desktop/Github/rttr/src/rttr/detail/visitor/create_type_visitor_func_impl.h")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/rttr/detail/visitor" TYPE FILE PERMISSIONS OWNER_READ FILES "C:/Users/User/Desktop/Github/rttr/src/rttr/detail/visitor/method_visitor_invoker.h")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/rttr/detail/visitor" TYPE FILE PERMISSIONS OWNER_READ FILES "C:/Users/User/Desktop/Github/rttr/src/rttr/detail/visitor/constructor_visitor_invoker.h")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/rttr/detail/visitor" TYPE FILE PERMISSIONS OWNER_READ FILES "C:/Users/User/Desktop/Github/rttr/src/rttr/detail/visitor/property_visitor_invoker.h")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/rttr/detail/visitor" TYPE FILE PERMISSIONS OWNER_READ FILES "C:/Users/User/Desktop/Github/rttr/src/rttr/detail/visitor/visitor_impl.h")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/rttr/detail/visitor" TYPE FILE PERMISSIONS OWNER_READ FILES "C:/Users/User/Desktop/Github/rttr/src/rttr/detail/visitor/type_visitor_invoker.h")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/rttr/detail/visitor" TYPE FILE PERMISSIONS OWNER_READ FILES "C:/Users/User/Desktop/Github/rttr/src/rttr/detail/visitor/visitor_registration.h")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  if("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Dd][Ee][Bb][Uu][Gg])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY OPTIONAL FILES "C:/Users/User/Desktop/Github/rttr/lib/Debug/rttr_core_d.lib")
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY OPTIONAL FILES "C:/Users/User/Desktop/Github/rttr/lib/Release/rttr_core.lib")
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Mm][Ii][Nn][Ss][Ii][Zz][Ee][Rr][Ee][Ll])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY OPTIONAL FILES "C:/Users/User/Desktop/Github/rttr/lib/MinSizeRel/rttr_core.lib")
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Rr][Ee][Ll][Ww][Ii][Tt][Hh][Dd][Ee][Bb][Ii][Nn][Ff][Oo])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY OPTIONAL FILES "C:/Users/User/Desktop/Github/rttr/lib/RelWithDebInfo/rttr_core.lib")
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  if("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Dd][Ee][Bb][Uu][Gg])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE SHARED_LIBRARY FILES "C:/Users/User/Desktop/Github/rttr/bin/Debug/rttr_core_d.dll")
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE SHARED_LIBRARY FILES "C:/Users/User/Desktop/Github/rttr/bin/Release/rttr_core.dll")
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Mm][Ii][Nn][Ss][Ii][Zz][Ee][Rr][Ee][Ll])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE SHARED_LIBRARY FILES "C:/Users/User/Desktop/Github/rttr/bin/MinSizeRel/rttr_core.dll")
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Rr][Ee][Ll][Ww][Ii][Tt][Hh][Dd][Ee][Bb][Ii][Nn][Ff][Oo])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE SHARED_LIBRARY FILES "C:/Users/User/Desktop/Github/rttr/bin/RelWithDebInfo/rttr_core.dll")
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  if("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Dd][Ee][Bb][Uu][Gg])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE FILE FILES "C:/Users/User/Desktop/Github/rttr/bin/Debug/rttr_core_d.pdb")
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Rr][Ee][Ll][Ww][Ii][Tt][Hh][Dd][Ee][Bb][Ii][Nn][Ff][Oo])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE FILE FILES "C:/Users/User/Desktop/Github/rttr/bin/RelWithDebInfo/rttr_core.pdb")
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}C:/Users/User/Desktop/Github/rttr/install/cmake/rttr-config.cmake")
    file(DIFFERENT EXPORT_FILE_CHANGED FILES
         "$ENV{DESTDIR}C:/Users/User/Desktop/Github/rttr/install/cmake/rttr-config.cmake"
         "C:/Users/User/Desktop/Github/rttr/src/rttr/CMakeFiles/Export/C_/Users/User/Desktop/Github/rttr/install/cmake/rttr-config.cmake")
    if(EXPORT_FILE_CHANGED)
      file(GLOB OLD_CONFIG_FILES "$ENV{DESTDIR}C:/Users/User/Desktop/Github/rttr/install/cmake/rttr-config-*.cmake")
      if(OLD_CONFIG_FILES)
        message(STATUS "Old export file \"$ENV{DESTDIR}C:/Users/User/Desktop/Github/rttr/install/cmake/rttr-config.cmake\" will be replaced.  Removing files [${OLD_CONFIG_FILES}].")
        file(REMOVE ${OLD_CONFIG_FILES})
      endif()
    endif()
  endif()
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "C:/Users/User/Desktop/Github/rttr/install/cmake/rttr-config.cmake")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
file(INSTALL DESTINATION "C:/Users/User/Desktop/Github/rttr/install/cmake" TYPE FILE FILES "C:/Users/User/Desktop/Github/rttr/src/rttr/CMakeFiles/Export/C_/Users/User/Desktop/Github/rttr/install/cmake/rttr-config.cmake")
  if("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Dd][Ee][Bb][Uu][Gg])$")
    list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
     "C:/Users/User/Desktop/Github/rttr/install/cmake/rttr-config-debug.cmake")
    if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
        message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
    endif()
    if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
        message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
    endif()
file(INSTALL DESTINATION "C:/Users/User/Desktop/Github/rttr/install/cmake" TYPE FILE FILES "C:/Users/User/Desktop/Github/rttr/src/rttr/CMakeFiles/Export/C_/Users/User/Desktop/Github/rttr/install/cmake/rttr-config-debug.cmake")
  endif()
  if("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Mm][Ii][Nn][Ss][Ii][Zz][Ee][Rr][Ee][Ll])$")
    list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
     "C:/Users/User/Desktop/Github/rttr/install/cmake/rttr-config-minsizerel.cmake")
    if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
        message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
    endif()
    if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
        message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
    endif()
file(INSTALL DESTINATION "C:/Users/User/Desktop/Github/rttr/install/cmake" TYPE FILE FILES "C:/Users/User/Desktop/Github/rttr/src/rttr/CMakeFiles/Export/C_/Users/User/Desktop/Github/rttr/install/cmake/rttr-config-minsizerel.cmake")
  endif()
  if("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Rr][Ee][Ll][Ww][Ii][Tt][Hh][Dd][Ee][Bb][Ii][Nn][Ff][Oo])$")
    list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
     "C:/Users/User/Desktop/Github/rttr/install/cmake/rttr-config-relwithdebinfo.cmake")
    if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
        message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
    endif()
    if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
        message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
    endif()
file(INSTALL DESTINATION "C:/Users/User/Desktop/Github/rttr/install/cmake" TYPE FILE FILES "C:/Users/User/Desktop/Github/rttr/src/rttr/CMakeFiles/Export/C_/Users/User/Desktop/Github/rttr/install/cmake/rttr-config-relwithdebinfo.cmake")
  endif()
  if("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee])$")
    list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
     "C:/Users/User/Desktop/Github/rttr/install/cmake/rttr-config-release.cmake")
    if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
        message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
    endif()
    if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
        message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
    endif()
file(INSTALL DESTINATION "C:/Users/User/Desktop/Github/rttr/install/cmake" TYPE FILE FILES "C:/Users/User/Desktop/Github/rttr/src/rttr/CMakeFiles/Export/C_/Users/User/Desktop/Github/rttr/install/cmake/rttr-config-release.cmake")
  endif()
endif()

