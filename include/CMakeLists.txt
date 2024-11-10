set(target ${STACK_AND_QUEUE_CUSTOM})

file(GLOB hdrs "*.h*")

add_custom_target(${target} SOURCES ${hdrs})