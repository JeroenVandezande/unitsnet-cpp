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
    enum class ElectricCapacitanceUnit : std::uint8_t
    {
        Farad,
        Picofarad,
        Nanofarad,
        Microfarad,
        Millifarad,
        Kilofarad,
        Megafarad,
    };

#if defined(UNITSNET_ENABLE_DTO) || defined(UNITSNET_ENABLE_NLOHMANN_JSON)
    /// <summary>A data-transfer representation of ElectricCapacitance.</summary>
    class ElectricCapacitanceDto
    {
    public:
        constexpr ElectricCapacitanceDto() noexcept
            : value{}, unit(ElectricCapacitanceUnit::Farad)
        {
        }

        constexpr ElectricCapacitanceDto(
            const un_scalar_t value,
            const ElectricCapacitanceUnit unit) noexcept
            : value(value), unit(unit)
        {
        }

        /// <summary>The numeric value of the quantity.</summary>
        un_scalar_t value;

        /// <summary>The unit in which value is expressed.</summary>
        ElectricCapacitanceUnit unit;

        /// <summary>The stable UnitsNet name used for cross-language serialization.</summary>
        [[nodiscard]] constexpr std::string_view unit_name() const noexcept
        {
            return magic_enum::enum_name(unit);
        }

        /// <summary>Converts a stable UnitsNet unit name to its strongly typed enum.</summary>
        [[nodiscard]] static constexpr ElectricCapacitanceUnit unit_from_name(const std::string_view name)
        {
            const auto unit = magic_enum::enum_cast<ElectricCapacitanceUnit>(name);
            if (unit.has_value())
            {
                return *unit;
            }

            throw std::invalid_argument("Unknown ElectricCapacitance unit name.");
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
        [[nodiscard]] static ElectricCapacitanceDto from_json(const nlohmann::json& json)
        {
            return ElectricCapacitanceDto(
                json.at("value").get<un_scalar_t>(),
                unit_from_name(json.at("unit").get<std::string>()));
        }
#endif
    };
#endif

    /// <summary>Capacitance is the capacity of a material object or device to store electric charge.</summary>
    class ElectricCapacitance : public UnitsNetBase
    {
    public:
        constexpr explicit ElectricCapacitance(
            const un_scalar_t value,
            const ElectricCapacitanceUnit unit = ElectricCapacitanceUnit::Farad)
        {
            value_ = value;
            value_unit_type_ = unit;
        }
                
        [[nodiscard]] constexpr un_scalar_t base_value() const noexcept
        {
            return convert_to_base(value_, value_unit_type_);    
        }

        [[nodiscard]] constexpr un_scalar_t value(const ElectricCapacitanceUnit unit) const
        {
            return convert_from_base(unit);
        }

#if defined(UNITSNET_ENABLE_DTO) || defined(UNITSNET_ENABLE_NLOHMANN_JSON)
        /// <summary>Creates a DTO, expressed in the requested unit.</summary>
        [[nodiscard]] constexpr ElectricCapacitanceDto to_dto(
            const ElectricCapacitanceUnit unit = ElectricCapacitanceUnit::Farad) const
        {
            return ElectricCapacitanceDto(value(unit), unit);
        }

        /// <summary>Creates a quantity from its DTO representation.</summary>
        [[nodiscard]] static constexpr ElectricCapacitance from_dto(const ElectricCapacitanceDto& dto)
        {
            return ElectricCapacitance(dto.value, dto.unit);
        }

#ifdef UNITSNET_ENABLE_NLOHMANN_JSON
        /// <summary>Serializes this quantity to a nlohmann JSON object.</summary>
        [[nodiscard]] nlohmann::json to_json(
            const ElectricCapacitanceUnit unit = ElectricCapacitanceUnit::Farad) const
        {
            return to_dto(unit).to_json();
        }

        /// <summary>Creates a quantity from a nlohmann JSON object.</summary>
        [[nodiscard]] static ElectricCapacitance from_json(const nlohmann::json& json)
        {
            return from_dto(ElectricCapacitanceDto::from_json(json));
        }
#endif
#endif

        [[nodiscard]] constexpr ElectricCapacitance operator+(const ElectricCapacitance& other) const noexcept
        {
            return ElectricCapacitance(base_value() + other.base_value());
        }

        [[nodiscard]] constexpr ElectricCapacitance operator-(const ElectricCapacitance& other)const noexcept
        {
            return ElectricCapacitance(base_value() - other.base_value());
        }

        [[nodiscard]] constexpr ElectricCapacitance operator*(const un_scalar_t scalar) const noexcept
        {
            return ElectricCapacitance(base_value() * scalar);
        }

        [[nodiscard]] constexpr ElectricCapacitance operator/(const un_scalar_t scalar) const noexcept
        {
            return ElectricCapacitance(base_value() / scalar);
        }

        [[nodiscard]] constexpr bool operator==(const ElectricCapacitance& other) const noexcept
        {
            return base_value() == other.base_value();
        }

        [[nodiscard]] constexpr bool operator<(const ElectricCapacitance& other) const noexcept
        {
            return base_value() < other.base_value();
        }
        
        [[nodiscard]] constexpr bool operator>(const ElectricCapacitance& other) const noexcept
        {
            return base_value() > other.base_value();
        }

        [[nodiscard]] constexpr un_scalar_t farads() const
        {
            return convert_from_base(ElectricCapacitanceUnit::Farad);
        }

        [[nodiscard]] static constexpr ElectricCapacitance from_farads(const un_scalar_t value)
        {
            return ElectricCapacitance(value, ElectricCapacitanceUnit::Farad);
        }

        [[nodiscard]] constexpr un_scalar_t picofarads() const
        {
            return convert_from_base(ElectricCapacitanceUnit::Picofarad);
        }

        [[nodiscard]] static constexpr ElectricCapacitance from_picofarads(const un_scalar_t value)
        {
            return ElectricCapacitance(value, ElectricCapacitanceUnit::Picofarad);
        }

        [[nodiscard]] constexpr un_scalar_t nanofarads() const
        {
            return convert_from_base(ElectricCapacitanceUnit::Nanofarad);
        }

        [[nodiscard]] static constexpr ElectricCapacitance from_nanofarads(const un_scalar_t value)
        {
            return ElectricCapacitance(value, ElectricCapacitanceUnit::Nanofarad);
        }

        [[nodiscard]] constexpr un_scalar_t microfarads() const
        {
            return convert_from_base(ElectricCapacitanceUnit::Microfarad);
        }

        [[nodiscard]] static constexpr ElectricCapacitance from_microfarads(const un_scalar_t value)
        {
            return ElectricCapacitance(value, ElectricCapacitanceUnit::Microfarad);
        }

        [[nodiscard]] constexpr un_scalar_t millifarads() const
        {
            return convert_from_base(ElectricCapacitanceUnit::Millifarad);
        }

        [[nodiscard]] static constexpr ElectricCapacitance from_millifarads(const un_scalar_t value)
        {
            return ElectricCapacitance(value, ElectricCapacitanceUnit::Millifarad);
        }

        [[nodiscard]] constexpr un_scalar_t kilofarads() const
        {
            return convert_from_base(ElectricCapacitanceUnit::Kilofarad);
        }

        [[nodiscard]] static constexpr ElectricCapacitance from_kilofarads(const un_scalar_t value)
        {
            return ElectricCapacitance(value, ElectricCapacitanceUnit::Kilofarad);
        }

        [[nodiscard]] constexpr un_scalar_t megafarads() const
        {
            return convert_from_base(ElectricCapacitanceUnit::Megafarad);
        }

        [[nodiscard]] static constexpr ElectricCapacitance from_megafarads(const un_scalar_t value)
        {
            return ElectricCapacitance(value, ElectricCapacitanceUnit::Megafarad);
        }

        [[nodiscard]] static constexpr ElectricCapacitance from_invalid()
        {
            return ElectricCapacitance(false);
        }
    private:
            
        [[nodiscard]] static constexpr un_scalar_t convert_to_base(un_scalar_t value, ElectricCapacitanceUnit unit)
        {
            switch (unit)
            {

            case ElectricCapacitanceUnit::Farad:
                return value;

            case ElectricCapacitanceUnit::Picofarad:
                return (value * static_cast<un_scalar_t>(1e-12));

            case ElectricCapacitanceUnit::Nanofarad:
                return (value * static_cast<un_scalar_t>(1e-9));

            case ElectricCapacitanceUnit::Microfarad:
                return (value * static_cast<un_scalar_t>(1e-6));

            case ElectricCapacitanceUnit::Millifarad:
                return (value * static_cast<un_scalar_t>(1e-3));

            case ElectricCapacitanceUnit::Kilofarad:
                return (value * static_cast<un_scalar_t>(1e3));

            case ElectricCapacitanceUnit::Megafarad:
                return (value * static_cast<un_scalar_t>(1e6));

            }

            throw std::invalid_argument("Unknown ElectricCapacitance unit.");
        }

        [[nodiscard]] constexpr un_scalar_t convert_from_base(const ElectricCapacitanceUnit unit) const
        {
            if(unit == value_unit_type_)
            {
                return value_;
            }
            
            auto base_value = convert_to_base(value_, value_unit_type_);
            
            switch (unit)
            {

            case ElectricCapacitanceUnit::Farad:
                return base_value;

            case ElectricCapacitanceUnit::Picofarad:
                return (base_value) / static_cast<un_scalar_t>(1e-12);

            case ElectricCapacitanceUnit::Nanofarad:
                return (base_value) / static_cast<un_scalar_t>(1e-9);

            case ElectricCapacitanceUnit::Microfarad:
                return (base_value) / static_cast<un_scalar_t>(1e-6);

            case ElectricCapacitanceUnit::Millifarad:
                return (base_value) / static_cast<un_scalar_t>(1e-3);

            case ElectricCapacitanceUnit::Kilofarad:
                return (base_value) / static_cast<un_scalar_t>(1e3);

            case ElectricCapacitanceUnit::Megafarad:
                return (base_value) / static_cast<un_scalar_t>(1e6);

            }

            throw std::invalid_argument("Unknown ElectricCapacitance unit.");
        }

        un_scalar_t value_;
        ElectricCapacitanceUnit value_unit_type_;       
    };
}
