#pragma once

namespace op {

template<typename Derived>
class Scalable {
public:
    friend Derived operator*(float x, Derived derived)
    {
        return Derived{derived.value * x};
    }

    friend Derived operator*(Derived derived, float x)
    {
        return operator*(x, derived);
    }

    friend Derived operator/(Derived derived, float x)
    {
        return Derived{derived.value / x};
    }

    void operator*=(float x)
    {
        This().value *= x;
    }

    void operator/=(float x)
    {
        This().value /= x;
    }

private:
    Derived& This()
    {
        return *static_cast<Derived*>(this);
    }
};

template<typename Derived>
class Multipliable {
public:
    friend Derived operator*(Derived a, Derived b)
    {
        return Derived{a.value * b.value};
    }

    void operator*=(Derived x)
    {
        This().value *= x.value;
    }

private:
    Derived& This()
    {
        return *static_cast<Derived*>(this);
    }
};

template<typename Derived>
class Addable {
public:
    friend Derived operator+(Derived a, Derived b)
    {
        return Derived{a.value + b.value};
    }

    void operator+=(Derived x)
    {
        This().value += x.value;
    }

private:
    Derived& This()
    {
        return *static_cast<Derived*>(this);
    }
};

template<typename Derived>
class Subtractable {
public:
    friend Derived operator-(Derived a, Derived b)
    {
        return Derived{a.value - b.value};
    }

    void operator-=(Derived x)
    {
        This().value -= x.value;
    }

private:
    Derived& This()
    {
        return *static_cast<Derived*>(this);
    }
};

template<typename Derived>
class Negatable {
public:
    friend Derived operator-(Derived derived)
    {
        return Derived{-derived.value};
    }
};

} // namespace op
