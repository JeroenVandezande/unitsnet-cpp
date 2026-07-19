#pragma once

#include <cstdint>
#include <numbers>
#include <stdexcept>
#include "UnitsNetConfig.h"
#include "UnitsNetBase.h"

namespace unitsnet_cpp
{
    enum class PressureUnit : std::uint8_t
    {
        Pascals,
        Micropascals,
        Millipascals,
        Decapascals,
        Hectopascals,
        Kilopascals,
        Megapascals,
        Gigapascals,
        Atmospheres,
        Bars,
        Microbars,
        Millibars,
        Centibars,
        Decibars,
        Kilobars,
        Megabars,
        KilogramsForcePerSquareMeter,
        KilogramsForcePerSquareCentimeter,
        KilogramsForcePerSquareMillimeter,
        NewtonsPerSquareMeter,
        KilonewtonsPerSquareMeter,
        MeganewtonsPerSquareMeter,
        NewtonsPerSquareCentimeter,
        KilonewtonsPerSquareCentimeter,
        NewtonsPerSquareMillimeter,
        KilonewtonsPerSquareMillimeter,
        TechnicalAtmospheres,
        Torrs,
        Millitorrs,
        PoundsForcePerSquareInch,
        KilopoundsForcePerSquareInch,
        PoundsForcePerSquareMil,
        KilopoundsForcePerSquareMil,
        PoundsForcePerSquareFoot,
        KilopoundsForcePerSquareFoot,
        TonnesForcePerSquareMillimeter,
        TonnesForcePerSquareMeter,
        MetersOfHead,
        TonnesForcePerSquareCentimeter,
        FeetOfHead,
        MillimetersOfMercury,
        InchesOfMercury,
        DynesPerSquareCentimeter,
        PoundsPerInchSecondSquared,
        MetersOfWaterColumn,
        MillimetersOfWaterColumn,
        CentimetersOfWaterColumn,
        InchesOfWaterColumn,
        MilligramsForcePerSquareMeter,
        MilligramsForcePerSquareFoot,
    };

    /// <summary>Pressure (symbol: P or p) is the ratio of force to the area over which that force is distributed. Pressure is force per unit area applied in a direction perpendicular to the surface of an object. Gauge pressure (also spelled gage pressure)[a] is the pressure relative to the local atmospheric or ambient pressure. Pressure is measured in any unit of force divided by any unit of area. The SI unit of pressure is the newton per square metre, which is called the pascal (Pa) after the seventeenth-century philosopher and scientist Blaise Pascal. A pressure of 1 Pa is small; it approximately equals the pressure exerted by a dollar bill resting flat on a table. Everyday pressures are often stated in kilopascals (1 kPa = 1000 Pa).</summary>
    class Pressure : public UnitsNetBase
    {
    public:
        constexpr explicit Pressure(
            const un_scalar_t value,
            const PressureUnit unit = PressureUnit::Pascals)
        {
            value_ = value;
            value_unit_type_ = unit;
        }
                
        [[nodiscard]] constexpr un_scalar_t base_value() const noexcept
        {
            return convert_to_base(value_, value_unit_type_);    
        }

        [[nodiscard]] constexpr un_scalar_t value(const PressureUnit unit) const
        {
            return convert_from_base(unit);
        }

        [[nodiscard]] constexpr Pressure operator+(const Pressure& other) const noexcept
        {
            return Pressure(base_value() + other.base_value());
        }

        [[nodiscard]] constexpr Pressure operator-(const Pressure& other)const noexcept
        {
            return Pressure(base_value() - other.base_value());
        }

        [[nodiscard]] constexpr Pressure operator*(const un_scalar_t scalar) const noexcept
        {
            return Pressure(base_value() * scalar);
        }

        [[nodiscard]] constexpr Pressure operator/(const un_scalar_t scalar) const noexcept
        {
            return Pressure(base_value() / scalar);
        }

        [[nodiscard]] constexpr bool operator==(const Pressure& other) const noexcept
        {
            return base_value() == other.base_value();
        }

        [[nodiscard]] constexpr bool operator<(const Pressure& other) const noexcept
        {
            return base_value() < other.base_value();
        }
        
        [[nodiscard]] constexpr bool operator>(const Pressure& other) const noexcept
        {
            return base_value() > other.base_value();
        }

        [[nodiscard]] constexpr un_scalar_t pascals() const
        {
            return convert_from_base(PressureUnit::Pascals);
        }

        [[nodiscard]] static constexpr Pressure from_pascals(const un_scalar_t value)
        {
            return Pressure(value, PressureUnit::Pascals);
        }

        [[nodiscard]] constexpr un_scalar_t micropascals() const
        {
            return convert_from_base(PressureUnit::Micropascals);
        }

        [[nodiscard]] static constexpr Pressure from_micropascals(const un_scalar_t value)
        {
            return Pressure(value, PressureUnit::Micropascals);
        }

        [[nodiscard]] constexpr un_scalar_t millipascals() const
        {
            return convert_from_base(PressureUnit::Millipascals);
        }

        [[nodiscard]] static constexpr Pressure from_millipascals(const un_scalar_t value)
        {
            return Pressure(value, PressureUnit::Millipascals);
        }

        [[nodiscard]] constexpr un_scalar_t decapascals() const
        {
            return convert_from_base(PressureUnit::Decapascals);
        }

        [[nodiscard]] static constexpr Pressure from_decapascals(const un_scalar_t value)
        {
            return Pressure(value, PressureUnit::Decapascals);
        }

        [[nodiscard]] constexpr un_scalar_t hectopascals() const
        {
            return convert_from_base(PressureUnit::Hectopascals);
        }

        [[nodiscard]] static constexpr Pressure from_hectopascals(const un_scalar_t value)
        {
            return Pressure(value, PressureUnit::Hectopascals);
        }

        [[nodiscard]] constexpr un_scalar_t kilopascals() const
        {
            return convert_from_base(PressureUnit::Kilopascals);
        }

        [[nodiscard]] static constexpr Pressure from_kilopascals(const un_scalar_t value)
        {
            return Pressure(value, PressureUnit::Kilopascals);
        }

        [[nodiscard]] constexpr un_scalar_t megapascals() const
        {
            return convert_from_base(PressureUnit::Megapascals);
        }

        [[nodiscard]] static constexpr Pressure from_megapascals(const un_scalar_t value)
        {
            return Pressure(value, PressureUnit::Megapascals);
        }

        [[nodiscard]] constexpr un_scalar_t gigapascals() const
        {
            return convert_from_base(PressureUnit::Gigapascals);
        }

        [[nodiscard]] static constexpr Pressure from_gigapascals(const un_scalar_t value)
        {
            return Pressure(value, PressureUnit::Gigapascals);
        }

        /// <summary>The standard atmosphere (symbol: atm) is a unit of pressure defined as 101325 Pa. It is sometimes used as a reference pressure or standard pressure. It is approximately equal to Earth's average atmospheric pressure at sea level.</summary>
        [[nodiscard]] constexpr un_scalar_t atmospheres() const
        {
            return convert_from_base(PressureUnit::Atmospheres);
        }

        /// <summary>The standard atmosphere (symbol: atm) is a unit of pressure defined as 101325 Pa. It is sometimes used as a reference pressure or standard pressure. It is approximately equal to Earth's average atmospheric pressure at sea level.</summary>
        [[nodiscard]] static constexpr Pressure from_atmospheres(const un_scalar_t value)
        {
            return Pressure(value, PressureUnit::Atmospheres);
        }

        /// <summary>The bar is a metric unit of pressure defined as 100,000 Pa (100 kPa), though not part of the International System of Units (SI). A pressure of 1 bar is slightly less than the current average atmospheric pressure on Earth at sea level (approximately 1.013 bar).</summary>
        [[nodiscard]] constexpr un_scalar_t bars() const
        {
            return convert_from_base(PressureUnit::Bars);
        }

        /// <summary>The bar is a metric unit of pressure defined as 100,000 Pa (100 kPa), though not part of the International System of Units (SI). A pressure of 1 bar is slightly less than the current average atmospheric pressure on Earth at sea level (approximately 1.013 bar).</summary>
        [[nodiscard]] static constexpr Pressure from_bars(const un_scalar_t value)
        {
            return Pressure(value, PressureUnit::Bars);
        }

        /// <summary>The bar is a metric unit of pressure defined as 100,000 Pa (100 kPa), though not part of the International System of Units (SI). A pressure of 1 bar is slightly less than the current average atmospheric pressure on Earth at sea level (approximately 1.013 bar).</summary>
        [[nodiscard]] constexpr un_scalar_t microbars() const
        {
            return convert_from_base(PressureUnit::Microbars);
        }

        /// <summary>The bar is a metric unit of pressure defined as 100,000 Pa (100 kPa), though not part of the International System of Units (SI). A pressure of 1 bar is slightly less than the current average atmospheric pressure on Earth at sea level (approximately 1.013 bar).</summary>
        [[nodiscard]] static constexpr Pressure from_microbars(const un_scalar_t value)
        {
            return Pressure(value, PressureUnit::Microbars);
        }

        /// <summary>The bar is a metric unit of pressure defined as 100,000 Pa (100 kPa), though not part of the International System of Units (SI). A pressure of 1 bar is slightly less than the current average atmospheric pressure on Earth at sea level (approximately 1.013 bar).</summary>
        [[nodiscard]] constexpr un_scalar_t millibars() const
        {
            return convert_from_base(PressureUnit::Millibars);
        }

        /// <summary>The bar is a metric unit of pressure defined as 100,000 Pa (100 kPa), though not part of the International System of Units (SI). A pressure of 1 bar is slightly less than the current average atmospheric pressure on Earth at sea level (approximately 1.013 bar).</summary>
        [[nodiscard]] static constexpr Pressure from_millibars(const un_scalar_t value)
        {
            return Pressure(value, PressureUnit::Millibars);
        }

        /// <summary>The bar is a metric unit of pressure defined as 100,000 Pa (100 kPa), though not part of the International System of Units (SI). A pressure of 1 bar is slightly less than the current average atmospheric pressure on Earth at sea level (approximately 1.013 bar).</summary>
        [[nodiscard]] constexpr un_scalar_t centibars() const
        {
            return convert_from_base(PressureUnit::Centibars);
        }

        /// <summary>The bar is a metric unit of pressure defined as 100,000 Pa (100 kPa), though not part of the International System of Units (SI). A pressure of 1 bar is slightly less than the current average atmospheric pressure on Earth at sea level (approximately 1.013 bar).</summary>
        [[nodiscard]] static constexpr Pressure from_centibars(const un_scalar_t value)
        {
            return Pressure(value, PressureUnit::Centibars);
        }

        /// <summary>The bar is a metric unit of pressure defined as 100,000 Pa (100 kPa), though not part of the International System of Units (SI). A pressure of 1 bar is slightly less than the current average atmospheric pressure on Earth at sea level (approximately 1.013 bar).</summary>
        [[nodiscard]] constexpr un_scalar_t decibars() const
        {
            return convert_from_base(PressureUnit::Decibars);
        }

        /// <summary>The bar is a metric unit of pressure defined as 100,000 Pa (100 kPa), though not part of the International System of Units (SI). A pressure of 1 bar is slightly less than the current average atmospheric pressure on Earth at sea level (approximately 1.013 bar).</summary>
        [[nodiscard]] static constexpr Pressure from_decibars(const un_scalar_t value)
        {
            return Pressure(value, PressureUnit::Decibars);
        }

        /// <summary>The bar is a metric unit of pressure defined as 100,000 Pa (100 kPa), though not part of the International System of Units (SI). A pressure of 1 bar is slightly less than the current average atmospheric pressure on Earth at sea level (approximately 1.013 bar).</summary>
        [[nodiscard]] constexpr un_scalar_t kilobars() const
        {
            return convert_from_base(PressureUnit::Kilobars);
        }

        /// <summary>The bar is a metric unit of pressure defined as 100,000 Pa (100 kPa), though not part of the International System of Units (SI). A pressure of 1 bar is slightly less than the current average atmospheric pressure on Earth at sea level (approximately 1.013 bar).</summary>
        [[nodiscard]] static constexpr Pressure from_kilobars(const un_scalar_t value)
        {
            return Pressure(value, PressureUnit::Kilobars);
        }

        /// <summary>The bar is a metric unit of pressure defined as 100,000 Pa (100 kPa), though not part of the International System of Units (SI). A pressure of 1 bar is slightly less than the current average atmospheric pressure on Earth at sea level (approximately 1.013 bar).</summary>
        [[nodiscard]] constexpr un_scalar_t megabars() const
        {
            return convert_from_base(PressureUnit::Megabars);
        }

        /// <summary>The bar is a metric unit of pressure defined as 100,000 Pa (100 kPa), though not part of the International System of Units (SI). A pressure of 1 bar is slightly less than the current average atmospheric pressure on Earth at sea level (approximately 1.013 bar).</summary>
        [[nodiscard]] static constexpr Pressure from_megabars(const un_scalar_t value)
        {
            return Pressure(value, PressureUnit::Megabars);
        }

        [[nodiscard]] constexpr un_scalar_t kilograms_force_per_square_meter() const
        {
            return convert_from_base(PressureUnit::KilogramsForcePerSquareMeter);
        }

        [[nodiscard]] static constexpr Pressure from_kilograms_force_per_square_meter(const un_scalar_t value)
        {
            return Pressure(value, PressureUnit::KilogramsForcePerSquareMeter);
        }

        /// <summary>A kilogram-force per centimetre square (kgf/cm2), often just kilogram per square centimetre (kg/cm2), or kilopond per centimetre square (kp/cm2) is a deprecated unit of pressure using metric units. It is not a part of the International System of Units (SI), the modern metric system. 1 kgf/cm2 equals 98.0665 kPa (kilopascals). It is also known as a technical atmosphere (symbol: at).</summary>
        [[nodiscard]] constexpr un_scalar_t kilograms_force_per_square_centimeter() const
        {
            return convert_from_base(PressureUnit::KilogramsForcePerSquareCentimeter);
        }

        /// <summary>A kilogram-force per centimetre square (kgf/cm2), often just kilogram per square centimetre (kg/cm2), or kilopond per centimetre square (kp/cm2) is a deprecated unit of pressure using metric units. It is not a part of the International System of Units (SI), the modern metric system. 1 kgf/cm2 equals 98.0665 kPa (kilopascals). It is also known as a technical atmosphere (symbol: at).</summary>
        [[nodiscard]] static constexpr Pressure from_kilograms_force_per_square_centimeter(const un_scalar_t value)
        {
            return Pressure(value, PressureUnit::KilogramsForcePerSquareCentimeter);
        }

        [[nodiscard]] constexpr un_scalar_t kilograms_force_per_square_millimeter() const
        {
            return convert_from_base(PressureUnit::KilogramsForcePerSquareMillimeter);
        }

        [[nodiscard]] static constexpr Pressure from_kilograms_force_per_square_millimeter(const un_scalar_t value)
        {
            return Pressure(value, PressureUnit::KilogramsForcePerSquareMillimeter);
        }

        [[nodiscard]] constexpr un_scalar_t newtons_per_square_meter() const
        {
            return convert_from_base(PressureUnit::NewtonsPerSquareMeter);
        }

        [[nodiscard]] static constexpr Pressure from_newtons_per_square_meter(const un_scalar_t value)
        {
            return Pressure(value, PressureUnit::NewtonsPerSquareMeter);
        }

        [[nodiscard]] constexpr un_scalar_t kilonewtons_per_square_meter() const
        {
            return convert_from_base(PressureUnit::KilonewtonsPerSquareMeter);
        }

        [[nodiscard]] static constexpr Pressure from_kilonewtons_per_square_meter(const un_scalar_t value)
        {
            return Pressure(value, PressureUnit::KilonewtonsPerSquareMeter);
        }

        [[nodiscard]] constexpr un_scalar_t meganewtons_per_square_meter() const
        {
            return convert_from_base(PressureUnit::MeganewtonsPerSquareMeter);
        }

        [[nodiscard]] static constexpr Pressure from_meganewtons_per_square_meter(const un_scalar_t value)
        {
            return Pressure(value, PressureUnit::MeganewtonsPerSquareMeter);
        }

        [[nodiscard]] constexpr un_scalar_t newtons_per_square_centimeter() const
        {
            return convert_from_base(PressureUnit::NewtonsPerSquareCentimeter);
        }

        [[nodiscard]] static constexpr Pressure from_newtons_per_square_centimeter(const un_scalar_t value)
        {
            return Pressure(value, PressureUnit::NewtonsPerSquareCentimeter);
        }

        [[nodiscard]] constexpr un_scalar_t kilonewtons_per_square_centimeter() const
        {
            return convert_from_base(PressureUnit::KilonewtonsPerSquareCentimeter);
        }

        [[nodiscard]] static constexpr Pressure from_kilonewtons_per_square_centimeter(const un_scalar_t value)
        {
            return Pressure(value, PressureUnit::KilonewtonsPerSquareCentimeter);
        }

        [[nodiscard]] constexpr un_scalar_t newtons_per_square_millimeter() const
        {
            return convert_from_base(PressureUnit::NewtonsPerSquareMillimeter);
        }

        [[nodiscard]] static constexpr Pressure from_newtons_per_square_millimeter(const un_scalar_t value)
        {
            return Pressure(value, PressureUnit::NewtonsPerSquareMillimeter);
        }

        [[nodiscard]] constexpr un_scalar_t kilonewtons_per_square_millimeter() const
        {
            return convert_from_base(PressureUnit::KilonewtonsPerSquareMillimeter);
        }

        [[nodiscard]] static constexpr Pressure from_kilonewtons_per_square_millimeter(const un_scalar_t value)
        {
            return Pressure(value, PressureUnit::KilonewtonsPerSquareMillimeter);
        }

        /// <summary>A kilogram-force per centimetre square (kgf/cm2), often just kilogram per square centimetre (kg/cm2), or kilopond per centimetre square (kp/cm2) is a deprecated unit of pressure using metric units. It is not a part of the International System of Units (SI), the modern metric system. 1 kgf/cm2 equals 98.0665 kPa (kilopascals). It is also known as a technical atmosphere (symbol: at).</summary>
        [[nodiscard]] constexpr un_scalar_t technical_atmospheres() const
        {
            return convert_from_base(PressureUnit::TechnicalAtmospheres);
        }

        /// <summary>A kilogram-force per centimetre square (kgf/cm2), often just kilogram per square centimetre (kg/cm2), or kilopond per centimetre square (kp/cm2) is a deprecated unit of pressure using metric units. It is not a part of the International System of Units (SI), the modern metric system. 1 kgf/cm2 equals 98.0665 kPa (kilopascals). It is also known as a technical atmosphere (symbol: at).</summary>
        [[nodiscard]] static constexpr Pressure from_technical_atmospheres(const un_scalar_t value)
        {
            return Pressure(value, PressureUnit::TechnicalAtmospheres);
        }

        /// <summary>The torr (symbol: Torr) is a unit of pressure based on an absolute scale, defined as exactly 1/760 of a standard atmosphere (101325 Pa). Thus one torr is exactly 101325/760 pascals (≈ 133.32 Pa).</summary>
        [[nodiscard]] constexpr un_scalar_t torrs() const
        {
            return convert_from_base(PressureUnit::Torrs);
        }

        /// <summary>The torr (symbol: Torr) is a unit of pressure based on an absolute scale, defined as exactly 1/760 of a standard atmosphere (101325 Pa). Thus one torr is exactly 101325/760 pascals (≈ 133.32 Pa).</summary>
        [[nodiscard]] static constexpr Pressure from_torrs(const un_scalar_t value)
        {
            return Pressure(value, PressureUnit::Torrs);
        }

        /// <summary>The torr (symbol: Torr) is a unit of pressure based on an absolute scale, defined as exactly 1/760 of a standard atmosphere (101325 Pa). Thus one torr is exactly 101325/760 pascals (≈ 133.32 Pa).</summary>
        [[nodiscard]] constexpr un_scalar_t millitorrs() const
        {
            return convert_from_base(PressureUnit::Millitorrs);
        }

        /// <summary>The torr (symbol: Torr) is a unit of pressure based on an absolute scale, defined as exactly 1/760 of a standard atmosphere (101325 Pa). Thus one torr is exactly 101325/760 pascals (≈ 133.32 Pa).</summary>
        [[nodiscard]] static constexpr Pressure from_millitorrs(const un_scalar_t value)
        {
            return Pressure(value, PressureUnit::Millitorrs);
        }

        [[nodiscard]] constexpr un_scalar_t pounds_force_per_square_inch() const
        {
            return convert_from_base(PressureUnit::PoundsForcePerSquareInch);
        }

        [[nodiscard]] static constexpr Pressure from_pounds_force_per_square_inch(const un_scalar_t value)
        {
            return Pressure(value, PressureUnit::PoundsForcePerSquareInch);
        }

        [[nodiscard]] constexpr un_scalar_t kilopounds_force_per_square_inch() const
        {
            return convert_from_base(PressureUnit::KilopoundsForcePerSquareInch);
        }

        [[nodiscard]] static constexpr Pressure from_kilopounds_force_per_square_inch(const un_scalar_t value)
        {
            return Pressure(value, PressureUnit::KilopoundsForcePerSquareInch);
        }

        [[nodiscard]] constexpr un_scalar_t pounds_force_per_square_mil() const
        {
            return convert_from_base(PressureUnit::PoundsForcePerSquareMil);
        }

        [[nodiscard]] static constexpr Pressure from_pounds_force_per_square_mil(const un_scalar_t value)
        {
            return Pressure(value, PressureUnit::PoundsForcePerSquareMil);
        }

        [[nodiscard]] constexpr un_scalar_t kilopounds_force_per_square_mil() const
        {
            return convert_from_base(PressureUnit::KilopoundsForcePerSquareMil);
        }

        [[nodiscard]] static constexpr Pressure from_kilopounds_force_per_square_mil(const un_scalar_t value)
        {
            return Pressure(value, PressureUnit::KilopoundsForcePerSquareMil);
        }

        [[nodiscard]] constexpr un_scalar_t pounds_force_per_square_foot() const
        {
            return convert_from_base(PressureUnit::PoundsForcePerSquareFoot);
        }

        [[nodiscard]] static constexpr Pressure from_pounds_force_per_square_foot(const un_scalar_t value)
        {
            return Pressure(value, PressureUnit::PoundsForcePerSquareFoot);
        }

        [[nodiscard]] constexpr un_scalar_t kilopounds_force_per_square_foot() const
        {
            return convert_from_base(PressureUnit::KilopoundsForcePerSquareFoot);
        }

        [[nodiscard]] static constexpr Pressure from_kilopounds_force_per_square_foot(const un_scalar_t value)
        {
            return Pressure(value, PressureUnit::KilopoundsForcePerSquareFoot);
        }

        [[nodiscard]] constexpr un_scalar_t tonnes_force_per_square_millimeter() const
        {
            return convert_from_base(PressureUnit::TonnesForcePerSquareMillimeter);
        }

        [[nodiscard]] static constexpr Pressure from_tonnes_force_per_square_millimeter(const un_scalar_t value)
        {
            return Pressure(value, PressureUnit::TonnesForcePerSquareMillimeter);
        }

        [[nodiscard]] constexpr un_scalar_t tonnes_force_per_square_meter() const
        {
            return convert_from_base(PressureUnit::TonnesForcePerSquareMeter);
        }

        [[nodiscard]] static constexpr Pressure from_tonnes_force_per_square_meter(const un_scalar_t value)
        {
            return Pressure(value, PressureUnit::TonnesForcePerSquareMeter);
        }

        [[nodiscard]] constexpr un_scalar_t meters_of_head() const
        {
            return convert_from_base(PressureUnit::MetersOfHead);
        }

        [[nodiscard]] static constexpr Pressure from_meters_of_head(const un_scalar_t value)
        {
            return Pressure(value, PressureUnit::MetersOfHead);
        }

        [[nodiscard]] constexpr un_scalar_t tonnes_force_per_square_centimeter() const
        {
            return convert_from_base(PressureUnit::TonnesForcePerSquareCentimeter);
        }

        [[nodiscard]] static constexpr Pressure from_tonnes_force_per_square_centimeter(const un_scalar_t value)
        {
            return Pressure(value, PressureUnit::TonnesForcePerSquareCentimeter);
        }

        [[nodiscard]] constexpr un_scalar_t feet_of_head() const
        {
            return convert_from_base(PressureUnit::FeetOfHead);
        }

        [[nodiscard]] static constexpr Pressure from_feet_of_head(const un_scalar_t value)
        {
            return Pressure(value, PressureUnit::FeetOfHead);
        }

        /// <summary>A millimetre of mercury is a manometric unit of pressure, formerly defined as the extra pressure generated by a column of mercury one millimetre high, and currently defined as exactly 133.322387415 pascals.</summary>
        [[nodiscard]] constexpr un_scalar_t millimeters_of_mercury() const
        {
            return convert_from_base(PressureUnit::MillimetersOfMercury);
        }

        /// <summary>A millimetre of mercury is a manometric unit of pressure, formerly defined as the extra pressure generated by a column of mercury one millimetre high, and currently defined as exactly 133.322387415 pascals.</summary>
        [[nodiscard]] static constexpr Pressure from_millimeters_of_mercury(const un_scalar_t value)
        {
            return Pressure(value, PressureUnit::MillimetersOfMercury);
        }

        /// <summary>Inch of mercury (inHg and ″Hg) is a non-SI unit of measurement for pressure. It is used for barometric pressure in weather reports, refrigeration and aviation in the United States. It is the pressure exerted by a column of mercury 1 inch (25.4 mm) in height at the standard acceleration of gravity.</summary>
        [[nodiscard]] constexpr un_scalar_t inches_of_mercury() const
        {
            return convert_from_base(PressureUnit::InchesOfMercury);
        }

        /// <summary>Inch of mercury (inHg and ″Hg) is a non-SI unit of measurement for pressure. It is used for barometric pressure in weather reports, refrigeration and aviation in the United States. It is the pressure exerted by a column of mercury 1 inch (25.4 mm) in height at the standard acceleration of gravity.</summary>
        [[nodiscard]] static constexpr Pressure from_inches_of_mercury(const un_scalar_t value)
        {
            return Pressure(value, PressureUnit::InchesOfMercury);
        }

        [[nodiscard]] constexpr un_scalar_t dynes_per_square_centimeter() const
        {
            return convert_from_base(PressureUnit::DynesPerSquareCentimeter);
        }

        [[nodiscard]] static constexpr Pressure from_dynes_per_square_centimeter(const un_scalar_t value)
        {
            return Pressure(value, PressureUnit::DynesPerSquareCentimeter);
        }

        [[nodiscard]] constexpr un_scalar_t pounds_per_inch_second_squared() const
        {
            return convert_from_base(PressureUnit::PoundsPerInchSecondSquared);
        }

        [[nodiscard]] static constexpr Pressure from_pounds_per_inch_second_squared(const un_scalar_t value)
        {
            return Pressure(value, PressureUnit::PoundsPerInchSecondSquared);
        }

        /// <summary>A centimetre of water is defined as the pressure exerted by a column of water of 1 cm in height at 4 °C (temperature of maximum density) at the standard acceleration of gravity, so that 1 cmH2O (4°C) = 999.9720 kg/m3 × 9.80665 m/s2 × 1 cm = 98.063754138 Pa, but conventionally a nominal maximum water density of 1000 kg/m3 is used, giving 98.0665 Pa.</summary>
        [[nodiscard]] constexpr un_scalar_t meters_of_water_column() const
        {
            return convert_from_base(PressureUnit::MetersOfWaterColumn);
        }

        /// <summary>A centimetre of water is defined as the pressure exerted by a column of water of 1 cm in height at 4 °C (temperature of maximum density) at the standard acceleration of gravity, so that 1 cmH2O (4°C) = 999.9720 kg/m3 × 9.80665 m/s2 × 1 cm = 98.063754138 Pa, but conventionally a nominal maximum water density of 1000 kg/m3 is used, giving 98.0665 Pa.</summary>
        [[nodiscard]] static constexpr Pressure from_meters_of_water_column(const un_scalar_t value)
        {
            return Pressure(value, PressureUnit::MetersOfWaterColumn);
        }

        /// <summary>A centimetre of water is defined as the pressure exerted by a column of water of 1 cm in height at 4 °C (temperature of maximum density) at the standard acceleration of gravity, so that 1 cmH2O (4°C) = 999.9720 kg/m3 × 9.80665 m/s2 × 1 cm = 98.063754138 Pa, but conventionally a nominal maximum water density of 1000 kg/m3 is used, giving 98.0665 Pa.</summary>
        [[nodiscard]] constexpr un_scalar_t millimeters_of_water_column() const
        {
            return convert_from_base(PressureUnit::MillimetersOfWaterColumn);
        }

        /// <summary>A centimetre of water is defined as the pressure exerted by a column of water of 1 cm in height at 4 °C (temperature of maximum density) at the standard acceleration of gravity, so that 1 cmH2O (4°C) = 999.9720 kg/m3 × 9.80665 m/s2 × 1 cm = 98.063754138 Pa, but conventionally a nominal maximum water density of 1000 kg/m3 is used, giving 98.0665 Pa.</summary>
        [[nodiscard]] static constexpr Pressure from_millimeters_of_water_column(const un_scalar_t value)
        {
            return Pressure(value, PressureUnit::MillimetersOfWaterColumn);
        }

        /// <summary>A centimetre of water is defined as the pressure exerted by a column of water of 1 cm in height at 4 °C (temperature of maximum density) at the standard acceleration of gravity, so that 1 cmH2O (4°C) = 999.9720 kg/m3 × 9.80665 m/s2 × 1 cm = 98.063754138 Pa, but conventionally a nominal maximum water density of 1000 kg/m3 is used, giving 98.0665 Pa.</summary>
        [[nodiscard]] constexpr un_scalar_t centimeters_of_water_column() const
        {
            return convert_from_base(PressureUnit::CentimetersOfWaterColumn);
        }

        /// <summary>A centimetre of water is defined as the pressure exerted by a column of water of 1 cm in height at 4 °C (temperature of maximum density) at the standard acceleration of gravity, so that 1 cmH2O (4°C) = 999.9720 kg/m3 × 9.80665 m/s2 × 1 cm = 98.063754138 Pa, but conventionally a nominal maximum water density of 1000 kg/m3 is used, giving 98.0665 Pa.</summary>
        [[nodiscard]] static constexpr Pressure from_centimeters_of_water_column(const un_scalar_t value)
        {
            return Pressure(value, PressureUnit::CentimetersOfWaterColumn);
        }

        /// <summary>Inches of water is a non-SI unit for pressure. It is defined as the pressure exerted by a column of water of 1 inch in height at defined conditions. At a temperature of 4 °C (39.2 °F) pure water has its highest density (1000 kg/m3). At that temperature and assuming the standard acceleration of gravity, 1 inAq is approximately 249.082 pascals (0.0361263 psi).</summary>
        [[nodiscard]] constexpr un_scalar_t inches_of_water_column() const
        {
            return convert_from_base(PressureUnit::InchesOfWaterColumn);
        }

        /// <summary>Inches of water is a non-SI unit for pressure. It is defined as the pressure exerted by a column of water of 1 inch in height at defined conditions. At a temperature of 4 °C (39.2 °F) pure water has its highest density (1000 kg/m3). At that temperature and assuming the standard acceleration of gravity, 1 inAq is approximately 249.082 pascals (0.0361263 psi).</summary>
        [[nodiscard]] static constexpr Pressure from_inches_of_water_column(const un_scalar_t value)
        {
            return Pressure(value, PressureUnit::InchesOfWaterColumn);
        }

        [[nodiscard]] constexpr un_scalar_t milligrams_force_per_square_meter() const
        {
            return convert_from_base(PressureUnit::MilligramsForcePerSquareMeter);
        }

        [[nodiscard]] static constexpr Pressure from_milligrams_force_per_square_meter(const un_scalar_t value)
        {
            return Pressure(value, PressureUnit::MilligramsForcePerSquareMeter);
        }

        [[nodiscard]] constexpr un_scalar_t milligrams_force_per_square_foot() const
        {
            return convert_from_base(PressureUnit::MilligramsForcePerSquareFoot);
        }

        [[nodiscard]] static constexpr Pressure from_milligrams_force_per_square_foot(const un_scalar_t value)
        {
            return Pressure(value, PressureUnit::MilligramsForcePerSquareFoot);
        }

        [[nodiscard]] static constexpr Pressure from_invalid()
        {
            return Pressure(false);
        }
    private:
            
        [[nodiscard]] static constexpr un_scalar_t convert_to_base(un_scalar_t value, PressureUnit unit)
        {
            switch (unit)
            {

            case PressureUnit::Pascals:
                return value;

            case PressureUnit::Micropascals:
                return (value * static_cast<un_scalar_t>(1e-6));

            case PressureUnit::Millipascals:
                return (value * static_cast<un_scalar_t>(1e-3));

            case PressureUnit::Decapascals:
                return (value * static_cast<un_scalar_t>(1e1));

            case PressureUnit::Hectopascals:
                return (value * static_cast<un_scalar_t>(1e2));

            case PressureUnit::Kilopascals:
                return (value * static_cast<un_scalar_t>(1e3));

            case PressureUnit::Megapascals:
                return (value * static_cast<un_scalar_t>(1e6));

            case PressureUnit::Gigapascals:
                return (value * static_cast<un_scalar_t>(1e9));

            case PressureUnit::Atmospheres:
                return value * static_cast<un_scalar_t>(1.01325) * static_cast<un_scalar_t>(1e5);

            case PressureUnit::Bars:
                return value * static_cast<un_scalar_t>(1e5);

            case PressureUnit::Microbars:
                return (value * static_cast<un_scalar_t>(1e-6)) * static_cast<un_scalar_t>(1e5);

            case PressureUnit::Millibars:
                return (value * static_cast<un_scalar_t>(1e-3)) * static_cast<un_scalar_t>(1e5);

            case PressureUnit::Centibars:
                return (value * static_cast<un_scalar_t>(1e-2)) * static_cast<un_scalar_t>(1e5);

            case PressureUnit::Decibars:
                return (value * static_cast<un_scalar_t>(1e-1)) * static_cast<un_scalar_t>(1e5);

            case PressureUnit::Kilobars:
                return (value * static_cast<un_scalar_t>(1e3)) * static_cast<un_scalar_t>(1e5);

            case PressureUnit::Megabars:
                return (value * static_cast<un_scalar_t>(1e6)) * static_cast<un_scalar_t>(1e5);

            case PressureUnit::KilogramsForcePerSquareMeter:
                return value * static_cast<un_scalar_t>(9.80665);

            case PressureUnit::KilogramsForcePerSquareCentimeter:
                return value * static_cast<un_scalar_t>(9.80665e4);

            case PressureUnit::KilogramsForcePerSquareMillimeter:
                return value * static_cast<un_scalar_t>(9.80665e6);

            case PressureUnit::NewtonsPerSquareMeter:
                return value;

            case PressureUnit::KilonewtonsPerSquareMeter:
                return (value * static_cast<un_scalar_t>(1e3));

            case PressureUnit::MeganewtonsPerSquareMeter:
                return (value * static_cast<un_scalar_t>(1e6));

            case PressureUnit::NewtonsPerSquareCentimeter:
                return value * static_cast<un_scalar_t>(1e4);

            case PressureUnit::KilonewtonsPerSquareCentimeter:
                return (value * static_cast<un_scalar_t>(1e3)) * static_cast<un_scalar_t>(1e4);

            case PressureUnit::NewtonsPerSquareMillimeter:
                return value * static_cast<un_scalar_t>(1e6);

            case PressureUnit::KilonewtonsPerSquareMillimeter:
                return (value * static_cast<un_scalar_t>(1e3)) * static_cast<un_scalar_t>(1e6);

            case PressureUnit::TechnicalAtmospheres:
                return value * static_cast<un_scalar_t>(9.80665e4);

            case PressureUnit::Torrs:
                return value * static_cast<un_scalar_t>(101325) / static_cast<un_scalar_t>(760);

            case PressureUnit::Millitorrs:
                return (value * static_cast<un_scalar_t>(1e-3)) * static_cast<un_scalar_t>(101325) / static_cast<un_scalar_t>(760);

            case PressureUnit::PoundsForcePerSquareInch:
                return value * static_cast<un_scalar_t>(4.4482216152605) / static_cast<un_scalar_t>(0.00064516);

            case PressureUnit::KilopoundsForcePerSquareInch:
                return (value * static_cast<un_scalar_t>(1e3)) * static_cast<un_scalar_t>(4.4482216152605) / static_cast<un_scalar_t>(0.00064516);

            case PressureUnit::PoundsForcePerSquareMil:
                return value * static_cast<un_scalar_t>(4.4482216152605) / (static_cast<un_scalar_t>(2.54e-5) * static_cast<un_scalar_t>(2.54e-5));

            case PressureUnit::KilopoundsForcePerSquareMil:
                return (value * static_cast<un_scalar_t>(1e3)) * static_cast<un_scalar_t>(4.4482216152605) / (static_cast<un_scalar_t>(2.54e-5) * static_cast<un_scalar_t>(2.54e-5));

            case PressureUnit::PoundsForcePerSquareFoot:
                return value * static_cast<un_scalar_t>(4.4482216152605) / static_cast<un_scalar_t>(9.290304e-2);

            case PressureUnit::KilopoundsForcePerSquareFoot:
                return (value * static_cast<un_scalar_t>(1e3)) * static_cast<un_scalar_t>(4.4482216152605) / static_cast<un_scalar_t>(9.290304e-2);

            case PressureUnit::TonnesForcePerSquareMillimeter:
                return value * static_cast<un_scalar_t>(9.80665e9);

            case PressureUnit::TonnesForcePerSquareMeter:
                return value * static_cast<un_scalar_t>(9.80665e3);

            case PressureUnit::MetersOfHead:
                return value * static_cast<un_scalar_t>(9804.139432);

            case PressureUnit::TonnesForcePerSquareCentimeter:
                return value * static_cast<un_scalar_t>(9.80665e7);

            case PressureUnit::FeetOfHead:
                return value * static_cast<un_scalar_t>(9804.139432) * static_cast<un_scalar_t>(0.3048);

            case PressureUnit::MillimetersOfMercury:
                return value * static_cast<un_scalar_t>(133.322387415);

            case PressureUnit::InchesOfMercury:
                return value * static_cast<un_scalar_t>(2.54e1) * static_cast<un_scalar_t>(133.322387415);

            case PressureUnit::DynesPerSquareCentimeter:
                return value * static_cast<un_scalar_t>(1.0e-1);

            case PressureUnit::PoundsPerInchSecondSquared:
                return value * (static_cast<un_scalar_t>(4.4482216152605) / static_cast<un_scalar_t>(0.00064516)) / static_cast<un_scalar_t>(386.0886);

            case PressureUnit::MetersOfWaterColumn:
                return value * static_cast<un_scalar_t>(9.80665e3);

            case PressureUnit::MillimetersOfWaterColumn:
                return (value * static_cast<un_scalar_t>(1e-3)) * static_cast<un_scalar_t>(9.80665e3);

            case PressureUnit::CentimetersOfWaterColumn:
                return (value * static_cast<un_scalar_t>(1e-2)) * static_cast<un_scalar_t>(9.80665e3);

            case PressureUnit::InchesOfWaterColumn:
                return value * static_cast<un_scalar_t>(2.54e-2) * static_cast<un_scalar_t>(9.80665e3);

            case PressureUnit::MilligramsForcePerSquareMeter:
                return value * static_cast<un_scalar_t>(9.80665e-6);

            case PressureUnit::MilligramsForcePerSquareFoot:
                return value * static_cast<un_scalar_t>(9.80665e-6) / static_cast<un_scalar_t>(9.290304e-2);

            }

            throw std::invalid_argument("Unknown Pressure unit.");
        }

        [[nodiscard]] constexpr un_scalar_t convert_from_base(const PressureUnit unit) const
        {
            if(unit == value_unit_type_)
            {
                return value_;
            }
            
            auto base_value = convert_to_base(value_, value_unit_type_);
            
            switch (unit)
            {

            case PressureUnit::Pascals:
                return base_value;

            case PressureUnit::Micropascals:
                return (base_value) / static_cast<un_scalar_t>(1e-6);

            case PressureUnit::Millipascals:
                return (base_value) / static_cast<un_scalar_t>(1e-3);

            case PressureUnit::Decapascals:
                return (base_value) / static_cast<un_scalar_t>(1e1);

            case PressureUnit::Hectopascals:
                return (base_value) / static_cast<un_scalar_t>(1e2);

            case PressureUnit::Kilopascals:
                return (base_value) / static_cast<un_scalar_t>(1e3);

            case PressureUnit::Megapascals:
                return (base_value) / static_cast<un_scalar_t>(1e6);

            case PressureUnit::Gigapascals:
                return (base_value) / static_cast<un_scalar_t>(1e9);

            case PressureUnit::Atmospheres:
                return base_value / (static_cast<un_scalar_t>(1.01325) * static_cast<un_scalar_t>(1e5));

            case PressureUnit::Bars:
                return base_value / static_cast<un_scalar_t>(1e5);

            case PressureUnit::Microbars:
                return (base_value / static_cast<un_scalar_t>(1e5)) / static_cast<un_scalar_t>(1e-6);

            case PressureUnit::Millibars:
                return (base_value / static_cast<un_scalar_t>(1e5)) / static_cast<un_scalar_t>(1e-3);

            case PressureUnit::Centibars:
                return (base_value / static_cast<un_scalar_t>(1e5)) / static_cast<un_scalar_t>(1e-2);

            case PressureUnit::Decibars:
                return (base_value / static_cast<un_scalar_t>(1e5)) / static_cast<un_scalar_t>(1e-1);

            case PressureUnit::Kilobars:
                return (base_value / static_cast<un_scalar_t>(1e5)) / static_cast<un_scalar_t>(1e3);

            case PressureUnit::Megabars:
                return (base_value / static_cast<un_scalar_t>(1e5)) / static_cast<un_scalar_t>(1e6);

            case PressureUnit::KilogramsForcePerSquareMeter:
                return base_value / static_cast<un_scalar_t>(9.80665);

            case PressureUnit::KilogramsForcePerSquareCentimeter:
                return base_value / static_cast<un_scalar_t>(9.80665e4);

            case PressureUnit::KilogramsForcePerSquareMillimeter:
                return base_value / static_cast<un_scalar_t>(9.80665e6);

            case PressureUnit::NewtonsPerSquareMeter:
                return base_value;

            case PressureUnit::KilonewtonsPerSquareMeter:
                return (base_value) / static_cast<un_scalar_t>(1e3);

            case PressureUnit::MeganewtonsPerSquareMeter:
                return (base_value) / static_cast<un_scalar_t>(1e6);

            case PressureUnit::NewtonsPerSquareCentimeter:
                return base_value / static_cast<un_scalar_t>(1e4);

            case PressureUnit::KilonewtonsPerSquareCentimeter:
                return (base_value / static_cast<un_scalar_t>(1e4)) / static_cast<un_scalar_t>(1e3);

            case PressureUnit::NewtonsPerSquareMillimeter:
                return base_value / static_cast<un_scalar_t>(1e6);

            case PressureUnit::KilonewtonsPerSquareMillimeter:
                return (base_value / static_cast<un_scalar_t>(1e6)) / static_cast<un_scalar_t>(1e3);

            case PressureUnit::TechnicalAtmospheres:
                return base_value / static_cast<un_scalar_t>(9.80665e4);

            case PressureUnit::Torrs:
                return base_value * static_cast<un_scalar_t>(760) / static_cast<un_scalar_t>(101325);

            case PressureUnit::Millitorrs:
                return (base_value * static_cast<un_scalar_t>(760) / static_cast<un_scalar_t>(101325)) / static_cast<un_scalar_t>(1e-3);

            case PressureUnit::PoundsForcePerSquareInch:
                return base_value * static_cast<un_scalar_t>(0.00064516) / static_cast<un_scalar_t>(4.4482216152605);

            case PressureUnit::KilopoundsForcePerSquareInch:
                return (base_value * static_cast<un_scalar_t>(0.00064516) / static_cast<un_scalar_t>(4.4482216152605)) / static_cast<un_scalar_t>(1e3);

            case PressureUnit::PoundsForcePerSquareMil:
                return base_value * (static_cast<un_scalar_t>(2.54e-5) * static_cast<un_scalar_t>(2.54e-5)) / static_cast<un_scalar_t>(4.4482216152605);

            case PressureUnit::KilopoundsForcePerSquareMil:
                return (base_value * (static_cast<un_scalar_t>(2.54e-5) * static_cast<un_scalar_t>(2.54e-5)) / static_cast<un_scalar_t>(4.4482216152605)) / static_cast<un_scalar_t>(1e3);

            case PressureUnit::PoundsForcePerSquareFoot:
                return base_value * static_cast<un_scalar_t>(9.290304e-2) / static_cast<un_scalar_t>(4.4482216152605);

            case PressureUnit::KilopoundsForcePerSquareFoot:
                return (base_value * static_cast<un_scalar_t>(9.290304e-2) / static_cast<un_scalar_t>(4.4482216152605)) / static_cast<un_scalar_t>(1e3);

            case PressureUnit::TonnesForcePerSquareMillimeter:
                return base_value / static_cast<un_scalar_t>(9.80665e9);

            case PressureUnit::TonnesForcePerSquareMeter:
                return base_value / static_cast<un_scalar_t>(9.80665e3);

            case PressureUnit::MetersOfHead:
                return base_value / static_cast<un_scalar_t>(9804.139432);

            case PressureUnit::TonnesForcePerSquareCentimeter:
                return base_value / static_cast<un_scalar_t>(9.80665e7);

            case PressureUnit::FeetOfHead:
                return base_value / (static_cast<un_scalar_t>(9804.139432) * static_cast<un_scalar_t>(0.3048));

            case PressureUnit::MillimetersOfMercury:
                return base_value / static_cast<un_scalar_t>(133.322387415);

            case PressureUnit::InchesOfMercury:
                return base_value / (static_cast<un_scalar_t>(2.54e1) * static_cast<un_scalar_t>(133.322387415));

            case PressureUnit::DynesPerSquareCentimeter:
                return base_value / static_cast<un_scalar_t>(1.0e-1);

            case PressureUnit::PoundsPerInchSecondSquared:
                return base_value * static_cast<un_scalar_t>(386.0886) / (static_cast<un_scalar_t>(4.4482216152605) / static_cast<un_scalar_t>(0.00064516));

            case PressureUnit::MetersOfWaterColumn:
                return base_value / static_cast<un_scalar_t>(9.80665e3);

            case PressureUnit::MillimetersOfWaterColumn:
                return (base_value / static_cast<un_scalar_t>(9.80665e3)) / static_cast<un_scalar_t>(1e-3);

            case PressureUnit::CentimetersOfWaterColumn:
                return (base_value / static_cast<un_scalar_t>(9.80665e3)) / static_cast<un_scalar_t>(1e-2);

            case PressureUnit::InchesOfWaterColumn:
                return base_value / (static_cast<un_scalar_t>(2.54e-2) * static_cast<un_scalar_t>(9.80665e3));

            case PressureUnit::MilligramsForcePerSquareMeter:
                return base_value / static_cast<un_scalar_t>(9.80665e-6);

            case PressureUnit::MilligramsForcePerSquareFoot:
                return base_value / static_cast<un_scalar_t>(9.80665e-6) * static_cast<un_scalar_t>(9.290304e-2);

            }

            throw std::invalid_argument("Unknown Pressure unit.");
        }

        un_scalar_t value_;
        PressureUnit value_unit_type_;       
    };
}
