#pragma once

#include <cstdint>
#include <numbers>
#include <stdexcept>
#include "UnitsNetConfig.h"

namespace unitsnet_cpp
{
    enum class VitaminAUnit : std::uint8_t
    {
        InternationalUnits,
    };

    /// <summary>Vitamin A: 1 IU is the biological equivalent of 0.3 µg retinol, or of 0.6 µg beta-carotene.</summary>
    class VitaminA
    {
    public:
        constexpr explicit VitaminA(
            const un_scalar_t value,
            const VitaminAUnit unit = VitaminAUnit::InternationalUnits)
            : value_(convert_to_base(value, unit))
        {
        }

        [[nodiscard]] constexpr un_scalar_t base_value() const noexcept
        {
            return value_;
        }

        [[nodiscard]] constexpr un_scalar_t value(const VitaminAUnit unit) const
        {
            return convert_from_base(unit);
        }

        [[nodiscard]] constexpr VitaminA operator+(const VitaminA other) const noexcept
        {
            return VitaminA(value_ + other.value_);
        }

        [[nodiscard]] constexpr VitaminA operator-(const VitaminA other) const noexcept
        {
            return VitaminA(value_ - other.value_);
        }

        [[nodiscard]] constexpr VitaminA operator*(const un_scalar_t scalar) const noexcept
        {
            return VitaminA(value_ * scalar);
        }

        [[nodiscard]] constexpr VitaminA operator/(const un_scalar_t scalar) const noexcept
        {
            return VitaminA(value_ / scalar);
        }

        [[nodiscard]] constexpr bool operator==(const VitaminA other) const noexcept
        {
            return value_ == other.value_;
        }

        [[nodiscard]] constexpr bool operator<(const VitaminA other) const noexcept
        {
            return value_ < other.value_;
        }


        [[nodiscard]] constexpr un_scalar_t international_units() const
        {
            return convert_from_base(VitaminAUnit::InternationalUnits);
        }

        [[nodiscard]] static constexpr VitaminA from_international_units(const un_scalar_t value)
        {
            return VitaminA(value, VitaminAUnit::InternationalUnits);
        }


    private:
        [[nodiscard]] static constexpr un_scalar_t convert_to_base(un_scalar_t value, VitaminAUnit unit)
        {
            switch (unit)
            {

            case VitaminAUnit::InternationalUnits:
                return value;

            }

            throw std::invalid_argument("Unknown VitaminA unit.");
        }

        [[nodiscard]] constexpr un_scalar_t convert_from_base(const VitaminAUnit unit) const
        {
            switch (unit)
            {

            case VitaminAUnit::InternationalUnits:
                return value_;

            }

            throw std::invalid_argument("Unknown VitaminA unit.");
        }

        un_scalar_t value_;
    };
}
