cmake_minimum_required(VERSION 3.17)
project(C___Test)

set(CMAKE_CXX_STANDARD 20)

include_directories(/opt/homebrew/Cellar/ffmpeg/6.0/include/)
link_directories(/opt/homebrew/Cellar/ffmpeg/6.0/lib/)

add_executable(hello hello_world.cpp)
add_executable(test_001 1-10/test_001.cpp)
add_executable(test_002 1-10/test_002.cpp)
add_executable(test_003 1-10/test_003.cpp)
add_executable(test_004 1-10/test_004.cpp)
add_executable(test_005 1-10/test_005.cpp)
add_executable(test_006 1-10/test_006.cpp)
add_executable(test_007 1-10/test_007.cpp)
add_executable(test_008 1-10/test_008.cpp)
add_executable(test_009 1-10/test_009.cpp)
add_executable(test_010 1-10/test_010.cpp)
add_executable(Sales_item_1 book_1/Sales_item.h book_1/Sales_item_add.cpp)
add_executable(Sales_item_2 book_1/Sales_item.h book_1/Sales_item_add2.cpp)
add_executable(type book_2/type.cpp)
add_executable(init book_2/init.cpp)
add_executable(name_scope book_2/name_scope.cpp)
add_executable(symbol book_2/symbol.cpp)
add_executable(const_pointer book_2/const_pointer.cpp)
add_executable(auto book_2/auto.cpp)
add_executable(decltype book_2/decltype.cpp)
add_executable(string_init book_3/string_init.cpp)
add_executable(string_add book_3/string_add.cpp)
add_executable(string_method book_3/string_method.cpp)
add_executable(vector book_3/iterator.cpp)
add_executable(array_init book_3/array_init.cpp)
add_executable(operator book_4/operator.cpp)
add_executable(brackets book_5/brackets.cpp)
add_executable(switch book_5/switch.cpp)
add_executable(erase test/erase.cpp)
add_executable(Test bytequeue/Test.cpp bytequeue/ByteQueue.cpp)

add_executable(C___Test1 multi-audio-mix/AudioResampler.cpp)
add_executable(C___Test3 multi-audio-mix/resampler.cpp)
add_executable(C___Test multi-audio-mix/resampler2.cpp)

add_executable(C___Test4 multi-audio-mix/MultiAudioMixManager.cpp)

target_link_libraries(
        C___Test
        avcodec
        avdevice
        avfilter
        avformat
        avresample
        avutil
        postproc
        swresample
        swscale
)
