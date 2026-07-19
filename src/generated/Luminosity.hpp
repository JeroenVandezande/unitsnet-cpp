#pragma once

#include <cstdint>
#include <numbers>
#include <stdexcept>
#include "UnitsNetConfig.h"
#include "UnitsNetBase.h"

namespace unitsnet_cpp
{
    enum class LuminosityUnit : std::uint8_t
    {
        Watts,
        Femtowatts,
        Picowatts,
        Nanowatts,
        Microwatts,
        Milliwatts,
        Deciwatts,
        Decawatts,
        Kilowatts,
        Megawatts,
        Gigawatts,
        Terawatts,
        Petawatts,
        SolarLuminosities,
    };

    /// <summary>Luminosity is an absolute measure of radiated electromagnetic power (light), the radiant power emitted by a light-emitting object.</summary>
    class Luminosity : public UnitsNetBase
    {
    public:
        constexpr explicit Luminosity(
            const un_scalar_t value,
            const LuminosityUnit unit = LuminosityUnit::Watts)
        {
            value_ = value;
            value_unit_type_ = unit;
            if(unit == LuminosityUnit::Watts)
            {
                base_value_ = value;
                base_value_exists_ = true;
            }
            else
            {
                base_value_ = 0;
                base_value_exists_ = false;
            }
        }
        
        constexpr void create_base_value_if_needed() const noexcept
        {
            if(base_value_exists_)
            {
                return;
            }
            else
            {
                base_value_ = convert_to_base(value_, value_unit_type_);
                base_value_exists_ = true;
                return;
            }
        }
                
        [[nodiscard]] constexpr un_scalar_t base_value() const noexcept
        {
            create_base_value_if_needed();    
            return base_value_;    
        }

        [[nodiscard]] constexpr un_scalar_t value(const LuminosityUnit unit) const
        {
            return convert_from_base(unit);
        }

        [[nodiscard]] constexpr Luminosity operator+(const Luminosity& other) const noexcept
        {
            return Luminosity(base_value() + other.base_value());
        }

        [[nodiscard]] constexpr Luminosity operator-(const Luminosity& other)const noexcept
        {
            return Luminosity(base_value() - other.base_value());
        }

        [[nodiscard]] constexpr Luminosity operator*(const un_scalar_t scalar) const noexcept
        {
            return Luminosity(base_value() * scalar);
        }

        [[nodiscard]] constexpr Luminosity operator/(const un_scalar_t scalar) const noexcept
        {
            return Luminosity(base_value() / scalar);
        }

        [[nodiscard]] constexpr bool operator==(const Luminosity& other) const noexcept
        {
            return base_value() == other.base_value();
        }

        [[nodiscard]] constexpr bool operator<(const Luminosity& other) const noexcept
        {
            return base_value() < other.base_value();
        }
        
        [[nodiscard]] constexpr bool operator>(const Luminosity& other) const noexcept
        {
            return base_value() > other.base_value();
        }


        [[nodiscard]] constexpr un_scalar_t watts() const
        {
            return convert_from_base(LuminosityUnit::Watts);
        }

        [[nodiscard]] static constexpr Luminosity from_watts(const un_scalar_t value)
        {
            return Luminosity(value, LuminosityUnit::Watts);
        }


        [[nodiscard]] constexpr un_scalar_t femtowatts() const
        {
            return convert_from_base(LuminosityUnit::Femtowatts);
        }

        [[nodiscard]] static constexpr Luminosity from_femtowatts(const un_scalar_t value)
        {
            return Luminosity(value, LuminosityUnit::Femtowatts);
        }


        [[nodiscard]] constexpr un_scalar_t picowatts() const
        {
            return convert_from_base(LuminosityUnit::Picowatts);
        }

        [[nodiscard]] static constexpr Luminosity from_picowatts(const un_scalar_t value)
        {
            return Luminosity(value, LuminosityUnit::Picowatts);
        }


        [[nodiscard]] constexpr un_scalar_t nanowatts() const
        {
            return convert_from_base(LuminosityUnit::Nanowatts);
        }

        [[nodiscard]] static constexpr Luminosity from_nanowatts(const un_scalar_t value)
        {
            return Luminosity(value, LuminosityUnit::Nanowatts);
        }


        [[nodiscard]] constexpr un_scalar_t microwatts() const
        {
            return convert_from_base(LuminosityUnit::Microwatts);
        }

        [[nodiscard]] static constexpr Luminosity from_microwatts(const un_scalar_t value)
        {
            return Luminosity(value, LuminosityUnit::Microwatts);
        }


        [[nodiscard]] constexpr un_scalar_t milliwatts() const
        {
            return convert_from_base(LuminosityUnit::Milliwatts);
        }

        [[nodiscard]] static constexpr Luminosity from_milliwatts(const un_scalar_t value)
        {
            return Luminosity(value, LuminosityUnit::Milliwatts);
        }


        [[nodiscard]] constexpr un_scalar_t deciwatts() const
        {
            return convert_from_base(LuminosityUnit::Deciwatts);
        }

        [[nodiscard]] static constexpr Luminosity from_deciwatts(const un_scalar_t value)
        {
            return Luminosity(value, LuminosityUnit::Deciwatts);
        }


        [[nodiscard]] constexpr un_scalar_t decawatts() const
        {
            return convert_from_base(LuminosityUnit::Decawatts);
        }

        [[nodiscard]] static constexpr Luminosity from_decawatts(const un_scalar_t value)
        {
            return Luminosity(value, LuminosityUnit::Decawatts);
        }


        [[nodiscard]] constexpr un_scalar_t kilowatts() const
        {
            return convert_from_base(LuminosityUnit::Kilowatts);
        }

        [[nodiscard]] static constexpr Luminosity from_kilowatts(const un_scalar_t value)
        {
            return Luminosity(value, LuminosityUnit::Kilowatts);
        }


        [[nodiscard]] constexpr un_scalar_t megawatts() const
        {
            return convert_from_base(LuminosityUnit::Megawatts);
        }

        [[nodiscard]] static constexpr Luminosity from_megawatts(const un_scalar_t value)
        {
            return Luminosity(value, LuminosityUnit::Megawatts);
        }


        [[nodiscard]] constexpr un_scalar_t gigawatts() const
        {
            return convert_from_base(LuminosityUnit::Gigawatts);
        }

        [[nodiscard]] static constexpr Luminosity from_gigawatts(const un_scalar_t value)
        {
            return Luminosity(value, LuminosityUnit::Gigawatts);
        }


        [[nodiscard]] constexpr un_scalar_t terawatts() const
        {
            return convert_from_base(LuminosityUnit::Terawatts);
        }

        [[nodiscard]] static constexpr Luminosity from_terawatts(const un_scalar_t value)
        {
            return Luminosity(value, LuminosityUnit::Terawatts);
        }


        [[nodiscard]] constexpr un_scalar_t petawatts() const
        {
            return convert_from_base(LuminosityUnit::Petawatts);
        }

        [[nodiscard]] static constexpr Luminosity from_petawatts(const un_scalar_t value)
        {
            return Luminosity(value, LuminosityUnit::Petawatts);
        }


        /// <summary>The IAU has defined a nominal solar luminosity of 3.828×10^26 W to promote publication of consistent and comparable values in units of the solar luminosity.</summary>
        [[nodiscard]] constexpr un_scalar_t solar_luminosities() const
        {
            return convert_from_base(LuminosityUnit::SolarLuminosities);
        }

        /// <summary>The IAU has defined a nominal solar luminosity of 3.828×10^26 W to promote publication of consistent and comparable values in units of the solar luminosity.</summary>
        [[nodiscard]] static constexpr Luminosity from_solar_luminosities(const un_scalar_t value)
        {
            return Luminosity(value, LuminosityUnit::SolarLuminosities);
        }


        [[nodiscard]] static constexpr Luminosity from_invalid()
        {
            return Luminosity(false);
        }
    private:
            
        [[nodiscard]] static constexpr un_scalar_t convert_to_base(un_scalar_t value, LuminosityUnit unit)
        {
            switch (unit)
            {

            case LuminosityUnit::Watts:
                return value;

            case LuminosityUnit::Femtowatts:
                return (value * static_cast<un_scalar_t>(1e-15));

            case LuminosityUnit::Picowatts:
                return (value * static_cast<un_scalar_t>(1e-12));

            case LuminosityUnit::Nanowatts:
                return (value * static_cast<un_scalar_t>(1e-9));

            case LuminosityUnit::Microwatts:
                return (value * static_cast<un_scalar_t>(1e-6));

            case LuminosityUnit::Milliwatts:
                return (value * static_cast<un_scalar_t>(1e-3));

            case LuminosityUnit::Deciwatts:
                return (value * static_cast<un_scalar_t>(1e-1));

            case LuminosityUnit::Decawatts:
                return (value * static_cast<un_scalar_t>(1e1));

            case LuminosityUnit::Kilowatts:
                return (value * static_cast<un_scalar_t>(1e3));

            case LuminosityUnit::Megawatts:
                return (value * static_cast<un_scalar_t>(1e6));

            case LuminosityUnit::Gigawatts:
                return (value * static_cast<un_scalar_t>(1e9));

            case LuminosityUnit::Terawatts:
                return (value * static_cast<un_scalar_t>(1e12));

            case LuminosityUnit::Petawatts:
                return (value * static_cast<un_scalar_t>(1e15));

            case LuminosityUnit::SolarLuminosities:
                return value * static_cast<un_scalar_t>(3.828e26);

            }

            throw std::invalid_argument("Unknown Luminosity unit.");
        }

        [[nodiscard]] constexpr un_scalar_t convert_from_base(const LuminosityUnit unit) const
        {
            if(unit == value_unit_type_)
            {
                return value_;
            }
            
            create_base_value_if_needed();
            
            switch (unit)
            {

            case LuminosityUnit::Watts:
                return base_value_;

            case LuminosityUnit::Femtowatts:
                return (base_value_) / static_cast<un_scalar_t>(1e-15);

            case LuminosityUnit::Picowatts:
                return (base_value_) / static_cast<un_scalar_t>(1e-12);

            case LuminosityUnit::Nanowatts:
                return (base_value_) / static_cast<un_scalar_t>(1e-9);

            case LuminosityUnit::Microwatts:
                return (base_value_) / static_cast<un_scalar_t>(1e-6);

            case LuminosityUnit::Milliwatts:
                return (base_value_) / static_cast<un_scalar_t>(1e-3);

            case LuminosityUnit::Deciwatts:
                return (base_value_) / static_cast<un_scalar_t>(1e-1);

            case LuminosityUnit::Decawatts:
                return (base_value_) / static_cast<un_scalar_t>(1e1);

            case LuminosityUnit::Kilowatts:
                return (base_value_) / static_cast<un_scalar_t>(1e3);

            case LuminosityUnit::Megawatts:
                return (base_value_) / static_cast<un_scalar_t>(1e6);

            case LuminosityUnit::Gigawatts:
                return (base_value_) / static_cast<un_scalar_t>(1e9);

            case LuminosityUnit::Terawatts:
                return (base_value_) / static_cast<un_scalar_t>(1e12);

            case LuminosityUnit::Petawatts:
                return (base_value_) / static_cast<un_scalar_t>(1e15);

            case LuminosityUnit::SolarLuminosities:
                return base_value_ / static_cast<un_scalar_t>(3.828e26);

            }

            throw std::invalid_argument("Unknown Luminosity unit.");
        }

        un_scalar_t value_;
        LuminosityUnit value_unit_type_;
        mutable un_scalar_t base_value_;
        mutable bool base_value_exists_ = false;
       
    };
}
