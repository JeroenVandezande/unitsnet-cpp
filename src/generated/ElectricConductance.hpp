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
    enum class ElectricConductanceUnit : std::uint8_t
    {
        Siemens,
        Nanosiemens,
        Microsiemens,
        Millisiemens,
        Kilosiemens,
        Megasiemens,
        Gigasiemens,
        Terasiemens,
        Mho,
        Nanomho,
        Micromho,
        Millimho,
        Kilomho,
        Megamho,
        Gigamho,
        Teramho,
    };

#if defined(UNITSNET_ENABLE_DTO) || defined(UNITSNET_ENABLE_NLOHMANN_JSON)
    /// <summary>A data-transfer representation of ElectricConductance.</summary>
    class ElectricConductanceDto
    {
    public:
        constexpr ElectricConductanceDto() noexcept
            : value{}, unit(ElectricConductanceUnit::Siemens)
        {
        }

        constexpr ElectricConductanceDto(
            const un_scalar_t value,
            const ElectricConductanceUnit unit) noexcept
            : value(value), unit(unit)
        {
        }

        /// <summary>The numeric value of the quantity.</summary>
        un_scalar_t value;

        /// <summary>The unit in which value is expressed.</summary>
        ElectricConductanceUnit unit;

        /// <summary>The stable UnitsNet name used for cross-language serialization.</summary>
        [[nodiscard]] constexpr std::string_view unit_name() const noexcept
        {
            return magic_enum::enum_name(unit);
        }

        /// <summary>Converts a stable UnitsNet unit name to its strongly typed enum.</summary>
        [[nodiscard]] static constexpr ElectricConductanceUnit unit_from_name(const std::string_view name)
        {
            const auto unit = magic_enum::enum_cast<ElectricConductanceUnit>(name);
            if (unit.has_value())
            {
                return *unit;
            }

            throw std::invalid_argument("Unknown ElectricConductance unit name.");
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
        [[nodiscard]] static ElectricConductanceDto from_json(const nlohmann::json& json)
        {
            return ElectricConductanceDto(
                json.at("value").get<un_scalar_t>(),
                unit_from_name(json.at("unit").get<std::string>()));
        }
#endif
    };
#endif

    /// <summary>The electrical conductance of an object is a measure of the ease with which an electric current passes. Along with susceptance, it is one of two elements of admittance. Its reciprocal quantity is electrical resistance.</summary>
    class ElectricConductance : public UnitsNetBase
    {
    public:
        constexpr explicit ElectricConductance(
            const un_scalar_t value,
            const ElectricConductanceUnit unit = ElectricConductanceUnit::Siemens)
        {
            value_ = value;
            value_unit_type_ = unit;
        }
                
        [[nodiscard]] constexpr un_scalar_t base_value() const noexcept
        {
            return convert_to_base(value_, value_unit_type_);    
        }

        [[nodiscard]] constexpr un_scalar_t value(const ElectricConductanceUnit unit) const
        {
            return convert_from_base(unit);
        }

#if defined(UNITSNET_ENABLE_DTO) || defined(UNITSNET_ENABLE_NLOHMANN_JSON)
        /// <summary>Creates a DTO, expressed in the requested unit.</summary>
        [[nodiscard]] constexpr ElectricConductanceDto to_dto(
            const ElectricConductanceUnit unit = ElectricConductanceUnit::Siemens) const
        {
            return ElectricConductanceDto(value(unit), unit);
        }

        /// <summary>Creates a quantity from its DTO representation.</summary>
        [[nodiscard]] static constexpr ElectricConductance from_dto(const ElectricConductanceDto& dto)
        {
            return ElectricConductance(dto.value, dto.unit);
        }

#ifdef UNITSNET_ENABLE_NLOHMANN_JSON
        /// <summary>Serializes this quantity to a nlohmann JSON object.</summary>
        [[nodiscard]] nlohmann::json to_json(
            const ElectricConductanceUnit unit = ElectricConductanceUnit::Siemens) const
        {
            return to_dto(unit).to_json();
        }

        /// <summary>Creates a quantity from a nlohmann JSON object.</summary>
        [[nodiscard]] static ElectricConductance from_json(const nlohmann::json& json)
        {
            return from_dto(ElectricConductanceDto::from_json(json));
        }
#endif
#endif

        [[nodiscard]] constexpr ElectricConductance operator+(const ElectricConductance& other) const noexcept
        {
            return ElectricConductance(base_value() + other.base_value());
        }

        [[nodiscard]] constexpr ElectricConductance operator-(const ElectricConductance& other)const noexcept
        {
            return ElectricConductance(base_value() - other.base_value());
        }

        [[nodiscard]] constexpr ElectricConductance operator*(const un_scalar_t scalar) const noexcept
        {
            return ElectricConductance(base_value() * scalar);
        }

        [[nodiscard]] constexpr ElectricConductance operator/(const un_scalar_t scalar) const noexcept
        {
            return ElectricConductance(base_value() / scalar);
        }

        [[nodiscard]] constexpr bool operator==(const ElectricConductance& other) const noexcept
        {
            return base_value() == other.base_value();
        }

        [[nodiscard]] constexpr bool operator<(const ElectricConductance& other) const noexcept
        {
            return base_value() < other.base_value();
        }
        
        [[nodiscard]] constexpr bool operator>(const ElectricConductance& other) const noexcept
        {
            return base_value() > other.base_value();
        }

        [[nodiscard]] constexpr un_scalar_t siemens() const
        {
            return convert_from_base(ElectricConductanceUnit::Siemens);
        }

        [[nodiscard]] static constexpr ElectricConductance from_siemens(const un_scalar_t value)
        {
            return ElectricConductance(value, ElectricConductanceUnit::Siemens);
        }

        [[nodiscard]] constexpr un_scalar_t nanosiemens() const
        {
            return convert_from_base(ElectricConductanceUnit::Nanosiemens);
        }

        [[nodiscard]] static constexpr ElectricConductance from_nanosiemens(const un_scalar_t value)
        {
            return ElectricConductance(value, ElectricConductanceUnit::Nanosiemens);
        }

        [[nodiscard]] constexpr un_scalar_t microsiemens() const
        {
            return convert_from_base(ElectricConductanceUnit::Microsiemens);
        }

        [[nodiscard]] static constexpr ElectricConductance from_microsiemens(const un_scalar_t value)
        {
            return ElectricConductance(value, ElectricConductanceUnit::Microsiemens);
        }

        [[nodiscard]] constexpr un_scalar_t millisiemens() const
        {
            return convert_from_base(ElectricConductanceUnit::Millisiemens);
        }

        [[nodiscard]] static constexpr ElectricConductance from_millisiemens(const un_scalar_t value)
        {
            return ElectricConductance(value, ElectricConductanceUnit::Millisiemens);
        }

        [[nodiscard]] constexpr un_scalar_t kilosiemens() const
        {
            return convert_from_base(ElectricConductanceUnit::Kilosiemens);
        }

        [[nodiscard]] static constexpr ElectricConductance from_kilosiemens(const un_scalar_t value)
        {
            return ElectricConductance(value, ElectricConductanceUnit::Kilosiemens);
        }

        [[nodiscard]] constexpr un_scalar_t megasiemens() const
        {
            return convert_from_base(ElectricConductanceUnit::Megasiemens);
        }

        [[nodiscard]] static constexpr ElectricConductance from_megasiemens(const un_scalar_t value)
        {
            return ElectricConductance(value, ElectricConductanceUnit::Megasiemens);
        }

        [[nodiscard]] constexpr un_scalar_t gigasiemens() const
        {
            return convert_from_base(ElectricConductanceUnit::Gigasiemens);
        }

        [[nodiscard]] static constexpr ElectricConductance from_gigasiemens(const un_scalar_t value)
        {
            return ElectricConductance(value, ElectricConductanceUnit::Gigasiemens);
        }

        [[nodiscard]] constexpr un_scalar_t terasiemens() const
        {
            return convert_from_base(ElectricConductanceUnit::Terasiemens);
        }

        [[nodiscard]] static constexpr ElectricConductance from_terasiemens(const un_scalar_t value)
        {
            return ElectricConductance(value, ElectricConductanceUnit::Terasiemens);
        }

        [[nodiscard]] constexpr un_scalar_t mhos() const
        {
            return convert_from_base(ElectricConductanceUnit::Mho);
        }

        [[nodiscard]] static constexpr ElectricConductance from_mhos(const un_scalar_t value)
        {
            return ElectricConductance(value, ElectricConductanceUnit::Mho);
        }

        [[nodiscard]] constexpr un_scalar_t nanomhos() const
        {
            return convert_from_base(ElectricConductanceUnit::Nanomho);
        }

        [[nodiscard]] static constexpr ElectricConductance from_nanomhos(const un_scalar_t value)
        {
            return ElectricConductance(value, ElectricConductanceUnit::Nanomho);
        }

        [[nodiscard]] constexpr un_scalar_t micromhos() const
        {
            return convert_from_base(ElectricConductanceUnit::Micromho);
        }

        [[nodiscard]] static constexpr ElectricConductance from_micromhos(const un_scalar_t value)
        {
            return ElectricConductance(value, ElectricConductanceUnit::Micromho);
        }

        [[nodiscard]] constexpr un_scalar_t millimhos() const
        {
            return convert_from_base(ElectricConductanceUnit::Millimho);
        }

        [[nodiscard]] static constexpr ElectricConductance from_millimhos(const un_scalar_t value)
        {
            return ElectricConductance(value, ElectricConductanceUnit::Millimho);
        }

        [[nodiscard]] constexpr un_scalar_t kilomhos() const
        {
            return convert_from_base(ElectricConductanceUnit::Kilomho);
        }

        [[nodiscard]] static constexpr ElectricConductance from_kilomhos(const un_scalar_t value)
        {
            return ElectricConductance(value, ElectricConductanceUnit::Kilomho);
        }

        [[nodiscard]] constexpr un_scalar_t megamhos() const
        {
            return convert_from_base(ElectricConductanceUnit::Megamho);
        }

        [[nodiscard]] static constexpr ElectricConductance from_megamhos(const un_scalar_t value)
        {
            return ElectricConductance(value, ElectricConductanceUnit::Megamho);
        }

        [[nodiscard]] constexpr un_scalar_t gigamhos() const
        {
            return convert_from_base(ElectricConductanceUnit::Gigamho);
        }

        [[nodiscard]] static constexpr ElectricConductance from_gigamhos(const un_scalar_t value)
        {
            return ElectricConductance(value, ElectricConductanceUnit::Gigamho);
        }

        [[nodiscard]] constexpr un_scalar_t teramhos() const
        {
            return convert_from_base(ElectricConductanceUnit::Teramho);
        }

        [[nodiscard]] static constexpr ElectricConductance from_teramhos(const un_scalar_t value)
        {
            return ElectricConductance(value, ElectricConductanceUnit::Teramho);
        }

        [[nodiscard]] static constexpr ElectricConductance from_invalid()
        {
            return ElectricConductance(false);
        }
    private:
            
        [[nodiscard]] static constexpr un_scalar_t convert_to_base(un_scalar_t value, ElectricConductanceUnit unit)
        {
            switch (unit)
            {

            case ElectricConductanceUnit::Siemens:
                return value;

            case ElectricConductanceUnit::Nanosiemens:
                return (value * static_cast<un_scalar_t>(1e-9));

            case ElectricConductanceUnit::Microsiemens:
                return (value * static_cast<un_scalar_t>(1e-6));

            case ElectricConductanceUnit::Millisiemens:
                return (value * static_cast<un_scalar_t>(1e-3));

            case ElectricConductanceUnit::Kilosiemens:
                return (value * static_cast<un_scalar_t>(1e3));

            case ElectricConductanceUnit::Megasiemens:
                return (value * static_cast<un_scalar_t>(1e6));

            case ElectricConductanceUnit::Gigasiemens:
                return (value * static_cast<un_scalar_t>(1e9));

            case ElectricConductanceUnit::Terasiemens:
                return (value * static_cast<un_scalar_t>(1e12));

            case ElectricConductanceUnit::Mho:
                return value;

            case ElectricConductanceUnit::Nanomho:
                return (value * static_cast<un_scalar_t>(1e-9));

            case ElectricConductanceUnit::Micromho:
                return (value * static_cast<un_scalar_t>(1e-6));

            case ElectricConductanceUnit::Millimho:
                return (value * static_cast<un_scalar_t>(1e-3));

            case ElectricConductanceUnit::Kilomho:
                return (value * static_cast<un_scalar_t>(1e3));

            case ElectricConductanceUnit::Megamho:
                return (value * static_cast<un_scalar_t>(1e6));

            case ElectricConductanceUnit::Gigamho:
                return (value * static_cast<un_scalar_t>(1e9));

            case ElectricConductanceUnit::Teramho:
                return (value * static_cast<un_scalar_t>(1e12));

            }

            throw std::invalid_argument("Unknown ElectricConductance unit.");
        }

        [[nodiscard]] constexpr un_scalar_t convert_from_base(const ElectricConductanceUnit unit) const
        {
            if(unit == value_unit_type_)
            {
                return value_;
            }
            
            auto base_value = convert_to_base(value_, value_unit_type_);
            
            switch (unit)
            {

            case ElectricConductanceUnit::Siemens:
                return base_value;

            case ElectricConductanceUnit::Nanosiemens:
                return (base_value) / static_cast<un_scalar_t>(1e-9);

            case ElectricConductanceUnit::Microsiemens:
                return (base_value) / static_cast<un_scalar_t>(1e-6);

            case ElectricConductanceUnit::Millisiemens:
                return (base_value) / static_cast<un_scalar_t>(1e-3);

            case ElectricConductanceUnit::Kilosiemens:
                return (base_value) / static_cast<un_scalar_t>(1e3);

            case ElectricConductanceUnit::Megasiemens:
                return (base_value) / static_cast<un_scalar_t>(1e6);

            case ElectricConductanceUnit::Gigasiemens:
                return (base_value) / static_cast<un_scalar_t>(1e9);

            case ElectricConductanceUnit::Terasiemens:
                return (base_value) / static_cast<un_scalar_t>(1e12);

            case ElectricConductanceUnit::Mho:
                return base_value;

            case ElectricConductanceUnit::Nanomho:
                return (base_value) / static_cast<un_scalar_t>(1e-9);

            case ElectricConductanceUnit::Micromho:
                return (base_value) / static_cast<un_scalar_t>(1e-6);

            case ElectricConductanceUnit::Millimho:
                return (base_value) / static_cast<un_scalar_t>(1e-3);

            case ElectricConductanceUnit::Kilomho:
                return (base_value) / static_cast<un_scalar_t>(1e3);

            case ElectricConductanceUnit::Megamho:
                return (base_value) / static_cast<un_scalar_t>(1e6);

            case ElectricConductanceUnit::Gigamho:
                return (base_value) / static_cast<un_scalar_t>(1e9);

            case ElectricConductanceUnit::Teramho:
                return (base_value) / static_cast<un_scalar_t>(1e12);

            }

            throw std::invalid_argument("Unknown ElectricConductance unit.");
        }

        un_scalar_t value_;
        ElectricConductanceUnit value_unit_type_;       
    };
}
