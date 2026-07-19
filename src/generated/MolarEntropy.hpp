#pragma once

#include <cstdint>
#include <numbers>
#include <stdexcept>
#include "UnitsNetConfig.h"

namespace unitsnet_cpp
{
    enum class MolarEntropyUnit : std::uint8_t
    {
        JoulesPerMoleKelvin,
        KilojoulesPerMoleKelvin,
        MegajoulesPerMoleKelvin,
    };

    /// <summary>Molar entropy is amount of energy required to increase temperature of 1 mole substance by 1 Kelvin.</summary>
    class MolarEntropy
    {
    public:
        constexpr explicit MolarEntropy(
            const un_scalar_t value,
            const MolarEntropyUnit unit = MolarEntropyUnit::JoulesPerMoleKelvin)
            : value_(convert_to_base(value, unit))
        {
        }

        [[nodiscard]] constexpr un_scalar_t base_value() const noexcept
        {
            return value_;
        }

        [[nodiscard]] constexpr un_scalar_t value(const MolarEntropyUnit unit) const
        {
            return convert_from_base(unit);
        }

        [[nodiscard]] constexpr MolarEntropy operator+(const MolarEntropy other) const noexcept
        {
            return MolarEntropy(value_ + other.value_);
        }

        [[nodiscard]] constexpr MolarEntropy operator-(const MolarEntropy other) const noexcept
        {
            return MolarEntropy(value_ - other.value_);
        }

        [[nodiscard]] constexpr MolarEntropy operator*(const un_scalar_t scalar) const noexcept
        {
            return MolarEntropy(value_ * scalar);
        }

        [[nodiscard]] constexpr MolarEntropy operator/(const un_scalar_t scalar) const noexcept
        {
            return MolarEntropy(value_ / scalar);
        }

        [[nodiscard]] constexpr bool operator==(const MolarEntropy other) const noexcept
        {
            return value_ == other.value_;
        }

        [[nodiscard]] constexpr bool operator<(const MolarEntropy other) const noexcept
        {
            return value_ < other.value_;
        }


        [[nodiscard]] constexpr un_scalar_t joules_per_mole_kelvin() const
        {
            return convert_from_base(MolarEntropyUnit::JoulesPerMoleKelvin);
        }

        [[nodiscard]] static constexpr MolarEntropy from_joules_per_mole_kelvin(const un_scalar_t value)
        {
            return MolarEntropy(value, MolarEntropyUnit::JoulesPerMoleKelvin);
        }


        [[nodiscard]] constexpr un_scalar_t kilojoules_per_mole_kelvin() const
        {
            return convert_from_base(MolarEntropyUnit::KilojoulesPerMoleKelvin);
        }

        [[nodiscard]] static constexpr MolarEntropy from_kilojoules_per_mole_kelvin(const un_scalar_t value)
        {
            return MolarEntropy(value, MolarEntropyUnit::KilojoulesPerMoleKelvin);
        }


        [[nodiscard]] constexpr un_scalar_t megajoules_per_mole_kelvin() const
        {
            return convert_from_base(MolarEntropyUnit::MegajoulesPerMoleKelvin);
        }

        [[nodiscard]] static constexpr MolarEntropy from_megajoules_per_mole_kelvin(const un_scalar_t value)
        {
            return MolarEntropy(value, MolarEntropyUnit::MegajoulesPerMoleKelvin);
        }


    private:
        [[nodiscard]] static constexpr un_scalar_t convert_to_base(un_scalar_t value, MolarEntropyUnit unit)
        {
            switch (unit)
            {

            case MolarEntropyUnit::JoulesPerMoleKelvin:
                return value;

            case MolarEntropyUnit::KilojoulesPerMoleKelvin:
                return (value * static_cast<un_scalar_t>(1e3));

            case MolarEntropyUnit::MegajoulesPerMoleKelvin:
                return (value * static_cast<un_scalar_t>(1e6));

            }

            throw std::invalid_argument("Unknown MolarEntropy unit.");
        }

        [[nodiscard]] constexpr un_scalar_t convert_from_base(const MolarEntropyUnit unit) const
        {
            switch (unit)
            {

            case MolarEntropyUnit::JoulesPerMoleKelvin:
                return value_;

            case MolarEntropyUnit::KilojoulesPerMoleKelvin:
                return (value_) / static_cast<un_scalar_t>(1e3);

            case MolarEntropyUnit::MegajoulesPerMoleKelvin:
                return (value_) / static_cast<un_scalar_t>(1e6);

            }

            throw std::invalid_argument("Unknown MolarEntropy unit.");
        }

        un_scalar_t value_;
    };
}
