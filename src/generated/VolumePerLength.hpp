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
    enum class VolumePerLengthUnit : std::uint8_t
    {
        CubicMeterPerMeter,
        LiterPerMeter,
        LiterPerKilometer,
        LiterPerMillimeter,
        OilBarrelPerFoot,
        CubicYardPerFoot,
        CubicYardPerUsSurveyFoot,
        UsGallonPerMile,
        ImperialGallonPerMile,
    };

#if defined(UNITSNET_ENABLE_DTO) || defined(UNITSNET_ENABLE_NLOHMANN_JSON)
    /// <summary>A data-transfer representation of VolumePerLength.</summary>
    class VolumePerLengthDto
    {
    public:
        constexpr VolumePerLengthDto() noexcept
            : value{}, unit(VolumePerLengthUnit::CubicMeterPerMeter)
        {
        }

        constexpr VolumePerLengthDto(
            const un_scalar_t value,
            const VolumePerLengthUnit unit) noexcept
            : value(value), unit(unit)
        {
        }

        /// <summary>The numeric value of the quantity.</summary>
        un_scalar_t value;

        /// <summary>The unit in which value is expressed.</summary>
        VolumePerLengthUnit unit;

        /// <summary>The stable UnitsNet name used for cross-language serialization.</summary>
        [[nodiscard]] constexpr std::string_view unit_name() const noexcept
        {
            return magic_enum::enum_name(unit);
        }

        /// <summary>Converts a stable UnitsNet unit name to its strongly typed enum.</summary>
        [[nodiscard]] static constexpr VolumePerLengthUnit unit_from_name(const std::string_view name)
        {
            const auto unit = magic_enum::enum_cast<VolumePerLengthUnit>(name);
            if (unit.has_value())
            {
                return *unit;
            }

            throw std::invalid_argument("Unknown VolumePerLength unit name.");
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
        [[nodiscard]] static VolumePerLengthDto from_json(const nlohmann::json& json)
        {
            return VolumePerLengthDto(
                json.at("value").get<un_scalar_t>(),
                unit_from_name(json.at("unit").get<std::string>()));
        }
#endif
    };
#endif

    /// <summary>Volume, typically of fluid, that a container can hold within a unit of length.</summary>
    class VolumePerLength : public UnitsNetBase
    {
    public:
        constexpr explicit VolumePerLength(
            const un_scalar_t value,
            const VolumePerLengthUnit unit = VolumePerLengthUnit::CubicMeterPerMeter)
        {
            value_ = value;
            value_unit_type_ = unit;
        }
                
        [[nodiscard]] constexpr un_scalar_t base_value() const noexcept
        {
            return convert_to_base(value_, value_unit_type_);    
        }

        [[nodiscard]] constexpr un_scalar_t value(const VolumePerLengthUnit unit) const
        {
            return convert_from_base(unit);
        }

#if defined(UNITSNET_ENABLE_DTO) || defined(UNITSNET_ENABLE_NLOHMANN_JSON)
        /// <summary>Creates a DTO, expressed in the requested unit.</summary>
        [[nodiscard]] constexpr VolumePerLengthDto to_dto(
            const VolumePerLengthUnit unit = VolumePerLengthUnit::CubicMeterPerMeter) const
        {
            return VolumePerLengthDto(value(unit), unit);
        }

        /// <summary>Creates a quantity from its DTO representation.</summary>
        [[nodiscard]] static constexpr VolumePerLength from_dto(const VolumePerLengthDto& dto)
        {
            return VolumePerLength(dto.value, dto.unit);
        }

#ifdef UNITSNET_ENABLE_NLOHMANN_JSON
        /// <summary>Serializes this quantity to a nlohmann JSON object.</summary>
        [[nodiscard]] nlohmann::json to_json(
            const VolumePerLengthUnit unit = VolumePerLengthUnit::CubicMeterPerMeter) const
        {
            return to_dto(unit).to_json();
        }

        /// <summary>Creates a quantity from a nlohmann JSON object.</summary>
        [[nodiscard]] static VolumePerLength from_json(const nlohmann::json& json)
        {
            return from_dto(VolumePerLengthDto::from_json(json));
        }
#endif
#endif

        [[nodiscard]] constexpr VolumePerLength operator+(const VolumePerLength& other) const noexcept
        {
            return VolumePerLength(base_value() + other.base_value());
        }

        [[nodiscard]] constexpr VolumePerLength operator-(const VolumePerLength& other)const noexcept
        {
            return VolumePerLength(base_value() - other.base_value());
        }

        [[nodiscard]] constexpr VolumePerLength operator*(const un_scalar_t scalar) const noexcept
        {
            return VolumePerLength(base_value() * scalar);
        }

        [[nodiscard]] constexpr VolumePerLength operator/(const un_scalar_t scalar) const noexcept
        {
            return VolumePerLength(base_value() / scalar);
        }

        [[nodiscard]] constexpr bool operator==(const VolumePerLength& other) const noexcept
        {
            return base_value() == other.base_value();
        }

        [[nodiscard]] constexpr bool operator<(const VolumePerLength& other) const noexcept
        {
            return base_value() < other.base_value();
        }
        
        [[nodiscard]] constexpr bool operator>(const VolumePerLength& other) const noexcept
        {
            return base_value() > other.base_value();
        }

        [[nodiscard]] constexpr un_scalar_t cubic_meters_per_meter() const
        {
            return convert_from_base(VolumePerLengthUnit::CubicMeterPerMeter);
        }

        [[nodiscard]] static constexpr VolumePerLength from_cubic_meters_per_meter(const un_scalar_t value)
        {
            return VolumePerLength(value, VolumePerLengthUnit::CubicMeterPerMeter);
        }

        [[nodiscard]] constexpr un_scalar_t liters_per_meter() const
        {
            return convert_from_base(VolumePerLengthUnit::LiterPerMeter);
        }

        [[nodiscard]] static constexpr VolumePerLength from_liters_per_meter(const un_scalar_t value)
        {
            return VolumePerLength(value, VolumePerLengthUnit::LiterPerMeter);
        }

        [[nodiscard]] constexpr un_scalar_t liters_per_kilometer() const
        {
            return convert_from_base(VolumePerLengthUnit::LiterPerKilometer);
        }

        [[nodiscard]] static constexpr VolumePerLength from_liters_per_kilometer(const un_scalar_t value)
        {
            return VolumePerLength(value, VolumePerLengthUnit::LiterPerKilometer);
        }

        [[nodiscard]] constexpr un_scalar_t liters_per_millimeter() const
        {
            return convert_from_base(VolumePerLengthUnit::LiterPerMillimeter);
        }

        [[nodiscard]] static constexpr VolumePerLength from_liters_per_millimeter(const un_scalar_t value)
        {
            return VolumePerLength(value, VolumePerLengthUnit::LiterPerMillimeter);
        }

        [[nodiscard]] constexpr un_scalar_t oil_barrels_per_foot() const
        {
            return convert_from_base(VolumePerLengthUnit::OilBarrelPerFoot);
        }

        [[nodiscard]] static constexpr VolumePerLength from_oil_barrels_per_foot(const un_scalar_t value)
        {
            return VolumePerLength(value, VolumePerLengthUnit::OilBarrelPerFoot);
        }

        [[nodiscard]] constexpr un_scalar_t cubic_yards_per_foot() const
        {
            return convert_from_base(VolumePerLengthUnit::CubicYardPerFoot);
        }

        [[nodiscard]] static constexpr VolumePerLength from_cubic_yards_per_foot(const un_scalar_t value)
        {
            return VolumePerLength(value, VolumePerLengthUnit::CubicYardPerFoot);
        }

        [[nodiscard]] constexpr un_scalar_t cubic_yards_per_us_survey_foot() const
        {
            return convert_from_base(VolumePerLengthUnit::CubicYardPerUsSurveyFoot);
        }

        [[nodiscard]] static constexpr VolumePerLength from_cubic_yards_per_us_survey_foot(const un_scalar_t value)
        {
            return VolumePerLength(value, VolumePerLengthUnit::CubicYardPerUsSurveyFoot);
        }

        [[nodiscard]] constexpr un_scalar_t us_gallons_per_mile() const
        {
            return convert_from_base(VolumePerLengthUnit::UsGallonPerMile);
        }

        [[nodiscard]] static constexpr VolumePerLength from_us_gallons_per_mile(const un_scalar_t value)
        {
            return VolumePerLength(value, VolumePerLengthUnit::UsGallonPerMile);
        }

        [[nodiscard]] constexpr un_scalar_t imperial_gallons_per_mile() const
        {
            return convert_from_base(VolumePerLengthUnit::ImperialGallonPerMile);
        }

        [[nodiscard]] static constexpr VolumePerLength from_imperial_gallons_per_mile(const un_scalar_t value)
        {
            return VolumePerLength(value, VolumePerLengthUnit::ImperialGallonPerMile);
        }

        [[nodiscard]] static constexpr VolumePerLength from_invalid()
        {
            return VolumePerLength(false);
        }
    private:
            
        [[nodiscard]] static constexpr un_scalar_t convert_to_base(un_scalar_t value, VolumePerLengthUnit unit)
        {
            switch (unit)
            {

            case VolumePerLengthUnit::CubicMeterPerMeter:
                return value;

            case VolumePerLengthUnit::LiterPerMeter:
                return value / static_cast<un_scalar_t>(1000);

            case VolumePerLengthUnit::LiterPerKilometer:
                return value / static_cast<un_scalar_t>(1e6);

            case VolumePerLengthUnit::LiterPerMillimeter:
                return value;

            case VolumePerLengthUnit::OilBarrelPerFoot:
                return value * static_cast<un_scalar_t>(0.158987294928) / static_cast<un_scalar_t>(0.3048);

            case VolumePerLengthUnit::CubicYardPerFoot:
                return value * static_cast<un_scalar_t>(0.764554857984) / static_cast<un_scalar_t>(0.3048);

            case VolumePerLengthUnit::CubicYardPerUsSurveyFoot:
                return value * static_cast<un_scalar_t>(0.764554857984) * static_cast<un_scalar_t>(3937) / static_cast<un_scalar_t>(1200);

            case VolumePerLengthUnit::UsGallonPerMile:
                return value * static_cast<un_scalar_t>(0.003785411784) / static_cast<un_scalar_t>(1609.344);

            case VolumePerLengthUnit::ImperialGallonPerMile:
                return value * static_cast<un_scalar_t>(0.00454609) / static_cast<un_scalar_t>(1609.344);

            }

            throw std::invalid_argument("Unknown VolumePerLength unit.");
        }

        [[nodiscard]] constexpr un_scalar_t convert_from_base(const VolumePerLengthUnit unit) const
        {
            if(unit == value_unit_type_)
            {
                return value_;
            }
            
            auto base_value = convert_to_base(value_, value_unit_type_);
            
            switch (unit)
            {

            case VolumePerLengthUnit::CubicMeterPerMeter:
                return base_value;

            case VolumePerLengthUnit::LiterPerMeter:
                return base_value * static_cast<un_scalar_t>(1000);

            case VolumePerLengthUnit::LiterPerKilometer:
                return base_value * static_cast<un_scalar_t>(1e6);

            case VolumePerLengthUnit::LiterPerMillimeter:
                return base_value;

            case VolumePerLengthUnit::OilBarrelPerFoot:
                return base_value * static_cast<un_scalar_t>(0.3048) / static_cast<un_scalar_t>(0.158987294928);

            case VolumePerLengthUnit::CubicYardPerFoot:
                return base_value * static_cast<un_scalar_t>(0.3048) / static_cast<un_scalar_t>(0.764554857984);

            case VolumePerLengthUnit::CubicYardPerUsSurveyFoot:
                return base_value * static_cast<un_scalar_t>(1200) / (static_cast<un_scalar_t>(0.764554857984) * static_cast<un_scalar_t>(3937));

            case VolumePerLengthUnit::UsGallonPerMile:
                return base_value * static_cast<un_scalar_t>(1609.344) / static_cast<un_scalar_t>(0.003785411784);

            case VolumePerLengthUnit::ImperialGallonPerMile:
                return base_value * static_cast<un_scalar_t>(1609.344) / static_cast<un_scalar_t>(0.00454609);

            }

            throw std::invalid_argument("Unknown VolumePerLength unit.");
        }

        un_scalar_t value_;
        VolumePerLengthUnit value_unit_type_;       
    };
}
