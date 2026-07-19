#pragma once

#include <cstdint>
#include <numbers>
#include <stdexcept>
#include "UnitsNetConfig.h"

namespace unitsnet_cpp
{
    enum class PorousMediumPermeabilityUnit : std::uint8_t
    {
        Darcys,
        Microdarcys,
        Millidarcys,
        SquareMeters,
        SquareCentimeters,
    };

    /// <summary></summary>
    class PorousMediumPermeability
    {
    public:
        constexpr explicit PorousMediumPermeability(
            const un_scalar_t value,
            const PorousMediumPermeabilityUnit unit = PorousMediumPermeabilityUnit::SquareMeters)
            : value_(convert_to_base(value, unit))
        {
        }

        [[nodiscard]] constexpr un_scalar_t base_value() const noexcept
        {
            return value_;
        }

        [[nodiscard]] constexpr un_scalar_t value(const PorousMediumPermeabilityUnit unit) const
        {
            return convert_from_base(unit);
        }

        [[nodiscard]] constexpr PorousMediumPermeability operator+(const PorousMediumPermeability other) const noexcept
        {
            return PorousMediumPermeability(value_ + other.value_);
        }

        [[nodiscard]] constexpr PorousMediumPermeability operator-(const PorousMediumPermeability other) const noexcept
        {
            return PorousMediumPermeability(value_ - other.value_);
        }

        [[nodiscard]] constexpr PorousMediumPermeability operator*(const un_scalar_t scalar) const noexcept
        {
            return PorousMediumPermeability(value_ * scalar);
        }

        [[nodiscard]] constexpr PorousMediumPermeability operator/(const un_scalar_t scalar) const noexcept
        {
            return PorousMediumPermeability(value_ / scalar);
        }

        [[nodiscard]] constexpr bool operator==(const PorousMediumPermeability other) const noexcept
        {
            return value_ == other.value_;
        }

        [[nodiscard]] constexpr bool operator<(const PorousMediumPermeability other) const noexcept
        {
            return value_ < other.value_;
        }


        [[nodiscard]] constexpr un_scalar_t darcys() const
        {
            return convert_from_base(PorousMediumPermeabilityUnit::Darcys);
        }

        [[nodiscard]] static constexpr PorousMediumPermeability from_darcys(const un_scalar_t value)
        {
            return PorousMediumPermeability(value, PorousMediumPermeabilityUnit::Darcys);
        }


        [[nodiscard]] constexpr un_scalar_t microdarcys() const
        {
            return convert_from_base(PorousMediumPermeabilityUnit::Microdarcys);
        }

        [[nodiscard]] static constexpr PorousMediumPermeability from_microdarcys(const un_scalar_t value)
        {
            return PorousMediumPermeability(value, PorousMediumPermeabilityUnit::Microdarcys);
        }


        [[nodiscard]] constexpr un_scalar_t millidarcys() const
        {
            return convert_from_base(PorousMediumPermeabilityUnit::Millidarcys);
        }

        [[nodiscard]] static constexpr PorousMediumPermeability from_millidarcys(const un_scalar_t value)
        {
            return PorousMediumPermeability(value, PorousMediumPermeabilityUnit::Millidarcys);
        }


        [[nodiscard]] constexpr un_scalar_t square_meters() const
        {
            return convert_from_base(PorousMediumPermeabilityUnit::SquareMeters);
        }

        [[nodiscard]] static constexpr PorousMediumPermeability from_square_meters(const un_scalar_t value)
        {
            return PorousMediumPermeability(value, PorousMediumPermeabilityUnit::SquareMeters);
        }


        [[nodiscard]] constexpr un_scalar_t square_centimeters() const
        {
            return convert_from_base(PorousMediumPermeabilityUnit::SquareCentimeters);
        }

        [[nodiscard]] static constexpr PorousMediumPermeability from_square_centimeters(const un_scalar_t value)
        {
            return PorousMediumPermeability(value, PorousMediumPermeabilityUnit::SquareCentimeters);
        }


    private:
        [[nodiscard]] static constexpr un_scalar_t convert_to_base(un_scalar_t value, PorousMediumPermeabilityUnit unit)
        {
            switch (unit)
            {

            case PorousMediumPermeabilityUnit::Darcys:
                return value * static_cast<un_scalar_t>(9.869233e-13);

            case PorousMediumPermeabilityUnit::Microdarcys:
                return (value * static_cast<un_scalar_t>(1e-6)) * static_cast<un_scalar_t>(9.869233e-13);

            case PorousMediumPermeabilityUnit::Millidarcys:
                return (value * static_cast<un_scalar_t>(1e-3)) * static_cast<un_scalar_t>(9.869233e-13);

            case PorousMediumPermeabilityUnit::SquareMeters:
                return value;

            case PorousMediumPermeabilityUnit::SquareCentimeters:
                return value * static_cast<un_scalar_t>(1e-4);

            }

            throw std::invalid_argument("Unknown PorousMediumPermeability unit.");
        }

        [[nodiscard]] constexpr un_scalar_t convert_from_base(const PorousMediumPermeabilityUnit unit) const
        {
            switch (unit)
            {

            case PorousMediumPermeabilityUnit::Darcys:
                return value_ / static_cast<un_scalar_t>(9.869233e-13);

            case PorousMediumPermeabilityUnit::Microdarcys:
                return (value_ / static_cast<un_scalar_t>(9.869233e-13)) / static_cast<un_scalar_t>(1e-6);

            case PorousMediumPermeabilityUnit::Millidarcys:
                return (value_ / static_cast<un_scalar_t>(9.869233e-13)) / static_cast<un_scalar_t>(1e-3);

            case PorousMediumPermeabilityUnit::SquareMeters:
                return value_;

            case PorousMediumPermeabilityUnit::SquareCentimeters:
                return value_ / static_cast<un_scalar_t>(1e-4);

            }

            throw std::invalid_argument("Unknown PorousMediumPermeability unit.");
        }

        un_scalar_t value_;
    };
}
