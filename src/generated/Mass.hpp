#pragma once

#include <cstdint>
#include <numbers>
#include <stdexcept>

namespace unitsnet_cpp
{
    enum class MassUnit : std::uint16_t
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
            double value,
            MassUnit unit = MassUnit::Kilograms)
            : value_(convert_to_base(value, unit))
        {
        }

        [[nodiscard]] constexpr double base_value() const noexcept
        {
            return value_;
        }

        [[nodiscard]] constexpr double value(MassUnit unit) const
        {
            return convert_from_base(unit);
        }

        [[nodiscard]] constexpr Mass operator+(Mass other) const noexcept
        {
            return Mass(value_ + other.value_);
        }

        [[nodiscard]] constexpr Mass operator-(Mass other) const noexcept
        {
            return Mass(value_ - other.value_);
        }

        [[nodiscard]] constexpr Mass operator*(double scalar) const noexcept
        {
            return Mass(value_ * scalar);
        }

        [[nodiscard]] constexpr Mass operator/(double scalar) const noexcept
        {
            return Mass(value_ / scalar);
        }

        [[nodiscard]] constexpr bool operator==(Mass other) const noexcept
        {
            return value_ == other.value_;
        }

        [[nodiscard]] constexpr bool operator<(Mass other) const noexcept
        {
            return value_ < other.value_;
        }


        [[nodiscard]] constexpr double grams() const
        {
            return convert_from_base(MassUnit::Grams);
        }

        [[nodiscard]] static constexpr Mass from_grams(double value)
        {
            return Mass(value, MassUnit::Grams);
        }


        [[nodiscard]] constexpr double femtograms() const
        {
            return convert_from_base(MassUnit::Femtograms);
        }

        [[nodiscard]] static constexpr Mass from_femtograms(double value)
        {
            return Mass(value, MassUnit::Femtograms);
        }


        [[nodiscard]] constexpr double picograms() const
        {
            return convert_from_base(MassUnit::Picograms);
        }

        [[nodiscard]] static constexpr Mass from_picograms(double value)
        {
            return Mass(value, MassUnit::Picograms);
        }


        [[nodiscard]] constexpr double nanograms() const
        {
            return convert_from_base(MassUnit::Nanograms);
        }

        [[nodiscard]] static constexpr Mass from_nanograms(double value)
        {
            return Mass(value, MassUnit::Nanograms);
        }


        [[nodiscard]] constexpr double micrograms() const
        {
            return convert_from_base(MassUnit::Micrograms);
        }

        [[nodiscard]] static constexpr Mass from_micrograms(double value)
        {
            return Mass(value, MassUnit::Micrograms);
        }


        [[nodiscard]] constexpr double milligrams() const
        {
            return convert_from_base(MassUnit::Milligrams);
        }

        [[nodiscard]] static constexpr Mass from_milligrams(double value)
        {
            return Mass(value, MassUnit::Milligrams);
        }


        [[nodiscard]] constexpr double centigrams() const
        {
            return convert_from_base(MassUnit::Centigrams);
        }

        [[nodiscard]] static constexpr Mass from_centigrams(double value)
        {
            return Mass(value, MassUnit::Centigrams);
        }


        [[nodiscard]] constexpr double decigrams() const
        {
            return convert_from_base(MassUnit::Decigrams);
        }

        [[nodiscard]] static constexpr Mass from_decigrams(double value)
        {
            return Mass(value, MassUnit::Decigrams);
        }


        [[nodiscard]] constexpr double decagrams() const
        {
            return convert_from_base(MassUnit::Decagrams);
        }

        [[nodiscard]] static constexpr Mass from_decagrams(double value)
        {
            return Mass(value, MassUnit::Decagrams);
        }


        [[nodiscard]] constexpr double hectograms() const
        {
            return convert_from_base(MassUnit::Hectograms);
        }

        [[nodiscard]] static constexpr Mass from_hectograms(double value)
        {
            return Mass(value, MassUnit::Hectograms);
        }


        [[nodiscard]] constexpr double kilograms() const
        {
            return convert_from_base(MassUnit::Kilograms);
        }

        [[nodiscard]] static constexpr Mass from_kilograms(double value)
        {
            return Mass(value, MassUnit::Kilograms);
        }


        [[nodiscard]] constexpr double tonnes() const
        {
            return convert_from_base(MassUnit::Tonnes);
        }

        [[nodiscard]] static constexpr Mass from_tonnes(double value)
        {
            return Mass(value, MassUnit::Tonnes);
        }


        [[nodiscard]] constexpr double kilotonnes() const
        {
            return convert_from_base(MassUnit::Kilotonnes);
        }

        [[nodiscard]] static constexpr Mass from_kilotonnes(double value)
        {
            return Mass(value, MassUnit::Kilotonnes);
        }


        [[nodiscard]] constexpr double megatonnes() const
        {
            return convert_from_base(MassUnit::Megatonnes);
        }

        [[nodiscard]] static constexpr Mass from_megatonnes(double value)
        {
            return Mass(value, MassUnit::Megatonnes);
        }


        [[nodiscard]] constexpr double short_tons() const
        {
            return convert_from_base(MassUnit::ShortTons);
        }

        [[nodiscard]] static constexpr Mass from_short_tons(double value)
        {
            return Mass(value, MassUnit::ShortTons);
        }


        [[nodiscard]] constexpr double long_tons() const
        {
            return convert_from_base(MassUnit::LongTons);
        }

        [[nodiscard]] static constexpr Mass from_long_tons(double value)
        {
            return Mass(value, MassUnit::LongTons);
        }


        [[nodiscard]] constexpr double pounds() const
        {
            return convert_from_base(MassUnit::Pounds);
        }

        [[nodiscard]] static constexpr Mass from_pounds(double value)
        {
            return Mass(value, MassUnit::Pounds);
        }


        [[nodiscard]] constexpr double kilopounds() const
        {
            return convert_from_base(MassUnit::Kilopounds);
        }

        [[nodiscard]] static constexpr Mass from_kilopounds(double value)
        {
            return Mass(value, MassUnit::Kilopounds);
        }


        [[nodiscard]] constexpr double megapounds() const
        {
            return convert_from_base(MassUnit::Megapounds);
        }

        [[nodiscard]] static constexpr Mass from_megapounds(double value)
        {
            return Mass(value, MassUnit::Megapounds);
        }


        [[nodiscard]] constexpr double ounces() const
        {
            return convert_from_base(MassUnit::Ounces);
        }

        [[nodiscard]] static constexpr Mass from_ounces(double value)
        {
            return Mass(value, MassUnit::Ounces);
        }


        [[nodiscard]] constexpr double slugs() const
        {
            return convert_from_base(MassUnit::Slugs);
        }

        [[nodiscard]] static constexpr Mass from_slugs(double value)
        {
            return Mass(value, MassUnit::Slugs);
        }


        [[nodiscard]] constexpr double stone() const
        {
            return convert_from_base(MassUnit::Stone);
        }

        [[nodiscard]] static constexpr Mass from_stone(double value)
        {
            return Mass(value, MassUnit::Stone);
        }


        [[nodiscard]] constexpr double short_hundredweight() const
        {
            return convert_from_base(MassUnit::ShortHundredweight);
        }

        [[nodiscard]] static constexpr Mass from_short_hundredweight(double value)
        {
            return Mass(value, MassUnit::ShortHundredweight);
        }


        [[nodiscard]] constexpr double long_hundredweight() const
        {
            return convert_from_base(MassUnit::LongHundredweight);
        }

        [[nodiscard]] static constexpr Mass from_long_hundredweight(double value)
        {
            return Mass(value, MassUnit::LongHundredweight);
        }


        [[nodiscard]] constexpr double grains() const
        {
            return convert_from_base(MassUnit::Grains);
        }

        [[nodiscard]] static constexpr Mass from_grains(double value)
        {
            return Mass(value, MassUnit::Grains);
        }


        [[nodiscard]] constexpr double solar_masses() const
        {
            return convert_from_base(MassUnit::SolarMasses);
        }

        [[nodiscard]] static constexpr Mass from_solar_masses(double value)
        {
            return Mass(value, MassUnit::SolarMasses);
        }


        [[nodiscard]] constexpr double earth_masses() const
        {
            return convert_from_base(MassUnit::EarthMasses);
        }

        [[nodiscard]] static constexpr Mass from_earth_masses(double value)
        {
            return Mass(value, MassUnit::EarthMasses);
        }


        [[nodiscard]] constexpr double daltons() const
        {
            return convert_from_base(MassUnit::Daltons);
        }

        [[nodiscard]] static constexpr Mass from_daltons(double value)
        {
            return Mass(value, MassUnit::Daltons);
        }


        [[nodiscard]] constexpr double kilodaltons() const
        {
            return convert_from_base(MassUnit::Kilodaltons);
        }

        [[nodiscard]] static constexpr Mass from_kilodaltons(double value)
        {
            return Mass(value, MassUnit::Kilodaltons);
        }


        [[nodiscard]] constexpr double megadaltons() const
        {
            return convert_from_base(MassUnit::Megadaltons);
        }

        [[nodiscard]] static constexpr Mass from_megadaltons(double value)
        {
            return Mass(value, MassUnit::Megadaltons);
        }


        [[nodiscard]] constexpr double gigadaltons() const
        {
            return convert_from_base(MassUnit::Gigadaltons);
        }

        [[nodiscard]] static constexpr Mass from_gigadaltons(double value)
        {
            return Mass(value, MassUnit::Gigadaltons);
        }


    private:
        [[nodiscard]] static constexpr double convert_to_base(double value, MassUnit unit)
        {
            switch (unit)
            {

            case MassUnit::Grams:
                return value / 1e3;

            case MassUnit::Femtograms:
                return (value * 1e-15) / 1e3;

            case MassUnit::Picograms:
                return (value * 1e-12) / 1e3;

            case MassUnit::Nanograms:
                return (value * 1e-9) / 1e3;

            case MassUnit::Micrograms:
                return (value * 1e-6) / 1e3;

            case MassUnit::Milligrams:
                return (value * 1e-3) / 1e3;

            case MassUnit::Centigrams:
                return (value * 1e-2) / 1e3;

            case MassUnit::Decigrams:
                return (value * 1e-1) / 1e3;

            case MassUnit::Decagrams:
                return (value * 1e1) / 1e3;

            case MassUnit::Hectograms:
                return (value * 1e2) / 1e3;

            case MassUnit::Kilograms:
                return (value * 1e3) / 1e3;

            case MassUnit::Tonnes:
                return value * 1e3;

            case MassUnit::Kilotonnes:
                return (value * 1e3) * 1e3;

            case MassUnit::Megatonnes:
                return (value * 1e6) * 1e3;

            case MassUnit::ShortTons:
                return value * 907.18474;

            case MassUnit::LongTons:
                return value * 1016.0469088;

            case MassUnit::Pounds:
                return value * 0.45359237;

            case MassUnit::Kilopounds:
                return (value * 1e3) * 0.45359237;

            case MassUnit::Megapounds:
                return (value * 1e6) * 0.45359237;

            case MassUnit::Ounces:
                return value * 0.028349523125;

            case MassUnit::Slugs:
                return value * 0.45359237 * 9.80665 / 0.3048;

            case MassUnit::Stone:
                return value * 6.35029318;

            case MassUnit::ShortHundredweight:
                return value * 45.359237;

            case MassUnit::LongHundredweight:
                return value * 50.80234544;

            case MassUnit::Grains:
                return value * 64.79891e-6;

            case MassUnit::SolarMasses:
                return value * 1.98947e30;

            case MassUnit::EarthMasses:
                return value * 5.9722E+24;

            case MassUnit::Daltons:
                return value *  1.66053906660e-27;

            case MassUnit::Kilodaltons:
                return (value * 1e3) *  1.66053906660e-27;

            case MassUnit::Megadaltons:
                return (value * 1e6) *  1.66053906660e-27;

            case MassUnit::Gigadaltons:
                return (value * 1e9) *  1.66053906660e-27;

            }

            throw std::invalid_argument("Unknown Mass unit.");
        }

        [[nodiscard]] constexpr double convert_from_base(MassUnit unit) const
        {
            switch (unit)
            {

            case MassUnit::Grams:
                return value_ * 1e3;

            case MassUnit::Femtograms:
                return (value_ * 1e3) / 1e-15;

            case MassUnit::Picograms:
                return (value_ * 1e3) / 1e-12;

            case MassUnit::Nanograms:
                return (value_ * 1e3) / 1e-9;

            case MassUnit::Micrograms:
                return (value_ * 1e3) / 1e-6;

            case MassUnit::Milligrams:
                return (value_ * 1e3) / 1e-3;

            case MassUnit::Centigrams:
                return (value_ * 1e3) / 1e-2;

            case MassUnit::Decigrams:
                return (value_ * 1e3) / 1e-1;

            case MassUnit::Decagrams:
                return (value_ * 1e3) / 1e1;

            case MassUnit::Hectograms:
                return (value_ * 1e3) / 1e2;

            case MassUnit::Kilograms:
                return (value_ * 1e3) / 1e3;

            case MassUnit::Tonnes:
                return value_ / 1e3;

            case MassUnit::Kilotonnes:
                return (value_ / 1e3) / 1e3;

            case MassUnit::Megatonnes:
                return (value_ / 1e3) / 1e6;

            case MassUnit::ShortTons:
                return value_ / 907.18474;

            case MassUnit::LongTons:
                return value_ / 1016.0469088;

            case MassUnit::Pounds:
                return value_ / 0.45359237;

            case MassUnit::Kilopounds:
                return (value_ / 0.45359237) / 1e3;

            case MassUnit::Megapounds:
                return (value_ / 0.45359237) / 1e6;

            case MassUnit::Ounces:
                return value_ / 0.028349523125;

            case MassUnit::Slugs:
                return value_ * 0.3048 / (0.45359237 * 9.80665);

            case MassUnit::Stone:
                return value_ / 6.35029318;

            case MassUnit::ShortHundredweight:
                return value_ / 45.359237;

            case MassUnit::LongHundredweight:
                return value_ / 50.80234544;

            case MassUnit::Grains:
                return value_ / 64.79891e-6;

            case MassUnit::SolarMasses:
                return value_ / 1.98947e30;

            case MassUnit::EarthMasses:
                return value_ / 5.9722E+24;

            case MassUnit::Daltons:
                return value_ /  1.66053906660e-27;

            case MassUnit::Kilodaltons:
                return (value_ /  1.66053906660e-27) / 1e3;

            case MassUnit::Megadaltons:
                return (value_ /  1.66053906660e-27) / 1e6;

            case MassUnit::Gigadaltons:
                return (value_ /  1.66053906660e-27) / 1e9;

            }

            throw std::invalid_argument("Unknown Mass unit.");
        }

        double value_;
    };
}
