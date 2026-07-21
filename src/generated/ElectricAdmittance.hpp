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
    enum class ElectricAdmittanceUnit : std::uint8_t
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
    /// <summary>A data-transfer representation of ElectricAdmittance.</summary>
    class ElectricAdmittanceDto
    {
    public:
        constexpr ElectricAdmittanceDto() noexcept
            : value{}, unit(ElectricAdmittanceUnit::Siemens)
        {
        }

        constexpr ElectricAdmittanceDto(
            const un_scalar_t value,
            const ElectricAdmittanceUnit unit) noexcept
            : value(value), unit(unit)
        {
        }

        /// <summary>The numeric value of the quantity.</summary>
        un_scalar_t value;

        /// <summary>The unit in which value is expressed.</summary>
        ElectricAdmittanceUnit unit;

        /// <summary>The stable UnitsNet name used for cross-language serialization.</summary>
        [[nodiscard]] constexpr std::string_view unit_name() const noexcept
        {
            return magic_enum::enum_name(unit);
        }

        /// <summary>Converts a stable UnitsNet unit name to its strongly typed enum.</summary>
        [[nodiscard]] static constexpr ElectricAdmittanceUnit unit_from_name(const std::string_view name)
        {
            const auto unit = magic_enum::enum_cast<ElectricAdmittanceUnit>(name);
            if (unit.has_value())
            {
                return *unit;
            }

            throw std::invalid_argument("Unknown ElectricAdmittance unit name.");
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
        [[nodiscard]] static ElectricAdmittanceDto from_json(const nlohmann::json& json)
        {
            return ElectricAdmittanceDto(
                json.at("value").get<un_scalar_t>(),
                unit_from_name(json.at("unit").get<std::string>()));
        }
#endif
    };
#endif

    /// <summary>Electric admittance is a measure of how easily a circuit or device will allow a current to flow by the combined effect of conductance and susceptance in a circuit. It is defined as the inverse of impedance. The SI unit of admittance is the siemens (symbol S).</summary>
    class ElectricAdmittance : public UnitsNetBase
    {
    public:
        constexpr explicit ElectricAdmittance(
            const un_scalar_t value,
            const ElectricAdmittanceUnit unit = ElectricAdmittanceUnit::Siemens)
        {
            value_ = value;
            value_unit_type_ = unit;
        }
                
        [[nodiscard]] constexpr un_scalar_t base_value() const noexcept
        {
            return convert_to_base(value_, value_unit_type_);    
        }

        [[nodiscard]] constexpr un_scalar_t value(const ElectricAdmittanceUnit unit) const
        {
            return convert_from_base(unit);
        }

#if defined(UNITSNET_ENABLE_DTO) || defined(UNITSNET_ENABLE_NLOHMANN_JSON)
        /// <summary>Creates a DTO, expressed in the requested unit.</summary>
        [[nodiscard]] constexpr ElectricAdmittanceDto to_dto(
            const ElectricAdmittanceUnit unit = ElectricAdmittanceUnit::Siemens) const
        {
            return ElectricAdmittanceDto(value(unit), unit);
        }

        /// <summary>Creates a quantity from its DTO representation.</summary>
        [[nodiscard]] static constexpr ElectricAdmittance from_dto(const ElectricAdmittanceDto& dto)
        {
            return ElectricAdmittance(dto.value, dto.unit);
        }

#ifdef UNITSNET_ENABLE_NLOHMANN_JSON
        /// <summary>Serializes this quantity to a nlohmann JSON object.</summary>
        [[nodiscard]] nlohmann::json to_json(
            const ElectricAdmittanceUnit unit = ElectricAdmittanceUnit::Siemens) const
        {
            return to_dto(unit).to_json();
        }

        /// <summary>Creates a quantity from a nlohmann JSON object.</summary>
        [[nodiscard]] static ElectricAdmittance from_json(const nlohmann::json& json)
        {
            return from_dto(ElectricAdmittanceDto::from_json(json));
        }
#endif
#endif

        [[nodiscard]] constexpr ElectricAdmittance operator+(const ElectricAdmittance& other) const noexcept
        {
            return ElectricAdmittance(base_value() + other.base_value());
        }

        [[nodiscard]] constexpr ElectricAdmittance operator-(const ElectricAdmittance& other)const noexcept
        {
            return ElectricAdmittance(base_value() - other.base_value());
        }

        [[nodiscard]] constexpr ElectricAdmittance operator*(const un_scalar_t scalar) const noexcept
        {
            return ElectricAdmittance(base_value() * scalar);
        }

        [[nodiscard]] constexpr ElectricAdmittance operator/(const un_scalar_t scalar) const noexcept
        {
            return ElectricAdmittance(base_value() / scalar);
        }

        [[nodiscard]] constexpr bool operator==(const ElectricAdmittance& other) const noexcept
        {
            return base_value() == other.base_value();
        }

        [[nodiscard]] constexpr bool operator<(const ElectricAdmittance& other) const noexcept
        {
            return base_value() < other.base_value();
        }
        
        [[nodiscard]] constexpr bool operator>(const ElectricAdmittance& other) const noexcept
        {
            return base_value() > other.base_value();
        }

        [[nodiscard]] constexpr un_scalar_t siemens() const
        {
            return convert_from_base(ElectricAdmittanceUnit::Siemens);
        }

        [[nodiscard]] static constexpr ElectricAdmittance from_siemens(const un_scalar_t value)
        {
            return ElectricAdmittance(value, ElectricAdmittanceUnit::Siemens);
        }

        [[nodiscard]] constexpr un_scalar_t nanosiemens() const
        {
            return convert_from_base(ElectricAdmittanceUnit::Nanosiemens);
        }

        [[nodiscard]] static constexpr ElectricAdmittance from_nanosiemens(const un_scalar_t value)
        {
            return ElectricAdmittance(value, ElectricAdmittanceUnit::Nanosiemens);
        }

        [[nodiscard]] constexpr un_scalar_t microsiemens() const
        {
            return convert_from_base(ElectricAdmittanceUnit::Microsiemens);
        }

        [[nodiscard]] static constexpr ElectricAdmittance from_microsiemens(const un_scalar_t value)
        {
            return ElectricAdmittance(value, ElectricAdmittanceUnit::Microsiemens);
        }

        [[nodiscard]] constexpr un_scalar_t millisiemens() const
        {
            return convert_from_base(ElectricAdmittanceUnit::Millisiemens);
        }

        [[nodiscard]] static constexpr ElectricAdmittance from_millisiemens(const un_scalar_t value)
        {
            return ElectricAdmittance(value, ElectricAdmittanceUnit::Millisiemens);
        }

        [[nodiscard]] constexpr un_scalar_t kilosiemens() const
        {
            return convert_from_base(ElectricAdmittanceUnit::Kilosiemens);
        }

        [[nodiscard]] static constexpr ElectricAdmittance from_kilosiemens(const un_scalar_t value)
        {
            return ElectricAdmittance(value, ElectricAdmittanceUnit::Kilosiemens);
        }

        [[nodiscard]] constexpr un_scalar_t megasiemens() const
        {
            return convert_from_base(ElectricAdmittanceUnit::Megasiemens);
        }

        [[nodiscard]] static constexpr ElectricAdmittance from_megasiemens(const un_scalar_t value)
        {
            return ElectricAdmittance(value, ElectricAdmittanceUnit::Megasiemens);
        }

        [[nodiscard]] constexpr un_scalar_t gigasiemens() const
        {
            return convert_from_base(ElectricAdmittanceUnit::Gigasiemens);
        }

        [[nodiscard]] static constexpr ElectricAdmittance from_gigasiemens(const un_scalar_t value)
        {
            return ElectricAdmittance(value, ElectricAdmittanceUnit::Gigasiemens);
        }

        [[nodiscard]] constexpr un_scalar_t terasiemens() const
        {
            return convert_from_base(ElectricAdmittanceUnit::Terasiemens);
        }

        [[nodiscard]] static constexpr ElectricAdmittance from_terasiemens(const un_scalar_t value)
        {
            return ElectricAdmittance(value, ElectricAdmittanceUnit::Terasiemens);
        }

        [[nodiscard]] constexpr un_scalar_t mhos() const
        {
            return convert_from_base(ElectricAdmittanceUnit::Mho);
        }

        [[nodiscard]] static constexpr ElectricAdmittance from_mhos(const un_scalar_t value)
        {
            return ElectricAdmittance(value, ElectricAdmittanceUnit::Mho);
        }

        [[nodiscard]] constexpr un_scalar_t nanomhos() const
        {
            return convert_from_base(ElectricAdmittanceUnit::Nanomho);
        }

        [[nodiscard]] static constexpr ElectricAdmittance from_nanomhos(const un_scalar_t value)
        {
            return ElectricAdmittance(value, ElectricAdmittanceUnit::Nanomho);
        }

        [[nodiscard]] constexpr un_scalar_t micromhos() const
        {
            return convert_from_base(ElectricAdmittanceUnit::Micromho);
        }

        [[nodiscard]] static constexpr ElectricAdmittance from_micromhos(const un_scalar_t value)
        {
            return ElectricAdmittance(value, ElectricAdmittanceUnit::Micromho);
        }

        [[nodiscard]] constexpr un_scalar_t millimhos() const
        {
            return convert_from_base(ElectricAdmittanceUnit::Millimho);
        }

        [[nodiscard]] static constexpr ElectricAdmittance from_millimhos(const un_scalar_t value)
        {
            return ElectricAdmittance(value, ElectricAdmittanceUnit::Millimho);
        }

        [[nodiscard]] constexpr un_scalar_t kilomhos() const
        {
            return convert_from_base(ElectricAdmittanceUnit::Kilomho);
        }

        [[nodiscard]] static constexpr ElectricAdmittance from_kilomhos(const un_scalar_t value)
        {
            return ElectricAdmittance(value, ElectricAdmittanceUnit::Kilomho);
        }

        [[nodiscard]] constexpr un_scalar_t megamhos() const
        {
            return convert_from_base(ElectricAdmittanceUnit::Megamho);
        }

        [[nodiscard]] static constexpr ElectricAdmittance from_megamhos(const un_scalar_t value)
        {
            return ElectricAdmittance(value, ElectricAdmittanceUnit::Megamho);
        }

        [[nodiscard]] constexpr un_scalar_t gigamhos() const
        {
            return convert_from_base(ElectricAdmittanceUnit::Gigamho);
        }

        [[nodiscard]] static constexpr ElectricAdmittance from_gigamhos(const un_scalar_t value)
        {
            return ElectricAdmittance(value, ElectricAdmittanceUnit::Gigamho);
        }

        [[nodiscard]] constexpr un_scalar_t teramhos() const
        {
            return convert_from_base(ElectricAdmittanceUnit::Teramho);
        }

        [[nodiscard]] static constexpr ElectricAdmittance from_teramhos(const un_scalar_t value)
        {
            return ElectricAdmittance(value, ElectricAdmittanceUnit::Teramho);
        }

        [[nodiscard]] static constexpr ElectricAdmittance from_invalid()
        {
            return ElectricAdmittance(false);
        }
    private:
            
        [[nodiscard]] static constexpr un_scalar_t convert_to_base(un_scalar_t value, ElectricAdmittanceUnit unit)
        {
            switch (unit)
            {

            case ElectricAdmittanceUnit::Siemens:
                return value;

            case ElectricAdmittanceUnit::Nanosiemens:
                return (value * static_cast<un_scalar_t>(1e-9));

            case ElectricAdmittanceUnit::Microsiemens:
                return (value * static_cast<un_scalar_t>(1e-6));

            case ElectricAdmittanceUnit::Millisiemens:
                return (value * static_cast<un_scalar_t>(1e-3));

            case ElectricAdmittanceUnit::Kilosiemens:
                return (value * static_cast<un_scalar_t>(1e3));

            case ElectricAdmittanceUnit::Megasiemens:
                return (value * static_cast<un_scalar_t>(1e6));

            case ElectricAdmittanceUnit::Gigasiemens:
                return (value * static_cast<un_scalar_t>(1e9));

            case ElectricAdmittanceUnit::Terasiemens:
                return (value * static_cast<un_scalar_t>(1e12));

            case ElectricAdmittanceUnit::Mho:
                return value;

            case ElectricAdmittanceUnit::Nanomho:
                return (value * static_cast<un_scalar_t>(1e-9));

            case ElectricAdmittanceUnit::Micromho:
                return (value * static_cast<un_scalar_t>(1e-6));

            case ElectricAdmittanceUnit::Millimho:
                return (value * static_cast<un_scalar_t>(1e-3));

            case ElectricAdmittanceUnit::Kilomho:
                return (value * static_cast<un_scalar_t>(1e3));

            case ElectricAdmittanceUnit::Megamho:
                return (value * static_cast<un_scalar_t>(1e6));

            case ElectricAdmittanceUnit::Gigamho:
                return (value * static_cast<un_scalar_t>(1e9));

            case ElectricAdmittanceUnit::Teramho:
                return (value * static_cast<un_scalar_t>(1e12));

            }

            throw std::invalid_argument("Unknown ElectricAdmittance unit.");
        }

        [[nodiscard]] constexpr un_scalar_t convert_from_base(const ElectricAdmittanceUnit unit) const
        {
            if(unit == value_unit_type_)
            {
                return value_;
            }
            
            auto base_value = convert_to_base(value_, value_unit_type_);
            
            switch (unit)
            {

            case ElectricAdmittanceUnit::Siemens:
                return base_value;

            case ElectricAdmittanceUnit::Nanosiemens:
                return (base_value) / static_cast<un_scalar_t>(1e-9);

            case ElectricAdmittanceUnit::Microsiemens:
                return (base_value) / static_cast<un_scalar_t>(1e-6);

            case ElectricAdmittanceUnit::Millisiemens:
                return (base_value) / static_cast<un_scalar_t>(1e-3);

            case ElectricAdmittanceUnit::Kilosiemens:
                return (base_value) / static_cast<un_scalar_t>(1e3);

            case ElectricAdmittanceUnit::Megasiemens:
                return (base_value) / static_cast<un_scalar_t>(1e6);

            case ElectricAdmittanceUnit::Gigasiemens:
                return (base_value) / static_cast<un_scalar_t>(1e9);

            case ElectricAdmittanceUnit::Terasiemens:
                return (base_value) / static_cast<un_scalar_t>(1e12);

            case ElectricAdmittanceUnit::Mho:
                return base_value;

            case ElectricAdmittanceUnit::Nanomho:
                return (base_value) / static_cast<un_scalar_t>(1e-9);

            case ElectricAdmittanceUnit::Micromho:
                return (base_value) / static_cast<un_scalar_t>(1e-6);

            case ElectricAdmittanceUnit::Millimho:
                return (base_value) / static_cast<un_scalar_t>(1e-3);

            case ElectricAdmittanceUnit::Kilomho:
                return (base_value) / static_cast<un_scalar_t>(1e3);

            case ElectricAdmittanceUnit::Megamho:
                return (base_value) / static_cast<un_scalar_t>(1e6);

            case ElectricAdmittanceUnit::Gigamho:
                return (base_value) / static_cast<un_scalar_t>(1e9);

            case ElectricAdmittanceUnit::Teramho:
                return (base_value) / static_cast<un_scalar_t>(1e12);

            }

            throw std::invalid_argument("Unknown ElectricAdmittance unit.");
        }

        un_scalar_t value_;
        ElectricAdmittanceUnit value_unit_type_;       
    };
}
