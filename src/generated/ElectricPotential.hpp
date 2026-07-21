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
    enum class ElectricPotentialUnit : std::uint8_t
    {
        Volt,
        Nanovolt,
        Microvolt,
        Millivolt,
        Kilovolt,
        Megavolt,
    };

#if defined(UNITSNET_ENABLE_DTO) || defined(UNITSNET_ENABLE_NLOHMANN_JSON)
    /// <summary>A data-transfer representation of ElectricPotential.</summary>
    class ElectricPotentialDto
    {
    public:
        constexpr ElectricPotentialDto() noexcept
            : value{}, unit(ElectricPotentialUnit::Volt)
        {
        }

        constexpr ElectricPotentialDto(
            const un_scalar_t value,
            const ElectricPotentialUnit unit) noexcept
            : value(value), unit(unit)
        {
        }

        /// <summary>The numeric value of the quantity.</summary>
        un_scalar_t value;

        /// <summary>The unit in which value is expressed.</summary>
        ElectricPotentialUnit unit;

        /// <summary>The stable UnitsNet name used for cross-language serialization.</summary>
        [[nodiscard]] constexpr std::string_view unit_name() const noexcept
        {
            return magic_enum::enum_name(unit);
        }

        /// <summary>Converts a stable UnitsNet unit name to its strongly typed enum.</summary>
        [[nodiscard]] static constexpr ElectricPotentialUnit unit_from_name(const std::string_view name)
        {
            const auto unit = magic_enum::enum_cast<ElectricPotentialUnit>(name);
            if (unit.has_value())
            {
                return *unit;
            }

            throw std::invalid_argument("Unknown ElectricPotential unit name.");
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
        [[nodiscard]] static ElectricPotentialDto from_json(const nlohmann::json& json)
        {
            return ElectricPotentialDto(
                json.at("value").get<un_scalar_t>(),
                unit_from_name(json.at("unit").get<std::string>()));
        }
#endif
    };
#endif

    /// <summary>In classical electromagnetism, the electric potential (a scalar quantity denoted by Φ, ΦE or V and also called the electric field potential or the electrostatic potential) at a point is the amount of electric potential energy that a unitary point charge would have when located at that point.</summary>
    class ElectricPotential : public UnitsNetBase
    {
    public:
        constexpr explicit ElectricPotential(
            const un_scalar_t value,
            const ElectricPotentialUnit unit = ElectricPotentialUnit::Volt)
        {
            value_ = value;
            value_unit_type_ = unit;
        }
                
        [[nodiscard]] constexpr un_scalar_t base_value() const noexcept
        {
            return convert_to_base(value_, value_unit_type_);    
        }

        [[nodiscard]] constexpr un_scalar_t value(const ElectricPotentialUnit unit) const
        {
            return convert_from_base(unit);
        }

#if defined(UNITSNET_ENABLE_DTO) || defined(UNITSNET_ENABLE_NLOHMANN_JSON)
        /// <summary>Creates a DTO, expressed in the requested unit.</summary>
        [[nodiscard]] constexpr ElectricPotentialDto to_dto(
            const ElectricPotentialUnit unit = ElectricPotentialUnit::Volt) const
        {
            return ElectricPotentialDto(value(unit), unit);
        }

        /// <summary>Creates a quantity from its DTO representation.</summary>
        [[nodiscard]] static constexpr ElectricPotential from_dto(const ElectricPotentialDto& dto)
        {
            return ElectricPotential(dto.value, dto.unit);
        }

#ifdef UNITSNET_ENABLE_NLOHMANN_JSON
        /// <summary>Serializes this quantity to a nlohmann JSON object.</summary>
        [[nodiscard]] nlohmann::json to_json(
            const ElectricPotentialUnit unit = ElectricPotentialUnit::Volt) const
        {
            return to_dto(unit).to_json();
        }

        /// <summary>Creates a quantity from a nlohmann JSON object.</summary>
        [[nodiscard]] static ElectricPotential from_json(const nlohmann::json& json)
        {
            return from_dto(ElectricPotentialDto::from_json(json));
        }
#endif
#endif

        [[nodiscard]] constexpr ElectricPotential operator+(const ElectricPotential& other) const noexcept
        {
            return ElectricPotential(base_value() + other.base_value());
        }

        [[nodiscard]] constexpr ElectricPotential operator-(const ElectricPotential& other)const noexcept
        {
            return ElectricPotential(base_value() - other.base_value());
        }

        [[nodiscard]] constexpr ElectricPotential operator*(const un_scalar_t scalar) const noexcept
        {
            return ElectricPotential(base_value() * scalar);
        }

        [[nodiscard]] constexpr ElectricPotential operator/(const un_scalar_t scalar) const noexcept
        {
            return ElectricPotential(base_value() / scalar);
        }

        [[nodiscard]] constexpr bool operator==(const ElectricPotential& other) const noexcept
        {
            return base_value() == other.base_value();
        }

        [[nodiscard]] constexpr bool operator<(const ElectricPotential& other) const noexcept
        {
            return base_value() < other.base_value();
        }
        
        [[nodiscard]] constexpr bool operator>(const ElectricPotential& other) const noexcept
        {
            return base_value() > other.base_value();
        }

        [[nodiscard]] constexpr un_scalar_t volts() const
        {
            return convert_from_base(ElectricPotentialUnit::Volt);
        }

        [[nodiscard]] static constexpr ElectricPotential from_volts(const un_scalar_t value)
        {
            return ElectricPotential(value, ElectricPotentialUnit::Volt);
        }

        [[nodiscard]] constexpr un_scalar_t nanovolts() const
        {
            return convert_from_base(ElectricPotentialUnit::Nanovolt);
        }

        [[nodiscard]] static constexpr ElectricPotential from_nanovolts(const un_scalar_t value)
        {
            return ElectricPotential(value, ElectricPotentialUnit::Nanovolt);
        }

        [[nodiscard]] constexpr un_scalar_t microvolts() const
        {
            return convert_from_base(ElectricPotentialUnit::Microvolt);
        }

        [[nodiscard]] static constexpr ElectricPotential from_microvolts(const un_scalar_t value)
        {
            return ElectricPotential(value, ElectricPotentialUnit::Microvolt);
        }

        [[nodiscard]] constexpr un_scalar_t millivolts() const
        {
            return convert_from_base(ElectricPotentialUnit::Millivolt);
        }

        [[nodiscard]] static constexpr ElectricPotential from_millivolts(const un_scalar_t value)
        {
            return ElectricPotential(value, ElectricPotentialUnit::Millivolt);
        }

        [[nodiscard]] constexpr un_scalar_t kilovolts() const
        {
            return convert_from_base(ElectricPotentialUnit::Kilovolt);
        }

        [[nodiscard]] static constexpr ElectricPotential from_kilovolts(const un_scalar_t value)
        {
            return ElectricPotential(value, ElectricPotentialUnit::Kilovolt);
        }

        [[nodiscard]] constexpr un_scalar_t megavolts() const
        {
            return convert_from_base(ElectricPotentialUnit::Megavolt);
        }

        [[nodiscard]] static constexpr ElectricPotential from_megavolts(const un_scalar_t value)
        {
            return ElectricPotential(value, ElectricPotentialUnit::Megavolt);
        }

        [[nodiscard]] static constexpr ElectricPotential from_invalid()
        {
            return ElectricPotential(false);
        }
    private:
            
        [[nodiscard]] static constexpr un_scalar_t convert_to_base(un_scalar_t value, ElectricPotentialUnit unit)
        {
            switch (unit)
            {

            case ElectricPotentialUnit::Volt:
                return value;

            case ElectricPotentialUnit::Nanovolt:
                return (value * static_cast<un_scalar_t>(1e-9));

            case ElectricPotentialUnit::Microvolt:
                return (value * static_cast<un_scalar_t>(1e-6));

            case ElectricPotentialUnit::Millivolt:
                return (value * static_cast<un_scalar_t>(1e-3));

            case ElectricPotentialUnit::Kilovolt:
                return (value * static_cast<un_scalar_t>(1e3));

            case ElectricPotentialUnit::Megavolt:
                return (value * static_cast<un_scalar_t>(1e6));

            }

            throw std::invalid_argument("Unknown ElectricPotential unit.");
        }

        [[nodiscard]] constexpr un_scalar_t convert_from_base(const ElectricPotentialUnit unit) const
        {
            if(unit == value_unit_type_)
            {
                return value_;
            }
            
            auto base_value = convert_to_base(value_, value_unit_type_);
            
            switch (unit)
            {

            case ElectricPotentialUnit::Volt:
                return base_value;

            case ElectricPotentialUnit::Nanovolt:
                return (base_value) / static_cast<un_scalar_t>(1e-9);

            case ElectricPotentialUnit::Microvolt:
                return (base_value) / static_cast<un_scalar_t>(1e-6);

            case ElectricPotentialUnit::Millivolt:
                return (base_value) / static_cast<un_scalar_t>(1e-3);

            case ElectricPotentialUnit::Kilovolt:
                return (base_value) / static_cast<un_scalar_t>(1e3);

            case ElectricPotentialUnit::Megavolt:
                return (base_value) / static_cast<un_scalar_t>(1e6);

            }

            throw std::invalid_argument("Unknown ElectricPotential unit.");
        }

        un_scalar_t value_;
        ElectricPotentialUnit value_unit_type_;       
    };
}
