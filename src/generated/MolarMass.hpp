#pragma once

#include <cstdint>
#include <numbers>
#include <stdexcept>
#include "UnitsNetConfig.h"

namespace unitsnet_cpp
{
    enum class MolarMassUnit : std::uint8_t
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
            const un_scalar_t value,
            const MolarMassUnit unit = MolarMassUnit::KilogramsPerMole)
            : value_(convert_to_base(value, unit))
        {
        }

        [[nodiscard]] constexpr un_scalar_t base_value() const noexcept
        {
            return value_;
        }

        [[nodiscard]] constexpr un_scalar_t value(const MolarMassUnit unit) const
        {
            return convert_from_base(unit);
        }

        [[nodiscard]] constexpr MolarMass operator+(const MolarMass other) const noexcept
        {
            return MolarMass(value_ + other.value_);
        }

        [[nodiscard]] constexpr MolarMass operator-(const MolarMass other) const noexcept
        {
            return MolarMass(value_ - other.value_);
        }

        [[nodiscard]] constexpr MolarMass operator*(const un_scalar_t scalar) const noexcept
        {
            return MolarMass(value_ * scalar);
        }

        [[nodiscard]] constexpr MolarMass operator/(const un_scalar_t scalar) const noexcept
        {
            return MolarMass(value_ / scalar);
        }

        [[nodiscard]] constexpr bool operator==(const MolarMass other) const noexcept
        {
            return value_ == other.value_;
        }

        [[nodiscard]] constexpr bool operator<(const MolarMass other) const noexcept
        {
            return value_ < other.value_;
        }


        [[nodiscard]] constexpr un_scalar_t grams_per_mole() const
        {
            return convert_from_base(MolarMassUnit::GramsPerMole);
        }

        [[nodiscard]] static constexpr MolarMass from_grams_per_mole(const un_scalar_t value)
        {
            return MolarMass(value, MolarMassUnit::GramsPerMole);
        }


        [[nodiscard]] constexpr un_scalar_t nanograms_per_mole() const
        {
            return convert_from_base(MolarMassUnit::NanogramsPerMole);
        }

        [[nodiscard]] static constexpr MolarMass from_nanograms_per_mole(const un_scalar_t value)
        {
            return MolarMass(value, MolarMassUnit::NanogramsPerMole);
        }


        [[nodiscard]] constexpr un_scalar_t micrograms_per_mole() const
        {
            return convert_from_base(MolarMassUnit::MicrogramsPerMole);
        }

        [[nodiscard]] static constexpr MolarMass from_micrograms_per_mole(const un_scalar_t value)
        {
            return MolarMass(value, MolarMassUnit::MicrogramsPerMole);
        }


        [[nodiscard]] constexpr un_scalar_t milligrams_per_mole() const
        {
            return convert_from_base(MolarMassUnit::MilligramsPerMole);
        }

        [[nodiscard]] static constexpr MolarMass from_milligrams_per_mole(const un_scalar_t value)
        {
            return MolarMass(value, MolarMassUnit::MilligramsPerMole);
        }


        [[nodiscard]] constexpr un_scalar_t centigrams_per_mole() const
        {
            return convert_from_base(MolarMassUnit::CentigramsPerMole);
        }

        [[nodiscard]] static constexpr MolarMass from_centigrams_per_mole(const un_scalar_t value)
        {
            return MolarMass(value, MolarMassUnit::CentigramsPerMole);
        }


        [[nodiscard]] constexpr un_scalar_t decigrams_per_mole() const
        {
            return convert_from_base(MolarMassUnit::DecigramsPerMole);
        }

        [[nodiscard]] static constexpr MolarMass from_decigrams_per_mole(const un_scalar_t value)
        {
            return MolarMass(value, MolarMassUnit::DecigramsPerMole);
        }


        [[nodiscard]] constexpr un_scalar_t decagrams_per_mole() const
        {
            return convert_from_base(MolarMassUnit::DecagramsPerMole);
        }

        [[nodiscard]] static constexpr MolarMass from_decagrams_per_mole(const un_scalar_t value)
        {
            return MolarMass(value, MolarMassUnit::DecagramsPerMole);
        }


        [[nodiscard]] constexpr un_scalar_t hectograms_per_mole() const
        {
            return convert_from_base(MolarMassUnit::HectogramsPerMole);
        }

        [[nodiscard]] static constexpr MolarMass from_hectograms_per_mole(const un_scalar_t value)
        {
            return MolarMass(value, MolarMassUnit::HectogramsPerMole);
        }


        [[nodiscard]] constexpr un_scalar_t kilograms_per_mole() const
        {
            return convert_from_base(MolarMassUnit::KilogramsPerMole);
        }

        [[nodiscard]] static constexpr MolarMass from_kilograms_per_mole(const un_scalar_t value)
        {
            return MolarMass(value, MolarMassUnit::KilogramsPerMole);
        }


        [[nodiscard]] constexpr un_scalar_t kilograms_per_kilomole() const
        {
            return convert_from_base(MolarMassUnit::KilogramsPerKilomole);
        }

        [[nodiscard]] static constexpr MolarMass from_kilograms_per_kilomole(const un_scalar_t value)
        {
            return MolarMass(value, MolarMassUnit::KilogramsPerKilomole);
        }


        [[nodiscard]] constexpr un_scalar_t pounds_per_mole() const
        {
            return convert_from_base(MolarMassUnit::PoundsPerMole);
        }

        [[nodiscard]] static constexpr MolarMass from_pounds_per_mole(const un_scalar_t value)
        {
            return MolarMass(value, MolarMassUnit::PoundsPerMole);
        }


        [[nodiscard]] constexpr un_scalar_t kilopounds_per_mole() const
        {
            return convert_from_base(MolarMassUnit::KilopoundsPerMole);
        }

        [[nodiscard]] static constexpr MolarMass from_kilopounds_per_mole(const un_scalar_t value)
        {
            return MolarMass(value, MolarMassUnit::KilopoundsPerMole);
        }


        [[nodiscard]] constexpr un_scalar_t megapounds_per_mole() const
        {
            return convert_from_base(MolarMassUnit::MegapoundsPerMole);
        }

        [[nodiscard]] static constexpr MolarMass from_megapounds_per_mole(const un_scalar_t value)
        {
            return MolarMass(value, MolarMassUnit::MegapoundsPerMole);
        }


    private:
        [[nodiscard]] static constexpr un_scalar_t convert_to_base(un_scalar_t value, MolarMassUnit unit)
        {
            switch (unit)
            {

            case MolarMassUnit::GramsPerMole:
                return value / 1e3;

            case MolarMassUnit::NanogramsPerMole:
                return (value * static_cast<un_scalar_t>(1e-9)) / 1e3;

            case MolarMassUnit::MicrogramsPerMole:
                return (value * static_cast<un_scalar_t>(1e-6)) / 1e3;

            case MolarMassUnit::MilligramsPerMole:
                return (value * static_cast<un_scalar_t>(1e-3)) / 1e3;

            case MolarMassUnit::CentigramsPerMole:
                return (value * static_cast<un_scalar_t>(1e-2)) / 1e3;

            case MolarMassUnit::DecigramsPerMole:
                return (value * static_cast<un_scalar_t>(1e-1)) / 1e3;

            case MolarMassUnit::DecagramsPerMole:
                return (value * static_cast<un_scalar_t>(1e1)) / 1e3;

            case MolarMassUnit::HectogramsPerMole:
                return (value * static_cast<un_scalar_t>(1e2)) / 1e3;

            case MolarMassUnit::KilogramsPerMole:
                return (value * static_cast<un_scalar_t>(1e3)) / 1e3;

            case MolarMassUnit::KilogramsPerKilomole:
                return value / 1e3;

            case MolarMassUnit::PoundsPerMole:
                return value * 0.45359237;

            case MolarMassUnit::KilopoundsPerMole:
                return (value * static_cast<un_scalar_t>(1e3)) * 0.45359237;

            case MolarMassUnit::MegapoundsPerMole:
                return (value * static_cast<un_scalar_t>(1e6)) * 0.45359237;

            }

            throw std::invalid_argument("Unknown MolarMass unit.");
        }

        [[nodiscard]] constexpr un_scalar_t convert_from_base(const MolarMassUnit unit) const
        {
            switch (unit)
            {

            case MolarMassUnit::GramsPerMole:
                return value_ * 1e3;

            case MolarMassUnit::NanogramsPerMole:
                return (value_ * 1e3) / static_cast<un_scalar_t>(1e-9);

            case MolarMassUnit::MicrogramsPerMole:
                return (value_ * 1e3) / static_cast<un_scalar_t>(1e-6);

            case MolarMassUnit::MilligramsPerMole:
                return (value_ * 1e3) / static_cast<un_scalar_t>(1e-3);

            case MolarMassUnit::CentigramsPerMole:
                return (value_ * 1e3) / static_cast<un_scalar_t>(1e-2);

            case MolarMassUnit::DecigramsPerMole:
                return (value_ * 1e3) / static_cast<un_scalar_t>(1e-1);

            case MolarMassUnit::DecagramsPerMole:
                return (value_ * 1e3) / static_cast<un_scalar_t>(1e1);

            case MolarMassUnit::HectogramsPerMole:
                return (value_ * 1e3) / static_cast<un_scalar_t>(1e2);

            case MolarMassUnit::KilogramsPerMole:
                return (value_ * 1e3) / static_cast<un_scalar_t>(1e3);

            case MolarMassUnit::KilogramsPerKilomole:
                return value_ * 1e3;

            case MolarMassUnit::PoundsPerMole:
                return value_ / 0.45359237;

            case MolarMassUnit::KilopoundsPerMole:
                return (value_ / 0.45359237) / static_cast<un_scalar_t>(1e3);

            case MolarMassUnit::MegapoundsPerMole:
                return (value_ / 0.45359237) / static_cast<un_scalar_t>(1e6);

            }

            throw std::invalid_argument("Unknown MolarMass unit.");
        }

        un_scalar_t value_;
    };
}
