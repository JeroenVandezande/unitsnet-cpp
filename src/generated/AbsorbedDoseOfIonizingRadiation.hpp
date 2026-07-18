#pragma once

#include <cstdint>
#include <numbers>
#include <stdexcept>

namespace unitsnet_cpp
{
    enum class AbsorbedDoseOfIonizingRadiationUnit : std::uint16_t
    {
        Grays,
        Femtograys,
        Picograys,
        Nanograys,
        Micrograys,
        Milligrays,
        Centigrays,
        Decigrays,
        Kilograys,
        Megagrays,
        Gigagrays,
        Teragrays,
        Petagrays,
        Rads,
        Millirads,
        Kilorads,
        Megarads,
    };

    /// <summary>Absorbed dose is a dose quantity which is the measure of the energy deposited in matter by ionizing radiation per unit mass.</summary>
    class AbsorbedDoseOfIonizingRadiation
    {
    public:
        constexpr explicit AbsorbedDoseOfIonizingRadiation(
            double value,
            AbsorbedDoseOfIonizingRadiationUnit unit = AbsorbedDoseOfIonizingRadiationUnit::Grays)
            : value_(convert_to_base(value, unit))
        {
        }

        [[nodiscard]] constexpr double base_value() const noexcept
        {
            return value_;
        }

        [[nodiscard]] constexpr double value(AbsorbedDoseOfIonizingRadiationUnit unit) const
        {
            return convert_from_base(unit);
        }

        [[nodiscard]] constexpr AbsorbedDoseOfIonizingRadiation operator+(AbsorbedDoseOfIonizingRadiation other) const noexcept
        {
            return AbsorbedDoseOfIonizingRadiation(value_ + other.value_);
        }

        [[nodiscard]] constexpr AbsorbedDoseOfIonizingRadiation operator-(AbsorbedDoseOfIonizingRadiation other) const noexcept
        {
            return AbsorbedDoseOfIonizingRadiation(value_ - other.value_);
        }

        [[nodiscard]] constexpr AbsorbedDoseOfIonizingRadiation operator*(double scalar) const noexcept
        {
            return AbsorbedDoseOfIonizingRadiation(value_ * scalar);
        }

        [[nodiscard]] constexpr AbsorbedDoseOfIonizingRadiation operator/(double scalar) const noexcept
        {
            return AbsorbedDoseOfIonizingRadiation(value_ / scalar);
        }

        [[nodiscard]] constexpr bool operator==(AbsorbedDoseOfIonizingRadiation other) const noexcept
        {
            return value_ == other.value_;
        }

        [[nodiscard]] constexpr bool operator<(AbsorbedDoseOfIonizingRadiation other) const noexcept
        {
            return value_ < other.value_;
        }


        [[nodiscard]] constexpr double grays() const
        {
            return convert_from_base(AbsorbedDoseOfIonizingRadiationUnit::Grays);
        }

        [[nodiscard]] static constexpr AbsorbedDoseOfIonizingRadiation from_grays(double value)
        {
            return AbsorbedDoseOfIonizingRadiation(value, AbsorbedDoseOfIonizingRadiationUnit::Grays);
        }


        [[nodiscard]] constexpr double femtograys() const
        {
            return convert_from_base(AbsorbedDoseOfIonizingRadiationUnit::Femtograys);
        }

        [[nodiscard]] static constexpr AbsorbedDoseOfIonizingRadiation from_femtograys(double value)
        {
            return AbsorbedDoseOfIonizingRadiation(value, AbsorbedDoseOfIonizingRadiationUnit::Femtograys);
        }


        [[nodiscard]] constexpr double picograys() const
        {
            return convert_from_base(AbsorbedDoseOfIonizingRadiationUnit::Picograys);
        }

        [[nodiscard]] static constexpr AbsorbedDoseOfIonizingRadiation from_picograys(double value)
        {
            return AbsorbedDoseOfIonizingRadiation(value, AbsorbedDoseOfIonizingRadiationUnit::Picograys);
        }


        [[nodiscard]] constexpr double nanograys() const
        {
            return convert_from_base(AbsorbedDoseOfIonizingRadiationUnit::Nanograys);
        }

        [[nodiscard]] static constexpr AbsorbedDoseOfIonizingRadiation from_nanograys(double value)
        {
            return AbsorbedDoseOfIonizingRadiation(value, AbsorbedDoseOfIonizingRadiationUnit::Nanograys);
        }


        [[nodiscard]] constexpr double micrograys() const
        {
            return convert_from_base(AbsorbedDoseOfIonizingRadiationUnit::Micrograys);
        }

        [[nodiscard]] static constexpr AbsorbedDoseOfIonizingRadiation from_micrograys(double value)
        {
            return AbsorbedDoseOfIonizingRadiation(value, AbsorbedDoseOfIonizingRadiationUnit::Micrograys);
        }


        [[nodiscard]] constexpr double milligrays() const
        {
            return convert_from_base(AbsorbedDoseOfIonizingRadiationUnit::Milligrays);
        }

        [[nodiscard]] static constexpr AbsorbedDoseOfIonizingRadiation from_milligrays(double value)
        {
            return AbsorbedDoseOfIonizingRadiation(value, AbsorbedDoseOfIonizingRadiationUnit::Milligrays);
        }


        [[nodiscard]] constexpr double centigrays() const
        {
            return convert_from_base(AbsorbedDoseOfIonizingRadiationUnit::Centigrays);
        }

        [[nodiscard]] static constexpr AbsorbedDoseOfIonizingRadiation from_centigrays(double value)
        {
            return AbsorbedDoseOfIonizingRadiation(value, AbsorbedDoseOfIonizingRadiationUnit::Centigrays);
        }


        [[nodiscard]] constexpr double decigrays() const
        {
            return convert_from_base(AbsorbedDoseOfIonizingRadiationUnit::Decigrays);
        }

        [[nodiscard]] static constexpr AbsorbedDoseOfIonizingRadiation from_decigrays(double value)
        {
            return AbsorbedDoseOfIonizingRadiation(value, AbsorbedDoseOfIonizingRadiationUnit::Decigrays);
        }


        [[nodiscard]] constexpr double kilograys() const
        {
            return convert_from_base(AbsorbedDoseOfIonizingRadiationUnit::Kilograys);
        }

        [[nodiscard]] static constexpr AbsorbedDoseOfIonizingRadiation from_kilograys(double value)
        {
            return AbsorbedDoseOfIonizingRadiation(value, AbsorbedDoseOfIonizingRadiationUnit::Kilograys);
        }


        [[nodiscard]] constexpr double megagrays() const
        {
            return convert_from_base(AbsorbedDoseOfIonizingRadiationUnit::Megagrays);
        }

        [[nodiscard]] static constexpr AbsorbedDoseOfIonizingRadiation from_megagrays(double value)
        {
            return AbsorbedDoseOfIonizingRadiation(value, AbsorbedDoseOfIonizingRadiationUnit::Megagrays);
        }


        [[nodiscard]] constexpr double gigagrays() const
        {
            return convert_from_base(AbsorbedDoseOfIonizingRadiationUnit::Gigagrays);
        }

        [[nodiscard]] static constexpr AbsorbedDoseOfIonizingRadiation from_gigagrays(double value)
        {
            return AbsorbedDoseOfIonizingRadiation(value, AbsorbedDoseOfIonizingRadiationUnit::Gigagrays);
        }


        [[nodiscard]] constexpr double teragrays() const
        {
            return convert_from_base(AbsorbedDoseOfIonizingRadiationUnit::Teragrays);
        }

        [[nodiscard]] static constexpr AbsorbedDoseOfIonizingRadiation from_teragrays(double value)
        {
            return AbsorbedDoseOfIonizingRadiation(value, AbsorbedDoseOfIonizingRadiationUnit::Teragrays);
        }


        [[nodiscard]] constexpr double petagrays() const
        {
            return convert_from_base(AbsorbedDoseOfIonizingRadiationUnit::Petagrays);
        }

        [[nodiscard]] static constexpr AbsorbedDoseOfIonizingRadiation from_petagrays(double value)
        {
            return AbsorbedDoseOfIonizingRadiation(value, AbsorbedDoseOfIonizingRadiationUnit::Petagrays);
        }


        [[nodiscard]] constexpr double rads() const
        {
            return convert_from_base(AbsorbedDoseOfIonizingRadiationUnit::Rads);
        }

        [[nodiscard]] static constexpr AbsorbedDoseOfIonizingRadiation from_rads(double value)
        {
            return AbsorbedDoseOfIonizingRadiation(value, AbsorbedDoseOfIonizingRadiationUnit::Rads);
        }


        [[nodiscard]] constexpr double millirads() const
        {
            return convert_from_base(AbsorbedDoseOfIonizingRadiationUnit::Millirads);
        }

        [[nodiscard]] static constexpr AbsorbedDoseOfIonizingRadiation from_millirads(double value)
        {
            return AbsorbedDoseOfIonizingRadiation(value, AbsorbedDoseOfIonizingRadiationUnit::Millirads);
        }


        [[nodiscard]] constexpr double kilorads() const
        {
            return convert_from_base(AbsorbedDoseOfIonizingRadiationUnit::Kilorads);
        }

        [[nodiscard]] static constexpr AbsorbedDoseOfIonizingRadiation from_kilorads(double value)
        {
            return AbsorbedDoseOfIonizingRadiation(value, AbsorbedDoseOfIonizingRadiationUnit::Kilorads);
        }


        [[nodiscard]] constexpr double megarads() const
        {
            return convert_from_base(AbsorbedDoseOfIonizingRadiationUnit::Megarads);
        }

        [[nodiscard]] static constexpr AbsorbedDoseOfIonizingRadiation from_megarads(double value)
        {
            return AbsorbedDoseOfIonizingRadiation(value, AbsorbedDoseOfIonizingRadiationUnit::Megarads);
        }


    private:
        [[nodiscard]] static constexpr double convert_to_base(double value, AbsorbedDoseOfIonizingRadiationUnit unit)
        {
            switch (unit)
            {

            case AbsorbedDoseOfIonizingRadiationUnit::Grays:
                return value;

            case AbsorbedDoseOfIonizingRadiationUnit::Femtograys:
                return (value * 1e-15);

            case AbsorbedDoseOfIonizingRadiationUnit::Picograys:
                return (value * 1e-12);

            case AbsorbedDoseOfIonizingRadiationUnit::Nanograys:
                return (value * 1e-9);

            case AbsorbedDoseOfIonizingRadiationUnit::Micrograys:
                return (value * 1e-6);

            case AbsorbedDoseOfIonizingRadiationUnit::Milligrays:
                return (value * 1e-3);

            case AbsorbedDoseOfIonizingRadiationUnit::Centigrays:
                return (value * 1e-2);

            case AbsorbedDoseOfIonizingRadiationUnit::Decigrays:
                return (value * 1e-1);

            case AbsorbedDoseOfIonizingRadiationUnit::Kilograys:
                return (value * 1e3);

            case AbsorbedDoseOfIonizingRadiationUnit::Megagrays:
                return (value * 1e6);

            case AbsorbedDoseOfIonizingRadiationUnit::Gigagrays:
                return (value * 1e9);

            case AbsorbedDoseOfIonizingRadiationUnit::Teragrays:
                return (value * 1e12);

            case AbsorbedDoseOfIonizingRadiationUnit::Petagrays:
                return (value * 1e15);

            case AbsorbedDoseOfIonizingRadiationUnit::Rads:
                return value / 100;

            case AbsorbedDoseOfIonizingRadiationUnit::Millirads:
                return (value * 1e-3) / 100;

            case AbsorbedDoseOfIonizingRadiationUnit::Kilorads:
                return (value * 1e3) / 100;

            case AbsorbedDoseOfIonizingRadiationUnit::Megarads:
                return (value * 1e6) / 100;

            }

            throw std::invalid_argument("Unknown AbsorbedDoseOfIonizingRadiation unit.");
        }

        [[nodiscard]] constexpr double convert_from_base(AbsorbedDoseOfIonizingRadiationUnit unit) const
        {
            switch (unit)
            {

            case AbsorbedDoseOfIonizingRadiationUnit::Grays:
                return value_;

            case AbsorbedDoseOfIonizingRadiationUnit::Femtograys:
                return (value_) / 1e-15;

            case AbsorbedDoseOfIonizingRadiationUnit::Picograys:
                return (value_) / 1e-12;

            case AbsorbedDoseOfIonizingRadiationUnit::Nanograys:
                return (value_) / 1e-9;

            case AbsorbedDoseOfIonizingRadiationUnit::Micrograys:
                return (value_) / 1e-6;

            case AbsorbedDoseOfIonizingRadiationUnit::Milligrays:
                return (value_) / 1e-3;

            case AbsorbedDoseOfIonizingRadiationUnit::Centigrays:
                return (value_) / 1e-2;

            case AbsorbedDoseOfIonizingRadiationUnit::Decigrays:
                return (value_) / 1e-1;

            case AbsorbedDoseOfIonizingRadiationUnit::Kilograys:
                return (value_) / 1e3;

            case AbsorbedDoseOfIonizingRadiationUnit::Megagrays:
                return (value_) / 1e6;

            case AbsorbedDoseOfIonizingRadiationUnit::Gigagrays:
                return (value_) / 1e9;

            case AbsorbedDoseOfIonizingRadiationUnit::Teragrays:
                return (value_) / 1e12;

            case AbsorbedDoseOfIonizingRadiationUnit::Petagrays:
                return (value_) / 1e15;

            case AbsorbedDoseOfIonizingRadiationUnit::Rads:
                return value_ * 100;

            case AbsorbedDoseOfIonizingRadiationUnit::Millirads:
                return (value_ * 100) / 1e-3;

            case AbsorbedDoseOfIonizingRadiationUnit::Kilorads:
                return (value_ * 100) / 1e3;

            case AbsorbedDoseOfIonizingRadiationUnit::Megarads:
                return (value_ * 100) / 1e6;

            }

            throw std::invalid_argument("Unknown AbsorbedDoseOfIonizingRadiation unit.");
        }

        double value_;
    };
}
