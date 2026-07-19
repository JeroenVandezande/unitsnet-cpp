#pragma once

#include <cstdint>
#include <numbers>
#include <stdexcept>
#include "UnitsNetConfig.h"

namespace unitsnet_cpp
{
    enum class MassUnit : std::uint8_t
    {
        Grams,
        Femtograms,
        Picograms,
        Nanograms,
        Micrograms,
        Milligrams,
        Centigrams,
        Decigrams,
        Decagrams,
        Hectograms,
        Kilograms,
        Tonnes,
        Kilotonnes,
        Megatonnes,
        ShortTons,
        LongTons,
        Pounds,
        Kilopounds,
        Megapounds,
        Ounces,
        Slugs,
        Stone,
        ShortHundredweight,
        LongHundredweight,
        Grains,
        SolarMasses,
        EarthMasses,
        Daltons,
        Kilodaltons,
        Megadaltons,
        Gigadaltons,
    };

    /// <summary>In physics, mass (from Greek μᾶζα "barley cake, lump [of dough]") is a property of a physical system or body, giving rise to the phenomena of the body's resistance to being accelerated by a force and the strength of its mutual gravitational attraction with other bodies. Instruments such as mass balances or scales use those phenomena to measure mass. The SI unit of mass is the kilogram (kg).</summary>
    class Mass
    {
    public:
        constexpr explicit Mass(
            const un_scalar_t value,
            const MassUnit unit = MassUnit::Kilograms)
            : value_(convert_to_base(value, unit))
        {
        }
        
        constexpr explicit Mass(const bool isValid)
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

        [[nodiscard]] constexpr un_scalar_t value(const MassUnit unit) const
        {
            return convert_from_base(unit);
        }

        [[nodiscard]] constexpr Mass operator+(const Mass other) const noexcept
        {
            return Mass(value_ + other.value_);
        }

        [[nodiscard]] constexpr Mass operator-(const Mass other) const noexcept
        {
            return Mass(value_ - other.value_);
        }

        [[nodiscard]] constexpr Mass operator*(const un_scalar_t scalar) const noexcept
        {
            return Mass(value_ * scalar);
        }

        [[nodiscard]] constexpr Mass operator/(const un_scalar_t scalar) const noexcept
        {
            return Mass(value_ / scalar);
        }

        [[nodiscard]] constexpr bool operator==(const Mass other) const noexcept
        {
            return value_ == other.value_;
        }

        [[nodiscard]] constexpr bool operator<(const Mass other) const noexcept
        {
            return value_ < other.value_;
        }
        
        [[nodiscard]] constexpr bool operator>(const Mass other) const noexcept
        {
            return value_ > other.value_;
        }


        [[nodiscard]] constexpr un_scalar_t grams() const
        {
            return convert_from_base(MassUnit::Grams);
        }

        [[nodiscard]] static constexpr Mass from_grams(const un_scalar_t value)
        {
            return Mass(value, MassUnit::Grams);
        }


        [[nodiscard]] constexpr un_scalar_t femtograms() const
        {
            return convert_from_base(MassUnit::Femtograms);
        }

        [[nodiscard]] static constexpr Mass from_femtograms(const un_scalar_t value)
        {
            return Mass(value, MassUnit::Femtograms);
        }


        [[nodiscard]] constexpr un_scalar_t picograms() const
        {
            return convert_from_base(MassUnit::Picograms);
        }

        [[nodiscard]] static constexpr Mass from_picograms(const un_scalar_t value)
        {
            return Mass(value, MassUnit::Picograms);
        }


        [[nodiscard]] constexpr un_scalar_t nanograms() const
        {
            return convert_from_base(MassUnit::Nanograms);
        }

        [[nodiscard]] static constexpr Mass from_nanograms(const un_scalar_t value)
        {
            return Mass(value, MassUnit::Nanograms);
        }


        [[nodiscard]] constexpr un_scalar_t micrograms() const
        {
            return convert_from_base(MassUnit::Micrograms);
        }

        [[nodiscard]] static constexpr Mass from_micrograms(const un_scalar_t value)
        {
            return Mass(value, MassUnit::Micrograms);
        }


        [[nodiscard]] constexpr un_scalar_t milligrams() const
        {
            return convert_from_base(MassUnit::Milligrams);
        }

        [[nodiscard]] static constexpr Mass from_milligrams(const un_scalar_t value)
        {
            return Mass(value, MassUnit::Milligrams);
        }


        [[nodiscard]] constexpr un_scalar_t centigrams() const
        {
            return convert_from_base(MassUnit::Centigrams);
        }

        [[nodiscard]] static constexpr Mass from_centigrams(const un_scalar_t value)
        {
            return Mass(value, MassUnit::Centigrams);
        }


        [[nodiscard]] constexpr un_scalar_t decigrams() const
        {
            return convert_from_base(MassUnit::Decigrams);
        }

        [[nodiscard]] static constexpr Mass from_decigrams(const un_scalar_t value)
        {
            return Mass(value, MassUnit::Decigrams);
        }


        [[nodiscard]] constexpr un_scalar_t decagrams() const
        {
            return convert_from_base(MassUnit::Decagrams);
        }

        [[nodiscard]] static constexpr Mass from_decagrams(const un_scalar_t value)
        {
            return Mass(value, MassUnit::Decagrams);
        }


        [[nodiscard]] constexpr un_scalar_t hectograms() const
        {
            return convert_from_base(MassUnit::Hectograms);
        }

        [[nodiscard]] static constexpr Mass from_hectograms(const un_scalar_t value)
        {
            return Mass(value, MassUnit::Hectograms);
        }


        [[nodiscard]] constexpr un_scalar_t kilograms() const
        {
            return convert_from_base(MassUnit::Kilograms);
        }

        [[nodiscard]] static constexpr Mass from_kilograms(const un_scalar_t value)
        {
            return Mass(value, MassUnit::Kilograms);
        }


        /// <summary>The tonne is a unit of mass equal to 1,000 kilograms. It is a non-SI unit accepted for use with SI. It is also referred to as a metric ton in the United States to distinguish it from the non-metric units of the short ton (United States customary units) and the long ton (British imperial units). It is equivalent to approximately 2,204.6 pounds, 1.102 short tons, and 0.984 long tons.</summary>
        [[nodiscard]] constexpr un_scalar_t tonnes() const
        {
            return convert_from_base(MassUnit::Tonnes);
        }

        /// <summary>The tonne is a unit of mass equal to 1,000 kilograms. It is a non-SI unit accepted for use with SI. It is also referred to as a metric ton in the United States to distinguish it from the non-metric units of the short ton (United States customary units) and the long ton (British imperial units). It is equivalent to approximately 2,204.6 pounds, 1.102 short tons, and 0.984 long tons.</summary>
        [[nodiscard]] static constexpr Mass from_tonnes(const un_scalar_t value)
        {
            return Mass(value, MassUnit::Tonnes);
        }


        /// <summary>The tonne is a unit of mass equal to 1,000 kilograms. It is a non-SI unit accepted for use with SI. It is also referred to as a metric ton in the United States to distinguish it from the non-metric units of the short ton (United States customary units) and the long ton (British imperial units). It is equivalent to approximately 2,204.6 pounds, 1.102 short tons, and 0.984 long tons.</summary>
        [[nodiscard]] constexpr un_scalar_t kilotonnes() const
        {
            return convert_from_base(MassUnit::Kilotonnes);
        }

        /// <summary>The tonne is a unit of mass equal to 1,000 kilograms. It is a non-SI unit accepted for use with SI. It is also referred to as a metric ton in the United States to distinguish it from the non-metric units of the short ton (United States customary units) and the long ton (British imperial units). It is equivalent to approximately 2,204.6 pounds, 1.102 short tons, and 0.984 long tons.</summary>
        [[nodiscard]] static constexpr Mass from_kilotonnes(const un_scalar_t value)
        {
            return Mass(value, MassUnit::Kilotonnes);
        }


        /// <summary>The tonne is a unit of mass equal to 1,000 kilograms. It is a non-SI unit accepted for use with SI. It is also referred to as a metric ton in the United States to distinguish it from the non-metric units of the short ton (United States customary units) and the long ton (British imperial units). It is equivalent to approximately 2,204.6 pounds, 1.102 short tons, and 0.984 long tons.</summary>
        [[nodiscard]] constexpr un_scalar_t megatonnes() const
        {
            return convert_from_base(MassUnit::Megatonnes);
        }

        /// <summary>The tonne is a unit of mass equal to 1,000 kilograms. It is a non-SI unit accepted for use with SI. It is also referred to as a metric ton in the United States to distinguish it from the non-metric units of the short ton (United States customary units) and the long ton (British imperial units). It is equivalent to approximately 2,204.6 pounds, 1.102 short tons, and 0.984 long tons.</summary>
        [[nodiscard]] static constexpr Mass from_megatonnes(const un_scalar_t value)
        {
            return Mass(value, MassUnit::Megatonnes);
        }


        /// <summary>The short ton is a unit of mass equal to 2,000 pounds (907.18474 kg), that is most commonly used in the United States – known there simply as the ton.</summary>
        [[nodiscard]] constexpr un_scalar_t short_tons() const
        {
            return convert_from_base(MassUnit::ShortTons);
        }

        /// <summary>The short ton is a unit of mass equal to 2,000 pounds (907.18474 kg), that is most commonly used in the United States – known there simply as the ton.</summary>
        [[nodiscard]] static constexpr Mass from_short_tons(const un_scalar_t value)
        {
            return Mass(value, MassUnit::ShortTons);
        }


        /// <summary>Long ton (weight ton or Imperial ton) is a unit of mass equal to 2,240 pounds (1,016 kg) and is the name for the unit called the "ton" in the avoirdupois or Imperial system of measurements that was used in the United Kingdom and several other Commonwealth countries before metrication.</summary>
        [[nodiscard]] constexpr un_scalar_t long_tons() const
        {
            return convert_from_base(MassUnit::LongTons);
        }

        /// <summary>Long ton (weight ton or Imperial ton) is a unit of mass equal to 2,240 pounds (1,016 kg) and is the name for the unit called the "ton" in the avoirdupois or Imperial system of measurements that was used in the United Kingdom and several other Commonwealth countries before metrication.</summary>
        [[nodiscard]] static constexpr Mass from_long_tons(const un_scalar_t value)
        {
            return Mass(value, MassUnit::LongTons);
        }


        /// <summary>The pound or pound-mass (abbreviations: lb, lbm) is a unit of mass used in the imperial, United States customary and other systems of measurement. A number of different definitions have been used, the most common today being the international avoirdupois pound which is legally defined as exactly 0.45359237 kilograms, and which is divided into 16 avoirdupois ounces.</summary>
        [[nodiscard]] constexpr un_scalar_t pounds() const
        {
            return convert_from_base(MassUnit::Pounds);
        }

        /// <summary>The pound or pound-mass (abbreviations: lb, lbm) is a unit of mass used in the imperial, United States customary and other systems of measurement. A number of different definitions have been used, the most common today being the international avoirdupois pound which is legally defined as exactly 0.45359237 kilograms, and which is divided into 16 avoirdupois ounces.</summary>
        [[nodiscard]] static constexpr Mass from_pounds(const un_scalar_t value)
        {
            return Mass(value, MassUnit::Pounds);
        }


        /// <summary>The pound or pound-mass (abbreviations: lb, lbm) is a unit of mass used in the imperial, United States customary and other systems of measurement. A number of different definitions have been used, the most common today being the international avoirdupois pound which is legally defined as exactly 0.45359237 kilograms, and which is divided into 16 avoirdupois ounces.</summary>
        [[nodiscard]] constexpr un_scalar_t kilopounds() const
        {
            return convert_from_base(MassUnit::Kilopounds);
        }

        /// <summary>The pound or pound-mass (abbreviations: lb, lbm) is a unit of mass used in the imperial, United States customary and other systems of measurement. A number of different definitions have been used, the most common today being the international avoirdupois pound which is legally defined as exactly 0.45359237 kilograms, and which is divided into 16 avoirdupois ounces.</summary>
        [[nodiscard]] static constexpr Mass from_kilopounds(const un_scalar_t value)
        {
            return Mass(value, MassUnit::Kilopounds);
        }


        /// <summary>The pound or pound-mass (abbreviations: lb, lbm) is a unit of mass used in the imperial, United States customary and other systems of measurement. A number of different definitions have been used, the most common today being the international avoirdupois pound which is legally defined as exactly 0.45359237 kilograms, and which is divided into 16 avoirdupois ounces.</summary>
        [[nodiscard]] constexpr un_scalar_t megapounds() const
        {
            return convert_from_base(MassUnit::Megapounds);
        }

        /// <summary>The pound or pound-mass (abbreviations: lb, lbm) is a unit of mass used in the imperial, United States customary and other systems of measurement. A number of different definitions have been used, the most common today being the international avoirdupois pound which is legally defined as exactly 0.45359237 kilograms, and which is divided into 16 avoirdupois ounces.</summary>
        [[nodiscard]] static constexpr Mass from_megapounds(const un_scalar_t value)
        {
            return Mass(value, MassUnit::Megapounds);
        }


        /// <summary>The international avoirdupois ounce (abbreviated oz) is defined as exactly 28.349523125 g under the international yard and pound agreement of 1959, signed by the United States and countries of the Commonwealth of Nations. 16 oz make up an avoirdupois pound.</summary>
        [[nodiscard]] constexpr un_scalar_t ounces() const
        {
            return convert_from_base(MassUnit::Ounces);
        }

        /// <summary>The international avoirdupois ounce (abbreviated oz) is defined as exactly 28.349523125 g under the international yard and pound agreement of 1959, signed by the United States and countries of the Commonwealth of Nations. 16 oz make up an avoirdupois pound.</summary>
        [[nodiscard]] static constexpr Mass from_ounces(const un_scalar_t value)
        {
            return Mass(value, MassUnit::Ounces);
        }


        /// <summary>The slug (abbreviation slug) is a unit of mass that is accelerated by 1 ft/s² when a force of one pound (lbf) is exerted on it.</summary>
        [[nodiscard]] constexpr un_scalar_t slugs() const
        {
            return convert_from_base(MassUnit::Slugs);
        }

        /// <summary>The slug (abbreviation slug) is a unit of mass that is accelerated by 1 ft/s² when a force of one pound (lbf) is exerted on it.</summary>
        [[nodiscard]] static constexpr Mass from_slugs(const un_scalar_t value)
        {
            return Mass(value, MassUnit::Slugs);
        }


        /// <summary>The stone (abbreviation st) is a unit of mass equal to 14 pounds avoirdupois (about 6.35 kilograms) used in Great Britain and Ireland for measuring human body weight.</summary>
        [[nodiscard]] constexpr un_scalar_t stone() const
        {
            return convert_from_base(MassUnit::Stone);
        }

        /// <summary>The stone (abbreviation st) is a unit of mass equal to 14 pounds avoirdupois (about 6.35 kilograms) used in Great Britain and Ireland for measuring human body weight.</summary>
        [[nodiscard]] static constexpr Mass from_stone(const un_scalar_t value)
        {
            return Mass(value, MassUnit::Stone);
        }


        /// <summary>The short hundredweight (abbreviation cwt) is a unit of mass equal to 100 pounds in US and Canada. In British English, the short hundredweight is referred to as the "cental".</summary>
        [[nodiscard]] constexpr un_scalar_t short_hundredweight() const
        {
            return convert_from_base(MassUnit::ShortHundredweight);
        }

        /// <summary>The short hundredweight (abbreviation cwt) is a unit of mass equal to 100 pounds in US and Canada. In British English, the short hundredweight is referred to as the "cental".</summary>
        [[nodiscard]] static constexpr Mass from_short_hundredweight(const un_scalar_t value)
        {
            return Mass(value, MassUnit::ShortHundredweight);
        }


        /// <summary>The long or imperial hundredweight (abbreviation cwt) is a unit of mass equal to 112 pounds in US and Canada.</summary>
        [[nodiscard]] constexpr un_scalar_t long_hundredweight() const
        {
            return convert_from_base(MassUnit::LongHundredweight);
        }

        /// <summary>The long or imperial hundredweight (abbreviation cwt) is a unit of mass equal to 112 pounds in US and Canada.</summary>
        [[nodiscard]] static constexpr Mass from_long_hundredweight(const un_scalar_t value)
        {
            return Mass(value, MassUnit::LongHundredweight);
        }


        /// <summary>A grain is a unit of measurement of mass, and in the troy weight, avoirdupois, and Apothecaries' system, equal to exactly 64.79891 milligrams.</summary>
        [[nodiscard]] constexpr un_scalar_t grains() const
        {
            return convert_from_base(MassUnit::Grains);
        }

        /// <summary>A grain is a unit of measurement of mass, and in the troy weight, avoirdupois, and Apothecaries' system, equal to exactly 64.79891 milligrams.</summary>
        [[nodiscard]] static constexpr Mass from_grains(const un_scalar_t value)
        {
            return Mass(value, MassUnit::Grains);
        }


        /// <summary>Solar mass is a ratio unit to the mass of the solar system star, the sun.</summary>
        [[nodiscard]] constexpr un_scalar_t solar_masses() const
        {
            return convert_from_base(MassUnit::SolarMasses);
        }

        /// <summary>Solar mass is a ratio unit to the mass of the solar system star, the sun.</summary>
        [[nodiscard]] static constexpr Mass from_solar_masses(const un_scalar_t value)
        {
            return Mass(value, MassUnit::SolarMasses);
        }


        /// <summary>Earth mass is a ratio unit to the mass of planet Earth.</summary>
        [[nodiscard]] constexpr un_scalar_t earth_masses() const
        {
            return convert_from_base(MassUnit::EarthMasses);
        }

        /// <summary>Earth mass is a ratio unit to the mass of planet Earth.</summary>
        [[nodiscard]] static constexpr Mass from_earth_masses(const un_scalar_t value)
        {
            return Mass(value, MassUnit::EarthMasses);
        }


        /// <summary>The Dalton or unified atomic mass unit (abbreviation Da or u) is a unit of mass defined as 1/12 of the mass of an unbound neutral atom of carbon-12 in its nuclear and electronic ground state and at rest.</summary>
        [[nodiscard]] constexpr un_scalar_t daltons() const
        {
            return convert_from_base(MassUnit::Daltons);
        }

        /// <summary>The Dalton or unified atomic mass unit (abbreviation Da or u) is a unit of mass defined as 1/12 of the mass of an unbound neutral atom of carbon-12 in its nuclear and electronic ground state and at rest.</summary>
        [[nodiscard]] static constexpr Mass from_daltons(const un_scalar_t value)
        {
            return Mass(value, MassUnit::Daltons);
        }


        /// <summary>The Dalton or unified atomic mass unit (abbreviation Da or u) is a unit of mass defined as 1/12 of the mass of an unbound neutral atom of carbon-12 in its nuclear and electronic ground state and at rest.</summary>
        [[nodiscard]] constexpr un_scalar_t kilodaltons() const
        {
            return convert_from_base(MassUnit::Kilodaltons);
        }

        /// <summary>The Dalton or unified atomic mass unit (abbreviation Da or u) is a unit of mass defined as 1/12 of the mass of an unbound neutral atom of carbon-12 in its nuclear and electronic ground state and at rest.</summary>
        [[nodiscard]] static constexpr Mass from_kilodaltons(const un_scalar_t value)
        {
            return Mass(value, MassUnit::Kilodaltons);
        }


        /// <summary>The Dalton or unified atomic mass unit (abbreviation Da or u) is a unit of mass defined as 1/12 of the mass of an unbound neutral atom of carbon-12 in its nuclear and electronic ground state and at rest.</summary>
        [[nodiscard]] constexpr un_scalar_t megadaltons() const
        {
            return convert_from_base(MassUnit::Megadaltons);
        }

        /// <summary>The Dalton or unified atomic mass unit (abbreviation Da or u) is a unit of mass defined as 1/12 of the mass of an unbound neutral atom of carbon-12 in its nuclear and electronic ground state and at rest.</summary>
        [[nodiscard]] static constexpr Mass from_megadaltons(const un_scalar_t value)
        {
            return Mass(value, MassUnit::Megadaltons);
        }


        /// <summary>The Dalton or unified atomic mass unit (abbreviation Da or u) is a unit of mass defined as 1/12 of the mass of an unbound neutral atom of carbon-12 in its nuclear and electronic ground state and at rest.</summary>
        [[nodiscard]] constexpr un_scalar_t gigadaltons() const
        {
            return convert_from_base(MassUnit::Gigadaltons);
        }

        /// <summary>The Dalton or unified atomic mass unit (abbreviation Da or u) is a unit of mass defined as 1/12 of the mass of an unbound neutral atom of carbon-12 in its nuclear and electronic ground state and at rest.</summary>
        [[nodiscard]] static constexpr Mass from_gigadaltons(const un_scalar_t value)
        {
            return Mass(value, MassUnit::Gigadaltons);
        }


        [[nodiscard]] static constexpr Mass from_invalid()
        {
            return Mass(false);
        }
    private:
        bool _isInvalid = false;
    
        [[nodiscard]] static constexpr un_scalar_t convert_to_base(un_scalar_t value, MassUnit unit)
        {
            switch (unit)
            {

            case MassUnit::Grams:
                return value / static_cast<un_scalar_t>(1e3);

            case MassUnit::Femtograms:
                return (value * static_cast<un_scalar_t>(1e-15)) / static_cast<un_scalar_t>(1e3);

            case MassUnit::Picograms:
                return (value * static_cast<un_scalar_t>(1e-12)) / static_cast<un_scalar_t>(1e3);

            case MassUnit::Nanograms:
                return (value * static_cast<un_scalar_t>(1e-9)) / static_cast<un_scalar_t>(1e3);

            case MassUnit::Micrograms:
                return (value * static_cast<un_scalar_t>(1e-6)) / static_cast<un_scalar_t>(1e3);

            case MassUnit::Milligrams:
                return (value * static_cast<un_scalar_t>(1e-3)) / static_cast<un_scalar_t>(1e3);

            case MassUnit::Centigrams:
                return (value * static_cast<un_scalar_t>(1e-2)) / static_cast<un_scalar_t>(1e3);

            case MassUnit::Decigrams:
                return (value * static_cast<un_scalar_t>(1e-1)) / static_cast<un_scalar_t>(1e3);

            case MassUnit::Decagrams:
                return (value * static_cast<un_scalar_t>(1e1)) / static_cast<un_scalar_t>(1e3);

            case MassUnit::Hectograms:
                return (value * static_cast<un_scalar_t>(1e2)) / static_cast<un_scalar_t>(1e3);

            case MassUnit::Kilograms:
                return (value * static_cast<un_scalar_t>(1e3)) / static_cast<un_scalar_t>(1e3);

            case MassUnit::Tonnes:
                return value * static_cast<un_scalar_t>(1e3);

            case MassUnit::Kilotonnes:
                return (value * static_cast<un_scalar_t>(1e3)) * static_cast<un_scalar_t>(1e3);

            case MassUnit::Megatonnes:
                return (value * static_cast<un_scalar_t>(1e6)) * static_cast<un_scalar_t>(1e3);

            case MassUnit::ShortTons:
                return value * static_cast<un_scalar_t>(907.18474);

            case MassUnit::LongTons:
                return value * static_cast<un_scalar_t>(1016.0469088);

            case MassUnit::Pounds:
                return value * static_cast<un_scalar_t>(0.45359237);

            case MassUnit::Kilopounds:
                return (value * static_cast<un_scalar_t>(1e3)) * static_cast<un_scalar_t>(0.45359237);

            case MassUnit::Megapounds:
                return (value * static_cast<un_scalar_t>(1e6)) * static_cast<un_scalar_t>(0.45359237);

            case MassUnit::Ounces:
                return value * static_cast<un_scalar_t>(0.028349523125);

            case MassUnit::Slugs:
                return value * static_cast<un_scalar_t>(0.45359237) * static_cast<un_scalar_t>(9.80665) / static_cast<un_scalar_t>(0.3048);

            case MassUnit::Stone:
                return value * static_cast<un_scalar_t>(6.35029318);

            case MassUnit::ShortHundredweight:
                return value * static_cast<un_scalar_t>(45.359237);

            case MassUnit::LongHundredweight:
                return value * static_cast<un_scalar_t>(50.80234544);

            case MassUnit::Grains:
                return value * static_cast<un_scalar_t>(64.79891e-6);

            case MassUnit::SolarMasses:
                return value * static_cast<un_scalar_t>(1.98947e30);

            case MassUnit::EarthMasses:
                return value * static_cast<un_scalar_t>(5.9722E+24);

            case MassUnit::Daltons:
                return value *  static_cast<un_scalar_t>(1.66053906660e-27);

            case MassUnit::Kilodaltons:
                return (value * static_cast<un_scalar_t>(1e3)) *  static_cast<un_scalar_t>(1.66053906660e-27);

            case MassUnit::Megadaltons:
                return (value * static_cast<un_scalar_t>(1e6)) *  static_cast<un_scalar_t>(1.66053906660e-27);

            case MassUnit::Gigadaltons:
                return (value * static_cast<un_scalar_t>(1e9)) *  static_cast<un_scalar_t>(1.66053906660e-27);

            }

            throw std::invalid_argument("Unknown Mass unit.");
        }

        [[nodiscard]] constexpr un_scalar_t convert_from_base(const MassUnit unit) const
        {
            switch (unit)
            {

            case MassUnit::Grams:
                return value_ * static_cast<un_scalar_t>(1e3);

            case MassUnit::Femtograms:
                return (value_ * static_cast<un_scalar_t>(1e3)) / static_cast<un_scalar_t>(1e-15);

            case MassUnit::Picograms:
                return (value_ * static_cast<un_scalar_t>(1e3)) / static_cast<un_scalar_t>(1e-12);

            case MassUnit::Nanograms:
                return (value_ * static_cast<un_scalar_t>(1e3)) / static_cast<un_scalar_t>(1e-9);

            case MassUnit::Micrograms:
                return (value_ * static_cast<un_scalar_t>(1e3)) / static_cast<un_scalar_t>(1e-6);

            case MassUnit::Milligrams:
                return (value_ * static_cast<un_scalar_t>(1e3)) / static_cast<un_scalar_t>(1e-3);

            case MassUnit::Centigrams:
                return (value_ * static_cast<un_scalar_t>(1e3)) / static_cast<un_scalar_t>(1e-2);

            case MassUnit::Decigrams:
                return (value_ * static_cast<un_scalar_t>(1e3)) / static_cast<un_scalar_t>(1e-1);

            case MassUnit::Decagrams:
                return (value_ * static_cast<un_scalar_t>(1e3)) / static_cast<un_scalar_t>(1e1);

            case MassUnit::Hectograms:
                return (value_ * static_cast<un_scalar_t>(1e3)) / static_cast<un_scalar_t>(1e2);

            case MassUnit::Kilograms:
                return (value_ * static_cast<un_scalar_t>(1e3)) / static_cast<un_scalar_t>(1e3);

            case MassUnit::Tonnes:
                return value_ / static_cast<un_scalar_t>(1e3);

            case MassUnit::Kilotonnes:
                return (value_ / static_cast<un_scalar_t>(1e3)) / static_cast<un_scalar_t>(1e3);

            case MassUnit::Megatonnes:
                return (value_ / static_cast<un_scalar_t>(1e3)) / static_cast<un_scalar_t>(1e6);

            case MassUnit::ShortTons:
                return value_ / static_cast<un_scalar_t>(907.18474);

            case MassUnit::LongTons:
                return value_ / static_cast<un_scalar_t>(1016.0469088);

            case MassUnit::Pounds:
                return value_ / static_cast<un_scalar_t>(0.45359237);

            case MassUnit::Kilopounds:
                return (value_ / static_cast<un_scalar_t>(0.45359237)) / static_cast<un_scalar_t>(1e3);

            case MassUnit::Megapounds:
                return (value_ / static_cast<un_scalar_t>(0.45359237)) / static_cast<un_scalar_t>(1e6);

            case MassUnit::Ounces:
                return value_ / static_cast<un_scalar_t>(0.028349523125);

            case MassUnit::Slugs:
                return value_ * static_cast<un_scalar_t>(0.3048) / (static_cast<un_scalar_t>(0.45359237) * static_cast<un_scalar_t>(9.80665));

            case MassUnit::Stone:
                return value_ / static_cast<un_scalar_t>(6.35029318);

            case MassUnit::ShortHundredweight:
                return value_ / static_cast<un_scalar_t>(45.359237);

            case MassUnit::LongHundredweight:
                return value_ / static_cast<un_scalar_t>(50.80234544);

            case MassUnit::Grains:
                return value_ / static_cast<un_scalar_t>(64.79891e-6);

            case MassUnit::SolarMasses:
                return value_ / static_cast<un_scalar_t>(1.98947e30);

            case MassUnit::EarthMasses:
                return value_ / static_cast<un_scalar_t>(5.9722E+24);

            case MassUnit::Daltons:
                return value_ /  static_cast<un_scalar_t>(1.66053906660e-27);

            case MassUnit::Kilodaltons:
                return (value_ /  static_cast<un_scalar_t>(1.66053906660e-27)) / static_cast<un_scalar_t>(1e3);

            case MassUnit::Megadaltons:
                return (value_ /  static_cast<un_scalar_t>(1.66053906660e-27)) / static_cast<un_scalar_t>(1e6);

            case MassUnit::Gigadaltons:
                return (value_ /  static_cast<un_scalar_t>(1.66053906660e-27)) / static_cast<un_scalar_t>(1e9);

            }

            throw std::invalid_argument("Unknown Mass unit.");
        }

        un_scalar_t value_;
    };
}
