#pragma once

#include <cmath>

#include "tiny_gl_text_renderer/vec2.h"

namespace tiny_graph_plot
{

using tiny_gl_text_renderer::Vec2;

template<typename T>
class XYrange
{
    static_assert(std::is_same<T, float>::value
               || std::is_same<T, double>::value, "");
public:
    explicit XYrange() = default;
    explicit XYrange(const T x_min, const T dx, const T y_min, const T dy)
    :   _x_min(x_min), _dx(dx), _y_min(y_min), _dy(dy) {}
    ~XYrange() = default;
    XYrange(const XYrange& other) = default;
    XYrange(XYrange&& other) = default;
    XYrange& operator=(const XYrange& other) = default;
    XYrange& operator=(XYrange&& other) = default;
public:
    template<typename U>
    __forceinline XYrange& operator=(const XYrange<U>& rhs) {
        _x_min = static_cast<T>(rhs.lowx());
        _dx    = static_cast<T>(rhs.dx());
        _y_min = static_cast<T>(rhs.lowy());
        _dy    = static_cast<T>(rhs.dy());
        return *this;
    }
    template<typename U>
    __forceinline void Include(const XYrange<U>& other) {
        const T x_max = std::fmax(_x_min + _dx, static_cast<T>(other.lowx() + other.dx()));
        const T y_max = std::fmax(_y_min + _dy, static_cast<T>(other.lowy() + other.dy()));
        _x_min = std::fmin(_x_min, static_cast<T>(other.lowx()));
        _y_min = std::fmin(_y_min, static_cast<T>(other.lowy()));
        _dx = x_max - _x_min;
        _dy = y_max - _y_min;
    }
    __forceinline void Include(const Vec2<T>& point) {
        if (!std::isfinite(point.x()) || !std::isfinite(point.y())) return;
        const T x_max = std::fmax(_x_min + _dx, point.x());
        const T y_max = std::fmax(_y_min + _dy, point.y());
        _x_min = std::fmin(_x_min, point.x());
        _y_min = std::fmin(_y_min, point.y());
        _dx = x_max - _x_min;
        _dy = y_max - _y_min;

    }
    __forceinline bool IncludesX(const T x) const {
        return (x >= _x_min) && (x <= _x_min + _dx);
    }
    __forceinline void FixDegenerateCases() {
        if (_dx <= 1.0e-8) { // abs?
            _x_min -= static_cast<T>(0.5);
            _dx     = static_cast<T>(1.0);
        }
        if (_dy <= 1.0e-8) { // abs?
            _y_min -= static_cast<T>(0.5);
            _dy     = static_cast<T>(1.0);
        }
    }
    __forceinline void Set1(const T x_min, const T x_max, const T y_min, const T y_max) {
        _x_min = x_min; _dx = x_max - x_min; _y_min = y_min; _dy = y_max - y_min;
    }
    __forceinline void Set2(const T x_min, const T dx, const T y_min, const T dy) {
        _x_min = x_min; _dx = dx; _y_min = y_min; _dy = dy;
    }
    __forceinline void SetXrange1(const T x_min, const T x_max) { _x_min = x_min; _dx = x_max - x_min; }
    __forceinline void SetYrange1(const T y_min, const T y_max) { _y_min = y_min; _dy = y_max - y_min; }
    __forceinline void SetXrange2(const T x_min, const T dx) { _x_min = x_min; _dx = dx; }
    __forceinline void SetYrange2(const T y_min, const T dy) { _y_min = y_min; _dy = dy; }
    __forceinline void MoveX(const T shift) { _x_min += shift; }
    __forceinline void MoveY(const T shift) { _y_min += shift; }
    __forceinline const T& lowx() const { return _x_min; }
    __forceinline const T highx() const { return _x_min + _dx; }
    __forceinline const T& lowy() const { return _y_min; }
    __forceinline const T highy() const { return _y_min + _dy; }
    __forceinline const T& dx()   const { return _dx; }
    __forceinline const T& dy()   const { return _dy; }
    __forceinline T xm() const { return _x_min + T(0.5) * _dx; }
    __forceinline T ym() const { return _y_min + T(0.5) * _dy; }
    __forceinline T twoxm() const { return T(2.0) * _x_min + _dx; }
    __forceinline T twoym() const { return T(2.0) * _y_min + _dy; }
private:
    T _x_min = T(0.0);
    T _dx = T(1.0);
    T _y_min = T(0.0);
    T _dy = T(1.0);
};

template class XYrange<float>;
template class XYrange<double>;

} // end of namespace tiny_graph_plot
