#pragma once

#include <cstdint>
#include <numbers>
#include <stdexcept>

namespace unitsnet_cpp
{
    enum class MolarEnergyUnit : std::uint16_t
    {
        JoulesPerMole,
        KilojoulesPerMole,
        MegajoulesPerMole,
    };

    /// <summary>Molar energy is the amount of energy stored in 1 mole of a substance.</summary>
    class MolarEnergy
    {
    public:
        constexpr explicit MolarEnergy(
            double value,
            MolarEnergyUnit unit = MolarEnergyUnit::JoulesPerMole)
            : value_(convert_to_base(value, unit))
        {
        }

        [[nodiscard]] constexpr double base_value() const noexcept
        {
            return value_;
        }

        [[nodiscard]] constexpr double value(MolarEnergyUnit unit) const
        {
            return convert_from_base(unit);
        }

        [[nodiscard]] constexpr MolarEnergy operator+(MolarEnergy other) const noexcept
        {
            return MolarEnergy(value_ + other.value_);
        }

        [[nodiscard]] constexpr MolarEnergy operator-(MolarEnergy other) const noexcept
        {
            return MolarEnergy(value_ - other.value_);
        }

        [[nodiscard]] constexpr MolarEnergy operator*(double scalar) const noexcept
        {
            return MolarEnergy(value_ * scalar);
        }

        [[nodiscard]] constexpr MolarEnergy operator/(double scalar) const noexcept
        {
            return MolarEnergy(value_ / scalar);
        }

        [[nodiscard]] constexpr bool operator==(MolarEnergy other) const noexcept
        {
            return value_ == other.value_;
        }

        [[nodiscard]] constexpr bool operator<(MolarEnergy other) const noexcept
        {
            return value_ < other.value_;
        }


        [[nodiscard]] constexpr double joules_per_mole() const
        {
            return convert_from_base(MolarEnergyUnit::JoulesPerMole);
        }

        [[nodiscard]] static constexpr MolarEnergy from_joules_per_mole(double value)
        {
            return MolarEnergy(value, MolarEnergyUnit::JoulesPerMole);
        }


        [[nodiscard]] constexpr double kilojoules_per_mole() const
        {
            return convert_from_base(MolarEnergyUnit::KilojoulesPerMole);
        }

        [[nodiscard]] static constexpr MolarEnergy from_kilojoules_per_mole(double value)
        {
            return MolarEnergy(value, MolarEnergyUnit::KilojoulesPerMole);
        }


        [[nodiscard]] constexpr double megajoules_per_mole() const
        {
            return convert_from_base(MolarEnergyUnit::MegajoulesPerMole);
        }

        [[nodiscard]] static constexpr MolarEnergy from_megajoules_per_mole(double value)
        {
            return MolarEnergy(value, MolarEnergyUnit::MegajoulesPerMole);
        }


    private:
        [[nodiscard]] static constexpr double convert_to_base(double value, MolarEnergyUnit unit)
        {
            switch (unit)
            {

            case MolarEnergyUnit::JoulesPerMole:
                return value;

            case MolarEnergyUnit::KilojoulesPerMole:
                return (value * 1e3);

            case MolarEnergyUnit::MegajoulesPerMole:
                return (value * 1e6);

            }

            throw std::invalid_argument("Unknown MolarEnergy unit.");
        }

        [[nodiscard]] constexpr double convert_from_base(MolarEnergyUnit unit) const
        {
            switch (unit)
            {

            case MolarEnergyUnit::JoulesPerMole:
                return value_;

            case MolarEnergyUnit::KilojoulesPerMole:
                return (value_) / 1e3;

            case MolarEnergyUnit::MegajoulesPerMole:
                return (value_) / 1e6;

            }

            throw std::invalid_argument("Unknown MolarEnergy unit.");
        }

        double value_;
    };
}
