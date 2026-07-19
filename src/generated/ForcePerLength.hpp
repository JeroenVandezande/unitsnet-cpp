#pragma once

#include <cstdint>
#include <numbers>
#include <stdexcept>
#include "UnitsNetConfig.h"
#include "UnitsNetBase.h"

namespace unitsnet_cpp
{
    enum class ForcePerLengthUnit : std::uint8_t
    {
        NewtonsPerMeter,
        NanonewtonsPerMeter,
        MicronewtonsPerMeter,
        MillinewtonsPerMeter,
        CentinewtonsPerMeter,
        DecinewtonsPerMeter,
        DecanewtonsPerMeter,
        KilonewtonsPerMeter,
        MeganewtonsPerMeter,
        NewtonsPerCentimeter,
        NanonewtonsPerCentimeter,
        MicronewtonsPerCentimeter,
        MillinewtonsPerCentimeter,
        CentinewtonsPerCentimeter,
        DecinewtonsPerCentimeter,
        DecanewtonsPerCentimeter,
        KilonewtonsPerCentimeter,
        MeganewtonsPerCentimeter,
        NewtonsPerMillimeter,
        NanonewtonsPerMillimeter,
        MicronewtonsPerMillimeter,
        MillinewtonsPerMillimeter,
        CentinewtonsPerMillimeter,
        DecinewtonsPerMillimeter,
        DecanewtonsPerMillimeter,
        KilonewtonsPerMillimeter,
        MeganewtonsPerMillimeter,
        KilogramsForcePerMeter,
        KilogramsForcePerCentimeter,
        KilogramsForcePerMillimeter,
        TonnesForcePerMeter,
        TonnesForcePerCentimeter,
        TonnesForcePerMillimeter,
        PoundsForcePerFoot,
        PoundsForcePerInch,
        PoundsForcePerYard,
        KilopoundsForcePerFoot,
        KilopoundsForcePerInch,
    };

    /// <summary>The magnitude of force per unit length.</summary>
    class ForcePerLength : public UnitsNetBase
    {
    public:
        constexpr explicit ForcePerLength(
            const un_scalar_t value,
            const ForcePerLengthUnit unit = ForcePerLengthUnit::NewtonsPerMeter)
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
           return "ForcePerLength"; 
        }
        
        [[nodiscard]] constexpr std::string_view unit_name() const noexcept override
        {
            switch (value_unit_type_)
            {

            case ForcePerLengthUnit::NewtonsPerMeter:
                return "NewtonsPerMeter";

            case ForcePerLengthUnit::NanonewtonsPerMeter:
                return "NanonewtonsPerMeter";

            case ForcePerLengthUnit::MicronewtonsPerMeter:
                return "MicronewtonsPerMeter";

            case ForcePerLengthUnit::MillinewtonsPerMeter:
                return "MillinewtonsPerMeter";

            case ForcePerLengthUnit::CentinewtonsPerMeter:
                return "CentinewtonsPerMeter";

            case ForcePerLengthUnit::DecinewtonsPerMeter:
                return "DecinewtonsPerMeter";

            case ForcePerLengthUnit::DecanewtonsPerMeter:
                return "DecanewtonsPerMeter";

            case ForcePerLengthUnit::KilonewtonsPerMeter:
                return "KilonewtonsPerMeter";

            case ForcePerLengthUnit::MeganewtonsPerMeter:
                return "MeganewtonsPerMeter";

            case ForcePerLengthUnit::NewtonsPerCentimeter:
                return "NewtonsPerCentimeter";

            case ForcePerLengthUnit::NanonewtonsPerCentimeter:
                return "NanonewtonsPerCentimeter";

            case ForcePerLengthUnit::MicronewtonsPerCentimeter:
                return "MicronewtonsPerCentimeter";

            case ForcePerLengthUnit::MillinewtonsPerCentimeter:
                return "MillinewtonsPerCentimeter";

            case ForcePerLengthUnit::CentinewtonsPerCentimeter:
                return "CentinewtonsPerCentimeter";

            case ForcePerLengthUnit::DecinewtonsPerCentimeter:
                return "DecinewtonsPerCentimeter";

            case ForcePerLengthUnit::DecanewtonsPerCentimeter:
                return "DecanewtonsPerCentimeter";

            case ForcePerLengthUnit::KilonewtonsPerCentimeter:
                return "KilonewtonsPerCentimeter";

            case ForcePerLengthUnit::MeganewtonsPerCentimeter:
                return "MeganewtonsPerCentimeter";

            case ForcePerLengthUnit::NewtonsPerMillimeter:
                return "NewtonsPerMillimeter";

            case ForcePerLengthUnit::NanonewtonsPerMillimeter:
                return "NanonewtonsPerMillimeter";

            case ForcePerLengthUnit::MicronewtonsPerMillimeter:
                return "MicronewtonsPerMillimeter";

            case ForcePerLengthUnit::MillinewtonsPerMillimeter:
                return "MillinewtonsPerMillimeter";

            case ForcePerLengthUnit::CentinewtonsPerMillimeter:
                return "CentinewtonsPerMillimeter";

            case ForcePerLengthUnit::DecinewtonsPerMillimeter:
                return "DecinewtonsPerMillimeter";

            case ForcePerLengthUnit::DecanewtonsPerMillimeter:
                return "DecanewtonsPerMillimeter";

            case ForcePerLengthUnit::KilonewtonsPerMillimeter:
                return "KilonewtonsPerMillimeter";

            case ForcePerLengthUnit::MeganewtonsPerMillimeter:
                return "MeganewtonsPerMillimeter";

            case ForcePerLengthUnit::KilogramsForcePerMeter:
                return "KilogramsForcePerMeter";

            case ForcePerLengthUnit::KilogramsForcePerCentimeter:
                return "KilogramsForcePerCentimeter";

            case ForcePerLengthUnit::KilogramsForcePerMillimeter:
                return "KilogramsForcePerMillimeter";

            case ForcePerLengthUnit::TonnesForcePerMeter:
                return "TonnesForcePerMeter";

            case ForcePerLengthUnit::TonnesForcePerCentimeter:
                return "TonnesForcePerCentimeter";

            case ForcePerLengthUnit::TonnesForcePerMillimeter:
                return "TonnesForcePerMillimeter";

            case ForcePerLengthUnit::PoundsForcePerFoot:
                return "PoundsForcePerFoot";

            case ForcePerLengthUnit::PoundsForcePerInch:
                return "PoundsForcePerInch";

            case ForcePerLengthUnit::PoundsForcePerYard:
                return "PoundsForcePerYard";

            case ForcePerLengthUnit::KilopoundsForcePerFoot:
                return "KilopoundsForcePerFoot";

            case ForcePerLengthUnit::KilopoundsForcePerInch:
                return "KilopoundsForcePerInch";

            }
            
            return {};
        }
                
        [[nodiscard]] constexpr un_scalar_t base_value() const noexcept
        {
            return convert_to_base(value_, value_unit_type_);    
        }

        [[nodiscard]] constexpr un_scalar_t value(const ForcePerLengthUnit unit) const
        {
            return convert_from_base(unit);
        }

        [[nodiscard]] constexpr ForcePerLength operator+(const ForcePerLength& other) const noexcept
        {
            return ForcePerLength(base_value() + other.base_value());
        }

        [[nodiscard]] constexpr ForcePerLength operator-(const ForcePerLength& other)const noexcept
        {
            return ForcePerLength(base_value() - other.base_value());
        }

        [[nodiscard]] constexpr ForcePerLength operator*(const un_scalar_t scalar) const noexcept
        {
            return ForcePerLength(base_value() * scalar);
        }

        [[nodiscard]] constexpr ForcePerLength operator/(const un_scalar_t scalar) const noexcept
        {
            return ForcePerLength(base_value() / scalar);
        }

        [[nodiscard]] constexpr bool operator==(const ForcePerLength& other) const noexcept
        {
            return base_value() == other.base_value();
        }

        [[nodiscard]] constexpr bool operator<(const ForcePerLength& other) const noexcept
        {
            return base_value() < other.base_value();
        }
        
        [[nodiscard]] constexpr bool operator>(const ForcePerLength& other) const noexcept
        {
            return base_value() > other.base_value();
        }

        [[nodiscard]] constexpr un_scalar_t newtons_per_meter() const
        {
            return convert_from_base(ForcePerLengthUnit::NewtonsPerMeter);
        }

        [[nodiscard]] static constexpr ForcePerLength from_newtons_per_meter(const un_scalar_t value)
        {
            return ForcePerLength(value, ForcePerLengthUnit::NewtonsPerMeter);
        }

        [[nodiscard]] constexpr un_scalar_t nanonewtons_per_meter() const
        {
            return convert_from_base(ForcePerLengthUnit::NanonewtonsPerMeter);
        }

        [[nodiscard]] static constexpr ForcePerLength from_nanonewtons_per_meter(const un_scalar_t value)
        {
            return ForcePerLength(value, ForcePerLengthUnit::NanonewtonsPerMeter);
        }

        [[nodiscard]] constexpr un_scalar_t micronewtons_per_meter() const
        {
            return convert_from_base(ForcePerLengthUnit::MicronewtonsPerMeter);
        }

        [[nodiscard]] static constexpr ForcePerLength from_micronewtons_per_meter(const un_scalar_t value)
        {
            return ForcePerLength(value, ForcePerLengthUnit::MicronewtonsPerMeter);
        }

        [[nodiscard]] constexpr un_scalar_t millinewtons_per_meter() const
        {
            return convert_from_base(ForcePerLengthUnit::MillinewtonsPerMeter);
        }

        [[nodiscard]] static constexpr ForcePerLength from_millinewtons_per_meter(const un_scalar_t value)
        {
            return ForcePerLength(value, ForcePerLengthUnit::MillinewtonsPerMeter);
        }

        [[nodiscard]] constexpr un_scalar_t centinewtons_per_meter() const
        {
            return convert_from_base(ForcePerLengthUnit::CentinewtonsPerMeter);
        }

        [[nodiscard]] static constexpr ForcePerLength from_centinewtons_per_meter(const un_scalar_t value)
        {
            return ForcePerLength(value, ForcePerLengthUnit::CentinewtonsPerMeter);
        }

        [[nodiscard]] constexpr un_scalar_t decinewtons_per_meter() const
        {
            return convert_from_base(ForcePerLengthUnit::DecinewtonsPerMeter);
        }

        [[nodiscard]] static constexpr ForcePerLength from_decinewtons_per_meter(const un_scalar_t value)
        {
            return ForcePerLength(value, ForcePerLengthUnit::DecinewtonsPerMeter);
        }

        [[nodiscard]] constexpr un_scalar_t decanewtons_per_meter() const
        {
            return convert_from_base(ForcePerLengthUnit::DecanewtonsPerMeter);
        }

        [[nodiscard]] static constexpr ForcePerLength from_decanewtons_per_meter(const un_scalar_t value)
        {
            return ForcePerLength(value, ForcePerLengthUnit::DecanewtonsPerMeter);
        }

        [[nodiscard]] constexpr un_scalar_t kilonewtons_per_meter() const
        {
            return convert_from_base(ForcePerLengthUnit::KilonewtonsPerMeter);
        }

        [[nodiscard]] static constexpr ForcePerLength from_kilonewtons_per_meter(const un_scalar_t value)
        {
            return ForcePerLength(value, ForcePerLengthUnit::KilonewtonsPerMeter);
        }

        [[nodiscard]] constexpr un_scalar_t meganewtons_per_meter() const
        {
            return convert_from_base(ForcePerLengthUnit::MeganewtonsPerMeter);
        }

        [[nodiscard]] static constexpr ForcePerLength from_meganewtons_per_meter(const un_scalar_t value)
        {
            return ForcePerLength(value, ForcePerLengthUnit::MeganewtonsPerMeter);
        }

        [[nodiscard]] constexpr un_scalar_t newtons_per_centimeter() const
        {
            return convert_from_base(ForcePerLengthUnit::NewtonsPerCentimeter);
        }

        [[nodiscard]] static constexpr ForcePerLength from_newtons_per_centimeter(const un_scalar_t value)
        {
            return ForcePerLength(value, ForcePerLengthUnit::NewtonsPerCentimeter);
        }

        [[nodiscard]] constexpr un_scalar_t nanonewtons_per_centimeter() const
        {
            return convert_from_base(ForcePerLengthUnit::NanonewtonsPerCentimeter);
        }

        [[nodiscard]] static constexpr ForcePerLength from_nanonewtons_per_centimeter(const un_scalar_t value)
        {
            return ForcePerLength(value, ForcePerLengthUnit::NanonewtonsPerCentimeter);
        }

        [[nodiscard]] constexpr un_scalar_t micronewtons_per_centimeter() const
        {
            return convert_from_base(ForcePerLengthUnit::MicronewtonsPerCentimeter);
        }

        [[nodiscard]] static constexpr ForcePerLength from_micronewtons_per_centimeter(const un_scalar_t value)
        {
            return ForcePerLength(value, ForcePerLengthUnit::MicronewtonsPerCentimeter);
        }

        [[nodiscard]] constexpr un_scalar_t millinewtons_per_centimeter() const
        {
            return convert_from_base(ForcePerLengthUnit::MillinewtonsPerCentimeter);
        }

        [[nodiscard]] static constexpr ForcePerLength from_millinewtons_per_centimeter(const un_scalar_t value)
        {
            return ForcePerLength(value, ForcePerLengthUnit::MillinewtonsPerCentimeter);
        }

        [[nodiscard]] constexpr un_scalar_t centinewtons_per_centimeter() const
        {
            return convert_from_base(ForcePerLengthUnit::CentinewtonsPerCentimeter);
        }

        [[nodiscard]] static constexpr ForcePerLength from_centinewtons_per_centimeter(const un_scalar_t value)
        {
            return ForcePerLength(value, ForcePerLengthUnit::CentinewtonsPerCentimeter);
        }

        [[nodiscard]] constexpr un_scalar_t decinewtons_per_centimeter() const
        {
            return convert_from_base(ForcePerLengthUnit::DecinewtonsPerCentimeter);
        }

        [[nodiscard]] static constexpr ForcePerLength from_decinewtons_per_centimeter(const un_scalar_t value)
        {
            return ForcePerLength(value, ForcePerLengthUnit::DecinewtonsPerCentimeter);
        }

        [[nodiscard]] constexpr un_scalar_t decanewtons_per_centimeter() const
        {
            return convert_from_base(ForcePerLengthUnit::DecanewtonsPerCentimeter);
        }

        [[nodiscard]] static constexpr ForcePerLength from_decanewtons_per_centimeter(const un_scalar_t value)
        {
            return ForcePerLength(value, ForcePerLengthUnit::DecanewtonsPerCentimeter);
        }

        [[nodiscard]] constexpr un_scalar_t kilonewtons_per_centimeter() const
        {
            return convert_from_base(ForcePerLengthUnit::KilonewtonsPerCentimeter);
        }

        [[nodiscard]] static constexpr ForcePerLength from_kilonewtons_per_centimeter(const un_scalar_t value)
        {
            return ForcePerLength(value, ForcePerLengthUnit::KilonewtonsPerCentimeter);
        }

        [[nodiscard]] constexpr un_scalar_t meganewtons_per_centimeter() const
        {
            return convert_from_base(ForcePerLengthUnit::MeganewtonsPerCentimeter);
        }

        [[nodiscard]] static constexpr ForcePerLength from_meganewtons_per_centimeter(const un_scalar_t value)
        {
            return ForcePerLength(value, ForcePerLengthUnit::MeganewtonsPerCentimeter);
        }

        [[nodiscard]] constexpr un_scalar_t newtons_per_millimeter() const
        {
            return convert_from_base(ForcePerLengthUnit::NewtonsPerMillimeter);
        }

        [[nodiscard]] static constexpr ForcePerLength from_newtons_per_millimeter(const un_scalar_t value)
        {
            return ForcePerLength(value, ForcePerLengthUnit::NewtonsPerMillimeter);
        }

        [[nodiscard]] constexpr un_scalar_t nanonewtons_per_millimeter() const
        {
            return convert_from_base(ForcePerLengthUnit::NanonewtonsPerMillimeter);
        }

        [[nodiscard]] static constexpr ForcePerLength from_nanonewtons_per_millimeter(const un_scalar_t value)
        {
            return ForcePerLength(value, ForcePerLengthUnit::NanonewtonsPerMillimeter);
        }

        [[nodiscard]] constexpr un_scalar_t micronewtons_per_millimeter() const
        {
            return convert_from_base(ForcePerLengthUnit::MicronewtonsPerMillimeter);
        }

        [[nodiscard]] static constexpr ForcePerLength from_micronewtons_per_millimeter(const un_scalar_t value)
        {
            return ForcePerLength(value, ForcePerLengthUnit::MicronewtonsPerMillimeter);
        }

        [[nodiscard]] constexpr un_scalar_t millinewtons_per_millimeter() const
        {
            return convert_from_base(ForcePerLengthUnit::MillinewtonsPerMillimeter);
        }

        [[nodiscard]] static constexpr ForcePerLength from_millinewtons_per_millimeter(const un_scalar_t value)
        {
            return ForcePerLength(value, ForcePerLengthUnit::MillinewtonsPerMillimeter);
        }

        [[nodiscard]] constexpr un_scalar_t centinewtons_per_millimeter() const
        {
            return convert_from_base(ForcePerLengthUnit::CentinewtonsPerMillimeter);
        }

        [[nodiscard]] static constexpr ForcePerLength from_centinewtons_per_millimeter(const un_scalar_t value)
        {
            return ForcePerLength(value, ForcePerLengthUnit::CentinewtonsPerMillimeter);
        }

        [[nodiscard]] constexpr un_scalar_t decinewtons_per_millimeter() const
        {
            return convert_from_base(ForcePerLengthUnit::DecinewtonsPerMillimeter);
        }

        [[nodiscard]] static constexpr ForcePerLength from_decinewtons_per_millimeter(const un_scalar_t value)
        {
            return ForcePerLength(value, ForcePerLengthUnit::DecinewtonsPerMillimeter);
        }

        [[nodiscard]] constexpr un_scalar_t decanewtons_per_millimeter() const
        {
            return convert_from_base(ForcePerLengthUnit::DecanewtonsPerMillimeter);
        }

        [[nodiscard]] static constexpr ForcePerLength from_decanewtons_per_millimeter(const un_scalar_t value)
        {
            return ForcePerLength(value, ForcePerLengthUnit::DecanewtonsPerMillimeter);
        }

        [[nodiscard]] constexpr un_scalar_t kilonewtons_per_millimeter() const
        {
            return convert_from_base(ForcePerLengthUnit::KilonewtonsPerMillimeter);
        }

        [[nodiscard]] static constexpr ForcePerLength from_kilonewtons_per_millimeter(const un_scalar_t value)
        {
            return ForcePerLength(value, ForcePerLengthUnit::KilonewtonsPerMillimeter);
        }

        [[nodiscard]] constexpr un_scalar_t meganewtons_per_millimeter() const
        {
            return convert_from_base(ForcePerLengthUnit::MeganewtonsPerMillimeter);
        }

        [[nodiscard]] static constexpr ForcePerLength from_meganewtons_per_millimeter(const un_scalar_t value)
        {
            return ForcePerLength(value, ForcePerLengthUnit::MeganewtonsPerMillimeter);
        }

        [[nodiscard]] constexpr un_scalar_t kilograms_force_per_meter() const
        {
            return convert_from_base(ForcePerLengthUnit::KilogramsForcePerMeter);
        }

        [[nodiscard]] static constexpr ForcePerLength from_kilograms_force_per_meter(const un_scalar_t value)
        {
            return ForcePerLength(value, ForcePerLengthUnit::KilogramsForcePerMeter);
        }

        [[nodiscard]] constexpr un_scalar_t kilograms_force_per_centimeter() const
        {
            return convert_from_base(ForcePerLengthUnit::KilogramsForcePerCentimeter);
        }

        [[nodiscard]] static constexpr ForcePerLength from_kilograms_force_per_centimeter(const un_scalar_t value)
        {
            return ForcePerLength(value, ForcePerLengthUnit::KilogramsForcePerCentimeter);
        }

        [[nodiscard]] constexpr un_scalar_t kilograms_force_per_millimeter() const
        {
            return convert_from_base(ForcePerLengthUnit::KilogramsForcePerMillimeter);
        }

        [[nodiscard]] static constexpr ForcePerLength from_kilograms_force_per_millimeter(const un_scalar_t value)
        {
            return ForcePerLength(value, ForcePerLengthUnit::KilogramsForcePerMillimeter);
        }

        [[nodiscard]] constexpr un_scalar_t tonnes_force_per_meter() const
        {
            return convert_from_base(ForcePerLengthUnit::TonnesForcePerMeter);
        }

        [[nodiscard]] static constexpr ForcePerLength from_tonnes_force_per_meter(const un_scalar_t value)
        {
            return ForcePerLength(value, ForcePerLengthUnit::TonnesForcePerMeter);
        }

        [[nodiscard]] constexpr un_scalar_t tonnes_force_per_centimeter() const
        {
            return convert_from_base(ForcePerLengthUnit::TonnesForcePerCentimeter);
        }

        [[nodiscard]] static constexpr ForcePerLength from_tonnes_force_per_centimeter(const un_scalar_t value)
        {
            return ForcePerLength(value, ForcePerLengthUnit::TonnesForcePerCentimeter);
        }

        [[nodiscard]] constexpr un_scalar_t tonnes_force_per_millimeter() const
        {
            return convert_from_base(ForcePerLengthUnit::TonnesForcePerMillimeter);
        }

        [[nodiscard]] static constexpr ForcePerLength from_tonnes_force_per_millimeter(const un_scalar_t value)
        {
            return ForcePerLength(value, ForcePerLengthUnit::TonnesForcePerMillimeter);
        }

        [[nodiscard]] constexpr un_scalar_t pounds_force_per_foot() const
        {
            return convert_from_base(ForcePerLengthUnit::PoundsForcePerFoot);
        }

        [[nodiscard]] static constexpr ForcePerLength from_pounds_force_per_foot(const un_scalar_t value)
        {
            return ForcePerLength(value, ForcePerLengthUnit::PoundsForcePerFoot);
        }

        [[nodiscard]] constexpr un_scalar_t pounds_force_per_inch() const
        {
            return convert_from_base(ForcePerLengthUnit::PoundsForcePerInch);
        }

        [[nodiscard]] static constexpr ForcePerLength from_pounds_force_per_inch(const un_scalar_t value)
        {
            return ForcePerLength(value, ForcePerLengthUnit::PoundsForcePerInch);
        }

        [[nodiscard]] constexpr un_scalar_t pounds_force_per_yard() const
        {
            return convert_from_base(ForcePerLengthUnit::PoundsForcePerYard);
        }

        [[nodiscard]] static constexpr ForcePerLength from_pounds_force_per_yard(const un_scalar_t value)
        {
            return ForcePerLength(value, ForcePerLengthUnit::PoundsForcePerYard);
        }

        [[nodiscard]] constexpr un_scalar_t kilopounds_force_per_foot() const
        {
            return convert_from_base(ForcePerLengthUnit::KilopoundsForcePerFoot);
        }

        [[nodiscard]] static constexpr ForcePerLength from_kilopounds_force_per_foot(const un_scalar_t value)
        {
            return ForcePerLength(value, ForcePerLengthUnit::KilopoundsForcePerFoot);
        }

        [[nodiscard]] constexpr un_scalar_t kilopounds_force_per_inch() const
        {
            return convert_from_base(ForcePerLengthUnit::KilopoundsForcePerInch);
        }

        [[nodiscard]] static constexpr ForcePerLength from_kilopounds_force_per_inch(const un_scalar_t value)
        {
            return ForcePerLength(value, ForcePerLengthUnit::KilopoundsForcePerInch);
        }

        [[nodiscard]] static constexpr ForcePerLength from_invalid()
        {
            return ForcePerLength(false);
        }
    private:
            
        [[nodiscard]] static constexpr un_scalar_t convert_to_base(un_scalar_t value, ForcePerLengthUnit unit)
        {
            switch (unit)
            {

            case ForcePerLengthUnit::NewtonsPerMeter:
                return value;

            case ForcePerLengthUnit::NanonewtonsPerMeter:
                return (value * static_cast<un_scalar_t>(1e-9));

            case ForcePerLengthUnit::MicronewtonsPerMeter:
                return (value * static_cast<un_scalar_t>(1e-6));

            case ForcePerLengthUnit::MillinewtonsPerMeter:
                return (value * static_cast<un_scalar_t>(1e-3));

            case ForcePerLengthUnit::CentinewtonsPerMeter:
                return (value * static_cast<un_scalar_t>(1e-2));

            case ForcePerLengthUnit::DecinewtonsPerMeter:
                return (value * static_cast<un_scalar_t>(1e-1));

            case ForcePerLengthUnit::DecanewtonsPerMeter:
                return (value * static_cast<un_scalar_t>(1e1));

            case ForcePerLengthUnit::KilonewtonsPerMeter:
                return (value * static_cast<un_scalar_t>(1e3));

            case ForcePerLengthUnit::MeganewtonsPerMeter:
                return (value * static_cast<un_scalar_t>(1e6));

            case ForcePerLengthUnit::NewtonsPerCentimeter:
                return value * static_cast<un_scalar_t>(1e2);

            case ForcePerLengthUnit::NanonewtonsPerCentimeter:
                return (value * static_cast<un_scalar_t>(1e-9)) * static_cast<un_scalar_t>(1e2);

            case ForcePerLengthUnit::MicronewtonsPerCentimeter:
                return (value * static_cast<un_scalar_t>(1e-6)) * static_cast<un_scalar_t>(1e2);

            case ForcePerLengthUnit::MillinewtonsPerCentimeter:
                return (value * static_cast<un_scalar_t>(1e-3)) * static_cast<un_scalar_t>(1e2);

            case ForcePerLengthUnit::CentinewtonsPerCentimeter:
                return (value * static_cast<un_scalar_t>(1e-2)) * static_cast<un_scalar_t>(1e2);

            case ForcePerLengthUnit::DecinewtonsPerCentimeter:
                return (value * static_cast<un_scalar_t>(1e-1)) * static_cast<un_scalar_t>(1e2);

            case ForcePerLengthUnit::DecanewtonsPerCentimeter:
                return (value * static_cast<un_scalar_t>(1e1)) * static_cast<un_scalar_t>(1e2);

            case ForcePerLengthUnit::KilonewtonsPerCentimeter:
                return (value * static_cast<un_scalar_t>(1e3)) * static_cast<un_scalar_t>(1e2);

            case ForcePerLengthUnit::MeganewtonsPerCentimeter:
                return (value * static_cast<un_scalar_t>(1e6)) * static_cast<un_scalar_t>(1e2);

            case ForcePerLengthUnit::NewtonsPerMillimeter:
                return value * static_cast<un_scalar_t>(1e3);

            case ForcePerLengthUnit::NanonewtonsPerMillimeter:
                return (value * static_cast<un_scalar_t>(1e-9)) * static_cast<un_scalar_t>(1e3);

            case ForcePerLengthUnit::MicronewtonsPerMillimeter:
                return (value * static_cast<un_scalar_t>(1e-6)) * static_cast<un_scalar_t>(1e3);

            case ForcePerLengthUnit::MillinewtonsPerMillimeter:
                return (value * static_cast<un_scalar_t>(1e-3)) * static_cast<un_scalar_t>(1e3);

            case ForcePerLengthUnit::CentinewtonsPerMillimeter:
                return (value * static_cast<un_scalar_t>(1e-2)) * static_cast<un_scalar_t>(1e3);

            case ForcePerLengthUnit::DecinewtonsPerMillimeter:
                return (value * static_cast<un_scalar_t>(1e-1)) * static_cast<un_scalar_t>(1e3);

            case ForcePerLengthUnit::DecanewtonsPerMillimeter:
                return (value * static_cast<un_scalar_t>(1e1)) * static_cast<un_scalar_t>(1e3);

            case ForcePerLengthUnit::KilonewtonsPerMillimeter:
                return (value * static_cast<un_scalar_t>(1e3)) * static_cast<un_scalar_t>(1e3);

            case ForcePerLengthUnit::MeganewtonsPerMillimeter:
                return (value * static_cast<un_scalar_t>(1e6)) * static_cast<un_scalar_t>(1e3);

            case ForcePerLengthUnit::KilogramsForcePerMeter:
                return value * static_cast<un_scalar_t>(9.80665);

            case ForcePerLengthUnit::KilogramsForcePerCentimeter:
                return value * static_cast<un_scalar_t>(980.665);

            case ForcePerLengthUnit::KilogramsForcePerMillimeter:
                return value * static_cast<un_scalar_t>(9.80665e3);

            case ForcePerLengthUnit::TonnesForcePerMeter:
                return value * static_cast<un_scalar_t>(9.80665e3);

            case ForcePerLengthUnit::TonnesForcePerCentimeter:
                return value * static_cast<un_scalar_t>(9.80665e5);

            case ForcePerLengthUnit::TonnesForcePerMillimeter:
                return value * static_cast<un_scalar_t>(9.80665e6);

            case ForcePerLengthUnit::PoundsForcePerFoot:
                return value * static_cast<un_scalar_t>(4.4482216152605) / static_cast<un_scalar_t>(0.3048);

            case ForcePerLengthUnit::PoundsForcePerInch:
                return value * static_cast<un_scalar_t>(4.4482216152605) / static_cast<un_scalar_t>(2.54e-2);

            case ForcePerLengthUnit::PoundsForcePerYard:
                return value * static_cast<un_scalar_t>(4.4482216152605) / static_cast<un_scalar_t>(0.9144);

            case ForcePerLengthUnit::KilopoundsForcePerFoot:
                return value * static_cast<un_scalar_t>(4.4482216152605) / static_cast<un_scalar_t>(0.3048e-3);

            case ForcePerLengthUnit::KilopoundsForcePerInch:
                return value * static_cast<un_scalar_t>(4.4482216152605) / static_cast<un_scalar_t>(2.54e-5);

            }

            throw std::invalid_argument("Unknown ForcePerLength unit.");
        }

        [[nodiscard]] constexpr un_scalar_t convert_from_base(const ForcePerLengthUnit unit) const
        {
            if(unit == value_unit_type_)
            {
                return value_;
            }
            
            auto base_value = convert_to_base(value_, value_unit_type_);
            
            switch (unit)
            {

            case ForcePerLengthUnit::NewtonsPerMeter:
                return base_value;

            case ForcePerLengthUnit::NanonewtonsPerMeter:
                return (base_value) / static_cast<un_scalar_t>(1e-9);

            case ForcePerLengthUnit::MicronewtonsPerMeter:
                return (base_value) / static_cast<un_scalar_t>(1e-6);

            case ForcePerLengthUnit::MillinewtonsPerMeter:
                return (base_value) / static_cast<un_scalar_t>(1e-3);

            case ForcePerLengthUnit::CentinewtonsPerMeter:
                return (base_value) / static_cast<un_scalar_t>(1e-2);

            case ForcePerLengthUnit::DecinewtonsPerMeter:
                return (base_value) / static_cast<un_scalar_t>(1e-1);

            case ForcePerLengthUnit::DecanewtonsPerMeter:
                return (base_value) / static_cast<un_scalar_t>(1e1);

            case ForcePerLengthUnit::KilonewtonsPerMeter:
                return (base_value) / static_cast<un_scalar_t>(1e3);

            case ForcePerLengthUnit::MeganewtonsPerMeter:
                return (base_value) / static_cast<un_scalar_t>(1e6);

            case ForcePerLengthUnit::NewtonsPerCentimeter:
                return base_value / static_cast<un_scalar_t>(1e2);

            case ForcePerLengthUnit::NanonewtonsPerCentimeter:
                return (base_value / static_cast<un_scalar_t>(1e2)) / static_cast<un_scalar_t>(1e-9);

            case ForcePerLengthUnit::MicronewtonsPerCentimeter:
                return (base_value / static_cast<un_scalar_t>(1e2)) / static_cast<un_scalar_t>(1e-6);

            case ForcePerLengthUnit::MillinewtonsPerCentimeter:
                return (base_value / static_cast<un_scalar_t>(1e2)) / static_cast<un_scalar_t>(1e-3);

            case ForcePerLengthUnit::CentinewtonsPerCentimeter:
                return (base_value / static_cast<un_scalar_t>(1e2)) / static_cast<un_scalar_t>(1e-2);

            case ForcePerLengthUnit::DecinewtonsPerCentimeter:
                return (base_value / static_cast<un_scalar_t>(1e2)) / static_cast<un_scalar_t>(1e-1);

            case ForcePerLengthUnit::DecanewtonsPerCentimeter:
                return (base_value / static_cast<un_scalar_t>(1e2)) / static_cast<un_scalar_t>(1e1);

            case ForcePerLengthUnit::KilonewtonsPerCentimeter:
                return (base_value / static_cast<un_scalar_t>(1e2)) / static_cast<un_scalar_t>(1e3);

            case ForcePerLengthUnit::MeganewtonsPerCentimeter:
                return (base_value / static_cast<un_scalar_t>(1e2)) / static_cast<un_scalar_t>(1e6);

            case ForcePerLengthUnit::NewtonsPerMillimeter:
                return base_value / static_cast<un_scalar_t>(1e3);

            case ForcePerLengthUnit::NanonewtonsPerMillimeter:
                return (base_value / static_cast<un_scalar_t>(1e3)) / static_cast<un_scalar_t>(1e-9);

            case ForcePerLengthUnit::MicronewtonsPerMillimeter:
                return (base_value / static_cast<un_scalar_t>(1e3)) / static_cast<un_scalar_t>(1e-6);

            case ForcePerLengthUnit::MillinewtonsPerMillimeter:
                return (base_value / static_cast<un_scalar_t>(1e3)) / static_cast<un_scalar_t>(1e-3);

            case ForcePerLengthUnit::CentinewtonsPerMillimeter:
                return (base_value / static_cast<un_scalar_t>(1e3)) / static_cast<un_scalar_t>(1e-2);

            case ForcePerLengthUnit::DecinewtonsPerMillimeter:
                return (base_value / static_cast<un_scalar_t>(1e3)) / static_cast<un_scalar_t>(1e-1);

            case ForcePerLengthUnit::DecanewtonsPerMillimeter:
                return (base_value / static_cast<un_scalar_t>(1e3)) / static_cast<un_scalar_t>(1e1);

            case ForcePerLengthUnit::KilonewtonsPerMillimeter:
                return (base_value / static_cast<un_scalar_t>(1e3)) / static_cast<un_scalar_t>(1e3);

            case ForcePerLengthUnit::MeganewtonsPerMillimeter:
                return (base_value / static_cast<un_scalar_t>(1e3)) / static_cast<un_scalar_t>(1e6);

            case ForcePerLengthUnit::KilogramsForcePerMeter:
                return base_value / static_cast<un_scalar_t>(9.80665);

            case ForcePerLengthUnit::KilogramsForcePerCentimeter:
                return base_value / static_cast<un_scalar_t>(980.665);

            case ForcePerLengthUnit::KilogramsForcePerMillimeter:
                return base_value / static_cast<un_scalar_t>(9.80665e3);

            case ForcePerLengthUnit::TonnesForcePerMeter:
                return base_value / static_cast<un_scalar_t>(9.80665e3);

            case ForcePerLengthUnit::TonnesForcePerCentimeter:
                return base_value / static_cast<un_scalar_t>(9.80665e5);

            case ForcePerLengthUnit::TonnesForcePerMillimeter:
                return base_value / static_cast<un_scalar_t>(9.80665e6);

            case ForcePerLengthUnit::PoundsForcePerFoot:
                return base_value * static_cast<un_scalar_t>(0.3048) / static_cast<un_scalar_t>(4.4482216152605);

            case ForcePerLengthUnit::PoundsForcePerInch:
                return base_value * static_cast<un_scalar_t>(2.54e-2) / static_cast<un_scalar_t>(4.4482216152605);

            case ForcePerLengthUnit::PoundsForcePerYard:
                return base_value * static_cast<un_scalar_t>(0.9144) / static_cast<un_scalar_t>(4.4482216152605);

            case ForcePerLengthUnit::KilopoundsForcePerFoot:
                return base_value * static_cast<un_scalar_t>(0.3048e-3) / static_cast<un_scalar_t>(4.4482216152605);

            case ForcePerLengthUnit::KilopoundsForcePerInch:
                return base_value * static_cast<un_scalar_t>(2.54e-5) / static_cast<un_scalar_t>(4.4482216152605);

            }

            throw std::invalid_argument("Unknown ForcePerLength unit.");
        }

        un_scalar_t value_;
        ForcePerLengthUnit value_unit_type_;       
    };
}
