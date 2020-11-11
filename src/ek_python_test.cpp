#include <enoki/array.h>
#include <enoki/math.h>
#include <enoki/cuda.h>

#include <pybind11/pybind11.h>

// Import pybind11 and Enoki namespaces
namespace py = pybind11;
namespace ek = enoki;

// The function we want to expose in Python
template <typename Float>
ek::Array<Float, 3> sph_to_cartesian(Float theta, Float phi) {
    auto [sin_theta, cos_theta ] = ek::sincos(theta);
    auto [sin_phi,   cos_phi   ] = ek::sincos(phi);

    return { sin_theta * cos_phi,
             sin_theta * sin_phi,
             cos_theta };
}

/* The function below is called when the extension module is loaded. It performs a
   sequence of m.def(...) calls which define functions in the module namespace 'm' */
PYBIND11_MODULE(_ek_python_test /* <- name of extension module */, m) {
    m.doc() = "Enoki & pybind11 test plugin"; // Set a docstring

    // 1. Bind the scalar version of the function
    m.def("sph_to_cartesian",      // Function name in Python
          sph_to_cartesian<float>, // Function to be  exposed

          // Docstring (shown in the auto-generated help)
          "Convert from spherical to cartesian coordinates [scalar version]",

          // Designate parameter names for help and keyword-based calls
          py::arg("theta"), py::arg("phi"));

    // 2. Bind the GPU version of the function
    m.def("sph_to_cartesian",
          sph_to_cartesian<ek::CUDAArray<float>>,
          "Convert from spherical to cartesian coordinates [GPU version]",
          py::arg("theta"), py::arg("phi"));
}
