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
    enum class FuelEfficiencyUnit : std::uint8_t
    {
        LiterPer100Kilometers,
        MilePerUsGallon,
        MilePerUkGallon,
        KilometerPerLiter,
    };

#if defined(UNITSNET_ENABLE_DTO) || defined(UNITSNET_ENABLE_NLOHMANN_JSON)
    /// <summary>A data-transfer representation of FuelEfficiency.</summary>
    class FuelEfficiencyDto
    {
    public:
        constexpr FuelEfficiencyDto() noexcept
            : value{}, unit(FuelEfficiencyUnit::KilometerPerLiter)
        {
        }

        constexpr FuelEfficiencyDto(
            const un_scalar_t value,
            const FuelEfficiencyUnit unit) noexcept
            : value(value), unit(unit)
        {
        }

        /// <summary>The numeric value of the quantity.</summary>
        un_scalar_t value;

        /// <summary>The unit in which value is expressed.</summary>
        FuelEfficiencyUnit unit;

        /// <summary>The stable UnitsNet name used for cross-language serialization.</summary>
        [[nodiscard]] constexpr std::string_view unit_name() const noexcept
        {
            return magic_enum::enum_name(unit);
        }

        /// <summary>Converts a stable UnitsNet unit name to its strongly typed enum.</summary>
        [[nodiscard]] static constexpr FuelEfficiencyUnit unit_from_name(const std::string_view name)
        {
            const auto unit = magic_enum::enum_cast<FuelEfficiencyUnit>(name);
            if (unit.has_value())
            {
                return *unit;
            }

            throw std::invalid_argument("Unknown FuelEfficiency unit name.");
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
        [[nodiscard]] static FuelEfficiencyDto from_json(const nlohmann::json& json)
        {
            return FuelEfficiencyDto(
                json.at("value").get<un_scalar_t>(),
                unit_from_name(json.at("unit").get<std::string>()));
        }
#endif
    };
#endif

    /// <summary>In the context of transport, fuel economy is the energy efficiency of a particular vehicle, given as a ratio of distance traveled per unit of fuel consumed. In most countries, using the metric system, fuel economy is stated as "fuel consumption" in liters per 100 kilometers (L/100 km) or kilometers per liter (km/L or kmpl). In countries using non-metric system, fuel economy is expressed in miles per gallon (mpg) (imperial galon or US galon).</summary>
    class FuelEfficiency : public UnitsNetBase
    {
    public:
        constexpr explicit FuelEfficiency(
            const un_scalar_t value,
            const FuelEfficiencyUnit unit = FuelEfficiencyUnit::KilometerPerLiter)
        {
            value_ = value;
            value_unit_type_ = unit;
        }
                
        [[nodiscard]] constexpr un_scalar_t base_value() const noexcept
        {
            return convert_to_base(value_, value_unit_type_);    
        }

        [[nodiscard]] constexpr un_scalar_t value(const FuelEfficiencyUnit unit) const
        {
            return convert_from_base(unit);
        }

#if defined(UNITSNET_ENABLE_DTO) || defined(UNITSNET_ENABLE_NLOHMANN_JSON)
        /// <summary>Creates a DTO, expressed in the requested unit.</summary>
        [[nodiscard]] constexpr FuelEfficiencyDto to_dto(
            const FuelEfficiencyUnit unit = FuelEfficiencyUnit::KilometerPerLiter) const
        {
            return FuelEfficiencyDto(value(unit), unit);
        }

        /// <summary>Creates a quantity from its DTO representation.</summary>
        [[nodiscard]] static constexpr FuelEfficiency from_dto(const FuelEfficiencyDto& dto)
        {
            return FuelEfficiency(dto.value, dto.unit);
        }

#ifdef UNITSNET_ENABLE_NLOHMANN_JSON
        /// <summary>Serializes this quantity to a nlohmann JSON object.</summary>
        [[nodiscard]] nlohmann::json to_json(
            const FuelEfficiencyUnit unit = FuelEfficiencyUnit::KilometerPerLiter) const
        {
            return to_dto(unit).to_json();
        }

        /// <summary>Creates a quantity from a nlohmann JSON object.</summary>
        [[nodiscard]] static FuelEfficiency from_json(const nlohmann::json& json)
        {
            return from_dto(FuelEfficiencyDto::from_json(json));
        }
#endif
#endif

        [[nodiscard]] constexpr FuelEfficiency operator+(const FuelEfficiency& other) const noexcept
        {
            return FuelEfficiency(base_value() + other.base_value());
        }

        [[nodiscard]] constexpr FuelEfficiency operator-(const FuelEfficiency& other)const noexcept
        {
            return FuelEfficiency(base_value() - other.base_value());
        }

        [[nodiscard]] constexpr FuelEfficiency operator*(const un_scalar_t scalar) const noexcept
        {
            return FuelEfficiency(base_value() * scalar);
        }

        [[nodiscard]] constexpr FuelEfficiency operator/(const un_scalar_t scalar) const noexcept
        {
            return FuelEfficiency(base_value() / scalar);
        }

        [[nodiscard]] constexpr bool operator==(const FuelEfficiency& other) const noexcept
        {
            return base_value() == other.base_value();
        }

        [[nodiscard]] constexpr bool operator<(const FuelEfficiency& other) const noexcept
        {
            return base_value() < other.base_value();
        }
        
        [[nodiscard]] constexpr bool operator>(const FuelEfficiency& other) const noexcept
        {
            return base_value() > other.base_value();
        }

        [[nodiscard]] constexpr un_scalar_t liters_per100_kilometers() const
        {
            return convert_from_base(FuelEfficiencyUnit::LiterPer100Kilometers);
        }

        [[nodiscard]] static constexpr FuelEfficiency from_liters_per100_kilometers(const un_scalar_t value)
        {
            return FuelEfficiency(value, FuelEfficiencyUnit::LiterPer100Kilometers);
        }

        [[nodiscard]] constexpr un_scalar_t miles_per_us_gallon() const
        {
            return convert_from_base(FuelEfficiencyUnit::MilePerUsGallon);
        }

        [[nodiscard]] static constexpr FuelEfficiency from_miles_per_us_gallon(const un_scalar_t value)
        {
            return FuelEfficiency(value, FuelEfficiencyUnit::MilePerUsGallon);
        }

        [[nodiscard]] constexpr un_scalar_t miles_per_uk_gallon() const
        {
            return convert_from_base(FuelEfficiencyUnit::MilePerUkGallon);
        }

        [[nodiscard]] static constexpr FuelEfficiency from_miles_per_uk_gallon(const un_scalar_t value)
        {
            return FuelEfficiency(value, FuelEfficiencyUnit::MilePerUkGallon);
        }

        [[nodiscard]] constexpr un_scalar_t kilometers_per_liter() const
        {
            return convert_from_base(FuelEfficiencyUnit::KilometerPerLiter);
        }

        [[nodiscard]] static constexpr FuelEfficiency from_kilometers_per_liter(const un_scalar_t value)
        {
            return FuelEfficiency(value, FuelEfficiencyUnit::KilometerPerLiter);
        }

        [[nodiscard]] static constexpr FuelEfficiency from_invalid()
        {
            return FuelEfficiency(false);
        }
    private:
            
        [[nodiscard]] static constexpr un_scalar_t convert_to_base(un_scalar_t value, FuelEfficiencyUnit unit)
        {
            switch (unit)
            {

            case FuelEfficiencyUnit::LiterPer100Kilometers:
                return static_cast<un_scalar_t>(100) / value;

            case FuelEfficiencyUnit::MilePerUsGallon:
                return value * static_cast<un_scalar_t>(1.609344) / static_cast<un_scalar_t>(3.785411784);

            case FuelEfficiencyUnit::MilePerUkGallon:
                return value * static_cast<un_scalar_t>(1.609344) / static_cast<un_scalar_t>(4.54609);

            case FuelEfficiencyUnit::KilometerPerLiter:
                return value;

            }

            throw std::invalid_argument("Unknown FuelEfficiency unit.");
        }

        [[nodiscard]] constexpr un_scalar_t convert_from_base(const FuelEfficiencyUnit unit) const
        {
            if(unit == value_unit_type_)
            {
                return value_;
            }
            
            auto base_value = convert_to_base(value_, value_unit_type_);
            
            switch (unit)
            {

            case FuelEfficiencyUnit::LiterPer100Kilometers:
                return static_cast<un_scalar_t>(100) / base_value;

            case FuelEfficiencyUnit::MilePerUsGallon:
                return base_value * static_cast<un_scalar_t>(3.785411784) / static_cast<un_scalar_t>(1.609344);

            case FuelEfficiencyUnit::MilePerUkGallon:
                return base_value * static_cast<un_scalar_t>(4.54609) / static_cast<un_scalar_t>(1.609344);

            case FuelEfficiencyUnit::KilometerPerLiter:
                return base_value;

            }

            throw std::invalid_argument("Unknown FuelEfficiency unit.");
        }

        un_scalar_t value_;
        FuelEfficiencyUnit value_unit_type_;       
    };
}
