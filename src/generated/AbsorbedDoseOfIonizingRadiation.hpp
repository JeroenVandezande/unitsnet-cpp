#pragma once

#include <cstdint>
#include <numbers>
#include <stdexcept>
#include "UnitsNetConfig.h"

namespace unitsnet_cpp
{
    enum class AbsorbedDoseOfIonizingRadiationUnit : std::uint8_t
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
            const un_scalar_t value,
            const AbsorbedDoseOfIonizingRadiationUnit unit = AbsorbedDoseOfIonizingRadiationUnit::Grays)
            : value_(convert_to_base(value, unit))
        {
        }

        [[nodiscard]] constexpr un_scalar_t base_value() const noexcept
        {
            return value_;
        }

        [[nodiscard]] constexpr un_scalar_t value(const AbsorbedDoseOfIonizingRadiationUnit unit) const
        {
            return convert_from_base(unit);
        }

        [[nodiscard]] constexpr AbsorbedDoseOfIonizingRadiation operator+(const AbsorbedDoseOfIonizingRadiation other) const noexcept
        {
            return AbsorbedDoseOfIonizingRadiation(value_ + other.value_);
        }

        [[nodiscard]] constexpr AbsorbedDoseOfIonizingRadiation operator-(const AbsorbedDoseOfIonizingRadiation other) const noexcept
        {
            return AbsorbedDoseOfIonizingRadiation(value_ - other.value_);
        }

        [[nodiscard]] constexpr AbsorbedDoseOfIonizingRadiation operator*(const un_scalar_t scalar) const noexcept
        {
            return AbsorbedDoseOfIonizingRadiation(value_ * scalar);
        }

        [[nodiscard]] constexpr AbsorbedDoseOfIonizingRadiation operator/(const un_scalar_t scalar) const noexcept
        {
            return AbsorbedDoseOfIonizingRadiation(value_ / scalar);
        }

        [[nodiscard]] constexpr bool operator==(const AbsorbedDoseOfIonizingRadiation other) const noexcept
        {
            return value_ == other.value_;
        }

        [[nodiscard]] constexpr bool operator<(const AbsorbedDoseOfIonizingRadiation other) const noexcept
        {
            return value_ < other.value_;
        }


        [[nodiscard]] constexpr un_scalar_t grays() const
        {
            return convert_from_base(AbsorbedDoseOfIonizingRadiationUnit::Grays);
        }

        [[nodiscard]] static constexpr AbsorbedDoseOfIonizingRadiation from_grays(const un_scalar_t value)
        {
            return AbsorbedDoseOfIonizingRadiation(value, AbsorbedDoseOfIonizingRadiationUnit::Grays);
        }


        [[nodiscard]] constexpr un_scalar_t femtograys() const
        {
            return convert_from_base(AbsorbedDoseOfIonizingRadiationUnit::Femtograys);
        }

        [[nodiscard]] static constexpr AbsorbedDoseOfIonizingRadiation from_femtograys(const un_scalar_t value)
        {
            return AbsorbedDoseOfIonizingRadiation(value, AbsorbedDoseOfIonizingRadiationUnit::Femtograys);
        }


        [[nodiscard]] constexpr un_scalar_t picograys() const
        {
            return convert_from_base(AbsorbedDoseOfIonizingRadiationUnit::Picograys);
        }

        [[nodiscard]] static constexpr AbsorbedDoseOfIonizingRadiation from_picograys(const un_scalar_t value)
        {
            return AbsorbedDoseOfIonizingRadiation(value, AbsorbedDoseOfIonizingRadiationUnit::Picograys);
        }


        [[nodiscard]] constexpr un_scalar_t nanograys() const
        {
            return convert_from_base(AbsorbedDoseOfIonizingRadiationUnit::Nanograys);
        }

        [[nodiscard]] static constexpr AbsorbedDoseOfIonizingRadiation from_nanograys(const un_scalar_t value)
        {
            return AbsorbedDoseOfIonizingRadiation(value, AbsorbedDoseOfIonizingRadiationUnit::Nanograys);
        }


        [[nodiscard]] constexpr un_scalar_t micrograys() const
        {
            return convert_from_base(AbsorbedDoseOfIonizingRadiationUnit::Micrograys);
        }

        [[nodiscard]] static constexpr AbsorbedDoseOfIonizingRadiation from_micrograys(const un_scalar_t value)
        {
            return AbsorbedDoseOfIonizingRadiation(value, AbsorbedDoseOfIonizingRadiationUnit::Micrograys);
        }


        [[nodiscard]] constexpr un_scalar_t milligrays() const
        {
            return convert_from_base(AbsorbedDoseOfIonizingRadiationUnit::Milligrays);
        }

        [[nodiscard]] static constexpr AbsorbedDoseOfIonizingRadiation from_milligrays(const un_scalar_t value)
        {
            return AbsorbedDoseOfIonizingRadiation(value, AbsorbedDoseOfIonizingRadiationUnit::Milligrays);
        }


        [[nodiscard]] constexpr un_scalar_t centigrays() const
        {
            return convert_from_base(AbsorbedDoseOfIonizingRadiationUnit::Centigrays);
        }

        [[nodiscard]] static constexpr AbsorbedDoseOfIonizingRadiation from_centigrays(const un_scalar_t value)
        {
            return AbsorbedDoseOfIonizingRadiation(value, AbsorbedDoseOfIonizingRadiationUnit::Centigrays);
        }


        [[nodiscard]] constexpr un_scalar_t decigrays() const
        {
            return convert_from_base(AbsorbedDoseOfIonizingRadiationUnit::Decigrays);
        }

        [[nodiscard]] static constexpr AbsorbedDoseOfIonizingRadiation from_decigrays(const un_scalar_t value)
        {
            return AbsorbedDoseOfIonizingRadiation(value, AbsorbedDoseOfIonizingRadiationUnit::Decigrays);
        }


        [[nodiscard]] constexpr un_scalar_t kilograys() const
        {
            return convert_from_base(AbsorbedDoseOfIonizingRadiationUnit::Kilograys);
        }

        [[nodiscard]] static constexpr AbsorbedDoseOfIonizingRadiation from_kilograys(const un_scalar_t value)
        {
            return AbsorbedDoseOfIonizingRadiation(value, AbsorbedDoseOfIonizingRadiationUnit::Kilograys);
        }


        [[nodiscard]] constexpr un_scalar_t megagrays() const
        {
            return convert_from_base(AbsorbedDoseOfIonizingRadiationUnit::Megagrays);
        }

        [[nodiscard]] static constexpr AbsorbedDoseOfIonizingRadiation from_megagrays(const un_scalar_t value)
        {
            return AbsorbedDoseOfIonizingRadiation(value, AbsorbedDoseOfIonizingRadiationUnit::Megagrays);
        }


        [[nodiscard]] constexpr un_scalar_t gigagrays() const
        {
            return convert_from_base(AbsorbedDoseOfIonizingRadiationUnit::Gigagrays);
        }

        [[nodiscard]] static constexpr AbsorbedDoseOfIonizingRadiation from_gigagrays(const un_scalar_t value)
        {
            return AbsorbedDoseOfIonizingRadiation(value, AbsorbedDoseOfIonizingRadiationUnit::Gigagrays);
        }


        [[nodiscard]] constexpr un_scalar_t teragrays() const
        {
            return convert_from_base(AbsorbedDoseOfIonizingRadiationUnit::Teragrays);
        }

        [[nodiscard]] static constexpr AbsorbedDoseOfIonizingRadiation from_teragrays(const un_scalar_t value)
        {
            return AbsorbedDoseOfIonizingRadiation(value, AbsorbedDoseOfIonizingRadiationUnit::Teragrays);
        }


        [[nodiscard]] constexpr un_scalar_t petagrays() const
        {
            return convert_from_base(AbsorbedDoseOfIonizingRadiationUnit::Petagrays);
        }

        [[nodiscard]] static constexpr AbsorbedDoseOfIonizingRadiation from_petagrays(const un_scalar_t value)
        {
            return AbsorbedDoseOfIonizingRadiation(value, AbsorbedDoseOfIonizingRadiationUnit::Petagrays);
        }


        [[nodiscard]] constexpr un_scalar_t rads() const
        {
            return convert_from_base(AbsorbedDoseOfIonizingRadiationUnit::Rads);
        }

        [[nodiscard]] static constexpr AbsorbedDoseOfIonizingRadiation from_rads(const un_scalar_t value)
        {
            return AbsorbedDoseOfIonizingRadiation(value, AbsorbedDoseOfIonizingRadiationUnit::Rads);
        }


        [[nodiscard]] constexpr un_scalar_t millirads() const
        {
            return convert_from_base(AbsorbedDoseOfIonizingRadiationUnit::Millirads);
        }

        [[nodiscard]] static constexpr AbsorbedDoseOfIonizingRadiation from_millirads(const un_scalar_t value)
        {
            return AbsorbedDoseOfIonizingRadiation(value, AbsorbedDoseOfIonizingRadiationUnit::Millirads);
        }


        [[nodiscard]] constexpr un_scalar_t kilorads() const
        {
            return convert_from_base(AbsorbedDoseOfIonizingRadiationUnit::Kilorads);
        }

        [[nodiscard]] static constexpr AbsorbedDoseOfIonizingRadiation from_kilorads(const un_scalar_t value)
        {
            return AbsorbedDoseOfIonizingRadiation(value, AbsorbedDoseOfIonizingRadiationUnit::Kilorads);
        }


        [[nodiscard]] constexpr un_scalar_t megarads() const
        {
            return convert_from_base(AbsorbedDoseOfIonizingRadiationUnit::Megarads);
        }

        [[nodiscard]] static constexpr AbsorbedDoseOfIonizingRadiation from_megarads(const un_scalar_t value)
        {
            return AbsorbedDoseOfIonizingRadiation(value, AbsorbedDoseOfIonizingRadiationUnit::Megarads);
        }


    private:
        [[nodiscard]] static constexpr un_scalar_t convert_to_base(un_scalar_t value, AbsorbedDoseOfIonizingRadiationUnit unit)
        {
            switch (unit)
            {

            case AbsorbedDoseOfIonizingRadiationUnit::Grays:
                return value;

            case AbsorbedDoseOfIonizingRadiationUnit::Femtograys:
                return (value * static_cast<un_scalar_t>(1e-15));

            case AbsorbedDoseOfIonizingRadiationUnit::Picograys:
                return (value * static_cast<un_scalar_t>(1e-12));

            case AbsorbedDoseOfIonizingRadiationUnit::Nanograys:
                return (value * static_cast<un_scalar_t>(1e-9));

            case AbsorbedDoseOfIonizingRadiationUnit::Micrograys:
                return (value * static_cast<un_scalar_t>(1e-6));

            case AbsorbedDoseOfIonizingRadiationUnit::Milligrays:
                return (value * static_cast<un_scalar_t>(1e-3));

            case AbsorbedDoseOfIonizingRadiationUnit::Centigrays:
                return (value * static_cast<un_scalar_t>(1e-2));

            case AbsorbedDoseOfIonizingRadiationUnit::Decigrays:
                return (value * static_cast<un_scalar_t>(1e-1));

            case AbsorbedDoseOfIonizingRadiationUnit::Kilograys:
                return (value * static_cast<un_scalar_t>(1e3));

            case AbsorbedDoseOfIonizingRadiationUnit::Megagrays:
                return (value * static_cast<un_scalar_t>(1e6));

            case AbsorbedDoseOfIonizingRadiationUnit::Gigagrays:
                return (value * static_cast<un_scalar_t>(1e9));

            case AbsorbedDoseOfIonizingRadiationUnit::Teragrays:
                return (value * static_cast<un_scalar_t>(1e12));

            case AbsorbedDoseOfIonizingRadiationUnit::Petagrays:
                return (value * static_cast<un_scalar_t>(1e15));

            case AbsorbedDoseOfIonizingRadiationUnit::Rads:
                return value / 100;

            case AbsorbedDoseOfIonizingRadiationUnit::Millirads:
                return (value * static_cast<un_scalar_t>(1e-3)) / 100;

            case AbsorbedDoseOfIonizingRadiationUnit::Kilorads:
                return (value * static_cast<un_scalar_t>(1e3)) / 100;

            case AbsorbedDoseOfIonizingRadiationUnit::Megarads:
                return (value * static_cast<un_scalar_t>(1e6)) / 100;

            }

            throw std::invalid_argument("Unknown AbsorbedDoseOfIonizingRadiation unit.");
        }

        [[nodiscard]] constexpr un_scalar_t convert_from_base(const AbsorbedDoseOfIonizingRadiationUnit unit) const
        {
            switch (unit)
            {

            case AbsorbedDoseOfIonizingRadiationUnit::Grays:
                return value_;

            case AbsorbedDoseOfIonizingRadiationUnit::Femtograys:
                return (value_) / static_cast<un_scalar_t>(1e-15);

            case AbsorbedDoseOfIonizingRadiationUnit::Picograys:
                return (value_) / static_cast<un_scalar_t>(1e-12);

            case AbsorbedDoseOfIonizingRadiationUnit::Nanograys:
                return (value_) / static_cast<un_scalar_t>(1e-9);

            case AbsorbedDoseOfIonizingRadiationUnit::Micrograys:
                return (value_) / static_cast<un_scalar_t>(1e-6);

            case AbsorbedDoseOfIonizingRadiationUnit::Milligrays:
                return (value_) / static_cast<un_scalar_t>(1e-3);

            case AbsorbedDoseOfIonizingRadiationUnit::Centigrays:
                return (value_) / static_cast<un_scalar_t>(1e-2);

            case AbsorbedDoseOfIonizingRadiationUnit::Decigrays:
                return (value_) / static_cast<un_scalar_t>(1e-1);

            case AbsorbedDoseOfIonizingRadiationUnit::Kilograys:
                return (value_) / static_cast<un_scalar_t>(1e3);

            case AbsorbedDoseOfIonizingRadiationUnit::Megagrays:
                return (value_) / static_cast<un_scalar_t>(1e6);

            case AbsorbedDoseOfIonizingRadiationUnit::Gigagrays:
                return (value_) / static_cast<un_scalar_t>(1e9);

            case AbsorbedDoseOfIonizingRadiationUnit::Teragrays:
                return (value_) / static_cast<un_scalar_t>(1e12);

            case AbsorbedDoseOfIonizingRadiationUnit::Petagrays:
                return (value_) / static_cast<un_scalar_t>(1e15);

            case AbsorbedDoseOfIonizingRadiationUnit::Rads:
                return value_ * 100;

            case AbsorbedDoseOfIonizingRadiationUnit::Millirads:
                return (value_ * 100) / static_cast<un_scalar_t>(1e-3);

            case AbsorbedDoseOfIonizingRadiationUnit::Kilorads:
                return (value_ * 100) / static_cast<un_scalar_t>(1e3);

            case AbsorbedDoseOfIonizingRadiationUnit::Megarads:
                return (value_ * 100) / static_cast<un_scalar_t>(1e6);

            }

            throw std::invalid_argument("Unknown AbsorbedDoseOfIonizingRadiation unit.");
        }

        un_scalar_t value_;
    };
}
