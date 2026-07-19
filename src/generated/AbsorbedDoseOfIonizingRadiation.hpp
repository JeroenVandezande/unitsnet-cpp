#pragma once

#include <cstdint>
#include <numbers>
#include <stdexcept>
#include "UnitsNetConfig.h"
#include "UnitsNetBase.h"

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
    class AbsorbedDoseOfIonizingRadiation : public UnitsNetBase
    {
    public:
        constexpr explicit AbsorbedDoseOfIonizingRadiation(
            const un_scalar_t value,
            const AbsorbedDoseOfIonizingRadiationUnit unit = AbsorbedDoseOfIonizingRadiationUnit::Grays)
        {
            value_ = value;
            value_unit_type_ = unit;
        }
                
        [[nodiscard]] constexpr un_scalar_t base_value() const noexcept
        {
            return convert_to_base(value_, value_unit_type_);    
        }

        [[nodiscard]] constexpr un_scalar_t value(const AbsorbedDoseOfIonizingRadiationUnit unit) const
        {
            return convert_from_base(unit);
        }

        [[nodiscard]] constexpr AbsorbedDoseOfIonizingRadiation operator+(const AbsorbedDoseOfIonizingRadiation& other) const noexcept
        {
            return AbsorbedDoseOfIonizingRadiation(base_value() + other.base_value());
        }

        [[nodiscard]] constexpr AbsorbedDoseOfIonizingRadiation operator-(const AbsorbedDoseOfIonizingRadiation& other)const noexcept
        {
            return AbsorbedDoseOfIonizingRadiation(base_value() - other.base_value());
        }

        [[nodiscard]] constexpr AbsorbedDoseOfIonizingRadiation operator*(const un_scalar_t scalar) const noexcept
        {
            return AbsorbedDoseOfIonizingRadiation(base_value() * scalar);
        }

        [[nodiscard]] constexpr AbsorbedDoseOfIonizingRadiation operator/(const un_scalar_t scalar) const noexcept
        {
            return AbsorbedDoseOfIonizingRadiation(base_value() / scalar);
        }

        [[nodiscard]] constexpr bool operator==(const AbsorbedDoseOfIonizingRadiation& other) const noexcept
        {
            return base_value() == other.base_value();
        }

        [[nodiscard]] constexpr bool operator<(const AbsorbedDoseOfIonizingRadiation& other) const noexcept
        {
            return base_value() < other.base_value();
        }
        
        [[nodiscard]] constexpr bool operator>(const AbsorbedDoseOfIonizingRadiation& other) const noexcept
        {
            return base_value() > other.base_value();
        }

        /// <summary>The gray is the unit of ionizing radiation dose in the SI, defined as the absorption of one joule of radiation energy per kilogram of matter.</summary>
        [[nodiscard]] constexpr un_scalar_t grays() const
        {
            return convert_from_base(AbsorbedDoseOfIonizingRadiationUnit::Grays);
        }

        /// <summary>The gray is the unit of ionizing radiation dose in the SI, defined as the absorption of one joule of radiation energy per kilogram of matter.</summary>
        [[nodiscard]] static constexpr AbsorbedDoseOfIonizingRadiation from_grays(const un_scalar_t value)
        {
            return AbsorbedDoseOfIonizingRadiation(value, AbsorbedDoseOfIonizingRadiationUnit::Grays);
        }

        /// <summary>The gray is the unit of ionizing radiation dose in the SI, defined as the absorption of one joule of radiation energy per kilogram of matter.</summary>
        [[nodiscard]] constexpr un_scalar_t femtograys() const
        {
            return convert_from_base(AbsorbedDoseOfIonizingRadiationUnit::Femtograys);
        }

        /// <summary>The gray is the unit of ionizing radiation dose in the SI, defined as the absorption of one joule of radiation energy per kilogram of matter.</summary>
        [[nodiscard]] static constexpr AbsorbedDoseOfIonizingRadiation from_femtograys(const un_scalar_t value)
        {
            return AbsorbedDoseOfIonizingRadiation(value, AbsorbedDoseOfIonizingRadiationUnit::Femtograys);
        }

        /// <summary>The gray is the unit of ionizing radiation dose in the SI, defined as the absorption of one joule of radiation energy per kilogram of matter.</summary>
        [[nodiscard]] constexpr un_scalar_t picograys() const
        {
            return convert_from_base(AbsorbedDoseOfIonizingRadiationUnit::Picograys);
        }

        /// <summary>The gray is the unit of ionizing radiation dose in the SI, defined as the absorption of one joule of radiation energy per kilogram of matter.</summary>
        [[nodiscard]] static constexpr AbsorbedDoseOfIonizingRadiation from_picograys(const un_scalar_t value)
        {
            return AbsorbedDoseOfIonizingRadiation(value, AbsorbedDoseOfIonizingRadiationUnit::Picograys);
        }

        /// <summary>The gray is the unit of ionizing radiation dose in the SI, defined as the absorption of one joule of radiation energy per kilogram of matter.</summary>
        [[nodiscard]] constexpr un_scalar_t nanograys() const
        {
            return convert_from_base(AbsorbedDoseOfIonizingRadiationUnit::Nanograys);
        }

        /// <summary>The gray is the unit of ionizing radiation dose in the SI, defined as the absorption of one joule of radiation energy per kilogram of matter.</summary>
        [[nodiscard]] static constexpr AbsorbedDoseOfIonizingRadiation from_nanograys(const un_scalar_t value)
        {
            return AbsorbedDoseOfIonizingRadiation(value, AbsorbedDoseOfIonizingRadiationUnit::Nanograys);
        }

        /// <summary>The gray is the unit of ionizing radiation dose in the SI, defined as the absorption of one joule of radiation energy per kilogram of matter.</summary>
        [[nodiscard]] constexpr un_scalar_t micrograys() const
        {
            return convert_from_base(AbsorbedDoseOfIonizingRadiationUnit::Micrograys);
        }

        /// <summary>The gray is the unit of ionizing radiation dose in the SI, defined as the absorption of one joule of radiation energy per kilogram of matter.</summary>
        [[nodiscard]] static constexpr AbsorbedDoseOfIonizingRadiation from_micrograys(const un_scalar_t value)
        {
            return AbsorbedDoseOfIonizingRadiation(value, AbsorbedDoseOfIonizingRadiationUnit::Micrograys);
        }

        /// <summary>The gray is the unit of ionizing radiation dose in the SI, defined as the absorption of one joule of radiation energy per kilogram of matter.</summary>
        [[nodiscard]] constexpr un_scalar_t milligrays() const
        {
            return convert_from_base(AbsorbedDoseOfIonizingRadiationUnit::Milligrays);
        }

        /// <summary>The gray is the unit of ionizing radiation dose in the SI, defined as the absorption of one joule of radiation energy per kilogram of matter.</summary>
        [[nodiscard]] static constexpr AbsorbedDoseOfIonizingRadiation from_milligrays(const un_scalar_t value)
        {
            return AbsorbedDoseOfIonizingRadiation(value, AbsorbedDoseOfIonizingRadiationUnit::Milligrays);
        }

        /// <summary>The gray is the unit of ionizing radiation dose in the SI, defined as the absorption of one joule of radiation energy per kilogram of matter.</summary>
        [[nodiscard]] constexpr un_scalar_t centigrays() const
        {
            return convert_from_base(AbsorbedDoseOfIonizingRadiationUnit::Centigrays);
        }

        /// <summary>The gray is the unit of ionizing radiation dose in the SI, defined as the absorption of one joule of radiation energy per kilogram of matter.</summary>
        [[nodiscard]] static constexpr AbsorbedDoseOfIonizingRadiation from_centigrays(const un_scalar_t value)
        {
            return AbsorbedDoseOfIonizingRadiation(value, AbsorbedDoseOfIonizingRadiationUnit::Centigrays);
        }

        /// <summary>The gray is the unit of ionizing radiation dose in the SI, defined as the absorption of one joule of radiation energy per kilogram of matter.</summary>
        [[nodiscard]] constexpr un_scalar_t decigrays() const
        {
            return convert_from_base(AbsorbedDoseOfIonizingRadiationUnit::Decigrays);
        }

        /// <summary>The gray is the unit of ionizing radiation dose in the SI, defined as the absorption of one joule of radiation energy per kilogram of matter.</summary>
        [[nodiscard]] static constexpr AbsorbedDoseOfIonizingRadiation from_decigrays(const un_scalar_t value)
        {
            return AbsorbedDoseOfIonizingRadiation(value, AbsorbedDoseOfIonizingRadiationUnit::Decigrays);
        }

        /// <summary>The gray is the unit of ionizing radiation dose in the SI, defined as the absorption of one joule of radiation energy per kilogram of matter.</summary>
        [[nodiscard]] constexpr un_scalar_t kilograys() const
        {
            return convert_from_base(AbsorbedDoseOfIonizingRadiationUnit::Kilograys);
        }

        /// <summary>The gray is the unit of ionizing radiation dose in the SI, defined as the absorption of one joule of radiation energy per kilogram of matter.</summary>
        [[nodiscard]] static constexpr AbsorbedDoseOfIonizingRadiation from_kilograys(const un_scalar_t value)
        {
            return AbsorbedDoseOfIonizingRadiation(value, AbsorbedDoseOfIonizingRadiationUnit::Kilograys);
        }

        /// <summary>The gray is the unit of ionizing radiation dose in the SI, defined as the absorption of one joule of radiation energy per kilogram of matter.</summary>
        [[nodiscard]] constexpr un_scalar_t megagrays() const
        {
            return convert_from_base(AbsorbedDoseOfIonizingRadiationUnit::Megagrays);
        }

        /// <summary>The gray is the unit of ionizing radiation dose in the SI, defined as the absorption of one joule of radiation energy per kilogram of matter.</summary>
        [[nodiscard]] static constexpr AbsorbedDoseOfIonizingRadiation from_megagrays(const un_scalar_t value)
        {
            return AbsorbedDoseOfIonizingRadiation(value, AbsorbedDoseOfIonizingRadiationUnit::Megagrays);
        }

        /// <summary>The gray is the unit of ionizing radiation dose in the SI, defined as the absorption of one joule of radiation energy per kilogram of matter.</summary>
        [[nodiscard]] constexpr un_scalar_t gigagrays() const
        {
            return convert_from_base(AbsorbedDoseOfIonizingRadiationUnit::Gigagrays);
        }

        /// <summary>The gray is the unit of ionizing radiation dose in the SI, defined as the absorption of one joule of radiation energy per kilogram of matter.</summary>
        [[nodiscard]] static constexpr AbsorbedDoseOfIonizingRadiation from_gigagrays(const un_scalar_t value)
        {
            return AbsorbedDoseOfIonizingRadiation(value, AbsorbedDoseOfIonizingRadiationUnit::Gigagrays);
        }

        /// <summary>The gray is the unit of ionizing radiation dose in the SI, defined as the absorption of one joule of radiation energy per kilogram of matter.</summary>
        [[nodiscard]] constexpr un_scalar_t teragrays() const
        {
            return convert_from_base(AbsorbedDoseOfIonizingRadiationUnit::Teragrays);
        }

        /// <summary>The gray is the unit of ionizing radiation dose in the SI, defined as the absorption of one joule of radiation energy per kilogram of matter.</summary>
        [[nodiscard]] static constexpr AbsorbedDoseOfIonizingRadiation from_teragrays(const un_scalar_t value)
        {
            return AbsorbedDoseOfIonizingRadiation(value, AbsorbedDoseOfIonizingRadiationUnit::Teragrays);
        }

        /// <summary>The gray is the unit of ionizing radiation dose in the SI, defined as the absorption of one joule of radiation energy per kilogram of matter.</summary>
        [[nodiscard]] constexpr un_scalar_t petagrays() const
        {
            return convert_from_base(AbsorbedDoseOfIonizingRadiationUnit::Petagrays);
        }

        /// <summary>The gray is the unit of ionizing radiation dose in the SI, defined as the absorption of one joule of radiation energy per kilogram of matter.</summary>
        [[nodiscard]] static constexpr AbsorbedDoseOfIonizingRadiation from_petagrays(const un_scalar_t value)
        {
            return AbsorbedDoseOfIonizingRadiation(value, AbsorbedDoseOfIonizingRadiationUnit::Petagrays);
        }

        /// <summary>The rad is a unit of absorbed radiation dose, defined as 1 rad = 0.01 Gy = 0.01 J/kg.</summary>
        [[nodiscard]] constexpr un_scalar_t rads() const
        {
            return convert_from_base(AbsorbedDoseOfIonizingRadiationUnit::Rads);
        }

        /// <summary>The rad is a unit of absorbed radiation dose, defined as 1 rad = 0.01 Gy = 0.01 J/kg.</summary>
        [[nodiscard]] static constexpr AbsorbedDoseOfIonizingRadiation from_rads(const un_scalar_t value)
        {
            return AbsorbedDoseOfIonizingRadiation(value, AbsorbedDoseOfIonizingRadiationUnit::Rads);
        }

        /// <summary>The rad is a unit of absorbed radiation dose, defined as 1 rad = 0.01 Gy = 0.01 J/kg.</summary>
        [[nodiscard]] constexpr un_scalar_t millirads() const
        {
            return convert_from_base(AbsorbedDoseOfIonizingRadiationUnit::Millirads);
        }

        /// <summary>The rad is a unit of absorbed radiation dose, defined as 1 rad = 0.01 Gy = 0.01 J/kg.</summary>
        [[nodiscard]] static constexpr AbsorbedDoseOfIonizingRadiation from_millirads(const un_scalar_t value)
        {
            return AbsorbedDoseOfIonizingRadiation(value, AbsorbedDoseOfIonizingRadiationUnit::Millirads);
        }

        /// <summary>The rad is a unit of absorbed radiation dose, defined as 1 rad = 0.01 Gy = 0.01 J/kg.</summary>
        [[nodiscard]] constexpr un_scalar_t kilorads() const
        {
            return convert_from_base(AbsorbedDoseOfIonizingRadiationUnit::Kilorads);
        }

        /// <summary>The rad is a unit of absorbed radiation dose, defined as 1 rad = 0.01 Gy = 0.01 J/kg.</summary>
        [[nodiscard]] static constexpr AbsorbedDoseOfIonizingRadiation from_kilorads(const un_scalar_t value)
        {
            return AbsorbedDoseOfIonizingRadiation(value, AbsorbedDoseOfIonizingRadiationUnit::Kilorads);
        }

        /// <summary>The rad is a unit of absorbed radiation dose, defined as 1 rad = 0.01 Gy = 0.01 J/kg.</summary>
        [[nodiscard]] constexpr un_scalar_t megarads() const
        {
            return convert_from_base(AbsorbedDoseOfIonizingRadiationUnit::Megarads);
        }

        /// <summary>The rad is a unit of absorbed radiation dose, defined as 1 rad = 0.01 Gy = 0.01 J/kg.</summary>
        [[nodiscard]] static constexpr AbsorbedDoseOfIonizingRadiation from_megarads(const un_scalar_t value)
        {
            return AbsorbedDoseOfIonizingRadiation(value, AbsorbedDoseOfIonizingRadiationUnit::Megarads);
        }

        [[nodiscard]] static constexpr AbsorbedDoseOfIonizingRadiation from_invalid()
        {
            return AbsorbedDoseOfIonizingRadiation(false);
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
                return value / static_cast<un_scalar_t>(100);

            case AbsorbedDoseOfIonizingRadiationUnit::Millirads:
                return (value * static_cast<un_scalar_t>(1e-3)) / static_cast<un_scalar_t>(100);

            case AbsorbedDoseOfIonizingRadiationUnit::Kilorads:
                return (value * static_cast<un_scalar_t>(1e3)) / static_cast<un_scalar_t>(100);

            case AbsorbedDoseOfIonizingRadiationUnit::Megarads:
                return (value * static_cast<un_scalar_t>(1e6)) / static_cast<un_scalar_t>(100);

            }

            throw std::invalid_argument("Unknown AbsorbedDoseOfIonizingRadiation unit.");
        }

        [[nodiscard]] constexpr un_scalar_t convert_from_base(const AbsorbedDoseOfIonizingRadiationUnit unit) const
        {
            if(unit == value_unit_type_)
            {
                return value_;
            }
            
            auto base_value = convert_to_base(value_, value_unit_type_);
            
            switch (unit)
            {

            case AbsorbedDoseOfIonizingRadiationUnit::Grays:
                return base_value;

            case AbsorbedDoseOfIonizingRadiationUnit::Femtograys:
                return (base_value) / static_cast<un_scalar_t>(1e-15);

            case AbsorbedDoseOfIonizingRadiationUnit::Picograys:
                return (base_value) / static_cast<un_scalar_t>(1e-12);

            case AbsorbedDoseOfIonizingRadiationUnit::Nanograys:
                return (base_value) / static_cast<un_scalar_t>(1e-9);

            case AbsorbedDoseOfIonizingRadiationUnit::Micrograys:
                return (base_value) / static_cast<un_scalar_t>(1e-6);

            case AbsorbedDoseOfIonizingRadiationUnit::Milligrays:
                return (base_value) / static_cast<un_scalar_t>(1e-3);

            case AbsorbedDoseOfIonizingRadiationUnit::Centigrays:
                return (base_value) / static_cast<un_scalar_t>(1e-2);

            case AbsorbedDoseOfIonizingRadiationUnit::Decigrays:
                return (base_value) / static_cast<un_scalar_t>(1e-1);

            case AbsorbedDoseOfIonizingRadiationUnit::Kilograys:
                return (base_value) / static_cast<un_scalar_t>(1e3);

            case AbsorbedDoseOfIonizingRadiationUnit::Megagrays:
                return (base_value) / static_cast<un_scalar_t>(1e6);

            case AbsorbedDoseOfIonizingRadiationUnit::Gigagrays:
                return (base_value) / static_cast<un_scalar_t>(1e9);

            case AbsorbedDoseOfIonizingRadiationUnit::Teragrays:
                return (base_value) / static_cast<un_scalar_t>(1e12);

            case AbsorbedDoseOfIonizingRadiationUnit::Petagrays:
                return (base_value) / static_cast<un_scalar_t>(1e15);

            case AbsorbedDoseOfIonizingRadiationUnit::Rads:
                return base_value * static_cast<un_scalar_t>(100);

            case AbsorbedDoseOfIonizingRadiationUnit::Millirads:
                return (base_value * static_cast<un_scalar_t>(100)) / static_cast<un_scalar_t>(1e-3);

            case AbsorbedDoseOfIonizingRadiationUnit::Kilorads:
                return (base_value * static_cast<un_scalar_t>(100)) / static_cast<un_scalar_t>(1e3);

            case AbsorbedDoseOfIonizingRadiationUnit::Megarads:
                return (base_value * static_cast<un_scalar_t>(100)) / static_cast<un_scalar_t>(1e6);

            }

            throw std::invalid_argument("Unknown AbsorbedDoseOfIonizingRadiation unit.");
        }

        un_scalar_t value_;
        AbsorbedDoseOfIonizingRadiationUnit value_unit_type_;       
    };
}
