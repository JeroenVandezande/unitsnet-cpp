#pragma once

#include <cstdint>
#include <numbers>
#include <stdexcept>
#include "UnitsNetConfig.h"
#include "UnitsNetBase.h"

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
    class Volume : public UnitsNetBase
    {
    public:
        constexpr explicit Volume(
            const un_scalar_t value,
            const VolumeUnit unit = VolumeUnit::CubicMeters)
        {
            value_ = value;
            value_unit_type_ = unit;
        }
                
        [[nodiscard]] constexpr un_scalar_t base_value() const noexcept
        {
            return convert_to_base(value_, value_unit_type_);    
        }

        [[nodiscard]] constexpr un_scalar_t value(const VolumeUnit unit) const
        {
            return convert_from_base(unit);
        }

        [[nodiscard]] constexpr Volume operator+(const Volume& other) const noexcept
        {
            return Volume(base_value() + other.base_value());
        }

        [[nodiscard]] constexpr Volume operator-(const Volume& other)const noexcept
        {
            return Volume(base_value() - other.base_value());
        }

        [[nodiscard]] constexpr Volume operator*(const un_scalar_t scalar) const noexcept
        {
            return Volume(base_value() * scalar);
        }

        [[nodiscard]] constexpr Volume operator/(const un_scalar_t scalar) const noexcept
        {
            return Volume(base_value() / scalar);
        }

        [[nodiscard]] constexpr bool operator==(const Volume& other) const noexcept
        {
            return base_value() == other.base_value();
        }

        [[nodiscard]] constexpr bool operator<(const Volume& other) const noexcept
        {
            return base_value() < other.base_value();
        }
        
        [[nodiscard]] constexpr bool operator>(const Volume& other) const noexcept
        {
            return base_value() > other.base_value();
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

        /// <summary>A cubic mile (abbreviation: cu mi or mi3) is an imperial and US customary (non-SI non-metric) unit of volume, used in the United States, Canada and the United Kingdom. It is defined as the volume of a cube with sides of 1 mile (63360 inches, 5280 feet, 1760 yards or ~1.609 kilometres) in length.</summary>
        [[nodiscard]] constexpr un_scalar_t cubic_miles() const
        {
            return convert_from_base(VolumeUnit::CubicMiles);
        }

        /// <summary>A cubic mile (abbreviation: cu mi or mi3) is an imperial and US customary (non-SI non-metric) unit of volume, used in the United States, Canada and the United Kingdom. It is defined as the volume of a cube with sides of 1 mile (63360 inches, 5280 feet, 1760 yards or ~1.609 kilometres) in length.</summary>
        [[nodiscard]] static constexpr Volume from_cubic_miles(const un_scalar_t value)
        {
            return Volume(value, VolumeUnit::CubicMiles);
        }

        /// <summary>A cubic yard is an Imperial / U.S. customary (non-SI non-metric) unit of volume, used in Canada and the United States. It is defined as the volume of a cube with sides of 1 yard (3 feet, 36 inches, 0.9144 meters) in length.</summary>
        [[nodiscard]] constexpr un_scalar_t cubic_yards() const
        {
            return convert_from_base(VolumeUnit::CubicYards);
        }

        /// <summary>A cubic yard is an Imperial / U.S. customary (non-SI non-metric) unit of volume, used in Canada and the United States. It is defined as the volume of a cube with sides of 1 yard (3 feet, 36 inches, 0.9144 meters) in length.</summary>
        [[nodiscard]] static constexpr Volume from_cubic_yards(const un_scalar_t value)
        {
            return Volume(value, VolumeUnit::CubicYards);
        }

        /// <summary>The cubic foot (symbol ft3 or cu ft) is an imperial and US customary (non-metric) unit of volume, used in the United States and the United Kingdom. It is defined as the volume of a cube with sides of one foot (0.3048 m) in length.</summary>
        [[nodiscard]] constexpr un_scalar_t cubic_feet() const
        {
            return convert_from_base(VolumeUnit::CubicFeet);
        }

        /// <summary>The cubic foot (symbol ft3 or cu ft) is an imperial and US customary (non-metric) unit of volume, used in the United States and the United Kingdom. It is defined as the volume of a cube with sides of one foot (0.3048 m) in length.</summary>
        [[nodiscard]] static constexpr Volume from_cubic_feet(const un_scalar_t value)
        {
            return Volume(value, VolumeUnit::CubicFeet);
        }

        /// <summary>The cubic foot (symbol ft3 or cu ft) is an imperial and US customary (non-metric) unit of volume, used in the United States and the United Kingdom. It is defined as the volume of a cube with sides of one foot (0.3048 m) in length.</summary>
        [[nodiscard]] constexpr un_scalar_t hectocubic_feet() const
        {
            return convert_from_base(VolumeUnit::HectocubicFeet);
        }

        /// <summary>The cubic foot (symbol ft3 or cu ft) is an imperial and US customary (non-metric) unit of volume, used in the United States and the United Kingdom. It is defined as the volume of a cube with sides of one foot (0.3048 m) in length.</summary>
        [[nodiscard]] static constexpr Volume from_hectocubic_feet(const un_scalar_t value)
        {
            return Volume(value, VolumeUnit::HectocubicFeet);
        }

        /// <summary>The cubic foot (symbol ft3 or cu ft) is an imperial and US customary (non-metric) unit of volume, used in the United States and the United Kingdom. It is defined as the volume of a cube with sides of one foot (0.3048 m) in length.</summary>
        [[nodiscard]] constexpr un_scalar_t kilocubic_feet() const
        {
            return convert_from_base(VolumeUnit::KilocubicFeet);
        }

        /// <summary>The cubic foot (symbol ft3 or cu ft) is an imperial and US customary (non-metric) unit of volume, used in the United States and the United Kingdom. It is defined as the volume of a cube with sides of one foot (0.3048 m) in length.</summary>
        [[nodiscard]] static constexpr Volume from_kilocubic_feet(const un_scalar_t value)
        {
            return Volume(value, VolumeUnit::KilocubicFeet);
        }

        /// <summary>The cubic foot (symbol ft3 or cu ft) is an imperial and US customary (non-metric) unit of volume, used in the United States and the United Kingdom. It is defined as the volume of a cube with sides of one foot (0.3048 m) in length.</summary>
        [[nodiscard]] constexpr un_scalar_t megacubic_feet() const
        {
            return convert_from_base(VolumeUnit::MegacubicFeet);
        }

        /// <summary>The cubic foot (symbol ft3 or cu ft) is an imperial and US customary (non-metric) unit of volume, used in the United States and the United Kingdom. It is defined as the volume of a cube with sides of one foot (0.3048 m) in length.</summary>
        [[nodiscard]] static constexpr Volume from_megacubic_feet(const un_scalar_t value)
        {
            return Volume(value, VolumeUnit::MegacubicFeet);
        }

        /// <summary>The cubic inch (symbol in3) is a unit of volume in the Imperial units and United States customary units systems. It is the volume of a cube with each of its three dimensions (length, width, and height) being one inch long which is equivalent to 1/231 of a US gallon.</summary>
        [[nodiscard]] constexpr un_scalar_t cubic_inches() const
        {
            return convert_from_base(VolumeUnit::CubicInches);
        }

        /// <summary>The cubic inch (symbol in3) is a unit of volume in the Imperial units and United States customary units systems. It is the volume of a cube with each of its three dimensions (length, width, and height) being one inch long which is equivalent to 1/231 of a US gallon.</summary>
        [[nodiscard]] static constexpr Volume from_cubic_inches(const un_scalar_t value)
        {
            return Volume(value, VolumeUnit::CubicInches);
        }

        /// <summary>The British imperial gallon (frequently called simply "gallon") is defined as exactly 4.54609 litres.</summary>
        [[nodiscard]] constexpr un_scalar_t imperial_gallons() const
        {
            return convert_from_base(VolumeUnit::ImperialGallons);
        }

        /// <summary>The British imperial gallon (frequently called simply "gallon") is defined as exactly 4.54609 litres.</summary>
        [[nodiscard]] static constexpr Volume from_imperial_gallons(const un_scalar_t value)
        {
            return Volume(value, VolumeUnit::ImperialGallons);
        }

        /// <summary>The British imperial gallon (frequently called simply "gallon") is defined as exactly 4.54609 litres.</summary>
        [[nodiscard]] constexpr un_scalar_t kiloimperial_gallons() const
        {
            return convert_from_base(VolumeUnit::KiloimperialGallons);
        }

        /// <summary>The British imperial gallon (frequently called simply "gallon") is defined as exactly 4.54609 litres.</summary>
        [[nodiscard]] static constexpr Volume from_kiloimperial_gallons(const un_scalar_t value)
        {
            return Volume(value, VolumeUnit::KiloimperialGallons);
        }

        /// <summary>The British imperial gallon (frequently called simply "gallon") is defined as exactly 4.54609 litres.</summary>
        [[nodiscard]] constexpr un_scalar_t megaimperial_gallons() const
        {
            return convert_from_base(VolumeUnit::MegaimperialGallons);
        }

        /// <summary>The British imperial gallon (frequently called simply "gallon") is defined as exactly 4.54609 litres.</summary>
        [[nodiscard]] static constexpr Volume from_megaimperial_gallons(const un_scalar_t value)
        {
            return Volume(value, VolumeUnit::MegaimperialGallons);
        }

        /// <summary>An imperial fluid ounce is 1⁄20 of an imperial pint, 1⁄160 of an imperial gallon or exactly 28.4130625 mL.</summary>
        [[nodiscard]] constexpr un_scalar_t imperial_ounces() const
        {
            return convert_from_base(VolumeUnit::ImperialOunces);
        }

        /// <summary>An imperial fluid ounce is 1⁄20 of an imperial pint, 1⁄160 of an imperial gallon or exactly 28.4130625 mL.</summary>
        [[nodiscard]] static constexpr Volume from_imperial_ounces(const un_scalar_t value)
        {
            return Volume(value, VolumeUnit::ImperialOunces);
        }

        /// <summary>The US liquid gallon (frequently called simply "gallon") is legally defined as 231 cubic inches, which is exactly 3.785411784 litres.</summary>
        [[nodiscard]] constexpr un_scalar_t us_gallons() const
        {
            return convert_from_base(VolumeUnit::UsGallons);
        }

        /// <summary>The US liquid gallon (frequently called simply "gallon") is legally defined as 231 cubic inches, which is exactly 3.785411784 litres.</summary>
        [[nodiscard]] static constexpr Volume from_us_gallons(const un_scalar_t value)
        {
            return Volume(value, VolumeUnit::UsGallons);
        }

        /// <summary>The US liquid gallon (frequently called simply "gallon") is legally defined as 231 cubic inches, which is exactly 3.785411784 litres.</summary>
        [[nodiscard]] constexpr un_scalar_t decaus_gallons() const
        {
            return convert_from_base(VolumeUnit::DecausGallons);
        }

        /// <summary>The US liquid gallon (frequently called simply "gallon") is legally defined as 231 cubic inches, which is exactly 3.785411784 litres.</summary>
        [[nodiscard]] static constexpr Volume from_decaus_gallons(const un_scalar_t value)
        {
            return Volume(value, VolumeUnit::DecausGallons);
        }

        /// <summary>The US liquid gallon (frequently called simply "gallon") is legally defined as 231 cubic inches, which is exactly 3.785411784 litres.</summary>
        [[nodiscard]] constexpr un_scalar_t decius_gallons() const
        {
            return convert_from_base(VolumeUnit::DeciusGallons);
        }

        /// <summary>The US liquid gallon (frequently called simply "gallon") is legally defined as 231 cubic inches, which is exactly 3.785411784 litres.</summary>
        [[nodiscard]] static constexpr Volume from_decius_gallons(const un_scalar_t value)
        {
            return Volume(value, VolumeUnit::DeciusGallons);
        }

        /// <summary>The US liquid gallon (frequently called simply "gallon") is legally defined as 231 cubic inches, which is exactly 3.785411784 litres.</summary>
        [[nodiscard]] constexpr un_scalar_t hectous_gallons() const
        {
            return convert_from_base(VolumeUnit::HectousGallons);
        }

        /// <summary>The US liquid gallon (frequently called simply "gallon") is legally defined as 231 cubic inches, which is exactly 3.785411784 litres.</summary>
        [[nodiscard]] static constexpr Volume from_hectous_gallons(const un_scalar_t value)
        {
            return Volume(value, VolumeUnit::HectousGallons);
        }

        /// <summary>The US liquid gallon (frequently called simply "gallon") is legally defined as 231 cubic inches, which is exactly 3.785411784 litres.</summary>
        [[nodiscard]] constexpr un_scalar_t kilous_gallons() const
        {
            return convert_from_base(VolumeUnit::KilousGallons);
        }

        /// <summary>The US liquid gallon (frequently called simply "gallon") is legally defined as 231 cubic inches, which is exactly 3.785411784 litres.</summary>
        [[nodiscard]] static constexpr Volume from_kilous_gallons(const un_scalar_t value)
        {
            return Volume(value, VolumeUnit::KilousGallons);
        }

        /// <summary>The US liquid gallon (frequently called simply "gallon") is legally defined as 231 cubic inches, which is exactly 3.785411784 litres.</summary>
        [[nodiscard]] constexpr un_scalar_t megaus_gallons() const
        {
            return convert_from_base(VolumeUnit::MegausGallons);
        }

        /// <summary>The US liquid gallon (frequently called simply "gallon") is legally defined as 231 cubic inches, which is exactly 3.785411784 litres.</summary>
        [[nodiscard]] static constexpr Volume from_megaus_gallons(const un_scalar_t value)
        {
            return Volume(value, VolumeUnit::MegausGallons);
        }

        /// <summary>A US customary fluid ounce is 1⁄16 of a US liquid pint and 1⁄128 of a US liquid gallon or exactly 29.5735295625 mL, making it about 4.08% larger than the imperial fluid ounce.</summary>
        [[nodiscard]] constexpr un_scalar_t us_ounces() const
        {
            return convert_from_base(VolumeUnit::UsOunces);
        }

        /// <summary>A US customary fluid ounce is 1⁄16 of a US liquid pint and 1⁄128 of a US liquid gallon or exactly 29.5735295625 mL, making it about 4.08% larger than the imperial fluid ounce.</summary>
        [[nodiscard]] static constexpr Volume from_us_ounces(const un_scalar_t value)
        {
            return Volume(value, VolumeUnit::UsOunces);
        }

        /// <summary>The traditional U.S. interpretation of the tablespoon as a unit of volume is: 1 US tablespoon = 4 fluid drams, or 3 teaspoons or 1/2 US fluid ounce (≈ 14.8 ml)</summary>
        [[nodiscard]] constexpr un_scalar_t us_tablespoons() const
        {
            return convert_from_base(VolumeUnit::UsTablespoons);
        }

        /// <summary>The traditional U.S. interpretation of the tablespoon as a unit of volume is: 1 US tablespoon = 4 fluid drams, or 3 teaspoons or 1/2 US fluid ounce (≈ 14.8 ml)</summary>
        [[nodiscard]] static constexpr Volume from_us_tablespoons(const un_scalar_t value)
        {
            return Volume(value, VolumeUnit::UsTablespoons);
        }

        /// <summary>In Australia, the definition of the tablespoon is 20 ml (0.70 imp fl oz).</summary>
        [[nodiscard]] constexpr un_scalar_t au_tablespoons() const
        {
            return convert_from_base(VolumeUnit::AuTablespoons);
        }

        /// <summary>In Australia, the definition of the tablespoon is 20 ml (0.70 imp fl oz).</summary>
        [[nodiscard]] static constexpr Volume from_au_tablespoons(const un_scalar_t value)
        {
            return Volume(value, VolumeUnit::AuTablespoons);
        }

        /// <summary>An international metric tablespoon is exactly equal to 15 mL. It is the equivalence of 1⁠ 1/2 metric dessert spoons or 3 metric teaspoons.</summary>
        [[nodiscard]] constexpr un_scalar_t metric_tablespoons() const
        {
            return convert_from_base(VolumeUnit::MetricTablespoons);
        }

        /// <summary>An international metric tablespoon is exactly equal to 15 mL. It is the equivalence of 1⁠ 1/2 metric dessert spoons or 3 metric teaspoons.</summary>
        [[nodiscard]] static constexpr Volume from_metric_tablespoons(const un_scalar_t value)
        {
            return Volume(value, VolumeUnit::MetricTablespoons);
        }

        /// <summary>In nutrition labeling in the U.S. and the U.K., a tablespoon is defined as 15 ml (0.51 US fl oz). In Australia, the definition of the tablespoon is 20 ml (0.70 imp fl oz).</summary>
        [[nodiscard]] constexpr un_scalar_t uk_tablespoons() const
        {
            return convert_from_base(VolumeUnit::UkTablespoons);
        }

        /// <summary>In nutrition labeling in the U.S. and the U.K., a tablespoon is defined as 15 ml (0.51 US fl oz). In Australia, the definition of the tablespoon is 20 ml (0.70 imp fl oz).</summary>
        [[nodiscard]] static constexpr Volume from_uk_tablespoons(const un_scalar_t value)
        {
            return Volume(value, VolumeUnit::UkTablespoons);
        }

        /// <summary>The metric teaspoon as a unit of culinary measure is 5 ml (0.18 imp fl oz; 0.17 US fl oz),[17] equal to 5 cm3, 1⁄3 UK/Canadian metric tablespoon, or 1⁄4 Australian metric tablespoon.</summary>
        [[nodiscard]] constexpr un_scalar_t metric_teaspoons() const
        {
            return convert_from_base(VolumeUnit::MetricTeaspoons);
        }

        /// <summary>The metric teaspoon as a unit of culinary measure is 5 ml (0.18 imp fl oz; 0.17 US fl oz),[17] equal to 5 cm3, 1⁄3 UK/Canadian metric tablespoon, or 1⁄4 Australian metric tablespoon.</summary>
        [[nodiscard]] static constexpr Volume from_metric_teaspoons(const un_scalar_t value)
        {
            return Volume(value, VolumeUnit::MetricTeaspoons);
        }

        /// <summary>As a unit of culinary measure, one teaspoon in the United States is 1⁄3 tablespoon, exactly 4.92892159375 ml, 1 1⁄3 US fluid drams, 1⁄6 US fl oz, 1⁄48 US cup, 1⁄768 US liquid gallon, or 77⁄256 (0.30078125) cubic inches.</summary>
        [[nodiscard]] constexpr un_scalar_t us_teaspoons() const
        {
            return convert_from_base(VolumeUnit::UsTeaspoons);
        }

        /// <summary>As a unit of culinary measure, one teaspoon in the United States is 1⁄3 tablespoon, exactly 4.92892159375 ml, 1 1⁄3 US fluid drams, 1⁄6 US fl oz, 1⁄48 US cup, 1⁄768 US liquid gallon, or 77⁄256 (0.30078125) cubic inches.</summary>
        [[nodiscard]] static constexpr Volume from_us_teaspoons(const un_scalar_t value)
        {
            return Volume(value, VolumeUnit::UsTeaspoons);
        }

        /// <summary>Australia, Canada, New Zealand, and some other members of the Commonwealth of Nations, being former British colonies that have since metricated, employ a metric cup of 250 millilitres. Although derived from the metric system, it is not an SI unit.</summary>
        [[nodiscard]] constexpr un_scalar_t metric_cups() const
        {
            return convert_from_base(VolumeUnit::MetricCups);
        }

        /// <summary>Australia, Canada, New Zealand, and some other members of the Commonwealth of Nations, being former British colonies that have since metricated, employ a metric cup of 250 millilitres. Although derived from the metric system, it is not an SI unit.</summary>
        [[nodiscard]] static constexpr Volume from_metric_cups(const un_scalar_t value)
        {
            return Volume(value, VolumeUnit::MetricCups);
        }

        /// <summary>In the United States, the customary cup is half of a liquid pint or 1⁄16 US customary gallon which is 236.5882365 milliliters exactly.</summary>
        [[nodiscard]] constexpr un_scalar_t us_customary_cups() const
        {
            return convert_from_base(VolumeUnit::UsCustomaryCups);
        }

        /// <summary>In the United States, the customary cup is half of a liquid pint or 1⁄16 US customary gallon which is 236.5882365 milliliters exactly.</summary>
        [[nodiscard]] static constexpr Volume from_us_customary_cups(const un_scalar_t value)
        {
            return Volume(value, VolumeUnit::UsCustomaryCups);
        }

        /// <summary>The cup currently used in the United States for nutrition labelling is defined in United States law as 240 ml.</summary>
        [[nodiscard]] constexpr un_scalar_t us_legal_cups() const
        {
            return convert_from_base(VolumeUnit::UsLegalCups);
        }

        /// <summary>The cup currently used in the United States for nutrition labelling is defined in United States law as 240 ml.</summary>
        [[nodiscard]] static constexpr Volume from_us_legal_cups(const un_scalar_t value)
        {
            return Volume(value, VolumeUnit::UsLegalCups);
        }

        /// <summary>In the oil industry, one barrel (unit symbol bbl) is a unit of volume used for measuring oil defined as exactly 42 US gallons, approximately 159 liters, or 35 imperial gallons.</summary>
        [[nodiscard]] constexpr un_scalar_t oil_barrels() const
        {
            return convert_from_base(VolumeUnit::OilBarrels);
        }

        /// <summary>In the oil industry, one barrel (unit symbol bbl) is a unit of volume used for measuring oil defined as exactly 42 US gallons, approximately 159 liters, or 35 imperial gallons.</summary>
        [[nodiscard]] static constexpr Volume from_oil_barrels(const un_scalar_t value)
        {
            return Volume(value, VolumeUnit::OilBarrels);
        }

        /// <summary>Fluid barrels vary depending on what is being measured and where. In the US most fluid barrels (apart from oil) are 31.5 US gallons (26 imp gal; 119 L) (half a hogshead), but a beer barrel is 31 US gallons (26 imp gal; 117 L).</summary>
        [[nodiscard]] constexpr un_scalar_t us_beer_barrels() const
        {
            return convert_from_base(VolumeUnit::UsBeerBarrels);
        }

        /// <summary>Fluid barrels vary depending on what is being measured and where. In the US most fluid barrels (apart from oil) are 31.5 US gallons (26 imp gal; 119 L) (half a hogshead), but a beer barrel is 31 US gallons (26 imp gal; 117 L).</summary>
        [[nodiscard]] static constexpr Volume from_us_beer_barrels(const un_scalar_t value)
        {
            return Volume(value, VolumeUnit::UsBeerBarrels);
        }

        /// <summary>Fluid barrels vary depending on what is being measured and where. In the UK a beer barrel is 36 imperial gallons (43 US gal; ~164 L).</summary>
        [[nodiscard]] constexpr un_scalar_t imperial_beer_barrels() const
        {
            return convert_from_base(VolumeUnit::ImperialBeerBarrels);
        }

        /// <summary>Fluid barrels vary depending on what is being measured and where. In the UK a beer barrel is 36 imperial gallons (43 US gal; ~164 L).</summary>
        [[nodiscard]] static constexpr Volume from_imperial_beer_barrels(const un_scalar_t value)
        {
            return Volume(value, VolumeUnit::ImperialBeerBarrels);
        }

        /// <summary>The US liquid quart equals 57.75 cubic inches, which is exactly equal to 0.946352946 L.</summary>
        [[nodiscard]] constexpr un_scalar_t us_quarts() const
        {
            return convert_from_base(VolumeUnit::UsQuarts);
        }

        /// <summary>The US liquid quart equals 57.75 cubic inches, which is exactly equal to 0.946352946 L.</summary>
        [[nodiscard]] static constexpr Volume from_us_quarts(const un_scalar_t value)
        {
            return Volume(value, VolumeUnit::UsQuarts);
        }

        /// <summary>The imperial quart, which is used for both liquid and dry capacity, is equal to one quarter of an imperial gallon, or exactly 1.1365225 liters.</summary>
        [[nodiscard]] constexpr un_scalar_t imperial_quarts() const
        {
            return convert_from_base(VolumeUnit::ImperialQuarts);
        }

        /// <summary>The imperial quart, which is used for both liquid and dry capacity, is equal to one quarter of an imperial gallon, or exactly 1.1365225 liters.</summary>
        [[nodiscard]] static constexpr Volume from_imperial_quarts(const un_scalar_t value)
        {
            return Volume(value, VolumeUnit::ImperialQuarts);
        }

        /// <summary>The pint is a unit of volume or capacity in both the imperial and United States customary measurement systems. In both of those systems it is traditionally one eighth of a gallon. The British imperial pint is about 20% larger than the American pint because the two systems are defined differently.</summary>
        [[nodiscard]] constexpr un_scalar_t us_pints() const
        {
            return convert_from_base(VolumeUnit::UsPints);
        }

        /// <summary>The pint is a unit of volume or capacity in both the imperial and United States customary measurement systems. In both of those systems it is traditionally one eighth of a gallon. The British imperial pint is about 20% larger than the American pint because the two systems are defined differently.</summary>
        [[nodiscard]] static constexpr Volume from_us_pints(const un_scalar_t value)
        {
            return Volume(value, VolumeUnit::UsPints);
        }

        /// <summary>An acre-foot is 43,560 cubic feet (~1,233.5 m3).</summary>
        [[nodiscard]] constexpr un_scalar_t acre_feet() const
        {
            return convert_from_base(VolumeUnit::AcreFeet);
        }

        /// <summary>An acre-foot is 43,560 cubic feet (~1,233.5 m3).</summary>
        [[nodiscard]] static constexpr Volume from_acre_feet(const un_scalar_t value)
        {
            return Volume(value, VolumeUnit::AcreFeet);
        }

        /// <summary>The pint is a unit of volume or capacity in both the imperial and United States customary measurement systems. In both of those systems it is traditionally one eighth of a gallon. The British imperial pint is about 20% larger than the American pint because the two systems are defined differently.</summary>
        [[nodiscard]] constexpr un_scalar_t imperial_pints() const
        {
            return convert_from_base(VolumeUnit::ImperialPints);
        }

        /// <summary>The pint is a unit of volume or capacity in both the imperial and United States customary measurement systems. In both of those systems it is traditionally one eighth of a gallon. The British imperial pint is about 20% larger than the American pint because the two systems are defined differently.</summary>
        [[nodiscard]] static constexpr Volume from_imperial_pints(const un_scalar_t value)
        {
            return Volume(value, VolumeUnit::ImperialPints);
        }

        /// <summary>The board foot or board-foot is a unit of measurement for the volume of lumber in the United States and Canada. It equals the volume of a board that is one-foot (305 mm) in length, one-foot (305 mm) in width, and one-inch (25.4 mm) in thickness.</summary>
        [[nodiscard]] constexpr un_scalar_t board_feet() const
        {
            return convert_from_base(VolumeUnit::BoardFeet);
        }

        /// <summary>The board foot or board-foot is a unit of measurement for the volume of lumber in the United States and Canada. It equals the volume of a board that is one-foot (305 mm) in length, one-foot (305 mm) in width, and one-inch (25.4 mm) in thickness.</summary>
        [[nodiscard]] static constexpr Volume from_board_feet(const un_scalar_t value)
        {
            return Volume(value, VolumeUnit::BoardFeet);
        }

        [[nodiscard]] static constexpr Volume from_invalid()
        {
            return Volume(false);
        }
    private:
            
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
            if(unit == value_unit_type_)
            {
                return value_;
            }
            
            auto base_value = convert_to_base(value_, value_unit_type_);
            
            switch (unit)
            {

            case VolumeUnit::Liters:
                return base_value * static_cast<un_scalar_t>(1e3);

            case VolumeUnit::Nanoliters:
                return (base_value * static_cast<un_scalar_t>(1e3)) / static_cast<un_scalar_t>(1e-9);

            case VolumeUnit::Microliters:
                return (base_value * static_cast<un_scalar_t>(1e3)) / static_cast<un_scalar_t>(1e-6);

            case VolumeUnit::Milliliters:
                return (base_value * static_cast<un_scalar_t>(1e3)) / static_cast<un_scalar_t>(1e-3);

            case VolumeUnit::Centiliters:
                return (base_value * static_cast<un_scalar_t>(1e3)) / static_cast<un_scalar_t>(1e-2);

            case VolumeUnit::Deciliters:
                return (base_value * static_cast<un_scalar_t>(1e3)) / static_cast<un_scalar_t>(1e-1);

            case VolumeUnit::Decaliters:
                return (base_value * static_cast<un_scalar_t>(1e3)) / static_cast<un_scalar_t>(1e1);

            case VolumeUnit::Hectoliters:
                return (base_value * static_cast<un_scalar_t>(1e3)) / static_cast<un_scalar_t>(1e2);

            case VolumeUnit::Kiloliters:
                return (base_value * static_cast<un_scalar_t>(1e3)) / static_cast<un_scalar_t>(1e3);

            case VolumeUnit::Megaliters:
                return (base_value * static_cast<un_scalar_t>(1e3)) / static_cast<un_scalar_t>(1e6);

            case VolumeUnit::CubicMeters:
                return base_value;

            case VolumeUnit::HectocubicMeters:
                return (base_value) / static_cast<un_scalar_t>(1e2);

            case VolumeUnit::KilocubicMeters:
                return (base_value) / static_cast<un_scalar_t>(1e3);

            case VolumeUnit::CubicKilometers:
                return base_value / static_cast<un_scalar_t>(1e9);

            case VolumeUnit::CubicHectometers:
                return base_value / static_cast<un_scalar_t>(1e6);

            case VolumeUnit::CubicDecimeters:
                return base_value * static_cast<un_scalar_t>(1e3);

            case VolumeUnit::CubicCentimeters:
                return base_value * static_cast<un_scalar_t>(1e6);

            case VolumeUnit::CubicMillimeters:
                return base_value * static_cast<un_scalar_t>(1e9);

            case VolumeUnit::CubicMicrometers:
                return base_value * static_cast<un_scalar_t>(1e18);

            case VolumeUnit::CubicMiles:
                return base_value / static_cast<un_scalar_t>(4.168181825440579584e9);

            case VolumeUnit::CubicYards:
                return base_value / static_cast<un_scalar_t>(0.764554857984);

            case VolumeUnit::CubicFeet:
                return base_value / static_cast<un_scalar_t>(0.028316846592);

            case VolumeUnit::HectocubicFeet:
                return (base_value / static_cast<un_scalar_t>(0.028316846592)) / static_cast<un_scalar_t>(1e2);

            case VolumeUnit::KilocubicFeet:
                return (base_value / static_cast<un_scalar_t>(0.028316846592)) / static_cast<un_scalar_t>(1e3);

            case VolumeUnit::MegacubicFeet:
                return (base_value / static_cast<un_scalar_t>(0.028316846592)) / static_cast<un_scalar_t>(1e6);

            case VolumeUnit::CubicInches:
                return base_value / static_cast<un_scalar_t>(1.6387064e-5);

            case VolumeUnit::ImperialGallons:
                return base_value / static_cast<un_scalar_t>(0.00454609);

            case VolumeUnit::KiloimperialGallons:
                return (base_value / static_cast<un_scalar_t>(0.00454609)) / static_cast<un_scalar_t>(1e3);

            case VolumeUnit::MegaimperialGallons:
                return (base_value / static_cast<un_scalar_t>(0.00454609)) / static_cast<un_scalar_t>(1e6);

            case VolumeUnit::ImperialOunces:
                return base_value / static_cast<un_scalar_t>(2.84130625e-5);

            case VolumeUnit::UsGallons:
                return base_value / static_cast<un_scalar_t>(0.003785411784);

            case VolumeUnit::DecausGallons:
                return (base_value / static_cast<un_scalar_t>(0.003785411784)) / static_cast<un_scalar_t>(1e1);

            case VolumeUnit::DeciusGallons:
                return (base_value / static_cast<un_scalar_t>(0.003785411784)) / static_cast<un_scalar_t>(1e-1);

            case VolumeUnit::HectousGallons:
                return (base_value / static_cast<un_scalar_t>(0.003785411784)) / static_cast<un_scalar_t>(1e2);

            case VolumeUnit::KilousGallons:
                return (base_value / static_cast<un_scalar_t>(0.003785411784)) / static_cast<un_scalar_t>(1e3);

            case VolumeUnit::MegausGallons:
                return (base_value / static_cast<un_scalar_t>(0.003785411784)) / static_cast<un_scalar_t>(1e6);

            case VolumeUnit::UsOunces:
                return base_value / static_cast<un_scalar_t>(2.95735295625e-5);

            case VolumeUnit::UsTablespoons:
                return base_value / static_cast<un_scalar_t>(1.478676478125e-5);

            case VolumeUnit::AuTablespoons:
                return base_value / static_cast<un_scalar_t>(2e-5);

            case VolumeUnit::MetricTablespoons:
                return base_value / static_cast<un_scalar_t>(1.5e-5);

            case VolumeUnit::UkTablespoons:
                return base_value / static_cast<un_scalar_t>(1.5e-5);

            case VolumeUnit::MetricTeaspoons:
                return base_value / static_cast<un_scalar_t>(0.5e-5);

            case VolumeUnit::UsTeaspoons:
                return base_value / static_cast<un_scalar_t>(4.92892159375e-6);

            case VolumeUnit::MetricCups:
                return base_value / static_cast<un_scalar_t>(0.00025);

            case VolumeUnit::UsCustomaryCups:
                return base_value / static_cast<un_scalar_t>(0.0002365882365);

            case VolumeUnit::UsLegalCups:
                return base_value / static_cast<un_scalar_t>(0.00024);

            case VolumeUnit::OilBarrels:
                return base_value / static_cast<un_scalar_t>(0.158987294928);

            case VolumeUnit::UsBeerBarrels:
                return base_value / static_cast<un_scalar_t>(0.117347765304);

            case VolumeUnit::ImperialBeerBarrels:
                return base_value / static_cast<un_scalar_t>(0.16365924);

            case VolumeUnit::UsQuarts:
                return base_value / static_cast<un_scalar_t>(9.46352946e-4);

            case VolumeUnit::ImperialQuarts:
                return base_value / static_cast<un_scalar_t>(1.1365225e-3);

            case VolumeUnit::UsPints:
                return base_value / static_cast<un_scalar_t>(4.73176473e-4);

            case VolumeUnit::AcreFeet:
                return base_value / static_cast<un_scalar_t>(1233.48183754752);

            case VolumeUnit::ImperialPints:
                return base_value / static_cast<un_scalar_t>(5.6826125e-4);

            case VolumeUnit::BoardFeet:
                return base_value / (static_cast<un_scalar_t>(0.028316846592) / static_cast<un_scalar_t>(12));

            }

            throw std::invalid_argument("Unknown Volume unit.");
        }

        un_scalar_t value_;
        VolumeUnit value_unit_type_;       
    };
}
