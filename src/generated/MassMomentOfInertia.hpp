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
    enum class MassMomentOfInertiaUnit : std::uint8_t
    {
        GramSquareMeter,
        MilligramSquareMeter,
        KilogramSquareMeter,
        GramSquareDecimeter,
        MilligramSquareDecimeter,
        KilogramSquareDecimeter,
        GramSquareCentimeter,
        MilligramSquareCentimeter,
        KilogramSquareCentimeter,
        GramSquareMillimeter,
        MilligramSquareMillimeter,
        KilogramSquareMillimeter,
        TonneSquareMeter,
        KilotonneSquareMeter,
        MegatonneSquareMeter,
        TonneSquareDecimeter,
        KilotonneSquareDecimeter,
        MegatonneSquareDecimeter,
        TonneSquareCentimeter,
        KilotonneSquareCentimeter,
        MegatonneSquareCentimeter,
        TonneSquareMillimeter,
        KilotonneSquareMillimeter,
        MegatonneSquareMillimeter,
        PoundSquareFoot,
        PoundSquareInch,
        SlugSquareFoot,
        SlugSquareInch,
    };

#if defined(UNITSNET_ENABLE_DTO) || defined(UNITSNET_ENABLE_NLOHMANN_JSON)
    /// <summary>A data-transfer representation of MassMomentOfInertia.</summary>
    class MassMomentOfInertiaDto
    {
    public:
        constexpr MassMomentOfInertiaDto() noexcept
            : value{}, unit(MassMomentOfInertiaUnit::KilogramSquareMeter)
        {
        }

        constexpr MassMomentOfInertiaDto(
            const un_scalar_t value,
            const MassMomentOfInertiaUnit unit) noexcept
            : value(value), unit(unit)
        {
        }

        /// <summary>The numeric value of the quantity.</summary>
        un_scalar_t value;

        /// <summary>The unit in which value is expressed.</summary>
        MassMomentOfInertiaUnit unit;

        /// <summary>The stable UnitsNet name used for cross-language serialization.</summary>
        [[nodiscard]] constexpr std::string_view unit_name() const noexcept
        {
            return magic_enum::enum_name(unit);
        }

        /// <summary>Converts a stable UnitsNet unit name to its strongly typed enum.</summary>
        [[nodiscard]] static constexpr MassMomentOfInertiaUnit unit_from_name(const std::string_view name)
        {
            const auto unit = magic_enum::enum_cast<MassMomentOfInertiaUnit>(name);
            if (unit.has_value())
            {
                return *unit;
            }

            throw std::invalid_argument("Unknown MassMomentOfInertia unit name.");
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
        [[nodiscard]] static MassMomentOfInertiaDto from_json(const nlohmann::json& json)
        {
            return MassMomentOfInertiaDto(
                json.at("value").get<un_scalar_t>(),
                unit_from_name(json.at("unit").get<std::string>()));
        }
#endif
    };
#endif

    /// <summary>A property of body reflects how its mass is distributed with regard to an axis.</summary>
    class MassMomentOfInertia : public UnitsNetBase
    {
    public:
        constexpr explicit MassMomentOfInertia(
            const un_scalar_t value,
            const MassMomentOfInertiaUnit unit = MassMomentOfInertiaUnit::KilogramSquareMeter)
        {
            value_ = value;
            value_unit_type_ = unit;
        }
                
        [[nodiscard]] constexpr un_scalar_t base_value() const noexcept
        {
            return convert_to_base(value_, value_unit_type_);    
        }

        [[nodiscard]] constexpr un_scalar_t value(const MassMomentOfInertiaUnit unit) const
        {
            return convert_from_base(unit);
        }

#if defined(UNITSNET_ENABLE_DTO) || defined(UNITSNET_ENABLE_NLOHMANN_JSON)
        /// <summary>Creates a DTO, expressed in the requested unit.</summary>
        [[nodiscard]] constexpr MassMomentOfInertiaDto to_dto(
            const MassMomentOfInertiaUnit unit = MassMomentOfInertiaUnit::KilogramSquareMeter) const
        {
            return MassMomentOfInertiaDto(value(unit), unit);
        }

        /// <summary>Creates a quantity from its DTO representation.</summary>
        [[nodiscard]] static constexpr MassMomentOfInertia from_dto(const MassMomentOfInertiaDto& dto)
        {
            return MassMomentOfInertia(dto.value, dto.unit);
        }

#ifdef UNITSNET_ENABLE_NLOHMANN_JSON
        /// <summary>Serializes this quantity to a nlohmann JSON object.</summary>
        [[nodiscard]] nlohmann::json to_json(
            const MassMomentOfInertiaUnit unit = MassMomentOfInertiaUnit::KilogramSquareMeter) const
        {
            return to_dto(unit).to_json();
        }

        /// <summary>Creates a quantity from a nlohmann JSON object.</summary>
        [[nodiscard]] static MassMomentOfInertia from_json(const nlohmann::json& json)
        {
            return from_dto(MassMomentOfInertiaDto::from_json(json));
        }
#endif
#endif

        [[nodiscard]] constexpr MassMomentOfInertia operator+(const MassMomentOfInertia& other) const noexcept
        {
            return MassMomentOfInertia(base_value() + other.base_value());
        }

        [[nodiscard]] constexpr MassMomentOfInertia operator-(const MassMomentOfInertia& other)const noexcept
        {
            return MassMomentOfInertia(base_value() - other.base_value());
        }

        [[nodiscard]] constexpr MassMomentOfInertia operator*(const un_scalar_t scalar) const noexcept
        {
            return MassMomentOfInertia(base_value() * scalar);
        }

        [[nodiscard]] constexpr MassMomentOfInertia operator/(const un_scalar_t scalar) const noexcept
        {
            return MassMomentOfInertia(base_value() / scalar);
        }

        [[nodiscard]] constexpr bool operator==(const MassMomentOfInertia& other) const noexcept
        {
            return base_value() == other.base_value();
        }

        [[nodiscard]] constexpr bool operator<(const MassMomentOfInertia& other) const noexcept
        {
            return base_value() < other.base_value();
        }
        
        [[nodiscard]] constexpr bool operator>(const MassMomentOfInertia& other) const noexcept
        {
            return base_value() > other.base_value();
        }

        [[nodiscard]] constexpr un_scalar_t gram_square_meters() const
        {
            return convert_from_base(MassMomentOfInertiaUnit::GramSquareMeter);
        }

        [[nodiscard]] static constexpr MassMomentOfInertia from_gram_square_meters(const un_scalar_t value)
        {
            return MassMomentOfInertia(value, MassMomentOfInertiaUnit::GramSquareMeter);
        }

        [[nodiscard]] constexpr un_scalar_t milligram_square_meters() const
        {
            return convert_from_base(MassMomentOfInertiaUnit::MilligramSquareMeter);
        }

        [[nodiscard]] static constexpr MassMomentOfInertia from_milligram_square_meters(const un_scalar_t value)
        {
            return MassMomentOfInertia(value, MassMomentOfInertiaUnit::MilligramSquareMeter);
        }

        [[nodiscard]] constexpr un_scalar_t kilogram_square_meters() const
        {
            return convert_from_base(MassMomentOfInertiaUnit::KilogramSquareMeter);
        }

        [[nodiscard]] static constexpr MassMomentOfInertia from_kilogram_square_meters(const un_scalar_t value)
        {
            return MassMomentOfInertia(value, MassMomentOfInertiaUnit::KilogramSquareMeter);
        }

        [[nodiscard]] constexpr un_scalar_t gram_square_decimeters() const
        {
            return convert_from_base(MassMomentOfInertiaUnit::GramSquareDecimeter);
        }

        [[nodiscard]] static constexpr MassMomentOfInertia from_gram_square_decimeters(const un_scalar_t value)
        {
            return MassMomentOfInertia(value, MassMomentOfInertiaUnit::GramSquareDecimeter);
        }

        [[nodiscard]] constexpr un_scalar_t milligram_square_decimeters() const
        {
            return convert_from_base(MassMomentOfInertiaUnit::MilligramSquareDecimeter);
        }

        [[nodiscard]] static constexpr MassMomentOfInertia from_milligram_square_decimeters(const un_scalar_t value)
        {
            return MassMomentOfInertia(value, MassMomentOfInertiaUnit::MilligramSquareDecimeter);
        }

        [[nodiscard]] constexpr un_scalar_t kilogram_square_decimeters() const
        {
            return convert_from_base(MassMomentOfInertiaUnit::KilogramSquareDecimeter);
        }

        [[nodiscard]] static constexpr MassMomentOfInertia from_kilogram_square_decimeters(const un_scalar_t value)
        {
            return MassMomentOfInertia(value, MassMomentOfInertiaUnit::KilogramSquareDecimeter);
        }

        [[nodiscard]] constexpr un_scalar_t gram_square_centimeters() const
        {
            return convert_from_base(MassMomentOfInertiaUnit::GramSquareCentimeter);
        }

        [[nodiscard]] static constexpr MassMomentOfInertia from_gram_square_centimeters(const un_scalar_t value)
        {
            return MassMomentOfInertia(value, MassMomentOfInertiaUnit::GramSquareCentimeter);
        }

        [[nodiscard]] constexpr un_scalar_t milligram_square_centimeters() const
        {
            return convert_from_base(MassMomentOfInertiaUnit::MilligramSquareCentimeter);
        }

        [[nodiscard]] static constexpr MassMomentOfInertia from_milligram_square_centimeters(const un_scalar_t value)
        {
            return MassMomentOfInertia(value, MassMomentOfInertiaUnit::MilligramSquareCentimeter);
        }

        [[nodiscard]] constexpr un_scalar_t kilogram_square_centimeters() const
        {
            return convert_from_base(MassMomentOfInertiaUnit::KilogramSquareCentimeter);
        }

        [[nodiscard]] static constexpr MassMomentOfInertia from_kilogram_square_centimeters(const un_scalar_t value)
        {
            return MassMomentOfInertia(value, MassMomentOfInertiaUnit::KilogramSquareCentimeter);
        }

        [[nodiscard]] constexpr un_scalar_t gram_square_millimeters() const
        {
            return convert_from_base(MassMomentOfInertiaUnit::GramSquareMillimeter);
        }

        [[nodiscard]] static constexpr MassMomentOfInertia from_gram_square_millimeters(const un_scalar_t value)
        {
            return MassMomentOfInertia(value, MassMomentOfInertiaUnit::GramSquareMillimeter);
        }

        [[nodiscard]] constexpr un_scalar_t milligram_square_millimeters() const
        {
            return convert_from_base(MassMomentOfInertiaUnit::MilligramSquareMillimeter);
        }

        [[nodiscard]] static constexpr MassMomentOfInertia from_milligram_square_millimeters(const un_scalar_t value)
        {
            return MassMomentOfInertia(value, MassMomentOfInertiaUnit::MilligramSquareMillimeter);
        }

        [[nodiscard]] constexpr un_scalar_t kilogram_square_millimeters() const
        {
            return convert_from_base(MassMomentOfInertiaUnit::KilogramSquareMillimeter);
        }

        [[nodiscard]] static constexpr MassMomentOfInertia from_kilogram_square_millimeters(const un_scalar_t value)
        {
            return MassMomentOfInertia(value, MassMomentOfInertiaUnit::KilogramSquareMillimeter);
        }

        [[nodiscard]] constexpr un_scalar_t tonne_square_meters() const
        {
            return convert_from_base(MassMomentOfInertiaUnit::TonneSquareMeter);
        }

        [[nodiscard]] static constexpr MassMomentOfInertia from_tonne_square_meters(const un_scalar_t value)
        {
            return MassMomentOfInertia(value, MassMomentOfInertiaUnit::TonneSquareMeter);
        }

        [[nodiscard]] constexpr un_scalar_t kilotonne_square_meters() const
        {
            return convert_from_base(MassMomentOfInertiaUnit::KilotonneSquareMeter);
        }

        [[nodiscard]] static constexpr MassMomentOfInertia from_kilotonne_square_meters(const un_scalar_t value)
        {
            return MassMomentOfInertia(value, MassMomentOfInertiaUnit::KilotonneSquareMeter);
        }

        [[nodiscard]] constexpr un_scalar_t megatonne_square_meters() const
        {
            return convert_from_base(MassMomentOfInertiaUnit::MegatonneSquareMeter);
        }

        [[nodiscard]] static constexpr MassMomentOfInertia from_megatonne_square_meters(const un_scalar_t value)
        {
            return MassMomentOfInertia(value, MassMomentOfInertiaUnit::MegatonneSquareMeter);
        }

        [[nodiscard]] constexpr un_scalar_t tonne_square_decimeters() const
        {
            return convert_from_base(MassMomentOfInertiaUnit::TonneSquareDecimeter);
        }

        [[nodiscard]] static constexpr MassMomentOfInertia from_tonne_square_decimeters(const un_scalar_t value)
        {
            return MassMomentOfInertia(value, MassMomentOfInertiaUnit::TonneSquareDecimeter);
        }

        [[nodiscard]] constexpr un_scalar_t kilotonne_square_decimeters() const
        {
            return convert_from_base(MassMomentOfInertiaUnit::KilotonneSquareDecimeter);
        }

        [[nodiscard]] static constexpr MassMomentOfInertia from_kilotonne_square_decimeters(const un_scalar_t value)
        {
            return MassMomentOfInertia(value, MassMomentOfInertiaUnit::KilotonneSquareDecimeter);
        }

        [[nodiscard]] constexpr un_scalar_t megatonne_square_decimeters() const
        {
            return convert_from_base(MassMomentOfInertiaUnit::MegatonneSquareDecimeter);
        }

        [[nodiscard]] static constexpr MassMomentOfInertia from_megatonne_square_decimeters(const un_scalar_t value)
        {
            return MassMomentOfInertia(value, MassMomentOfInertiaUnit::MegatonneSquareDecimeter);
        }

        [[nodiscard]] constexpr un_scalar_t tonne_square_centimeters() const
        {
            return convert_from_base(MassMomentOfInertiaUnit::TonneSquareCentimeter);
        }

        [[nodiscard]] static constexpr MassMomentOfInertia from_tonne_square_centimeters(const un_scalar_t value)
        {
            return MassMomentOfInertia(value, MassMomentOfInertiaUnit::TonneSquareCentimeter);
        }

        [[nodiscard]] constexpr un_scalar_t kilotonne_square_centimeters() const
        {
            return convert_from_base(MassMomentOfInertiaUnit::KilotonneSquareCentimeter);
        }

        [[nodiscard]] static constexpr MassMomentOfInertia from_kilotonne_square_centimeters(const un_scalar_t value)
        {
            return MassMomentOfInertia(value, MassMomentOfInertiaUnit::KilotonneSquareCentimeter);
        }

        [[nodiscard]] constexpr un_scalar_t megatonne_square_centimeters() const
        {
            return convert_from_base(MassMomentOfInertiaUnit::MegatonneSquareCentimeter);
        }

        [[nodiscard]] static constexpr MassMomentOfInertia from_megatonne_square_centimeters(const un_scalar_t value)
        {
            return MassMomentOfInertia(value, MassMomentOfInertiaUnit::MegatonneSquareCentimeter);
        }

        [[nodiscard]] constexpr un_scalar_t tonne_square_millimeters() const
        {
            return convert_from_base(MassMomentOfInertiaUnit::TonneSquareMillimeter);
        }

        [[nodiscard]] static constexpr MassMomentOfInertia from_tonne_square_millimeters(const un_scalar_t value)
        {
            return MassMomentOfInertia(value, MassMomentOfInertiaUnit::TonneSquareMillimeter);
        }

        [[nodiscard]] constexpr un_scalar_t kilotonne_square_millimeters() const
        {
            return convert_from_base(MassMomentOfInertiaUnit::KilotonneSquareMillimeter);
        }

        [[nodiscard]] static constexpr MassMomentOfInertia from_kilotonne_square_millimeters(const un_scalar_t value)
        {
            return MassMomentOfInertia(value, MassMomentOfInertiaUnit::KilotonneSquareMillimeter);
        }

        [[nodiscard]] constexpr un_scalar_t megatonne_square_millimeters() const
        {
            return convert_from_base(MassMomentOfInertiaUnit::MegatonneSquareMillimeter);
        }

        [[nodiscard]] static constexpr MassMomentOfInertia from_megatonne_square_millimeters(const un_scalar_t value)
        {
            return MassMomentOfInertia(value, MassMomentOfInertiaUnit::MegatonneSquareMillimeter);
        }

        [[nodiscard]] constexpr un_scalar_t pound_square_feet() const
        {
            return convert_from_base(MassMomentOfInertiaUnit::PoundSquareFoot);
        }

        [[nodiscard]] static constexpr MassMomentOfInertia from_pound_square_feet(const un_scalar_t value)
        {
            return MassMomentOfInertia(value, MassMomentOfInertiaUnit::PoundSquareFoot);
        }

        [[nodiscard]] constexpr un_scalar_t pound_square_inches() const
        {
            return convert_from_base(MassMomentOfInertiaUnit::PoundSquareInch);
        }

        [[nodiscard]] static constexpr MassMomentOfInertia from_pound_square_inches(const un_scalar_t value)
        {
            return MassMomentOfInertia(value, MassMomentOfInertiaUnit::PoundSquareInch);
        }

        [[nodiscard]] constexpr un_scalar_t slug_square_feet() const
        {
            return convert_from_base(MassMomentOfInertiaUnit::SlugSquareFoot);
        }

        [[nodiscard]] static constexpr MassMomentOfInertia from_slug_square_feet(const un_scalar_t value)
        {
            return MassMomentOfInertia(value, MassMomentOfInertiaUnit::SlugSquareFoot);
        }

        [[nodiscard]] constexpr un_scalar_t slug_square_inches() const
        {
            return convert_from_base(MassMomentOfInertiaUnit::SlugSquareInch);
        }

        [[nodiscard]] static constexpr MassMomentOfInertia from_slug_square_inches(const un_scalar_t value)
        {
            return MassMomentOfInertia(value, MassMomentOfInertiaUnit::SlugSquareInch);
        }

        [[nodiscard]] static constexpr MassMomentOfInertia from_invalid()
        {
            return MassMomentOfInertia(false);
        }
    private:
            
        [[nodiscard]] static constexpr un_scalar_t convert_to_base(un_scalar_t value, MassMomentOfInertiaUnit unit)
        {
            switch (unit)
            {

            case MassMomentOfInertiaUnit::GramSquareMeter:
                return value / static_cast<un_scalar_t>(1e3);

            case MassMomentOfInertiaUnit::MilligramSquareMeter:
                return (value * static_cast<un_scalar_t>(1e-3)) / static_cast<un_scalar_t>(1e3);

            case MassMomentOfInertiaUnit::KilogramSquareMeter:
                return (value * static_cast<un_scalar_t>(1e3)) / static_cast<un_scalar_t>(1e3);

            case MassMomentOfInertiaUnit::GramSquareDecimeter:
                return value / static_cast<un_scalar_t>(1e5);

            case MassMomentOfInertiaUnit::MilligramSquareDecimeter:
                return (value * static_cast<un_scalar_t>(1e-3)) / static_cast<un_scalar_t>(1e5);

            case MassMomentOfInertiaUnit::KilogramSquareDecimeter:
                return (value * static_cast<un_scalar_t>(1e3)) / static_cast<un_scalar_t>(1e5);

            case MassMomentOfInertiaUnit::GramSquareCentimeter:
                return value / static_cast<un_scalar_t>(1e7);

            case MassMomentOfInertiaUnit::MilligramSquareCentimeter:
                return (value * static_cast<un_scalar_t>(1e-3)) / static_cast<un_scalar_t>(1e7);

            case MassMomentOfInertiaUnit::KilogramSquareCentimeter:
                return (value * static_cast<un_scalar_t>(1e3)) / static_cast<un_scalar_t>(1e7);

            case MassMomentOfInertiaUnit::GramSquareMillimeter:
                return value / static_cast<un_scalar_t>(1e9);

            case MassMomentOfInertiaUnit::MilligramSquareMillimeter:
                return (value * static_cast<un_scalar_t>(1e-3)) / static_cast<un_scalar_t>(1e9);

            case MassMomentOfInertiaUnit::KilogramSquareMillimeter:
                return (value * static_cast<un_scalar_t>(1e3)) / static_cast<un_scalar_t>(1e9);

            case MassMomentOfInertiaUnit::TonneSquareMeter:
                return value / static_cast<un_scalar_t>(1e-3);

            case MassMomentOfInertiaUnit::KilotonneSquareMeter:
                return (value * static_cast<un_scalar_t>(1e3)) / static_cast<un_scalar_t>(1e-3);

            case MassMomentOfInertiaUnit::MegatonneSquareMeter:
                return (value * static_cast<un_scalar_t>(1e6)) / static_cast<un_scalar_t>(1e-3);

            case MassMomentOfInertiaUnit::TonneSquareDecimeter:
                return value / static_cast<un_scalar_t>(1e-1);

            case MassMomentOfInertiaUnit::KilotonneSquareDecimeter:
                return (value * static_cast<un_scalar_t>(1e3)) / static_cast<un_scalar_t>(1e-1);

            case MassMomentOfInertiaUnit::MegatonneSquareDecimeter:
                return (value * static_cast<un_scalar_t>(1e6)) / static_cast<un_scalar_t>(1e-1);

            case MassMomentOfInertiaUnit::TonneSquareCentimeter:
                return value / static_cast<un_scalar_t>(1e1);

            case MassMomentOfInertiaUnit::KilotonneSquareCentimeter:
                return (value * static_cast<un_scalar_t>(1e3)) / static_cast<un_scalar_t>(1e1);

            case MassMomentOfInertiaUnit::MegatonneSquareCentimeter:
                return (value * static_cast<un_scalar_t>(1e6)) / static_cast<un_scalar_t>(1e1);

            case MassMomentOfInertiaUnit::TonneSquareMillimeter:
                return value / static_cast<un_scalar_t>(1e3);

            case MassMomentOfInertiaUnit::KilotonneSquareMillimeter:
                return (value * static_cast<un_scalar_t>(1e3)) / static_cast<un_scalar_t>(1e3);

            case MassMomentOfInertiaUnit::MegatonneSquareMillimeter:
                return (value * static_cast<un_scalar_t>(1e6)) / static_cast<un_scalar_t>(1e3);

            case MassMomentOfInertiaUnit::PoundSquareFoot:
                return value * (static_cast<un_scalar_t>(0.45359237) * static_cast<un_scalar_t>(9.290304e-2));

            case MassMomentOfInertiaUnit::PoundSquareInch:
                return value * (static_cast<un_scalar_t>(0.45359237) * static_cast<un_scalar_t>(0.00064516));

            case MassMomentOfInertiaUnit::SlugSquareFoot:
                return value * static_cast<un_scalar_t>(0.45359237) * static_cast<un_scalar_t>(9.290304e-2) * static_cast<un_scalar_t>(9.80665) / static_cast<un_scalar_t>(0.3048);

            case MassMomentOfInertiaUnit::SlugSquareInch:
                return value * static_cast<un_scalar_t>(0.45359237) * static_cast<un_scalar_t>(0.00064516) * static_cast<un_scalar_t>(9.80665) / static_cast<un_scalar_t>(0.3048);

            }

            throw std::invalid_argument("Unknown MassMomentOfInertia unit.");
        }

        [[nodiscard]] constexpr un_scalar_t convert_from_base(const MassMomentOfInertiaUnit unit) const
        {
            if(unit == value_unit_type_)
            {
                return value_;
            }
            
            auto base_value = convert_to_base(value_, value_unit_type_);
            
            switch (unit)
            {

            case MassMomentOfInertiaUnit::GramSquareMeter:
                return base_value * static_cast<un_scalar_t>(1e3);

            case MassMomentOfInertiaUnit::MilligramSquareMeter:
                return (base_value * static_cast<un_scalar_t>(1e3)) / static_cast<un_scalar_t>(1e-3);

            case MassMomentOfInertiaUnit::KilogramSquareMeter:
                return (base_value * static_cast<un_scalar_t>(1e3)) / static_cast<un_scalar_t>(1e3);

            case MassMomentOfInertiaUnit::GramSquareDecimeter:
                return base_value * static_cast<un_scalar_t>(1e5);

            case MassMomentOfInertiaUnit::MilligramSquareDecimeter:
                return (base_value * static_cast<un_scalar_t>(1e5)) / static_cast<un_scalar_t>(1e-3);

            case MassMomentOfInertiaUnit::KilogramSquareDecimeter:
                return (base_value * static_cast<un_scalar_t>(1e5)) / static_cast<un_scalar_t>(1e3);

            case MassMomentOfInertiaUnit::GramSquareCentimeter:
                return base_value * static_cast<un_scalar_t>(1e7);

            case MassMomentOfInertiaUnit::MilligramSquareCentimeter:
                return (base_value * static_cast<un_scalar_t>(1e7)) / static_cast<un_scalar_t>(1e-3);

            case MassMomentOfInertiaUnit::KilogramSquareCentimeter:
                return (base_value * static_cast<un_scalar_t>(1e7)) / static_cast<un_scalar_t>(1e3);

            case MassMomentOfInertiaUnit::GramSquareMillimeter:
                return base_value * static_cast<un_scalar_t>(1e9);

            case MassMomentOfInertiaUnit::MilligramSquareMillimeter:
                return (base_value * static_cast<un_scalar_t>(1e9)) / static_cast<un_scalar_t>(1e-3);

            case MassMomentOfInertiaUnit::KilogramSquareMillimeter:
                return (base_value * static_cast<un_scalar_t>(1e9)) / static_cast<un_scalar_t>(1e3);

            case MassMomentOfInertiaUnit::TonneSquareMeter:
                return base_value * static_cast<un_scalar_t>(1e-3);

            case MassMomentOfInertiaUnit::KilotonneSquareMeter:
                return (base_value * static_cast<un_scalar_t>(1e-3)) / static_cast<un_scalar_t>(1e3);

            case MassMomentOfInertiaUnit::MegatonneSquareMeter:
                return (base_value * static_cast<un_scalar_t>(1e-3)) / static_cast<un_scalar_t>(1e6);

            case MassMomentOfInertiaUnit::TonneSquareDecimeter:
                return base_value * static_cast<un_scalar_t>(1e-1);

            case MassMomentOfInertiaUnit::KilotonneSquareDecimeter:
                return (base_value * static_cast<un_scalar_t>(1e-1)) / static_cast<un_scalar_t>(1e3);

            case MassMomentOfInertiaUnit::MegatonneSquareDecimeter:
                return (base_value * static_cast<un_scalar_t>(1e-1)) / static_cast<un_scalar_t>(1e6);

            case MassMomentOfInertiaUnit::TonneSquareCentimeter:
                return base_value * static_cast<un_scalar_t>(1e1);

            case MassMomentOfInertiaUnit::KilotonneSquareCentimeter:
                return (base_value * static_cast<un_scalar_t>(1e1)) / static_cast<un_scalar_t>(1e3);

            case MassMomentOfInertiaUnit::MegatonneSquareCentimeter:
                return (base_value * static_cast<un_scalar_t>(1e1)) / static_cast<un_scalar_t>(1e6);

            case MassMomentOfInertiaUnit::TonneSquareMillimeter:
                return base_value * static_cast<un_scalar_t>(1e3);

            case MassMomentOfInertiaUnit::KilotonneSquareMillimeter:
                return (base_value * static_cast<un_scalar_t>(1e3)) / static_cast<un_scalar_t>(1e3);

            case MassMomentOfInertiaUnit::MegatonneSquareMillimeter:
                return (base_value * static_cast<un_scalar_t>(1e3)) / static_cast<un_scalar_t>(1e6);

            case MassMomentOfInertiaUnit::PoundSquareFoot:
                return base_value / (static_cast<un_scalar_t>(0.45359237) * static_cast<un_scalar_t>(9.290304e-2));

            case MassMomentOfInertiaUnit::PoundSquareInch:
                return base_value / (static_cast<un_scalar_t>(0.45359237) * static_cast<un_scalar_t>(0.00064516));

            case MassMomentOfInertiaUnit::SlugSquareFoot:
                return base_value * static_cast<un_scalar_t>(0.3048) / (static_cast<un_scalar_t>(0.45359237) * static_cast<un_scalar_t>(9.290304e-2) * static_cast<un_scalar_t>(9.80665));

            case MassMomentOfInertiaUnit::SlugSquareInch:
                return base_value * static_cast<un_scalar_t>(0.3048) / (static_cast<un_scalar_t>(0.45359237) * static_cast<un_scalar_t>(0.00064516) * static_cast<un_scalar_t>(9.80665));

            }

            throw std::invalid_argument("Unknown MassMomentOfInertia unit.");
        }

        un_scalar_t value_;
        MassMomentOfInertiaUnit value_unit_type_;       
    };
}
