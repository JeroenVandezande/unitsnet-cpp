#pragma once

#include <cstdint>
#include <numbers>
#include <stdexcept>
#include "UnitsNetConfig.h"
#include "UnitsNetBase.h"

namespace unitsnet_cpp
{
    enum class LinearPowerDensityUnit : std::uint8_t
    {
        WattsPerMeter,
        MilliwattsPerMeter,
        KilowattsPerMeter,
        MegawattsPerMeter,
        GigawattsPerMeter,
        WattsPerCentimeter,
        MilliwattsPerCentimeter,
        KilowattsPerCentimeter,
        MegawattsPerCentimeter,
        GigawattsPerCentimeter,
        WattsPerMillimeter,
        MilliwattsPerMillimeter,
        KilowattsPerMillimeter,
        MegawattsPerMillimeter,
        GigawattsPerMillimeter,
        WattsPerInch,
        MilliwattsPerInch,
        KilowattsPerInch,
        MegawattsPerInch,
        GigawattsPerInch,
        WattsPerFoot,
        MilliwattsPerFoot,
        KilowattsPerFoot,
        MegawattsPerFoot,
        GigawattsPerFoot,
    };

    /// <summary>The Linear Power Density of a substance is its power per unit length.  The term linear density is most often used when describing the characteristics of one-dimensional objects, although linear density can also be used to describe the density of a three-dimensional quantity along one particular dimension.</summary>
    class LinearPowerDensity : public UnitsNetBase
    {
    public:
        constexpr explicit LinearPowerDensity(
            const un_scalar_t value,
            const LinearPowerDensityUnit unit = LinearPowerDensityUnit::WattsPerMeter)
        {
            value_ = value;
            value_unit_type_ = unit;
        }
        
        [[nodiscard]] constexpr un_scalar_t stored_value() const noexcept override
        {
           return value_; 
        }
        
        [[nodiscard]] constexpr std::string_view quantity_name() const noexcept override
        {
           return "LinearPowerDensity"; 
        }
        
        [[nodiscard]] constexpr std::string_view unit_name() const noexcept override
        {
            switch (value_unit_type_)
            {

            case LinearPowerDensityUnit::WattsPerMeter:
                return "WattsPerMeter";

            case LinearPowerDensityUnit::MilliwattsPerMeter:
                return "MilliwattsPerMeter";

            case LinearPowerDensityUnit::KilowattsPerMeter:
                return "KilowattsPerMeter";

            case LinearPowerDensityUnit::MegawattsPerMeter:
                return "MegawattsPerMeter";

            case LinearPowerDensityUnit::GigawattsPerMeter:
                return "GigawattsPerMeter";

            case LinearPowerDensityUnit::WattsPerCentimeter:
                return "WattsPerCentimeter";

            case LinearPowerDensityUnit::MilliwattsPerCentimeter:
                return "MilliwattsPerCentimeter";

            case LinearPowerDensityUnit::KilowattsPerCentimeter:
                return "KilowattsPerCentimeter";

            case LinearPowerDensityUnit::MegawattsPerCentimeter:
                return "MegawattsPerCentimeter";

            case LinearPowerDensityUnit::GigawattsPerCentimeter:
                return "GigawattsPerCentimeter";

            case LinearPowerDensityUnit::WattsPerMillimeter:
                return "WattsPerMillimeter";

            case LinearPowerDensityUnit::MilliwattsPerMillimeter:
                return "MilliwattsPerMillimeter";

            case LinearPowerDensityUnit::KilowattsPerMillimeter:
                return "KilowattsPerMillimeter";

            case LinearPowerDensityUnit::MegawattsPerMillimeter:
                return "MegawattsPerMillimeter";

            case LinearPowerDensityUnit::GigawattsPerMillimeter:
                return "GigawattsPerMillimeter";

            case LinearPowerDensityUnit::WattsPerInch:
                return "WattsPerInch";

            case LinearPowerDensityUnit::MilliwattsPerInch:
                return "MilliwattsPerInch";

            case LinearPowerDensityUnit::KilowattsPerInch:
                return "KilowattsPerInch";

            case LinearPowerDensityUnit::MegawattsPerInch:
                return "MegawattsPerInch";

            case LinearPowerDensityUnit::GigawattsPerInch:
                return "GigawattsPerInch";

            case LinearPowerDensityUnit::WattsPerFoot:
                return "WattsPerFoot";

            case LinearPowerDensityUnit::MilliwattsPerFoot:
                return "MilliwattsPerFoot";

            case LinearPowerDensityUnit::KilowattsPerFoot:
                return "KilowattsPerFoot";

            case LinearPowerDensityUnit::MegawattsPerFoot:
                return "MegawattsPerFoot";

            case LinearPowerDensityUnit::GigawattsPerFoot:
                return "GigawattsPerFoot";

            }
            
            return {};
        }
                
        [[nodiscard]] constexpr un_scalar_t base_value() const noexcept
        {
            return convert_to_base(value_, value_unit_type_);    
        }

        [[nodiscard]] constexpr un_scalar_t value(const LinearPowerDensityUnit unit) const
        {
            return convert_from_base(unit);
        }

        [[nodiscard]] constexpr LinearPowerDensity operator+(const LinearPowerDensity& other) const noexcept
        {
            return LinearPowerDensity(base_value() + other.base_value());
        }

        [[nodiscard]] constexpr LinearPowerDensity operator-(const LinearPowerDensity& other)const noexcept
        {
            return LinearPowerDensity(base_value() - other.base_value());
        }

        [[nodiscard]] constexpr LinearPowerDensity operator*(const un_scalar_t scalar) const noexcept
        {
            return LinearPowerDensity(base_value() * scalar);
        }

        [[nodiscard]] constexpr LinearPowerDensity operator/(const un_scalar_t scalar) const noexcept
        {
            return LinearPowerDensity(base_value() / scalar);
        }

        [[nodiscard]] constexpr bool operator==(const LinearPowerDensity& other) const noexcept
        {
            return base_value() == other.base_value();
        }

        [[nodiscard]] constexpr bool operator<(const LinearPowerDensity& other) const noexcept
        {
            return base_value() < other.base_value();
        }
        
        [[nodiscard]] constexpr bool operator>(const LinearPowerDensity& other) const noexcept
        {
            return base_value() > other.base_value();
        }

        [[nodiscard]] constexpr un_scalar_t watts_per_meter() const
        {
            return convert_from_base(LinearPowerDensityUnit::WattsPerMeter);
        }

        [[nodiscard]] static constexpr LinearPowerDensity from_watts_per_meter(const un_scalar_t value)
        {
            return LinearPowerDensity(value, LinearPowerDensityUnit::WattsPerMeter);
        }

        [[nodiscard]] constexpr un_scalar_t milliwatts_per_meter() const
        {
            return convert_from_base(LinearPowerDensityUnit::MilliwattsPerMeter);
        }

        [[nodiscard]] static constexpr LinearPowerDensity from_milliwatts_per_meter(const un_scalar_t value)
        {
            return LinearPowerDensity(value, LinearPowerDensityUnit::MilliwattsPerMeter);
        }

        [[nodiscard]] constexpr un_scalar_t kilowatts_per_meter() const
        {
            return convert_from_base(LinearPowerDensityUnit::KilowattsPerMeter);
        }

        [[nodiscard]] static constexpr LinearPowerDensity from_kilowatts_per_meter(const un_scalar_t value)
        {
            return LinearPowerDensity(value, LinearPowerDensityUnit::KilowattsPerMeter);
        }

        [[nodiscard]] constexpr un_scalar_t megawatts_per_meter() const
        {
            return convert_from_base(LinearPowerDensityUnit::MegawattsPerMeter);
        }

        [[nodiscard]] static constexpr LinearPowerDensity from_megawatts_per_meter(const un_scalar_t value)
        {
            return LinearPowerDensity(value, LinearPowerDensityUnit::MegawattsPerMeter);
        }

        [[nodiscard]] constexpr un_scalar_t gigawatts_per_meter() const
        {
            return convert_from_base(LinearPowerDensityUnit::GigawattsPerMeter);
        }

        [[nodiscard]] static constexpr LinearPowerDensity from_gigawatts_per_meter(const un_scalar_t value)
        {
            return LinearPowerDensity(value, LinearPowerDensityUnit::GigawattsPerMeter);
        }

        [[nodiscard]] constexpr un_scalar_t watts_per_centimeter() const
        {
            return convert_from_base(LinearPowerDensityUnit::WattsPerCentimeter);
        }

        [[nodiscard]] static constexpr LinearPowerDensity from_watts_per_centimeter(const un_scalar_t value)
        {
            return LinearPowerDensity(value, LinearPowerDensityUnit::WattsPerCentimeter);
        }

        [[nodiscard]] constexpr un_scalar_t milliwatts_per_centimeter() const
        {
            return convert_from_base(LinearPowerDensityUnit::MilliwattsPerCentimeter);
        }

        [[nodiscard]] static constexpr LinearPowerDensity from_milliwatts_per_centimeter(const un_scalar_t value)
        {
            return LinearPowerDensity(value, LinearPowerDensityUnit::MilliwattsPerCentimeter);
        }

        [[nodiscard]] constexpr un_scalar_t kilowatts_per_centimeter() const
        {
            return convert_from_base(LinearPowerDensityUnit::KilowattsPerCentimeter);
        }

        [[nodiscard]] static constexpr LinearPowerDensity from_kilowatts_per_centimeter(const un_scalar_t value)
        {
            return LinearPowerDensity(value, LinearPowerDensityUnit::KilowattsPerCentimeter);
        }

        [[nodiscard]] constexpr un_scalar_t megawatts_per_centimeter() const
        {
            return convert_from_base(LinearPowerDensityUnit::MegawattsPerCentimeter);
        }

        [[nodiscard]] static constexpr LinearPowerDensity from_megawatts_per_centimeter(const un_scalar_t value)
        {
            return LinearPowerDensity(value, LinearPowerDensityUnit::MegawattsPerCentimeter);
        }

        [[nodiscard]] constexpr un_scalar_t gigawatts_per_centimeter() const
        {
            return convert_from_base(LinearPowerDensityUnit::GigawattsPerCentimeter);
        }

        [[nodiscard]] static constexpr LinearPowerDensity from_gigawatts_per_centimeter(const un_scalar_t value)
        {
            return LinearPowerDensity(value, LinearPowerDensityUnit::GigawattsPerCentimeter);
        }

        [[nodiscard]] constexpr un_scalar_t watts_per_millimeter() const
        {
            return convert_from_base(LinearPowerDensityUnit::WattsPerMillimeter);
        }

        [[nodiscard]] static constexpr LinearPowerDensity from_watts_per_millimeter(const un_scalar_t value)
        {
            return LinearPowerDensity(value, LinearPowerDensityUnit::WattsPerMillimeter);
        }

        [[nodiscard]] constexpr un_scalar_t milliwatts_per_millimeter() const
        {
            return convert_from_base(LinearPowerDensityUnit::MilliwattsPerMillimeter);
        }

        [[nodiscard]] static constexpr LinearPowerDensity from_milliwatts_per_millimeter(const un_scalar_t value)
        {
            return LinearPowerDensity(value, LinearPowerDensityUnit::MilliwattsPerMillimeter);
        }

        [[nodiscard]] constexpr un_scalar_t kilowatts_per_millimeter() const
        {
            return convert_from_base(LinearPowerDensityUnit::KilowattsPerMillimeter);
        }

        [[nodiscard]] static constexpr LinearPowerDensity from_kilowatts_per_millimeter(const un_scalar_t value)
        {
            return LinearPowerDensity(value, LinearPowerDensityUnit::KilowattsPerMillimeter);
        }

        [[nodiscard]] constexpr un_scalar_t megawatts_per_millimeter() const
        {
            return convert_from_base(LinearPowerDensityUnit::MegawattsPerMillimeter);
        }

        [[nodiscard]] static constexpr LinearPowerDensity from_megawatts_per_millimeter(const un_scalar_t value)
        {
            return LinearPowerDensity(value, LinearPowerDensityUnit::MegawattsPerMillimeter);
        }

        [[nodiscard]] constexpr un_scalar_t gigawatts_per_millimeter() const
        {
            return convert_from_base(LinearPowerDensityUnit::GigawattsPerMillimeter);
        }

        [[nodiscard]] static constexpr LinearPowerDensity from_gigawatts_per_millimeter(const un_scalar_t value)
        {
            return LinearPowerDensity(value, LinearPowerDensityUnit::GigawattsPerMillimeter);
        }

        [[nodiscard]] constexpr un_scalar_t watts_per_inch() const
        {
            return convert_from_base(LinearPowerDensityUnit::WattsPerInch);
        }

        [[nodiscard]] static constexpr LinearPowerDensity from_watts_per_inch(const un_scalar_t value)
        {
            return LinearPowerDensity(value, LinearPowerDensityUnit::WattsPerInch);
        }

        [[nodiscard]] constexpr un_scalar_t milliwatts_per_inch() const
        {
            return convert_from_base(LinearPowerDensityUnit::MilliwattsPerInch);
        }

        [[nodiscard]] static constexpr LinearPowerDensity from_milliwatts_per_inch(const un_scalar_t value)
        {
            return LinearPowerDensity(value, LinearPowerDensityUnit::MilliwattsPerInch);
        }

        [[nodiscard]] constexpr un_scalar_t kilowatts_per_inch() const
        {
            return convert_from_base(LinearPowerDensityUnit::KilowattsPerInch);
        }

        [[nodiscard]] static constexpr LinearPowerDensity from_kilowatts_per_inch(const un_scalar_t value)
        {
            return LinearPowerDensity(value, LinearPowerDensityUnit::KilowattsPerInch);
        }

        [[nodiscard]] constexpr un_scalar_t megawatts_per_inch() const
        {
            return convert_from_base(LinearPowerDensityUnit::MegawattsPerInch);
        }

        [[nodiscard]] static constexpr LinearPowerDensity from_megawatts_per_inch(const un_scalar_t value)
        {
            return LinearPowerDensity(value, LinearPowerDensityUnit::MegawattsPerInch);
        }

        [[nodiscard]] constexpr un_scalar_t gigawatts_per_inch() const
        {
            return convert_from_base(LinearPowerDensityUnit::GigawattsPerInch);
        }

        [[nodiscard]] static constexpr LinearPowerDensity from_gigawatts_per_inch(const un_scalar_t value)
        {
            return LinearPowerDensity(value, LinearPowerDensityUnit::GigawattsPerInch);
        }

        [[nodiscard]] constexpr un_scalar_t watts_per_foot() const
        {
            return convert_from_base(LinearPowerDensityUnit::WattsPerFoot);
        }

        [[nodiscard]] static constexpr LinearPowerDensity from_watts_per_foot(const un_scalar_t value)
        {
            return LinearPowerDensity(value, LinearPowerDensityUnit::WattsPerFoot);
        }

        [[nodiscard]] constexpr un_scalar_t milliwatts_per_foot() const
        {
            return convert_from_base(LinearPowerDensityUnit::MilliwattsPerFoot);
        }

        [[nodiscard]] static constexpr LinearPowerDensity from_milliwatts_per_foot(const un_scalar_t value)
        {
            return LinearPowerDensity(value, LinearPowerDensityUnit::MilliwattsPerFoot);
        }

        [[nodiscard]] constexpr un_scalar_t kilowatts_per_foot() const
        {
            return convert_from_base(LinearPowerDensityUnit::KilowattsPerFoot);
        }

        [[nodiscard]] static constexpr LinearPowerDensity from_kilowatts_per_foot(const un_scalar_t value)
        {
            return LinearPowerDensity(value, LinearPowerDensityUnit::KilowattsPerFoot);
        }

        [[nodiscard]] constexpr un_scalar_t megawatts_per_foot() const
        {
            return convert_from_base(LinearPowerDensityUnit::MegawattsPerFoot);
        }

        [[nodiscard]] static constexpr LinearPowerDensity from_megawatts_per_foot(const un_scalar_t value)
        {
            return LinearPowerDensity(value, LinearPowerDensityUnit::MegawattsPerFoot);
        }

        [[nodiscard]] constexpr un_scalar_t gigawatts_per_foot() const
        {
            return convert_from_base(LinearPowerDensityUnit::GigawattsPerFoot);
        }

        [[nodiscard]] static constexpr LinearPowerDensity from_gigawatts_per_foot(const un_scalar_t value)
        {
            return LinearPowerDensity(value, LinearPowerDensityUnit::GigawattsPerFoot);
        }

        [[nodiscard]] static constexpr LinearPowerDensity from_invalid()
        {
            return LinearPowerDensity(false);
        }
    private:
            
        [[nodiscard]] static constexpr un_scalar_t convert_to_base(un_scalar_t value, LinearPowerDensityUnit unit)
        {
            switch (unit)
            {

            case LinearPowerDensityUnit::WattsPerMeter:
                return value;

            case LinearPowerDensityUnit::MilliwattsPerMeter:
                return (value * static_cast<un_scalar_t>(1e-3));

            case LinearPowerDensityUnit::KilowattsPerMeter:
                return (value * static_cast<un_scalar_t>(1e3));

            case LinearPowerDensityUnit::MegawattsPerMeter:
                return (value * static_cast<un_scalar_t>(1e6));

            case LinearPowerDensityUnit::GigawattsPerMeter:
                return (value * static_cast<un_scalar_t>(1e9));

            case LinearPowerDensityUnit::WattsPerCentimeter:
                return value * static_cast<un_scalar_t>(1e2);

            case LinearPowerDensityUnit::MilliwattsPerCentimeter:
                return (value * static_cast<un_scalar_t>(1e-3)) * static_cast<un_scalar_t>(1e2);

            case LinearPowerDensityUnit::KilowattsPerCentimeter:
                return (value * static_cast<un_scalar_t>(1e3)) * static_cast<un_scalar_t>(1e2);

            case LinearPowerDensityUnit::MegawattsPerCentimeter:
                return (value * static_cast<un_scalar_t>(1e6)) * static_cast<un_scalar_t>(1e2);

            case LinearPowerDensityUnit::GigawattsPerCentimeter:
                return (value * static_cast<un_scalar_t>(1e9)) * static_cast<un_scalar_t>(1e2);

            case LinearPowerDensityUnit::WattsPerMillimeter:
                return value * static_cast<un_scalar_t>(1e3);

            case LinearPowerDensityUnit::MilliwattsPerMillimeter:
                return (value * static_cast<un_scalar_t>(1e-3)) * static_cast<un_scalar_t>(1e3);

            case LinearPowerDensityUnit::KilowattsPerMillimeter:
                return (value * static_cast<un_scalar_t>(1e3)) * static_cast<un_scalar_t>(1e3);

            case LinearPowerDensityUnit::MegawattsPerMillimeter:
                return (value * static_cast<un_scalar_t>(1e6)) * static_cast<un_scalar_t>(1e3);

            case LinearPowerDensityUnit::GigawattsPerMillimeter:
                return (value * static_cast<un_scalar_t>(1e9)) * static_cast<un_scalar_t>(1e3);

            case LinearPowerDensityUnit::WattsPerInch:
                return value / static_cast<un_scalar_t>(2.54e-2);

            case LinearPowerDensityUnit::MilliwattsPerInch:
                return (value * static_cast<un_scalar_t>(1e-3)) / static_cast<un_scalar_t>(2.54e-2);

            case LinearPowerDensityUnit::KilowattsPerInch:
                return (value * static_cast<un_scalar_t>(1e3)) / static_cast<un_scalar_t>(2.54e-2);

            case LinearPowerDensityUnit::MegawattsPerInch:
                return (value * static_cast<un_scalar_t>(1e6)) / static_cast<un_scalar_t>(2.54e-2);

            case LinearPowerDensityUnit::GigawattsPerInch:
                return (value * static_cast<un_scalar_t>(1e9)) / static_cast<un_scalar_t>(2.54e-2);

            case LinearPowerDensityUnit::WattsPerFoot:
                return value / static_cast<un_scalar_t>(0.3048);

            case LinearPowerDensityUnit::MilliwattsPerFoot:
                return (value * static_cast<un_scalar_t>(1e-3)) / static_cast<un_scalar_t>(0.3048);

            case LinearPowerDensityUnit::KilowattsPerFoot:
                return (value * static_cast<un_scalar_t>(1e3)) / static_cast<un_scalar_t>(0.3048);

            case LinearPowerDensityUnit::MegawattsPerFoot:
                return (value * static_cast<un_scalar_t>(1e6)) / static_cast<un_scalar_t>(0.3048);

            case LinearPowerDensityUnit::GigawattsPerFoot:
                return (value * static_cast<un_scalar_t>(1e9)) / static_cast<un_scalar_t>(0.3048);

            }

            throw std::invalid_argument("Unknown LinearPowerDensity unit.");
        }

        [[nodiscard]] constexpr un_scalar_t convert_from_base(const LinearPowerDensityUnit unit) const
        {
            if(unit == value_unit_type_)
            {
                return value_;
            }
            
            auto base_value = convert_to_base(value_, value_unit_type_);
            
            switch (unit)
            {

            case LinearPowerDensityUnit::WattsPerMeter:
                return base_value;

            case LinearPowerDensityUnit::MilliwattsPerMeter:
                return (base_value) / static_cast<un_scalar_t>(1e-3);

            case LinearPowerDensityUnit::KilowattsPerMeter:
                return (base_value) / static_cast<un_scalar_t>(1e3);

            case LinearPowerDensityUnit::MegawattsPerMeter:
                return (base_value) / static_cast<un_scalar_t>(1e6);

            case LinearPowerDensityUnit::GigawattsPerMeter:
                return (base_value) / static_cast<un_scalar_t>(1e9);

            case LinearPowerDensityUnit::WattsPerCentimeter:
                return base_value / static_cast<un_scalar_t>(1e2);

            case LinearPowerDensityUnit::MilliwattsPerCentimeter:
                return (base_value / static_cast<un_scalar_t>(1e2)) / static_cast<un_scalar_t>(1e-3);

            case LinearPowerDensityUnit::KilowattsPerCentimeter:
                return (base_value / static_cast<un_scalar_t>(1e2)) / static_cast<un_scalar_t>(1e3);

            case LinearPowerDensityUnit::MegawattsPerCentimeter:
                return (base_value / static_cast<un_scalar_t>(1e2)) / static_cast<un_scalar_t>(1e6);

            case LinearPowerDensityUnit::GigawattsPerCentimeter:
                return (base_value / static_cast<un_scalar_t>(1e2)) / static_cast<un_scalar_t>(1e9);

            case LinearPowerDensityUnit::WattsPerMillimeter:
                return base_value / static_cast<un_scalar_t>(1e3);

            case LinearPowerDensityUnit::MilliwattsPerMillimeter:
                return (base_value / static_cast<un_scalar_t>(1e3)) / static_cast<un_scalar_t>(1e-3);

            case LinearPowerDensityUnit::KilowattsPerMillimeter:
                return (base_value / static_cast<un_scalar_t>(1e3)) / static_cast<un_scalar_t>(1e3);

            case LinearPowerDensityUnit::MegawattsPerMillimeter:
                return (base_value / static_cast<un_scalar_t>(1e3)) / static_cast<un_scalar_t>(1e6);

            case LinearPowerDensityUnit::GigawattsPerMillimeter:
                return (base_value / static_cast<un_scalar_t>(1e3)) / static_cast<un_scalar_t>(1e9);

            case LinearPowerDensityUnit::WattsPerInch:
                return base_value * static_cast<un_scalar_t>(2.54e-2);

            case LinearPowerDensityUnit::MilliwattsPerInch:
                return (base_value * static_cast<un_scalar_t>(2.54e-2)) / static_cast<un_scalar_t>(1e-3);

            case LinearPowerDensityUnit::KilowattsPerInch:
                return (base_value * static_cast<un_scalar_t>(2.54e-2)) / static_cast<un_scalar_t>(1e3);

            case LinearPowerDensityUnit::MegawattsPerInch:
                return (base_value * static_cast<un_scalar_t>(2.54e-2)) / static_cast<un_scalar_t>(1e6);

            case LinearPowerDensityUnit::GigawattsPerInch:
                return (base_value * static_cast<un_scalar_t>(2.54e-2)) / static_cast<un_scalar_t>(1e9);

            case LinearPowerDensityUnit::WattsPerFoot:
                return base_value * static_cast<un_scalar_t>(0.3048);

            case LinearPowerDensityUnit::MilliwattsPerFoot:
                return (base_value * static_cast<un_scalar_t>(0.3048)) / static_cast<un_scalar_t>(1e-3);

            case LinearPowerDensityUnit::KilowattsPerFoot:
                return (base_value * static_cast<un_scalar_t>(0.3048)) / static_cast<un_scalar_t>(1e3);

            case LinearPowerDensityUnit::MegawattsPerFoot:
                return (base_value * static_cast<un_scalar_t>(0.3048)) / static_cast<un_scalar_t>(1e6);

            case LinearPowerDensityUnit::GigawattsPerFoot:
                return (base_value * static_cast<un_scalar_t>(0.3048)) / static_cast<un_scalar_t>(1e9);

            }

            throw std::invalid_argument("Unknown LinearPowerDensity unit.");
        }

        un_scalar_t value_;
        LinearPowerDensityUnit value_unit_type_;       
    };
}
