#pragma once

#include <cstdint>
#include <numbers>
#include <stdexcept>
#include "UnitsNetConfig.h"

namespace unitsnet_cpp
{
    enum class VolumeUnit : std::uint8_t
    {
        Liters,
        Nanoliters,
        Microliters,
        Milliliters,
        Centiliters,
        Deciliters,
        Decaliters,
        Hectoliters,
        Kiloliters,
        Megaliters,
        CubicMeters,
        HectocubicMeters,
        KilocubicMeters,
        CubicKilometers,
        CubicHectometers,
        CubicDecimeters,
        CubicCentimeters,
        CubicMillimeters,
        CubicMicrometers,
        CubicMiles,
        CubicYards,
        CubicFeet,
        HectocubicFeet,
        KilocubicFeet,
        MegacubicFeet,
        CubicInches,
        ImperialGallons,
        KiloimperialGallons,
        MegaimperialGallons,
        ImperialOunces,
        UsGallons,
        DecausGallons,
        DeciusGallons,
        HectousGallons,
        KilousGallons,
        MegausGallons,
        UsOunces,
        UsTablespoons,
        AuTablespoons,
        MetricTablespoons,
        UkTablespoons,
        MetricTeaspoons,
        UsTeaspoons,
        MetricCups,
        UsCustomaryCups,
        UsLegalCups,
        OilBarrels,
        UsBeerBarrels,
        ImperialBeerBarrels,
        UsQuarts,
        ImperialQuarts,
        UsPints,
        AcreFeet,
        ImperialPints,
        BoardFeet,
    };

    /// <summary>Volume is the quantity of three-dimensional space enclosed by some closed boundary, for example, the space that a substance (solid, liquid, gas, or plasma) or shape occupies or contains.[1] Volume is often quantified numerically using the SI derived unit, the cubic metre. The volume of a container is generally understood to be the capacity of the container, i. e. the amount of fluid (gas or liquid) that the container could hold, rather than the amount of space the container itself displaces.</summary>
    class Volume
    {
    public:
        constexpr explicit Volume(
            const un_scalar_t value,
            const VolumeUnit unit = VolumeUnit::CubicMeters)
            : value_(convert_to_base(value, unit))
        {
        }
        
        constexpr explicit Volume(const bool isValid)
        {
            _isInvalid = !isValid;
        }
        
        void SetValueAsInvalid()
        {
            _isInvalid = true;
        }
        
        void SetValueAsValid()
        {
            _isInvalid = false;
        }
        
        [[nodiscard]] bool GetValueIsValid() const
        {
            return _isInvalid;
        }

        [[nodiscard]] constexpr un_scalar_t base_value() const noexcept
        {
            return value_;
        }

        [[nodiscard]] constexpr un_scalar_t value(const VolumeUnit unit) const
        {
            return convert_from_base(unit);
        }

        [[nodiscard]] constexpr Volume operator+(const Volume other) const noexcept
        {
            return Volume(value_ + other.value_);
        }

        [[nodiscard]] constexpr Volume operator-(const Volume other) const noexcept
        {
            return Volume(value_ - other.value_);
        }

        [[nodiscard]] constexpr Volume operator*(const un_scalar_t scalar) const noexcept
        {
            return Volume(value_ * scalar);
        }

        [[nodiscard]] constexpr Volume operator/(const un_scalar_t scalar) const noexcept
        {
            return Volume(value_ / scalar);
        }

        [[nodiscard]] constexpr bool operator==(const Volume other) const noexcept
        {
            return value_ == other.value_;
        }

        [[nodiscard]] constexpr bool operator<(const Volume other) const noexcept
        {
            return value_ < other.value_;
        }
        
        [[nodiscard]] constexpr bool operator>(const Volume other) const noexcept
        {
            return value_ > other.value_;
        }


        [[nodiscard]] constexpr un_scalar_t liters() const
        {
            return convert_from_base(VolumeUnit::Liters);
        }

        [[nodiscard]] static constexpr Volume from_liters(const un_scalar_t value)
        {
            return Volume(value, VolumeUnit::Liters);
        }


        [[nodiscard]] constexpr un_scalar_t nanoliters() const
        {
            return convert_from_base(VolumeUnit::Nanoliters);
        }

        [[nodiscard]] static constexpr Volume from_nanoliters(const un_scalar_t value)
        {
            return Volume(value, VolumeUnit::Nanoliters);
        }


        [[nodiscard]] constexpr un_scalar_t microliters() const
        {
            return convert_from_base(VolumeUnit::Microliters);
        }

        [[nodiscard]] static constexpr Volume from_microliters(const un_scalar_t value)
        {
            return Volume(value, VolumeUnit::Microliters);
        }


        [[nodiscard]] constexpr un_scalar_t milliliters() const
        {
            return convert_from_base(VolumeUnit::Milliliters);
        }

        [[nodiscard]] static constexpr Volume from_milliliters(const un_scalar_t value)
        {
            return Volume(value, VolumeUnit::Milliliters);
        }


        [[nodiscard]] constexpr un_scalar_t centiliters() const
        {
            return convert_from_base(VolumeUnit::Centiliters);
        }

        [[nodiscard]] static constexpr Volume from_centiliters(const un_scalar_t value)
        {
            return Volume(value, VolumeUnit::Centiliters);
        }


        [[nodiscard]] constexpr un_scalar_t deciliters() const
        {
            return convert_from_base(VolumeUnit::Deciliters);
        }

        [[nodiscard]] static constexpr Volume from_deciliters(const un_scalar_t value)
        {
            return Volume(value, VolumeUnit::Deciliters);
        }


        [[nodiscard]] constexpr un_scalar_t decaliters() const
        {
            return convert_from_base(VolumeUnit::Decaliters);
        }

        [[nodiscard]] static constexpr Volume from_decaliters(const un_scalar_t value)
        {
            return Volume(value, VolumeUnit::Decaliters);
        }


        [[nodiscard]] constexpr un_scalar_t hectoliters() const
        {
            return convert_from_base(VolumeUnit::Hectoliters);
        }

        [[nodiscard]] static constexpr Volume from_hectoliters(const un_scalar_t value)
        {
            return Volume(value, VolumeUnit::Hectoliters);
        }


        [[nodiscard]] constexpr un_scalar_t kiloliters() const
        {
            return convert_from_base(VolumeUnit::Kiloliters);
        }

        [[nodiscard]] static constexpr Volume from_kiloliters(const un_scalar_t value)
        {
            return Volume(value, VolumeUnit::Kiloliters);
        }


        [[nodiscard]] constexpr un_scalar_t megaliters() const
        {
            return convert_from_base(VolumeUnit::Megaliters);
        }

        [[nodiscard]] static constexpr Volume from_megaliters(const un_scalar_t value)
        {
            return Volume(value, VolumeUnit::Megaliters);
        }


        [[nodiscard]] constexpr un_scalar_t cubic_meters() const
        {
            return convert_from_base(VolumeUnit::CubicMeters);
        }

        [[nodiscard]] static constexpr Volume from_cubic_meters(const un_scalar_t value)
        {
            return Volume(value, VolumeUnit::CubicMeters);
        }


        [[nodiscard]] constexpr un_scalar_t hectocubic_meters() const
        {
            return convert_from_base(VolumeUnit::HectocubicMeters);
        }

        [[nodiscard]] static constexpr Volume from_hectocubic_meters(const un_scalar_t value)
        {
            return Volume(value, VolumeUnit::HectocubicMeters);
        }


        [[nodiscard]] constexpr un_scalar_t kilocubic_meters() const
        {
            return convert_from_base(VolumeUnit::KilocubicMeters);
        }

        [[nodiscard]] static constexpr Volume from_kilocubic_meters(const un_scalar_t value)
        {
            return Volume(value, VolumeUnit::KilocubicMeters);
        }


        [[nodiscard]] constexpr un_scalar_t cubic_kilometers() const
        {
            return convert_from_base(VolumeUnit::CubicKilometers);
        }

        [[nodiscard]] static constexpr Volume from_cubic_kilometers(const un_scalar_t value)
        {
            return Volume(value, VolumeUnit::CubicKilometers);
        }


        [[nodiscard]] constexpr un_scalar_t cubic_hectometers() const
        {
            return convert_from_base(VolumeUnit::CubicHectometers);
        }

        [[nodiscard]] static constexpr Volume from_cubic_hectometers(const un_scalar_t value)
        {
            return Volume(value, VolumeUnit::CubicHectometers);
        }


        [[nodiscard]] constexpr un_scalar_t cubic_decimeters() const
        {
            return convert_from_base(VolumeUnit::CubicDecimeters);
        }

        [[nodiscard]] static constexpr Volume from_cubic_decimeters(const un_scalar_t value)
        {
            return Volume(value, VolumeUnit::CubicDecimeters);
        }


        [[nodiscard]] constexpr un_scalar_t cubic_centimeters() const
        {
            return convert_from_base(VolumeUnit::CubicCentimeters);
        }

        [[nodiscard]] static constexpr Volume from_cubic_centimeters(const un_scalar_t value)
        {
            return Volume(value, VolumeUnit::CubicCentimeters);
        }


        [[nodiscard]] constexpr un_scalar_t cubic_millimeters() const
        {
            return convert_from_base(VolumeUnit::CubicMillimeters);
        }

        [[nodiscard]] static constexpr Volume from_cubic_millimeters(const un_scalar_t value)
        {
            return Volume(value, VolumeUnit::CubicMillimeters);
        }


        [[nodiscard]] constexpr un_scalar_t cubic_micrometers() const
        {
            return convert_from_base(VolumeUnit::CubicMicrometers);
        }

        [[nodiscard]] static constexpr Volume from_cubic_micrometers(const un_scalar_t value)
        {
            return Volume(value, VolumeUnit::CubicMicrometers);
        }


        [[nodiscard]] constexpr un_scalar_t cubic_miles() const
        {
            return convert_from_base(VolumeUnit::CubicMiles);
        }

        [[nodiscard]] static constexpr Volume from_cubic_miles(const un_scalar_t value)
        {
            return Volume(value, VolumeUnit::CubicMiles);
        }


        [[nodiscard]] constexpr un_scalar_t cubic_yards() const
        {
            return convert_from_base(VolumeUnit::CubicYards);
        }

        [[nodiscard]] static constexpr Volume from_cubic_yards(const un_scalar_t value)
        {
            return Volume(value, VolumeUnit::CubicYards);
        }


        [[nodiscard]] constexpr un_scalar_t cubic_feet() const
        {
            return convert_from_base(VolumeUnit::CubicFeet);
        }

        [[nodiscard]] static constexpr Volume from_cubic_feet(const un_scalar_t value)
        {
            return Volume(value, VolumeUnit::CubicFeet);
        }


        [[nodiscard]] constexpr un_scalar_t hectocubic_feet() const
        {
            return convert_from_base(VolumeUnit::HectocubicFeet);
        }

        [[nodiscard]] static constexpr Volume from_hectocubic_feet(const un_scalar_t value)
        {
            return Volume(value, VolumeUnit::HectocubicFeet);
        }


        [[nodiscard]] constexpr un_scalar_t kilocubic_feet() const
        {
            return convert_from_base(VolumeUnit::KilocubicFeet);
        }

        [[nodiscard]] static constexpr Volume from_kilocubic_feet(const un_scalar_t value)
        {
            return Volume(value, VolumeUnit::KilocubicFeet);
        }


        [[nodiscard]] constexpr un_scalar_t megacubic_feet() const
        {
            return convert_from_base(VolumeUnit::MegacubicFeet);
        }

        [[nodiscard]] static constexpr Volume from_megacubic_feet(const un_scalar_t value)
        {
            return Volume(value, VolumeUnit::MegacubicFeet);
        }


        [[nodiscard]] constexpr un_scalar_t cubic_inches() const
        {
            return convert_from_base(VolumeUnit::CubicInches);
        }

        [[nodiscard]] static constexpr Volume from_cubic_inches(const un_scalar_t value)
        {
            return Volume(value, VolumeUnit::CubicInches);
        }


        [[nodiscard]] constexpr un_scalar_t imperial_gallons() const
        {
            return convert_from_base(VolumeUnit::ImperialGallons);
        }

        [[nodiscard]] static constexpr Volume from_imperial_gallons(const un_scalar_t value)
        {
            return Volume(value, VolumeUnit::ImperialGallons);
        }


        [[nodiscard]] constexpr un_scalar_t kiloimperial_gallons() const
        {
            return convert_from_base(VolumeUnit::KiloimperialGallons);
        }

        [[nodiscard]] static constexpr Volume from_kiloimperial_gallons(const un_scalar_t value)
        {
            return Volume(value, VolumeUnit::KiloimperialGallons);
        }


        [[nodiscard]] constexpr un_scalar_t megaimperial_gallons() const
        {
            return convert_from_base(VolumeUnit::MegaimperialGallons);
        }

        [[nodiscard]] static constexpr Volume from_megaimperial_gallons(const un_scalar_t value)
        {
            return Volume(value, VolumeUnit::MegaimperialGallons);
        }


        [[nodiscard]] constexpr un_scalar_t imperial_ounces() const
        {
            return convert_from_base(VolumeUnit::ImperialOunces);
        }

        [[nodiscard]] static constexpr Volume from_imperial_ounces(const un_scalar_t value)
        {
            return Volume(value, VolumeUnit::ImperialOunces);
        }


        [[nodiscard]] constexpr un_scalar_t us_gallons() const
        {
            return convert_from_base(VolumeUnit::UsGallons);
        }

        [[nodiscard]] static constexpr Volume from_us_gallons(const un_scalar_t value)
        {
            return Volume(value, VolumeUnit::UsGallons);
        }


        [[nodiscard]] constexpr un_scalar_t decaus_gallons() const
        {
            return convert_from_base(VolumeUnit::DecausGallons);
        }

        [[nodiscard]] static constexpr Volume from_decaus_gallons(const un_scalar_t value)
        {
            return Volume(value, VolumeUnit::DecausGallons);
        }


        [[nodiscard]] constexpr un_scalar_t decius_gallons() const
        {
            return convert_from_base(VolumeUnit::DeciusGallons);
        }

        [[nodiscard]] static constexpr Volume from_decius_gallons(const un_scalar_t value)
        {
            return Volume(value, VolumeUnit::DeciusGallons);
        }


        [[nodiscard]] constexpr un_scalar_t hectous_gallons() const
        {
            return convert_from_base(VolumeUnit::HectousGallons);
        }

        [[nodiscard]] static constexpr Volume from_hectous_gallons(const un_scalar_t value)
        {
            return Volume(value, VolumeUnit::HectousGallons);
        }


        [[nodiscard]] constexpr un_scalar_t kilous_gallons() const
        {
            return convert_from_base(VolumeUnit::KilousGallons);
        }

        [[nodiscard]] static constexpr Volume from_kilous_gallons(const un_scalar_t value)
        {
            return Volume(value, VolumeUnit::KilousGallons);
        }


        [[nodiscard]] constexpr un_scalar_t megaus_gallons() const
        {
            return convert_from_base(VolumeUnit::MegausGallons);
        }

        [[nodiscard]] static constexpr Volume from_megaus_gallons(const un_scalar_t value)
        {
            return Volume(value, VolumeUnit::MegausGallons);
        }


        [[nodiscard]] constexpr un_scalar_t us_ounces() const
        {
            return convert_from_base(VolumeUnit::UsOunces);
        }

        [[nodiscard]] static constexpr Volume from_us_ounces(const un_scalar_t value)
        {
            return Volume(value, VolumeUnit::UsOunces);
        }


        [[nodiscard]] constexpr un_scalar_t us_tablespoons() const
        {
            return convert_from_base(VolumeUnit::UsTablespoons);
        }

        [[nodiscard]] static constexpr Volume from_us_tablespoons(const un_scalar_t value)
        {
            return Volume(value, VolumeUnit::UsTablespoons);
        }


        [[nodiscard]] constexpr un_scalar_t au_tablespoons() const
        {
            return convert_from_base(VolumeUnit::AuTablespoons);
        }

        [[nodiscard]] static constexpr Volume from_au_tablespoons(const un_scalar_t value)
        {
            return Volume(value, VolumeUnit::AuTablespoons);
        }


        [[nodiscard]] constexpr un_scalar_t metric_tablespoons() const
        {
            return convert_from_base(VolumeUnit::MetricTablespoons);
        }

        [[nodiscard]] static constexpr Volume from_metric_tablespoons(const un_scalar_t value)
        {
            return Volume(value, VolumeUnit::MetricTablespoons);
        }


        [[nodiscard]] constexpr un_scalar_t uk_tablespoons() const
        {
            return convert_from_base(VolumeUnit::UkTablespoons);
        }

        [[nodiscard]] static constexpr Volume from_uk_tablespoons(const un_scalar_t value)
        {
            return Volume(value, VolumeUnit::UkTablespoons);
        }


        [[nodiscard]] constexpr un_scalar_t metric_teaspoons() const
        {
            return convert_from_base(VolumeUnit::MetricTeaspoons);
        }

        [[nodiscard]] static constexpr Volume from_metric_teaspoons(const un_scalar_t value)
        {
            return Volume(value, VolumeUnit::MetricTeaspoons);
        }


        [[nodiscard]] constexpr un_scalar_t us_teaspoons() const
        {
            return convert_from_base(VolumeUnit::UsTeaspoons);
        }

        [[nodiscard]] static constexpr Volume from_us_teaspoons(const un_scalar_t value)
        {
            return Volume(value, VolumeUnit::UsTeaspoons);
        }


        [[nodiscard]] constexpr un_scalar_t metric_cups() const
        {
            return convert_from_base(VolumeUnit::MetricCups);
        }

        [[nodiscard]] static constexpr Volume from_metric_cups(const un_scalar_t value)
        {
            return Volume(value, VolumeUnit::MetricCups);
        }


        [[nodiscard]] constexpr un_scalar_t us_customary_cups() const
        {
            return convert_from_base(VolumeUnit::UsCustomaryCups);
        }

        [[nodiscard]] static constexpr Volume from_us_customary_cups(const un_scalar_t value)
        {
            return Volume(value, VolumeUnit::UsCustomaryCups);
        }


        [[nodiscard]] constexpr un_scalar_t us_legal_cups() const
        {
            return convert_from_base(VolumeUnit::UsLegalCups);
        }

        [[nodiscard]] static constexpr Volume from_us_legal_cups(const un_scalar_t value)
        {
            return Volume(value, VolumeUnit::UsLegalCups);
        }


        [[nodiscard]] constexpr un_scalar_t oil_barrels() const
        {
            return convert_from_base(VolumeUnit::OilBarrels);
        }

        [[nodiscard]] static constexpr Volume from_oil_barrels(const un_scalar_t value)
        {
            return Volume(value, VolumeUnit::OilBarrels);
        }


        [[nodiscard]] constexpr un_scalar_t us_beer_barrels() const
        {
            return convert_from_base(VolumeUnit::UsBeerBarrels);
        }

        [[nodiscard]] static constexpr Volume from_us_beer_barrels(const un_scalar_t value)
        {
            return Volume(value, VolumeUnit::UsBeerBarrels);
        }


        [[nodiscard]] constexpr un_scalar_t imperial_beer_barrels() const
        {
            return convert_from_base(VolumeUnit::ImperialBeerBarrels);
        }

        [[nodiscard]] static constexpr Volume from_imperial_beer_barrels(const un_scalar_t value)
        {
            return Volume(value, VolumeUnit::ImperialBeerBarrels);
        }


        [[nodiscard]] constexpr un_scalar_t us_quarts() const
        {
            return convert_from_base(VolumeUnit::UsQuarts);
        }

        [[nodiscard]] static constexpr Volume from_us_quarts(const un_scalar_t value)
        {
            return Volume(value, VolumeUnit::UsQuarts);
        }


        [[nodiscard]] constexpr un_scalar_t imperial_quarts() const
        {
            return convert_from_base(VolumeUnit::ImperialQuarts);
        }

        [[nodiscard]] static constexpr Volume from_imperial_quarts(const un_scalar_t value)
        {
            return Volume(value, VolumeUnit::ImperialQuarts);
        }


        [[nodiscard]] constexpr un_scalar_t us_pints() const
        {
            return convert_from_base(VolumeUnit::UsPints);
        }

        [[nodiscard]] static constexpr Volume from_us_pints(const un_scalar_t value)
        {
            return Volume(value, VolumeUnit::UsPints);
        }


        [[nodiscard]] constexpr un_scalar_t acre_feet() const
        {
            return convert_from_base(VolumeUnit::AcreFeet);
        }

        [[nodiscard]] static constexpr Volume from_acre_feet(const un_scalar_t value)
        {
            return Volume(value, VolumeUnit::AcreFeet);
        }


        [[nodiscard]] constexpr un_scalar_t imperial_pints() const
        {
            return convert_from_base(VolumeUnit::ImperialPints);
        }

        [[nodiscard]] static constexpr Volume from_imperial_pints(const un_scalar_t value)
        {
            return Volume(value, VolumeUnit::ImperialPints);
        }


        [[nodiscard]] constexpr un_scalar_t board_feet() const
        {
            return convert_from_base(VolumeUnit::BoardFeet);
        }

        [[nodiscard]] static constexpr Volume from_board_feet(const un_scalar_t value)
        {
            return Volume(value, VolumeUnit::BoardFeet);
        }


        [[nodiscard]] static constexpr Volume from_invalid()
        {
            return Volume(false);
        }
    private:
        bool _isInvalid = false;
    
        [[nodiscard]] static constexpr un_scalar_t convert_to_base(un_scalar_t value, VolumeUnit unit)
        {
            switch (unit)
            {

            case VolumeUnit::Liters:
                return value / static_cast<un_scalar_t>(1e3);

            case VolumeUnit::Nanoliters:
                return (value * static_cast<un_scalar_t>(1e-9)) / static_cast<un_scalar_t>(1e3);

            case VolumeUnit::Microliters:
                return (value * static_cast<un_scalar_t>(1e-6)) / static_cast<un_scalar_t>(1e3);

            case VolumeUnit::Milliliters:
                return (value * static_cast<un_scalar_t>(1e-3)) / static_cast<un_scalar_t>(1e3);

            case VolumeUnit::Centiliters:
                return (value * static_cast<un_scalar_t>(1e-2)) / static_cast<un_scalar_t>(1e3);

            case VolumeUnit::Deciliters:
                return (value * static_cast<un_scalar_t>(1e-1)) / static_cast<un_scalar_t>(1e3);

            case VolumeUnit::Decaliters:
                return (value * static_cast<un_scalar_t>(1e1)) / static_cast<un_scalar_t>(1e3);

            case VolumeUnit::Hectoliters:
                return (value * static_cast<un_scalar_t>(1e2)) / static_cast<un_scalar_t>(1e3);

            case VolumeUnit::Kiloliters:
                return (value * static_cast<un_scalar_t>(1e3)) / static_cast<un_scalar_t>(1e3);

            case VolumeUnit::Megaliters:
                return (value * static_cast<un_scalar_t>(1e6)) / static_cast<un_scalar_t>(1e3);

            case VolumeUnit::CubicMeters:
                return value;

            case VolumeUnit::HectocubicMeters:
                return (value * static_cast<un_scalar_t>(1e2));

            case VolumeUnit::KilocubicMeters:
                return (value * static_cast<un_scalar_t>(1e3));

            case VolumeUnit::CubicKilometers:
                return value * static_cast<un_scalar_t>(1e9);

            case VolumeUnit::CubicHectometers:
                return value * static_cast<un_scalar_t>(1e6);

            case VolumeUnit::CubicDecimeters:
                return value / static_cast<un_scalar_t>(1e3);

            case VolumeUnit::CubicCentimeters:
                return value / static_cast<un_scalar_t>(1e6);

            case VolumeUnit::CubicMillimeters:
                return value / static_cast<un_scalar_t>(1e9);

            case VolumeUnit::CubicMicrometers:
                return value / static_cast<un_scalar_t>(1e18);

            case VolumeUnit::CubicMiles:
                return value * static_cast<un_scalar_t>(4.168181825440579584e9);

            case VolumeUnit::CubicYards:
                return value * static_cast<un_scalar_t>(0.764554857984);

            case VolumeUnit::CubicFeet:
                return value * static_cast<un_scalar_t>(0.028316846592);

            case VolumeUnit::HectocubicFeet:
                return (value * static_cast<un_scalar_t>(1e2)) * static_cast<un_scalar_t>(0.028316846592);

            case VolumeUnit::KilocubicFeet:
                return (value * static_cast<un_scalar_t>(1e3)) * static_cast<un_scalar_t>(0.028316846592);

            case VolumeUnit::MegacubicFeet:
                return (value * static_cast<un_scalar_t>(1e6)) * static_cast<un_scalar_t>(0.028316846592);

            case VolumeUnit::CubicInches:
                return value * static_cast<un_scalar_t>(1.6387064e-5);

            case VolumeUnit::ImperialGallons:
                return value * static_cast<un_scalar_t>(0.00454609);

            case VolumeUnit::KiloimperialGallons:
                return (value * static_cast<un_scalar_t>(1e3)) * static_cast<un_scalar_t>(0.00454609);

            case VolumeUnit::MegaimperialGallons:
                return (value * static_cast<un_scalar_t>(1e6)) * static_cast<un_scalar_t>(0.00454609);

            case VolumeUnit::ImperialOunces:
                return value * static_cast<un_scalar_t>(2.84130625e-5);

            case VolumeUnit::UsGallons:
                return value * static_cast<un_scalar_t>(0.003785411784);

            case VolumeUnit::DecausGallons:
                return (value * static_cast<un_scalar_t>(1e1)) * static_cast<un_scalar_t>(0.003785411784);

            case VolumeUnit::DeciusGallons:
                return (value * static_cast<un_scalar_t>(1e-1)) * static_cast<un_scalar_t>(0.003785411784);

            case VolumeUnit::HectousGallons:
                return (value * static_cast<un_scalar_t>(1e2)) * static_cast<un_scalar_t>(0.003785411784);

            case VolumeUnit::KilousGallons:
                return (value * static_cast<un_scalar_t>(1e3)) * static_cast<un_scalar_t>(0.003785411784);

            case VolumeUnit::MegausGallons:
                return (value * static_cast<un_scalar_t>(1e6)) * static_cast<un_scalar_t>(0.003785411784);

            case VolumeUnit::UsOunces:
                return value * static_cast<un_scalar_t>(2.95735295625e-5);

            case VolumeUnit::UsTablespoons:
                return value * static_cast<un_scalar_t>(1.478676478125e-5);

            case VolumeUnit::AuTablespoons:
                return value * static_cast<un_scalar_t>(2e-5);

            case VolumeUnit::MetricTablespoons:
                return value * static_cast<un_scalar_t>(1.5e-5);

            case VolumeUnit::UkTablespoons:
                return value * static_cast<un_scalar_t>(1.5e-5);

            case VolumeUnit::MetricTeaspoons:
                return value * static_cast<un_scalar_t>(0.5e-5);

            case VolumeUnit::UsTeaspoons:
                return value * static_cast<un_scalar_t>(4.92892159375e-6);

            case VolumeUnit::MetricCups:
                return value * static_cast<un_scalar_t>(0.00025);

            case VolumeUnit::UsCustomaryCups:
                return value * static_cast<un_scalar_t>(0.0002365882365);

            case VolumeUnit::UsLegalCups:
                return value * static_cast<un_scalar_t>(0.00024);

            case VolumeUnit::OilBarrels:
                return value * static_cast<un_scalar_t>(0.158987294928);

            case VolumeUnit::UsBeerBarrels:
                return value * static_cast<un_scalar_t>(0.117347765304);

            case VolumeUnit::ImperialBeerBarrels:
                return value * static_cast<un_scalar_t>(0.16365924);

            case VolumeUnit::UsQuarts:
                return value * static_cast<un_scalar_t>(9.46352946e-4);

            case VolumeUnit::ImperialQuarts:
                return value * static_cast<un_scalar_t>(1.1365225e-3);

            case VolumeUnit::UsPints:
                return value * static_cast<un_scalar_t>(4.73176473e-4);

            case VolumeUnit::AcreFeet:
                return value * static_cast<un_scalar_t>(1233.48183754752);

            case VolumeUnit::ImperialPints:
                return value * static_cast<un_scalar_t>(5.6826125e-4);

            case VolumeUnit::BoardFeet:
                return value * (static_cast<un_scalar_t>(0.028316846592) / static_cast<un_scalar_t>(12));

            }

            throw std::invalid_argument("Unknown Volume unit.");
        }

        [[nodiscard]] constexpr un_scalar_t convert_from_base(const VolumeUnit unit) const
        {
            switch (unit)
            {

            case VolumeUnit::Liters:
                return value_ * static_cast<un_scalar_t>(1e3);

            case VolumeUnit::Nanoliters:
                return (value_ * static_cast<un_scalar_t>(1e3)) / static_cast<un_scalar_t>(1e-9);

            case VolumeUnit::Microliters:
                return (value_ * static_cast<un_scalar_t>(1e3)) / static_cast<un_scalar_t>(1e-6);

            case VolumeUnit::Milliliters:
                return (value_ * static_cast<un_scalar_t>(1e3)) / static_cast<un_scalar_t>(1e-3);

            case VolumeUnit::Centiliters:
                return (value_ * static_cast<un_scalar_t>(1e3)) / static_cast<un_scalar_t>(1e-2);

            case VolumeUnit::Deciliters:
                return (value_ * static_cast<un_scalar_t>(1e3)) / static_cast<un_scalar_t>(1e-1);

            case VolumeUnit::Decaliters:
                return (value_ * static_cast<un_scalar_t>(1e3)) / static_cast<un_scalar_t>(1e1);

            case VolumeUnit::Hectoliters:
                return (value_ * static_cast<un_scalar_t>(1e3)) / static_cast<un_scalar_t>(1e2);

            case VolumeUnit::Kiloliters:
                return (value_ * static_cast<un_scalar_t>(1e3)) / static_cast<un_scalar_t>(1e3);

            case VolumeUnit::Megaliters:
                return (value_ * static_cast<un_scalar_t>(1e3)) / static_cast<un_scalar_t>(1e6);

            case VolumeUnit::CubicMeters:
                return value_;

            case VolumeUnit::HectocubicMeters:
                return (value_) / static_cast<un_scalar_t>(1e2);

            case VolumeUnit::KilocubicMeters:
                return (value_) / static_cast<un_scalar_t>(1e3);

            case VolumeUnit::CubicKilometers:
                return value_ / static_cast<un_scalar_t>(1e9);

            case VolumeUnit::CubicHectometers:
                return value_ / static_cast<un_scalar_t>(1e6);

            case VolumeUnit::CubicDecimeters:
                return value_ * static_cast<un_scalar_t>(1e3);

            case VolumeUnit::CubicCentimeters:
                return value_ * static_cast<un_scalar_t>(1e6);

            case VolumeUnit::CubicMillimeters:
                return value_ * static_cast<un_scalar_t>(1e9);

            case VolumeUnit::CubicMicrometers:
                return value_ * static_cast<un_scalar_t>(1e18);

            case VolumeUnit::CubicMiles:
                return value_ / static_cast<un_scalar_t>(4.168181825440579584e9);

            case VolumeUnit::CubicYards:
                return value_ / static_cast<un_scalar_t>(0.764554857984);

            case VolumeUnit::CubicFeet:
                return value_ / static_cast<un_scalar_t>(0.028316846592);

            case VolumeUnit::HectocubicFeet:
                return (value_ / static_cast<un_scalar_t>(0.028316846592)) / static_cast<un_scalar_t>(1e2);

            case VolumeUnit::KilocubicFeet:
                return (value_ / static_cast<un_scalar_t>(0.028316846592)) / static_cast<un_scalar_t>(1e3);

            case VolumeUnit::MegacubicFeet:
                return (value_ / static_cast<un_scalar_t>(0.028316846592)) / static_cast<un_scalar_t>(1e6);

            case VolumeUnit::CubicInches:
                return value_ / static_cast<un_scalar_t>(1.6387064e-5);

            case VolumeUnit::ImperialGallons:
                return value_ / static_cast<un_scalar_t>(0.00454609);

            case VolumeUnit::KiloimperialGallons:
                return (value_ / static_cast<un_scalar_t>(0.00454609)) / static_cast<un_scalar_t>(1e3);

            case VolumeUnit::MegaimperialGallons:
                return (value_ / static_cast<un_scalar_t>(0.00454609)) / static_cast<un_scalar_t>(1e6);

            case VolumeUnit::ImperialOunces:
                return value_ / static_cast<un_scalar_t>(2.84130625e-5);

            case VolumeUnit::UsGallons:
                return value_ / static_cast<un_scalar_t>(0.003785411784);

            case VolumeUnit::DecausGallons:
                return (value_ / static_cast<un_scalar_t>(0.003785411784)) / static_cast<un_scalar_t>(1e1);

            case VolumeUnit::DeciusGallons:
                return (value_ / static_cast<un_scalar_t>(0.003785411784)) / static_cast<un_scalar_t>(1e-1);

            case VolumeUnit::HectousGallons:
                return (value_ / static_cast<un_scalar_t>(0.003785411784)) / static_cast<un_scalar_t>(1e2);

            case VolumeUnit::KilousGallons:
                return (value_ / static_cast<un_scalar_t>(0.003785411784)) / static_cast<un_scalar_t>(1e3);

            case VolumeUnit::MegausGallons:
                return (value_ / static_cast<un_scalar_t>(0.003785411784)) / static_cast<un_scalar_t>(1e6);

            case VolumeUnit::UsOunces:
                return value_ / static_cast<un_scalar_t>(2.95735295625e-5);

            case VolumeUnit::UsTablespoons:
                return value_ / static_cast<un_scalar_t>(1.478676478125e-5);

            case VolumeUnit::AuTablespoons:
                return value_ / static_cast<un_scalar_t>(2e-5);

            case VolumeUnit::MetricTablespoons:
                return value_ / static_cast<un_scalar_t>(1.5e-5);

            case VolumeUnit::UkTablespoons:
                return value_ / static_cast<un_scalar_t>(1.5e-5);

            case VolumeUnit::MetricTeaspoons:
                return value_ / static_cast<un_scalar_t>(0.5e-5);

            case VolumeUnit::UsTeaspoons:
                return value_ / static_cast<un_scalar_t>(4.92892159375e-6);

            case VolumeUnit::MetricCups:
                return value_ / static_cast<un_scalar_t>(0.00025);

            case VolumeUnit::UsCustomaryCups:
                return value_ / static_cast<un_scalar_t>(0.0002365882365);

            case VolumeUnit::UsLegalCups:
                return value_ / static_cast<un_scalar_t>(0.00024);

            case VolumeUnit::OilBarrels:
                return value_ / static_cast<un_scalar_t>(0.158987294928);

            case VolumeUnit::UsBeerBarrels:
                return value_ / static_cast<un_scalar_t>(0.117347765304);

            case VolumeUnit::ImperialBeerBarrels:
                return value_ / static_cast<un_scalar_t>(0.16365924);

            case VolumeUnit::UsQuarts:
                return value_ / static_cast<un_scalar_t>(9.46352946e-4);

            case VolumeUnit::ImperialQuarts:
                return value_ / static_cast<un_scalar_t>(1.1365225e-3);

            case VolumeUnit::UsPints:
                return value_ / static_cast<un_scalar_t>(4.73176473e-4);

            case VolumeUnit::AcreFeet:
                return value_ / static_cast<un_scalar_t>(1233.48183754752);

            case VolumeUnit::ImperialPints:
                return value_ / static_cast<un_scalar_t>(5.6826125e-4);

            case VolumeUnit::BoardFeet:
                return value_ / (static_cast<un_scalar_t>(0.028316846592) / static_cast<un_scalar_t>(12));

            }

            throw std::invalid_argument("Unknown Volume unit.");
        }

        un_scalar_t value_;
    };
}
