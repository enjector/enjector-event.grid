#include <pybind11/pybind11.h>

#include <string>

class Example {
 public:
  Example(double a) : _a(a) {}

  Example& operator+=(const Example& other) {
    _a += other._a;
    return *this;
  }

 private:
  double _a;
};

PYBIND11_MODULE(example, m) {
  m.doc() = "Python bindings for an example library";

  namespace py = pybind11;

  py::class_<Example>(m, "Example")
      .def(py::init([](double a) { return new Example(a); }))
      .def("__iadd__", &Example::operator+=);
}

//#include <pybind11/pybind11.h>
//#include <event.grid/client/NodeClient.h>
//
//EventGrid::Client::NodeClient node;
//
//int add(int i, int j) {
//    return i + j;
//}
//
//namespace py = pybind11;
//
//PYBIND11_MODULE(eventgrid, m) {
//    m.doc() = R"pbdoc(
//        Pybind11 example plugin
//        -----------------------
//
//        .. currentmodule:: eventgrid
//
//        .. autosummary::
//           :toctree: _generate
//
//           add
//           subtract
//    )pbdoc";
//
//    m.def("add", &add, R"pbdoc(
//        Add two numbers
//
//        Some other explanation about the add function.
//    )pbdoc");
//
//    m.def("subtract", [](int i, int j) { return i - j; }, R"pbdoc(
//        Subtract two numbers
//
//        Some other explanation about the subtract function.
//    )pbdoc");
//
//#ifdef VERSION_INFO
//    m.attr("__version__") = VERSION_INFO;
//#else
//    m.attr("__version__") = "dev";
//#endif
//}
