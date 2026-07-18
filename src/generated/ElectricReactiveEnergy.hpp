#pragma once

#include <cstdint>
#include <numbers>
#include <stdexcept>

namespace unitsnet_cpp
{
    enum class ElectricReactiveEnergyUnit : std::uint16_t
    {
        VoltampereReactiveHours,
        KilovoltampereReactiveHours,
        MegavoltampereReactiveHours,
    };

    /// <summary>The volt-ampere reactive hour (expressed as varh) is the reactive power of one Volt-ampere reactive produced in one hour.</summary>
    class ElectricReactiveEnergy
    {
    public:
        constexpr explicit ElectricReactiveEnergy(
            double value,
            ElectricReactiveEnergyUnit unit = ElectricReactiveEnergyUnit::VoltampereReactiveHours)
            : value_(convert_to_base(value, unit))
        {
        }

        [[nodiscard]] constexpr double base_value() const noexcept
        {
            return value_;
        }

        [[nodiscard]] constexpr double value(ElectricReactiveEnergyUnit unit) const
        {
            return convert_from_base(unit);
        }

        [[nodiscard]] constexpr ElectricReactiveEnergy operator+(ElectricReactiveEnergy other) const noexcept
        {
            return ElectricReactiveEnergy(value_ + other.value_);
        }

        [[nodiscard]] constexpr ElectricReactiveEnergy operator-(ElectricReactiveEnergy other) const noexcept
        {
            return ElectricReactiveEnergy(value_ - other.value_);
        }

        [[nodiscard]] constexpr ElectricReactiveEnergy operator*(double scalar) const noexcept
        {
            return ElectricReactiveEnergy(value_ * scalar);
        }

        [[nodiscard]] constexpr ElectricReactiveEnergy operator/(double scalar) const noexcept
        {
            return ElectricReactiveEnergy(value_ / scalar);
        }

        [[nodiscard]] constexpr bool operator==(ElectricReactiveEnergy other) const noexcept
        {
            return value_ == other.value_;
        }

        [[nodiscard]] constexpr bool operator<(ElectricReactiveEnergy other) const noexcept
        {
            return value_ < other.value_;
        }


        [[nodiscard]] constexpr double voltampere_reactive_hours() const
        {
            return convert_from_base(ElectricReactiveEnergyUnit::VoltampereReactiveHours);
        }

        [[nodiscard]] static constexpr ElectricReactiveEnergy from_voltampere_reactive_hours(double value)
        {
            return ElectricReactiveEnergy(value, ElectricReactiveEnergyUnit::VoltampereReactiveHours);
        }


        [[nodiscard]] constexpr double kilovoltampere_reactive_hours() const
        {
            return convert_from_base(ElectricReactiveEnergyUnit::KilovoltampereReactiveHours);
        }

        [[nodiscard]] static constexpr ElectricReactiveEnergy from_kilovoltampere_reactive_hours(double value)
        {
            return ElectricReactiveEnergy(value, ElectricReactiveEnergyUnit::KilovoltampereReactiveHours);
        }


        [[nodiscard]] constexpr double megavoltampere_reactive_hours() const
        {
            return convert_from_base(ElectricReactiveEnergyUnit::MegavoltampereReactiveHours);
        }

        [[nodiscard]] static constexpr ElectricReactiveEnergy from_megavoltampere_reactive_hours(double value)
        {
            return ElectricReactiveEnergy(value, ElectricReactiveEnergyUnit::MegavoltampereReactiveHours);
        }


    private:
        [[nodiscard]] static constexpr double convert_to_base(double value, ElectricReactiveEnergyUnit unit)
        {
            switch (unit)
            {

            case ElectricReactiveEnergyUnit::VoltampereReactiveHours:
                return value;

            case ElectricReactiveEnergyUnit::KilovoltampereReactiveHours:
                return (value * 1e3);

            case ElectricReactiveEnergyUnit::MegavoltampereReactiveHours:
                return (value * 1e6);

            }

            throw std::invalid_argument("Unknown ElectricReactiveEnergy unit.");
        }

        [[nodiscard]] constexpr double convert_from_base(ElectricReactiveEnergyUnit unit) const
        {
            switch (unit)
            {

            case ElectricReactiveEnergyUnit::VoltampereReactiveHours:
                return value_;

            case ElectricReactiveEnergyUnit::KilovoltampereReactiveHours:
                return (value_) / 1e3;

            case ElectricReactiveEnergyUnit::MegavoltampereReactiveHours:
                return (value_) / 1e6;

            }

            throw std::invalid_argument("Unknown ElectricReactiveEnergy unit.");
        }

        double value_;
    };
}
