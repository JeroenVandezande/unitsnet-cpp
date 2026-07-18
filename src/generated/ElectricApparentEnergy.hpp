#pragma once

#include <cstdint>
#include <numbers>
#include <stdexcept>

namespace unitsnet_cpp
{
    enum class ElectricApparentEnergyUnit : std::uint16_t
    {
        VoltampereHours,
        KilovoltampereHours,
        MegavoltampereHours,
    };

    /// <summary>A unit for expressing the integral of apparent power over time, equal to the product of 1 volt-ampere and 1 hour, or to 3600 joules.</summary>
    class ElectricApparentEnergy
    {
    public:
        constexpr explicit ElectricApparentEnergy(
            double value,
            ElectricApparentEnergyUnit unit = ElectricApparentEnergyUnit::VoltampereHours)
            : value_(convert_to_base(value, unit))
        {
        }

        [[nodiscard]] constexpr double base_value() const noexcept
        {
            return value_;
        }

        [[nodiscard]] constexpr double value(ElectricApparentEnergyUnit unit) const
        {
            return convert_from_base(unit);
        }

        [[nodiscard]] constexpr ElectricApparentEnergy operator+(ElectricApparentEnergy other) const noexcept
        {
            return ElectricApparentEnergy(value_ + other.value_);
        }

        [[nodiscard]] constexpr ElectricApparentEnergy operator-(ElectricApparentEnergy other) const noexcept
        {
            return ElectricApparentEnergy(value_ - other.value_);
        }

        [[nodiscard]] constexpr ElectricApparentEnergy operator*(double scalar) const noexcept
        {
            return ElectricApparentEnergy(value_ * scalar);
        }

        [[nodiscard]] constexpr ElectricApparentEnergy operator/(double scalar) const noexcept
        {
            return ElectricApparentEnergy(value_ / scalar);
        }

        [[nodiscard]] constexpr bool operator==(ElectricApparentEnergy other) const noexcept
        {
            return value_ == other.value_;
        }

        [[nodiscard]] constexpr bool operator<(ElectricApparentEnergy other) const noexcept
        {
            return value_ < other.value_;
        }


        [[nodiscard]] constexpr double voltampere_hours() const
        {
            return convert_from_base(ElectricApparentEnergyUnit::VoltampereHours);
        }

        [[nodiscard]] static constexpr ElectricApparentEnergy from_voltampere_hours(double value)
        {
            return ElectricApparentEnergy(value, ElectricApparentEnergyUnit::VoltampereHours);
        }


        [[nodiscard]] constexpr double kilovoltampere_hours() const
        {
            return convert_from_base(ElectricApparentEnergyUnit::KilovoltampereHours);
        }

        [[nodiscard]] static constexpr ElectricApparentEnergy from_kilovoltampere_hours(double value)
        {
            return ElectricApparentEnergy(value, ElectricApparentEnergyUnit::KilovoltampereHours);
        }


        [[nodiscard]] constexpr double megavoltampere_hours() const
        {
            return convert_from_base(ElectricApparentEnergyUnit::MegavoltampereHours);
        }

        [[nodiscard]] static constexpr ElectricApparentEnergy from_megavoltampere_hours(double value)
        {
            return ElectricApparentEnergy(value, ElectricApparentEnergyUnit::MegavoltampereHours);
        }


    private:
        [[nodiscard]] static constexpr double convert_to_base(double value, ElectricApparentEnergyUnit unit)
        {
            switch (unit)
            {

            case ElectricApparentEnergyUnit::VoltampereHours:
                return value;

            case ElectricApparentEnergyUnit::KilovoltampereHours:
                return (value * 1e3);

            case ElectricApparentEnergyUnit::MegavoltampereHours:
                return (value * 1e6);

            }

            throw std::invalid_argument("Unknown ElectricApparentEnergy unit.");
        }

        [[nodiscard]] constexpr double convert_from_base(ElectricApparentEnergyUnit unit) const
        {
            switch (unit)
            {

            case ElectricApparentEnergyUnit::VoltampereHours:
                return value_;

            case ElectricApparentEnergyUnit::KilovoltampereHours:
                return (value_) / 1e3;

            case ElectricApparentEnergyUnit::MegavoltampereHours:
                return (value_) / 1e6;

            }

            throw std::invalid_argument("Unknown ElectricApparentEnergy unit.");
        }

        double value_;
    };
}
