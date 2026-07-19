#pragma once

#include <cstdint>
#include <numbers>
#include <stdexcept>
#include "UnitsNetConfig.h"
#include "UnitsNetBase.h"

namespace unitsnet_cpp
{
    enum class MassMomentOfInertiaUnit : std::uint8_t
    {
        GramSquareMeters,
        MilligramSquareMeters,
        KilogramSquareMeters,
        GramSquareDecimeters,
        MilligramSquareDecimeters,
        KilogramSquareDecimeters,
        GramSquareCentimeters,
        MilligramSquareCentimeters,
        KilogramSquareCentimeters,
        GramSquareMillimeters,
        MilligramSquareMillimeters,
        KilogramSquareMillimeters,
        TonneSquareMeters,
        KilotonneSquareMeters,
        MegatonneSquareMeters,
        TonneSquareDecimeters,
        KilotonneSquareDecimeters,
        MegatonneSquareDecimeters,
        TonneSquareCentimeters,
        KilotonneSquareCentimeters,
        MegatonneSquareCentimeters,
        TonneSquareMillimeters,
        KilotonneSquareMillimeters,
        MegatonneSquareMillimeters,
        PoundSquareFeet,
        PoundSquareInches,
        SlugSquareFeet,
        SlugSquareInches,
    };

    /// <summary>A property of body reflects how its mass is distributed with regard to an axis.</summary>
    class MassMomentOfInertia : public UnitsNetBase
    {
    public:
        constexpr explicit MassMomentOfInertia(
            const un_scalar_t value,
            const MassMomentOfInertiaUnit unit = MassMomentOfInertiaUnit::KilogramSquareMeters)
        {
            value_ = value;
            value_unit_type_ = unit;
        }
        
        [[nodiscard]] constexpr un_scalar_t stored_value() const noexcept override
        {
           return value_; 
        }
        
        [[nodiscard]] constexpr std::string_view quantity_name() const noexcept override
        {
           return "MassMomentOfInertia"; 
        }
        
        [[nodiscard]] constexpr std::string_view unit_name() const noexcept override
        {
            switch (value_unit_type_)
            {

            case MassMomentOfInertiaUnit::GramSquareMeters:
                return "GramSquareMeters";

            case MassMomentOfInertiaUnit::MilligramSquareMeters:
                return "MilligramSquareMeters";

            case MassMomentOfInertiaUnit::KilogramSquareMeters:
                return "KilogramSquareMeters";

            case MassMomentOfInertiaUnit::GramSquareDecimeters:
                return "GramSquareDecimeters";

            case MassMomentOfInertiaUnit::MilligramSquareDecimeters:
                return "MilligramSquareDecimeters";

            case MassMomentOfInertiaUnit::KilogramSquareDecimeters:
                return "KilogramSquareDecimeters";

            case MassMomentOfInertiaUnit::GramSquareCentimeters:
                return "GramSquareCentimeters";

            case MassMomentOfInertiaUnit::MilligramSquareCentimeters:
                return "MilligramSquareCentimeters";

            case MassMomentOfInertiaUnit::KilogramSquareCentimeters:
                return "KilogramSquareCentimeters";

            case MassMomentOfInertiaUnit::GramSquareMillimeters:
                return "GramSquareMillimeters";

            case MassMomentOfInertiaUnit::MilligramSquareMillimeters:
                return "MilligramSquareMillimeters";

            case MassMomentOfInertiaUnit::KilogramSquareMillimeters:
                return "KilogramSquareMillimeters";

            case MassMomentOfInertiaUnit::TonneSquareMeters:
                return "TonneSquareMeters";

            case MassMomentOfInertiaUnit::KilotonneSquareMeters:
                return "KilotonneSquareMeters";

            case MassMomentOfInertiaUnit::MegatonneSquareMeters:
                return "MegatonneSquareMeters";

            case MassMomentOfInertiaUnit::TonneSquareDecimeters:
                return "TonneSquareDecimeters";

            case MassMomentOfInertiaUnit::KilotonneSquareDecimeters:
                return "KilotonneSquareDecimeters";

            case MassMomentOfInertiaUnit::MegatonneSquareDecimeters:
                return "MegatonneSquareDecimeters";

            case MassMomentOfInertiaUnit::TonneSquareCentimeters:
                return "TonneSquareCentimeters";

            case MassMomentOfInertiaUnit::KilotonneSquareCentimeters:
                return "KilotonneSquareCentimeters";

            case MassMomentOfInertiaUnit::MegatonneSquareCentimeters:
                return "MegatonneSquareCentimeters";

            case MassMomentOfInertiaUnit::TonneSquareMillimeters:
                return "TonneSquareMillimeters";

            case MassMomentOfInertiaUnit::KilotonneSquareMillimeters:
                return "KilotonneSquareMillimeters";

            case MassMomentOfInertiaUnit::MegatonneSquareMillimeters:
                return "MegatonneSquareMillimeters";

            case MassMomentOfInertiaUnit::PoundSquareFeet:
                return "PoundSquareFeet";

            case MassMomentOfInertiaUnit::PoundSquareInches:
                return "PoundSquareInches";

            case MassMomentOfInertiaUnit::SlugSquareFeet:
                return "SlugSquareFeet";

            case MassMomentOfInertiaUnit::SlugSquareInches:
                return "SlugSquareInches";

            }
            
            return {};
        }
                
        [[nodiscard]] constexpr un_scalar_t base_value() const noexcept
        {
            return convert_to_base(value_, value_unit_type_);    
        }

        [[nodiscard]] constexpr un_scalar_t value(const MassMomentOfInertiaUnit unit) const
        {
            return convert_from_base(unit);
        }

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
            return convert_from_base(MassMomentOfInertiaUnit::GramSquareMeters);
        }

        [[nodiscard]] static constexpr MassMomentOfInertia from_gram_square_meters(const un_scalar_t value)
        {
            return MassMomentOfInertia(value, MassMomentOfInertiaUnit::GramSquareMeters);
        }

        [[nodiscard]] constexpr un_scalar_t milligram_square_meters() const
        {
            return convert_from_base(MassMomentOfInertiaUnit::MilligramSquareMeters);
        }

        [[nodiscard]] static constexpr MassMomentOfInertia from_milligram_square_meters(const un_scalar_t value)
        {
            return MassMomentOfInertia(value, MassMomentOfInertiaUnit::MilligramSquareMeters);
        }

        [[nodiscard]] constexpr un_scalar_t kilogram_square_meters() const
        {
            return convert_from_base(MassMomentOfInertiaUnit::KilogramSquareMeters);
        }

        [[nodiscard]] static constexpr MassMomentOfInertia from_kilogram_square_meters(const un_scalar_t value)
        {
            return MassMomentOfInertia(value, MassMomentOfInertiaUnit::KilogramSquareMeters);
        }

        [[nodiscard]] constexpr un_scalar_t gram_square_decimeters() const
        {
            return convert_from_base(MassMomentOfInertiaUnit::GramSquareDecimeters);
        }

        [[nodiscard]] static constexpr MassMomentOfInertia from_gram_square_decimeters(const un_scalar_t value)
        {
            return MassMomentOfInertia(value, MassMomentOfInertiaUnit::GramSquareDecimeters);
        }

        [[nodiscard]] constexpr un_scalar_t milligram_square_decimeters() const
        {
            return convert_from_base(MassMomentOfInertiaUnit::MilligramSquareDecimeters);
        }

        [[nodiscard]] static constexpr MassMomentOfInertia from_milligram_square_decimeters(const un_scalar_t value)
        {
            return MassMomentOfInertia(value, MassMomentOfInertiaUnit::MilligramSquareDecimeters);
        }

        [[nodiscard]] constexpr un_scalar_t kilogram_square_decimeters() const
        {
            return convert_from_base(MassMomentOfInertiaUnit::KilogramSquareDecimeters);
        }

        [[nodiscard]] static constexpr MassMomentOfInertia from_kilogram_square_decimeters(const un_scalar_t value)
        {
            return MassMomentOfInertia(value, MassMomentOfInertiaUnit::KilogramSquareDecimeters);
        }

        [[nodiscard]] constexpr un_scalar_t gram_square_centimeters() const
        {
            return convert_from_base(MassMomentOfInertiaUnit::GramSquareCentimeters);
        }

        [[nodiscard]] static constexpr MassMomentOfInertia from_gram_square_centimeters(const un_scalar_t value)
        {
            return MassMomentOfInertia(value, MassMomentOfInertiaUnit::GramSquareCentimeters);
        }

        [[nodiscard]] constexpr un_scalar_t milligram_square_centimeters() const
        {
            return convert_from_base(MassMomentOfInertiaUnit::MilligramSquareCentimeters);
        }

        [[nodiscard]] static constexpr MassMomentOfInertia from_milligram_square_centimeters(const un_scalar_t value)
        {
            return MassMomentOfInertia(value, MassMomentOfInertiaUnit::MilligramSquareCentimeters);
        }

        [[nodiscard]] constexpr un_scalar_t kilogram_square_centimeters() const
        {
            return convert_from_base(MassMomentOfInertiaUnit::KilogramSquareCentimeters);
        }

        [[nodiscard]] static constexpr MassMomentOfInertia from_kilogram_square_centimeters(const un_scalar_t value)
        {
            return MassMomentOfInertia(value, MassMomentOfInertiaUnit::KilogramSquareCentimeters);
        }

        [[nodiscard]] constexpr un_scalar_t gram_square_millimeters() const
        {
            return convert_from_base(MassMomentOfInertiaUnit::GramSquareMillimeters);
        }

        [[nodiscard]] static constexpr MassMomentOfInertia from_gram_square_millimeters(const un_scalar_t value)
        {
            return MassMomentOfInertia(value, MassMomentOfInertiaUnit::GramSquareMillimeters);
        }

        [[nodiscard]] constexpr un_scalar_t milligram_square_millimeters() const
        {
            return convert_from_base(MassMomentOfInertiaUnit::MilligramSquareMillimeters);
        }

        [[nodiscard]] static constexpr MassMomentOfInertia from_milligram_square_millimeters(const un_scalar_t value)
        {
            return MassMomentOfInertia(value, MassMomentOfInertiaUnit::MilligramSquareMillimeters);
        }

        [[nodiscard]] constexpr un_scalar_t kilogram_square_millimeters() const
        {
            return convert_from_base(MassMomentOfInertiaUnit::KilogramSquareMillimeters);
        }

        [[nodiscard]] static constexpr MassMomentOfInertia from_kilogram_square_millimeters(const un_scalar_t value)
        {
            return MassMomentOfInertia(value, MassMomentOfInertiaUnit::KilogramSquareMillimeters);
        }

        [[nodiscard]] constexpr un_scalar_t tonne_square_meters() const
        {
            return convert_from_base(MassMomentOfInertiaUnit::TonneSquareMeters);
        }

        [[nodiscard]] static constexpr MassMomentOfInertia from_tonne_square_meters(const un_scalar_t value)
        {
            return MassMomentOfInertia(value, MassMomentOfInertiaUnit::TonneSquareMeters);
        }

        [[nodiscard]] constexpr un_scalar_t kilotonne_square_meters() const
        {
            return convert_from_base(MassMomentOfInertiaUnit::KilotonneSquareMeters);
        }

        [[nodiscard]] static constexpr MassMomentOfInertia from_kilotonne_square_meters(const un_scalar_t value)
        {
            return MassMomentOfInertia(value, MassMomentOfInertiaUnit::KilotonneSquareMeters);
        }

        [[nodiscard]] constexpr un_scalar_t megatonne_square_meters() const
        {
            return convert_from_base(MassMomentOfInertiaUnit::MegatonneSquareMeters);
        }

        [[nodiscard]] static constexpr MassMomentOfInertia from_megatonne_square_meters(const un_scalar_t value)
        {
            return MassMomentOfInertia(value, MassMomentOfInertiaUnit::MegatonneSquareMeters);
        }

        [[nodiscard]] constexpr un_scalar_t tonne_square_decimeters() const
        {
            return convert_from_base(MassMomentOfInertiaUnit::TonneSquareDecimeters);
        }

        [[nodiscard]] static constexpr MassMomentOfInertia from_tonne_square_decimeters(const un_scalar_t value)
        {
            return MassMomentOfInertia(value, MassMomentOfInertiaUnit::TonneSquareDecimeters);
        }

        [[nodiscard]] constexpr un_scalar_t kilotonne_square_decimeters() const
        {
            return convert_from_base(MassMomentOfInertiaUnit::KilotonneSquareDecimeters);
        }

        [[nodiscard]] static constexpr MassMomentOfInertia from_kilotonne_square_decimeters(const un_scalar_t value)
        {
            return MassMomentOfInertia(value, MassMomentOfInertiaUnit::KilotonneSquareDecimeters);
        }

        [[nodiscard]] constexpr un_scalar_t megatonne_square_decimeters() const
        {
            return convert_from_base(MassMomentOfInertiaUnit::MegatonneSquareDecimeters);
        }

        [[nodiscard]] static constexpr MassMomentOfInertia from_megatonne_square_decimeters(const un_scalar_t value)
        {
            return MassMomentOfInertia(value, MassMomentOfInertiaUnit::MegatonneSquareDecimeters);
        }

        [[nodiscard]] constexpr un_scalar_t tonne_square_centimeters() const
        {
            return convert_from_base(MassMomentOfInertiaUnit::TonneSquareCentimeters);
        }

        [[nodiscard]] static constexpr MassMomentOfInertia from_tonne_square_centimeters(const un_scalar_t value)
        {
            return MassMomentOfInertia(value, MassMomentOfInertiaUnit::TonneSquareCentimeters);
        }

        [[nodiscard]] constexpr un_scalar_t kilotonne_square_centimeters() const
        {
            return convert_from_base(MassMomentOfInertiaUnit::KilotonneSquareCentimeters);
        }

        [[nodiscard]] static constexpr MassMomentOfInertia from_kilotonne_square_centimeters(const un_scalar_t value)
        {
            return MassMomentOfInertia(value, MassMomentOfInertiaUnit::KilotonneSquareCentimeters);
        }

        [[nodiscard]] constexpr un_scalar_t megatonne_square_centimeters() const
        {
            return convert_from_base(MassMomentOfInertiaUnit::MegatonneSquareCentimeters);
        }

        [[nodiscard]] static constexpr MassMomentOfInertia from_megatonne_square_centimeters(const un_scalar_t value)
        {
            return MassMomentOfInertia(value, MassMomentOfInertiaUnit::MegatonneSquareCentimeters);
        }

        [[nodiscard]] constexpr un_scalar_t tonne_square_millimeters() const
        {
            return convert_from_base(MassMomentOfInertiaUnit::TonneSquareMillimeters);
        }

        [[nodiscard]] static constexpr MassMomentOfInertia from_tonne_square_millimeters(const un_scalar_t value)
        {
            return MassMomentOfInertia(value, MassMomentOfInertiaUnit::TonneSquareMillimeters);
        }

        [[nodiscard]] constexpr un_scalar_t kilotonne_square_millimeters() const
        {
            return convert_from_base(MassMomentOfInertiaUnit::KilotonneSquareMillimeters);
        }

        [[nodiscard]] static constexpr MassMomentOfInertia from_kilotonne_square_millimeters(const un_scalar_t value)
        {
            return MassMomentOfInertia(value, MassMomentOfInertiaUnit::KilotonneSquareMillimeters);
        }

        [[nodiscard]] constexpr un_scalar_t megatonne_square_millimeters() const
        {
            return convert_from_base(MassMomentOfInertiaUnit::MegatonneSquareMillimeters);
        }

        [[nodiscard]] static constexpr MassMomentOfInertia from_megatonne_square_millimeters(const un_scalar_t value)
        {
            return MassMomentOfInertia(value, MassMomentOfInertiaUnit::MegatonneSquareMillimeters);
        }

        [[nodiscard]] constexpr un_scalar_t pound_square_feet() const
        {
            return convert_from_base(MassMomentOfInertiaUnit::PoundSquareFeet);
        }

        [[nodiscard]] static constexpr MassMomentOfInertia from_pound_square_feet(const un_scalar_t value)
        {
            return MassMomentOfInertia(value, MassMomentOfInertiaUnit::PoundSquareFeet);
        }

        [[nodiscard]] constexpr un_scalar_t pound_square_inches() const
        {
            return convert_from_base(MassMomentOfInertiaUnit::PoundSquareInches);
        }

        [[nodiscard]] static constexpr MassMomentOfInertia from_pound_square_inches(const un_scalar_t value)
        {
            return MassMomentOfInertia(value, MassMomentOfInertiaUnit::PoundSquareInches);
        }

        [[nodiscard]] constexpr un_scalar_t slug_square_feet() const
        {
            return convert_from_base(MassMomentOfInertiaUnit::SlugSquareFeet);
        }

        [[nodiscard]] static constexpr MassMomentOfInertia from_slug_square_feet(const un_scalar_t value)
        {
            return MassMomentOfInertia(value, MassMomentOfInertiaUnit::SlugSquareFeet);
        }

        [[nodiscard]] constexpr un_scalar_t slug_square_inches() const
        {
            return convert_from_base(MassMomentOfInertiaUnit::SlugSquareInches);
        }

        [[nodiscard]] static constexpr MassMomentOfInertia from_slug_square_inches(const un_scalar_t value)
        {
            return MassMomentOfInertia(value, MassMomentOfInertiaUnit::SlugSquareInches);
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

            case MassMomentOfInertiaUnit::GramSquareMeters:
                return value / static_cast<un_scalar_t>(1e3);

            case MassMomentOfInertiaUnit::MilligramSquareMeters:
                return (value * static_cast<un_scalar_t>(1e-3)) / static_cast<un_scalar_t>(1e3);

            case MassMomentOfInertiaUnit::KilogramSquareMeters:
                return (value * static_cast<un_scalar_t>(1e3)) / static_cast<un_scalar_t>(1e3);

            case MassMomentOfInertiaUnit::GramSquareDecimeters:
                return value / static_cast<un_scalar_t>(1e5);

            case MassMomentOfInertiaUnit::MilligramSquareDecimeters:
                return (value * static_cast<un_scalar_t>(1e-3)) / static_cast<un_scalar_t>(1e5);

            case MassMomentOfInertiaUnit::KilogramSquareDecimeters:
                return (value * static_cast<un_scalar_t>(1e3)) / static_cast<un_scalar_t>(1e5);

            case MassMomentOfInertiaUnit::GramSquareCentimeters:
                return value / static_cast<un_scalar_t>(1e7);

            case MassMomentOfInertiaUnit::MilligramSquareCentimeters:
                return (value * static_cast<un_scalar_t>(1e-3)) / static_cast<un_scalar_t>(1e7);

            case MassMomentOfInertiaUnit::KilogramSquareCentimeters:
                return (value * static_cast<un_scalar_t>(1e3)) / static_cast<un_scalar_t>(1e7);

            case MassMomentOfInertiaUnit::GramSquareMillimeters:
                return value / static_cast<un_scalar_t>(1e9);

            case MassMomentOfInertiaUnit::MilligramSquareMillimeters:
                return (value * static_cast<un_scalar_t>(1e-3)) / static_cast<un_scalar_t>(1e9);

            case MassMomentOfInertiaUnit::KilogramSquareMillimeters:
                return (value * static_cast<un_scalar_t>(1e3)) / static_cast<un_scalar_t>(1e9);

            case MassMomentOfInertiaUnit::TonneSquareMeters:
                return value / static_cast<un_scalar_t>(1e-3);

            case MassMomentOfInertiaUnit::KilotonneSquareMeters:
                return (value * static_cast<un_scalar_t>(1e3)) / static_cast<un_scalar_t>(1e-3);

            case MassMomentOfInertiaUnit::MegatonneSquareMeters:
                return (value * static_cast<un_scalar_t>(1e6)) / static_cast<un_scalar_t>(1e-3);

            case MassMomentOfInertiaUnit::TonneSquareDecimeters:
                return value / static_cast<un_scalar_t>(1e-1);

            case MassMomentOfInertiaUnit::KilotonneSquareDecimeters:
                return (value * static_cast<un_scalar_t>(1e3)) / static_cast<un_scalar_t>(1e-1);

            case MassMomentOfInertiaUnit::MegatonneSquareDecimeters:
                return (value * static_cast<un_scalar_t>(1e6)) / static_cast<un_scalar_t>(1e-1);

            case MassMomentOfInertiaUnit::TonneSquareCentimeters:
                return value / static_cast<un_scalar_t>(1e1);

            case MassMomentOfInertiaUnit::KilotonneSquareCentimeters:
                return (value * static_cast<un_scalar_t>(1e3)) / static_cast<un_scalar_t>(1e1);

            case MassMomentOfInertiaUnit::MegatonneSquareCentimeters:
                return (value * static_cast<un_scalar_t>(1e6)) / static_cast<un_scalar_t>(1e1);

            case MassMomentOfInertiaUnit::TonneSquareMillimeters:
                return value / static_cast<un_scalar_t>(1e3);

            case MassMomentOfInertiaUnit::KilotonneSquareMillimeters:
                return (value * static_cast<un_scalar_t>(1e3)) / static_cast<un_scalar_t>(1e3);

            case MassMomentOfInertiaUnit::MegatonneSquareMillimeters:
                return (value * static_cast<un_scalar_t>(1e6)) / static_cast<un_scalar_t>(1e3);

            case MassMomentOfInertiaUnit::PoundSquareFeet:
                return value * (static_cast<un_scalar_t>(0.45359237) * static_cast<un_scalar_t>(9.290304e-2));

            case MassMomentOfInertiaUnit::PoundSquareInches:
                return value * (static_cast<un_scalar_t>(0.45359237) * static_cast<un_scalar_t>(0.00064516));

            case MassMomentOfInertiaUnit::SlugSquareFeet:
                return value * static_cast<un_scalar_t>(0.45359237) * static_cast<un_scalar_t>(9.290304e-2) * static_cast<un_scalar_t>(9.80665) / static_cast<un_scalar_t>(0.3048);

            case MassMomentOfInertiaUnit::SlugSquareInches:
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

            case MassMomentOfInertiaUnit::GramSquareMeters:
                return base_value * static_cast<un_scalar_t>(1e3);

            case MassMomentOfInertiaUnit::MilligramSquareMeters:
                return (base_value * static_cast<un_scalar_t>(1e3)) / static_cast<un_scalar_t>(1e-3);

            case MassMomentOfInertiaUnit::KilogramSquareMeters:
                return (base_value * static_cast<un_scalar_t>(1e3)) / static_cast<un_scalar_t>(1e3);

            case MassMomentOfInertiaUnit::GramSquareDecimeters:
                return base_value * static_cast<un_scalar_t>(1e5);

            case MassMomentOfInertiaUnit::MilligramSquareDecimeters:
                return (base_value * static_cast<un_scalar_t>(1e5)) / static_cast<un_scalar_t>(1e-3);

            case MassMomentOfInertiaUnit::KilogramSquareDecimeters:
                return (base_value * static_cast<un_scalar_t>(1e5)) / static_cast<un_scalar_t>(1e3);

            case MassMomentOfInertiaUnit::GramSquareCentimeters:
                return base_value * static_cast<un_scalar_t>(1e7);

            case MassMomentOfInertiaUnit::MilligramSquareCentimeters:
                return (base_value * static_cast<un_scalar_t>(1e7)) / static_cast<un_scalar_t>(1e-3);

            case MassMomentOfInertiaUnit::KilogramSquareCentimeters:
                return (base_value * static_cast<un_scalar_t>(1e7)) / static_cast<un_scalar_t>(1e3);

            case MassMomentOfInertiaUnit::GramSquareMillimeters:
                return base_value * static_cast<un_scalar_t>(1e9);

            case MassMomentOfInertiaUnit::MilligramSquareMillimeters:
                return (base_value * static_cast<un_scalar_t>(1e9)) / static_cast<un_scalar_t>(1e-3);

            case MassMomentOfInertiaUnit::KilogramSquareMillimeters:
                return (base_value * static_cast<un_scalar_t>(1e9)) / static_cast<un_scalar_t>(1e3);

            case MassMomentOfInertiaUnit::TonneSquareMeters:
                return base_value * static_cast<un_scalar_t>(1e-3);

            case MassMomentOfInertiaUnit::KilotonneSquareMeters:
                return (base_value * static_cast<un_scalar_t>(1e-3)) / static_cast<un_scalar_t>(1e3);

            case MassMomentOfInertiaUnit::MegatonneSquareMeters:
                return (base_value * static_cast<un_scalar_t>(1e-3)) / static_cast<un_scalar_t>(1e6);

            case MassMomentOfInertiaUnit::TonneSquareDecimeters:
                return base_value * static_cast<un_scalar_t>(1e-1);

            case MassMomentOfInertiaUnit::KilotonneSquareDecimeters:
                return (base_value * static_cast<un_scalar_t>(1e-1)) / static_cast<un_scalar_t>(1e3);

            case MassMomentOfInertiaUnit::MegatonneSquareDecimeters:
                return (base_value * static_cast<un_scalar_t>(1e-1)) / static_cast<un_scalar_t>(1e6);

            case MassMomentOfInertiaUnit::TonneSquareCentimeters:
                return base_value * static_cast<un_scalar_t>(1e1);

            case MassMomentOfInertiaUnit::KilotonneSquareCentimeters:
                return (base_value * static_cast<un_scalar_t>(1e1)) / static_cast<un_scalar_t>(1e3);

            case MassMomentOfInertiaUnit::MegatonneSquareCentimeters:
                return (base_value * static_cast<un_scalar_t>(1e1)) / static_cast<un_scalar_t>(1e6);

            case MassMomentOfInertiaUnit::TonneSquareMillimeters:
                return base_value * static_cast<un_scalar_t>(1e3);

            case MassMomentOfInertiaUnit::KilotonneSquareMillimeters:
                return (base_value * static_cast<un_scalar_t>(1e3)) / static_cast<un_scalar_t>(1e3);

            case MassMomentOfInertiaUnit::MegatonneSquareMillimeters:
                return (base_value * static_cast<un_scalar_t>(1e3)) / static_cast<un_scalar_t>(1e6);

            case MassMomentOfInertiaUnit::PoundSquareFeet:
                return base_value / (static_cast<un_scalar_t>(0.45359237) * static_cast<un_scalar_t>(9.290304e-2));

            case MassMomentOfInertiaUnit::PoundSquareInches:
                return base_value / (static_cast<un_scalar_t>(0.45359237) * static_cast<un_scalar_t>(0.00064516));

            case MassMomentOfInertiaUnit::SlugSquareFeet:
                return base_value * static_cast<un_scalar_t>(0.3048) / (static_cast<un_scalar_t>(0.45359237) * static_cast<un_scalar_t>(9.290304e-2) * static_cast<un_scalar_t>(9.80665));

            case MassMomentOfInertiaUnit::SlugSquareInches:
                return base_value * static_cast<un_scalar_t>(0.3048) / (static_cast<un_scalar_t>(0.45359237) * static_cast<un_scalar_t>(0.00064516) * static_cast<un_scalar_t>(9.80665));

            }

            throw std::invalid_argument("Unknown MassMomentOfInertia unit.");
        }

        un_scalar_t value_;
        MassMomentOfInertiaUnit value_unit_type_;       
    };
}
