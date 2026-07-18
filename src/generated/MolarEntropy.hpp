#pragma once

#include <cstdint>
#include <numbers>
#include <stdexcept>

namespace unitsnet_cpp
{
    enum class MolarEntropyUnit : std::uint16_t
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
            double value,
            MolarEntropyUnit unit = MolarEntropyUnit::JoulesPerMoleKelvin)
            : value_(convert_to_base(value, unit))
        {
        }

        [[nodiscard]] constexpr double base_value() const noexcept
        {
            return value_;
        }

        [[nodiscard]] constexpr double value(MolarEntropyUnit unit) const
        {
            return convert_from_base(unit);
        }

        [[nodiscard]] constexpr MolarEntropy operator+(MolarEntropy other) const noexcept
        {
            return MolarEntropy(value_ + other.value_);
        }

        [[nodiscard]] constexpr MolarEntropy operator-(MolarEntropy other) const noexcept
        {
            return MolarEntropy(value_ - other.value_);
        }

        [[nodiscard]] constexpr MolarEntropy operator*(double scalar) const noexcept
        {
            return MolarEntropy(value_ * scalar);
        }

        [[nodiscard]] constexpr MolarEntropy operator/(double scalar) const noexcept
        {
            return MolarEntropy(value_ / scalar);
        }

        [[nodiscard]] constexpr bool operator==(MolarEntropy other) const noexcept
        {
            return value_ == other.value_;
        }

        [[nodiscard]] constexpr bool operator<(MolarEntropy other) const noexcept
        {
            return value_ < other.value_;
        }


        [[nodiscard]] constexpr double joules_per_mole_kelvin() const
        {
            return convert_from_base(MolarEntropyUnit::JoulesPerMoleKelvin);
        }

        [[nodiscard]] static constexpr MolarEntropy from_joules_per_mole_kelvin(double value)
        {
            return MolarEntropy(value, MolarEntropyUnit::JoulesPerMoleKelvin);
        }


        [[nodiscard]] constexpr double kilojoules_per_mole_kelvin() const
        {
            return convert_from_base(MolarEntropyUnit::KilojoulesPerMoleKelvin);
        }

        [[nodiscard]] static constexpr MolarEntropy from_kilojoules_per_mole_kelvin(double value)
        {
            return MolarEntropy(value, MolarEntropyUnit::KilojoulesPerMoleKelvin);
        }


        [[nodiscard]] constexpr double megajoules_per_mole_kelvin() const
        {
            return convert_from_base(MolarEntropyUnit::MegajoulesPerMoleKelvin);
        }

        [[nodiscard]] static constexpr MolarEntropy from_megajoules_per_mole_kelvin(double value)
        {
            return MolarEntropy(value, MolarEntropyUnit::MegajoulesPerMoleKelvin);
        }


    private:
        [[nodiscard]] static constexpr double convert_to_base(double value, MolarEntropyUnit unit)
        {
            switch (unit)
            {

            case MolarEntropyUnit::JoulesPerMoleKelvin:
                return value;

            case MolarEntropyUnit::KilojoulesPerMoleKelvin:
                return (value * 1e3);

            case MolarEntropyUnit::MegajoulesPerMoleKelvin:
                return (value * 1e6);

            }

            throw std::invalid_argument("Unknown MolarEntropy unit.");
        }

        [[nodiscard]] constexpr double convert_from_base(MolarEntropyUnit unit) const
        {
            switch (unit)
            {

            case MolarEntropyUnit::JoulesPerMoleKelvin:
                return value_;

            case MolarEntropyUnit::KilojoulesPerMoleKelvin:
                return (value_) / 1e3;

            case MolarEntropyUnit::MegajoulesPerMoleKelvin:
                return (value_) / 1e6;

            }

            throw std::invalid_argument("Unknown MolarEntropy unit.");
        }

        double value_;
    };
}
