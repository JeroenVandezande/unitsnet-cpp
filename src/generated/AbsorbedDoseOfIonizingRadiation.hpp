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
        
        constexpr explicit AbsorbedDoseOfIonizingRadiation(const bool isValid)
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
        
        [[nodiscard]] constexpr bool operator>(const AbsorbedDoseOfIonizingRadiation other) const noexcept
        {
            return value_ > other.value_;
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
        bool _isInvalid = false;
    
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
                return value_ * static_cast<un_scalar_t>(100);

            case AbsorbedDoseOfIonizingRadiationUnit::Millirads:
                return (value_ * static_cast<un_scalar_t>(100)) / static_cast<un_scalar_t>(1e-3);

            case AbsorbedDoseOfIonizingRadiationUnit::Kilorads:
                return (value_ * static_cast<un_scalar_t>(100)) / static_cast<un_scalar_t>(1e3);

            case AbsorbedDoseOfIonizingRadiationUnit::Megarads:
                return (value_ * static_cast<un_scalar_t>(100)) / static_cast<un_scalar_t>(1e6);

            }

            throw std::invalid_argument("Unknown AbsorbedDoseOfIonizingRadiation unit.");
        }

        un_scalar_t value_;
    };
}
