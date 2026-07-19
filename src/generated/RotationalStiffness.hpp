#pragma once

#include <cstdint>
#include <numbers>
#include <stdexcept>
#include "UnitsNetConfig.h"
#include "UnitsNetBase.h"

namespace unitsnet_cpp
{
    enum class RotationalStiffnessUnit : std::uint8_t
    {
        NewtonMetersPerRadian,
        KilonewtonMetersPerRadian,
        MeganewtonMetersPerRadian,
        PoundForceFeetPerDegrees,
        KilopoundForceFeetPerDegrees,
        NewtonMillimetersPerDegree,
        NanonewtonMillimetersPerDegree,
        MicronewtonMillimetersPerDegree,
        MillinewtonMillimetersPerDegree,
        CentinewtonMillimetersPerDegree,
        DecinewtonMillimetersPerDegree,
        DecanewtonMillimetersPerDegree,
        KilonewtonMillimetersPerDegree,
        MeganewtonMillimetersPerDegree,
        NewtonMetersPerDegree,
        NanonewtonMetersPerDegree,
        MicronewtonMetersPerDegree,
        MillinewtonMetersPerDegree,
        CentinewtonMetersPerDegree,
        DecinewtonMetersPerDegree,
        DecanewtonMetersPerDegree,
        KilonewtonMetersPerDegree,
        MeganewtonMetersPerDegree,
        NewtonMillimetersPerRadian,
        NanonewtonMillimetersPerRadian,
        MicronewtonMillimetersPerRadian,
        MillinewtonMillimetersPerRadian,
        CentinewtonMillimetersPerRadian,
        DecinewtonMillimetersPerRadian,
        DecanewtonMillimetersPerRadian,
        KilonewtonMillimetersPerRadian,
        MeganewtonMillimetersPerRadian,
        PoundForceFeetPerRadian,
        KilopoundForceFeetPerRadian,
    };

    /// <summary>https://en.wikipedia.org/wiki/Stiffness#Rotational_stiffness</summary>
    class RotationalStiffness : public UnitsNetBase
    {
    public:
        constexpr explicit RotationalStiffness(
            const un_scalar_t value,
            const RotationalStiffnessUnit unit = RotationalStiffnessUnit::NewtonMetersPerRadian)
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
           return "RotationalStiffness"; 
        }
        
        [[nodiscard]] constexpr std::string_view unit_name() const noexcept override
        {
            switch (value_unit_type_)
            {

            case RotationalStiffnessUnit::NewtonMetersPerRadian:
                return "NewtonMetersPerRadian";

            case RotationalStiffnessUnit::KilonewtonMetersPerRadian:
                return "KilonewtonMetersPerRadian";

            case RotationalStiffnessUnit::MeganewtonMetersPerRadian:
                return "MeganewtonMetersPerRadian";

            case RotationalStiffnessUnit::PoundForceFeetPerDegrees:
                return "PoundForceFeetPerDegrees";

            case RotationalStiffnessUnit::KilopoundForceFeetPerDegrees:
                return "KilopoundForceFeetPerDegrees";

            case RotationalStiffnessUnit::NewtonMillimetersPerDegree:
                return "NewtonMillimetersPerDegree";

            case RotationalStiffnessUnit::NanonewtonMillimetersPerDegree:
                return "NanonewtonMillimetersPerDegree";

            case RotationalStiffnessUnit::MicronewtonMillimetersPerDegree:
                return "MicronewtonMillimetersPerDegree";

            case RotationalStiffnessUnit::MillinewtonMillimetersPerDegree:
                return "MillinewtonMillimetersPerDegree";

            case RotationalStiffnessUnit::CentinewtonMillimetersPerDegree:
                return "CentinewtonMillimetersPerDegree";

            case RotationalStiffnessUnit::DecinewtonMillimetersPerDegree:
                return "DecinewtonMillimetersPerDegree";

            case RotationalStiffnessUnit::DecanewtonMillimetersPerDegree:
                return "DecanewtonMillimetersPerDegree";

            case RotationalStiffnessUnit::KilonewtonMillimetersPerDegree:
                return "KilonewtonMillimetersPerDegree";

            case RotationalStiffnessUnit::MeganewtonMillimetersPerDegree:
                return "MeganewtonMillimetersPerDegree";

            case RotationalStiffnessUnit::NewtonMetersPerDegree:
                return "NewtonMetersPerDegree";

            case RotationalStiffnessUnit::NanonewtonMetersPerDegree:
                return "NanonewtonMetersPerDegree";

            case RotationalStiffnessUnit::MicronewtonMetersPerDegree:
                return "MicronewtonMetersPerDegree";

            case RotationalStiffnessUnit::MillinewtonMetersPerDegree:
                return "MillinewtonMetersPerDegree";

            case RotationalStiffnessUnit::CentinewtonMetersPerDegree:
                return "CentinewtonMetersPerDegree";

            case RotationalStiffnessUnit::DecinewtonMetersPerDegree:
                return "DecinewtonMetersPerDegree";

            case RotationalStiffnessUnit::DecanewtonMetersPerDegree:
                return "DecanewtonMetersPerDegree";

            case RotationalStiffnessUnit::KilonewtonMetersPerDegree:
                return "KilonewtonMetersPerDegree";

            case RotationalStiffnessUnit::MeganewtonMetersPerDegree:
                return "MeganewtonMetersPerDegree";

            case RotationalStiffnessUnit::NewtonMillimetersPerRadian:
                return "NewtonMillimetersPerRadian";

            case RotationalStiffnessUnit::NanonewtonMillimetersPerRadian:
                return "NanonewtonMillimetersPerRadian";

            case RotationalStiffnessUnit::MicronewtonMillimetersPerRadian:
                return "MicronewtonMillimetersPerRadian";

            case RotationalStiffnessUnit::MillinewtonMillimetersPerRadian:
                return "MillinewtonMillimetersPerRadian";

            case RotationalStiffnessUnit::CentinewtonMillimetersPerRadian:
                return "CentinewtonMillimetersPerRadian";

            case RotationalStiffnessUnit::DecinewtonMillimetersPerRadian:
                return "DecinewtonMillimetersPerRadian";

            case RotationalStiffnessUnit::DecanewtonMillimetersPerRadian:
                return "DecanewtonMillimetersPerRadian";

            case RotationalStiffnessUnit::KilonewtonMillimetersPerRadian:
                return "KilonewtonMillimetersPerRadian";

            case RotationalStiffnessUnit::MeganewtonMillimetersPerRadian:
                return "MeganewtonMillimetersPerRadian";

            case RotationalStiffnessUnit::PoundForceFeetPerRadian:
                return "PoundForceFeetPerRadian";

            case RotationalStiffnessUnit::KilopoundForceFeetPerRadian:
                return "KilopoundForceFeetPerRadian";

            }
            
            return {};
        }
                
        [[nodiscard]] constexpr un_scalar_t base_value() const noexcept
        {
            return convert_to_base(value_, value_unit_type_);    
        }

        [[nodiscard]] constexpr un_scalar_t value(const RotationalStiffnessUnit unit) const
        {
            return convert_from_base(unit);
        }

        [[nodiscard]] constexpr RotationalStiffness operator+(const RotationalStiffness& other) const noexcept
        {
            return RotationalStiffness(base_value() + other.base_value());
        }

        [[nodiscard]] constexpr RotationalStiffness operator-(const RotationalStiffness& other)const noexcept
        {
            return RotationalStiffness(base_value() - other.base_value());
        }

        [[nodiscard]] constexpr RotationalStiffness operator*(const un_scalar_t scalar) const noexcept
        {
            return RotationalStiffness(base_value() * scalar);
        }

        [[nodiscard]] constexpr RotationalStiffness operator/(const un_scalar_t scalar) const noexcept
        {
            return RotationalStiffness(base_value() / scalar);
        }

        [[nodiscard]] constexpr bool operator==(const RotationalStiffness& other) const noexcept
        {
            return base_value() == other.base_value();
        }

        [[nodiscard]] constexpr bool operator<(const RotationalStiffness& other) const noexcept
        {
            return base_value() < other.base_value();
        }
        
        [[nodiscard]] constexpr bool operator>(const RotationalStiffness& other) const noexcept
        {
            return base_value() > other.base_value();
        }

        [[nodiscard]] constexpr un_scalar_t newton_meters_per_radian() const
        {
            return convert_from_base(RotationalStiffnessUnit::NewtonMetersPerRadian);
        }

        [[nodiscard]] static constexpr RotationalStiffness from_newton_meters_per_radian(const un_scalar_t value)
        {
            return RotationalStiffness(value, RotationalStiffnessUnit::NewtonMetersPerRadian);
        }

        [[nodiscard]] constexpr un_scalar_t kilonewton_meters_per_radian() const
        {
            return convert_from_base(RotationalStiffnessUnit::KilonewtonMetersPerRadian);
        }

        [[nodiscard]] static constexpr RotationalStiffness from_kilonewton_meters_per_radian(const un_scalar_t value)
        {
            return RotationalStiffness(value, RotationalStiffnessUnit::KilonewtonMetersPerRadian);
        }

        [[nodiscard]] constexpr un_scalar_t meganewton_meters_per_radian() const
        {
            return convert_from_base(RotationalStiffnessUnit::MeganewtonMetersPerRadian);
        }

        [[nodiscard]] static constexpr RotationalStiffness from_meganewton_meters_per_radian(const un_scalar_t value)
        {
            return RotationalStiffness(value, RotationalStiffnessUnit::MeganewtonMetersPerRadian);
        }

        [[nodiscard]] constexpr un_scalar_t pound_force_feet_per_degrees() const
        {
            return convert_from_base(RotationalStiffnessUnit::PoundForceFeetPerDegrees);
        }

        [[nodiscard]] static constexpr RotationalStiffness from_pound_force_feet_per_degrees(const un_scalar_t value)
        {
            return RotationalStiffness(value, RotationalStiffnessUnit::PoundForceFeetPerDegrees);
        }

        [[nodiscard]] constexpr un_scalar_t kilopound_force_feet_per_degrees() const
        {
            return convert_from_base(RotationalStiffnessUnit::KilopoundForceFeetPerDegrees);
        }

        [[nodiscard]] static constexpr RotationalStiffness from_kilopound_force_feet_per_degrees(const un_scalar_t value)
        {
            return RotationalStiffness(value, RotationalStiffnessUnit::KilopoundForceFeetPerDegrees);
        }

        [[nodiscard]] constexpr un_scalar_t newton_millimeters_per_degree() const
        {
            return convert_from_base(RotationalStiffnessUnit::NewtonMillimetersPerDegree);
        }

        [[nodiscard]] static constexpr RotationalStiffness from_newton_millimeters_per_degree(const un_scalar_t value)
        {
            return RotationalStiffness(value, RotationalStiffnessUnit::NewtonMillimetersPerDegree);
        }

        [[nodiscard]] constexpr un_scalar_t nanonewton_millimeters_per_degree() const
        {
            return convert_from_base(RotationalStiffnessUnit::NanonewtonMillimetersPerDegree);
        }

        [[nodiscard]] static constexpr RotationalStiffness from_nanonewton_millimeters_per_degree(const un_scalar_t value)
        {
            return RotationalStiffness(value, RotationalStiffnessUnit::NanonewtonMillimetersPerDegree);
        }

        [[nodiscard]] constexpr un_scalar_t micronewton_millimeters_per_degree() const
        {
            return convert_from_base(RotationalStiffnessUnit::MicronewtonMillimetersPerDegree);
        }

        [[nodiscard]] static constexpr RotationalStiffness from_micronewton_millimeters_per_degree(const un_scalar_t value)
        {
            return RotationalStiffness(value, RotationalStiffnessUnit::MicronewtonMillimetersPerDegree);
        }

        [[nodiscard]] constexpr un_scalar_t millinewton_millimeters_per_degree() const
        {
            return convert_from_base(RotationalStiffnessUnit::MillinewtonMillimetersPerDegree);
        }

        [[nodiscard]] static constexpr RotationalStiffness from_millinewton_millimeters_per_degree(const un_scalar_t value)
        {
            return RotationalStiffness(value, RotationalStiffnessUnit::MillinewtonMillimetersPerDegree);
        }

        [[nodiscard]] constexpr un_scalar_t centinewton_millimeters_per_degree() const
        {
            return convert_from_base(RotationalStiffnessUnit::CentinewtonMillimetersPerDegree);
        }

        [[nodiscard]] static constexpr RotationalStiffness from_centinewton_millimeters_per_degree(const un_scalar_t value)
        {
            return RotationalStiffness(value, RotationalStiffnessUnit::CentinewtonMillimetersPerDegree);
        }

        [[nodiscard]] constexpr un_scalar_t decinewton_millimeters_per_degree() const
        {
            return convert_from_base(RotationalStiffnessUnit::DecinewtonMillimetersPerDegree);
        }

        [[nodiscard]] static constexpr RotationalStiffness from_decinewton_millimeters_per_degree(const un_scalar_t value)
        {
            return RotationalStiffness(value, RotationalStiffnessUnit::DecinewtonMillimetersPerDegree);
        }

        [[nodiscard]] constexpr un_scalar_t decanewton_millimeters_per_degree() const
        {
            return convert_from_base(RotationalStiffnessUnit::DecanewtonMillimetersPerDegree);
        }

        [[nodiscard]] static constexpr RotationalStiffness from_decanewton_millimeters_per_degree(const un_scalar_t value)
        {
            return RotationalStiffness(value, RotationalStiffnessUnit::DecanewtonMillimetersPerDegree);
        }

        [[nodiscard]] constexpr un_scalar_t kilonewton_millimeters_per_degree() const
        {
            return convert_from_base(RotationalStiffnessUnit::KilonewtonMillimetersPerDegree);
        }

        [[nodiscard]] static constexpr RotationalStiffness from_kilonewton_millimeters_per_degree(const un_scalar_t value)
        {
            return RotationalStiffness(value, RotationalStiffnessUnit::KilonewtonMillimetersPerDegree);
        }

        [[nodiscard]] constexpr un_scalar_t meganewton_millimeters_per_degree() const
        {
            return convert_from_base(RotationalStiffnessUnit::MeganewtonMillimetersPerDegree);
        }

        [[nodiscard]] static constexpr RotationalStiffness from_meganewton_millimeters_per_degree(const un_scalar_t value)
        {
            return RotationalStiffness(value, RotationalStiffnessUnit::MeganewtonMillimetersPerDegree);
        }

        [[nodiscard]] constexpr un_scalar_t newton_meters_per_degree() const
        {
            return convert_from_base(RotationalStiffnessUnit::NewtonMetersPerDegree);
        }

        [[nodiscard]] static constexpr RotationalStiffness from_newton_meters_per_degree(const un_scalar_t value)
        {
            return RotationalStiffness(value, RotationalStiffnessUnit::NewtonMetersPerDegree);
        }

        [[nodiscard]] constexpr un_scalar_t nanonewton_meters_per_degree() const
        {
            return convert_from_base(RotationalStiffnessUnit::NanonewtonMetersPerDegree);
        }

        [[nodiscard]] static constexpr RotationalStiffness from_nanonewton_meters_per_degree(const un_scalar_t value)
        {
            return RotationalStiffness(value, RotationalStiffnessUnit::NanonewtonMetersPerDegree);
        }

        [[nodiscard]] constexpr un_scalar_t micronewton_meters_per_degree() const
        {
            return convert_from_base(RotationalStiffnessUnit::MicronewtonMetersPerDegree);
        }

        [[nodiscard]] static constexpr RotationalStiffness from_micronewton_meters_per_degree(const un_scalar_t value)
        {
            return RotationalStiffness(value, RotationalStiffnessUnit::MicronewtonMetersPerDegree);
        }

        [[nodiscard]] constexpr un_scalar_t millinewton_meters_per_degree() const
        {
            return convert_from_base(RotationalStiffnessUnit::MillinewtonMetersPerDegree);
        }

        [[nodiscard]] static constexpr RotationalStiffness from_millinewton_meters_per_degree(const un_scalar_t value)
        {
            return RotationalStiffness(value, RotationalStiffnessUnit::MillinewtonMetersPerDegree);
        }

        [[nodiscard]] constexpr un_scalar_t centinewton_meters_per_degree() const
        {
            return convert_from_base(RotationalStiffnessUnit::CentinewtonMetersPerDegree);
        }

        [[nodiscard]] static constexpr RotationalStiffness from_centinewton_meters_per_degree(const un_scalar_t value)
        {
            return RotationalStiffness(value, RotationalStiffnessUnit::CentinewtonMetersPerDegree);
        }

        [[nodiscard]] constexpr un_scalar_t decinewton_meters_per_degree() const
        {
            return convert_from_base(RotationalStiffnessUnit::DecinewtonMetersPerDegree);
        }

        [[nodiscard]] static constexpr RotationalStiffness from_decinewton_meters_per_degree(const un_scalar_t value)
        {
            return RotationalStiffness(value, RotationalStiffnessUnit::DecinewtonMetersPerDegree);
        }

        [[nodiscard]] constexpr un_scalar_t decanewton_meters_per_degree() const
        {
            return convert_from_base(RotationalStiffnessUnit::DecanewtonMetersPerDegree);
        }

        [[nodiscard]] static constexpr RotationalStiffness from_decanewton_meters_per_degree(const un_scalar_t value)
        {
            return RotationalStiffness(value, RotationalStiffnessUnit::DecanewtonMetersPerDegree);
        }

        [[nodiscard]] constexpr un_scalar_t kilonewton_meters_per_degree() const
        {
            return convert_from_base(RotationalStiffnessUnit::KilonewtonMetersPerDegree);
        }

        [[nodiscard]] static constexpr RotationalStiffness from_kilonewton_meters_per_degree(const un_scalar_t value)
        {
            return RotationalStiffness(value, RotationalStiffnessUnit::KilonewtonMetersPerDegree);
        }

        [[nodiscard]] constexpr un_scalar_t meganewton_meters_per_degree() const
        {
            return convert_from_base(RotationalStiffnessUnit::MeganewtonMetersPerDegree);
        }

        [[nodiscard]] static constexpr RotationalStiffness from_meganewton_meters_per_degree(const un_scalar_t value)
        {
            return RotationalStiffness(value, RotationalStiffnessUnit::MeganewtonMetersPerDegree);
        }

        [[nodiscard]] constexpr un_scalar_t newton_millimeters_per_radian() const
        {
            return convert_from_base(RotationalStiffnessUnit::NewtonMillimetersPerRadian);
        }

        [[nodiscard]] static constexpr RotationalStiffness from_newton_millimeters_per_radian(const un_scalar_t value)
        {
            return RotationalStiffness(value, RotationalStiffnessUnit::NewtonMillimetersPerRadian);
        }

        [[nodiscard]] constexpr un_scalar_t nanonewton_millimeters_per_radian() const
        {
            return convert_from_base(RotationalStiffnessUnit::NanonewtonMillimetersPerRadian);
        }

        [[nodiscard]] static constexpr RotationalStiffness from_nanonewton_millimeters_per_radian(const un_scalar_t value)
        {
            return RotationalStiffness(value, RotationalStiffnessUnit::NanonewtonMillimetersPerRadian);
        }

        [[nodiscard]] constexpr un_scalar_t micronewton_millimeters_per_radian() const
        {
            return convert_from_base(RotationalStiffnessUnit::MicronewtonMillimetersPerRadian);
        }

        [[nodiscard]] static constexpr RotationalStiffness from_micronewton_millimeters_per_radian(const un_scalar_t value)
        {
            return RotationalStiffness(value, RotationalStiffnessUnit::MicronewtonMillimetersPerRadian);
        }

        [[nodiscard]] constexpr un_scalar_t millinewton_millimeters_per_radian() const
        {
            return convert_from_base(RotationalStiffnessUnit::MillinewtonMillimetersPerRadian);
        }

        [[nodiscard]] static constexpr RotationalStiffness from_millinewton_millimeters_per_radian(const un_scalar_t value)
        {
            return RotationalStiffness(value, RotationalStiffnessUnit::MillinewtonMillimetersPerRadian);
        }

        [[nodiscard]] constexpr un_scalar_t centinewton_millimeters_per_radian() const
        {
            return convert_from_base(RotationalStiffnessUnit::CentinewtonMillimetersPerRadian);
        }

        [[nodiscard]] static constexpr RotationalStiffness from_centinewton_millimeters_per_radian(const un_scalar_t value)
        {
            return RotationalStiffness(value, RotationalStiffnessUnit::CentinewtonMillimetersPerRadian);
        }

        [[nodiscard]] constexpr un_scalar_t decinewton_millimeters_per_radian() const
        {
            return convert_from_base(RotationalStiffnessUnit::DecinewtonMillimetersPerRadian);
        }

        [[nodiscard]] static constexpr RotationalStiffness from_decinewton_millimeters_per_radian(const un_scalar_t value)
        {
            return RotationalStiffness(value, RotationalStiffnessUnit::DecinewtonMillimetersPerRadian);
        }

        [[nodiscard]] constexpr un_scalar_t decanewton_millimeters_per_radian() const
        {
            return convert_from_base(RotationalStiffnessUnit::DecanewtonMillimetersPerRadian);
        }

        [[nodiscard]] static constexpr RotationalStiffness from_decanewton_millimeters_per_radian(const un_scalar_t value)
        {
            return RotationalStiffness(value, RotationalStiffnessUnit::DecanewtonMillimetersPerRadian);
        }

        [[nodiscard]] constexpr un_scalar_t kilonewton_millimeters_per_radian() const
        {
            return convert_from_base(RotationalStiffnessUnit::KilonewtonMillimetersPerRadian);
        }

        [[nodiscard]] static constexpr RotationalStiffness from_kilonewton_millimeters_per_radian(const un_scalar_t value)
        {
            return RotationalStiffness(value, RotationalStiffnessUnit::KilonewtonMillimetersPerRadian);
        }

        [[nodiscard]] constexpr un_scalar_t meganewton_millimeters_per_radian() const
        {
            return convert_from_base(RotationalStiffnessUnit::MeganewtonMillimetersPerRadian);
        }

        [[nodiscard]] static constexpr RotationalStiffness from_meganewton_millimeters_per_radian(const un_scalar_t value)
        {
            return RotationalStiffness(value, RotationalStiffnessUnit::MeganewtonMillimetersPerRadian);
        }

        [[nodiscard]] constexpr un_scalar_t pound_force_feet_per_radian() const
        {
            return convert_from_base(RotationalStiffnessUnit::PoundForceFeetPerRadian);
        }

        [[nodiscard]] static constexpr RotationalStiffness from_pound_force_feet_per_radian(const un_scalar_t value)
        {
            return RotationalStiffness(value, RotationalStiffnessUnit::PoundForceFeetPerRadian);
        }

        [[nodiscard]] constexpr un_scalar_t kilopound_force_feet_per_radian() const
        {
            return convert_from_base(RotationalStiffnessUnit::KilopoundForceFeetPerRadian);
        }

        [[nodiscard]] static constexpr RotationalStiffness from_kilopound_force_feet_per_radian(const un_scalar_t value)
        {
            return RotationalStiffness(value, RotationalStiffnessUnit::KilopoundForceFeetPerRadian);
        }

        [[nodiscard]] static constexpr RotationalStiffness from_invalid()
        {
            return RotationalStiffness(false);
        }
    private:
            
        [[nodiscard]] static constexpr un_scalar_t convert_to_base(un_scalar_t value, RotationalStiffnessUnit unit)
        {
            switch (unit)
            {

            case RotationalStiffnessUnit::NewtonMetersPerRadian:
                return value;

            case RotationalStiffnessUnit::KilonewtonMetersPerRadian:
                return (value * static_cast<un_scalar_t>(1e3));

            case RotationalStiffnessUnit::MeganewtonMetersPerRadian:
                return (value * static_cast<un_scalar_t>(1e6));

            case RotationalStiffnessUnit::PoundForceFeetPerDegrees:
                return value * (static_cast<un_scalar_t>(4.4482216152605) * static_cast<un_scalar_t>(0.3048) * static_cast<un_scalar_t>(180) / std::numbers::pi_v<un_scalar_t>);

            case RotationalStiffnessUnit::KilopoundForceFeetPerDegrees:
                return value * (static_cast<un_scalar_t>(4.4482216152605e3) * static_cast<un_scalar_t>(0.3048) * static_cast<un_scalar_t>(180) / std::numbers::pi_v<un_scalar_t>);

            case RotationalStiffnessUnit::NewtonMillimetersPerDegree:
                return value * static_cast<un_scalar_t>(180) / std::numbers::pi_v<un_scalar_t> * static_cast<un_scalar_t>(0.001);

            case RotationalStiffnessUnit::NanonewtonMillimetersPerDegree:
                return (value * static_cast<un_scalar_t>(1e-9)) * static_cast<un_scalar_t>(180) / std::numbers::pi_v<un_scalar_t> * static_cast<un_scalar_t>(0.001);

            case RotationalStiffnessUnit::MicronewtonMillimetersPerDegree:
                return (value * static_cast<un_scalar_t>(1e-6)) * static_cast<un_scalar_t>(180) / std::numbers::pi_v<un_scalar_t> * static_cast<un_scalar_t>(0.001);

            case RotationalStiffnessUnit::MillinewtonMillimetersPerDegree:
                return (value * static_cast<un_scalar_t>(1e-3)) * static_cast<un_scalar_t>(180) / std::numbers::pi_v<un_scalar_t> * static_cast<un_scalar_t>(0.001);

            case RotationalStiffnessUnit::CentinewtonMillimetersPerDegree:
                return (value * static_cast<un_scalar_t>(1e-2)) * static_cast<un_scalar_t>(180) / std::numbers::pi_v<un_scalar_t> * static_cast<un_scalar_t>(0.001);

            case RotationalStiffnessUnit::DecinewtonMillimetersPerDegree:
                return (value * static_cast<un_scalar_t>(1e-1)) * static_cast<un_scalar_t>(180) / std::numbers::pi_v<un_scalar_t> * static_cast<un_scalar_t>(0.001);

            case RotationalStiffnessUnit::DecanewtonMillimetersPerDegree:
                return (value * static_cast<un_scalar_t>(1e1)) * static_cast<un_scalar_t>(180) / std::numbers::pi_v<un_scalar_t> * static_cast<un_scalar_t>(0.001);

            case RotationalStiffnessUnit::KilonewtonMillimetersPerDegree:
                return (value * static_cast<un_scalar_t>(1e3)) * static_cast<un_scalar_t>(180) / std::numbers::pi_v<un_scalar_t> * static_cast<un_scalar_t>(0.001);

            case RotationalStiffnessUnit::MeganewtonMillimetersPerDegree:
                return (value * static_cast<un_scalar_t>(1e6)) * static_cast<un_scalar_t>(180) / std::numbers::pi_v<un_scalar_t> * static_cast<un_scalar_t>(0.001);

            case RotationalStiffnessUnit::NewtonMetersPerDegree:
                return value * (static_cast<un_scalar_t>(180) / std::numbers::pi_v<un_scalar_t>);

            case RotationalStiffnessUnit::NanonewtonMetersPerDegree:
                return (value * static_cast<un_scalar_t>(1e-9)) * (static_cast<un_scalar_t>(180) / std::numbers::pi_v<un_scalar_t>);

            case RotationalStiffnessUnit::MicronewtonMetersPerDegree:
                return (value * static_cast<un_scalar_t>(1e-6)) * (static_cast<un_scalar_t>(180) / std::numbers::pi_v<un_scalar_t>);

            case RotationalStiffnessUnit::MillinewtonMetersPerDegree:
                return (value * static_cast<un_scalar_t>(1e-3)) * (static_cast<un_scalar_t>(180) / std::numbers::pi_v<un_scalar_t>);

            case RotationalStiffnessUnit::CentinewtonMetersPerDegree:
                return (value * static_cast<un_scalar_t>(1e-2)) * (static_cast<un_scalar_t>(180) / std::numbers::pi_v<un_scalar_t>);

            case RotationalStiffnessUnit::DecinewtonMetersPerDegree:
                return (value * static_cast<un_scalar_t>(1e-1)) * (static_cast<un_scalar_t>(180) / std::numbers::pi_v<un_scalar_t>);

            case RotationalStiffnessUnit::DecanewtonMetersPerDegree:
                return (value * static_cast<un_scalar_t>(1e1)) * (static_cast<un_scalar_t>(180) / std::numbers::pi_v<un_scalar_t>);

            case RotationalStiffnessUnit::KilonewtonMetersPerDegree:
                return (value * static_cast<un_scalar_t>(1e3)) * (static_cast<un_scalar_t>(180) / std::numbers::pi_v<un_scalar_t>);

            case RotationalStiffnessUnit::MeganewtonMetersPerDegree:
                return (value * static_cast<un_scalar_t>(1e6)) * (static_cast<un_scalar_t>(180) / std::numbers::pi_v<un_scalar_t>);

            case RotationalStiffnessUnit::NewtonMillimetersPerRadian:
                return value * static_cast<un_scalar_t>(0.001);

            case RotationalStiffnessUnit::NanonewtonMillimetersPerRadian:
                return (value * static_cast<un_scalar_t>(1e-9)) * static_cast<un_scalar_t>(0.001);

            case RotationalStiffnessUnit::MicronewtonMillimetersPerRadian:
                return (value * static_cast<un_scalar_t>(1e-6)) * static_cast<un_scalar_t>(0.001);

            case RotationalStiffnessUnit::MillinewtonMillimetersPerRadian:
                return (value * static_cast<un_scalar_t>(1e-3)) * static_cast<un_scalar_t>(0.001);

            case RotationalStiffnessUnit::CentinewtonMillimetersPerRadian:
                return (value * static_cast<un_scalar_t>(1e-2)) * static_cast<un_scalar_t>(0.001);

            case RotationalStiffnessUnit::DecinewtonMillimetersPerRadian:
                return (value * static_cast<un_scalar_t>(1e-1)) * static_cast<un_scalar_t>(0.001);

            case RotationalStiffnessUnit::DecanewtonMillimetersPerRadian:
                return (value * static_cast<un_scalar_t>(1e1)) * static_cast<un_scalar_t>(0.001);

            case RotationalStiffnessUnit::KilonewtonMillimetersPerRadian:
                return (value * static_cast<un_scalar_t>(1e3)) * static_cast<un_scalar_t>(0.001);

            case RotationalStiffnessUnit::MeganewtonMillimetersPerRadian:
                return (value * static_cast<un_scalar_t>(1e6)) * static_cast<un_scalar_t>(0.001);

            case RotationalStiffnessUnit::PoundForceFeetPerRadian:
                return value * static_cast<un_scalar_t>(4.4482216152605) * static_cast<un_scalar_t>(0.3048);

            case RotationalStiffnessUnit::KilopoundForceFeetPerRadian:
                return value * static_cast<un_scalar_t>(4.4482216152605e3) * static_cast<un_scalar_t>(0.3048);

            }

            throw std::invalid_argument("Unknown RotationalStiffness unit.");
        }

        [[nodiscard]] constexpr un_scalar_t convert_from_base(const RotationalStiffnessUnit unit) const
        {
            if(unit == value_unit_type_)
            {
                return value_;
            }
            
            auto base_value = convert_to_base(value_, value_unit_type_);
            
            switch (unit)
            {

            case RotationalStiffnessUnit::NewtonMetersPerRadian:
                return base_value;

            case RotationalStiffnessUnit::KilonewtonMetersPerRadian:
                return (base_value) / static_cast<un_scalar_t>(1e3);

            case RotationalStiffnessUnit::MeganewtonMetersPerRadian:
                return (base_value) / static_cast<un_scalar_t>(1e6);

            case RotationalStiffnessUnit::PoundForceFeetPerDegrees:
                return base_value / (static_cast<un_scalar_t>(4.4482216152605) * static_cast<un_scalar_t>(0.3048) * static_cast<un_scalar_t>(180) / std::numbers::pi_v<un_scalar_t>);

            case RotationalStiffnessUnit::KilopoundForceFeetPerDegrees:
                return base_value / (static_cast<un_scalar_t>(4.4482216152605e3) * static_cast<un_scalar_t>(0.3048) * static_cast<un_scalar_t>(180) / std::numbers::pi_v<un_scalar_t>);

            case RotationalStiffnessUnit::NewtonMillimetersPerDegree:
                return base_value / static_cast<un_scalar_t>(180) * std::numbers::pi_v<un_scalar_t> * static_cast<un_scalar_t>(1000);

            case RotationalStiffnessUnit::NanonewtonMillimetersPerDegree:
                return (base_value / static_cast<un_scalar_t>(180) * std::numbers::pi_v<un_scalar_t> * static_cast<un_scalar_t>(1000)) / static_cast<un_scalar_t>(1e-9);

            case RotationalStiffnessUnit::MicronewtonMillimetersPerDegree:
                return (base_value / static_cast<un_scalar_t>(180) * std::numbers::pi_v<un_scalar_t> * static_cast<un_scalar_t>(1000)) / static_cast<un_scalar_t>(1e-6);

            case RotationalStiffnessUnit::MillinewtonMillimetersPerDegree:
                return (base_value / static_cast<un_scalar_t>(180) * std::numbers::pi_v<un_scalar_t> * static_cast<un_scalar_t>(1000)) / static_cast<un_scalar_t>(1e-3);

            case RotationalStiffnessUnit::CentinewtonMillimetersPerDegree:
                return (base_value / static_cast<un_scalar_t>(180) * std::numbers::pi_v<un_scalar_t> * static_cast<un_scalar_t>(1000)) / static_cast<un_scalar_t>(1e-2);

            case RotationalStiffnessUnit::DecinewtonMillimetersPerDegree:
                return (base_value / static_cast<un_scalar_t>(180) * std::numbers::pi_v<un_scalar_t> * static_cast<un_scalar_t>(1000)) / static_cast<un_scalar_t>(1e-1);

            case RotationalStiffnessUnit::DecanewtonMillimetersPerDegree:
                return (base_value / static_cast<un_scalar_t>(180) * std::numbers::pi_v<un_scalar_t> * static_cast<un_scalar_t>(1000)) / static_cast<un_scalar_t>(1e1);

            case RotationalStiffnessUnit::KilonewtonMillimetersPerDegree:
                return (base_value / static_cast<un_scalar_t>(180) * std::numbers::pi_v<un_scalar_t> * static_cast<un_scalar_t>(1000)) / static_cast<un_scalar_t>(1e3);

            case RotationalStiffnessUnit::MeganewtonMillimetersPerDegree:
                return (base_value / static_cast<un_scalar_t>(180) * std::numbers::pi_v<un_scalar_t> * static_cast<un_scalar_t>(1000)) / static_cast<un_scalar_t>(1e6);

            case RotationalStiffnessUnit::NewtonMetersPerDegree:
                return base_value / (static_cast<un_scalar_t>(180) / std::numbers::pi_v<un_scalar_t>);

            case RotationalStiffnessUnit::NanonewtonMetersPerDegree:
                return (base_value / (static_cast<un_scalar_t>(180) / std::numbers::pi_v<un_scalar_t>)) / static_cast<un_scalar_t>(1e-9);

            case RotationalStiffnessUnit::MicronewtonMetersPerDegree:
                return (base_value / (static_cast<un_scalar_t>(180) / std::numbers::pi_v<un_scalar_t>)) / static_cast<un_scalar_t>(1e-6);

            case RotationalStiffnessUnit::MillinewtonMetersPerDegree:
                return (base_value / (static_cast<un_scalar_t>(180) / std::numbers::pi_v<un_scalar_t>)) / static_cast<un_scalar_t>(1e-3);

            case RotationalStiffnessUnit::CentinewtonMetersPerDegree:
                return (base_value / (static_cast<un_scalar_t>(180) / std::numbers::pi_v<un_scalar_t>)) / static_cast<un_scalar_t>(1e-2);

            case RotationalStiffnessUnit::DecinewtonMetersPerDegree:
                return (base_value / (static_cast<un_scalar_t>(180) / std::numbers::pi_v<un_scalar_t>)) / static_cast<un_scalar_t>(1e-1);

            case RotationalStiffnessUnit::DecanewtonMetersPerDegree:
                return (base_value / (static_cast<un_scalar_t>(180) / std::numbers::pi_v<un_scalar_t>)) / static_cast<un_scalar_t>(1e1);

            case RotationalStiffnessUnit::KilonewtonMetersPerDegree:
                return (base_value / (static_cast<un_scalar_t>(180) / std::numbers::pi_v<un_scalar_t>)) / static_cast<un_scalar_t>(1e3);

            case RotationalStiffnessUnit::MeganewtonMetersPerDegree:
                return (base_value / (static_cast<un_scalar_t>(180) / std::numbers::pi_v<un_scalar_t>)) / static_cast<un_scalar_t>(1e6);

            case RotationalStiffnessUnit::NewtonMillimetersPerRadian:
                return base_value * static_cast<un_scalar_t>(1000);

            case RotationalStiffnessUnit::NanonewtonMillimetersPerRadian:
                return (base_value * static_cast<un_scalar_t>(1000)) / static_cast<un_scalar_t>(1e-9);

            case RotationalStiffnessUnit::MicronewtonMillimetersPerRadian:
                return (base_value * static_cast<un_scalar_t>(1000)) / static_cast<un_scalar_t>(1e-6);

            case RotationalStiffnessUnit::MillinewtonMillimetersPerRadian:
                return (base_value * static_cast<un_scalar_t>(1000)) / static_cast<un_scalar_t>(1e-3);

            case RotationalStiffnessUnit::CentinewtonMillimetersPerRadian:
                return (base_value * static_cast<un_scalar_t>(1000)) / static_cast<un_scalar_t>(1e-2);

            case RotationalStiffnessUnit::DecinewtonMillimetersPerRadian:
                return (base_value * static_cast<un_scalar_t>(1000)) / static_cast<un_scalar_t>(1e-1);

            case RotationalStiffnessUnit::DecanewtonMillimetersPerRadian:
                return (base_value * static_cast<un_scalar_t>(1000)) / static_cast<un_scalar_t>(1e1);

            case RotationalStiffnessUnit::KilonewtonMillimetersPerRadian:
                return (base_value * static_cast<un_scalar_t>(1000)) / static_cast<un_scalar_t>(1e3);

            case RotationalStiffnessUnit::MeganewtonMillimetersPerRadian:
                return (base_value * static_cast<un_scalar_t>(1000)) / static_cast<un_scalar_t>(1e6);

            case RotationalStiffnessUnit::PoundForceFeetPerRadian:
                return base_value / (static_cast<un_scalar_t>(4.4482216152605) * static_cast<un_scalar_t>(0.3048));

            case RotationalStiffnessUnit::KilopoundForceFeetPerRadian:
                return base_value / (static_cast<un_scalar_t>(4.4482216152605e3) * static_cast<un_scalar_t>(0.3048));

            }

            throw std::invalid_argument("Unknown RotationalStiffness unit.");
        }

        un_scalar_t value_;
        RotationalStiffnessUnit value_unit_type_;       
    };
}
