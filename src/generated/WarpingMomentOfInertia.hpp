#pragma once

#include <cstdint>
#include <numbers>
#include <stdexcept>

namespace unitsnet_cpp
{
    enum class WarpingMomentOfInertiaUnit : std::uint16_t
    {
        MetersToTheSixth,
        DecimetersToTheSixth,
        CentimetersToTheSixth,
        MillimetersToTheSixth,
        FeetToTheSixth,
        InchesToTheSixth,
    };

    /// <summary>A geometric property of an area that is used to determine the warping stress.</summary>
    class WarpingMomentOfInertia
    {
    public:
        constexpr explicit WarpingMomentOfInertia(
            double value,
            WarpingMomentOfInertiaUnit unit = WarpingMomentOfInertiaUnit::MetersToTheSixth)
            : value_(convert_to_base(value, unit))
        {
        }

        [[nodiscard]] constexpr double base_value() const noexcept
        {
            return value_;
        }

        [[nodiscard]] constexpr double value(WarpingMomentOfInertiaUnit unit) const
        {
            return convert_from_base(unit);
        }

        [[nodiscard]] constexpr WarpingMomentOfInertia operator+(WarpingMomentOfInertia other) const noexcept
        {
            return WarpingMomentOfInertia(value_ + other.value_);
        }

        [[nodiscard]] constexpr WarpingMomentOfInertia operator-(WarpingMomentOfInertia other) const noexcept
        {
            return WarpingMomentOfInertia(value_ - other.value_);
        }

        [[nodiscard]] constexpr WarpingMomentOfInertia operator*(double scalar) const noexcept
        {
            return WarpingMomentOfInertia(value_ * scalar);
        }

        [[nodiscard]] constexpr WarpingMomentOfInertia operator/(double scalar) const noexcept
        {
            return WarpingMomentOfInertia(value_ / scalar);
        }

        [[nodiscard]] constexpr bool operator==(WarpingMomentOfInertia other) const noexcept
        {
            return value_ == other.value_;
        }

        [[nodiscard]] constexpr bool operator<(WarpingMomentOfInertia other) const noexcept
        {
            return value_ < other.value_;
        }


        [[nodiscard]] constexpr double meters_to_the_sixth() const
        {
            return convert_from_base(WarpingMomentOfInertiaUnit::MetersToTheSixth);
        }

        [[nodiscard]] static constexpr WarpingMomentOfInertia from_meters_to_the_sixth(double value)
        {
            return WarpingMomentOfInertia(value, WarpingMomentOfInertiaUnit::MetersToTheSixth);
        }


        [[nodiscard]] constexpr double decimeters_to_the_sixth() const
        {
            return convert_from_base(WarpingMomentOfInertiaUnit::DecimetersToTheSixth);
        }

        [[nodiscard]] static constexpr WarpingMomentOfInertia from_decimeters_to_the_sixth(double value)
        {
            return WarpingMomentOfInertia(value, WarpingMomentOfInertiaUnit::DecimetersToTheSixth);
        }


        [[nodiscard]] constexpr double centimeters_to_the_sixth() const
        {
            return convert_from_base(WarpingMomentOfInertiaUnit::CentimetersToTheSixth);
        }

        [[nodiscard]] static constexpr WarpingMomentOfInertia from_centimeters_to_the_sixth(double value)
        {
            return WarpingMomentOfInertia(value, WarpingMomentOfInertiaUnit::CentimetersToTheSixth);
        }


        [[nodiscard]] constexpr double millimeters_to_the_sixth() const
        {
            return convert_from_base(WarpingMomentOfInertiaUnit::MillimetersToTheSixth);
        }

        [[nodiscard]] static constexpr WarpingMomentOfInertia from_millimeters_to_the_sixth(double value)
        {
            return WarpingMomentOfInertia(value, WarpingMomentOfInertiaUnit::MillimetersToTheSixth);
        }


        [[nodiscard]] constexpr double feet_to_the_sixth() const
        {
            return convert_from_base(WarpingMomentOfInertiaUnit::FeetToTheSixth);
        }

        [[nodiscard]] static constexpr WarpingMomentOfInertia from_feet_to_the_sixth(double value)
        {
            return WarpingMomentOfInertia(value, WarpingMomentOfInertiaUnit::FeetToTheSixth);
        }


        [[nodiscard]] constexpr double inches_to_the_sixth() const
        {
            return convert_from_base(WarpingMomentOfInertiaUnit::InchesToTheSixth);
        }

        [[nodiscard]] static constexpr WarpingMomentOfInertia from_inches_to_the_sixth(double value)
        {
            return WarpingMomentOfInertia(value, WarpingMomentOfInertiaUnit::InchesToTheSixth);
        }


    private:
        [[nodiscard]] static constexpr double convert_to_base(double value, WarpingMomentOfInertiaUnit unit)
        {
            switch (unit)
            {

            case WarpingMomentOfInertiaUnit::MetersToTheSixth:
                return value;

            case WarpingMomentOfInertiaUnit::DecimetersToTheSixth:
                return value / 1e6;

            case WarpingMomentOfInertiaUnit::CentimetersToTheSixth:
                return value / 1e12;

            case WarpingMomentOfInertiaUnit::MillimetersToTheSixth:
                return value / 1e18;

            case WarpingMomentOfInertiaUnit::FeetToTheSixth:
                return value * 0.000801843800914862014464;

            case WarpingMomentOfInertiaUnit::InchesToTheSixth:
                return value * 0.000000000268535866540096;

            }

            throw std::invalid_argument("Unknown WarpingMomentOfInertia unit.");
        }

        [[nodiscard]] constexpr double convert_from_base(WarpingMomentOfInertiaUnit unit) const
        {
            switch (unit)
            {

            case WarpingMomentOfInertiaUnit::MetersToTheSixth:
                return value_;

            case WarpingMomentOfInertiaUnit::DecimetersToTheSixth:
                return value_ * 1e6;

            case WarpingMomentOfInertiaUnit::CentimetersToTheSixth:
                return value_ * 1e12;

            case WarpingMomentOfInertiaUnit::MillimetersToTheSixth:
                return value_ * 1e18;

            case WarpingMomentOfInertiaUnit::FeetToTheSixth:
                return value_ / 0.000801843800914862014464;

            case WarpingMomentOfInertiaUnit::InchesToTheSixth:
                return value_ / 0.000000000268535866540096;

            }

            throw std::invalid_argument("Unknown WarpingMomentOfInertia unit.");
        }

        double value_;
    };
}
