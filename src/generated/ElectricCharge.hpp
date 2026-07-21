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
    enum class ElectricChargeUnit : std::uint8_t
    {
        Coulomb,
        Picocoulomb,
        Nanocoulomb,
        Microcoulomb,
        Millicoulomb,
        Kilocoulomb,
        Megacoulomb,
        AmpereHour,
        MilliampereHour,
        KiloampereHour,
        MegaampereHour,
    };

#if defined(UNITSNET_ENABLE_DTO) || defined(UNITSNET_ENABLE_NLOHMANN_JSON)
    /// <summary>A data-transfer representation of ElectricCharge.</summary>
    class ElectricChargeDto
    {
    public:
        constexpr ElectricChargeDto() noexcept
            : value{}, unit(ElectricChargeUnit::Coulomb)
        {
        }

        constexpr ElectricChargeDto(
            const un_scalar_t value,
            const ElectricChargeUnit unit) noexcept
            : value(value), unit(unit)
        {
        }

        /// <summary>The numeric value of the quantity.</summary>
        un_scalar_t value;

        /// <summary>The unit in which value is expressed.</summary>
        ElectricChargeUnit unit;

        /// <summary>The stable UnitsNet name used for cross-language serialization.</summary>
        [[nodiscard]] constexpr std::string_view unit_name() const noexcept
        {
            return magic_enum::enum_name(unit);
        }

        /// <summary>Converts a stable UnitsNet unit name to its strongly typed enum.</summary>
        [[nodiscard]] static constexpr ElectricChargeUnit unit_from_name(const std::string_view name)
        {
            const auto unit = magic_enum::enum_cast<ElectricChargeUnit>(name);
            if (unit.has_value())
            {
                return *unit;
            }

            throw std::invalid_argument("Unknown ElectricCharge unit name.");
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
        [[nodiscard]] static ElectricChargeDto from_json(const nlohmann::json& json)
        {
            return ElectricChargeDto(
                json.at("value").get<un_scalar_t>(),
                unit_from_name(json.at("unit").get<std::string>()));
        }
#endif
    };
#endif

    /// <summary>Electric charge is the physical property of matter that causes it to experience a force when placed in an electromagnetic field.</summary>
    class ElectricCharge : public UnitsNetBase
    {
    public:
        constexpr explicit ElectricCharge(
            const un_scalar_t value,
            const ElectricChargeUnit unit = ElectricChargeUnit::Coulomb)
        {
            value_ = value;
            value_unit_type_ = unit;
        }
                
        [[nodiscard]] constexpr un_scalar_t base_value() const noexcept
        {
            return convert_to_base(value_, value_unit_type_);    
        }

        [[nodiscard]] constexpr un_scalar_t value(const ElectricChargeUnit unit) const
        {
            return convert_from_base(unit);
        }

#if defined(UNITSNET_ENABLE_DTO) || defined(UNITSNET_ENABLE_NLOHMANN_JSON)
        /// <summary>Creates a DTO, expressed in the requested unit.</summary>
        [[nodiscard]] constexpr ElectricChargeDto to_dto(
            const ElectricChargeUnit unit = ElectricChargeUnit::Coulomb) const
        {
            return ElectricChargeDto(value(unit), unit);
        }

        /// <summary>Creates a quantity from its DTO representation.</summary>
        [[nodiscard]] static constexpr ElectricCharge from_dto(const ElectricChargeDto& dto)
        {
            return ElectricCharge(dto.value, dto.unit);
        }

#ifdef UNITSNET_ENABLE_NLOHMANN_JSON
        /// <summary>Serializes this quantity to a nlohmann JSON object.</summary>
        [[nodiscard]] nlohmann::json to_json(
            const ElectricChargeUnit unit = ElectricChargeUnit::Coulomb) const
        {
            return to_dto(unit).to_json();
        }

        /// <summary>Creates a quantity from a nlohmann JSON object.</summary>
        [[nodiscard]] static ElectricCharge from_json(const nlohmann::json& json)
        {
            return from_dto(ElectricChargeDto::from_json(json));
        }
#endif
#endif

        [[nodiscard]] constexpr ElectricCharge operator+(const ElectricCharge& other) const noexcept
        {
            return ElectricCharge(base_value() + other.base_value());
        }

        [[nodiscard]] constexpr ElectricCharge operator-(const ElectricCharge& other)const noexcept
        {
            return ElectricCharge(base_value() - other.base_value());
        }

        [[nodiscard]] constexpr ElectricCharge operator*(const un_scalar_t scalar) const noexcept
        {
            return ElectricCharge(base_value() * scalar);
        }

        [[nodiscard]] constexpr ElectricCharge operator/(const un_scalar_t scalar) const noexcept
        {
            return ElectricCharge(base_value() / scalar);
        }

        [[nodiscard]] constexpr bool operator==(const ElectricCharge& other) const noexcept
        {
            return base_value() == other.base_value();
        }

        [[nodiscard]] constexpr bool operator<(const ElectricCharge& other) const noexcept
        {
            return base_value() < other.base_value();
        }
        
        [[nodiscard]] constexpr bool operator>(const ElectricCharge& other) const noexcept
        {
            return base_value() > other.base_value();
        }

        [[nodiscard]] constexpr un_scalar_t coulombs() const
        {
            return convert_from_base(ElectricChargeUnit::Coulomb);
        }

        [[nodiscard]] static constexpr ElectricCharge from_coulombs(const un_scalar_t value)
        {
            return ElectricCharge(value, ElectricChargeUnit::Coulomb);
        }

        [[nodiscard]] constexpr un_scalar_t picocoulombs() const
        {
            return convert_from_base(ElectricChargeUnit::Picocoulomb);
        }

        [[nodiscard]] static constexpr ElectricCharge from_picocoulombs(const un_scalar_t value)
        {
            return ElectricCharge(value, ElectricChargeUnit::Picocoulomb);
        }

        [[nodiscard]] constexpr un_scalar_t nanocoulombs() const
        {
            return convert_from_base(ElectricChargeUnit::Nanocoulomb);
        }

        [[nodiscard]] static constexpr ElectricCharge from_nanocoulombs(const un_scalar_t value)
        {
            return ElectricCharge(value, ElectricChargeUnit::Nanocoulomb);
        }

        [[nodiscard]] constexpr un_scalar_t microcoulombs() const
        {
            return convert_from_base(ElectricChargeUnit::Microcoulomb);
        }

        [[nodiscard]] static constexpr ElectricCharge from_microcoulombs(const un_scalar_t value)
        {
            return ElectricCharge(value, ElectricChargeUnit::Microcoulomb);
        }

        [[nodiscard]] constexpr un_scalar_t millicoulombs() const
        {
            return convert_from_base(ElectricChargeUnit::Millicoulomb);
        }

        [[nodiscard]] static constexpr ElectricCharge from_millicoulombs(const un_scalar_t value)
        {
            return ElectricCharge(value, ElectricChargeUnit::Millicoulomb);
        }

        [[nodiscard]] constexpr un_scalar_t kilocoulombs() const
        {
            return convert_from_base(ElectricChargeUnit::Kilocoulomb);
        }

        [[nodiscard]] static constexpr ElectricCharge from_kilocoulombs(const un_scalar_t value)
        {
            return ElectricCharge(value, ElectricChargeUnit::Kilocoulomb);
        }

        [[nodiscard]] constexpr un_scalar_t megacoulombs() const
        {
            return convert_from_base(ElectricChargeUnit::Megacoulomb);
        }

        [[nodiscard]] static constexpr ElectricCharge from_megacoulombs(const un_scalar_t value)
        {
            return ElectricCharge(value, ElectricChargeUnit::Megacoulomb);
        }

        [[nodiscard]] constexpr un_scalar_t ampere_hours() const
        {
            return convert_from_base(ElectricChargeUnit::AmpereHour);
        }

        [[nodiscard]] static constexpr ElectricCharge from_ampere_hours(const un_scalar_t value)
        {
            return ElectricCharge(value, ElectricChargeUnit::AmpereHour);
        }

        [[nodiscard]] constexpr un_scalar_t milliampere_hours() const
        {
            return convert_from_base(ElectricChargeUnit::MilliampereHour);
        }

        [[nodiscard]] static constexpr ElectricCharge from_milliampere_hours(const un_scalar_t value)
        {
            return ElectricCharge(value, ElectricChargeUnit::MilliampereHour);
        }

        [[nodiscard]] constexpr un_scalar_t kiloampere_hours() const
        {
            return convert_from_base(ElectricChargeUnit::KiloampereHour);
        }

        [[nodiscard]] static constexpr ElectricCharge from_kiloampere_hours(const un_scalar_t value)
        {
            return ElectricCharge(value, ElectricChargeUnit::KiloampereHour);
        }

        [[nodiscard]] constexpr un_scalar_t megaampere_hours() const
        {
            return convert_from_base(ElectricChargeUnit::MegaampereHour);
        }

        [[nodiscard]] static constexpr ElectricCharge from_megaampere_hours(const un_scalar_t value)
        {
            return ElectricCharge(value, ElectricChargeUnit::MegaampereHour);
        }

        [[nodiscard]] static constexpr ElectricCharge from_invalid()
        {
            return ElectricCharge(false);
        }
    private:
            
        [[nodiscard]] static constexpr un_scalar_t convert_to_base(un_scalar_t value, ElectricChargeUnit unit)
        {
            switch (unit)
            {

            case ElectricChargeUnit::Coulomb:
                return value;

            case ElectricChargeUnit::Picocoulomb:
                return (value * static_cast<un_scalar_t>(1e-12));

            case ElectricChargeUnit::Nanocoulomb:
                return (value * static_cast<un_scalar_t>(1e-9));

            case ElectricChargeUnit::Microcoulomb:
                return (value * static_cast<un_scalar_t>(1e-6));

            case ElectricChargeUnit::Millicoulomb:
                return (value * static_cast<un_scalar_t>(1e-3));

            case ElectricChargeUnit::Kilocoulomb:
                return (value * static_cast<un_scalar_t>(1e3));

            case ElectricChargeUnit::Megacoulomb:
                return (value * static_cast<un_scalar_t>(1e6));

            case ElectricChargeUnit::AmpereHour:
                return value * static_cast<un_scalar_t>(3600);

            case ElectricChargeUnit::MilliampereHour:
                return (value * static_cast<un_scalar_t>(1e-3)) * static_cast<un_scalar_t>(3600);

            case ElectricChargeUnit::KiloampereHour:
                return (value * static_cast<un_scalar_t>(1e3)) * static_cast<un_scalar_t>(3600);

            case ElectricChargeUnit::MegaampereHour:
                return (value * static_cast<un_scalar_t>(1e6)) * static_cast<un_scalar_t>(3600);

            }

            throw std::invalid_argument("Unknown ElectricCharge unit.");
        }

        [[nodiscard]] constexpr un_scalar_t convert_from_base(const ElectricChargeUnit unit) const
        {
            if(unit == value_unit_type_)
            {
                return value_;
            }
            
            auto base_value = convert_to_base(value_, value_unit_type_);
            
            switch (unit)
            {

            case ElectricChargeUnit::Coulomb:
                return base_value;

            case ElectricChargeUnit::Picocoulomb:
                return (base_value) / static_cast<un_scalar_t>(1e-12);

            case ElectricChargeUnit::Nanocoulomb:
                return (base_value) / static_cast<un_scalar_t>(1e-9);

            case ElectricChargeUnit::Microcoulomb:
                return (base_value) / static_cast<un_scalar_t>(1e-6);

            case ElectricChargeUnit::Millicoulomb:
                return (base_value) / static_cast<un_scalar_t>(1e-3);

            case ElectricChargeUnit::Kilocoulomb:
                return (base_value) / static_cast<un_scalar_t>(1e3);

            case ElectricChargeUnit::Megacoulomb:
                return (base_value) / static_cast<un_scalar_t>(1e6);

            case ElectricChargeUnit::AmpereHour:
                return base_value / static_cast<un_scalar_t>(3600);

            case ElectricChargeUnit::MilliampereHour:
                return (base_value / static_cast<un_scalar_t>(3600)) / static_cast<un_scalar_t>(1e-3);

            case ElectricChargeUnit::KiloampereHour:
                return (base_value / static_cast<un_scalar_t>(3600)) / static_cast<un_scalar_t>(1e3);

            case ElectricChargeUnit::MegaampereHour:
                return (base_value / static_cast<un_scalar_t>(3600)) / static_cast<un_scalar_t>(1e6);

            }

            throw std::invalid_argument("Unknown ElectricCharge unit.");
        }

        un_scalar_t value_;
        ElectricChargeUnit value_unit_type_;       
    };
}
