#pragma once

#include <cstdint>
#include <numbers>
#include <stdexcept>

namespace unitsnet_cpp
{
    enum class MolarityUnit : std::uint16_t
    {
        MolesPerCubicMeter,
        KilomolesPerCubicMeter,
        MolesPerLiter,
        FemtomolesPerLiter,
        PicomolesPerLiter,
        NanomolesPerLiter,
        MicromolesPerLiter,
        MillimolesPerLiter,
        CentimolesPerLiter,
        DecimolesPerLiter,
        PoundMolesPerCubicFoot,
    };

    /// <summary>Molar concentration, also called molarity, amount concentration or substance concentration, is a measure of the concentration of a solute in a solution, or of any chemical species, in terms of amount of substance in a given volume.</summary>
    class Molarity
    {
    public:
        constexpr explicit Molarity(
            double value,
            MolarityUnit unit = MolarityUnit::MolesPerCubicMeter)
            : value_(convert_to_base(value, unit))
        {
        }

        [[nodiscard]] constexpr double base_value() const noexcept
        {
            return value_;
        }

        [[nodiscard]] constexpr double value(MolarityUnit unit) const
        {
            return convert_from_base(unit);
        }

        [[nodiscard]] constexpr Molarity operator+(Molarity other) const noexcept
        {
            return Molarity(value_ + other.value_);
        }

        [[nodiscard]] constexpr Molarity operator-(Molarity other) const noexcept
        {
            return Molarity(value_ - other.value_);
        }

        [[nodiscard]] constexpr Molarity operator*(double scalar) const noexcept
        {
            return Molarity(value_ * scalar);
        }

        [[nodiscard]] constexpr Molarity operator/(double scalar) const noexcept
        {
            return Molarity(value_ / scalar);
        }

        [[nodiscard]] constexpr bool operator==(Molarity other) const noexcept
        {
            return value_ == other.value_;
        }

        [[nodiscard]] constexpr bool operator<(Molarity other) const noexcept
        {
            return value_ < other.value_;
        }


        [[nodiscard]] constexpr double moles_per_cubic_meter() const
        {
            return convert_from_base(MolarityUnit::MolesPerCubicMeter);
        }

        [[nodiscard]] static constexpr Molarity from_moles_per_cubic_meter(double value)
        {
            return Molarity(value, MolarityUnit::MolesPerCubicMeter);
        }


        [[nodiscard]] constexpr double kilomoles_per_cubic_meter() const
        {
            return convert_from_base(MolarityUnit::KilomolesPerCubicMeter);
        }

        [[nodiscard]] static constexpr Molarity from_kilomoles_per_cubic_meter(double value)
        {
            return Molarity(value, MolarityUnit::KilomolesPerCubicMeter);
        }


        [[nodiscard]] constexpr double moles_per_liter() const
        {
            return convert_from_base(MolarityUnit::MolesPerLiter);
        }

        [[nodiscard]] static constexpr Molarity from_moles_per_liter(double value)
        {
            return Molarity(value, MolarityUnit::MolesPerLiter);
        }


        [[nodiscard]] constexpr double femtomoles_per_liter() const
        {
            return convert_from_base(MolarityUnit::FemtomolesPerLiter);
        }

        [[nodiscard]] static constexpr Molarity from_femtomoles_per_liter(double value)
        {
            return Molarity(value, MolarityUnit::FemtomolesPerLiter);
        }


        [[nodiscard]] constexpr double picomoles_per_liter() const
        {
            return convert_from_base(MolarityUnit::PicomolesPerLiter);
        }

        [[nodiscard]] static constexpr Molarity from_picomoles_per_liter(double value)
        {
            return Molarity(value, MolarityUnit::PicomolesPerLiter);
        }


        [[nodiscard]] constexpr double nanomoles_per_liter() const
        {
            return convert_from_base(MolarityUnit::NanomolesPerLiter);
        }

        [[nodiscard]] static constexpr Molarity from_nanomoles_per_liter(double value)
        {
            return Molarity(value, MolarityUnit::NanomolesPerLiter);
        }


        [[nodiscard]] constexpr double micromoles_per_liter() const
        {
            return convert_from_base(MolarityUnit::MicromolesPerLiter);
        }

        [[nodiscard]] static constexpr Molarity from_micromoles_per_liter(double value)
        {
            return Molarity(value, MolarityUnit::MicromolesPerLiter);
        }


        [[nodiscard]] constexpr double millimoles_per_liter() const
        {
            return convert_from_base(MolarityUnit::MillimolesPerLiter);
        }

        [[nodiscard]] static constexpr Molarity from_millimoles_per_liter(double value)
        {
            return Molarity(value, MolarityUnit::MillimolesPerLiter);
        }


        [[nodiscard]] constexpr double centimoles_per_liter() const
        {
            return convert_from_base(MolarityUnit::CentimolesPerLiter);
        }

        [[nodiscard]] static constexpr Molarity from_centimoles_per_liter(double value)
        {
            return Molarity(value, MolarityUnit::CentimolesPerLiter);
        }


        [[nodiscard]] constexpr double decimoles_per_liter() const
        {
            return convert_from_base(MolarityUnit::DecimolesPerLiter);
        }

        [[nodiscard]] static constexpr Molarity from_decimoles_per_liter(double value)
        {
            return Molarity(value, MolarityUnit::DecimolesPerLiter);
        }


        [[nodiscard]] constexpr double pound_moles_per_cubic_foot() const
        {
            return convert_from_base(MolarityUnit::PoundMolesPerCubicFoot);
        }

        [[nodiscard]] static constexpr Molarity from_pound_moles_per_cubic_foot(double value)
        {
            return Molarity(value, MolarityUnit::PoundMolesPerCubicFoot);
        }


    private:
        [[nodiscard]] static constexpr double convert_to_base(double value, MolarityUnit unit)
        {
            switch (unit)
            {

            case MolarityUnit::MolesPerCubicMeter:
                return value;

            case MolarityUnit::KilomolesPerCubicMeter:
                return (value * 1e3);

            case MolarityUnit::MolesPerLiter:
                return value / 1e-3;

            case MolarityUnit::FemtomolesPerLiter:
                return (value * 1e-15) / 1e-3;

            case MolarityUnit::PicomolesPerLiter:
                return (value * 1e-12) / 1e-3;

            case MolarityUnit::NanomolesPerLiter:
                return (value * 1e-9) / 1e-3;

            case MolarityUnit::MicromolesPerLiter:
                return (value * 1e-6) / 1e-3;

            case MolarityUnit::MillimolesPerLiter:
                return (value * 1e-3) / 1e-3;

            case MolarityUnit::CentimolesPerLiter:
                return (value * 1e-2) / 1e-3;

            case MolarityUnit::DecimolesPerLiter:
                return (value * 1e-1) / 1e-3;

            case MolarityUnit::PoundMolesPerCubicFoot:
                return value * 1000 * 0.45359237 / 0.028316846592;

            }

            throw std::invalid_argument("Unknown Molarity unit.");
        }

        [[nodiscard]] constexpr double convert_from_base(MolarityUnit unit) const
        {
            switch (unit)
            {

            case MolarityUnit::MolesPerCubicMeter:
                return value_;

            case MolarityUnit::KilomolesPerCubicMeter:
                return (value_) / 1e3;

            case MolarityUnit::MolesPerLiter:
                return value_ * 1e-3;

            case MolarityUnit::FemtomolesPerLiter:
                return (value_ * 1e-3) / 1e-15;

            case MolarityUnit::PicomolesPerLiter:
                return (value_ * 1e-3) / 1e-12;

            case MolarityUnit::NanomolesPerLiter:
                return (value_ * 1e-3) / 1e-9;

            case MolarityUnit::MicromolesPerLiter:
                return (value_ * 1e-3) / 1e-6;

            case MolarityUnit::MillimolesPerLiter:
                return (value_ * 1e-3) / 1e-3;

            case MolarityUnit::CentimolesPerLiter:
                return (value_ * 1e-3) / 1e-2;

            case MolarityUnit::DecimolesPerLiter:
                return (value_ * 1e-3) / 1e-1;

            case MolarityUnit::PoundMolesPerCubicFoot:
                return value_ / (1000 * 0.45359237 / 0.028316846592);

            }

            throw std::invalid_argument("Unknown Molarity unit.");
        }

        double value_;
    };
}
