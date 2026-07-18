#pragma once

#include <cstdint>
#include <numbers>
#include <stdexcept>

namespace unitsnet_cpp
{
    enum class MolalityUnit : std::uint16_t
    {
        MolesPerKilogram,
        MillimolesPerKilogram,
        MolesPerGram,
    };

    /// <summary>Molality is a measure of the amount of solute in a solution relative to a given mass of solvent.</summary>
    class Molality
    {
    public:
        constexpr explicit Molality(
            double value,
            MolalityUnit unit = MolalityUnit::MolesPerKilogram)
            : value_(convert_to_base(value, unit))
        {
        }

        [[nodiscard]] constexpr double base_value() const noexcept
        {
            return value_;
        }

        [[nodiscard]] constexpr double value(MolalityUnit unit) const
        {
            return convert_from_base(unit);
        }

        [[nodiscard]] constexpr Molality operator+(Molality other) const noexcept
        {
            return Molality(value_ + other.value_);
        }

        [[nodiscard]] constexpr Molality operator-(Molality other) const noexcept
        {
            return Molality(value_ - other.value_);
        }

        [[nodiscard]] constexpr Molality operator*(double scalar) const noexcept
        {
            return Molality(value_ * scalar);
        }

        [[nodiscard]] constexpr Molality operator/(double scalar) const noexcept
        {
            return Molality(value_ / scalar);
        }

        [[nodiscard]] constexpr bool operator==(Molality other) const noexcept
        {
            return value_ == other.value_;
        }

        [[nodiscard]] constexpr bool operator<(Molality other) const noexcept
        {
            return value_ < other.value_;
        }


        [[nodiscard]] constexpr double moles_per_kilogram() const
        {
            return convert_from_base(MolalityUnit::MolesPerKilogram);
        }

        [[nodiscard]] static constexpr Molality from_moles_per_kilogram(double value)
        {
            return Molality(value, MolalityUnit::MolesPerKilogram);
        }


        [[nodiscard]] constexpr double millimoles_per_kilogram() const
        {
            return convert_from_base(MolalityUnit::MillimolesPerKilogram);
        }

        [[nodiscard]] static constexpr Molality from_millimoles_per_kilogram(double value)
        {
            return Molality(value, MolalityUnit::MillimolesPerKilogram);
        }


        [[nodiscard]] constexpr double moles_per_gram() const
        {
            return convert_from_base(MolalityUnit::MolesPerGram);
        }

        [[nodiscard]] static constexpr Molality from_moles_per_gram(double value)
        {
            return Molality(value, MolalityUnit::MolesPerGram);
        }


    private:
        [[nodiscard]] static constexpr double convert_to_base(double value, MolalityUnit unit)
        {
            switch (unit)
            {

            case MolalityUnit::MolesPerKilogram:
                return value;

            case MolalityUnit::MillimolesPerKilogram:
                return (value * 1e-3);

            case MolalityUnit::MolesPerGram:
                return value / 1e-3;

            }

            throw std::invalid_argument("Unknown Molality unit.");
        }

        [[nodiscard]] constexpr double convert_from_base(MolalityUnit unit) const
        {
            switch (unit)
            {

            case MolalityUnit::MolesPerKilogram:
                return value_;

            case MolalityUnit::MillimolesPerKilogram:
                return (value_) / 1e-3;

            case MolalityUnit::MolesPerGram:
                return value_ * 1e-3;

            }

            throw std::invalid_argument("Unknown Molality unit.");
        }

        double value_;
    };
}
