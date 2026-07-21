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
    enum class MassFractionUnit : std::uint8_t
    {
        DecimalFraction,
        GramPerGram,
        NanogramPerGram,
        MicrogramPerGram,
        MilligramPerGram,
        CentigramPerGram,
        DecigramPerGram,
        DecagramPerGram,
        HectogramPerGram,
        KilogramPerGram,
        GramPerKilogram,
        NanogramPerKilogram,
        MicrogramPerKilogram,
        MilligramPerKilogram,
        CentigramPerKilogram,
        DecigramPerKilogram,
        DecagramPerKilogram,
        HectogramPerKilogram,
        KilogramPerKilogram,
        Percent,
        PartPerThousand,
        PartPerMillion,
        PartPerBillion,
        PartPerTrillion,
    };

#if defined(UNITSNET_ENABLE_DTO) || defined(UNITSNET_ENABLE_NLOHMANN_JSON)
    /// <summary>A data-transfer representation of MassFraction.</summary>
    class MassFractionDto
    {
    public:
        constexpr MassFractionDto() noexcept
            : value{}, unit(MassFractionUnit::DecimalFraction)
        {
        }

        constexpr MassFractionDto(
            const un_scalar_t value,
            const MassFractionUnit unit) noexcept
            : value(value), unit(unit)
        {
        }

        /// <summary>The numeric value of the quantity.</summary>
        un_scalar_t value;

        /// <summary>The unit in which value is expressed.</summary>
        MassFractionUnit unit;

        /// <summary>The stable UnitsNet name used for cross-language serialization.</summary>
        [[nodiscard]] constexpr std::string_view unit_name() const noexcept
        {
            return magic_enum::enum_name(unit);
        }

        /// <summary>Converts a stable UnitsNet unit name to its strongly typed enum.</summary>
        [[nodiscard]] static constexpr MassFractionUnit unit_from_name(const std::string_view name)
        {
            const auto unit = magic_enum::enum_cast<MassFractionUnit>(name);
            if (unit.has_value())
            {
                return *unit;
            }

            throw std::invalid_argument("Unknown MassFraction unit name.");
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
        [[nodiscard]] static MassFractionDto from_json(const nlohmann::json& json)
        {
            return MassFractionDto(
                json.at("value").get<un_scalar_t>(),
                unit_from_name(json.at("unit").get<std::string>()));
        }
#endif
    };
#endif

    /// <summary>The mass fraction is defined as the mass of a constituent divided by the total mass of the mixture.</summary>
    class MassFraction : public UnitsNetBase
    {
    public:
        constexpr explicit MassFraction(
            const un_scalar_t value,
            const MassFractionUnit unit = MassFractionUnit::DecimalFraction)
        {
            value_ = value;
            value_unit_type_ = unit;
        }
                
        [[nodiscard]] constexpr un_scalar_t base_value() const noexcept
        {
            return convert_to_base(value_, value_unit_type_);    
        }

        [[nodiscard]] constexpr un_scalar_t value(const MassFractionUnit unit) const
        {
            return convert_from_base(unit);
        }

#if defined(UNITSNET_ENABLE_DTO) || defined(UNITSNET_ENABLE_NLOHMANN_JSON)
        /// <summary>Creates a DTO, expressed in the requested unit.</summary>
        [[nodiscard]] constexpr MassFractionDto to_dto(
            const MassFractionUnit unit = MassFractionUnit::DecimalFraction) const
        {
            return MassFractionDto(value(unit), unit);
        }

        /// <summary>Creates a quantity from its DTO representation.</summary>
        [[nodiscard]] static constexpr MassFraction from_dto(const MassFractionDto& dto)
        {
            return MassFraction(dto.value, dto.unit);
        }

#ifdef UNITSNET_ENABLE_NLOHMANN_JSON
        /// <summary>Serializes this quantity to a nlohmann JSON object.</summary>
        [[nodiscard]] nlohmann::json to_json(
            const MassFractionUnit unit = MassFractionUnit::DecimalFraction) const
        {
            return to_dto(unit).to_json();
        }

        /// <summary>Creates a quantity from a nlohmann JSON object.</summary>
        [[nodiscard]] static MassFraction from_json(const nlohmann::json& json)
        {
            return from_dto(MassFractionDto::from_json(json));
        }
#endif
#endif

        [[nodiscard]] constexpr MassFraction operator+(const MassFraction& other) const noexcept
        {
            return MassFraction(base_value() + other.base_value());
        }

        [[nodiscard]] constexpr MassFraction operator-(const MassFraction& other)const noexcept
        {
            return MassFraction(base_value() - other.base_value());
        }

        [[nodiscard]] constexpr MassFraction operator*(const un_scalar_t scalar) const noexcept
        {
            return MassFraction(base_value() * scalar);
        }

        [[nodiscard]] constexpr MassFraction operator/(const un_scalar_t scalar) const noexcept
        {
            return MassFraction(base_value() / scalar);
        }

        [[nodiscard]] constexpr bool operator==(const MassFraction& other) const noexcept
        {
            return base_value() == other.base_value();
        }

        [[nodiscard]] constexpr bool operator<(const MassFraction& other) const noexcept
        {
            return base_value() < other.base_value();
        }
        
        [[nodiscard]] constexpr bool operator>(const MassFraction& other) const noexcept
        {
            return base_value() > other.base_value();
        }

        [[nodiscard]] constexpr un_scalar_t decimal_fractions() const
        {
            return convert_from_base(MassFractionUnit::DecimalFraction);
        }

        [[nodiscard]] static constexpr MassFraction from_decimal_fractions(const un_scalar_t value)
        {
            return MassFraction(value, MassFractionUnit::DecimalFraction);
        }

        [[nodiscard]] constexpr un_scalar_t grams_per_gram() const
        {
            return convert_from_base(MassFractionUnit::GramPerGram);
        }

        [[nodiscard]] static constexpr MassFraction from_grams_per_gram(const un_scalar_t value)
        {
            return MassFraction(value, MassFractionUnit::GramPerGram);
        }

        [[nodiscard]] constexpr un_scalar_t nanograms_per_gram() const
        {
            return convert_from_base(MassFractionUnit::NanogramPerGram);
        }

        [[nodiscard]] static constexpr MassFraction from_nanograms_per_gram(const un_scalar_t value)
        {
            return MassFraction(value, MassFractionUnit::NanogramPerGram);
        }

        [[nodiscard]] constexpr un_scalar_t micrograms_per_gram() const
        {
            return convert_from_base(MassFractionUnit::MicrogramPerGram);
        }

        [[nodiscard]] static constexpr MassFraction from_micrograms_per_gram(const un_scalar_t value)
        {
            return MassFraction(value, MassFractionUnit::MicrogramPerGram);
        }

        [[nodiscard]] constexpr un_scalar_t milligrams_per_gram() const
        {
            return convert_from_base(MassFractionUnit::MilligramPerGram);
        }

        [[nodiscard]] static constexpr MassFraction from_milligrams_per_gram(const un_scalar_t value)
        {
            return MassFraction(value, MassFractionUnit::MilligramPerGram);
        }

        [[nodiscard]] constexpr un_scalar_t centigrams_per_gram() const
        {
            return convert_from_base(MassFractionUnit::CentigramPerGram);
        }

        [[nodiscard]] static constexpr MassFraction from_centigrams_per_gram(const un_scalar_t value)
        {
            return MassFraction(value, MassFractionUnit::CentigramPerGram);
        }

        [[nodiscard]] constexpr un_scalar_t decigrams_per_gram() const
        {
            return convert_from_base(MassFractionUnit::DecigramPerGram);
        }

        [[nodiscard]] static constexpr MassFraction from_decigrams_per_gram(const un_scalar_t value)
        {
            return MassFraction(value, MassFractionUnit::DecigramPerGram);
        }

        [[nodiscard]] constexpr un_scalar_t decagrams_per_gram() const
        {
            return convert_from_base(MassFractionUnit::DecagramPerGram);
        }

        [[nodiscard]] static constexpr MassFraction from_decagrams_per_gram(const un_scalar_t value)
        {
            return MassFraction(value, MassFractionUnit::DecagramPerGram);
        }

        [[nodiscard]] constexpr un_scalar_t hectograms_per_gram() const
        {
            return convert_from_base(MassFractionUnit::HectogramPerGram);
        }

        [[nodiscard]] static constexpr MassFraction from_hectograms_per_gram(const un_scalar_t value)
        {
            return MassFraction(value, MassFractionUnit::HectogramPerGram);
        }

        [[nodiscard]] constexpr un_scalar_t kilograms_per_gram() const
        {
            return convert_from_base(MassFractionUnit::KilogramPerGram);
        }

        [[nodiscard]] static constexpr MassFraction from_kilograms_per_gram(const un_scalar_t value)
        {
            return MassFraction(value, MassFractionUnit::KilogramPerGram);
        }

        [[nodiscard]] constexpr un_scalar_t grams_per_kilogram() const
        {
            return convert_from_base(MassFractionUnit::GramPerKilogram);
        }

        [[nodiscard]] static constexpr MassFraction from_grams_per_kilogram(const un_scalar_t value)
        {
            return MassFraction(value, MassFractionUnit::GramPerKilogram);
        }

        [[nodiscard]] constexpr un_scalar_t nanograms_per_kilogram() const
        {
            return convert_from_base(MassFractionUnit::NanogramPerKilogram);
        }

        [[nodiscard]] static constexpr MassFraction from_nanograms_per_kilogram(const un_scalar_t value)
        {
            return MassFraction(value, MassFractionUnit::NanogramPerKilogram);
        }

        [[nodiscard]] constexpr un_scalar_t micrograms_per_kilogram() const
        {
            return convert_from_base(MassFractionUnit::MicrogramPerKilogram);
        }

        [[nodiscard]] static constexpr MassFraction from_micrograms_per_kilogram(const un_scalar_t value)
        {
            return MassFraction(value, MassFractionUnit::MicrogramPerKilogram);
        }

        [[nodiscard]] constexpr un_scalar_t milligrams_per_kilogram() const
        {
            return convert_from_base(MassFractionUnit::MilligramPerKilogram);
        }

        [[nodiscard]] static constexpr MassFraction from_milligrams_per_kilogram(const un_scalar_t value)
        {
            return MassFraction(value, MassFractionUnit::MilligramPerKilogram);
        }

        [[nodiscard]] constexpr un_scalar_t centigrams_per_kilogram() const
        {
            return convert_from_base(MassFractionUnit::CentigramPerKilogram);
        }

        [[nodiscard]] static constexpr MassFraction from_centigrams_per_kilogram(const un_scalar_t value)
        {
            return MassFraction(value, MassFractionUnit::CentigramPerKilogram);
        }

        [[nodiscard]] constexpr un_scalar_t decigrams_per_kilogram() const
        {
            return convert_from_base(MassFractionUnit::DecigramPerKilogram);
        }

        [[nodiscard]] static constexpr MassFraction from_decigrams_per_kilogram(const un_scalar_t value)
        {
            return MassFraction(value, MassFractionUnit::DecigramPerKilogram);
        }

        [[nodiscard]] constexpr un_scalar_t decagrams_per_kilogram() const
        {
            return convert_from_base(MassFractionUnit::DecagramPerKilogram);
        }

        [[nodiscard]] static constexpr MassFraction from_decagrams_per_kilogram(const un_scalar_t value)
        {
            return MassFraction(value, MassFractionUnit::DecagramPerKilogram);
        }

        [[nodiscard]] constexpr un_scalar_t hectograms_per_kilogram() const
        {
            return convert_from_base(MassFractionUnit::HectogramPerKilogram);
        }

        [[nodiscard]] static constexpr MassFraction from_hectograms_per_kilogram(const un_scalar_t value)
        {
            return MassFraction(value, MassFractionUnit::HectogramPerKilogram);
        }

        [[nodiscard]] constexpr un_scalar_t kilograms_per_kilogram() const
        {
            return convert_from_base(MassFractionUnit::KilogramPerKilogram);
        }

        [[nodiscard]] static constexpr MassFraction from_kilograms_per_kilogram(const un_scalar_t value)
        {
            return MassFraction(value, MassFractionUnit::KilogramPerKilogram);
        }

        [[nodiscard]] constexpr un_scalar_t percent() const
        {
            return convert_from_base(MassFractionUnit::Percent);
        }

        [[nodiscard]] static constexpr MassFraction from_percent(const un_scalar_t value)
        {
            return MassFraction(value, MassFractionUnit::Percent);
        }

        [[nodiscard]] constexpr un_scalar_t parts_per_thousand() const
        {
            return convert_from_base(MassFractionUnit::PartPerThousand);
        }

        [[nodiscard]] static constexpr MassFraction from_parts_per_thousand(const un_scalar_t value)
        {
            return MassFraction(value, MassFractionUnit::PartPerThousand);
        }

        [[nodiscard]] constexpr un_scalar_t parts_per_million() const
        {
            return convert_from_base(MassFractionUnit::PartPerMillion);
        }

        [[nodiscard]] static constexpr MassFraction from_parts_per_million(const un_scalar_t value)
        {
            return MassFraction(value, MassFractionUnit::PartPerMillion);
        }

        [[nodiscard]] constexpr un_scalar_t parts_per_billion() const
        {
            return convert_from_base(MassFractionUnit::PartPerBillion);
        }

        [[nodiscard]] static constexpr MassFraction from_parts_per_billion(const un_scalar_t value)
        {
            return MassFraction(value, MassFractionUnit::PartPerBillion);
        }

        [[nodiscard]] constexpr un_scalar_t parts_per_trillion() const
        {
            return convert_from_base(MassFractionUnit::PartPerTrillion);
        }

        [[nodiscard]] static constexpr MassFraction from_parts_per_trillion(const un_scalar_t value)
        {
            return MassFraction(value, MassFractionUnit::PartPerTrillion);
        }

        [[nodiscard]] static constexpr MassFraction from_invalid()
        {
            return MassFraction(false);
        }
    private:
            
        [[nodiscard]] static constexpr un_scalar_t convert_to_base(un_scalar_t value, MassFractionUnit unit)
        {
            switch (unit)
            {

            case MassFractionUnit::DecimalFraction:
                return value;

            case MassFractionUnit::GramPerGram:
                return value;

            case MassFractionUnit::NanogramPerGram:
                return (value * static_cast<un_scalar_t>(1e-9));

            case MassFractionUnit::MicrogramPerGram:
                return (value * static_cast<un_scalar_t>(1e-6));

            case MassFractionUnit::MilligramPerGram:
                return (value * static_cast<un_scalar_t>(1e-3));

            case MassFractionUnit::CentigramPerGram:
                return (value * static_cast<un_scalar_t>(1e-2));

            case MassFractionUnit::DecigramPerGram:
                return (value * static_cast<un_scalar_t>(1e-1));

            case MassFractionUnit::DecagramPerGram:
                return (value * static_cast<un_scalar_t>(1e1));

            case MassFractionUnit::HectogramPerGram:
                return (value * static_cast<un_scalar_t>(1e2));

            case MassFractionUnit::KilogramPerGram:
                return (value * static_cast<un_scalar_t>(1e3));

            case MassFractionUnit::GramPerKilogram:
                return value / static_cast<un_scalar_t>(1e3);

            case MassFractionUnit::NanogramPerKilogram:
                return (value * static_cast<un_scalar_t>(1e-9)) / static_cast<un_scalar_t>(1e3);

            case MassFractionUnit::MicrogramPerKilogram:
                return (value * static_cast<un_scalar_t>(1e-6)) / static_cast<un_scalar_t>(1e3);

            case MassFractionUnit::MilligramPerKilogram:
                return (value * static_cast<un_scalar_t>(1e-3)) / static_cast<un_scalar_t>(1e3);

            case MassFractionUnit::CentigramPerKilogram:
                return (value * static_cast<un_scalar_t>(1e-2)) / static_cast<un_scalar_t>(1e3);

            case MassFractionUnit::DecigramPerKilogram:
                return (value * static_cast<un_scalar_t>(1e-1)) / static_cast<un_scalar_t>(1e3);

            case MassFractionUnit::DecagramPerKilogram:
                return (value * static_cast<un_scalar_t>(1e1)) / static_cast<un_scalar_t>(1e3);

            case MassFractionUnit::HectogramPerKilogram:
                return (value * static_cast<un_scalar_t>(1e2)) / static_cast<un_scalar_t>(1e3);

            case MassFractionUnit::KilogramPerKilogram:
                return (value * static_cast<un_scalar_t>(1e3)) / static_cast<un_scalar_t>(1e3);

            case MassFractionUnit::Percent:
                return value / static_cast<un_scalar_t>(1e2);

            case MassFractionUnit::PartPerThousand:
                return value / static_cast<un_scalar_t>(1e3);

            case MassFractionUnit::PartPerMillion:
                return value / static_cast<un_scalar_t>(1e6);

            case MassFractionUnit::PartPerBillion:
                return value / static_cast<un_scalar_t>(1e9);

            case MassFractionUnit::PartPerTrillion:
                return value / static_cast<un_scalar_t>(1e12);

            }

            throw std::invalid_argument("Unknown MassFraction unit.");
        }

        [[nodiscard]] constexpr un_scalar_t convert_from_base(const MassFractionUnit unit) const
        {
            if(unit == value_unit_type_)
            {
                return value_;
            }
            
            auto base_value = convert_to_base(value_, value_unit_type_);
            
            switch (unit)
            {

            case MassFractionUnit::DecimalFraction:
                return base_value;

            case MassFractionUnit::GramPerGram:
                return base_value;

            case MassFractionUnit::NanogramPerGram:
                return (base_value) / static_cast<un_scalar_t>(1e-9);

            case MassFractionUnit::MicrogramPerGram:
                return (base_value) / static_cast<un_scalar_t>(1e-6);

            case MassFractionUnit::MilligramPerGram:
                return (base_value) / static_cast<un_scalar_t>(1e-3);

            case MassFractionUnit::CentigramPerGram:
                return (base_value) / static_cast<un_scalar_t>(1e-2);

            case MassFractionUnit::DecigramPerGram:
                return (base_value) / static_cast<un_scalar_t>(1e-1);

            case MassFractionUnit::DecagramPerGram:
                return (base_value) / static_cast<un_scalar_t>(1e1);

            case MassFractionUnit::HectogramPerGram:
                return (base_value) / static_cast<un_scalar_t>(1e2);

            case MassFractionUnit::KilogramPerGram:
                return (base_value) / static_cast<un_scalar_t>(1e3);

            case MassFractionUnit::GramPerKilogram:
                return base_value * static_cast<un_scalar_t>(1e3);

            case MassFractionUnit::NanogramPerKilogram:
                return (base_value * static_cast<un_scalar_t>(1e3)) / static_cast<un_scalar_t>(1e-9);

            case MassFractionUnit::MicrogramPerKilogram:
                return (base_value * static_cast<un_scalar_t>(1e3)) / static_cast<un_scalar_t>(1e-6);

            case MassFractionUnit::MilligramPerKilogram:
                return (base_value * static_cast<un_scalar_t>(1e3)) / static_cast<un_scalar_t>(1e-3);

            case MassFractionUnit::CentigramPerKilogram:
                return (base_value * static_cast<un_scalar_t>(1e3)) / static_cast<un_scalar_t>(1e-2);

            case MassFractionUnit::DecigramPerKilogram:
                return (base_value * static_cast<un_scalar_t>(1e3)) / static_cast<un_scalar_t>(1e-1);

            case MassFractionUnit::DecagramPerKilogram:
                return (base_value * static_cast<un_scalar_t>(1e3)) / static_cast<un_scalar_t>(1e1);

            case MassFractionUnit::HectogramPerKilogram:
                return (base_value * static_cast<un_scalar_t>(1e3)) / static_cast<un_scalar_t>(1e2);

            case MassFractionUnit::KilogramPerKilogram:
                return (base_value * static_cast<un_scalar_t>(1e3)) / static_cast<un_scalar_t>(1e3);

            case MassFractionUnit::Percent:
                return base_value * static_cast<un_scalar_t>(1e2);

            case MassFractionUnit::PartPerThousand:
                return base_value * static_cast<un_scalar_t>(1e3);

            case MassFractionUnit::PartPerMillion:
                return base_value * static_cast<un_scalar_t>(1e6);

            case MassFractionUnit::PartPerBillion:
                return base_value * static_cast<un_scalar_t>(1e9);

            case MassFractionUnit::PartPerTrillion:
                return base_value * static_cast<un_scalar_t>(1e12);

            }

            throw std::invalid_argument("Unknown MassFraction unit.");
        }

        un_scalar_t value_;
        MassFractionUnit value_unit_type_;       
    };
}
