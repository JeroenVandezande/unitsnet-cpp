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
    enum class MolarMassUnit : std::uint8_t
    {
        GramPerMole,
        NanogramPerMole,
        MicrogramPerMole,
        MilligramPerMole,
        CentigramPerMole,
        DecigramPerMole,
        DecagramPerMole,
        HectogramPerMole,
        KilogramPerMole,
        KilogramPerKilomole,
        PoundPerMole,
        KilopoundPerMole,
        MegapoundPerMole,
    };

#if defined(UNITSNET_ENABLE_DTO) || defined(UNITSNET_ENABLE_NLOHMANN_JSON)
    /// <summary>A data-transfer representation of MolarMass.</summary>
    class MolarMassDto
    {
    public:
        constexpr MolarMassDto() noexcept
            : value{}, unit(MolarMassUnit::KilogramPerMole)
        {
        }

        constexpr MolarMassDto(
            const un_scalar_t value,
            const MolarMassUnit unit) noexcept
            : value(value), unit(unit)
        {
        }

        /// <summary>The numeric value of the quantity.</summary>
        un_scalar_t value;

        /// <summary>The unit in which value is expressed.</summary>
        MolarMassUnit unit;

        /// <summary>The stable UnitsNet name used for cross-language serialization.</summary>
        [[nodiscard]] constexpr std::string_view unit_name() const noexcept
        {
            return magic_enum::enum_name(unit);
        }

        /// <summary>Converts a stable UnitsNet unit name to its strongly typed enum.</summary>
        [[nodiscard]] static constexpr MolarMassUnit unit_from_name(const std::string_view name)
        {
            const auto unit = magic_enum::enum_cast<MolarMassUnit>(name);
            if (unit.has_value())
            {
                return *unit;
            }

            throw std::invalid_argument("Unknown MolarMass unit name.");
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
        [[nodiscard]] static MolarMassDto from_json(const nlohmann::json& json)
        {
            return MolarMassDto(
                json.at("value").get<un_scalar_t>(),
                unit_from_name(json.at("unit").get<std::string>()));
        }
#endif
    };
#endif

    /// <summary>In chemistry, the molar mass M is a physical property defined as the mass of a given substance (chemical element or chemical compound) divided by the amount of substance.</summary>
    class MolarMass : public UnitsNetBase
    {
    public:
        constexpr explicit MolarMass(
            const un_scalar_t value,
            const MolarMassUnit unit = MolarMassUnit::KilogramPerMole)
        {
            value_ = value;
            value_unit_type_ = unit;
        }
                
        [[nodiscard]] constexpr un_scalar_t base_value() const noexcept
        {
            return convert_to_base(value_, value_unit_type_);    
        }

        [[nodiscard]] constexpr un_scalar_t value(const MolarMassUnit unit) const
        {
            return convert_from_base(unit);
        }

#if defined(UNITSNET_ENABLE_DTO) || defined(UNITSNET_ENABLE_NLOHMANN_JSON)
        /// <summary>Creates a DTO, expressed in the requested unit.</summary>
        [[nodiscard]] constexpr MolarMassDto to_dto(
            const MolarMassUnit unit = MolarMassUnit::KilogramPerMole) const
        {
            return MolarMassDto(value(unit), unit);
        }

        /// <summary>Creates a quantity from its DTO representation.</summary>
        [[nodiscard]] static constexpr MolarMass from_dto(const MolarMassDto& dto)
        {
            return MolarMass(dto.value, dto.unit);
        }

#ifdef UNITSNET_ENABLE_NLOHMANN_JSON
        /// <summary>Serializes this quantity to a nlohmann JSON object.</summary>
        [[nodiscard]] nlohmann::json to_json(
            const MolarMassUnit unit = MolarMassUnit::KilogramPerMole) const
        {
            return to_dto(unit).to_json();
        }

        /// <summary>Creates a quantity from a nlohmann JSON object.</summary>
        [[nodiscard]] static MolarMass from_json(const nlohmann::json& json)
        {
            return from_dto(MolarMassDto::from_json(json));
        }
#endif
#endif

        [[nodiscard]] constexpr MolarMass operator+(const MolarMass& other) const noexcept
        {
            return MolarMass(base_value() + other.base_value());
        }

        [[nodiscard]] constexpr MolarMass operator-(const MolarMass& other)const noexcept
        {
            return MolarMass(base_value() - other.base_value());
        }

        [[nodiscard]] constexpr MolarMass operator*(const un_scalar_t scalar) const noexcept
        {
            return MolarMass(base_value() * scalar);
        }

        [[nodiscard]] constexpr MolarMass operator/(const un_scalar_t scalar) const noexcept
        {
            return MolarMass(base_value() / scalar);
        }

        [[nodiscard]] constexpr bool operator==(const MolarMass& other) const noexcept
        {
            return base_value() == other.base_value();
        }

        [[nodiscard]] constexpr bool operator<(const MolarMass& other) const noexcept
        {
            return base_value() < other.base_value();
        }
        
        [[nodiscard]] constexpr bool operator>(const MolarMass& other) const noexcept
        {
            return base_value() > other.base_value();
        }

        [[nodiscard]] constexpr un_scalar_t grams_per_mole() const
        {
            return convert_from_base(MolarMassUnit::GramPerMole);
        }

        [[nodiscard]] static constexpr MolarMass from_grams_per_mole(const un_scalar_t value)
        {
            return MolarMass(value, MolarMassUnit::GramPerMole);
        }

        [[nodiscard]] constexpr un_scalar_t nanograms_per_mole() const
        {
            return convert_from_base(MolarMassUnit::NanogramPerMole);
        }

        [[nodiscard]] static constexpr MolarMass from_nanograms_per_mole(const un_scalar_t value)
        {
            return MolarMass(value, MolarMassUnit::NanogramPerMole);
        }

        [[nodiscard]] constexpr un_scalar_t micrograms_per_mole() const
        {
            return convert_from_base(MolarMassUnit::MicrogramPerMole);
        }

        [[nodiscard]] static constexpr MolarMass from_micrograms_per_mole(const un_scalar_t value)
        {
            return MolarMass(value, MolarMassUnit::MicrogramPerMole);
        }

        [[nodiscard]] constexpr un_scalar_t milligrams_per_mole() const
        {
            return convert_from_base(MolarMassUnit::MilligramPerMole);
        }

        [[nodiscard]] static constexpr MolarMass from_milligrams_per_mole(const un_scalar_t value)
        {
            return MolarMass(value, MolarMassUnit::MilligramPerMole);
        }

        [[nodiscard]] constexpr un_scalar_t centigrams_per_mole() const
        {
            return convert_from_base(MolarMassUnit::CentigramPerMole);
        }

        [[nodiscard]] static constexpr MolarMass from_centigrams_per_mole(const un_scalar_t value)
        {
            return MolarMass(value, MolarMassUnit::CentigramPerMole);
        }

        [[nodiscard]] constexpr un_scalar_t decigrams_per_mole() const
        {
            return convert_from_base(MolarMassUnit::DecigramPerMole);
        }

        [[nodiscard]] static constexpr MolarMass from_decigrams_per_mole(const un_scalar_t value)
        {
            return MolarMass(value, MolarMassUnit::DecigramPerMole);
        }

        [[nodiscard]] constexpr un_scalar_t decagrams_per_mole() const
        {
            return convert_from_base(MolarMassUnit::DecagramPerMole);
        }

        [[nodiscard]] static constexpr MolarMass from_decagrams_per_mole(const un_scalar_t value)
        {
            return MolarMass(value, MolarMassUnit::DecagramPerMole);
        }

        [[nodiscard]] constexpr un_scalar_t hectograms_per_mole() const
        {
            return convert_from_base(MolarMassUnit::HectogramPerMole);
        }

        [[nodiscard]] static constexpr MolarMass from_hectograms_per_mole(const un_scalar_t value)
        {
            return MolarMass(value, MolarMassUnit::HectogramPerMole);
        }

        [[nodiscard]] constexpr un_scalar_t kilograms_per_mole() const
        {
            return convert_from_base(MolarMassUnit::KilogramPerMole);
        }

        [[nodiscard]] static constexpr MolarMass from_kilograms_per_mole(const un_scalar_t value)
        {
            return MolarMass(value, MolarMassUnit::KilogramPerMole);
        }

        [[nodiscard]] constexpr un_scalar_t kilograms_per_kilomole() const
        {
            return convert_from_base(MolarMassUnit::KilogramPerKilomole);
        }

        [[nodiscard]] static constexpr MolarMass from_kilograms_per_kilomole(const un_scalar_t value)
        {
            return MolarMass(value, MolarMassUnit::KilogramPerKilomole);
        }

        [[nodiscard]] constexpr un_scalar_t pounds_per_mole() const
        {
            return convert_from_base(MolarMassUnit::PoundPerMole);
        }

        [[nodiscard]] static constexpr MolarMass from_pounds_per_mole(const un_scalar_t value)
        {
            return MolarMass(value, MolarMassUnit::PoundPerMole);
        }

        [[nodiscard]] constexpr un_scalar_t kilopounds_per_mole() const
        {
            return convert_from_base(MolarMassUnit::KilopoundPerMole);
        }

        [[nodiscard]] static constexpr MolarMass from_kilopounds_per_mole(const un_scalar_t value)
        {
            return MolarMass(value, MolarMassUnit::KilopoundPerMole);
        }

        [[nodiscard]] constexpr un_scalar_t megapounds_per_mole() const
        {
            return convert_from_base(MolarMassUnit::MegapoundPerMole);
        }

        [[nodiscard]] static constexpr MolarMass from_megapounds_per_mole(const un_scalar_t value)
        {
            return MolarMass(value, MolarMassUnit::MegapoundPerMole);
        }

        [[nodiscard]] static constexpr MolarMass from_invalid()
        {
            return MolarMass(false);
        }
    private:
            
        [[nodiscard]] static constexpr un_scalar_t convert_to_base(un_scalar_t value, MolarMassUnit unit)
        {
            switch (unit)
            {

            case MolarMassUnit::GramPerMole:
                return value / static_cast<un_scalar_t>(1e3);

            case MolarMassUnit::NanogramPerMole:
                return (value * static_cast<un_scalar_t>(1e-9)) / static_cast<un_scalar_t>(1e3);

            case MolarMassUnit::MicrogramPerMole:
                return (value * static_cast<un_scalar_t>(1e-6)) / static_cast<un_scalar_t>(1e3);

            case MolarMassUnit::MilligramPerMole:
                return (value * static_cast<un_scalar_t>(1e-3)) / static_cast<un_scalar_t>(1e3);

            case MolarMassUnit::CentigramPerMole:
                return (value * static_cast<un_scalar_t>(1e-2)) / static_cast<un_scalar_t>(1e3);

            case MolarMassUnit::DecigramPerMole:
                return (value * static_cast<un_scalar_t>(1e-1)) / static_cast<un_scalar_t>(1e3);

            case MolarMassUnit::DecagramPerMole:
                return (value * static_cast<un_scalar_t>(1e1)) / static_cast<un_scalar_t>(1e3);

            case MolarMassUnit::HectogramPerMole:
                return (value * static_cast<un_scalar_t>(1e2)) / static_cast<un_scalar_t>(1e3);

            case MolarMassUnit::KilogramPerMole:
                return (value * static_cast<un_scalar_t>(1e3)) / static_cast<un_scalar_t>(1e3);

            case MolarMassUnit::KilogramPerKilomole:
                return value / static_cast<un_scalar_t>(1e3);

            case MolarMassUnit::PoundPerMole:
                return value * static_cast<un_scalar_t>(0.45359237);

            case MolarMassUnit::KilopoundPerMole:
                return (value * static_cast<un_scalar_t>(1e3)) * static_cast<un_scalar_t>(0.45359237);

            case MolarMassUnit::MegapoundPerMole:
                return (value * static_cast<un_scalar_t>(1e6)) * static_cast<un_scalar_t>(0.45359237);

            }

            throw std::invalid_argument("Unknown MolarMass unit.");
        }

        [[nodiscard]] constexpr un_scalar_t convert_from_base(const MolarMassUnit unit) const
        {
            if(unit == value_unit_type_)
            {
                return value_;
            }
            
            auto base_value = convert_to_base(value_, value_unit_type_);
            
            switch (unit)
            {

            case MolarMassUnit::GramPerMole:
                return base_value * static_cast<un_scalar_t>(1e3);

            case MolarMassUnit::NanogramPerMole:
                return (base_value * static_cast<un_scalar_t>(1e3)) / static_cast<un_scalar_t>(1e-9);

            case MolarMassUnit::MicrogramPerMole:
                return (base_value * static_cast<un_scalar_t>(1e3)) / static_cast<un_scalar_t>(1e-6);

            case MolarMassUnit::MilligramPerMole:
                return (base_value * static_cast<un_scalar_t>(1e3)) / static_cast<un_scalar_t>(1e-3);

            case MolarMassUnit::CentigramPerMole:
                return (base_value * static_cast<un_scalar_t>(1e3)) / static_cast<un_scalar_t>(1e-2);

            case MolarMassUnit::DecigramPerMole:
                return (base_value * static_cast<un_scalar_t>(1e3)) / static_cast<un_scalar_t>(1e-1);

            case MolarMassUnit::DecagramPerMole:
                return (base_value * static_cast<un_scalar_t>(1e3)) / static_cast<un_scalar_t>(1e1);

            case MolarMassUnit::HectogramPerMole:
                return (base_value * static_cast<un_scalar_t>(1e3)) / static_cast<un_scalar_t>(1e2);

            case MolarMassUnit::KilogramPerMole:
                return (base_value * static_cast<un_scalar_t>(1e3)) / static_cast<un_scalar_t>(1e3);

            case MolarMassUnit::KilogramPerKilomole:
                return base_value * static_cast<un_scalar_t>(1e3);

            case MolarMassUnit::PoundPerMole:
                return base_value / static_cast<un_scalar_t>(0.45359237);

            case MolarMassUnit::KilopoundPerMole:
                return (base_value / static_cast<un_scalar_t>(0.45359237)) / static_cast<un_scalar_t>(1e3);

            case MolarMassUnit::MegapoundPerMole:
                return (base_value / static_cast<un_scalar_t>(0.45359237)) / static_cast<un_scalar_t>(1e6);

            }

            throw std::invalid_argument("Unknown MolarMass unit.");
        }

        un_scalar_t value_;
        MolarMassUnit value_unit_type_;       
    };
}
