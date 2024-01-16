#include "canvas_manager.h"
/*
//#include "glfw_callback_functions.h"

namespace tiny_graph_plot {

template<typename T>
CanvasManager<T>::CanvasManager(void) {
    //MIKA glfwSetErrorCallback(tiny_graph_plot:://MIKA glfw_callback_functions::error_callback_//MIKA glfw);
    //if (!//MIKA glfwInit()) {
        fprintf(stderr, "//MIKA glfw: error: failed to initialize.\n\nAborting.\n");
        exit(EXIT_FAILURE);
    //}
}

template<typename T>
CanvasManager<T>::~CanvasManager(void) {
    for (auto* canv : _canvases) {
        delete canv;
    }
    _canvases.clear();
    //MIKA glfwTerminate();
}

/*template<typename T>
Canvas<T>& CanvasManager<T>::CreateCanvas(const char* name,
    const unsigned int w, const unsigned int h,
    const unsigned int x, const unsigned int y) {
    //MIKA glfwWindowHint(//MIKA glfw_SAMPLES, 4);
    //MIKA glfwwindow* window = //MIKA glfwCreateWindow(w, h, name, NULL, NULL);
    //if (!window) {
        fprintf(stderr, "//MIKA glfw: error: failed to create a window.\n\nAborting.\n");
        //MIKA glfwTerminate();
        exit(EXIT_FAILURE);
    //}
    //MIKA glfwSetWindowPos(window, x, y);
    //MIKA glfwMakeContextCurrent(window);

    //if (!_glew_initialized) {
        tiny_graph_plot::init_glew();
        _glew_initialized = true;
    //}

    //MIKA glfwHideWindow(window);

    //Canvas<T>* new_canv = new Canvas<T>(window, w, h);
    //_canvases.push_back(new_canv);
    //return *new_canv;
}

template<typename T>
void CanvasManager<T>::WaitForTheWindowsToClose(void) {
    if (_canvases.size() < 1) return;
    //MIKA glfwwindow* const first_window = _canvases.at(0)->GetWindow();
    //while (!//MIKA glfwWindowShouldClose(first_window)) {
        //MIKA glfwWaitEvents();
    //}
}

template class CanvasManager<float>;
template class CanvasManager<double>;

} // end of namespace tiny_graph_plot
*/
