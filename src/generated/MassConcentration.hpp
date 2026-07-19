#pragma once

#include <cstdint>
#include <numbers>
#include <stdexcept>
#include "UnitsNetConfig.h"

namespace unitsnet_cpp
{
    enum class MassConcentrationUnit : std::uint8_t
    {
        GramsPerCubicMillimeter,
        KilogramsPerCubicMillimeter,
        GramsPerCubicCentimeter,
        KilogramsPerCubicCentimeter,
        GramsPerCubicMeter,
        KilogramsPerCubicMeter,
        MilligramsPerCubicMeter,
        MicrogramsPerCubicMeter,
        GramsPerMicroliter,
        PicogramsPerMicroliter,
        NanogramsPerMicroliter,
        MicrogramsPerMicroliter,
        MilligramsPerMicroliter,
        CentigramsPerMicroliter,
        DecigramsPerMicroliter,
        GramsPerMilliliter,
        PicogramsPerMilliliter,
        NanogramsPerMilliliter,
        MicrogramsPerMilliliter,
        MilligramsPerMilliliter,
        CentigramsPerMilliliter,
        DecigramsPerMilliliter,
        GramsPerDeciliter,
        PicogramsPerDeciliter,
        NanogramsPerDeciliter,
        MicrogramsPerDeciliter,
        MilligramsPerDeciliter,
        CentigramsPerDeciliter,
        DecigramsPerDeciliter,
        GramsPerLiter,
        PicogramsPerLiter,
        NanogramsPerLiter,
        MicrogramsPerLiter,
        MilligramsPerLiter,
        CentigramsPerLiter,
        DecigramsPerLiter,
        KilogramsPerLiter,
        TonnesPerCubicMillimeter,
        TonnesPerCubicCentimeter,
        TonnesPerCubicMeter,
        PoundsPerCubicInch,
        KilopoundsPerCubicInch,
        PoundsPerCubicFoot,
        KilopoundsPerCubicFoot,
        SlugsPerCubicFoot,
        PoundsPerUSGallon,
        OuncesPerUSGallon,
        OuncesPerImperialGallon,
        PoundsPerImperialGallon,
    };

    /// <summary>In chemistry, the mass concentration ρi (or γi) is defined as the mass of a constituent mi divided by the volume of the mixture V</summary>
    class MassConcentration
    {
    public:
        constexpr explicit MassConcentration(
            const un_scalar_t value,
            const MassConcentrationUnit unit = MassConcentrationUnit::KilogramsPerCubicMeter)
            : value_(convert_to_base(value, unit))
        {
        }
        
        constexpr explicit MassConcentration(const bool isValid)
        {
            _isInvalid = !isValid;
        }
        
        void SetValueAsInvalid()
        {
            _isInvalid = true;
        }
        
        void SetValueAsValid()
        {
            _isInvalid = false;
        }
        
        [[nodiscard]] bool GetValueIsValid() const
        {
            return _isInvalid;
        }

        [[nodiscard]] constexpr un_scalar_t base_value() const noexcept
        {
            return value_;
        }

        [[nodiscard]] constexpr un_scalar_t value(const MassConcentrationUnit unit) const
        {
            return convert_from_base(unit);
        }

        [[nodiscard]] constexpr MassConcentration operator+(const MassConcentration other) const noexcept
        {
            return MassConcentration(value_ + other.value_);
        }

        [[nodiscard]] constexpr MassConcentration operator-(const MassConcentration other) const noexcept
        {
            return MassConcentration(value_ - other.value_);
        }

        [[nodiscard]] constexpr MassConcentration operator*(const un_scalar_t scalar) const noexcept
        {
            return MassConcentration(value_ * scalar);
        }

        [[nodiscard]] constexpr MassConcentration operator/(const un_scalar_t scalar) const noexcept
        {
            return MassConcentration(value_ / scalar);
        }

        [[nodiscard]] constexpr bool operator==(const MassConcentration other) const noexcept
        {
            return value_ == other.value_;
        }

        [[nodiscard]] constexpr bool operator<(const MassConcentration other) const noexcept
        {
            return value_ < other.value_;
        }
        
        [[nodiscard]] constexpr bool operator>(const MassConcentration other) const noexcept
        {
            return value_ > other.value_;
        }


        [[nodiscard]] constexpr un_scalar_t grams_per_cubic_millimeter() const
        {
            return convert_from_base(MassConcentrationUnit::GramsPerCubicMillimeter);
        }

        [[nodiscard]] static constexpr MassConcentration from_grams_per_cubic_millimeter(const un_scalar_t value)
        {
            return MassConcentration(value, MassConcentrationUnit::GramsPerCubicMillimeter);
        }


        [[nodiscard]] constexpr un_scalar_t kilograms_per_cubic_millimeter() const
        {
            return convert_from_base(MassConcentrationUnit::KilogramsPerCubicMillimeter);
        }

        [[nodiscard]] static constexpr MassConcentration from_kilograms_per_cubic_millimeter(const un_scalar_t value)
        {
            return MassConcentration(value, MassConcentrationUnit::KilogramsPerCubicMillimeter);
        }


        [[nodiscard]] constexpr un_scalar_t grams_per_cubic_centimeter() const
        {
            return convert_from_base(MassConcentrationUnit::GramsPerCubicCentimeter);
        }

        [[nodiscard]] static constexpr MassConcentration from_grams_per_cubic_centimeter(const un_scalar_t value)
        {
            return MassConcentration(value, MassConcentrationUnit::GramsPerCubicCentimeter);
        }


        [[nodiscard]] constexpr un_scalar_t kilograms_per_cubic_centimeter() const
        {
            return convert_from_base(MassConcentrationUnit::KilogramsPerCubicCentimeter);
        }

        [[nodiscard]] static constexpr MassConcentration from_kilograms_per_cubic_centimeter(const un_scalar_t value)
        {
            return MassConcentration(value, MassConcentrationUnit::KilogramsPerCubicCentimeter);
        }


        [[nodiscard]] constexpr un_scalar_t grams_per_cubic_meter() const
        {
            return convert_from_base(MassConcentrationUnit::GramsPerCubicMeter);
        }

        [[nodiscard]] static constexpr MassConcentration from_grams_per_cubic_meter(const un_scalar_t value)
        {
            return MassConcentration(value, MassConcentrationUnit::GramsPerCubicMeter);
        }


        [[nodiscard]] constexpr un_scalar_t kilograms_per_cubic_meter() const
        {
            return convert_from_base(MassConcentrationUnit::KilogramsPerCubicMeter);
        }

        [[nodiscard]] static constexpr MassConcentration from_kilograms_per_cubic_meter(const un_scalar_t value)
        {
            return MassConcentration(value, MassConcentrationUnit::KilogramsPerCubicMeter);
        }


        [[nodiscard]] constexpr un_scalar_t milligrams_per_cubic_meter() const
        {
            return convert_from_base(MassConcentrationUnit::MilligramsPerCubicMeter);
        }

        [[nodiscard]] static constexpr MassConcentration from_milligrams_per_cubic_meter(const un_scalar_t value)
        {
            return MassConcentration(value, MassConcentrationUnit::MilligramsPerCubicMeter);
        }


        [[nodiscard]] constexpr un_scalar_t micrograms_per_cubic_meter() const
        {
            return convert_from_base(MassConcentrationUnit::MicrogramsPerCubicMeter);
        }

        [[nodiscard]] static constexpr MassConcentration from_micrograms_per_cubic_meter(const un_scalar_t value)
        {
            return MassConcentration(value, MassConcentrationUnit::MicrogramsPerCubicMeter);
        }


        [[nodiscard]] constexpr un_scalar_t grams_per_microliter() const
        {
            return convert_from_base(MassConcentrationUnit::GramsPerMicroliter);
        }

        [[nodiscard]] static constexpr MassConcentration from_grams_per_microliter(const un_scalar_t value)
        {
            return MassConcentration(value, MassConcentrationUnit::GramsPerMicroliter);
        }


        [[nodiscard]] constexpr un_scalar_t picograms_per_microliter() const
        {
            return convert_from_base(MassConcentrationUnit::PicogramsPerMicroliter);
        }

        [[nodiscard]] static constexpr MassConcentration from_picograms_per_microliter(const un_scalar_t value)
        {
            return MassConcentration(value, MassConcentrationUnit::PicogramsPerMicroliter);
        }


        [[nodiscard]] constexpr un_scalar_t nanograms_per_microliter() const
        {
            return convert_from_base(MassConcentrationUnit::NanogramsPerMicroliter);
        }

        [[nodiscard]] static constexpr MassConcentration from_nanograms_per_microliter(const un_scalar_t value)
        {
            return MassConcentration(value, MassConcentrationUnit::NanogramsPerMicroliter);
        }


        [[nodiscard]] constexpr un_scalar_t micrograms_per_microliter() const
        {
            return convert_from_base(MassConcentrationUnit::MicrogramsPerMicroliter);
        }

        [[nodiscard]] static constexpr MassConcentration from_micrograms_per_microliter(const un_scalar_t value)
        {
            return MassConcentration(value, MassConcentrationUnit::MicrogramsPerMicroliter);
        }


        [[nodiscard]] constexpr un_scalar_t milligrams_per_microliter() const
        {
            return convert_from_base(MassConcentrationUnit::MilligramsPerMicroliter);
        }

        [[nodiscard]] static constexpr MassConcentration from_milligrams_per_microliter(const un_scalar_t value)
        {
            return MassConcentration(value, MassConcentrationUnit::MilligramsPerMicroliter);
        }


        [[nodiscard]] constexpr un_scalar_t centigrams_per_microliter() const
        {
            return convert_from_base(MassConcentrationUnit::CentigramsPerMicroliter);
        }

        [[nodiscard]] static constexpr MassConcentration from_centigrams_per_microliter(const un_scalar_t value)
        {
            return MassConcentration(value, MassConcentrationUnit::CentigramsPerMicroliter);
        }


        [[nodiscard]] constexpr un_scalar_t decigrams_per_microliter() const
        {
            return convert_from_base(MassConcentrationUnit::DecigramsPerMicroliter);
        }

        [[nodiscard]] static constexpr MassConcentration from_decigrams_per_microliter(const un_scalar_t value)
        {
            return MassConcentration(value, MassConcentrationUnit::DecigramsPerMicroliter);
        }


        [[nodiscard]] constexpr un_scalar_t grams_per_milliliter() const
        {
            return convert_from_base(MassConcentrationUnit::GramsPerMilliliter);
        }

        [[nodiscard]] static constexpr MassConcentration from_grams_per_milliliter(const un_scalar_t value)
        {
            return MassConcentration(value, MassConcentrationUnit::GramsPerMilliliter);
        }


        [[nodiscard]] constexpr un_scalar_t picograms_per_milliliter() const
        {
            return convert_from_base(MassConcentrationUnit::PicogramsPerMilliliter);
        }

        [[nodiscard]] static constexpr MassConcentration from_picograms_per_milliliter(const un_scalar_t value)
        {
            return MassConcentration(value, MassConcentrationUnit::PicogramsPerMilliliter);
        }


        [[nodiscard]] constexpr un_scalar_t nanograms_per_milliliter() const
        {
            return convert_from_base(MassConcentrationUnit::NanogramsPerMilliliter);
        }

        [[nodiscard]] static constexpr MassConcentration from_nanograms_per_milliliter(const un_scalar_t value)
        {
            return MassConcentration(value, MassConcentrationUnit::NanogramsPerMilliliter);
        }


        [[nodiscard]] constexpr un_scalar_t micrograms_per_milliliter() const
        {
            return convert_from_base(MassConcentrationUnit::MicrogramsPerMilliliter);
        }

        [[nodiscard]] static constexpr MassConcentration from_micrograms_per_milliliter(const un_scalar_t value)
        {
            return MassConcentration(value, MassConcentrationUnit::MicrogramsPerMilliliter);
        }


        [[nodiscard]] constexpr un_scalar_t milligrams_per_milliliter() const
        {
            return convert_from_base(MassConcentrationUnit::MilligramsPerMilliliter);
        }

        [[nodiscard]] static constexpr MassConcentration from_milligrams_per_milliliter(const un_scalar_t value)
        {
            return MassConcentration(value, MassConcentrationUnit::MilligramsPerMilliliter);
        }


        [[nodiscard]] constexpr un_scalar_t centigrams_per_milliliter() const
        {
            return convert_from_base(MassConcentrationUnit::CentigramsPerMilliliter);
        }

        [[nodiscard]] static constexpr MassConcentration from_centigrams_per_milliliter(const un_scalar_t value)
        {
            return MassConcentration(value, MassConcentrationUnit::CentigramsPerMilliliter);
        }


        [[nodiscard]] constexpr un_scalar_t decigrams_per_milliliter() const
        {
            return convert_from_base(MassConcentrationUnit::DecigramsPerMilliliter);
        }

        [[nodiscard]] static constexpr MassConcentration from_decigrams_per_milliliter(const un_scalar_t value)
        {
            return MassConcentration(value, MassConcentrationUnit::DecigramsPerMilliliter);
        }


        [[nodiscard]] constexpr un_scalar_t grams_per_deciliter() const
        {
            return convert_from_base(MassConcentrationUnit::GramsPerDeciliter);
        }

        [[nodiscard]] static constexpr MassConcentration from_grams_per_deciliter(const un_scalar_t value)
        {
            return MassConcentration(value, MassConcentrationUnit::GramsPerDeciliter);
        }


        [[nodiscard]] constexpr un_scalar_t picograms_per_deciliter() const
        {
            return convert_from_base(MassConcentrationUnit::PicogramsPerDeciliter);
        }

        [[nodiscard]] static constexpr MassConcentration from_picograms_per_deciliter(const un_scalar_t value)
        {
            return MassConcentration(value, MassConcentrationUnit::PicogramsPerDeciliter);
        }


        [[nodiscard]] constexpr un_scalar_t nanograms_per_deciliter() const
        {
            return convert_from_base(MassConcentrationUnit::NanogramsPerDeciliter);
        }

        [[nodiscard]] static constexpr MassConcentration from_nanograms_per_deciliter(const un_scalar_t value)
        {
            return MassConcentration(value, MassConcentrationUnit::NanogramsPerDeciliter);
        }


        [[nodiscard]] constexpr un_scalar_t micrograms_per_deciliter() const
        {
            return convert_from_base(MassConcentrationUnit::MicrogramsPerDeciliter);
        }

        [[nodiscard]] static constexpr MassConcentration from_micrograms_per_deciliter(const un_scalar_t value)
        {
            return MassConcentration(value, MassConcentrationUnit::MicrogramsPerDeciliter);
        }


        [[nodiscard]] constexpr un_scalar_t milligrams_per_deciliter() const
        {
            return convert_from_base(MassConcentrationUnit::MilligramsPerDeciliter);
        }

        [[nodiscard]] static constexpr MassConcentration from_milligrams_per_deciliter(const un_scalar_t value)
        {
            return MassConcentration(value, MassConcentrationUnit::MilligramsPerDeciliter);
        }


        [[nodiscard]] constexpr un_scalar_t centigrams_per_deciliter() const
        {
            return convert_from_base(MassConcentrationUnit::CentigramsPerDeciliter);
        }

        [[nodiscard]] static constexpr MassConcentration from_centigrams_per_deciliter(const un_scalar_t value)
        {
            return MassConcentration(value, MassConcentrationUnit::CentigramsPerDeciliter);
        }


        [[nodiscard]] constexpr un_scalar_t decigrams_per_deciliter() const
        {
            return convert_from_base(MassConcentrationUnit::DecigramsPerDeciliter);
        }

        [[nodiscard]] static constexpr MassConcentration from_decigrams_per_deciliter(const un_scalar_t value)
        {
            return MassConcentration(value, MassConcentrationUnit::DecigramsPerDeciliter);
        }


        [[nodiscard]] constexpr un_scalar_t grams_per_liter() const
        {
            return convert_from_base(MassConcentrationUnit::GramsPerLiter);
        }

        [[nodiscard]] static constexpr MassConcentration from_grams_per_liter(const un_scalar_t value)
        {
            return MassConcentration(value, MassConcentrationUnit::GramsPerLiter);
        }


        [[nodiscard]] constexpr un_scalar_t picograms_per_liter() const
        {
            return convert_from_base(MassConcentrationUnit::PicogramsPerLiter);
        }

        [[nodiscard]] static constexpr MassConcentration from_picograms_per_liter(const un_scalar_t value)
        {
            return MassConcentration(value, MassConcentrationUnit::PicogramsPerLiter);
        }


        [[nodiscard]] constexpr un_scalar_t nanograms_per_liter() const
        {
            return convert_from_base(MassConcentrationUnit::NanogramsPerLiter);
        }

        [[nodiscard]] static constexpr MassConcentration from_nanograms_per_liter(const un_scalar_t value)
        {
            return MassConcentration(value, MassConcentrationUnit::NanogramsPerLiter);
        }


        [[nodiscard]] constexpr un_scalar_t micrograms_per_liter() const
        {
            return convert_from_base(MassConcentrationUnit::MicrogramsPerLiter);
        }

        [[nodiscard]] static constexpr MassConcentration from_micrograms_per_liter(const un_scalar_t value)
        {
            return MassConcentration(value, MassConcentrationUnit::MicrogramsPerLiter);
        }


        [[nodiscard]] constexpr un_scalar_t milligrams_per_liter() const
        {
            return convert_from_base(MassConcentrationUnit::MilligramsPerLiter);
        }

        [[nodiscard]] static constexpr MassConcentration from_milligrams_per_liter(const un_scalar_t value)
        {
            return MassConcentration(value, MassConcentrationUnit::MilligramsPerLiter);
        }


        [[nodiscard]] constexpr un_scalar_t centigrams_per_liter() const
        {
            return convert_from_base(MassConcentrationUnit::CentigramsPerLiter);
        }

        [[nodiscard]] static constexpr MassConcentration from_centigrams_per_liter(const un_scalar_t value)
        {
            return MassConcentration(value, MassConcentrationUnit::CentigramsPerLiter);
        }


        [[nodiscard]] constexpr un_scalar_t decigrams_per_liter() const
        {
            return convert_from_base(MassConcentrationUnit::DecigramsPerLiter);
        }

        [[nodiscard]] static constexpr MassConcentration from_decigrams_per_liter(const un_scalar_t value)
        {
            return MassConcentration(value, MassConcentrationUnit::DecigramsPerLiter);
        }


        [[nodiscard]] constexpr un_scalar_t kilograms_per_liter() const
        {
            return convert_from_base(MassConcentrationUnit::KilogramsPerLiter);
        }

        [[nodiscard]] static constexpr MassConcentration from_kilograms_per_liter(const un_scalar_t value)
        {
            return MassConcentration(value, MassConcentrationUnit::KilogramsPerLiter);
        }


        [[nodiscard]] constexpr un_scalar_t tonnes_per_cubic_millimeter() const
        {
            return convert_from_base(MassConcentrationUnit::TonnesPerCubicMillimeter);
        }

        [[nodiscard]] static constexpr MassConcentration from_tonnes_per_cubic_millimeter(const un_scalar_t value)
        {
            return MassConcentration(value, MassConcentrationUnit::TonnesPerCubicMillimeter);
        }


        [[nodiscard]] constexpr un_scalar_t tonnes_per_cubic_centimeter() const
        {
            return convert_from_base(MassConcentrationUnit::TonnesPerCubicCentimeter);
        }

        [[nodiscard]] static constexpr MassConcentration from_tonnes_per_cubic_centimeter(const un_scalar_t value)
        {
            return MassConcentration(value, MassConcentrationUnit::TonnesPerCubicCentimeter);
        }


        [[nodiscard]] constexpr un_scalar_t tonnes_per_cubic_meter() const
        {
            return convert_from_base(MassConcentrationUnit::TonnesPerCubicMeter);
        }

        [[nodiscard]] static constexpr MassConcentration from_tonnes_per_cubic_meter(const un_scalar_t value)
        {
            return MassConcentration(value, MassConcentrationUnit::TonnesPerCubicMeter);
        }


        [[nodiscard]] constexpr un_scalar_t pounds_per_cubic_inch() const
        {
            return convert_from_base(MassConcentrationUnit::PoundsPerCubicInch);
        }

        [[nodiscard]] static constexpr MassConcentration from_pounds_per_cubic_inch(const un_scalar_t value)
        {
            return MassConcentration(value, MassConcentrationUnit::PoundsPerCubicInch);
        }


        [[nodiscard]] constexpr un_scalar_t kilopounds_per_cubic_inch() const
        {
            return convert_from_base(MassConcentrationUnit::KilopoundsPerCubicInch);
        }

        [[nodiscard]] static constexpr MassConcentration from_kilopounds_per_cubic_inch(const un_scalar_t value)
        {
            return MassConcentration(value, MassConcentrationUnit::KilopoundsPerCubicInch);
        }


        [[nodiscard]] constexpr un_scalar_t pounds_per_cubic_foot() const
        {
            return convert_from_base(MassConcentrationUnit::PoundsPerCubicFoot);
        }

        [[nodiscard]] static constexpr MassConcentration from_pounds_per_cubic_foot(const un_scalar_t value)
        {
            return MassConcentration(value, MassConcentrationUnit::PoundsPerCubicFoot);
        }


        [[nodiscard]] constexpr un_scalar_t kilopounds_per_cubic_foot() const
        {
            return convert_from_base(MassConcentrationUnit::KilopoundsPerCubicFoot);
        }

        [[nodiscard]] static constexpr MassConcentration from_kilopounds_per_cubic_foot(const un_scalar_t value)
        {
            return MassConcentration(value, MassConcentrationUnit::KilopoundsPerCubicFoot);
        }


        [[nodiscard]] constexpr un_scalar_t slugs_per_cubic_foot() const
        {
            return convert_from_base(MassConcentrationUnit::SlugsPerCubicFoot);
        }

        [[nodiscard]] static constexpr MassConcentration from_slugs_per_cubic_foot(const un_scalar_t value)
        {
            return MassConcentration(value, MassConcentrationUnit::SlugsPerCubicFoot);
        }


        [[nodiscard]] constexpr un_scalar_t pounds_per_u_s_gallon() const
        {
            return convert_from_base(MassConcentrationUnit::PoundsPerUSGallon);
        }

        [[nodiscard]] static constexpr MassConcentration from_pounds_per_u_s_gallon(const un_scalar_t value)
        {
            return MassConcentration(value, MassConcentrationUnit::PoundsPerUSGallon);
        }


        [[nodiscard]] constexpr un_scalar_t ounces_per_u_s_gallon() const
        {
            return convert_from_base(MassConcentrationUnit::OuncesPerUSGallon);
        }

        [[nodiscard]] static constexpr MassConcentration from_ounces_per_u_s_gallon(const un_scalar_t value)
        {
            return MassConcentration(value, MassConcentrationUnit::OuncesPerUSGallon);
        }


        [[nodiscard]] constexpr un_scalar_t ounces_per_imperial_gallon() const
        {
            return convert_from_base(MassConcentrationUnit::OuncesPerImperialGallon);
        }

        [[nodiscard]] static constexpr MassConcentration from_ounces_per_imperial_gallon(const un_scalar_t value)
        {
            return MassConcentration(value, MassConcentrationUnit::OuncesPerImperialGallon);
        }


        [[nodiscard]] constexpr un_scalar_t pounds_per_imperial_gallon() const
        {
            return convert_from_base(MassConcentrationUnit::PoundsPerImperialGallon);
        }

        [[nodiscard]] static constexpr MassConcentration from_pounds_per_imperial_gallon(const un_scalar_t value)
        {
            return MassConcentration(value, MassConcentrationUnit::PoundsPerImperialGallon);
        }


        [[nodiscard]] static constexpr MassConcentration from_invalid()
        {
            return MassConcentration(false);
        }
    private:
        bool _isInvalid = false;
    
        [[nodiscard]] static constexpr un_scalar_t convert_to_base(un_scalar_t value, MassConcentrationUnit unit)
        {
            switch (unit)
            {

            case MassConcentrationUnit::GramsPerCubicMillimeter:
                return value / static_cast<un_scalar_t>(1e-6);

            case MassConcentrationUnit::KilogramsPerCubicMillimeter:
                return (value * static_cast<un_scalar_t>(1e3)) / static_cast<un_scalar_t>(1e-6);

            case MassConcentrationUnit::GramsPerCubicCentimeter:
                return value / static_cast<un_scalar_t>(1e-3);

            case MassConcentrationUnit::KilogramsPerCubicCentimeter:
                return (value * static_cast<un_scalar_t>(1e3)) / static_cast<un_scalar_t>(1e-3);

            case MassConcentrationUnit::GramsPerCubicMeter:
                return value / static_cast<un_scalar_t>(1e3);

            case MassConcentrationUnit::KilogramsPerCubicMeter:
                return (value * static_cast<un_scalar_t>(1e3)) / static_cast<un_scalar_t>(1e3);

            case MassConcentrationUnit::MilligramsPerCubicMeter:
                return (value * static_cast<un_scalar_t>(1e-3)) / static_cast<un_scalar_t>(1e3);

            case MassConcentrationUnit::MicrogramsPerCubicMeter:
                return (value * static_cast<un_scalar_t>(1e-6)) / static_cast<un_scalar_t>(1e3);

            case MassConcentrationUnit::GramsPerMicroliter:
                return value / static_cast<un_scalar_t>(1e-6);

            case MassConcentrationUnit::PicogramsPerMicroliter:
                return (value * static_cast<un_scalar_t>(1e-12)) / static_cast<un_scalar_t>(1e-6);

            case MassConcentrationUnit::NanogramsPerMicroliter:
                return (value * static_cast<un_scalar_t>(1e-9)) / static_cast<un_scalar_t>(1e-6);

            case MassConcentrationUnit::MicrogramsPerMicroliter:
                return (value * static_cast<un_scalar_t>(1e-6)) / static_cast<un_scalar_t>(1e-6);

            case MassConcentrationUnit::MilligramsPerMicroliter:
                return (value * static_cast<un_scalar_t>(1e-3)) / static_cast<un_scalar_t>(1e-6);

            case MassConcentrationUnit::CentigramsPerMicroliter:
                return (value * static_cast<un_scalar_t>(1e-2)) / static_cast<un_scalar_t>(1e-6);

            case MassConcentrationUnit::DecigramsPerMicroliter:
                return (value * static_cast<un_scalar_t>(1e-1)) / static_cast<un_scalar_t>(1e-6);

            case MassConcentrationUnit::GramsPerMilliliter:
                return value / static_cast<un_scalar_t>(1e-3);

            case MassConcentrationUnit::PicogramsPerMilliliter:
                return (value * static_cast<un_scalar_t>(1e-12)) / static_cast<un_scalar_t>(1e-3);

            case MassConcentrationUnit::NanogramsPerMilliliter:
                return (value * static_cast<un_scalar_t>(1e-9)) / static_cast<un_scalar_t>(1e-3);

            case MassConcentrationUnit::MicrogramsPerMilliliter:
                return (value * static_cast<un_scalar_t>(1e-6)) / static_cast<un_scalar_t>(1e-3);

            case MassConcentrationUnit::MilligramsPerMilliliter:
                return (value * static_cast<un_scalar_t>(1e-3)) / static_cast<un_scalar_t>(1e-3);

            case MassConcentrationUnit::CentigramsPerMilliliter:
                return (value * static_cast<un_scalar_t>(1e-2)) / static_cast<un_scalar_t>(1e-3);

            case MassConcentrationUnit::DecigramsPerMilliliter:
                return (value * static_cast<un_scalar_t>(1e-1)) / static_cast<un_scalar_t>(1e-3);

            case MassConcentrationUnit::GramsPerDeciliter:
                return value / static_cast<un_scalar_t>(1e-1);

            case MassConcentrationUnit::PicogramsPerDeciliter:
                return (value * static_cast<un_scalar_t>(1e-12)) / static_cast<un_scalar_t>(1e-1);

            case MassConcentrationUnit::NanogramsPerDeciliter:
                return (value * static_cast<un_scalar_t>(1e-9)) / static_cast<un_scalar_t>(1e-1);

            case MassConcentrationUnit::MicrogramsPerDeciliter:
                return (value * static_cast<un_scalar_t>(1e-6)) / static_cast<un_scalar_t>(1e-1);

            case MassConcentrationUnit::MilligramsPerDeciliter:
                return (value * static_cast<un_scalar_t>(1e-3)) / static_cast<un_scalar_t>(1e-1);

            case MassConcentrationUnit::CentigramsPerDeciliter:
                return (value * static_cast<un_scalar_t>(1e-2)) / static_cast<un_scalar_t>(1e-1);

            case MassConcentrationUnit::DecigramsPerDeciliter:
                return (value * static_cast<un_scalar_t>(1e-1)) / static_cast<un_scalar_t>(1e-1);

            case MassConcentrationUnit::GramsPerLiter:
                return value;

            case MassConcentrationUnit::PicogramsPerLiter:
                return (value * static_cast<un_scalar_t>(1e-12));

            case MassConcentrationUnit::NanogramsPerLiter:
                return (value * static_cast<un_scalar_t>(1e-9));

            case MassConcentrationUnit::MicrogramsPerLiter:
                return (value * static_cast<un_scalar_t>(1e-6));

            case MassConcentrationUnit::MilligramsPerLiter:
                return (value * static_cast<un_scalar_t>(1e-3));

            case MassConcentrationUnit::CentigramsPerLiter:
                return (value * static_cast<un_scalar_t>(1e-2));

            case MassConcentrationUnit::DecigramsPerLiter:
                return (value * static_cast<un_scalar_t>(1e-1));

            case MassConcentrationUnit::KilogramsPerLiter:
                return (value * static_cast<un_scalar_t>(1e3));

            case MassConcentrationUnit::TonnesPerCubicMillimeter:
                return value / static_cast<un_scalar_t>(1e-12);

            case MassConcentrationUnit::TonnesPerCubicCentimeter:
                return value / static_cast<un_scalar_t>(1e-9);

            case MassConcentrationUnit::TonnesPerCubicMeter:
                return value / static_cast<un_scalar_t>(0.001);

            case MassConcentrationUnit::PoundsPerCubicInch:
                return value * static_cast<un_scalar_t>(0.45359237) / static_cast<un_scalar_t>(1.6387064e-5);

            case MassConcentrationUnit::KilopoundsPerCubicInch:
                return (value * static_cast<un_scalar_t>(1e3)) * static_cast<un_scalar_t>(0.45359237) / static_cast<un_scalar_t>(1.6387064e-5);

            case MassConcentrationUnit::PoundsPerCubicFoot:
                return value * static_cast<un_scalar_t>(0.45359237) / static_cast<un_scalar_t>(0.028316846592);

            case MassConcentrationUnit::KilopoundsPerCubicFoot:
                return (value * static_cast<un_scalar_t>(1e3)) * static_cast<un_scalar_t>(0.45359237) / static_cast<un_scalar_t>(0.028316846592);

            case MassConcentrationUnit::SlugsPerCubicFoot:
                return value * (static_cast<un_scalar_t>(0.45359237) * static_cast<un_scalar_t>(9.80665)) / (static_cast<un_scalar_t>(0.3048) * static_cast<un_scalar_t>(0.028316846592));

            case MassConcentrationUnit::PoundsPerUSGallon:
                return value * static_cast<un_scalar_t>(0.45359237) / static_cast<un_scalar_t>(0.003785411784);

            case MassConcentrationUnit::OuncesPerUSGallon:
                return value * static_cast<un_scalar_t>(0.028349523125) / static_cast<un_scalar_t>(0.003785411784);

            case MassConcentrationUnit::OuncesPerImperialGallon:
                return value * static_cast<un_scalar_t>(0.028349523125) / static_cast<un_scalar_t>(0.00454609);

            case MassConcentrationUnit::PoundsPerImperialGallon:
                return value * static_cast<un_scalar_t>(0.45359237) / static_cast<un_scalar_t>(0.00454609);

            }

            throw std::invalid_argument("Unknown MassConcentration unit.");
        }

        [[nodiscard]] constexpr un_scalar_t convert_from_base(const MassConcentrationUnit unit) const
        {
            switch (unit)
            {

            case MassConcentrationUnit::GramsPerCubicMillimeter:
                return value_ * static_cast<un_scalar_t>(1e-6);

            case MassConcentrationUnit::KilogramsPerCubicMillimeter:
                return (value_ * static_cast<un_scalar_t>(1e-6)) / static_cast<un_scalar_t>(1e3);

            case MassConcentrationUnit::GramsPerCubicCentimeter:
                return value_ * static_cast<un_scalar_t>(1e-3);

            case MassConcentrationUnit::KilogramsPerCubicCentimeter:
                return (value_ * static_cast<un_scalar_t>(1e-3)) / static_cast<un_scalar_t>(1e3);

            case MassConcentrationUnit::GramsPerCubicMeter:
                return value_ * static_cast<un_scalar_t>(1e3);

            case MassConcentrationUnit::KilogramsPerCubicMeter:
                return (value_ * static_cast<un_scalar_t>(1e3)) / static_cast<un_scalar_t>(1e3);

            case MassConcentrationUnit::MilligramsPerCubicMeter:
                return (value_ * static_cast<un_scalar_t>(1e3)) / static_cast<un_scalar_t>(1e-3);

            case MassConcentrationUnit::MicrogramsPerCubicMeter:
                return (value_ * static_cast<un_scalar_t>(1e3)) / static_cast<un_scalar_t>(1e-6);

            case MassConcentrationUnit::GramsPerMicroliter:
                return value_ * static_cast<un_scalar_t>(1e-6);

            case MassConcentrationUnit::PicogramsPerMicroliter:
                return (value_ * static_cast<un_scalar_t>(1e-6)) / static_cast<un_scalar_t>(1e-12);

            case MassConcentrationUnit::NanogramsPerMicroliter:
                return (value_ * static_cast<un_scalar_t>(1e-6)) / static_cast<un_scalar_t>(1e-9);

            case MassConcentrationUnit::MicrogramsPerMicroliter:
                return (value_ * static_cast<un_scalar_t>(1e-6)) / static_cast<un_scalar_t>(1e-6);

            case MassConcentrationUnit::MilligramsPerMicroliter:
                return (value_ * static_cast<un_scalar_t>(1e-6)) / static_cast<un_scalar_t>(1e-3);

            case MassConcentrationUnit::CentigramsPerMicroliter:
                return (value_ * static_cast<un_scalar_t>(1e-6)) / static_cast<un_scalar_t>(1e-2);

            case MassConcentrationUnit::DecigramsPerMicroliter:
                return (value_ * static_cast<un_scalar_t>(1e-6)) / static_cast<un_scalar_t>(1e-1);

            case MassConcentrationUnit::GramsPerMilliliter:
                return value_ * static_cast<un_scalar_t>(1e-3);

            case MassConcentrationUnit::PicogramsPerMilliliter:
                return (value_ * static_cast<un_scalar_t>(1e-3)) / static_cast<un_scalar_t>(1e-12);

            case MassConcentrationUnit::NanogramsPerMilliliter:
                return (value_ * static_cast<un_scalar_t>(1e-3)) / static_cast<un_scalar_t>(1e-9);

            case MassConcentrationUnit::MicrogramsPerMilliliter:
                return (value_ * static_cast<un_scalar_t>(1e-3)) / static_cast<un_scalar_t>(1e-6);

            case MassConcentrationUnit::MilligramsPerMilliliter:
                return (value_ * static_cast<un_scalar_t>(1e-3)) / static_cast<un_scalar_t>(1e-3);

            case MassConcentrationUnit::CentigramsPerMilliliter:
                return (value_ * static_cast<un_scalar_t>(1e-3)) / static_cast<un_scalar_t>(1e-2);

            case MassConcentrationUnit::DecigramsPerMilliliter:
                return (value_ * static_cast<un_scalar_t>(1e-3)) / static_cast<un_scalar_t>(1e-1);

            case MassConcentrationUnit::GramsPerDeciliter:
                return value_ * static_cast<un_scalar_t>(1e-1);

            case MassConcentrationUnit::PicogramsPerDeciliter:
                return (value_ * static_cast<un_scalar_t>(1e-1)) / static_cast<un_scalar_t>(1e-12);

            case MassConcentrationUnit::NanogramsPerDeciliter:
                return (value_ * static_cast<un_scalar_t>(1e-1)) / static_cast<un_scalar_t>(1e-9);

            case MassConcentrationUnit::MicrogramsPerDeciliter:
                return (value_ * static_cast<un_scalar_t>(1e-1)) / static_cast<un_scalar_t>(1e-6);

            case MassConcentrationUnit::MilligramsPerDeciliter:
                return (value_ * static_cast<un_scalar_t>(1e-1)) / static_cast<un_scalar_t>(1e-3);

            case MassConcentrationUnit::CentigramsPerDeciliter:
                return (value_ * static_cast<un_scalar_t>(1e-1)) / static_cast<un_scalar_t>(1e-2);

            case MassConcentrationUnit::DecigramsPerDeciliter:
                return (value_ * static_cast<un_scalar_t>(1e-1)) / static_cast<un_scalar_t>(1e-1);

            case MassConcentrationUnit::GramsPerLiter:
                return value_;

            case MassConcentrationUnit::PicogramsPerLiter:
                return (value_) / static_cast<un_scalar_t>(1e-12);

            case MassConcentrationUnit::NanogramsPerLiter:
                return (value_) / static_cast<un_scalar_t>(1e-9);

            case MassConcentrationUnit::MicrogramsPerLiter:
                return (value_) / static_cast<un_scalar_t>(1e-6);

            case MassConcentrationUnit::MilligramsPerLiter:
                return (value_) / static_cast<un_scalar_t>(1e-3);

            case MassConcentrationUnit::CentigramsPerLiter:
                return (value_) / static_cast<un_scalar_t>(1e-2);

            case MassConcentrationUnit::DecigramsPerLiter:
                return (value_) / static_cast<un_scalar_t>(1e-1);

            case MassConcentrationUnit::KilogramsPerLiter:
                return (value_) / static_cast<un_scalar_t>(1e3);

            case MassConcentrationUnit::TonnesPerCubicMillimeter:
                return value_ * static_cast<un_scalar_t>(1e-12);

            case MassConcentrationUnit::TonnesPerCubicCentimeter:
                return value_ * static_cast<un_scalar_t>(1e-9);

            case MassConcentrationUnit::TonnesPerCubicMeter:
                return value_ * static_cast<un_scalar_t>(0.001);

            case MassConcentrationUnit::PoundsPerCubicInch:
                return value_ * static_cast<un_scalar_t>(1.6387064e-5) / static_cast<un_scalar_t>(0.45359237);

            case MassConcentrationUnit::KilopoundsPerCubicInch:
                return (value_ * static_cast<un_scalar_t>(1.6387064e-5) / static_cast<un_scalar_t>(0.45359237)) / static_cast<un_scalar_t>(1e3);

            case MassConcentrationUnit::PoundsPerCubicFoot:
                return value_ * static_cast<un_scalar_t>(0.028316846592) / static_cast<un_scalar_t>(0.45359237);

            case MassConcentrationUnit::KilopoundsPerCubicFoot:
                return (value_ * static_cast<un_scalar_t>(0.028316846592) / static_cast<un_scalar_t>(0.45359237)) / static_cast<un_scalar_t>(1e3);

            case MassConcentrationUnit::SlugsPerCubicFoot:
                return value_ * (static_cast<un_scalar_t>(0.3048) * static_cast<un_scalar_t>(0.028316846592)) / (static_cast<un_scalar_t>(0.45359237) * static_cast<un_scalar_t>(9.80665));

            case MassConcentrationUnit::PoundsPerUSGallon:
                return value_ * static_cast<un_scalar_t>(0.003785411784) / static_cast<un_scalar_t>(0.45359237);

            case MassConcentrationUnit::OuncesPerUSGallon:
                return value_ * static_cast<un_scalar_t>(0.003785411784) / static_cast<un_scalar_t>(0.028349523125);

            case MassConcentrationUnit::OuncesPerImperialGallon:
                return value_ * static_cast<un_scalar_t>(0.00454609) / static_cast<un_scalar_t>(0.028349523125);

            case MassConcentrationUnit::PoundsPerImperialGallon:
                return value_ * static_cast<un_scalar_t>(0.00454609) / static_cast<un_scalar_t>(0.45359237);

            }

            throw std::invalid_argument("Unknown MassConcentration unit.");
        }

        un_scalar_t value_;
    };
}
