#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <doctest/doctest.h>
#include <op/op.hpp>

TEST_CASE("Scalable")
{
    struct MyScalable : public op::Scalable<MyScalable> {
        explicit MyScalable(float value)
            : value{value} {}

        float value;
    };

    SUBCASE("Multiplication")
    {
        MyScalable x{3.f};
        SUBCASE("Operator *=")
        {
            x *= 2.f;
        }
        SUBCASE("Left scale")
        {
            x = 2.f * x;
        }
        SUBCASE("Right scale")
        {
            x = x * 2.f;
        }
        CHECK(x.value == doctest::Approx{6.f});
    }

    SUBCASE("Division")
    {
        MyScalable x{3.f};
        SUBCASE("Operator /=")
        {
            x /= 2.f;
        }
        SUBCASE("Operator /")
        {
            x = x / 2.f;
        }
        CHECK(x.value == doctest::Approx{1.5f});
    }
}

TEST_CASE("Multipliable")
{
    struct MyMultipliable : public op::Multipliable<MyMultipliable> {
        explicit MyMultipliable(float value)
            : value{value} {}

        float value;
    };

    MyMultipliable x{3.f};
    SUBCASE("Operator *=")
    {
        x *= MyMultipliable{2.f};
    }
    SUBCASE("Left Multiplication")
    {
        x = MyMultipliable{2.f} * x;
    }
    SUBCASE("Right Multiplication")
    {
        x = x * MyMultipliable{2.f};
    }
    CHECK(x.value == doctest::Approx{6.f});
}

TEST_CASE("Addable")
{
    struct MyAddable : public op::Addable<MyAddable> {
        explicit MyAddable(float value)
            : value{value} {}

        float value;
    };

    MyAddable x{3.f};
    SUBCASE("Operator +=")
    {
        x += MyAddable{2.f};
    }
    SUBCASE("Left Addition")
    {
        x = MyAddable{2.f} + x;
    }
    SUBCASE("Right Addition")
    {
        x = x + MyAddable{2.f};
    }
    CHECK(x.value == doctest::Approx{5.f});
}

TEST_CASE("Subtractable")
{
    struct MySubtractable : public op::Subtractable<MySubtractable> {
        explicit MySubtractable(float value)
            : value{value} {}

        float value;
    };

    MySubtractable x{3.f};
    SUBCASE("Operator -=")
    {
        x -= MySubtractable{2.f};
    }
    SUBCASE("Subtraction")
    {
        x = x - MySubtractable{2.f};
    }
    CHECK(x.value == doctest::Approx{1.f});
}

TEST_CASE("Negatable")
{
    struct MyNegatable : public op::Negatable<MyNegatable> {
        explicit MyNegatable(float value)
            : value{value} {}

        float value;
    };

    MyNegatable x{3.f};
    x = -x;
    CHECK(x.value == doctest::Approx{-3.f});
}