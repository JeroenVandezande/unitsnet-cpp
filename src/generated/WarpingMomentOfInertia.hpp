#pragma once

#include <cstdint>
#include <numbers>
#include <stdexcept>
#include "UnitsNetConfig.h"

namespace unitsnet_cpp
{
    enum class WarpingMomentOfInertiaUnit : std::uint8_t
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
            const un_scalar_t value,
            const WarpingMomentOfInertiaUnit unit = WarpingMomentOfInertiaUnit::MetersToTheSixth)
            : value_(convert_to_base(value, unit))
        {
        }

        [[nodiscard]] constexpr un_scalar_t base_value() const noexcept
        {
            return value_;
        }

        [[nodiscard]] constexpr un_scalar_t value(const WarpingMomentOfInertiaUnit unit) const
        {
            return convert_from_base(unit);
        }

        [[nodiscard]] constexpr WarpingMomentOfInertia operator+(const WarpingMomentOfInertia other) const noexcept
        {
            return WarpingMomentOfInertia(value_ + other.value_);
        }

        [[nodiscard]] constexpr WarpingMomentOfInertia operator-(const WarpingMomentOfInertia other) const noexcept
        {
            return WarpingMomentOfInertia(value_ - other.value_);
        }

        [[nodiscard]] constexpr WarpingMomentOfInertia operator*(const un_scalar_t scalar) const noexcept
        {
            return WarpingMomentOfInertia(value_ * scalar);
        }

        [[nodiscard]] constexpr WarpingMomentOfInertia operator/(const un_scalar_t scalar) const noexcept
        {
            return WarpingMomentOfInertia(value_ / scalar);
        }

        [[nodiscard]] constexpr bool operator==(const WarpingMomentOfInertia other) const noexcept
        {
            return value_ == other.value_;
        }

        [[nodiscard]] constexpr bool operator<(const WarpingMomentOfInertia other) const noexcept
        {
            return value_ < other.value_;
        }


        [[nodiscard]] constexpr un_scalar_t meters_to_the_sixth() const
        {
            return convert_from_base(WarpingMomentOfInertiaUnit::MetersToTheSixth);
        }

        [[nodiscard]] static constexpr WarpingMomentOfInertia from_meters_to_the_sixth(const un_scalar_t value)
        {
            return WarpingMomentOfInertia(value, WarpingMomentOfInertiaUnit::MetersToTheSixth);
        }


        [[nodiscard]] constexpr un_scalar_t decimeters_to_the_sixth() const
        {
            return convert_from_base(WarpingMomentOfInertiaUnit::DecimetersToTheSixth);
        }

        [[nodiscard]] static constexpr WarpingMomentOfInertia from_decimeters_to_the_sixth(const un_scalar_t value)
        {
            return WarpingMomentOfInertia(value, WarpingMomentOfInertiaUnit::DecimetersToTheSixth);
        }


        [[nodiscard]] constexpr un_scalar_t centimeters_to_the_sixth() const
        {
            return convert_from_base(WarpingMomentOfInertiaUnit::CentimetersToTheSixth);
        }

        [[nodiscard]] static constexpr WarpingMomentOfInertia from_centimeters_to_the_sixth(const un_scalar_t value)
        {
            return WarpingMomentOfInertia(value, WarpingMomentOfInertiaUnit::CentimetersToTheSixth);
        }


        [[nodiscard]] constexpr un_scalar_t millimeters_to_the_sixth() const
        {
            return convert_from_base(WarpingMomentOfInertiaUnit::MillimetersToTheSixth);
        }

        [[nodiscard]] static constexpr WarpingMomentOfInertia from_millimeters_to_the_sixth(const un_scalar_t value)
        {
            return WarpingMomentOfInertia(value, WarpingMomentOfInertiaUnit::MillimetersToTheSixth);
        }


        [[nodiscard]] constexpr un_scalar_t feet_to_the_sixth() const
        {
            return convert_from_base(WarpingMomentOfInertiaUnit::FeetToTheSixth);
        }

        [[nodiscard]] static constexpr WarpingMomentOfInertia from_feet_to_the_sixth(const un_scalar_t value)
        {
            return WarpingMomentOfInertia(value, WarpingMomentOfInertiaUnit::FeetToTheSixth);
        }


        [[nodiscard]] constexpr un_scalar_t inches_to_the_sixth() const
        {
            return convert_from_base(WarpingMomentOfInertiaUnit::InchesToTheSixth);
        }

        [[nodiscard]] static constexpr WarpingMomentOfInertia from_inches_to_the_sixth(const un_scalar_t value)
        {
            return WarpingMomentOfInertia(value, WarpingMomentOfInertiaUnit::InchesToTheSixth);
        }


    private:
        [[nodiscard]] static constexpr un_scalar_t convert_to_base(un_scalar_t value, WarpingMomentOfInertiaUnit unit)
        {
            switch (unit)
            {

            case WarpingMomentOfInertiaUnit::MetersToTheSixth:
                return value;

            case WarpingMomentOfInertiaUnit::DecimetersToTheSixth:
                return value / static_cast<un_scalar_t>(1e6);

            case WarpingMomentOfInertiaUnit::CentimetersToTheSixth:
                return value / static_cast<un_scalar_t>(1e12);

            case WarpingMomentOfInertiaUnit::MillimetersToTheSixth:
                return value / static_cast<un_scalar_t>(1e18);

            case WarpingMomentOfInertiaUnit::FeetToTheSixth:
                return value * static_cast<un_scalar_t>(0.000801843800914862014464);

            case WarpingMomentOfInertiaUnit::InchesToTheSixth:
                return value * static_cast<un_scalar_t>(0.000000000268535866540096);

            }

            throw std::invalid_argument("Unknown WarpingMomentOfInertia unit.");
        }

        [[nodiscard]] constexpr un_scalar_t convert_from_base(const WarpingMomentOfInertiaUnit unit) const
        {
            switch (unit)
            {

            case WarpingMomentOfInertiaUnit::MetersToTheSixth:
                return value_;

            case WarpingMomentOfInertiaUnit::DecimetersToTheSixth:
                return value_ * static_cast<un_scalar_t>(1e6);

            case WarpingMomentOfInertiaUnit::CentimetersToTheSixth:
                return value_ * static_cast<un_scalar_t>(1e12);

            case WarpingMomentOfInertiaUnit::MillimetersToTheSixth:
                return value_ * static_cast<un_scalar_t>(1e18);

            case WarpingMomentOfInertiaUnit::FeetToTheSixth:
                return value_ / static_cast<un_scalar_t>(0.000801843800914862014464);

            case WarpingMomentOfInertiaUnit::InchesToTheSixth:
                return value_ / static_cast<un_scalar_t>(0.000000000268535866540096);

            }

            throw std::invalid_argument("Unknown WarpingMomentOfInertia unit.");
        }

        un_scalar_t value_;
    };
}
