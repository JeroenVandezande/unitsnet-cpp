#pragma once

#include <cstdint>
#include <numbers>
#include <stdexcept>
#include "UnitsNetConfig.h"

namespace unitsnet_cpp
{
    enum class DensityUnit : std::uint8_t
    {
        GramsPerCubicMillimeter,
        KilogramsPerCubicMillimeter,
        GramsPerCubicCentimeter,
        KilogramsPerCubicCentimeter,
        GramsPerCubicMeter,
        KilogramsPerCubicMeter,
        MilligramsPerCubicMeter,
        MicrogramsPerCubicMeter,
        PoundsPerCubicInch,
        KilopoundsPerCubicInch,
        PoundsPerCubicFoot,
        KilopoundsPerCubicFoot,
        PoundsPerCubicYard,
        KilopoundsPerCubicYard,
        TonnesPerCubicMillimeter,
        TonnesPerCubicCentimeter,
        TonnesPerCubicMeter,
        SlugsPerCubicFoot,
        GramsPerLiter,
        FemtogramsPerLiter,
        PicogramsPerLiter,
        NanogramsPerLiter,
        MicrogramsPerLiter,
        MilligramsPerLiter,
        CentigramsPerLiter,
        DecigramsPerLiter,
        GramsPerDeciliter,
        FemtogramsPerDeciliter,
        PicogramsPerDeciliter,
        NanogramsPerDeciliter,
        MicrogramsPerDeciliter,
        MilligramsPerDeciliter,
        CentigramsPerDeciliter,
        DecigramsPerDeciliter,
        GramsPerMilliliter,
        FemtogramsPerMilliliter,
        PicogramsPerMilliliter,
        NanogramsPerMilliliter,
        MicrogramsPerMilliliter,
        MilligramsPerMilliliter,
        CentigramsPerMilliliter,
        DecigramsPerMilliliter,
        PoundsPerUSGallon,
        PoundsPerImperialGallon,
        KilogramsPerLiter,
        TonnesPerCubicFoot,
        TonnesPerCubicInch,
        GramsPerCubicFoot,
        GramsPerCubicInch,
        PoundsPerCubicMeter,
        PoundsPerCubicCentimeter,
        PoundsPerCubicMillimeter,
        SlugsPerCubicMeter,
        SlugsPerCubicCentimeter,
        SlugsPerCubicMillimeter,
        SlugsPerCubicInch,
    };

    /// <summary>The density, or more precisely, the volumetric mass density, of a substance is its mass per unit volume.</summary>
    class Density
    {
    public:
        constexpr explicit Density(
            const un_scalar_t value,
            const DensityUnit unit = DensityUnit::KilogramsPerCubicMeter)
            : value_(convert_to_base(value, unit))
        {
        }

        [[nodiscard]] constexpr un_scalar_t base_value() const noexcept
        {
            return value_;
        }

        [[nodiscard]] constexpr un_scalar_t value(const DensityUnit unit) const
        {
            return convert_from_base(unit);
        }

        [[nodiscard]] constexpr Density operator+(const Density other) const noexcept
        {
            return Density(value_ + other.value_);
        }

        [[nodiscard]] constexpr Density operator-(const Density other) const noexcept
        {
            return Density(value_ - other.value_);
        }

        [[nodiscard]] constexpr Density operator*(const un_scalar_t scalar) const noexcept
        {
            return Density(value_ * scalar);
        }

        [[nodiscard]] constexpr Density operator/(const un_scalar_t scalar) const noexcept
        {
            return Density(value_ / scalar);
        }

        [[nodiscard]] constexpr bool operator==(const Density other) const noexcept
        {
            return value_ == other.value_;
        }

        [[nodiscard]] constexpr bool operator<(const Density other) const noexcept
        {
            return value_ < other.value_;
        }


        [[nodiscard]] constexpr un_scalar_t grams_per_cubic_millimeter() const
        {
            return convert_from_base(DensityUnit::GramsPerCubicMillimeter);
        }

        [[nodiscard]] static constexpr Density from_grams_per_cubic_millimeter(const un_scalar_t value)
        {
            return Density(value, DensityUnit::GramsPerCubicMillimeter);
        }


        [[nodiscard]] constexpr un_scalar_t kilograms_per_cubic_millimeter() const
        {
            return convert_from_base(DensityUnit::KilogramsPerCubicMillimeter);
        }

        [[nodiscard]] static constexpr Density from_kilograms_per_cubic_millimeter(const un_scalar_t value)
        {
            return Density(value, DensityUnit::KilogramsPerCubicMillimeter);
        }


        [[nodiscard]] constexpr un_scalar_t grams_per_cubic_centimeter() const
        {
            return convert_from_base(DensityUnit::GramsPerCubicCentimeter);
        }

        [[nodiscard]] static constexpr Density from_grams_per_cubic_centimeter(const un_scalar_t value)
        {
            return Density(value, DensityUnit::GramsPerCubicCentimeter);
        }


        [[nodiscard]] constexpr un_scalar_t kilograms_per_cubic_centimeter() const
        {
            return convert_from_base(DensityUnit::KilogramsPerCubicCentimeter);
        }

        [[nodiscard]] static constexpr Density from_kilograms_per_cubic_centimeter(const un_scalar_t value)
        {
            return Density(value, DensityUnit::KilogramsPerCubicCentimeter);
        }


        [[nodiscard]] constexpr un_scalar_t grams_per_cubic_meter() const
        {
            return convert_from_base(DensityUnit::GramsPerCubicMeter);
        }

        [[nodiscard]] static constexpr Density from_grams_per_cubic_meter(const un_scalar_t value)
        {
            return Density(value, DensityUnit::GramsPerCubicMeter);
        }


        [[nodiscard]] constexpr un_scalar_t kilograms_per_cubic_meter() const
        {
            return convert_from_base(DensityUnit::KilogramsPerCubicMeter);
        }

        [[nodiscard]] static constexpr Density from_kilograms_per_cubic_meter(const un_scalar_t value)
        {
            return Density(value, DensityUnit::KilogramsPerCubicMeter);
        }


        [[nodiscard]] constexpr un_scalar_t milligrams_per_cubic_meter() const
        {
            return convert_from_base(DensityUnit::MilligramsPerCubicMeter);
        }

        [[nodiscard]] static constexpr Density from_milligrams_per_cubic_meter(const un_scalar_t value)
        {
            return Density(value, DensityUnit::MilligramsPerCubicMeter);
        }


        [[nodiscard]] constexpr un_scalar_t micrograms_per_cubic_meter() const
        {
            return convert_from_base(DensityUnit::MicrogramsPerCubicMeter);
        }

        [[nodiscard]] static constexpr Density from_micrograms_per_cubic_meter(const un_scalar_t value)
        {
            return Density(value, DensityUnit::MicrogramsPerCubicMeter);
        }


        [[nodiscard]] constexpr un_scalar_t pounds_per_cubic_inch() const
        {
            return convert_from_base(DensityUnit::PoundsPerCubicInch);
        }

        [[nodiscard]] static constexpr Density from_pounds_per_cubic_inch(const un_scalar_t value)
        {
            return Density(value, DensityUnit::PoundsPerCubicInch);
        }


        [[nodiscard]] constexpr un_scalar_t kilopounds_per_cubic_inch() const
        {
            return convert_from_base(DensityUnit::KilopoundsPerCubicInch);
        }

        [[nodiscard]] static constexpr Density from_kilopounds_per_cubic_inch(const un_scalar_t value)
        {
            return Density(value, DensityUnit::KilopoundsPerCubicInch);
        }


        [[nodiscard]] constexpr un_scalar_t pounds_per_cubic_foot() const
        {
            return convert_from_base(DensityUnit::PoundsPerCubicFoot);
        }

        [[nodiscard]] static constexpr Density from_pounds_per_cubic_foot(const un_scalar_t value)
        {
            return Density(value, DensityUnit::PoundsPerCubicFoot);
        }


        [[nodiscard]] constexpr un_scalar_t kilopounds_per_cubic_foot() const
        {
            return convert_from_base(DensityUnit::KilopoundsPerCubicFoot);
        }

        [[nodiscard]] static constexpr Density from_kilopounds_per_cubic_foot(const un_scalar_t value)
        {
            return Density(value, DensityUnit::KilopoundsPerCubicFoot);
        }


        [[nodiscard]] constexpr un_scalar_t pounds_per_cubic_yard() const
        {
            return convert_from_base(DensityUnit::PoundsPerCubicYard);
        }

        [[nodiscard]] static constexpr Density from_pounds_per_cubic_yard(const un_scalar_t value)
        {
            return Density(value, DensityUnit::PoundsPerCubicYard);
        }


        [[nodiscard]] constexpr un_scalar_t kilopounds_per_cubic_yard() const
        {
            return convert_from_base(DensityUnit::KilopoundsPerCubicYard);
        }

        [[nodiscard]] static constexpr Density from_kilopounds_per_cubic_yard(const un_scalar_t value)
        {
            return Density(value, DensityUnit::KilopoundsPerCubicYard);
        }


        [[nodiscard]] constexpr un_scalar_t tonnes_per_cubic_millimeter() const
        {
            return convert_from_base(DensityUnit::TonnesPerCubicMillimeter);
        }

        [[nodiscard]] static constexpr Density from_tonnes_per_cubic_millimeter(const un_scalar_t value)
        {
            return Density(value, DensityUnit::TonnesPerCubicMillimeter);
        }


        [[nodiscard]] constexpr un_scalar_t tonnes_per_cubic_centimeter() const
        {
            return convert_from_base(DensityUnit::TonnesPerCubicCentimeter);
        }

        [[nodiscard]] static constexpr Density from_tonnes_per_cubic_centimeter(const un_scalar_t value)
        {
            return Density(value, DensityUnit::TonnesPerCubicCentimeter);
        }


        [[nodiscard]] constexpr un_scalar_t tonnes_per_cubic_meter() const
        {
            return convert_from_base(DensityUnit::TonnesPerCubicMeter);
        }

        [[nodiscard]] static constexpr Density from_tonnes_per_cubic_meter(const un_scalar_t value)
        {
            return Density(value, DensityUnit::TonnesPerCubicMeter);
        }


        [[nodiscard]] constexpr un_scalar_t slugs_per_cubic_foot() const
        {
            return convert_from_base(DensityUnit::SlugsPerCubicFoot);
        }

        [[nodiscard]] static constexpr Density from_slugs_per_cubic_foot(const un_scalar_t value)
        {
            return Density(value, DensityUnit::SlugsPerCubicFoot);
        }


        [[nodiscard]] constexpr un_scalar_t grams_per_liter() const
        {
            return convert_from_base(DensityUnit::GramsPerLiter);
        }

        [[nodiscard]] static constexpr Density from_grams_per_liter(const un_scalar_t value)
        {
            return Density(value, DensityUnit::GramsPerLiter);
        }


        [[nodiscard]] constexpr un_scalar_t femtograms_per_liter() const
        {
            return convert_from_base(DensityUnit::FemtogramsPerLiter);
        }

        [[nodiscard]] static constexpr Density from_femtograms_per_liter(const un_scalar_t value)
        {
            return Density(value, DensityUnit::FemtogramsPerLiter);
        }


        [[nodiscard]] constexpr un_scalar_t picograms_per_liter() const
        {
            return convert_from_base(DensityUnit::PicogramsPerLiter);
        }

        [[nodiscard]] static constexpr Density from_picograms_per_liter(const un_scalar_t value)
        {
            return Density(value, DensityUnit::PicogramsPerLiter);
        }


        [[nodiscard]] constexpr un_scalar_t nanograms_per_liter() const
        {
            return convert_from_base(DensityUnit::NanogramsPerLiter);
        }

        [[nodiscard]] static constexpr Density from_nanograms_per_liter(const un_scalar_t value)
        {
            return Density(value, DensityUnit::NanogramsPerLiter);
        }


        [[nodiscard]] constexpr un_scalar_t micrograms_per_liter() const
        {
            return convert_from_base(DensityUnit::MicrogramsPerLiter);
        }

        [[nodiscard]] static constexpr Density from_micrograms_per_liter(const un_scalar_t value)
        {
            return Density(value, DensityUnit::MicrogramsPerLiter);
        }


        [[nodiscard]] constexpr un_scalar_t milligrams_per_liter() const
        {
            return convert_from_base(DensityUnit::MilligramsPerLiter);
        }

        [[nodiscard]] static constexpr Density from_milligrams_per_liter(const un_scalar_t value)
        {
            return Density(value, DensityUnit::MilligramsPerLiter);
        }


        [[nodiscard]] constexpr un_scalar_t centigrams_per_liter() const
        {
            return convert_from_base(DensityUnit::CentigramsPerLiter);
        }

        [[nodiscard]] static constexpr Density from_centigrams_per_liter(const un_scalar_t value)
        {
            return Density(value, DensityUnit::CentigramsPerLiter);
        }


        [[nodiscard]] constexpr un_scalar_t decigrams_per_liter() const
        {
            return convert_from_base(DensityUnit::DecigramsPerLiter);
        }

        [[nodiscard]] static constexpr Density from_decigrams_per_liter(const un_scalar_t value)
        {
            return Density(value, DensityUnit::DecigramsPerLiter);
        }


        [[nodiscard]] constexpr un_scalar_t grams_per_deciliter() const
        {
            return convert_from_base(DensityUnit::GramsPerDeciliter);
        }

        [[nodiscard]] static constexpr Density from_grams_per_deciliter(const un_scalar_t value)
        {
            return Density(value, DensityUnit::GramsPerDeciliter);
        }


        [[nodiscard]] constexpr un_scalar_t femtograms_per_deciliter() const
        {
            return convert_from_base(DensityUnit::FemtogramsPerDeciliter);
        }

        [[nodiscard]] static constexpr Density from_femtograms_per_deciliter(const un_scalar_t value)
        {
            return Density(value, DensityUnit::FemtogramsPerDeciliter);
        }


        [[nodiscard]] constexpr un_scalar_t picograms_per_deciliter() const
        {
            return convert_from_base(DensityUnit::PicogramsPerDeciliter);
        }

        [[nodiscard]] static constexpr Density from_picograms_per_deciliter(const un_scalar_t value)
        {
            return Density(value, DensityUnit::PicogramsPerDeciliter);
        }


        [[nodiscard]] constexpr un_scalar_t nanograms_per_deciliter() const
        {
            return convert_from_base(DensityUnit::NanogramsPerDeciliter);
        }

        [[nodiscard]] static constexpr Density from_nanograms_per_deciliter(const un_scalar_t value)
        {
            return Density(value, DensityUnit::NanogramsPerDeciliter);
        }


        [[nodiscard]] constexpr un_scalar_t micrograms_per_deciliter() const
        {
            return convert_from_base(DensityUnit::MicrogramsPerDeciliter);
        }

        [[nodiscard]] static constexpr Density from_micrograms_per_deciliter(const un_scalar_t value)
        {
            return Density(value, DensityUnit::MicrogramsPerDeciliter);
        }


        [[nodiscard]] constexpr un_scalar_t milligrams_per_deciliter() const
        {
            return convert_from_base(DensityUnit::MilligramsPerDeciliter);
        }

        [[nodiscard]] static constexpr Density from_milligrams_per_deciliter(const un_scalar_t value)
        {
            return Density(value, DensityUnit::MilligramsPerDeciliter);
        }


        [[nodiscard]] constexpr un_scalar_t centigrams_per_deciliter() const
        {
            return convert_from_base(DensityUnit::CentigramsPerDeciliter);
        }

        [[nodiscard]] static constexpr Density from_centigrams_per_deciliter(const un_scalar_t value)
        {
            return Density(value, DensityUnit::CentigramsPerDeciliter);
        }


        [[nodiscard]] constexpr un_scalar_t decigrams_per_deciliter() const
        {
            return convert_from_base(DensityUnit::DecigramsPerDeciliter);
        }

        [[nodiscard]] static constexpr Density from_decigrams_per_deciliter(const un_scalar_t value)
        {
            return Density(value, DensityUnit::DecigramsPerDeciliter);
        }


        [[nodiscard]] constexpr un_scalar_t grams_per_milliliter() const
        {
            return convert_from_base(DensityUnit::GramsPerMilliliter);
        }

        [[nodiscard]] static constexpr Density from_grams_per_milliliter(const un_scalar_t value)
        {
            return Density(value, DensityUnit::GramsPerMilliliter);
        }


        [[nodiscard]] constexpr un_scalar_t femtograms_per_milliliter() const
        {
            return convert_from_base(DensityUnit::FemtogramsPerMilliliter);
        }

        [[nodiscard]] static constexpr Density from_femtograms_per_milliliter(const un_scalar_t value)
        {
            return Density(value, DensityUnit::FemtogramsPerMilliliter);
        }


        [[nodiscard]] constexpr un_scalar_t picograms_per_milliliter() const
        {
            return convert_from_base(DensityUnit::PicogramsPerMilliliter);
        }

        [[nodiscard]] static constexpr Density from_picograms_per_milliliter(const un_scalar_t value)
        {
            return Density(value, DensityUnit::PicogramsPerMilliliter);
        }


        [[nodiscard]] constexpr un_scalar_t nanograms_per_milliliter() const
        {
            return convert_from_base(DensityUnit::NanogramsPerMilliliter);
        }

        [[nodiscard]] static constexpr Density from_nanograms_per_milliliter(const un_scalar_t value)
        {
            return Density(value, DensityUnit::NanogramsPerMilliliter);
        }


        [[nodiscard]] constexpr un_scalar_t micrograms_per_milliliter() const
        {
            return convert_from_base(DensityUnit::MicrogramsPerMilliliter);
        }

        [[nodiscard]] static constexpr Density from_micrograms_per_milliliter(const un_scalar_t value)
        {
            return Density(value, DensityUnit::MicrogramsPerMilliliter);
        }


        [[nodiscard]] constexpr un_scalar_t milligrams_per_milliliter() const
        {
            return convert_from_base(DensityUnit::MilligramsPerMilliliter);
        }

        [[nodiscard]] static constexpr Density from_milligrams_per_milliliter(const un_scalar_t value)
        {
            return Density(value, DensityUnit::MilligramsPerMilliliter);
        }


        [[nodiscard]] constexpr un_scalar_t centigrams_per_milliliter() const
        {
            return convert_from_base(DensityUnit::CentigramsPerMilliliter);
        }

        [[nodiscard]] static constexpr Density from_centigrams_per_milliliter(const un_scalar_t value)
        {
            return Density(value, DensityUnit::CentigramsPerMilliliter);
        }


        [[nodiscard]] constexpr un_scalar_t decigrams_per_milliliter() const
        {
            return convert_from_base(DensityUnit::DecigramsPerMilliliter);
        }

        [[nodiscard]] static constexpr Density from_decigrams_per_milliliter(const un_scalar_t value)
        {
            return Density(value, DensityUnit::DecigramsPerMilliliter);
        }


        [[nodiscard]] constexpr un_scalar_t pounds_per_u_s_gallon() const
        {
            return convert_from_base(DensityUnit::PoundsPerUSGallon);
        }

        [[nodiscard]] static constexpr Density from_pounds_per_u_s_gallon(const un_scalar_t value)
        {
            return Density(value, DensityUnit::PoundsPerUSGallon);
        }


        [[nodiscard]] constexpr un_scalar_t pounds_per_imperial_gallon() const
        {
            return convert_from_base(DensityUnit::PoundsPerImperialGallon);
        }

        [[nodiscard]] static constexpr Density from_pounds_per_imperial_gallon(const un_scalar_t value)
        {
            return Density(value, DensityUnit::PoundsPerImperialGallon);
        }


        [[nodiscard]] constexpr un_scalar_t kilograms_per_liter() const
        {
            return convert_from_base(DensityUnit::KilogramsPerLiter);
        }

        [[nodiscard]] static constexpr Density from_kilograms_per_liter(const un_scalar_t value)
        {
            return Density(value, DensityUnit::KilogramsPerLiter);
        }


        [[nodiscard]] constexpr un_scalar_t tonnes_per_cubic_foot() const
        {
            return convert_from_base(DensityUnit::TonnesPerCubicFoot);
        }

        [[nodiscard]] static constexpr Density from_tonnes_per_cubic_foot(const un_scalar_t value)
        {
            return Density(value, DensityUnit::TonnesPerCubicFoot);
        }


        [[nodiscard]] constexpr un_scalar_t tonnes_per_cubic_inch() const
        {
            return convert_from_base(DensityUnit::TonnesPerCubicInch);
        }

        [[nodiscard]] static constexpr Density from_tonnes_per_cubic_inch(const un_scalar_t value)
        {
            return Density(value, DensityUnit::TonnesPerCubicInch);
        }


        [[nodiscard]] constexpr un_scalar_t grams_per_cubic_foot() const
        {
            return convert_from_base(DensityUnit::GramsPerCubicFoot);
        }

        [[nodiscard]] static constexpr Density from_grams_per_cubic_foot(const un_scalar_t value)
        {
            return Density(value, DensityUnit::GramsPerCubicFoot);
        }


        [[nodiscard]] constexpr un_scalar_t grams_per_cubic_inch() const
        {
            return convert_from_base(DensityUnit::GramsPerCubicInch);
        }

        [[nodiscard]] static constexpr Density from_grams_per_cubic_inch(const un_scalar_t value)
        {
            return Density(value, DensityUnit::GramsPerCubicInch);
        }


        [[nodiscard]] constexpr un_scalar_t pounds_per_cubic_meter() const
        {
            return convert_from_base(DensityUnit::PoundsPerCubicMeter);
        }

        [[nodiscard]] static constexpr Density from_pounds_per_cubic_meter(const un_scalar_t value)
        {
            return Density(value, DensityUnit::PoundsPerCubicMeter);
        }


        [[nodiscard]] constexpr un_scalar_t pounds_per_cubic_centimeter() const
        {
            return convert_from_base(DensityUnit::PoundsPerCubicCentimeter);
        }

        [[nodiscard]] static constexpr Density from_pounds_per_cubic_centimeter(const un_scalar_t value)
        {
            return Density(value, DensityUnit::PoundsPerCubicCentimeter);
        }


        [[nodiscard]] constexpr un_scalar_t pounds_per_cubic_millimeter() const
        {
            return convert_from_base(DensityUnit::PoundsPerCubicMillimeter);
        }

        [[nodiscard]] static constexpr Density from_pounds_per_cubic_millimeter(const un_scalar_t value)
        {
            return Density(value, DensityUnit::PoundsPerCubicMillimeter);
        }


        [[nodiscard]] constexpr un_scalar_t slugs_per_cubic_meter() const
        {
            return convert_from_base(DensityUnit::SlugsPerCubicMeter);
        }

        [[nodiscard]] static constexpr Density from_slugs_per_cubic_meter(const un_scalar_t value)
        {
            return Density(value, DensityUnit::SlugsPerCubicMeter);
        }


        [[nodiscard]] constexpr un_scalar_t slugs_per_cubic_centimeter() const
        {
            return convert_from_base(DensityUnit::SlugsPerCubicCentimeter);
        }

        [[nodiscard]] static constexpr Density from_slugs_per_cubic_centimeter(const un_scalar_t value)
        {
            return Density(value, DensityUnit::SlugsPerCubicCentimeter);
        }


        [[nodiscard]] constexpr un_scalar_t slugs_per_cubic_millimeter() const
        {
            return convert_from_base(DensityUnit::SlugsPerCubicMillimeter);
        }

        [[nodiscard]] static constexpr Density from_slugs_per_cubic_millimeter(const un_scalar_t value)
        {
            return Density(value, DensityUnit::SlugsPerCubicMillimeter);
        }


        [[nodiscard]] constexpr un_scalar_t slugs_per_cubic_inch() const
        {
            return convert_from_base(DensityUnit::SlugsPerCubicInch);
        }

        [[nodiscard]] static constexpr Density from_slugs_per_cubic_inch(const un_scalar_t value)
        {
            return Density(value, DensityUnit::SlugsPerCubicInch);
        }


    private:
        [[nodiscard]] static constexpr un_scalar_t convert_to_base(un_scalar_t value, DensityUnit unit)
        {
            switch (unit)
            {

            case DensityUnit::GramsPerCubicMillimeter:
                return value / 1e-6;

            case DensityUnit::KilogramsPerCubicMillimeter:
                return (value * static_cast<un_scalar_t>(1e3)) / 1e-6;

            case DensityUnit::GramsPerCubicCentimeter:
                return value / 1e-3;

            case DensityUnit::KilogramsPerCubicCentimeter:
                return (value * static_cast<un_scalar_t>(1e3)) / 1e-3;

            case DensityUnit::GramsPerCubicMeter:
                return value / 1e3;

            case DensityUnit::KilogramsPerCubicMeter:
                return (value * static_cast<un_scalar_t>(1e3)) / 1e3;

            case DensityUnit::MilligramsPerCubicMeter:
                return (value * static_cast<un_scalar_t>(1e-3)) / 1e3;

            case DensityUnit::MicrogramsPerCubicMeter:
                return (value * static_cast<un_scalar_t>(1e-6)) / 1e3;

            case DensityUnit::PoundsPerCubicInch:
                return value * 0.45359237 / 1.6387064e-5;

            case DensityUnit::KilopoundsPerCubicInch:
                return (value * static_cast<un_scalar_t>(1e3)) * 0.45359237 / 1.6387064e-5;

            case DensityUnit::PoundsPerCubicFoot:
                return value * 0.45359237 / 0.028316846592;

            case DensityUnit::KilopoundsPerCubicFoot:
                return (value * static_cast<un_scalar_t>(1e3)) * 0.45359237 / 0.028316846592;

            case DensityUnit::PoundsPerCubicYard:
                return value * 0.45359237 / 0.764554857984;

            case DensityUnit::KilopoundsPerCubicYard:
                return (value * static_cast<un_scalar_t>(1e3)) * 0.45359237 / 0.764554857984;

            case DensityUnit::TonnesPerCubicMillimeter:
                return value / 1e-12;

            case DensityUnit::TonnesPerCubicCentimeter:
                return value / 1e-9;

            case DensityUnit::TonnesPerCubicMeter:
                return value / 0.001;

            case DensityUnit::SlugsPerCubicFoot:
                return value * (0.45359237 * 9.80665) / (0.3048 * 0.028316846592);

            case DensityUnit::GramsPerLiter:
                return value / 1;

            case DensityUnit::FemtogramsPerLiter:
                return (value * static_cast<un_scalar_t>(1e-15)) / 1;

            case DensityUnit::PicogramsPerLiter:
                return (value * static_cast<un_scalar_t>(1e-12)) / 1;

            case DensityUnit::NanogramsPerLiter:
                return (value * static_cast<un_scalar_t>(1e-9)) / 1;

            case DensityUnit::MicrogramsPerLiter:
                return (value * static_cast<un_scalar_t>(1e-6)) / 1;

            case DensityUnit::MilligramsPerLiter:
                return (value * static_cast<un_scalar_t>(1e-3)) / 1;

            case DensityUnit::CentigramsPerLiter:
                return (value * static_cast<un_scalar_t>(1e-2)) / 1;

            case DensityUnit::DecigramsPerLiter:
                return (value * static_cast<un_scalar_t>(1e-1)) / 1;

            case DensityUnit::GramsPerDeciliter:
                return value / 1e-1;

            case DensityUnit::FemtogramsPerDeciliter:
                return (value * static_cast<un_scalar_t>(1e-15)) / 1e-1;

            case DensityUnit::PicogramsPerDeciliter:
                return (value * static_cast<un_scalar_t>(1e-12)) / 1e-1;

            case DensityUnit::NanogramsPerDeciliter:
                return (value * static_cast<un_scalar_t>(1e-9)) / 1e-1;

            case DensityUnit::MicrogramsPerDeciliter:
                return (value * static_cast<un_scalar_t>(1e-6)) / 1e-1;

            case DensityUnit::MilligramsPerDeciliter:
                return (value * static_cast<un_scalar_t>(1e-3)) / 1e-1;

            case DensityUnit::CentigramsPerDeciliter:
                return (value * static_cast<un_scalar_t>(1e-2)) / 1e-1;

            case DensityUnit::DecigramsPerDeciliter:
                return (value * static_cast<un_scalar_t>(1e-1)) / 1e-1;

            case DensityUnit::GramsPerMilliliter:
                return value / 1e-3;

            case DensityUnit::FemtogramsPerMilliliter:
                return (value * static_cast<un_scalar_t>(1e-15)) / 1e-3;

            case DensityUnit::PicogramsPerMilliliter:
                return (value * static_cast<un_scalar_t>(1e-12)) / 1e-3;

            case DensityUnit::NanogramsPerMilliliter:
                return (value * static_cast<un_scalar_t>(1e-9)) / 1e-3;

            case DensityUnit::MicrogramsPerMilliliter:
                return (value * static_cast<un_scalar_t>(1e-6)) / 1e-3;

            case DensityUnit::MilligramsPerMilliliter:
                return (value * static_cast<un_scalar_t>(1e-3)) / 1e-3;

            case DensityUnit::CentigramsPerMilliliter:
                return (value * static_cast<un_scalar_t>(1e-2)) / 1e-3;

            case DensityUnit::DecigramsPerMilliliter:
                return (value * static_cast<un_scalar_t>(1e-1)) / 1e-3;

            case DensityUnit::PoundsPerUSGallon:
                return value * 0.45359237 / 0.003785411784;

            case DensityUnit::PoundsPerImperialGallon:
                return value * 0.45359237 / 0.00454609;

            case DensityUnit::KilogramsPerLiter:
                return value * 1e3;

            case DensityUnit::TonnesPerCubicFoot:
                return value * 1000 / 0.028316846592;

            case DensityUnit::TonnesPerCubicInch:
                return value * 1000 / 1.6387064e-5;

            case DensityUnit::GramsPerCubicFoot:
                return value * 0.001 / 0.028316846592;

            case DensityUnit::GramsPerCubicInch:
                return value * 0.001 / 1.6387064e-5;

            case DensityUnit::PoundsPerCubicMeter:
                return value * 0.45359237;

            case DensityUnit::PoundsPerCubicCentimeter:
                return value * 0.45359237e6;

            case DensityUnit::PoundsPerCubicMillimeter:
                return value * 0.45359237e9;

            case DensityUnit::SlugsPerCubicMeter:
                return value * 0.45359237 * 9.80665 / 0.3048;

            case DensityUnit::SlugsPerCubicCentimeter:
                return value * 0.45359237e6 * 9.80665 / 0.3048;

            case DensityUnit::SlugsPerCubicMillimeter:
                return value * 0.45359237e9 * 9.80665 / 0.3048;

            case DensityUnit::SlugsPerCubicInch:
                return value * (0.45359237 * 9.80665) / (0.3048 * 1.6387064e-5);

            }

            throw std::invalid_argument("Unknown Density unit.");
        }

        [[nodiscard]] constexpr un_scalar_t convert_from_base(const DensityUnit unit) const
        {
            switch (unit)
            {

            case DensityUnit::GramsPerCubicMillimeter:
                return value_ * 1e-6;

            case DensityUnit::KilogramsPerCubicMillimeter:
                return (value_ * 1e-6) / static_cast<un_scalar_t>(1e3);

            case DensityUnit::GramsPerCubicCentimeter:
                return value_ * 1e-3;

            case DensityUnit::KilogramsPerCubicCentimeter:
                return (value_ * 1e-3) / static_cast<un_scalar_t>(1e3);

            case DensityUnit::GramsPerCubicMeter:
                return value_ * 1e3;

            case DensityUnit::KilogramsPerCubicMeter:
                return (value_ * 1e3) / static_cast<un_scalar_t>(1e3);

            case DensityUnit::MilligramsPerCubicMeter:
                return (value_ * 1e3) / static_cast<un_scalar_t>(1e-3);

            case DensityUnit::MicrogramsPerCubicMeter:
                return (value_ * 1e3) / static_cast<un_scalar_t>(1e-6);

            case DensityUnit::PoundsPerCubicInch:
                return value_ * 1.6387064e-5 / 0.45359237;

            case DensityUnit::KilopoundsPerCubicInch:
                return (value_ * 1.6387064e-5 / 0.45359237) / static_cast<un_scalar_t>(1e3);

            case DensityUnit::PoundsPerCubicFoot:
                return value_ * 0.028316846592 / 0.45359237;

            case DensityUnit::KilopoundsPerCubicFoot:
                return (value_ * 0.028316846592 / 0.45359237) / static_cast<un_scalar_t>(1e3);

            case DensityUnit::PoundsPerCubicYard:
                return value_ * 0.764554857984 / 0.45359237;

            case DensityUnit::KilopoundsPerCubicYard:
                return (value_ * 0.764554857984 / 0.45359237) / static_cast<un_scalar_t>(1e3);

            case DensityUnit::TonnesPerCubicMillimeter:
                return value_ * 1e-12;

            case DensityUnit::TonnesPerCubicCentimeter:
                return value_ * 1e-9;

            case DensityUnit::TonnesPerCubicMeter:
                return value_ * 0.001;

            case DensityUnit::SlugsPerCubicFoot:
                return value_ * (0.3048 * 0.028316846592) / (0.45359237 * 9.80665);

            case DensityUnit::GramsPerLiter:
                return value_ * 1;

            case DensityUnit::FemtogramsPerLiter:
                return (value_ * 1) / static_cast<un_scalar_t>(1e-15);

            case DensityUnit::PicogramsPerLiter:
                return (value_ * 1) / static_cast<un_scalar_t>(1e-12);

            case DensityUnit::NanogramsPerLiter:
                return (value_ * 1) / static_cast<un_scalar_t>(1e-9);

            case DensityUnit::MicrogramsPerLiter:
                return (value_ * 1) / static_cast<un_scalar_t>(1e-6);

            case DensityUnit::MilligramsPerLiter:
                return (value_ * 1) / static_cast<un_scalar_t>(1e-3);

            case DensityUnit::CentigramsPerLiter:
                return (value_ * 1) / static_cast<un_scalar_t>(1e-2);

            case DensityUnit::DecigramsPerLiter:
                return (value_ * 1) / static_cast<un_scalar_t>(1e-1);

            case DensityUnit::GramsPerDeciliter:
                return value_ * 1e-1;

            case DensityUnit::FemtogramsPerDeciliter:
                return (value_ * 1e-1) / static_cast<un_scalar_t>(1e-15);

            case DensityUnit::PicogramsPerDeciliter:
                return (value_ * 1e-1) / static_cast<un_scalar_t>(1e-12);

            case DensityUnit::NanogramsPerDeciliter:
                return (value_ * 1e-1) / static_cast<un_scalar_t>(1e-9);

            case DensityUnit::MicrogramsPerDeciliter:
                return (value_ * 1e-1) / static_cast<un_scalar_t>(1e-6);

            case DensityUnit::MilligramsPerDeciliter:
                return (value_ * 1e-1) / static_cast<un_scalar_t>(1e-3);

            case DensityUnit::CentigramsPerDeciliter:
                return (value_ * 1e-1) / static_cast<un_scalar_t>(1e-2);

            case DensityUnit::DecigramsPerDeciliter:
                return (value_ * 1e-1) / static_cast<un_scalar_t>(1e-1);

            case DensityUnit::GramsPerMilliliter:
                return value_ * 1e-3;

            case DensityUnit::FemtogramsPerMilliliter:
                return (value_ * 1e-3) / static_cast<un_scalar_t>(1e-15);

            case DensityUnit::PicogramsPerMilliliter:
                return (value_ * 1e-3) / static_cast<un_scalar_t>(1e-12);

            case DensityUnit::NanogramsPerMilliliter:
                return (value_ * 1e-3) / static_cast<un_scalar_t>(1e-9);

            case DensityUnit::MicrogramsPerMilliliter:
                return (value_ * 1e-3) / static_cast<un_scalar_t>(1e-6);

            case DensityUnit::MilligramsPerMilliliter:
                return (value_ * 1e-3) / static_cast<un_scalar_t>(1e-3);

            case DensityUnit::CentigramsPerMilliliter:
                return (value_ * 1e-3) / static_cast<un_scalar_t>(1e-2);

            case DensityUnit::DecigramsPerMilliliter:
                return (value_ * 1e-3) / static_cast<un_scalar_t>(1e-1);

            case DensityUnit::PoundsPerUSGallon:
                return value_ * 0.003785411784 / 0.45359237;

            case DensityUnit::PoundsPerImperialGallon:
                return value_ * 0.00454609 / 0.45359237;

            case DensityUnit::KilogramsPerLiter:
                return value_ / 1e3;

            case DensityUnit::TonnesPerCubicFoot:
                return value_ * 0.028316846592 / 1000;

            case DensityUnit::TonnesPerCubicInch:
                return value_ * 1.6387064e-5 / 1000;

            case DensityUnit::GramsPerCubicFoot:
                return value_ * 0.028316846592 / 0.001;

            case DensityUnit::GramsPerCubicInch:
                return value_ * 1.6387064e-5 / 0.001;

            case DensityUnit::PoundsPerCubicMeter:
                return value_ / 0.45359237;

            case DensityUnit::PoundsPerCubicCentimeter:
                return value_ / 0.45359237e6;

            case DensityUnit::PoundsPerCubicMillimeter:
                return value_ / 0.45359237e9;

            case DensityUnit::SlugsPerCubicMeter:
                return value_ * 0.3048 / (0.45359237 * 9.80665);

            case DensityUnit::SlugsPerCubicCentimeter:
                return value_ * 0.3048 / (0.45359237e6 * 9.80665);

            case DensityUnit::SlugsPerCubicMillimeter:
                return value_ * 0.3048 / (0.45359237e9 * 9.80665);

            case DensityUnit::SlugsPerCubicInch:
                return value_ * (0.3048 * 1.6387064e-5) / (0.45359237 * 9.80665);

            }

            throw std::invalid_argument("Unknown Density unit.");
        }

        un_scalar_t value_;
    };
}
