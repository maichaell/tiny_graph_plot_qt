QT       += core gui opengl

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    main.cpp \
    mainwindow.cpp \
    tiny_graph_plot/source/qt_canvas.cpp \
    tiny_graph_plot/source/canvas_manager.cpp \
    tiny_graph_plot/source/glfw_callback_functions.cpp \
    tiny_graph_plot/source/main.cpp \
    tiny_graph_plot/source/stb_image_write_impl.cpp \
    tiny_graph_plot/source/text_renderer.cpp \
    #tiny_graph_plot/source/user_window.cpp \
    tiny_graph_plot/source/qt_user_window.cpp


INCLUDEPATH += tiny_graph_plot/include
INCLUDEPATH += tiny_graph_plot/third_party/glfw-3.3.9.bin.WIN64/include
INCLUDEPATH += tiny_graph_plot/third_party/glew-2.1.0/include
INCLUDEPATH += tiny_graph_plot/third_party/stbi

HEADERS += \
    mainwindow.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

LIBS += -lOpenGL32

#include_directories(include)
##include_directories(third_party/glfw-3.3.2.bin.WIN64/include)
##include_directories(third_party/glew-2.1.0/include)
#include_directories(third_party/stbi)
#link_directories(third_party/glfw-3.3.2.bin.WIN64/lib-vc2019)
#link_directories(third_party/glew-2.1.0/lib/Release/x64)

#add_executable(tiny_graph_plot ${SOURCES})

#target_link_libraries(tiny_graph_plot glfw3)
#target_link_libraries(tiny_graph_plot glew32)
#target_link_libraries(tiny_graph_plot opengl32)
