#pragma once

#include <cstdint>
#include <numbers>
#include <stdexcept>

namespace unitsnet_cpp
{
    enum class AreaMomentOfInertiaUnit : std::uint16_t
    {
        MetersToTheFourth,
        DecimetersToTheFourth,
        CentimetersToTheFourth,
        MillimetersToTheFourth,
        FeetToTheFourth,
        InchesToTheFourth,
    };

    /// <summary>A geometric property of an area that reflects how its points are distributed with regard to an axis.</summary>
    class AreaMomentOfInertia
    {
    public:
        constexpr explicit AreaMomentOfInertia(
            double value,
            AreaMomentOfInertiaUnit unit = AreaMomentOfInertiaUnit::MetersToTheFourth)
            : value_(convert_to_base(value, unit))
        {
        }

        [[nodiscard]] constexpr double base_value() const noexcept
        {
            return value_;
        }

        [[nodiscard]] constexpr double value(AreaMomentOfInertiaUnit unit) const
        {
            return convert_from_base(unit);
        }

        [[nodiscard]] constexpr AreaMomentOfInertia operator+(AreaMomentOfInertia other) const noexcept
        {
            return AreaMomentOfInertia(value_ + other.value_);
        }

        [[nodiscard]] constexpr AreaMomentOfInertia operator-(AreaMomentOfInertia other) const noexcept
        {
            return AreaMomentOfInertia(value_ - other.value_);
        }

        [[nodiscard]] constexpr AreaMomentOfInertia operator*(double scalar) const noexcept
        {
            return AreaMomentOfInertia(value_ * scalar);
        }

        [[nodiscard]] constexpr AreaMomentOfInertia operator/(double scalar) const noexcept
        {
            return AreaMomentOfInertia(value_ / scalar);
        }

        [[nodiscard]] constexpr bool operator==(AreaMomentOfInertia other) const noexcept
        {
            return value_ == other.value_;
        }

        [[nodiscard]] constexpr bool operator<(AreaMomentOfInertia other) const noexcept
        {
            return value_ < other.value_;
        }


        [[nodiscard]] constexpr double meters_to_the_fourth() const
        {
            return convert_from_base(AreaMomentOfInertiaUnit::MetersToTheFourth);
        }

        [[nodiscard]] static constexpr AreaMomentOfInertia from_meters_to_the_fourth(double value)
        {
            return AreaMomentOfInertia(value, AreaMomentOfInertiaUnit::MetersToTheFourth);
        }


        [[nodiscard]] constexpr double decimeters_to_the_fourth() const
        {
            return convert_from_base(AreaMomentOfInertiaUnit::DecimetersToTheFourth);
        }

        [[nodiscard]] static constexpr AreaMomentOfInertia from_decimeters_to_the_fourth(double value)
        {
            return AreaMomentOfInertia(value, AreaMomentOfInertiaUnit::DecimetersToTheFourth);
        }


        [[nodiscard]] constexpr double centimeters_to_the_fourth() const
        {
            return convert_from_base(AreaMomentOfInertiaUnit::CentimetersToTheFourth);
        }

        [[nodiscard]] static constexpr AreaMomentOfInertia from_centimeters_to_the_fourth(double value)
        {
            return AreaMomentOfInertia(value, AreaMomentOfInertiaUnit::CentimetersToTheFourth);
        }


        [[nodiscard]] constexpr double millimeters_to_the_fourth() const
        {
            return convert_from_base(AreaMomentOfInertiaUnit::MillimetersToTheFourth);
        }

        [[nodiscard]] static constexpr AreaMomentOfInertia from_millimeters_to_the_fourth(double value)
        {
            return AreaMomentOfInertia(value, AreaMomentOfInertiaUnit::MillimetersToTheFourth);
        }


        [[nodiscard]] constexpr double feet_to_the_fourth() const
        {
            return convert_from_base(AreaMomentOfInertiaUnit::FeetToTheFourth);
        }

        [[nodiscard]] static constexpr AreaMomentOfInertia from_feet_to_the_fourth(double value)
        {
            return AreaMomentOfInertia(value, AreaMomentOfInertiaUnit::FeetToTheFourth);
        }


        [[nodiscard]] constexpr double inches_to_the_fourth() const
        {
            return convert_from_base(AreaMomentOfInertiaUnit::InchesToTheFourth);
        }

        [[nodiscard]] static constexpr AreaMomentOfInertia from_inches_to_the_fourth(double value)
        {
            return AreaMomentOfInertia(value, AreaMomentOfInertiaUnit::InchesToTheFourth);
        }


    private:
        [[nodiscard]] static constexpr double convert_to_base(double value, AreaMomentOfInertiaUnit unit)
        {
            switch (unit)
            {

            case AreaMomentOfInertiaUnit::MetersToTheFourth:
                return value;

            case AreaMomentOfInertiaUnit::DecimetersToTheFourth:
                return value / 1e4;

            case AreaMomentOfInertiaUnit::CentimetersToTheFourth:
                return value / 1e8;

            case AreaMomentOfInertiaUnit::MillimetersToTheFourth:
                return value / 1e12;

            case AreaMomentOfInertiaUnit::FeetToTheFourth:
                return value * 0.0086309748412416;

            case AreaMomentOfInertiaUnit::InchesToTheFourth:
                return value * 0.0000004162314256;

            }

            throw std::invalid_argument("Unknown AreaMomentOfInertia unit.");
        }

        [[nodiscard]] constexpr double convert_from_base(AreaMomentOfInertiaUnit unit) const
        {
            switch (unit)
            {

            case AreaMomentOfInertiaUnit::MetersToTheFourth:
                return value_;

            case AreaMomentOfInertiaUnit::DecimetersToTheFourth:
                return value_ * 1e4;

            case AreaMomentOfInertiaUnit::CentimetersToTheFourth:
                return value_ * 1e8;

            case AreaMomentOfInertiaUnit::MillimetersToTheFourth:
                return value_ * 1e12;

            case AreaMomentOfInertiaUnit::FeetToTheFourth:
                return value_ / 0.0086309748412416;

            case AreaMomentOfInertiaUnit::InchesToTheFourth:
                return value_ / 0.0000004162314256;

            }

            throw std::invalid_argument("Unknown AreaMomentOfInertia unit.");
        }

        double value_;
    };
}
