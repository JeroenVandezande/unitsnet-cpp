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
    enum class AmountOfSubstanceUnit : std::uint8_t
    {
        Mole,
        Femtomole,
        Picomole,
        Nanomole,
        Micromole,
        Millimole,
        Centimole,
        Decimole,
        Kilomole,
        Megamole,
        PoundMole,
        NanopoundMole,
        MicropoundMole,
        MillipoundMole,
        CentipoundMole,
        DecipoundMole,
        KilopoundMole,
    };

#if defined(UNITSNET_ENABLE_DTO) || defined(UNITSNET_ENABLE_NLOHMANN_JSON)
    /// <summary>A data-transfer representation of AmountOfSubstance.</summary>
    class AmountOfSubstanceDto
    {
    public:
        constexpr AmountOfSubstanceDto() noexcept
            : value{}, unit(AmountOfSubstanceUnit::Mole)
        {
        }

        constexpr AmountOfSubstanceDto(
            const un_scalar_t value,
            const AmountOfSubstanceUnit unit) noexcept
            : value(value), unit(unit)
        {
        }

        /// <summary>The numeric value of the quantity.</summary>
        un_scalar_t value;

        /// <summary>The unit in which value is expressed.</summary>
        AmountOfSubstanceUnit unit;

        /// <summary>The stable UnitsNet name used for cross-language serialization.</summary>
        [[nodiscard]] constexpr std::string_view unit_name() const noexcept
        {
            return magic_enum::enum_name(unit);
        }

        /// <summary>Converts a stable UnitsNet unit name to its strongly typed enum.</summary>
        [[nodiscard]] static constexpr AmountOfSubstanceUnit unit_from_name(const std::string_view name)
        {
            const auto unit = magic_enum::enum_cast<AmountOfSubstanceUnit>(name);
            if (unit.has_value())
            {
                return *unit;
            }

            throw std::invalid_argument("Unknown AmountOfSubstance unit name.");
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
        [[nodiscard]] static AmountOfSubstanceDto from_json(const nlohmann::json& json)
        {
            return AmountOfSubstanceDto(
                json.at("value").get<un_scalar_t>(),
                unit_from_name(json.at("unit").get<std::string>()));
        }
#endif
    };
#endif

    /// <summary>Mole is the amount of substance containing Avagadro's Number (6.02 x 10 ^ 23) of real particles such as molecules,atoms, ions or radicals.</summary>
    class AmountOfSubstance : public UnitsNetBase
    {
    public:
        constexpr explicit AmountOfSubstance(
            const un_scalar_t value,
            const AmountOfSubstanceUnit unit = AmountOfSubstanceUnit::Mole)
        {
            value_ = value;
            value_unit_type_ = unit;
        }
                
        [[nodiscard]] constexpr un_scalar_t base_value() const noexcept
        {
            return convert_to_base(value_, value_unit_type_);    
        }

        [[nodiscard]] constexpr un_scalar_t value(const AmountOfSubstanceUnit unit) const
        {
            return convert_from_base(unit);
        }

#if defined(UNITSNET_ENABLE_DTO) || defined(UNITSNET_ENABLE_NLOHMANN_JSON)
        /// <summary>Creates a DTO, expressed in the requested unit.</summary>
        [[nodiscard]] constexpr AmountOfSubstanceDto to_dto(
            const AmountOfSubstanceUnit unit = AmountOfSubstanceUnit::Mole) const
        {
            return AmountOfSubstanceDto(value(unit), unit);
        }

        /// <summary>Creates a quantity from its DTO representation.</summary>
        [[nodiscard]] static constexpr AmountOfSubstance from_dto(const AmountOfSubstanceDto& dto)
        {
            return AmountOfSubstance(dto.value, dto.unit);
        }

#ifdef UNITSNET_ENABLE_NLOHMANN_JSON
        /// <summary>Serializes this quantity to a nlohmann JSON object.</summary>
        [[nodiscard]] nlohmann::json to_json(
            const AmountOfSubstanceUnit unit = AmountOfSubstanceUnit::Mole) const
        {
            return to_dto(unit).to_json();
        }

        /// <summary>Creates a quantity from a nlohmann JSON object.</summary>
        [[nodiscard]] static AmountOfSubstance from_json(const nlohmann::json& json)
        {
            return from_dto(AmountOfSubstanceDto::from_json(json));
        }
#endif
#endif

        [[nodiscard]] constexpr AmountOfSubstance operator+(const AmountOfSubstance& other) const noexcept
        {
            return AmountOfSubstance(base_value() + other.base_value());
        }

        [[nodiscard]] constexpr AmountOfSubstance operator-(const AmountOfSubstance& other)const noexcept
        {
            return AmountOfSubstance(base_value() - other.base_value());
        }

        [[nodiscard]] constexpr AmountOfSubstance operator*(const un_scalar_t scalar) const noexcept
        {
            return AmountOfSubstance(base_value() * scalar);
        }

        [[nodiscard]] constexpr AmountOfSubstance operator/(const un_scalar_t scalar) const noexcept
        {
            return AmountOfSubstance(base_value() / scalar);
        }

        [[nodiscard]] constexpr bool operator==(const AmountOfSubstance& other) const noexcept
        {
            return base_value() == other.base_value();
        }

        [[nodiscard]] constexpr bool operator<(const AmountOfSubstance& other) const noexcept
        {
            return base_value() < other.base_value();
        }
        
        [[nodiscard]] constexpr bool operator>(const AmountOfSubstance& other) const noexcept
        {
            return base_value() > other.base_value();
        }

        [[nodiscard]] constexpr un_scalar_t moles() const
        {
            return convert_from_base(AmountOfSubstanceUnit::Mole);
        }

        [[nodiscard]] static constexpr AmountOfSubstance from_moles(const un_scalar_t value)
        {
            return AmountOfSubstance(value, AmountOfSubstanceUnit::Mole);
        }

        [[nodiscard]] constexpr un_scalar_t femtomoles() const
        {
            return convert_from_base(AmountOfSubstanceUnit::Femtomole);
        }

        [[nodiscard]] static constexpr AmountOfSubstance from_femtomoles(const un_scalar_t value)
        {
            return AmountOfSubstance(value, AmountOfSubstanceUnit::Femtomole);
        }

        [[nodiscard]] constexpr un_scalar_t picomoles() const
        {
            return convert_from_base(AmountOfSubstanceUnit::Picomole);
        }

        [[nodiscard]] static constexpr AmountOfSubstance from_picomoles(const un_scalar_t value)
        {
            return AmountOfSubstance(value, AmountOfSubstanceUnit::Picomole);
        }

        [[nodiscard]] constexpr un_scalar_t nanomoles() const
        {
            return convert_from_base(AmountOfSubstanceUnit::Nanomole);
        }

        [[nodiscard]] static constexpr AmountOfSubstance from_nanomoles(const un_scalar_t value)
        {
            return AmountOfSubstance(value, AmountOfSubstanceUnit::Nanomole);
        }

        [[nodiscard]] constexpr un_scalar_t micromoles() const
        {
            return convert_from_base(AmountOfSubstanceUnit::Micromole);
        }

        [[nodiscard]] static constexpr AmountOfSubstance from_micromoles(const un_scalar_t value)
        {
            return AmountOfSubstance(value, AmountOfSubstanceUnit::Micromole);
        }

        [[nodiscard]] constexpr un_scalar_t millimoles() const
        {
            return convert_from_base(AmountOfSubstanceUnit::Millimole);
        }

        [[nodiscard]] static constexpr AmountOfSubstance from_millimoles(const un_scalar_t value)
        {
            return AmountOfSubstance(value, AmountOfSubstanceUnit::Millimole);
        }

        [[nodiscard]] constexpr un_scalar_t centimoles() const
        {
            return convert_from_base(AmountOfSubstanceUnit::Centimole);
        }

        [[nodiscard]] static constexpr AmountOfSubstance from_centimoles(const un_scalar_t value)
        {
            return AmountOfSubstance(value, AmountOfSubstanceUnit::Centimole);
        }

        [[nodiscard]] constexpr un_scalar_t decimoles() const
        {
            return convert_from_base(AmountOfSubstanceUnit::Decimole);
        }

        [[nodiscard]] static constexpr AmountOfSubstance from_decimoles(const un_scalar_t value)
        {
            return AmountOfSubstance(value, AmountOfSubstanceUnit::Decimole);
        }

        [[nodiscard]] constexpr un_scalar_t kilomoles() const
        {
            return convert_from_base(AmountOfSubstanceUnit::Kilomole);
        }

        [[nodiscard]] static constexpr AmountOfSubstance from_kilomoles(const un_scalar_t value)
        {
            return AmountOfSubstance(value, AmountOfSubstanceUnit::Kilomole);
        }

        [[nodiscard]] constexpr un_scalar_t megamoles() const
        {
            return convert_from_base(AmountOfSubstanceUnit::Megamole);
        }

        [[nodiscard]] static constexpr AmountOfSubstance from_megamoles(const un_scalar_t value)
        {
            return AmountOfSubstance(value, AmountOfSubstanceUnit::Megamole);
        }

        [[nodiscard]] constexpr un_scalar_t pound_moles() const
        {
            return convert_from_base(AmountOfSubstanceUnit::PoundMole);
        }

        [[nodiscard]] static constexpr AmountOfSubstance from_pound_moles(const un_scalar_t value)
        {
            return AmountOfSubstance(value, AmountOfSubstanceUnit::PoundMole);
        }

        [[nodiscard]] constexpr un_scalar_t nanopound_moles() const
        {
            return convert_from_base(AmountOfSubstanceUnit::NanopoundMole);
        }

        [[nodiscard]] static constexpr AmountOfSubstance from_nanopound_moles(const un_scalar_t value)
        {
            return AmountOfSubstance(value, AmountOfSubstanceUnit::NanopoundMole);
        }

        [[nodiscard]] constexpr un_scalar_t micropound_moles() const
        {
            return convert_from_base(AmountOfSubstanceUnit::MicropoundMole);
        }

        [[nodiscard]] static constexpr AmountOfSubstance from_micropound_moles(const un_scalar_t value)
        {
            return AmountOfSubstance(value, AmountOfSubstanceUnit::MicropoundMole);
        }

        [[nodiscard]] constexpr un_scalar_t millipound_moles() const
        {
            return convert_from_base(AmountOfSubstanceUnit::MillipoundMole);
        }

        [[nodiscard]] static constexpr AmountOfSubstance from_millipound_moles(const un_scalar_t value)
        {
            return AmountOfSubstance(value, AmountOfSubstanceUnit::MillipoundMole);
        }

        [[nodiscard]] constexpr un_scalar_t centipound_moles() const
        {
            return convert_from_base(AmountOfSubstanceUnit::CentipoundMole);
        }

        [[nodiscard]] static constexpr AmountOfSubstance from_centipound_moles(const un_scalar_t value)
        {
            return AmountOfSubstance(value, AmountOfSubstanceUnit::CentipoundMole);
        }

        [[nodiscard]] constexpr un_scalar_t decipound_moles() const
        {
            return convert_from_base(AmountOfSubstanceUnit::DecipoundMole);
        }

        [[nodiscard]] static constexpr AmountOfSubstance from_decipound_moles(const un_scalar_t value)
        {
            return AmountOfSubstance(value, AmountOfSubstanceUnit::DecipoundMole);
        }

        [[nodiscard]] constexpr un_scalar_t kilopound_moles() const
        {
            return convert_from_base(AmountOfSubstanceUnit::KilopoundMole);
        }

        [[nodiscard]] static constexpr AmountOfSubstance from_kilopound_moles(const un_scalar_t value)
        {
            return AmountOfSubstance(value, AmountOfSubstanceUnit::KilopoundMole);
        }

        [[nodiscard]] static constexpr AmountOfSubstance from_invalid()
        {
            return AmountOfSubstance(false);
        }
    private:
            
        [[nodiscard]] static constexpr un_scalar_t convert_to_base(un_scalar_t value, AmountOfSubstanceUnit unit)
        {
            switch (unit)
            {

            case AmountOfSubstanceUnit::Mole:
                return value;

            case AmountOfSubstanceUnit::Femtomole:
                return (value * static_cast<un_scalar_t>(1e-15));

            case AmountOfSubstanceUnit::Picomole:
                return (value * static_cast<un_scalar_t>(1e-12));

            case AmountOfSubstanceUnit::Nanomole:
                return (value * static_cast<un_scalar_t>(1e-9));

            case AmountOfSubstanceUnit::Micromole:
                return (value * static_cast<un_scalar_t>(1e-6));

            case AmountOfSubstanceUnit::Millimole:
                return (value * static_cast<un_scalar_t>(1e-3));

            case AmountOfSubstanceUnit::Centimole:
                return (value * static_cast<un_scalar_t>(1e-2));

            case AmountOfSubstanceUnit::Decimole:
                return (value * static_cast<un_scalar_t>(1e-1));

            case AmountOfSubstanceUnit::Kilomole:
                return (value * static_cast<un_scalar_t>(1e3));

            case AmountOfSubstanceUnit::Megamole:
                return (value * static_cast<un_scalar_t>(1e6));

            case AmountOfSubstanceUnit::PoundMole:
                return value * static_cast<un_scalar_t>(453.59237);

            case AmountOfSubstanceUnit::NanopoundMole:
                return (value * static_cast<un_scalar_t>(1e-9)) * static_cast<un_scalar_t>(453.59237);

            case AmountOfSubstanceUnit::MicropoundMole:
                return (value * static_cast<un_scalar_t>(1e-6)) * static_cast<un_scalar_t>(453.59237);

            case AmountOfSubstanceUnit::MillipoundMole:
                return (value * static_cast<un_scalar_t>(1e-3)) * static_cast<un_scalar_t>(453.59237);

            case AmountOfSubstanceUnit::CentipoundMole:
                return (value * static_cast<un_scalar_t>(1e-2)) * static_cast<un_scalar_t>(453.59237);

            case AmountOfSubstanceUnit::DecipoundMole:
                return (value * static_cast<un_scalar_t>(1e-1)) * static_cast<un_scalar_t>(453.59237);

            case AmountOfSubstanceUnit::KilopoundMole:
                return (value * static_cast<un_scalar_t>(1e3)) * static_cast<un_scalar_t>(453.59237);

            }

            throw std::invalid_argument("Unknown AmountOfSubstance unit.");
        }

        [[nodiscard]] constexpr un_scalar_t convert_from_base(const AmountOfSubstanceUnit unit) const
        {
            if(unit == value_unit_type_)
            {
                return value_;
            }
            
            auto base_value = convert_to_base(value_, value_unit_type_);
            
            switch (unit)
            {

            case AmountOfSubstanceUnit::Mole:
                return base_value;

            case AmountOfSubstanceUnit::Femtomole:
                return (base_value) / static_cast<un_scalar_t>(1e-15);

            case AmountOfSubstanceUnit::Picomole:
                return (base_value) / static_cast<un_scalar_t>(1e-12);

            case AmountOfSubstanceUnit::Nanomole:
                return (base_value) / static_cast<un_scalar_t>(1e-9);

            case AmountOfSubstanceUnit::Micromole:
                return (base_value) / static_cast<un_scalar_t>(1e-6);

            case AmountOfSubstanceUnit::Millimole:
                return (base_value) / static_cast<un_scalar_t>(1e-3);

            case AmountOfSubstanceUnit::Centimole:
                return (base_value) / static_cast<un_scalar_t>(1e-2);

            case AmountOfSubstanceUnit::Decimole:
                return (base_value) / static_cast<un_scalar_t>(1e-1);

            case AmountOfSubstanceUnit::Kilomole:
                return (base_value) / static_cast<un_scalar_t>(1e3);

            case AmountOfSubstanceUnit::Megamole:
                return (base_value) / static_cast<un_scalar_t>(1e6);

            case AmountOfSubstanceUnit::PoundMole:
                return base_value / static_cast<un_scalar_t>(453.59237);

            case AmountOfSubstanceUnit::NanopoundMole:
                return (base_value / static_cast<un_scalar_t>(453.59237)) / static_cast<un_scalar_t>(1e-9);

            case AmountOfSubstanceUnit::MicropoundMole:
                return (base_value / static_cast<un_scalar_t>(453.59237)) / static_cast<un_scalar_t>(1e-6);

            case AmountOfSubstanceUnit::MillipoundMole:
                return (base_value / static_cast<un_scalar_t>(453.59237)) / static_cast<un_scalar_t>(1e-3);

            case AmountOfSubstanceUnit::CentipoundMole:
                return (base_value / static_cast<un_scalar_t>(453.59237)) / static_cast<un_scalar_t>(1e-2);

            case AmountOfSubstanceUnit::DecipoundMole:
                return (base_value / static_cast<un_scalar_t>(453.59237)) / static_cast<un_scalar_t>(1e-1);

            case AmountOfSubstanceUnit::KilopoundMole:
                return (base_value / static_cast<un_scalar_t>(453.59237)) / static_cast<un_scalar_t>(1e3);

            }

            throw std::invalid_argument("Unknown AmountOfSubstance unit.");
        }

        un_scalar_t value_;
        AmountOfSubstanceUnit value_unit_type_;       
    };
}
