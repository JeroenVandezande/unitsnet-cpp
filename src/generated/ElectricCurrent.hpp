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
    enum class ElectricCurrentUnit : std::uint8_t
    {
        Ampere,
        Femtoampere,
        Picoampere,
        Nanoampere,
        Microampere,
        Milliampere,
        Centiampere,
        Kiloampere,
        Megaampere,
    };

#if defined(UNITSNET_ENABLE_DTO) || defined(UNITSNET_ENABLE_NLOHMANN_JSON)
    /// <summary>A data-transfer representation of ElectricCurrent.</summary>
    class ElectricCurrentDto
    {
    public:
        constexpr ElectricCurrentDto() noexcept
            : value{}, unit(ElectricCurrentUnit::Ampere)
        {
        }

        constexpr ElectricCurrentDto(
            const un_scalar_t value,
            const ElectricCurrentUnit unit) noexcept
            : value(value), unit(unit)
        {
        }

        /// <summary>The numeric value of the quantity.</summary>
        un_scalar_t value;

        /// <summary>The unit in which value is expressed.</summary>
        ElectricCurrentUnit unit;

        /// <summary>The stable UnitsNet name used for cross-language serialization.</summary>
        [[nodiscard]] constexpr std::string_view unit_name() const noexcept
        {
            return magic_enum::enum_name(unit);
        }

        /// <summary>Converts a stable UnitsNet unit name to its strongly typed enum.</summary>
        [[nodiscard]] static constexpr ElectricCurrentUnit unit_from_name(const std::string_view name)
        {
            const auto unit = magic_enum::enum_cast<ElectricCurrentUnit>(name);
            if (unit.has_value())
            {
                return *unit;
            }

            throw std::invalid_argument("Unknown ElectricCurrent unit name.");
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
        [[nodiscard]] static ElectricCurrentDto from_json(const nlohmann::json& json)
        {
            return ElectricCurrentDto(
                json.at("value").get<un_scalar_t>(),
                unit_from_name(json.at("unit").get<std::string>()));
        }
#endif
    };
#endif

    /// <summary>An electric current is a flow of electric charge. In electric circuits this charge is often carried by moving electrons in a wire. It can also be carried by ions in an electrolyte, or by both ions and electrons such as in a plasma.</summary>
    class ElectricCurrent : public UnitsNetBase
    {
    public:
        constexpr explicit ElectricCurrent(
            const un_scalar_t value,
            const ElectricCurrentUnit unit = ElectricCurrentUnit::Ampere)
        {
            value_ = value;
            value_unit_type_ = unit;
        }
                
        [[nodiscard]] constexpr un_scalar_t base_value() const noexcept
        {
            return convert_to_base(value_, value_unit_type_);    
        }

        [[nodiscard]] constexpr un_scalar_t value(const ElectricCurrentUnit unit) const
        {
            return convert_from_base(unit);
        }

#if defined(UNITSNET_ENABLE_DTO) || defined(UNITSNET_ENABLE_NLOHMANN_JSON)
        /// <summary>Creates a DTO, expressed in the requested unit.</summary>
        [[nodiscard]] constexpr ElectricCurrentDto to_dto(
            const ElectricCurrentUnit unit = ElectricCurrentUnit::Ampere) const
        {
            return ElectricCurrentDto(value(unit), unit);
        }

        /// <summary>Creates a quantity from its DTO representation.</summary>
        [[nodiscard]] static constexpr ElectricCurrent from_dto(const ElectricCurrentDto& dto)
        {
            return ElectricCurrent(dto.value, dto.unit);
        }

#ifdef UNITSNET_ENABLE_NLOHMANN_JSON
        /// <summary>Serializes this quantity to a nlohmann JSON object.</summary>
        [[nodiscard]] nlohmann::json to_json(
            const ElectricCurrentUnit unit = ElectricCurrentUnit::Ampere) const
        {
            return to_dto(unit).to_json();
        }

        /// <summary>Creates a quantity from a nlohmann JSON object.</summary>
        [[nodiscard]] static ElectricCurrent from_json(const nlohmann::json& json)
        {
            return from_dto(ElectricCurrentDto::from_json(json));
        }
#endif
#endif

        [[nodiscard]] constexpr ElectricCurrent operator+(const ElectricCurrent& other) const noexcept
        {
            return ElectricCurrent(base_value() + other.base_value());
        }

        [[nodiscard]] constexpr ElectricCurrent operator-(const ElectricCurrent& other)const noexcept
        {
            return ElectricCurrent(base_value() - other.base_value());
        }

        [[nodiscard]] constexpr ElectricCurrent operator*(const un_scalar_t scalar) const noexcept
        {
            return ElectricCurrent(base_value() * scalar);
        }

        [[nodiscard]] constexpr ElectricCurrent operator/(const un_scalar_t scalar) const noexcept
        {
            return ElectricCurrent(base_value() / scalar);
        }

        [[nodiscard]] constexpr bool operator==(const ElectricCurrent& other) const noexcept
        {
            return base_value() == other.base_value();
        }

        [[nodiscard]] constexpr bool operator<(const ElectricCurrent& other) const noexcept
        {
            return base_value() < other.base_value();
        }
        
        [[nodiscard]] constexpr bool operator>(const ElectricCurrent& other) const noexcept
        {
            return base_value() > other.base_value();
        }

        [[nodiscard]] constexpr un_scalar_t amperes() const
        {
            return convert_from_base(ElectricCurrentUnit::Ampere);
        }

        [[nodiscard]] static constexpr ElectricCurrent from_amperes(const un_scalar_t value)
        {
            return ElectricCurrent(value, ElectricCurrentUnit::Ampere);
        }

        [[nodiscard]] constexpr un_scalar_t femtoamperes() const
        {
            return convert_from_base(ElectricCurrentUnit::Femtoampere);
        }

        [[nodiscard]] static constexpr ElectricCurrent from_femtoamperes(const un_scalar_t value)
        {
            return ElectricCurrent(value, ElectricCurrentUnit::Femtoampere);
        }

        [[nodiscard]] constexpr un_scalar_t picoamperes() const
        {
            return convert_from_base(ElectricCurrentUnit::Picoampere);
        }

        [[nodiscard]] static constexpr ElectricCurrent from_picoamperes(const un_scalar_t value)
        {
            return ElectricCurrent(value, ElectricCurrentUnit::Picoampere);
        }

        [[nodiscard]] constexpr un_scalar_t nanoamperes() const
        {
            return convert_from_base(ElectricCurrentUnit::Nanoampere);
        }

        [[nodiscard]] static constexpr ElectricCurrent from_nanoamperes(const un_scalar_t value)
        {
            return ElectricCurrent(value, ElectricCurrentUnit::Nanoampere);
        }

        [[nodiscard]] constexpr un_scalar_t microamperes() const
        {
            return convert_from_base(ElectricCurrentUnit::Microampere);
        }

        [[nodiscard]] static constexpr ElectricCurrent from_microamperes(const un_scalar_t value)
        {
            return ElectricCurrent(value, ElectricCurrentUnit::Microampere);
        }

        [[nodiscard]] constexpr un_scalar_t milliamperes() const
        {
            return convert_from_base(ElectricCurrentUnit::Milliampere);
        }

        [[nodiscard]] static constexpr ElectricCurrent from_milliamperes(const un_scalar_t value)
        {
            return ElectricCurrent(value, ElectricCurrentUnit::Milliampere);
        }

        [[nodiscard]] constexpr un_scalar_t centiamperes() const
        {
            return convert_from_base(ElectricCurrentUnit::Centiampere);
        }

        [[nodiscard]] static constexpr ElectricCurrent from_centiamperes(const un_scalar_t value)
        {
            return ElectricCurrent(value, ElectricCurrentUnit::Centiampere);
        }

        [[nodiscard]] constexpr un_scalar_t kiloamperes() const
        {
            return convert_from_base(ElectricCurrentUnit::Kiloampere);
        }

        [[nodiscard]] static constexpr ElectricCurrent from_kiloamperes(const un_scalar_t value)
        {
            return ElectricCurrent(value, ElectricCurrentUnit::Kiloampere);
        }

        [[nodiscard]] constexpr un_scalar_t megaamperes() const
        {
            return convert_from_base(ElectricCurrentUnit::Megaampere);
        }

        [[nodiscard]] static constexpr ElectricCurrent from_megaamperes(const un_scalar_t value)
        {
            return ElectricCurrent(value, ElectricCurrentUnit::Megaampere);
        }

        [[nodiscard]] static constexpr ElectricCurrent from_invalid()
        {
            return ElectricCurrent(false);
        }
    private:
            
        [[nodiscard]] static constexpr un_scalar_t convert_to_base(un_scalar_t value, ElectricCurrentUnit unit)
        {
            switch (unit)
            {

            case ElectricCurrentUnit::Ampere:
                return value;

            case ElectricCurrentUnit::Femtoampere:
                return (value * static_cast<un_scalar_t>(1e-15));

            case ElectricCurrentUnit::Picoampere:
                return (value * static_cast<un_scalar_t>(1e-12));

            case ElectricCurrentUnit::Nanoampere:
                return (value * static_cast<un_scalar_t>(1e-9));

            case ElectricCurrentUnit::Microampere:
                return (value * static_cast<un_scalar_t>(1e-6));

            case ElectricCurrentUnit::Milliampere:
                return (value * static_cast<un_scalar_t>(1e-3));

            case ElectricCurrentUnit::Centiampere:
                return (value * static_cast<un_scalar_t>(1e-2));

            case ElectricCurrentUnit::Kiloampere:
                return (value * static_cast<un_scalar_t>(1e3));

            case ElectricCurrentUnit::Megaampere:
                return (value * static_cast<un_scalar_t>(1e6));

            }

            throw std::invalid_argument("Unknown ElectricCurrent unit.");
        }

        [[nodiscard]] constexpr un_scalar_t convert_from_base(const ElectricCurrentUnit unit) const
        {
            if(unit == value_unit_type_)
            {
                return value_;
            }
            
            auto base_value = convert_to_base(value_, value_unit_type_);
            
            switch (unit)
            {

            case ElectricCurrentUnit::Ampere:
                return base_value;

            case ElectricCurrentUnit::Femtoampere:
                return (base_value) / static_cast<un_scalar_t>(1e-15);

            case ElectricCurrentUnit::Picoampere:
                return (base_value) / static_cast<un_scalar_t>(1e-12);

            case ElectricCurrentUnit::Nanoampere:
                return (base_value) / static_cast<un_scalar_t>(1e-9);

            case ElectricCurrentUnit::Microampere:
                return (base_value) / static_cast<un_scalar_t>(1e-6);

            case ElectricCurrentUnit::Milliampere:
                return (base_value) / static_cast<un_scalar_t>(1e-3);

            case ElectricCurrentUnit::Centiampere:
                return (base_value) / static_cast<un_scalar_t>(1e-2);

            case ElectricCurrentUnit::Kiloampere:
                return (base_value) / static_cast<un_scalar_t>(1e3);

            case ElectricCurrentUnit::Megaampere:
                return (base_value) / static_cast<un_scalar_t>(1e6);

            }

            throw std::invalid_argument("Unknown ElectricCurrent unit.");
        }

        un_scalar_t value_;
        ElectricCurrentUnit value_unit_type_;       
    };
}
