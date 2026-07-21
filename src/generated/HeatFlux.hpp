#pragma once

#include <cstdint>
#include <numbers>
#include <stdexcept>
#include <string>
#include <string_view>
#if defined(UNITSNET_ENABLE_DTO) || defined(UNITSNET_ENABLE_NLOHMANN_JSON)
#include <magic_enum/magic_enum.hpp>
#endif
#ifdef UNITSNET_ENABLE_NLOHMANN_JSON
#include <nlohmann/json.hpp>
#endif
#include "UnitsNetConfig.h"
#include "UnitsNetBase.h"

namespace unitsnet_cpp
{
    enum class HeatFluxUnit : std::uint8_t
    {
        WattPerSquareMeter,
        NanowattPerSquareMeter,
        MicrowattPerSquareMeter,
        MilliwattPerSquareMeter,
        CentiwattPerSquareMeter,
        DeciwattPerSquareMeter,
        KilowattPerSquareMeter,
        WattPerSquareMillimeter,
        NanowattPerSquareMillimeter,
        MicrowattPerSquareMillimeter,
        MilliwattPerSquareMillimeter,
        CentiwattPerSquareMillimeter,
        DeciwattPerSquareMillimeter,
        KilowattPerSquareMillimeter,
        WattPerSquareInch,
        WattPerSquareFoot,
        BtuPerSecondSquareInch,
        BtuPerSecondSquareFoot,
        BtuPerMinuteSquareFoot,
        BtuPerHourSquareFoot,
        CaloriePerSecondSquareCentimeter,
        KilocaloriePerSecondSquareCentimeter,
        KilocaloriePerHourSquareMeter,
        PoundForcePerFootSecond,
        PoundPerSecondCubed,
    };

#if defined(UNITSNET_ENABLE_DTO) || defined(UNITSNET_ENABLE_NLOHMANN_JSON)
    /// <summary>A data-transfer representation of HeatFlux.</summary>
    class HeatFluxDto
    {
    public:
        constexpr HeatFluxDto() noexcept
            : value{}, unit(HeatFluxUnit::WattPerSquareMeter)
        {
        }

        constexpr HeatFluxDto(
            const un_scalar_t value,
            const HeatFluxUnit unit) noexcept
            : value(value), unit(unit)
        {
        }

        /// <summary>The numeric value of the quantity.</summary>
        un_scalar_t value;

        /// <summary>The unit in which value is expressed.</summary>
        HeatFluxUnit unit;

        /// <summary>The stable UnitsNet name used for cross-language serialization.</summary>
        [[nodiscard]] constexpr std::string_view unit_name() const noexcept
        {
            return magic_enum::enum_name(unit);
        }

        /// <summary>Converts a stable UnitsNet unit name to its strongly typed enum.</summary>
        [[nodiscard]] static constexpr HeatFluxUnit unit_from_name(const std::string_view name)
        {
            const auto unit = magic_enum::enum_cast<HeatFluxUnit>(name);
            if (unit.has_value())
            {
                return *unit;
            }

            throw std::invalid_argument("Unknown HeatFlux unit name.");
        }

#ifdef UNITSNET_ENABLE_NLOHMANN_JSON
        /// <summary>Serializes this DTO to a nlohmann JSON object.</summary>
        [[nodiscard]] nlohmann::json to_json() const
        {
            return nlohmann::json{
                {"value", value},
                {"unit", unit_name()}
            };
        }

        /// <summary>Creates a DTO from a nlohmann JSON object.</summary>
        [[nodiscard]] static HeatFluxDto from_json(const nlohmann::json& json)
        {
            return HeatFluxDto(
                json.at("value").get<un_scalar_t>(),
                unit_from_name(json.at("unit").get<std::string>()));
        }
#endif
    };
#endif

    /// <summary>Heat flux is the flow of energy per unit of area per unit of time</summary>
    class HeatFlux : public UnitsNetBase
    {
    public:
        constexpr explicit HeatFlux(
            const un_scalar_t value,
            const HeatFluxUnit unit = HeatFluxUnit::WattPerSquareMeter)
        {
            value_ = value;
            value_unit_type_ = unit;
        }
                
        [[nodiscard]] constexpr un_scalar_t base_value() const noexcept
        {
            return convert_to_base(value_, value_unit_type_);    
        }

        [[nodiscard]] constexpr un_scalar_t value(const HeatFluxUnit unit) const
        {
            return convert_from_base(unit);
        }

#if defined(UNITSNET_ENABLE_DTO) || defined(UNITSNET_ENABLE_NLOHMANN_JSON)
        /// <summary>Creates a DTO, expressed in the requested unit.</summary>
        [[nodiscard]] constexpr HeatFluxDto to_dto(
            const HeatFluxUnit unit = HeatFluxUnit::WattPerSquareMeter) const
        {
            return HeatFluxDto(value(unit), unit);
        }

        /// <summary>Creates a quantity from its DTO representation.</summary>
        [[nodiscard]] static constexpr HeatFlux from_dto(const HeatFluxDto& dto)
        {
            return HeatFlux(dto.value, dto.unit);
        }

#ifdef UNITSNET_ENABLE_NLOHMANN_JSON
        /// <summary>Serializes this quantity to a nlohmann JSON object.</summary>
        [[nodiscard]] nlohmann::json to_json(
            const HeatFluxUnit unit = HeatFluxUnit::WattPerSquareMeter) const
        {
            return to_dto(unit).to_json();
        }

        /// <summary>Creates a quantity from a nlohmann JSON object.</summary>
        [[nodiscard]] static HeatFlux from_json(const nlohmann::json& json)
        {
            return from_dto(HeatFluxDto::from_json(json));
        }
#endif
#endif

        [[nodiscard]] constexpr HeatFlux operator+(const HeatFlux& other) const noexcept
        {
            return HeatFlux(base_value() + other.base_value());
        }

        [[nodiscard]] constexpr HeatFlux operator-(const HeatFlux& other)const noexcept
        {
            return HeatFlux(base_value() - other.base_value());
        }

        [[nodiscard]] constexpr HeatFlux operator*(const un_scalar_t scalar) const noexcept
        {
            return HeatFlux(base_value() * scalar);
        }

        [[nodiscard]] constexpr HeatFlux operator/(const un_scalar_t scalar) const noexcept
        {
            return HeatFlux(base_value() / scalar);
        }

        [[nodiscard]] constexpr bool operator==(const HeatFlux& other) const noexcept
        {
            return base_value() == other.base_value();
        }

        [[nodiscard]] constexpr bool operator<(const HeatFlux& other) const noexcept
        {
            return base_value() < other.base_value();
        }
        
        [[nodiscard]] constexpr bool operator>(const HeatFlux& other) const noexcept
        {
            return base_value() > other.base_value();
        }

        [[nodiscard]] constexpr un_scalar_t watts_per_square_meter() const
        {
            return convert_from_base(HeatFluxUnit::WattPerSquareMeter);
        }

        [[nodiscard]] static constexpr HeatFlux from_watts_per_square_meter(const un_scalar_t value)
        {
            return HeatFlux(value, HeatFluxUnit::WattPerSquareMeter);
        }

        [[nodiscard]] constexpr un_scalar_t nanowatts_per_square_meter() const
        {
            return convert_from_base(HeatFluxUnit::NanowattPerSquareMeter);
        }

        [[nodiscard]] static constexpr HeatFlux from_nanowatts_per_square_meter(const un_scalar_t value)
        {
            return HeatFlux(value, HeatFluxUnit::NanowattPerSquareMeter);
        }

        [[nodiscard]] constexpr un_scalar_t microwatts_per_square_meter() const
        {
            return convert_from_base(HeatFluxUnit::MicrowattPerSquareMeter);
        }

        [[nodiscard]] static constexpr HeatFlux from_microwatts_per_square_meter(const un_scalar_t value)
        {
            return HeatFlux(value, HeatFluxUnit::MicrowattPerSquareMeter);
        }

        [[nodiscard]] constexpr un_scalar_t milliwatts_per_square_meter() const
        {
            return convert_from_base(HeatFluxUnit::MilliwattPerSquareMeter);
        }

        [[nodiscard]] static constexpr HeatFlux from_milliwatts_per_square_meter(const un_scalar_t value)
        {
            return HeatFlux(value, HeatFluxUnit::MilliwattPerSquareMeter);
        }

        [[nodiscard]] constexpr un_scalar_t centiwatts_per_square_meter() const
        {
            return convert_from_base(HeatFluxUnit::CentiwattPerSquareMeter);
        }

        [[nodiscard]] static constexpr HeatFlux from_centiwatts_per_square_meter(const un_scalar_t value)
        {
            return HeatFlux(value, HeatFluxUnit::CentiwattPerSquareMeter);
        }

        [[nodiscard]] constexpr un_scalar_t deciwatts_per_square_meter() const
        {
            return convert_from_base(HeatFluxUnit::DeciwattPerSquareMeter);
        }

        [[nodiscard]] static constexpr HeatFlux from_deciwatts_per_square_meter(const un_scalar_t value)
        {
            return HeatFlux(value, HeatFluxUnit::DeciwattPerSquareMeter);
        }

        [[nodiscard]] constexpr un_scalar_t kilowatts_per_square_meter() const
        {
            return convert_from_base(HeatFluxUnit::KilowattPerSquareMeter);
        }

        [[nodiscard]] static constexpr HeatFlux from_kilowatts_per_square_meter(const un_scalar_t value)
        {
            return HeatFlux(value, HeatFluxUnit::KilowattPerSquareMeter);
        }

        [[nodiscard]] constexpr un_scalar_t watts_per_square_millimeter() const
        {
            return convert_from_base(HeatFluxUnit::WattPerSquareMillimeter);
        }

        [[nodiscard]] static constexpr HeatFlux from_watts_per_square_millimeter(const un_scalar_t value)
        {
            return HeatFlux(value, HeatFluxUnit::WattPerSquareMillimeter);
        }

        [[nodiscard]] constexpr un_scalar_t nanowatts_per_square_millimeter() const
        {
            return convert_from_base(HeatFluxUnit::NanowattPerSquareMillimeter);
        }

        [[nodiscard]] static constexpr HeatFlux from_nanowatts_per_square_millimeter(const un_scalar_t value)
        {
            return HeatFlux(value, HeatFluxUnit::NanowattPerSquareMillimeter);
        }

        [[nodiscard]] constexpr un_scalar_t microwatts_per_square_millimeter() const
        {
            return convert_from_base(HeatFluxUnit::MicrowattPerSquareMillimeter);
        }

        [[nodiscard]] static constexpr HeatFlux from_microwatts_per_square_millimeter(const un_scalar_t value)
        {
            return HeatFlux(value, HeatFluxUnit::MicrowattPerSquareMillimeter);
        }

        [[nodiscard]] constexpr un_scalar_t milliwatts_per_square_millimeter() const
        {
            return convert_from_base(HeatFluxUnit::MilliwattPerSquareMillimeter);
        }

        [[nodiscard]] static constexpr HeatFlux from_milliwatts_per_square_millimeter(const un_scalar_t value)
        {
            return HeatFlux(value, HeatFluxUnit::MilliwattPerSquareMillimeter);
        }

        [[nodiscard]] constexpr un_scalar_t centiwatts_per_square_millimeter() const
        {
            return convert_from_base(HeatFluxUnit::CentiwattPerSquareMillimeter);
        }

        [[nodiscard]] static constexpr HeatFlux from_centiwatts_per_square_millimeter(const un_scalar_t value)
        {
            return HeatFlux(value, HeatFluxUnit::CentiwattPerSquareMillimeter);
        }

        [[nodiscard]] constexpr un_scalar_t deciwatts_per_square_millimeter() const
        {
            return convert_from_base(HeatFluxUnit::DeciwattPerSquareMillimeter);
        }

        [[nodiscard]] static constexpr HeatFlux from_deciwatts_per_square_millimeter(const un_scalar_t value)
        {
            return HeatFlux(value, HeatFluxUnit::DeciwattPerSquareMillimeter);
        }

        [[nodiscard]] constexpr un_scalar_t kilowatts_per_square_millimeter() const
        {
            return convert_from_base(HeatFluxUnit::KilowattPerSquareMillimeter);
        }

        [[nodiscard]] static constexpr HeatFlux from_kilowatts_per_square_millimeter(const un_scalar_t value)
        {
            return HeatFlux(value, HeatFluxUnit::KilowattPerSquareMillimeter);
        }

        [[nodiscard]] constexpr un_scalar_t watts_per_square_inch() const
        {
            return convert_from_base(HeatFluxUnit::WattPerSquareInch);
        }

        [[nodiscard]] static constexpr HeatFlux from_watts_per_square_inch(const un_scalar_t value)
        {
            return HeatFlux(value, HeatFluxUnit::WattPerSquareInch);
        }

        [[nodiscard]] constexpr un_scalar_t watts_per_square_foot() const
        {
            return convert_from_base(HeatFluxUnit::WattPerSquareFoot);
        }

        [[nodiscard]] static constexpr HeatFlux from_watts_per_square_foot(const un_scalar_t value)
        {
            return HeatFlux(value, HeatFluxUnit::WattPerSquareFoot);
        }

        [[nodiscard]] constexpr un_scalar_t btus_per_second_square_inch() const
        {
            return convert_from_base(HeatFluxUnit::BtuPerSecondSquareInch);
        }

        [[nodiscard]] static constexpr HeatFlux from_btus_per_second_square_inch(const un_scalar_t value)
        {
            return HeatFlux(value, HeatFluxUnit::BtuPerSecondSquareInch);
        }

        [[nodiscard]] constexpr un_scalar_t btus_per_second_square_foot() const
        {
            return convert_from_base(HeatFluxUnit::BtuPerSecondSquareFoot);
        }

        [[nodiscard]] static constexpr HeatFlux from_btus_per_second_square_foot(const un_scalar_t value)
        {
            return HeatFlux(value, HeatFluxUnit::BtuPerSecondSquareFoot);
        }

        [[nodiscard]] constexpr un_scalar_t btus_per_minute_square_foot() const
        {
            return convert_from_base(HeatFluxUnit::BtuPerMinuteSquareFoot);
        }

        [[nodiscard]] static constexpr HeatFlux from_btus_per_minute_square_foot(const un_scalar_t value)
        {
            return HeatFlux(value, HeatFluxUnit::BtuPerMinuteSquareFoot);
        }

        [[nodiscard]] constexpr un_scalar_t btus_per_hour_square_foot() const
        {
            return convert_from_base(HeatFluxUnit::BtuPerHourSquareFoot);
        }

        [[nodiscard]] static constexpr HeatFlux from_btus_per_hour_square_foot(const un_scalar_t value)
        {
            return HeatFlux(value, HeatFluxUnit::BtuPerHourSquareFoot);
        }

        [[nodiscard]] constexpr un_scalar_t calories_per_second_square_centimeter() const
        {
            return convert_from_base(HeatFluxUnit::CaloriePerSecondSquareCentimeter);
        }

        [[nodiscard]] static constexpr HeatFlux from_calories_per_second_square_centimeter(const un_scalar_t value)
        {
            return HeatFlux(value, HeatFluxUnit::CaloriePerSecondSquareCentimeter);
        }

        [[nodiscard]] constexpr un_scalar_t kilocalories_per_second_square_centimeter() const
        {
            return convert_from_base(HeatFluxUnit::KilocaloriePerSecondSquareCentimeter);
        }

        [[nodiscard]] static constexpr HeatFlux from_kilocalories_per_second_square_centimeter(const un_scalar_t value)
        {
            return HeatFlux(value, HeatFluxUnit::KilocaloriePerSecondSquareCentimeter);
        }

        [[nodiscard]] constexpr un_scalar_t kilocalories_per_hour_square_meter() const
        {
            return convert_from_base(HeatFluxUnit::KilocaloriePerHourSquareMeter);
        }

        [[nodiscard]] static constexpr HeatFlux from_kilocalories_per_hour_square_meter(const un_scalar_t value)
        {
            return HeatFlux(value, HeatFluxUnit::KilocaloriePerHourSquareMeter);
        }

        [[nodiscard]] constexpr un_scalar_t pounds_force_per_foot_second() const
        {
            return convert_from_base(HeatFluxUnit::PoundForcePerFootSecond);
        }

        [[nodiscard]] static constexpr HeatFlux from_pounds_force_per_foot_second(const un_scalar_t value)
        {
            return HeatFlux(value, HeatFluxUnit::PoundForcePerFootSecond);
        }

        [[nodiscard]] constexpr un_scalar_t pounds_per_second_cubed() const
        {
            return convert_from_base(HeatFluxUnit::PoundPerSecondCubed);
        }

        [[nodiscard]] static constexpr HeatFlux from_pounds_per_second_cubed(const un_scalar_t value)
        {
            return HeatFlux(value, HeatFluxUnit::PoundPerSecondCubed);
        }

        [[nodiscard]] static constexpr HeatFlux from_invalid()
        {
            return HeatFlux(false);
        }
    private:
            
        [[nodiscard]] static constexpr un_scalar_t convert_to_base(un_scalar_t value, HeatFluxUnit unit)
        {
            switch (unit)
            {

            case HeatFluxUnit::WattPerSquareMeter:
                return value;

            case HeatFluxUnit::NanowattPerSquareMeter:
                return (value * static_cast<un_scalar_t>(1e-9));

            case HeatFluxUnit::MicrowattPerSquareMeter:
                return (value * static_cast<un_scalar_t>(1e-6));

            case HeatFluxUnit::MilliwattPerSquareMeter:
                return (value * static_cast<un_scalar_t>(1e-3));

            case HeatFluxUnit::CentiwattPerSquareMeter:
                return (value * static_cast<un_scalar_t>(1e-2));

            case HeatFluxUnit::DeciwattPerSquareMeter:
                return (value * static_cast<un_scalar_t>(1e-1));

            case HeatFluxUnit::KilowattPerSquareMeter:
                return (value * static_cast<un_scalar_t>(1e3));

            case HeatFluxUnit::WattPerSquareMillimeter:
                return value / static_cast<un_scalar_t>(1e-6);

            case HeatFluxUnit::NanowattPerSquareMillimeter:
                return (value * static_cast<un_scalar_t>(1e-9)) / static_cast<un_scalar_t>(1e-6);

            case HeatFluxUnit::MicrowattPerSquareMillimeter:
                return (value * static_cast<un_scalar_t>(1e-6)) / static_cast<un_scalar_t>(1e-6);

            case HeatFluxUnit::MilliwattPerSquareMillimeter:
                return (value * static_cast<un_scalar_t>(1e-3)) / static_cast<un_scalar_t>(1e-6);

            case HeatFluxUnit::CentiwattPerSquareMillimeter:
                return (value * static_cast<un_scalar_t>(1e-2)) / static_cast<un_scalar_t>(1e-6);

            case HeatFluxUnit::DeciwattPerSquareMillimeter:
                return (value * static_cast<un_scalar_t>(1e-1)) / static_cast<un_scalar_t>(1e-6);

            case HeatFluxUnit::KilowattPerSquareMillimeter:
                return (value * static_cast<un_scalar_t>(1e3)) / static_cast<un_scalar_t>(1e-6);

            case HeatFluxUnit::WattPerSquareInch:
                return value / (static_cast<un_scalar_t>(2.54e-2) * static_cast<un_scalar_t>(2.54e-2));

            case HeatFluxUnit::WattPerSquareFoot:
                return value / (static_cast<un_scalar_t>(0.3048) * static_cast<un_scalar_t>(0.3048));

            case HeatFluxUnit::BtuPerSecondSquareInch:
                return value * static_cast<un_scalar_t>(1055.05585262) / (static_cast<un_scalar_t>(2.54e-2) * static_cast<un_scalar_t>(2.54e-2));

            case HeatFluxUnit::BtuPerSecondSquareFoot:
                return value * static_cast<un_scalar_t>(1055.05585262) / (static_cast<un_scalar_t>(0.3048) * static_cast<un_scalar_t>(0.3048));

            case HeatFluxUnit::BtuPerMinuteSquareFoot:
                return value * static_cast<un_scalar_t>(1055.05585262) / (static_cast<un_scalar_t>(0.3048) * static_cast<un_scalar_t>(0.3048) * static_cast<un_scalar_t>(60));

            case HeatFluxUnit::BtuPerHourSquareFoot:
                return value * static_cast<un_scalar_t>(1055.05585262) / (static_cast<un_scalar_t>(0.3048) * static_cast<un_scalar_t>(0.3048) * static_cast<un_scalar_t>(3600));

            case HeatFluxUnit::CaloriePerSecondSquareCentimeter:
                return value * static_cast<un_scalar_t>(4.184e4);

            case HeatFluxUnit::KilocaloriePerSecondSquareCentimeter:
                return (value * static_cast<un_scalar_t>(1e3)) * static_cast<un_scalar_t>(4.184e4);

            case HeatFluxUnit::KilocaloriePerHourSquareMeter:
                return value * static_cast<un_scalar_t>(4.184e3) / static_cast<un_scalar_t>(3600);

            case HeatFluxUnit::PoundForcePerFootSecond:
                return value * static_cast<un_scalar_t>(1.3558179483314004) / static_cast<un_scalar_t>(9.290304e-2);

            case HeatFluxUnit::PoundPerSecondCubed:
                return value * static_cast<un_scalar_t>(4.5359237e-1);

            }

            throw std::invalid_argument("Unknown HeatFlux unit.");
        }

        [[nodiscard]] constexpr un_scalar_t convert_from_base(const HeatFluxUnit unit) const
        {
            if(unit == value_unit_type_)
            {
                return value_;
            }
            
            auto base_value = convert_to_base(value_, value_unit_type_);
            
            switch (unit)
            {

            case HeatFluxUnit::WattPerSquareMeter:
                return base_value;

            case HeatFluxUnit::NanowattPerSquareMeter:
                return (base_value) / static_cast<un_scalar_t>(1e-9);

            case HeatFluxUnit::MicrowattPerSquareMeter:
                return (base_value) / static_cast<un_scalar_t>(1e-6);

            case HeatFluxUnit::MilliwattPerSquareMeter:
                return (base_value) / static_cast<un_scalar_t>(1e-3);

            case HeatFluxUnit::CentiwattPerSquareMeter:
                return (base_value) / static_cast<un_scalar_t>(1e-2);

            case HeatFluxUnit::DeciwattPerSquareMeter:
                return (base_value) / static_cast<un_scalar_t>(1e-1);

            case HeatFluxUnit::KilowattPerSquareMeter:
                return (base_value) / static_cast<un_scalar_t>(1e3);

            case HeatFluxUnit::WattPerSquareMillimeter:
                return base_value * static_cast<un_scalar_t>(1e-6);

            case HeatFluxUnit::NanowattPerSquareMillimeter:
                return (base_value * static_cast<un_scalar_t>(1e-6)) / static_cast<un_scalar_t>(1e-9);

            case HeatFluxUnit::MicrowattPerSquareMillimeter:
                return (base_value * static_cast<un_scalar_t>(1e-6)) / static_cast<un_scalar_t>(1e-6);

            case HeatFluxUnit::MilliwattPerSquareMillimeter:
                return (base_value * static_cast<un_scalar_t>(1e-6)) / static_cast<un_scalar_t>(1e-3);

            case HeatFluxUnit::CentiwattPerSquareMillimeter:
                return (base_value * static_cast<un_scalar_t>(1e-6)) / static_cast<un_scalar_t>(1e-2);

            case HeatFluxUnit::DeciwattPerSquareMillimeter:
                return (base_value * static_cast<un_scalar_t>(1e-6)) / static_cast<un_scalar_t>(1e-1);

            case HeatFluxUnit::KilowattPerSquareMillimeter:
                return (base_value * static_cast<un_scalar_t>(1e-6)) / static_cast<un_scalar_t>(1e3);

            case HeatFluxUnit::WattPerSquareInch:
                return base_value * (static_cast<un_scalar_t>(2.54e-2) * static_cast<un_scalar_t>(2.54e-2));

            case HeatFluxUnit::WattPerSquareFoot:
                return base_value * (static_cast<un_scalar_t>(0.3048) * static_cast<un_scalar_t>(0.3048));

            case HeatFluxUnit::BtuPerSecondSquareInch:
                return base_value * (static_cast<un_scalar_t>(2.54e-2) * static_cast<un_scalar_t>(2.54e-2)) / static_cast<un_scalar_t>(1055.05585262);

            case HeatFluxUnit::BtuPerSecondSquareFoot:
                return base_value * (static_cast<un_scalar_t>(0.3048) * static_cast<un_scalar_t>(0.3048)) / static_cast<un_scalar_t>(1055.05585262);

            case HeatFluxUnit::BtuPerMinuteSquareFoot:
                return base_value * (static_cast<un_scalar_t>(0.3048) * static_cast<un_scalar_t>(0.3048) * static_cast<un_scalar_t>(60)) / static_cast<un_scalar_t>(1055.05585262);

            case HeatFluxUnit::BtuPerHourSquareFoot:
                return base_value * (static_cast<un_scalar_t>(0.3048) * static_cast<un_scalar_t>(0.3048) * static_cast<un_scalar_t>(3600)) / static_cast<un_scalar_t>(1055.05585262);

            case HeatFluxUnit::CaloriePerSecondSquareCentimeter:
                return base_value / static_cast<un_scalar_t>(4.184e4);

            case HeatFluxUnit::KilocaloriePerSecondSquareCentimeter:
                return (base_value / static_cast<un_scalar_t>(4.184e4)) / static_cast<un_scalar_t>(1e3);

            case HeatFluxUnit::KilocaloriePerHourSquareMeter:
                return base_value * static_cast<un_scalar_t>(3600) / static_cast<un_scalar_t>(4.184e3);

            case HeatFluxUnit::PoundForcePerFootSecond:
                return base_value * static_cast<un_scalar_t>(9.290304e-2) / static_cast<un_scalar_t>(1.3558179483314004);

            case HeatFluxUnit::PoundPerSecondCubed:
                return base_value / static_cast<un_scalar_t>(4.5359237e-1);

            }

            throw std::invalid_argument("Unknown HeatFlux unit.");
        }

        un_scalar_t value_;
        HeatFluxUnit value_unit_type_;       
    };
}
