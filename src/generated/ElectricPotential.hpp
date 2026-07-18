#pragma once

#include <cstdint>
#include <numbers>
#include <stdexcept>

namespace unitsnet_cpp
{
    enum class ElectricPotentialUnit : std::uint16_t
    {
        Volts,
        Nanovolts,
        Microvolts,
        Millivolts,
        Kilovolts,
        Megavolts,
    };

    /// <summary>In classical electromagnetism, the electric potential (a scalar quantity denoted by Φ, ΦE or V and also called the electric field potential or the electrostatic potential) at a point is the amount of electric potential energy that a unitary point charge would have when located at that point.</summary>
    class ElectricPotential
    {
    public:
        constexpr explicit ElectricPotential(
            double value,
            ElectricPotentialUnit unit = ElectricPotentialUnit::Volts)
            : value_(convert_to_base(value, unit))
        {
        }

        [[nodiscard]] constexpr double base_value() const noexcept
        {
            return value_;
        }

        [[nodiscard]] constexpr double value(ElectricPotentialUnit unit) const
        {
            return convert_from_base(unit);
        }

        [[nodiscard]] constexpr ElectricPotential operator+(ElectricPotential other) const noexcept
        {
            return ElectricPotential(value_ + other.value_);
        }

        [[nodiscard]] constexpr ElectricPotential operator-(ElectricPotential other) const noexcept
        {
            return ElectricPotential(value_ - other.value_);
        }

        [[nodiscard]] constexpr ElectricPotential operator*(double scalar) const noexcept
        {
            return ElectricPotential(value_ * scalar);
        }

        [[nodiscard]] constexpr ElectricPotential operator/(double scalar) const noexcept
        {
            return ElectricPotential(value_ / scalar);
        }

        [[nodiscard]] constexpr bool operator==(ElectricPotential other) const noexcept
        {
            return value_ == other.value_;
        }

        [[nodiscard]] constexpr bool operator<(ElectricPotential other) const noexcept
        {
            return value_ < other.value_;
        }


        [[nodiscard]] constexpr double volts() const
        {
            return convert_from_base(ElectricPotentialUnit::Volts);
        }

        [[nodiscard]] static constexpr ElectricPotential from_volts(double value)
        {
            return ElectricPotential(value, ElectricPotentialUnit::Volts);
        }


        [[nodiscard]] constexpr double nanovolts() const
        {
            return convert_from_base(ElectricPotentialUnit::Nanovolts);
        }

        [[nodiscard]] static constexpr ElectricPotential from_nanovolts(double value)
        {
            return ElectricPotential(value, ElectricPotentialUnit::Nanovolts);
        }


        [[nodiscard]] constexpr double microvolts() const
        {
            return convert_from_base(ElectricPotentialUnit::Microvolts);
        }

        [[nodiscard]] static constexpr ElectricPotential from_microvolts(double value)
        {
            return ElectricPotential(value, ElectricPotentialUnit::Microvolts);
        }


        [[nodiscard]] constexpr double millivolts() const
        {
            return convert_from_base(ElectricPotentialUnit::Millivolts);
        }

        [[nodiscard]] static constexpr ElectricPotential from_millivolts(double value)
        {
            return ElectricPotential(value, ElectricPotentialUnit::Millivolts);
        }


        [[nodiscard]] constexpr double kilovolts() const
        {
            return convert_from_base(ElectricPotentialUnit::Kilovolts);
        }

        [[nodiscard]] static constexpr ElectricPotential from_kilovolts(double value)
        {
            return ElectricPotential(value, ElectricPotentialUnit::Kilovolts);
        }


        [[nodiscard]] constexpr double megavolts() const
        {
            return convert_from_base(ElectricPotentialUnit::Megavolts);
        }

        [[nodiscard]] static constexpr ElectricPotential from_megavolts(double value)
        {
            return ElectricPotential(value, ElectricPotentialUnit::Megavolts);
        }


    private:
        [[nodiscard]] static constexpr double convert_to_base(double value, ElectricPotentialUnit unit)
        {
            switch (unit)
            {

            case ElectricPotentialUnit::Volts:
                return value;

            case ElectricPotentialUnit::Nanovolts:
                return (value * 1e-9);

            case ElectricPotentialUnit::Microvolts:
                return (value * 1e-6);

            case ElectricPotentialUnit::Millivolts:
                return (value * 1e-3);

            case ElectricPotentialUnit::Kilovolts:
                return (value * 1e3);

            case ElectricPotentialUnit::Megavolts:
                return (value * 1e6);

            }

            throw std::invalid_argument("Unknown ElectricPotential unit.");
        }

        [[nodiscard]] constexpr double convert_from_base(ElectricPotentialUnit unit) const
        {
            switch (unit)
            {

            case ElectricPotentialUnit::Volts:
                return value_;

            case ElectricPotentialUnit::Nanovolts:
                return (value_) / 1e-9;

            case ElectricPotentialUnit::Microvolts:
                return (value_) / 1e-6;

            case ElectricPotentialUnit::Millivolts:
                return (value_) / 1e-3;

            case ElectricPotentialUnit::Kilovolts:
                return (value_) / 1e3;

            case ElectricPotentialUnit::Megavolts:
                return (value_) / 1e6;

            }

            throw std::invalid_argument("Unknown ElectricPotential unit.");
        }

        double value_;
    };
}
