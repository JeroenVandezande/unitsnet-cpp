#pragma once

#include <cstdint>
#include <numbers>
#include <stdexcept>

namespace unitsnet_cpp
{
    enum class VolumeUnit : std::uint16_t
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
            double value,
            VolumeUnit unit = VolumeUnit::CubicMeters)
            : value_(convert_to_base(value, unit))
        {
        }

        [[nodiscard]] constexpr double base_value() const noexcept
        {
            return value_;
        }

        [[nodiscard]] constexpr double value(VolumeUnit unit) const
        {
            return convert_from_base(unit);
        }

        [[nodiscard]] constexpr Volume operator+(Volume other) const noexcept
        {
            return Volume(value_ + other.value_);
        }

        [[nodiscard]] constexpr Volume operator-(Volume other) const noexcept
        {
            return Volume(value_ - other.value_);
        }

        [[nodiscard]] constexpr Volume operator*(double scalar) const noexcept
        {
            return Volume(value_ * scalar);
        }

        [[nodiscard]] constexpr Volume operator/(double scalar) const noexcept
        {
            return Volume(value_ / scalar);
        }

        [[nodiscard]] constexpr bool operator==(Volume other) const noexcept
        {
            return value_ == other.value_;
        }

        [[nodiscard]] constexpr bool operator<(Volume other) const noexcept
        {
            return value_ < other.value_;
        }


        [[nodiscard]] constexpr double liters() const
        {
            return convert_from_base(VolumeUnit::Liters);
        }

        [[nodiscard]] static constexpr Volume from_liters(double value)
        {
            return Volume(value, VolumeUnit::Liters);
        }


        [[nodiscard]] constexpr double nanoliters() const
        {
            return convert_from_base(VolumeUnit::Nanoliters);
        }

        [[nodiscard]] static constexpr Volume from_nanoliters(double value)
        {
            return Volume(value, VolumeUnit::Nanoliters);
        }


        [[nodiscard]] constexpr double microliters() const
        {
            return convert_from_base(VolumeUnit::Microliters);
        }

        [[nodiscard]] static constexpr Volume from_microliters(double value)
        {
            return Volume(value, VolumeUnit::Microliters);
        }


        [[nodiscard]] constexpr double milliliters() const
        {
            return convert_from_base(VolumeUnit::Milliliters);
        }

        [[nodiscard]] static constexpr Volume from_milliliters(double value)
        {
            return Volume(value, VolumeUnit::Milliliters);
        }


        [[nodiscard]] constexpr double centiliters() const
        {
            return convert_from_base(VolumeUnit::Centiliters);
        }

        [[nodiscard]] static constexpr Volume from_centiliters(double value)
        {
            return Volume(value, VolumeUnit::Centiliters);
        }


        [[nodiscard]] constexpr double deciliters() const
        {
            return convert_from_base(VolumeUnit::Deciliters);
        }

        [[nodiscard]] static constexpr Volume from_deciliters(double value)
        {
            return Volume(value, VolumeUnit::Deciliters);
        }


        [[nodiscard]] constexpr double decaliters() const
        {
            return convert_from_base(VolumeUnit::Decaliters);
        }

        [[nodiscard]] static constexpr Volume from_decaliters(double value)
        {
            return Volume(value, VolumeUnit::Decaliters);
        }


        [[nodiscard]] constexpr double hectoliters() const
        {
            return convert_from_base(VolumeUnit::Hectoliters);
        }

        [[nodiscard]] static constexpr Volume from_hectoliters(double value)
        {
            return Volume(value, VolumeUnit::Hectoliters);
        }


        [[nodiscard]] constexpr double kiloliters() const
        {
            return convert_from_base(VolumeUnit::Kiloliters);
        }

        [[nodiscard]] static constexpr Volume from_kiloliters(double value)
        {
            return Volume(value, VolumeUnit::Kiloliters);
        }


        [[nodiscard]] constexpr double megaliters() const
        {
            return convert_from_base(VolumeUnit::Megaliters);
        }

        [[nodiscard]] static constexpr Volume from_megaliters(double value)
        {
            return Volume(value, VolumeUnit::Megaliters);
        }


        [[nodiscard]] constexpr double cubic_meters() const
        {
            return convert_from_base(VolumeUnit::CubicMeters);
        }

        [[nodiscard]] static constexpr Volume from_cubic_meters(double value)
        {
            return Volume(value, VolumeUnit::CubicMeters);
        }


        [[nodiscard]] constexpr double hectocubic_meters() const
        {
            return convert_from_base(VolumeUnit::HectocubicMeters);
        }

        [[nodiscard]] static constexpr Volume from_hectocubic_meters(double value)
        {
            return Volume(value, VolumeUnit::HectocubicMeters);
        }


        [[nodiscard]] constexpr double kilocubic_meters() const
        {
            return convert_from_base(VolumeUnit::KilocubicMeters);
        }

        [[nodiscard]] static constexpr Volume from_kilocubic_meters(double value)
        {
            return Volume(value, VolumeUnit::KilocubicMeters);
        }


        [[nodiscard]] constexpr double cubic_kilometers() const
        {
            return convert_from_base(VolumeUnit::CubicKilometers);
        }

        [[nodiscard]] static constexpr Volume from_cubic_kilometers(double value)
        {
            return Volume(value, VolumeUnit::CubicKilometers);
        }


        [[nodiscard]] constexpr double cubic_hectometers() const
        {
            return convert_from_base(VolumeUnit::CubicHectometers);
        }

        [[nodiscard]] static constexpr Volume from_cubic_hectometers(double value)
        {
            return Volume(value, VolumeUnit::CubicHectometers);
        }


        [[nodiscard]] constexpr double cubic_decimeters() const
        {
            return convert_from_base(VolumeUnit::CubicDecimeters);
        }

        [[nodiscard]] static constexpr Volume from_cubic_decimeters(double value)
        {
            return Volume(value, VolumeUnit::CubicDecimeters);
        }


        [[nodiscard]] constexpr double cubic_centimeters() const
        {
            return convert_from_base(VolumeUnit::CubicCentimeters);
        }

        [[nodiscard]] static constexpr Volume from_cubic_centimeters(double value)
        {
            return Volume(value, VolumeUnit::CubicCentimeters);
        }


        [[nodiscard]] constexpr double cubic_millimeters() const
        {
            return convert_from_base(VolumeUnit::CubicMillimeters);
        }

        [[nodiscard]] static constexpr Volume from_cubic_millimeters(double value)
        {
            return Volume(value, VolumeUnit::CubicMillimeters);
        }


        [[nodiscard]] constexpr double cubic_micrometers() const
        {
            return convert_from_base(VolumeUnit::CubicMicrometers);
        }

        [[nodiscard]] static constexpr Volume from_cubic_micrometers(double value)
        {
            return Volume(value, VolumeUnit::CubicMicrometers);
        }


        [[nodiscard]] constexpr double cubic_miles() const
        {
            return convert_from_base(VolumeUnit::CubicMiles);
        }

        [[nodiscard]] static constexpr Volume from_cubic_miles(double value)
        {
            return Volume(value, VolumeUnit::CubicMiles);
        }


        [[nodiscard]] constexpr double cubic_yards() const
        {
            return convert_from_base(VolumeUnit::CubicYards);
        }

        [[nodiscard]] static constexpr Volume from_cubic_yards(double value)
        {
            return Volume(value, VolumeUnit::CubicYards);
        }


        [[nodiscard]] constexpr double cubic_feet() const
        {
            return convert_from_base(VolumeUnit::CubicFeet);
        }

        [[nodiscard]] static constexpr Volume from_cubic_feet(double value)
        {
            return Volume(value, VolumeUnit::CubicFeet);
        }


        [[nodiscard]] constexpr double hectocubic_feet() const
        {
            return convert_from_base(VolumeUnit::HectocubicFeet);
        }

        [[nodiscard]] static constexpr Volume from_hectocubic_feet(double value)
        {
            return Volume(value, VolumeUnit::HectocubicFeet);
        }


        [[nodiscard]] constexpr double kilocubic_feet() const
        {
            return convert_from_base(VolumeUnit::KilocubicFeet);
        }

        [[nodiscard]] static constexpr Volume from_kilocubic_feet(double value)
        {
            return Volume(value, VolumeUnit::KilocubicFeet);
        }


        [[nodiscard]] constexpr double megacubic_feet() const
        {
            return convert_from_base(VolumeUnit::MegacubicFeet);
        }

        [[nodiscard]] static constexpr Volume from_megacubic_feet(double value)
        {
            return Volume(value, VolumeUnit::MegacubicFeet);
        }


        [[nodiscard]] constexpr double cubic_inches() const
        {
            return convert_from_base(VolumeUnit::CubicInches);
        }

        [[nodiscard]] static constexpr Volume from_cubic_inches(double value)
        {
            return Volume(value, VolumeUnit::CubicInches);
        }


        [[nodiscard]] constexpr double imperial_gallons() const
        {
            return convert_from_base(VolumeUnit::ImperialGallons);
        }

        [[nodiscard]] static constexpr Volume from_imperial_gallons(double value)
        {
            return Volume(value, VolumeUnit::ImperialGallons);
        }


        [[nodiscard]] constexpr double kiloimperial_gallons() const
        {
            return convert_from_base(VolumeUnit::KiloimperialGallons);
        }

        [[nodiscard]] static constexpr Volume from_kiloimperial_gallons(double value)
        {
            return Volume(value, VolumeUnit::KiloimperialGallons);
        }


        [[nodiscard]] constexpr double megaimperial_gallons() const
        {
            return convert_from_base(VolumeUnit::MegaimperialGallons);
        }

        [[nodiscard]] static constexpr Volume from_megaimperial_gallons(double value)
        {
            return Volume(value, VolumeUnit::MegaimperialGallons);
        }


        [[nodiscard]] constexpr double imperial_ounces() const
        {
            return convert_from_base(VolumeUnit::ImperialOunces);
        }

        [[nodiscard]] static constexpr Volume from_imperial_ounces(double value)
        {
            return Volume(value, VolumeUnit::ImperialOunces);
        }


        [[nodiscard]] constexpr double us_gallons() const
        {
            return convert_from_base(VolumeUnit::UsGallons);
        }

        [[nodiscard]] static constexpr Volume from_us_gallons(double value)
        {
            return Volume(value, VolumeUnit::UsGallons);
        }


        [[nodiscard]] constexpr double decaus_gallons() const
        {
            return convert_from_base(VolumeUnit::DecausGallons);
        }

        [[nodiscard]] static constexpr Volume from_decaus_gallons(double value)
        {
            return Volume(value, VolumeUnit::DecausGallons);
        }


        [[nodiscard]] constexpr double decius_gallons() const
        {
            return convert_from_base(VolumeUnit::DeciusGallons);
        }

        [[nodiscard]] static constexpr Volume from_decius_gallons(double value)
        {
            return Volume(value, VolumeUnit::DeciusGallons);
        }


        [[nodiscard]] constexpr double hectous_gallons() const
        {
            return convert_from_base(VolumeUnit::HectousGallons);
        }

        [[nodiscard]] static constexpr Volume from_hectous_gallons(double value)
        {
            return Volume(value, VolumeUnit::HectousGallons);
        }


        [[nodiscard]] constexpr double kilous_gallons() const
        {
            return convert_from_base(VolumeUnit::KilousGallons);
        }

        [[nodiscard]] static constexpr Volume from_kilous_gallons(double value)
        {
            return Volume(value, VolumeUnit::KilousGallons);
        }


        [[nodiscard]] constexpr double megaus_gallons() const
        {
            return convert_from_base(VolumeUnit::MegausGallons);
        }

        [[nodiscard]] static constexpr Volume from_megaus_gallons(double value)
        {
            return Volume(value, VolumeUnit::MegausGallons);
        }


        [[nodiscard]] constexpr double us_ounces() const
        {
            return convert_from_base(VolumeUnit::UsOunces);
        }

        [[nodiscard]] static constexpr Volume from_us_ounces(double value)
        {
            return Volume(value, VolumeUnit::UsOunces);
        }


        [[nodiscard]] constexpr double us_tablespoons() const
        {
            return convert_from_base(VolumeUnit::UsTablespoons);
        }

        [[nodiscard]] static constexpr Volume from_us_tablespoons(double value)
        {
            return Volume(value, VolumeUnit::UsTablespoons);
        }


        [[nodiscard]] constexpr double au_tablespoons() const
        {
            return convert_from_base(VolumeUnit::AuTablespoons);
        }

        [[nodiscard]] static constexpr Volume from_au_tablespoons(double value)
        {
            return Volume(value, VolumeUnit::AuTablespoons);
        }


        [[nodiscard]] constexpr double metric_tablespoons() const
        {
            return convert_from_base(VolumeUnit::MetricTablespoons);
        }

        [[nodiscard]] static constexpr Volume from_metric_tablespoons(double value)
        {
            return Volume(value, VolumeUnit::MetricTablespoons);
        }


        [[nodiscard]] constexpr double uk_tablespoons() const
        {
            return convert_from_base(VolumeUnit::UkTablespoons);
        }

        [[nodiscard]] static constexpr Volume from_uk_tablespoons(double value)
        {
            return Volume(value, VolumeUnit::UkTablespoons);
        }


        [[nodiscard]] constexpr double metric_teaspoons() const
        {
            return convert_from_base(VolumeUnit::MetricTeaspoons);
        }

        [[nodiscard]] static constexpr Volume from_metric_teaspoons(double value)
        {
            return Volume(value, VolumeUnit::MetricTeaspoons);
        }


        [[nodiscard]] constexpr double us_teaspoons() const
        {
            return convert_from_base(VolumeUnit::UsTeaspoons);
        }

        [[nodiscard]] static constexpr Volume from_us_teaspoons(double value)
        {
            return Volume(value, VolumeUnit::UsTeaspoons);
        }


        [[nodiscard]] constexpr double metric_cups() const
        {
            return convert_from_base(VolumeUnit::MetricCups);
        }

        [[nodiscard]] static constexpr Volume from_metric_cups(double value)
        {
            return Volume(value, VolumeUnit::MetricCups);
        }


        [[nodiscard]] constexpr double us_customary_cups() const
        {
            return convert_from_base(VolumeUnit::UsCustomaryCups);
        }

        [[nodiscard]] static constexpr Volume from_us_customary_cups(double value)
        {
            return Volume(value, VolumeUnit::UsCustomaryCups);
        }


        [[nodiscard]] constexpr double us_legal_cups() const
        {
            return convert_from_base(VolumeUnit::UsLegalCups);
        }

        [[nodiscard]] static constexpr Volume from_us_legal_cups(double value)
        {
            return Volume(value, VolumeUnit::UsLegalCups);
        }


        [[nodiscard]] constexpr double oil_barrels() const
        {
            return convert_from_base(VolumeUnit::OilBarrels);
        }

        [[nodiscard]] static constexpr Volume from_oil_barrels(double value)
        {
            return Volume(value, VolumeUnit::OilBarrels);
        }


        [[nodiscard]] constexpr double us_beer_barrels() const
        {
            return convert_from_base(VolumeUnit::UsBeerBarrels);
        }

        [[nodiscard]] static constexpr Volume from_us_beer_barrels(double value)
        {
            return Volume(value, VolumeUnit::UsBeerBarrels);
        }


        [[nodiscard]] constexpr double imperial_beer_barrels() const
        {
            return convert_from_base(VolumeUnit::ImperialBeerBarrels);
        }

        [[nodiscard]] static constexpr Volume from_imperial_beer_barrels(double value)
        {
            return Volume(value, VolumeUnit::ImperialBeerBarrels);
        }


        [[nodiscard]] constexpr double us_quarts() const
        {
            return convert_from_base(VolumeUnit::UsQuarts);
        }

        [[nodiscard]] static constexpr Volume from_us_quarts(double value)
        {
            return Volume(value, VolumeUnit::UsQuarts);
        }


        [[nodiscard]] constexpr double imperial_quarts() const
        {
            return convert_from_base(VolumeUnit::ImperialQuarts);
        }

        [[nodiscard]] static constexpr Volume from_imperial_quarts(double value)
        {
            return Volume(value, VolumeUnit::ImperialQuarts);
        }


        [[nodiscard]] constexpr double us_pints() const
        {
            return convert_from_base(VolumeUnit::UsPints);
        }

        [[nodiscard]] static constexpr Volume from_us_pints(double value)
        {
            return Volume(value, VolumeUnit::UsPints);
        }


        [[nodiscard]] constexpr double acre_feet() const
        {
            return convert_from_base(VolumeUnit::AcreFeet);
        }

        [[nodiscard]] static constexpr Volume from_acre_feet(double value)
        {
            return Volume(value, VolumeUnit::AcreFeet);
        }


        [[nodiscard]] constexpr double imperial_pints() const
        {
            return convert_from_base(VolumeUnit::ImperialPints);
        }

        [[nodiscard]] static constexpr Volume from_imperial_pints(double value)
        {
            return Volume(value, VolumeUnit::ImperialPints);
        }


        [[nodiscard]] constexpr double board_feet() const
        {
            return convert_from_base(VolumeUnit::BoardFeet);
        }

        [[nodiscard]] static constexpr Volume from_board_feet(double value)
        {
            return Volume(value, VolumeUnit::BoardFeet);
        }


    private:
        [[nodiscard]] static constexpr double convert_to_base(double value, VolumeUnit unit)
        {
            switch (unit)
            {

            case VolumeUnit::Liters:
                return value / 1e3;

            case VolumeUnit::Nanoliters:
                return (value * 1e-9) / 1e3;

            case VolumeUnit::Microliters:
                return (value * 1e-6) / 1e3;

            case VolumeUnit::Milliliters:
                return (value * 1e-3) / 1e3;

            case VolumeUnit::Centiliters:
                return (value * 1e-2) / 1e3;

            case VolumeUnit::Deciliters:
                return (value * 1e-1) / 1e3;

            case VolumeUnit::Decaliters:
                return (value * 1e1) / 1e3;

            case VolumeUnit::Hectoliters:
                return (value * 1e2) / 1e3;

            case VolumeUnit::Kiloliters:
                return (value * 1e3) / 1e3;

            case VolumeUnit::Megaliters:
                return (value * 1e6) / 1e3;

            case VolumeUnit::CubicMeters:
                return value;

            case VolumeUnit::HectocubicMeters:
                return (value * 1e2);

            case VolumeUnit::KilocubicMeters:
                return (value * 1e3);

            case VolumeUnit::CubicKilometers:
                return value * 1e9;

            case VolumeUnit::CubicHectometers:
                return value * 1e6;

            case VolumeUnit::CubicDecimeters:
                return value / 1e3;

            case VolumeUnit::CubicCentimeters:
                return value / 1e6;

            case VolumeUnit::CubicMillimeters:
                return value / 1e9;

            case VolumeUnit::CubicMicrometers:
                return value / 1e18;

            case VolumeUnit::CubicMiles:
                return value * 4.168181825440579584e9;

            case VolumeUnit::CubicYards:
                return value * 0.764554857984;

            case VolumeUnit::CubicFeet:
                return value * 0.028316846592;

            case VolumeUnit::HectocubicFeet:
                return (value * 1e2) * 0.028316846592;

            case VolumeUnit::KilocubicFeet:
                return (value * 1e3) * 0.028316846592;

            case VolumeUnit::MegacubicFeet:
                return (value * 1e6) * 0.028316846592;

            case VolumeUnit::CubicInches:
                return value * 1.6387064e-5;

            case VolumeUnit::ImperialGallons:
                return value * 0.00454609;

            case VolumeUnit::KiloimperialGallons:
                return (value * 1e3) * 0.00454609;

            case VolumeUnit::MegaimperialGallons:
                return (value * 1e6) * 0.00454609;

            case VolumeUnit::ImperialOunces:
                return value * 2.84130625e-5;

            case VolumeUnit::UsGallons:
                return value * 0.003785411784;

            case VolumeUnit::DecausGallons:
                return (value * 1e1) * 0.003785411784;

            case VolumeUnit::DeciusGallons:
                return (value * 1e-1) * 0.003785411784;

            case VolumeUnit::HectousGallons:
                return (value * 1e2) * 0.003785411784;

            case VolumeUnit::KilousGallons:
                return (value * 1e3) * 0.003785411784;

            case VolumeUnit::MegausGallons:
                return (value * 1e6) * 0.003785411784;

            case VolumeUnit::UsOunces:
                return value * 2.95735295625e-5;

            case VolumeUnit::UsTablespoons:
                return value * 1.478676478125e-5;

            case VolumeUnit::AuTablespoons:
                return value * 2e-5;

            case VolumeUnit::MetricTablespoons:
                return value * 1.5e-5;

            case VolumeUnit::UkTablespoons:
                return value * 1.5e-5;

            case VolumeUnit::MetricTeaspoons:
                return value * 0.5e-5;

            case VolumeUnit::UsTeaspoons:
                return value * 4.92892159375e-6;

            case VolumeUnit::MetricCups:
                return value * 0.00025;

            case VolumeUnit::UsCustomaryCups:
                return value * 0.0002365882365;

            case VolumeUnit::UsLegalCups:
                return value * 0.00024;

            case VolumeUnit::OilBarrels:
                return value * 0.158987294928;

            case VolumeUnit::UsBeerBarrels:
                return value * 0.117347765304;

            case VolumeUnit::ImperialBeerBarrels:
                return value * 0.16365924;

            case VolumeUnit::UsQuarts:
                return value * 9.46352946e-4;

            case VolumeUnit::ImperialQuarts:
                return value * 1.1365225e-3;

            case VolumeUnit::UsPints:
                return value * 4.73176473e-4;

            case VolumeUnit::AcreFeet:
                return value * 1233.48183754752;

            case VolumeUnit::ImperialPints:
                return value * 5.6826125e-4;

            case VolumeUnit::BoardFeet:
                return value * (0.028316846592 / 12);

            }

            throw std::invalid_argument("Unknown Volume unit.");
        }

        [[nodiscard]] constexpr double convert_from_base(VolumeUnit unit) const
        {
            switch (unit)
            {

            case VolumeUnit::Liters:
                return value_ * 1e3;

            case VolumeUnit::Nanoliters:
                return (value_ * 1e3) / 1e-9;

            case VolumeUnit::Microliters:
                return (value_ * 1e3) / 1e-6;

            case VolumeUnit::Milliliters:
                return (value_ * 1e3) / 1e-3;

            case VolumeUnit::Centiliters:
                return (value_ * 1e3) / 1e-2;

            case VolumeUnit::Deciliters:
                return (value_ * 1e3) / 1e-1;

            case VolumeUnit::Decaliters:
                return (value_ * 1e3) / 1e1;

            case VolumeUnit::Hectoliters:
                return (value_ * 1e3) / 1e2;

            case VolumeUnit::Kiloliters:
                return (value_ * 1e3) / 1e3;

            case VolumeUnit::Megaliters:
                return (value_ * 1e3) / 1e6;

            case VolumeUnit::CubicMeters:
                return value_;

            case VolumeUnit::HectocubicMeters:
                return (value_) / 1e2;

            case VolumeUnit::KilocubicMeters:
                return (value_) / 1e3;

            case VolumeUnit::CubicKilometers:
                return value_ / 1e9;

            case VolumeUnit::CubicHectometers:
                return value_ / 1e6;

            case VolumeUnit::CubicDecimeters:
                return value_ * 1e3;

            case VolumeUnit::CubicCentimeters:
                return value_ * 1e6;

            case VolumeUnit::CubicMillimeters:
                return value_ * 1e9;

            case VolumeUnit::CubicMicrometers:
                return value_ * 1e18;

            case VolumeUnit::CubicMiles:
                return value_ / 4.168181825440579584e9;

            case VolumeUnit::CubicYards:
                return value_ / 0.764554857984;

            case VolumeUnit::CubicFeet:
                return value_ / 0.028316846592;

            case VolumeUnit::HectocubicFeet:
                return (value_ / 0.028316846592) / 1e2;

            case VolumeUnit::KilocubicFeet:
                return (value_ / 0.028316846592) / 1e3;

            case VolumeUnit::MegacubicFeet:
                return (value_ / 0.028316846592) / 1e6;

            case VolumeUnit::CubicInches:
                return value_ / 1.6387064e-5;

            case VolumeUnit::ImperialGallons:
                return value_ / 0.00454609;

            case VolumeUnit::KiloimperialGallons:
                return (value_ / 0.00454609) / 1e3;

            case VolumeUnit::MegaimperialGallons:
                return (value_ / 0.00454609) / 1e6;

            case VolumeUnit::ImperialOunces:
                return value_ / 2.84130625e-5;

            case VolumeUnit::UsGallons:
                return value_ / 0.003785411784;

            case VolumeUnit::DecausGallons:
                return (value_ / 0.003785411784) / 1e1;

            case VolumeUnit::DeciusGallons:
                return (value_ / 0.003785411784) / 1e-1;

            case VolumeUnit::HectousGallons:
                return (value_ / 0.003785411784) / 1e2;

            case VolumeUnit::KilousGallons:
                return (value_ / 0.003785411784) / 1e3;

            case VolumeUnit::MegausGallons:
                return (value_ / 0.003785411784) / 1e6;

            case VolumeUnit::UsOunces:
                return value_ / 2.95735295625e-5;

            case VolumeUnit::UsTablespoons:
                return value_ / 1.478676478125e-5;

            case VolumeUnit::AuTablespoons:
                return value_ / 2e-5;

            case VolumeUnit::MetricTablespoons:
                return value_ / 1.5e-5;

            case VolumeUnit::UkTablespoons:
                return value_ / 1.5e-5;

            case VolumeUnit::MetricTeaspoons:
                return value_ / 0.5e-5;

            case VolumeUnit::UsTeaspoons:
                return value_ / 4.92892159375e-6;

            case VolumeUnit::MetricCups:
                return value_ / 0.00025;

            case VolumeUnit::UsCustomaryCups:
                return value_ / 0.0002365882365;

            case VolumeUnit::UsLegalCups:
                return value_ / 0.00024;

            case VolumeUnit::OilBarrels:
                return value_ / 0.158987294928;

            case VolumeUnit::UsBeerBarrels:
                return value_ / 0.117347765304;

            case VolumeUnit::ImperialBeerBarrels:
                return value_ / 0.16365924;

            case VolumeUnit::UsQuarts:
                return value_ / 9.46352946e-4;

            case VolumeUnit::ImperialQuarts:
                return value_ / 1.1365225e-3;

            case VolumeUnit::UsPints:
                return value_ / 4.73176473e-4;

            case VolumeUnit::AcreFeet:
                return value_ / 1233.48183754752;

            case VolumeUnit::ImperialPints:
                return value_ / 5.6826125e-4;

            case VolumeUnit::BoardFeet:
                return value_ / (0.028316846592 / 12);

            }

            throw std::invalid_argument("Unknown Volume unit.");
        }

        double value_;
    };
}
