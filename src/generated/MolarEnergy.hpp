#pragma once

#include <cstdint>
#include <numbers>
#include <stdexcept>
#include "UnitsNetConfig.h"

namespace unitsnet_cpp
{
    enum class MolarEnergyUnit : std::uint8_t
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
            const un_scalar_t value,
            const MolarEnergyUnit unit = MolarEnergyUnit::JoulesPerMole)
            : value_(convert_to_base(value, unit))
        {
        }

        [[nodiscard]] constexpr un_scalar_t base_value() const noexcept
        {
            return value_;
        }

        [[nodiscard]] constexpr un_scalar_t value(const MolarEnergyUnit unit) const
        {
            return convert_from_base(unit);
        }

        [[nodiscard]] constexpr MolarEnergy operator+(const MolarEnergy other) const noexcept
        {
            return MolarEnergy(value_ + other.value_);
        }

        [[nodiscard]] constexpr MolarEnergy operator-(const MolarEnergy other) const noexcept
        {
            return MolarEnergy(value_ - other.value_);
        }

        [[nodiscard]] constexpr MolarEnergy operator*(const un_scalar_t scalar) const noexcept
        {
            return MolarEnergy(value_ * scalar);
        }

        [[nodiscard]] constexpr MolarEnergy operator/(const un_scalar_t scalar) const noexcept
        {
            return MolarEnergy(value_ / scalar);
        }

        [[nodiscard]] constexpr bool operator==(const MolarEnergy other) const noexcept
        {
            return value_ == other.value_;
        }

        [[nodiscard]] constexpr bool operator<(const MolarEnergy other) const noexcept
        {
            return value_ < other.value_;
        }


        [[nodiscard]] constexpr un_scalar_t joules_per_mole() const
        {
            return convert_from_base(MolarEnergyUnit::JoulesPerMole);
        }

        [[nodiscard]] static constexpr MolarEnergy from_joules_per_mole(const un_scalar_t value)
        {
            return MolarEnergy(value, MolarEnergyUnit::JoulesPerMole);
        }


        [[nodiscard]] constexpr un_scalar_t kilojoules_per_mole() const
        {
            return convert_from_base(MolarEnergyUnit::KilojoulesPerMole);
        }

        [[nodiscard]] static constexpr MolarEnergy from_kilojoules_per_mole(const un_scalar_t value)
        {
            return MolarEnergy(value, MolarEnergyUnit::KilojoulesPerMole);
        }


        [[nodiscard]] constexpr un_scalar_t megajoules_per_mole() const
        {
            return convert_from_base(MolarEnergyUnit::MegajoulesPerMole);
        }

        [[nodiscard]] static constexpr MolarEnergy from_megajoules_per_mole(const un_scalar_t value)
        {
            return MolarEnergy(value, MolarEnergyUnit::MegajoulesPerMole);
        }


    private:
        [[nodiscard]] static constexpr un_scalar_t convert_to_base(un_scalar_t value, MolarEnergyUnit unit)
        {
            switch (unit)
            {

            case MolarEnergyUnit::JoulesPerMole:
                return value;

            case MolarEnergyUnit::KilojoulesPerMole:
                return (value * static_cast<un_scalar_t>(1e3));

            case MolarEnergyUnit::MegajoulesPerMole:
                return (value * static_cast<un_scalar_t>(1e6));

            }

            throw std::invalid_argument("Unknown MolarEnergy unit.");
        }

        [[nodiscard]] constexpr un_scalar_t convert_from_base(const MolarEnergyUnit unit) const
        {
            switch (unit)
            {

            case MolarEnergyUnit::JoulesPerMole:
                return value_;

            case MolarEnergyUnit::KilojoulesPerMole:
                return (value_) / static_cast<un_scalar_t>(1e3);

            case MolarEnergyUnit::MegajoulesPerMole:
                return (value_) / static_cast<un_scalar_t>(1e6);

            }

            throw std::invalid_argument("Unknown MolarEnergy unit.");
        }

        un_scalar_t value_;
    };
}
