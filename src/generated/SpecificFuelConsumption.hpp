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
    enum class SpecificFuelConsumptionUnit : std::uint8_t
    {
        PoundMassPerPoundForceHour,
        KilogramPerKilogramForceHour,
        GramPerKilonewtonSecond,
        KilogramPerKilonewtonSecond,
    };

#if defined(UNITSNET_ENABLE_DTO) || defined(UNITSNET_ENABLE_NLOHMANN_JSON)
    /// <summary>A data-transfer representation of SpecificFuelConsumption.</summary>
    class SpecificFuelConsumptionDto
    {
    public:
        constexpr SpecificFuelConsumptionDto() noexcept
            : value{}, unit(SpecificFuelConsumptionUnit::GramPerKilonewtonSecond)
        {
        }

        constexpr SpecificFuelConsumptionDto(
            const un_scalar_t value,
            const SpecificFuelConsumptionUnit unit) noexcept
            : value(value), unit(unit)
        {
        }

        /// <summary>The numeric value of the quantity.</summary>
        un_scalar_t value;

        /// <summary>The unit in which value is expressed.</summary>
        SpecificFuelConsumptionUnit unit;

        /// <summary>The stable UnitsNet name used for cross-language serialization.</summary>
        [[nodiscard]] constexpr std::string_view unit_name() const noexcept
        {
            return magic_enum::enum_name(unit);
        }

        /// <summary>Converts a stable UnitsNet unit name to its strongly typed enum.</summary>
        [[nodiscard]] static constexpr SpecificFuelConsumptionUnit unit_from_name(const std::string_view name)
        {
            const auto unit = magic_enum::enum_cast<SpecificFuelConsumptionUnit>(name);
            if (unit.has_value())
            {
                return *unit;
            }

            throw std::invalid_argument("Unknown SpecificFuelConsumption unit name.");
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
        [[nodiscard]] static SpecificFuelConsumptionDto from_json(const nlohmann::json& json)
        {
            return SpecificFuelConsumptionDto(
                json.at("value").get<un_scalar_t>(),
                unit_from_name(json.at("unit").get<std::string>()));
        }
#endif
    };
#endif

    /// <summary>SFC is the fuel efficiency of an engine design with respect to thrust output</summary>
    class SpecificFuelConsumption : public UnitsNetBase
    {
    public:
        constexpr explicit SpecificFuelConsumption(
            const un_scalar_t value,
            const SpecificFuelConsumptionUnit unit = SpecificFuelConsumptionUnit::GramPerKilonewtonSecond)
        {
            value_ = value;
            value_unit_type_ = unit;
        }
                
        [[nodiscard]] constexpr un_scalar_t base_value() const noexcept
        {
            return convert_to_base(value_, value_unit_type_);    
        }

        [[nodiscard]] constexpr un_scalar_t value(const SpecificFuelConsumptionUnit unit) const
        {
            return convert_from_base(unit);
        }

#if defined(UNITSNET_ENABLE_DTO) || defined(UNITSNET_ENABLE_NLOHMANN_JSON)
        /// <summary>Creates a DTO, expressed in the requested unit.</summary>
        [[nodiscard]] constexpr SpecificFuelConsumptionDto to_dto(
            const SpecificFuelConsumptionUnit unit = SpecificFuelConsumptionUnit::GramPerKilonewtonSecond) const
        {
            return SpecificFuelConsumptionDto(value(unit), unit);
        }

        /// <summary>Creates a quantity from its DTO representation.</summary>
        [[nodiscard]] static constexpr SpecificFuelConsumption from_dto(const SpecificFuelConsumptionDto& dto)
        {
            return SpecificFuelConsumption(dto.value, dto.unit);
        }

#ifdef UNITSNET_ENABLE_NLOHMANN_JSON
        /// <summary>Serializes this quantity to a nlohmann JSON object.</summary>
        [[nodiscard]] nlohmann::json to_json(
            const SpecificFuelConsumptionUnit unit = SpecificFuelConsumptionUnit::GramPerKilonewtonSecond) const
        {
            return to_dto(unit).to_json();
        }

        /// <summary>Creates a quantity from a nlohmann JSON object.</summary>
        [[nodiscard]] static SpecificFuelConsumption from_json(const nlohmann::json& json)
        {
            return from_dto(SpecificFuelConsumptionDto::from_json(json));
        }
#endif
#endif

        [[nodiscard]] constexpr SpecificFuelConsumption operator+(const SpecificFuelConsumption& other) const noexcept
        {
            return SpecificFuelConsumption(base_value() + other.base_value());
        }

        [[nodiscard]] constexpr SpecificFuelConsumption operator-(const SpecificFuelConsumption& other)const noexcept
        {
            return SpecificFuelConsumption(base_value() - other.base_value());
        }

        [[nodiscard]] constexpr SpecificFuelConsumption operator*(const un_scalar_t scalar) const noexcept
        {
            return SpecificFuelConsumption(base_value() * scalar);
        }

        [[nodiscard]] constexpr SpecificFuelConsumption operator/(const un_scalar_t scalar) const noexcept
        {
            return SpecificFuelConsumption(base_value() / scalar);
        }

        [[nodiscard]] constexpr bool operator==(const SpecificFuelConsumption& other) const noexcept
        {
            return base_value() == other.base_value();
        }

        [[nodiscard]] constexpr bool operator<(const SpecificFuelConsumption& other) const noexcept
        {
            return base_value() < other.base_value();
        }
        
        [[nodiscard]] constexpr bool operator>(const SpecificFuelConsumption& other) const noexcept
        {
            return base_value() > other.base_value();
        }

        [[nodiscard]] constexpr un_scalar_t pounds_mass_per_pound_force_hour() const
        {
            return convert_from_base(SpecificFuelConsumptionUnit::PoundMassPerPoundForceHour);
        }

        [[nodiscard]] static constexpr SpecificFuelConsumption from_pounds_mass_per_pound_force_hour(const un_scalar_t value)
        {
            return SpecificFuelConsumption(value, SpecificFuelConsumptionUnit::PoundMassPerPoundForceHour);
        }

        [[nodiscard]] constexpr un_scalar_t kilograms_per_kilogram_force_hour() const
        {
            return convert_from_base(SpecificFuelConsumptionUnit::KilogramPerKilogramForceHour);
        }

        [[nodiscard]] static constexpr SpecificFuelConsumption from_kilograms_per_kilogram_force_hour(const un_scalar_t value)
        {
            return SpecificFuelConsumption(value, SpecificFuelConsumptionUnit::KilogramPerKilogramForceHour);
        }

        [[nodiscard]] constexpr un_scalar_t grams_per_kilonewton_second() const
        {
            return convert_from_base(SpecificFuelConsumptionUnit::GramPerKilonewtonSecond);
        }

        [[nodiscard]] static constexpr SpecificFuelConsumption from_grams_per_kilonewton_second(const un_scalar_t value)
        {
            return SpecificFuelConsumption(value, SpecificFuelConsumptionUnit::GramPerKilonewtonSecond);
        }

        [[nodiscard]] constexpr un_scalar_t kilograms_per_kilonewton_second() const
        {
            return convert_from_base(SpecificFuelConsumptionUnit::KilogramPerKilonewtonSecond);
        }

        [[nodiscard]] static constexpr SpecificFuelConsumption from_kilograms_per_kilonewton_second(const un_scalar_t value)
        {
            return SpecificFuelConsumption(value, SpecificFuelConsumptionUnit::KilogramPerKilonewtonSecond);
        }

        [[nodiscard]] static constexpr SpecificFuelConsumption from_invalid()
        {
            return SpecificFuelConsumption(false);
        }
    private:
            
        [[nodiscard]] static constexpr un_scalar_t convert_to_base(un_scalar_t value, SpecificFuelConsumptionUnit unit)
        {
            switch (unit)
            {

            case SpecificFuelConsumptionUnit::PoundMassPerPoundForceHour:
                return value * static_cast<un_scalar_t>(1000) / (static_cast<un_scalar_t>(9.80665e-3) * static_cast<un_scalar_t>(3600));

            case SpecificFuelConsumptionUnit::KilogramPerKilogramForceHour:
                return value * static_cast<un_scalar_t>(1000) / (static_cast<un_scalar_t>(9.80665e-3) * static_cast<un_scalar_t>(3600));

            case SpecificFuelConsumptionUnit::GramPerKilonewtonSecond:
                return value;

            case SpecificFuelConsumptionUnit::KilogramPerKilonewtonSecond:
                return (value * static_cast<un_scalar_t>(1e3));

            }

            throw std::invalid_argument("Unknown SpecificFuelConsumption unit.");
        }

        [[nodiscard]] constexpr un_scalar_t convert_from_base(const SpecificFuelConsumptionUnit unit) const
        {
            if(unit == value_unit_type_)
            {
                return value_;
            }
            
            auto base_value = convert_to_base(value_, value_unit_type_);
            
            switch (unit)
            {

            case SpecificFuelConsumptionUnit::PoundMassPerPoundForceHour:
                return base_value * static_cast<un_scalar_t>(9.80665e-3) * static_cast<un_scalar_t>(3600) / static_cast<un_scalar_t>(1000);

            case SpecificFuelConsumptionUnit::KilogramPerKilogramForceHour:
                return base_value * static_cast<un_scalar_t>(9.80665e-3) * static_cast<un_scalar_t>(3600) / static_cast<un_scalar_t>(1000);

            case SpecificFuelConsumptionUnit::GramPerKilonewtonSecond:
                return base_value;

            case SpecificFuelConsumptionUnit::KilogramPerKilonewtonSecond:
                return (base_value) / static_cast<un_scalar_t>(1e3);

            }

            throw std::invalid_argument("Unknown SpecificFuelConsumption unit.");
        }

        un_scalar_t value_;
        SpecificFuelConsumptionUnit value_unit_type_;       
    };
}
