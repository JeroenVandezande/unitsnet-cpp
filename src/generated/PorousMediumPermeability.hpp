#pragma once

#include <cstdint>
#include <numbers>
#include <stdexcept>

namespace unitsnet_cpp
{
    enum class PorousMediumPermeabilityUnit : std::uint16_t
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
            double value,
            PorousMediumPermeabilityUnit unit = PorousMediumPermeabilityUnit::SquareMeters)
            : value_(convert_to_base(value, unit))
        {
        }

        [[nodiscard]] constexpr double base_value() const noexcept
        {
            return value_;
        }

        [[nodiscard]] constexpr double value(PorousMediumPermeabilityUnit unit) const
        {
            return convert_from_base(unit);
        }

        [[nodiscard]] constexpr PorousMediumPermeability operator+(PorousMediumPermeability other) const noexcept
        {
            return PorousMediumPermeability(value_ + other.value_);
        }

        [[nodiscard]] constexpr PorousMediumPermeability operator-(PorousMediumPermeability other) const noexcept
        {
            return PorousMediumPermeability(value_ - other.value_);
        }

        [[nodiscard]] constexpr PorousMediumPermeability operator*(double scalar) const noexcept
        {
            return PorousMediumPermeability(value_ * scalar);
        }

        [[nodiscard]] constexpr PorousMediumPermeability operator/(double scalar) const noexcept
        {
            return PorousMediumPermeability(value_ / scalar);
        }

        [[nodiscard]] constexpr bool operator==(PorousMediumPermeability other) const noexcept
        {
            return value_ == other.value_;
        }

        [[nodiscard]] constexpr bool operator<(PorousMediumPermeability other) const noexcept
        {
            return value_ < other.value_;
        }


        [[nodiscard]] constexpr double darcys() const
        {
            return convert_from_base(PorousMediumPermeabilityUnit::Darcys);
        }

        [[nodiscard]] static constexpr PorousMediumPermeability from_darcys(double value)
        {
            return PorousMediumPermeability(value, PorousMediumPermeabilityUnit::Darcys);
        }


        [[nodiscard]] constexpr double microdarcys() const
        {
            return convert_from_base(PorousMediumPermeabilityUnit::Microdarcys);
        }

        [[nodiscard]] static constexpr PorousMediumPermeability from_microdarcys(double value)
        {
            return PorousMediumPermeability(value, PorousMediumPermeabilityUnit::Microdarcys);
        }


        [[nodiscard]] constexpr double millidarcys() const
        {
            return convert_from_base(PorousMediumPermeabilityUnit::Millidarcys);
        }

        [[nodiscard]] static constexpr PorousMediumPermeability from_millidarcys(double value)
        {
            return PorousMediumPermeability(value, PorousMediumPermeabilityUnit::Millidarcys);
        }


        [[nodiscard]] constexpr double square_meters() const
        {
            return convert_from_base(PorousMediumPermeabilityUnit::SquareMeters);
        }

        [[nodiscard]] static constexpr PorousMediumPermeability from_square_meters(double value)
        {
            return PorousMediumPermeability(value, PorousMediumPermeabilityUnit::SquareMeters);
        }


        [[nodiscard]] constexpr double square_centimeters() const
        {
            return convert_from_base(PorousMediumPermeabilityUnit::SquareCentimeters);
        }

        [[nodiscard]] static constexpr PorousMediumPermeability from_square_centimeters(double value)
        {
            return PorousMediumPermeability(value, PorousMediumPermeabilityUnit::SquareCentimeters);
        }


    private:
        [[nodiscard]] static constexpr double convert_to_base(double value, PorousMediumPermeabilityUnit unit)
        {
            switch (unit)
            {

            case PorousMediumPermeabilityUnit::Darcys:
                return value * 9.869233e-13;

            case PorousMediumPermeabilityUnit::Microdarcys:
                return (value * 1e-6) * 9.869233e-13;

            case PorousMediumPermeabilityUnit::Millidarcys:
                return (value * 1e-3) * 9.869233e-13;

            case PorousMediumPermeabilityUnit::SquareMeters:
                return value;

            case PorousMediumPermeabilityUnit::SquareCentimeters:
                return value * 1e-4;

            }

            throw std::invalid_argument("Unknown PorousMediumPermeability unit.");
        }

        [[nodiscard]] constexpr double convert_from_base(PorousMediumPermeabilityUnit unit) const
        {
            switch (unit)
            {

            case PorousMediumPermeabilityUnit::Darcys:
                return value_ / 9.869233e-13;

            case PorousMediumPermeabilityUnit::Microdarcys:
                return (value_ / 9.869233e-13) / 1e-6;

            case PorousMediumPermeabilityUnit::Millidarcys:
                return (value_ / 9.869233e-13) / 1e-3;

            case PorousMediumPermeabilityUnit::SquareMeters:
                return value_;

            case PorousMediumPermeabilityUnit::SquareCentimeters:
                return value_ / 1e-4;

            }

            throw std::invalid_argument("Unknown PorousMediumPermeability unit.");
        }

        double value_;
    };
}
