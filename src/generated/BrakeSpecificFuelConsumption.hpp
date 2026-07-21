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
    enum class BrakeSpecificFuelConsumptionUnit : std::uint8_t
    {
        GramPerKiloWattHour,
        KilogramPerJoule,
        PoundPerMechanicalHorsepowerHour,
    };

#if defined(UNITSNET_ENABLE_DTO) || defined(UNITSNET_ENABLE_NLOHMANN_JSON)
    /// <summary>A data-transfer representation of BrakeSpecificFuelConsumption.</summary>
    class BrakeSpecificFuelConsumptionDto
    {
    public:
        constexpr BrakeSpecificFuelConsumptionDto() noexcept
            : value{}, unit(BrakeSpecificFuelConsumptionUnit::KilogramPerJoule)
        {
        }

        constexpr BrakeSpecificFuelConsumptionDto(
            const un_scalar_t value,
            const BrakeSpecificFuelConsumptionUnit unit) noexcept
            : value(value), unit(unit)
        {
        }

        /// <summary>The numeric value of the quantity.</summary>
        un_scalar_t value;

        /// <summary>The unit in which value is expressed.</summary>
        BrakeSpecificFuelConsumptionUnit unit;

        /// <summary>The stable UnitsNet name used for cross-language serialization.</summary>
        [[nodiscard]] constexpr std::string_view unit_name() const noexcept
        {
            return magic_enum::enum_name(unit);
        }

        /// <summary>Converts a stable UnitsNet unit name to its strongly typed enum.</summary>
        [[nodiscard]] static constexpr BrakeSpecificFuelConsumptionUnit unit_from_name(const std::string_view name)
        {
            const auto unit = magic_enum::enum_cast<BrakeSpecificFuelConsumptionUnit>(name);
            if (unit.has_value())
            {
                return *unit;
            }

            throw std::invalid_argument("Unknown BrakeSpecificFuelConsumption unit name.");
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
        [[nodiscard]] static BrakeSpecificFuelConsumptionDto from_json(const nlohmann::json& json)
        {
            return BrakeSpecificFuelConsumptionDto(
                json.at("value").get<un_scalar_t>(),
                unit_from_name(json.at("unit").get<std::string>()));
        }
#endif
    };
#endif

    /// <summary>Brake specific fuel consumption (BSFC) is a measure of the fuel efficiency of any prime mover that burns fuel and produces rotational, or shaft, power. It is typically used for comparing the efficiency of internal combustion engines with a shaft output.</summary>
    class BrakeSpecificFuelConsumption : public UnitsNetBase
    {
    public:
        constexpr explicit BrakeSpecificFuelConsumption(
            const un_scalar_t value,
            const BrakeSpecificFuelConsumptionUnit unit = BrakeSpecificFuelConsumptionUnit::KilogramPerJoule)
        {
            value_ = value;
            value_unit_type_ = unit;
        }
                
        [[nodiscard]] constexpr un_scalar_t base_value() const noexcept
        {
            return convert_to_base(value_, value_unit_type_);    
        }

        [[nodiscard]] constexpr un_scalar_t value(const BrakeSpecificFuelConsumptionUnit unit) const
        {
            return convert_from_base(unit);
        }

#if defined(UNITSNET_ENABLE_DTO) || defined(UNITSNET_ENABLE_NLOHMANN_JSON)
        /// <summary>Creates a DTO, expressed in the requested unit.</summary>
        [[nodiscard]] constexpr BrakeSpecificFuelConsumptionDto to_dto(
            const BrakeSpecificFuelConsumptionUnit unit = BrakeSpecificFuelConsumptionUnit::KilogramPerJoule) const
        {
            return BrakeSpecificFuelConsumptionDto(value(unit), unit);
        }

        /// <summary>Creates a quantity from its DTO representation.</summary>
        [[nodiscard]] static constexpr BrakeSpecificFuelConsumption from_dto(const BrakeSpecificFuelConsumptionDto& dto)
        {
            return BrakeSpecificFuelConsumption(dto.value, dto.unit);
        }

#ifdef UNITSNET_ENABLE_NLOHMANN_JSON
        /// <summary>Serializes this quantity to a nlohmann JSON object.</summary>
        [[nodiscard]] nlohmann::json to_json(
            const BrakeSpecificFuelConsumptionUnit unit = BrakeSpecificFuelConsumptionUnit::KilogramPerJoule) const
        {
            return to_dto(unit).to_json();
        }

        /// <summary>Creates a quantity from a nlohmann JSON object.</summary>
        [[nodiscard]] static BrakeSpecificFuelConsumption from_json(const nlohmann::json& json)
        {
            return from_dto(BrakeSpecificFuelConsumptionDto::from_json(json));
        }
#endif
#endif

        [[nodiscard]] constexpr BrakeSpecificFuelConsumption operator+(const BrakeSpecificFuelConsumption& other) const noexcept
        {
            return BrakeSpecificFuelConsumption(base_value() + other.base_value());
        }

        [[nodiscard]] constexpr BrakeSpecificFuelConsumption operator-(const BrakeSpecificFuelConsumption& other)const noexcept
        {
            return BrakeSpecificFuelConsumption(base_value() - other.base_value());
        }

        [[nodiscard]] constexpr BrakeSpecificFuelConsumption operator*(const un_scalar_t scalar) const noexcept
        {
            return BrakeSpecificFuelConsumption(base_value() * scalar);
        }

        [[nodiscard]] constexpr BrakeSpecificFuelConsumption operator/(const un_scalar_t scalar) const noexcept
        {
            return BrakeSpecificFuelConsumption(base_value() / scalar);
        }

        [[nodiscard]] constexpr bool operator==(const BrakeSpecificFuelConsumption& other) const noexcept
        {
            return base_value() == other.base_value();
        }

        [[nodiscard]] constexpr bool operator<(const BrakeSpecificFuelConsumption& other) const noexcept
        {
            return base_value() < other.base_value();
        }
        
        [[nodiscard]] constexpr bool operator>(const BrakeSpecificFuelConsumption& other) const noexcept
        {
            return base_value() > other.base_value();
        }

        [[nodiscard]] constexpr un_scalar_t grams_per_kilo_watt_hour() const
        {
            return convert_from_base(BrakeSpecificFuelConsumptionUnit::GramPerKiloWattHour);
        }

        [[nodiscard]] static constexpr BrakeSpecificFuelConsumption from_grams_per_kilo_watt_hour(const un_scalar_t value)
        {
            return BrakeSpecificFuelConsumption(value, BrakeSpecificFuelConsumptionUnit::GramPerKiloWattHour);
        }

        [[nodiscard]] constexpr un_scalar_t kilograms_per_joule() const
        {
            return convert_from_base(BrakeSpecificFuelConsumptionUnit::KilogramPerJoule);
        }

        [[nodiscard]] static constexpr BrakeSpecificFuelConsumption from_kilograms_per_joule(const un_scalar_t value)
        {
            return BrakeSpecificFuelConsumption(value, BrakeSpecificFuelConsumptionUnit::KilogramPerJoule);
        }

        /// <summary>The pound per horse power hour uses mechanical horse power and the imperial pound</summary>
        [[nodiscard]] constexpr un_scalar_t pounds_per_mechanical_horsepower_hour() const
        {
            return convert_from_base(BrakeSpecificFuelConsumptionUnit::PoundPerMechanicalHorsepowerHour);
        }

        /// <summary>The pound per horse power hour uses mechanical horse power and the imperial pound</summary>
        [[nodiscard]] static constexpr BrakeSpecificFuelConsumption from_pounds_per_mechanical_horsepower_hour(const un_scalar_t value)
        {
            return BrakeSpecificFuelConsumption(value, BrakeSpecificFuelConsumptionUnit::PoundPerMechanicalHorsepowerHour);
        }

        [[nodiscard]] static constexpr BrakeSpecificFuelConsumption from_invalid()
        {
            return BrakeSpecificFuelConsumption(false);
        }
    private:
            
        [[nodiscard]] static constexpr un_scalar_t convert_to_base(un_scalar_t value, BrakeSpecificFuelConsumptionUnit unit)
        {
            switch (unit)
            {

            case BrakeSpecificFuelConsumptionUnit::GramPerKiloWattHour:
                return value / static_cast<un_scalar_t>(3.6e9);

            case BrakeSpecificFuelConsumptionUnit::KilogramPerJoule:
                return value;

            case BrakeSpecificFuelConsumptionUnit::PoundPerMechanicalHorsepowerHour:
                return value * (static_cast<un_scalar_t>(0.45359237) / (static_cast<un_scalar_t>(76.0402249) * static_cast<un_scalar_t>(9.80665)))/static_cast<un_scalar_t>(3600);

            }

            throw std::invalid_argument("Unknown BrakeSpecificFuelConsumption unit.");
        }

        [[nodiscard]] constexpr un_scalar_t convert_from_base(const BrakeSpecificFuelConsumptionUnit unit) const
        {
            if(unit == value_unit_type_)
            {
                return value_;
            }
            
            auto base_value = convert_to_base(value_, value_unit_type_);
            
            switch (unit)
            {

            case BrakeSpecificFuelConsumptionUnit::GramPerKiloWattHour:
                return base_value * static_cast<un_scalar_t>(3.6e9);

            case BrakeSpecificFuelConsumptionUnit::KilogramPerJoule:
                return base_value;

            case BrakeSpecificFuelConsumptionUnit::PoundPerMechanicalHorsepowerHour:
                return base_value * static_cast<un_scalar_t>(3600) / (static_cast<un_scalar_t>(0.45359237) / (static_cast<un_scalar_t>(76.0402249) * static_cast<un_scalar_t>(9.80665)));

            }

            throw std::invalid_argument("Unknown BrakeSpecificFuelConsumption unit.");
        }

        un_scalar_t value_;
        BrakeSpecificFuelConsumptionUnit value_unit_type_;       
    };
}
