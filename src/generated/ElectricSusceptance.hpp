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
    enum class ElectricSusceptanceUnit : std::uint8_t
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
    /// <summary>A data-transfer representation of ElectricSusceptance.</summary>
    class ElectricSusceptanceDto
    {
    public:
        constexpr ElectricSusceptanceDto() noexcept
            : value{}, unit(ElectricSusceptanceUnit::Siemens)
        {
        }

        constexpr ElectricSusceptanceDto(
            const un_scalar_t value,
            const ElectricSusceptanceUnit unit) noexcept
            : value(value), unit(unit)
        {
        }

        /// <summary>The numeric value of the quantity.</summary>
        un_scalar_t value;

        /// <summary>The unit in which value is expressed.</summary>
        ElectricSusceptanceUnit unit;

        /// <summary>The stable UnitsNet name used for cross-language serialization.</summary>
        [[nodiscard]] constexpr std::string_view unit_name() const noexcept
        {
            return magic_enum::enum_name(unit);
        }

        /// <summary>Converts a stable UnitsNet unit name to its strongly typed enum.</summary>
        [[nodiscard]] static constexpr ElectricSusceptanceUnit unit_from_name(const std::string_view name)
        {
            const auto unit = magic_enum::enum_cast<ElectricSusceptanceUnit>(name);
            if (unit.has_value())
            {
                return *unit;
            }

            throw std::invalid_argument("Unknown ElectricSusceptance unit name.");
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
        [[nodiscard]] static ElectricSusceptanceDto from_json(const nlohmann::json& json)
        {
            return ElectricSusceptanceDto(
                json.at("value").get<un_scalar_t>(),
                unit_from_name(json.at("unit").get<std::string>()));
        }
#endif
    };
#endif

    /// <summary>Electrical susceptance is the imaginary part of admittance, where the real part is conductance.</summary>
    class ElectricSusceptance : public UnitsNetBase
    {
    public:
        constexpr explicit ElectricSusceptance(
            const un_scalar_t value,
            const ElectricSusceptanceUnit unit = ElectricSusceptanceUnit::Siemens)
        {
            value_ = value;
            value_unit_type_ = unit;
        }
                
        [[nodiscard]] constexpr un_scalar_t base_value() const noexcept
        {
            return convert_to_base(value_, value_unit_type_);    
        }

        [[nodiscard]] constexpr un_scalar_t value(const ElectricSusceptanceUnit unit) const
        {
            return convert_from_base(unit);
        }

#if defined(UNITSNET_ENABLE_DTO) || defined(UNITSNET_ENABLE_NLOHMANN_JSON)
        /// <summary>Creates a DTO, expressed in the requested unit.</summary>
        [[nodiscard]] constexpr ElectricSusceptanceDto to_dto(
            const ElectricSusceptanceUnit unit = ElectricSusceptanceUnit::Siemens) const
        {
            return ElectricSusceptanceDto(value(unit), unit);
        }

        /// <summary>Creates a quantity from its DTO representation.</summary>
        [[nodiscard]] static constexpr ElectricSusceptance from_dto(const ElectricSusceptanceDto& dto)
        {
            return ElectricSusceptance(dto.value, dto.unit);
        }

#ifdef UNITSNET_ENABLE_NLOHMANN_JSON
        /// <summary>Serializes this quantity to a nlohmann JSON object.</summary>
        [[nodiscard]] nlohmann::json to_json(
            const ElectricSusceptanceUnit unit = ElectricSusceptanceUnit::Siemens) const
        {
            return to_dto(unit).to_json();
        }

        /// <summary>Creates a quantity from a nlohmann JSON object.</summary>
        [[nodiscard]] static ElectricSusceptance from_json(const nlohmann::json& json)
        {
            return from_dto(ElectricSusceptanceDto::from_json(json));
        }
#endif
#endif

        [[nodiscard]] constexpr ElectricSusceptance operator+(const ElectricSusceptance& other) const noexcept
        {
            return ElectricSusceptance(base_value() + other.base_value());
        }

        [[nodiscard]] constexpr ElectricSusceptance operator-(const ElectricSusceptance& other)const noexcept
        {
            return ElectricSusceptance(base_value() - other.base_value());
        }

        [[nodiscard]] constexpr ElectricSusceptance operator*(const un_scalar_t scalar) const noexcept
        {
            return ElectricSusceptance(base_value() * scalar);
        }

        [[nodiscard]] constexpr ElectricSusceptance operator/(const un_scalar_t scalar) const noexcept
        {
            return ElectricSusceptance(base_value() / scalar);
        }

        [[nodiscard]] constexpr bool operator==(const ElectricSusceptance& other) const noexcept
        {
            return base_value() == other.base_value();
        }

        [[nodiscard]] constexpr bool operator<(const ElectricSusceptance& other) const noexcept
        {
            return base_value() < other.base_value();
        }
        
        [[nodiscard]] constexpr bool operator>(const ElectricSusceptance& other) const noexcept
        {
            return base_value() > other.base_value();
        }

        [[nodiscard]] constexpr un_scalar_t siemens() const
        {
            return convert_from_base(ElectricSusceptanceUnit::Siemens);
        }

        [[nodiscard]] static constexpr ElectricSusceptance from_siemens(const un_scalar_t value)
        {
            return ElectricSusceptance(value, ElectricSusceptanceUnit::Siemens);
        }

        [[nodiscard]] constexpr un_scalar_t nanosiemens() const
        {
            return convert_from_base(ElectricSusceptanceUnit::Nanosiemens);
        }

        [[nodiscard]] static constexpr ElectricSusceptance from_nanosiemens(const un_scalar_t value)
        {
            return ElectricSusceptance(value, ElectricSusceptanceUnit::Nanosiemens);
        }

        [[nodiscard]] constexpr un_scalar_t microsiemens() const
        {
            return convert_from_base(ElectricSusceptanceUnit::Microsiemens);
        }

        [[nodiscard]] static constexpr ElectricSusceptance from_microsiemens(const un_scalar_t value)
        {
            return ElectricSusceptance(value, ElectricSusceptanceUnit::Microsiemens);
        }

        [[nodiscard]] constexpr un_scalar_t millisiemens() const
        {
            return convert_from_base(ElectricSusceptanceUnit::Millisiemens);
        }

        [[nodiscard]] static constexpr ElectricSusceptance from_millisiemens(const un_scalar_t value)
        {
            return ElectricSusceptance(value, ElectricSusceptanceUnit::Millisiemens);
        }

        [[nodiscard]] constexpr un_scalar_t kilosiemens() const
        {
            return convert_from_base(ElectricSusceptanceUnit::Kilosiemens);
        }

        [[nodiscard]] static constexpr ElectricSusceptance from_kilosiemens(const un_scalar_t value)
        {
            return ElectricSusceptance(value, ElectricSusceptanceUnit::Kilosiemens);
        }

        [[nodiscard]] constexpr un_scalar_t megasiemens() const
        {
            return convert_from_base(ElectricSusceptanceUnit::Megasiemens);
        }

        [[nodiscard]] static constexpr ElectricSusceptance from_megasiemens(const un_scalar_t value)
        {
            return ElectricSusceptance(value, ElectricSusceptanceUnit::Megasiemens);
        }

        [[nodiscard]] constexpr un_scalar_t gigasiemens() const
        {
            return convert_from_base(ElectricSusceptanceUnit::Gigasiemens);
        }

        [[nodiscard]] static constexpr ElectricSusceptance from_gigasiemens(const un_scalar_t value)
        {
            return ElectricSusceptance(value, ElectricSusceptanceUnit::Gigasiemens);
        }

        [[nodiscard]] constexpr un_scalar_t terasiemens() const
        {
            return convert_from_base(ElectricSusceptanceUnit::Terasiemens);
        }

        [[nodiscard]] static constexpr ElectricSusceptance from_terasiemens(const un_scalar_t value)
        {
            return ElectricSusceptance(value, ElectricSusceptanceUnit::Terasiemens);
        }

        [[nodiscard]] constexpr un_scalar_t mhos() const
        {
            return convert_from_base(ElectricSusceptanceUnit::Mho);
        }

        [[nodiscard]] static constexpr ElectricSusceptance from_mhos(const un_scalar_t value)
        {
            return ElectricSusceptance(value, ElectricSusceptanceUnit::Mho);
        }

        [[nodiscard]] constexpr un_scalar_t nanomhos() const
        {
            return convert_from_base(ElectricSusceptanceUnit::Nanomho);
        }

        [[nodiscard]] static constexpr ElectricSusceptance from_nanomhos(const un_scalar_t value)
        {
            return ElectricSusceptance(value, ElectricSusceptanceUnit::Nanomho);
        }

        [[nodiscard]] constexpr un_scalar_t micromhos() const
        {
            return convert_from_base(ElectricSusceptanceUnit::Micromho);
        }

        [[nodiscard]] static constexpr ElectricSusceptance from_micromhos(const un_scalar_t value)
        {
            return ElectricSusceptance(value, ElectricSusceptanceUnit::Micromho);
        }

        [[nodiscard]] constexpr un_scalar_t millimhos() const
        {
            return convert_from_base(ElectricSusceptanceUnit::Millimho);
        }

        [[nodiscard]] static constexpr ElectricSusceptance from_millimhos(const un_scalar_t value)
        {
            return ElectricSusceptance(value, ElectricSusceptanceUnit::Millimho);
        }

        [[nodiscard]] constexpr un_scalar_t kilomhos() const
        {
            return convert_from_base(ElectricSusceptanceUnit::Kilomho);
        }

        [[nodiscard]] static constexpr ElectricSusceptance from_kilomhos(const un_scalar_t value)
        {
            return ElectricSusceptance(value, ElectricSusceptanceUnit::Kilomho);
        }

        [[nodiscard]] constexpr un_scalar_t megamhos() const
        {
            return convert_from_base(ElectricSusceptanceUnit::Megamho);
        }

        [[nodiscard]] static constexpr ElectricSusceptance from_megamhos(const un_scalar_t value)
        {
            return ElectricSusceptance(value, ElectricSusceptanceUnit::Megamho);
        }

        [[nodiscard]] constexpr un_scalar_t gigamhos() const
        {
            return convert_from_base(ElectricSusceptanceUnit::Gigamho);
        }

        [[nodiscard]] static constexpr ElectricSusceptance from_gigamhos(const un_scalar_t value)
        {
            return ElectricSusceptance(value, ElectricSusceptanceUnit::Gigamho);
        }

        [[nodiscard]] constexpr un_scalar_t teramhos() const
        {
            return convert_from_base(ElectricSusceptanceUnit::Teramho);
        }

        [[nodiscard]] static constexpr ElectricSusceptance from_teramhos(const un_scalar_t value)
        {
            return ElectricSusceptance(value, ElectricSusceptanceUnit::Teramho);
        }

        [[nodiscard]] static constexpr ElectricSusceptance from_invalid()
        {
            return ElectricSusceptance(false);
        }
    private:
            
        [[nodiscard]] static constexpr un_scalar_t convert_to_base(un_scalar_t value, ElectricSusceptanceUnit unit)
        {
            switch (unit)
            {

            case ElectricSusceptanceUnit::Siemens:
                return value;

            case ElectricSusceptanceUnit::Nanosiemens:
                return (value * static_cast<un_scalar_t>(1e-9));

            case ElectricSusceptanceUnit::Microsiemens:
                return (value * static_cast<un_scalar_t>(1e-6));

            case ElectricSusceptanceUnit::Millisiemens:
                return (value * static_cast<un_scalar_t>(1e-3));

            case ElectricSusceptanceUnit::Kilosiemens:
                return (value * static_cast<un_scalar_t>(1e3));

            case ElectricSusceptanceUnit::Megasiemens:
                return (value * static_cast<un_scalar_t>(1e6));

            case ElectricSusceptanceUnit::Gigasiemens:
                return (value * static_cast<un_scalar_t>(1e9));

            case ElectricSusceptanceUnit::Terasiemens:
                return (value * static_cast<un_scalar_t>(1e12));

            case ElectricSusceptanceUnit::Mho:
                return value;

            case ElectricSusceptanceUnit::Nanomho:
                return (value * static_cast<un_scalar_t>(1e-9));

            case ElectricSusceptanceUnit::Micromho:
                return (value * static_cast<un_scalar_t>(1e-6));

            case ElectricSusceptanceUnit::Millimho:
                return (value * static_cast<un_scalar_t>(1e-3));

            case ElectricSusceptanceUnit::Kilomho:
                return (value * static_cast<un_scalar_t>(1e3));

            case ElectricSusceptanceUnit::Megamho:
                return (value * static_cast<un_scalar_t>(1e6));

            case ElectricSusceptanceUnit::Gigamho:
                return (value * static_cast<un_scalar_t>(1e9));

            case ElectricSusceptanceUnit::Teramho:
                return (value * static_cast<un_scalar_t>(1e12));

            }

            throw std::invalid_argument("Unknown ElectricSusceptance unit.");
        }

        [[nodiscard]] constexpr un_scalar_t convert_from_base(const ElectricSusceptanceUnit unit) const
        {
            if(unit == value_unit_type_)
            {
                return value_;
            }
            
            auto base_value = convert_to_base(value_, value_unit_type_);
            
            switch (unit)
            {

            case ElectricSusceptanceUnit::Siemens:
                return base_value;

            case ElectricSusceptanceUnit::Nanosiemens:
                return (base_value) / static_cast<un_scalar_t>(1e-9);

            case ElectricSusceptanceUnit::Microsiemens:
                return (base_value) / static_cast<un_scalar_t>(1e-6);

            case ElectricSusceptanceUnit::Millisiemens:
                return (base_value) / static_cast<un_scalar_t>(1e-3);

            case ElectricSusceptanceUnit::Kilosiemens:
                return (base_value) / static_cast<un_scalar_t>(1e3);

            case ElectricSusceptanceUnit::Megasiemens:
                return (base_value) / static_cast<un_scalar_t>(1e6);

            case ElectricSusceptanceUnit::Gigasiemens:
                return (base_value) / static_cast<un_scalar_t>(1e9);

            case ElectricSusceptanceUnit::Terasiemens:
                return (base_value) / static_cast<un_scalar_t>(1e12);

            case ElectricSusceptanceUnit::Mho:
                return base_value;

            case ElectricSusceptanceUnit::Nanomho:
                return (base_value) / static_cast<un_scalar_t>(1e-9);

            case ElectricSusceptanceUnit::Micromho:
                return (base_value) / static_cast<un_scalar_t>(1e-6);

            case ElectricSusceptanceUnit::Millimho:
                return (base_value) / static_cast<un_scalar_t>(1e-3);

            case ElectricSusceptanceUnit::Kilomho:
                return (base_value) / static_cast<un_scalar_t>(1e3);

            case ElectricSusceptanceUnit::Megamho:
                return (base_value) / static_cast<un_scalar_t>(1e6);

            case ElectricSusceptanceUnit::Gigamho:
                return (base_value) / static_cast<un_scalar_t>(1e9);

            case ElectricSusceptanceUnit::Teramho:
                return (base_value) / static_cast<un_scalar_t>(1e12);

            }

            throw std::invalid_argument("Unknown ElectricSusceptance unit.");
        }

        un_scalar_t value_;
        ElectricSusceptanceUnit value_unit_type_;       
    };
}
