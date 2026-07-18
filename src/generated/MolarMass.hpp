#pragma once

#include <cstdint>
#include <numbers>
#include <stdexcept>

namespace unitsnet_cpp
{
    enum class MolarMassUnit : std::uint16_t
    {
        GramsPerMole,
        NanogramsPerMole,
        MicrogramsPerMole,
        MilligramsPerMole,
        CentigramsPerMole,
        DecigramsPerMole,
        DecagramsPerMole,
        HectogramsPerMole,
        KilogramsPerMole,
        KilogramsPerKilomole,
        PoundsPerMole,
        KilopoundsPerMole,
        MegapoundsPerMole,
    };

    /// <summary>In chemistry, the molar mass M is a physical property defined as the mass of a given substance (chemical element or chemical compound) divided by the amount of substance.</summary>
    class MolarMass
    {
    public:
        constexpr explicit MolarMass(
            double value,
            MolarMassUnit unit = MolarMassUnit::KilogramsPerMole)
            : value_(convert_to_base(value, unit))
        {
        }

        [[nodiscard]] constexpr double base_value() const noexcept
        {
            return value_;
        }

        [[nodiscard]] constexpr double value(MolarMassUnit unit) const
        {
            return convert_from_base(unit);
        }

        [[nodiscard]] constexpr MolarMass operator+(MolarMass other) const noexcept
        {
            return MolarMass(value_ + other.value_);
        }

        [[nodiscard]] constexpr MolarMass operator-(MolarMass other) const noexcept
        {
            return MolarMass(value_ - other.value_);
        }

        [[nodiscard]] constexpr MolarMass operator*(double scalar) const noexcept
        {
            return MolarMass(value_ * scalar);
        }

        [[nodiscard]] constexpr MolarMass operator/(double scalar) const noexcept
        {
            return MolarMass(value_ / scalar);
        }

        [[nodiscard]] constexpr bool operator==(MolarMass other) const noexcept
        {
            return value_ == other.value_;
        }

        [[nodiscard]] constexpr bool operator<(MolarMass other) const noexcept
        {
            return value_ < other.value_;
        }


        [[nodiscard]] constexpr double grams_per_mole() const
        {
            return convert_from_base(MolarMassUnit::GramsPerMole);
        }

        [[nodiscard]] static constexpr MolarMass from_grams_per_mole(double value)
        {
            return MolarMass(value, MolarMassUnit::GramsPerMole);
        }


        [[nodiscard]] constexpr double nanograms_per_mole() const
        {
            return convert_from_base(MolarMassUnit::NanogramsPerMole);
        }

        [[nodiscard]] static constexpr MolarMass from_nanograms_per_mole(double value)
        {
            return MolarMass(value, MolarMassUnit::NanogramsPerMole);
        }


        [[nodiscard]] constexpr double micrograms_per_mole() const
        {
            return convert_from_base(MolarMassUnit::MicrogramsPerMole);
        }

        [[nodiscard]] static constexpr MolarMass from_micrograms_per_mole(double value)
        {
            return MolarMass(value, MolarMassUnit::MicrogramsPerMole);
        }


        [[nodiscard]] constexpr double milligrams_per_mole() const
        {
            return convert_from_base(MolarMassUnit::MilligramsPerMole);
        }

        [[nodiscard]] static constexpr MolarMass from_milligrams_per_mole(double value)
        {
            return MolarMass(value, MolarMassUnit::MilligramsPerMole);
        }


        [[nodiscard]] constexpr double centigrams_per_mole() const
        {
            return convert_from_base(MolarMassUnit::CentigramsPerMole);
        }

        [[nodiscard]] static constexpr MolarMass from_centigrams_per_mole(double value)
        {
            return MolarMass(value, MolarMassUnit::CentigramsPerMole);
        }


        [[nodiscard]] constexpr double decigrams_per_mole() const
        {
            return convert_from_base(MolarMassUnit::DecigramsPerMole);
        }

        [[nodiscard]] static constexpr MolarMass from_decigrams_per_mole(double value)
        {
            return MolarMass(value, MolarMassUnit::DecigramsPerMole);
        }


        [[nodiscard]] constexpr double decagrams_per_mole() const
        {
            return convert_from_base(MolarMassUnit::DecagramsPerMole);
        }

        [[nodiscard]] static constexpr MolarMass from_decagrams_per_mole(double value)
        {
            return MolarMass(value, MolarMassUnit::DecagramsPerMole);
        }


        [[nodiscard]] constexpr double hectograms_per_mole() const
        {
            return convert_from_base(MolarMassUnit::HectogramsPerMole);
        }

        [[nodiscard]] static constexpr MolarMass from_hectograms_per_mole(double value)
        {
            return MolarMass(value, MolarMassUnit::HectogramsPerMole);
        }


        [[nodiscard]] constexpr double kilograms_per_mole() const
        {
            return convert_from_base(MolarMassUnit::KilogramsPerMole);
        }

        [[nodiscard]] static constexpr MolarMass from_kilograms_per_mole(double value)
        {
            return MolarMass(value, MolarMassUnit::KilogramsPerMole);
        }


        [[nodiscard]] constexpr double kilograms_per_kilomole() const
        {
            return convert_from_base(MolarMassUnit::KilogramsPerKilomole);
        }

        [[nodiscard]] static constexpr MolarMass from_kilograms_per_kilomole(double value)
        {
            return MolarMass(value, MolarMassUnit::KilogramsPerKilomole);
        }


        [[nodiscard]] constexpr double pounds_per_mole() const
        {
            return convert_from_base(MolarMassUnit::PoundsPerMole);
        }

        [[nodiscard]] static constexpr MolarMass from_pounds_per_mole(double value)
        {
            return MolarMass(value, MolarMassUnit::PoundsPerMole);
        }


        [[nodiscard]] constexpr double kilopounds_per_mole() const
        {
            return convert_from_base(MolarMassUnit::KilopoundsPerMole);
        }

        [[nodiscard]] static constexpr MolarMass from_kilopounds_per_mole(double value)
        {
            return MolarMass(value, MolarMassUnit::KilopoundsPerMole);
        }


        [[nodiscard]] constexpr double megapounds_per_mole() const
        {
            return convert_from_base(MolarMassUnit::MegapoundsPerMole);
        }

        [[nodiscard]] static constexpr MolarMass from_megapounds_per_mole(double value)
        {
            return MolarMass(value, MolarMassUnit::MegapoundsPerMole);
        }


    private:
        [[nodiscard]] static constexpr double convert_to_base(double value, MolarMassUnit unit)
        {
            switch (unit)
            {

            case MolarMassUnit::GramsPerMole:
                return value / 1e3;

            case MolarMassUnit::NanogramsPerMole:
                return (value * 1e-9) / 1e3;

            case MolarMassUnit::MicrogramsPerMole:
                return (value * 1e-6) / 1e3;

            case MolarMassUnit::MilligramsPerMole:
                return (value * 1e-3) / 1e3;

            case MolarMassUnit::CentigramsPerMole:
                return (value * 1e-2) / 1e3;

            case MolarMassUnit::DecigramsPerMole:
                return (value * 1e-1) / 1e3;

            case MolarMassUnit::DecagramsPerMole:
                return (value * 1e1) / 1e3;

            case MolarMassUnit::HectogramsPerMole:
                return (value * 1e2) / 1e3;

            case MolarMassUnit::KilogramsPerMole:
                return (value * 1e3) / 1e3;

            case MolarMassUnit::KilogramsPerKilomole:
                return value / 1e3;

            case MolarMassUnit::PoundsPerMole:
                return value * 0.45359237;

            case MolarMassUnit::KilopoundsPerMole:
                return (value * 1e3) * 0.45359237;

            case MolarMassUnit::MegapoundsPerMole:
                return (value * 1e6) * 0.45359237;

            }

            throw std::invalid_argument("Unknown MolarMass unit.");
        }

        [[nodiscard]] constexpr double convert_from_base(MolarMassUnit unit) const
        {
            switch (unit)
            {

            case MolarMassUnit::GramsPerMole:
                return value_ * 1e3;

            case MolarMassUnit::NanogramsPerMole:
                return (value_ * 1e3) / 1e-9;

            case MolarMassUnit::MicrogramsPerMole:
                return (value_ * 1e3) / 1e-6;

            case MolarMassUnit::MilligramsPerMole:
                return (value_ * 1e3) / 1e-3;

            case MolarMassUnit::CentigramsPerMole:
                return (value_ * 1e3) / 1e-2;

            case MolarMassUnit::DecigramsPerMole:
                return (value_ * 1e3) / 1e-1;

            case MolarMassUnit::DecagramsPerMole:
                return (value_ * 1e3) / 1e1;

            case MolarMassUnit::HectogramsPerMole:
                return (value_ * 1e3) / 1e2;

            case MolarMassUnit::KilogramsPerMole:
                return (value_ * 1e3) / 1e3;

            case MolarMassUnit::KilogramsPerKilomole:
                return value_ * 1e3;

            case MolarMassUnit::PoundsPerMole:
                return value_ / 0.45359237;

            case MolarMassUnit::KilopoundsPerMole:
                return (value_ / 0.45359237) / 1e3;

            case MolarMassUnit::MegapoundsPerMole:
                return (value_ / 0.45359237) / 1e6;

            }

            throw std::invalid_argument("Unknown MolarMass unit.");
        }

        double value_;
    };
}
