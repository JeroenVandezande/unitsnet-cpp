#pragma once

#include <cstdint>
#include <numbers>
#include <stdexcept>

namespace unitsnet_cpp
{
    enum class VitaminAUnit : std::uint16_t
    {
        InternationalUnits,
    };

    /// <summary>Vitamin A: 1 IU is the biological equivalent of 0.3 µg retinol, or of 0.6 µg beta-carotene.</summary>
    class VitaminA
    {
    public:
        constexpr explicit VitaminA(
            double value,
            VitaminAUnit unit = VitaminAUnit::InternationalUnits)
            : value_(convert_to_base(value, unit))
        {
        }

        [[nodiscard]] constexpr double base_value() const noexcept
        {
            return value_;
        }

        [[nodiscard]] constexpr double value(VitaminAUnit unit) const
        {
            return convert_from_base(unit);
        }

        [[nodiscard]] constexpr VitaminA operator+(VitaminA other) const noexcept
        {
            return VitaminA(value_ + other.value_);
        }

        [[nodiscard]] constexpr VitaminA operator-(VitaminA other) const noexcept
        {
            return VitaminA(value_ - other.value_);
        }

        [[nodiscard]] constexpr VitaminA operator*(double scalar) const noexcept
        {
            return VitaminA(value_ * scalar);
        }

        [[nodiscard]] constexpr VitaminA operator/(double scalar) const noexcept
        {
            return VitaminA(value_ / scalar);
        }

        [[nodiscard]] constexpr bool operator==(VitaminA other) const noexcept
        {
            return value_ == other.value_;
        }

        [[nodiscard]] constexpr bool operator<(VitaminA other) const noexcept
        {
            return value_ < other.value_;
        }


        [[nodiscard]] constexpr double international_units() const
        {
            return convert_from_base(VitaminAUnit::InternationalUnits);
        }

        [[nodiscard]] static constexpr VitaminA from_international_units(double value)
        {
            return VitaminA(value, VitaminAUnit::InternationalUnits);
        }


    private:
        [[nodiscard]] static constexpr double convert_to_base(double value, VitaminAUnit unit)
        {
            switch (unit)
            {

            case VitaminAUnit::InternationalUnits:
                return value;

            }

            throw std::invalid_argument("Unknown VitaminA unit.");
        }

        [[nodiscard]] constexpr double convert_from_base(VitaminAUnit unit) const
        {
            switch (unit)
            {

            case VitaminAUnit::InternationalUnits:
                return value_;

            }

            throw std::invalid_argument("Unknown VitaminA unit.");
        }

        double value_;
    };
}
