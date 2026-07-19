#pragma once

#include <cstdint>
#include <numbers>
#include <stdexcept>
#include "UnitsNetConfig.h"
#include "UnitsNetBase.h"

namespace unitsnet_cpp
{
    enum class EnergyDensityUnit : std::uint8_t
    {
        JoulesPerCubicMeter,
        KilojoulesPerCubicMeter,
        MegajoulesPerCubicMeter,
        GigajoulesPerCubicMeter,
        TerajoulesPerCubicMeter,
        PetajoulesPerCubicMeter,
        WattHoursPerCubicMeter,
        KilowattHoursPerCubicMeter,
        MegawattHoursPerCubicMeter,
        GigawattHoursPerCubicMeter,
        TerawattHoursPerCubicMeter,
        PetawattHoursPerCubicMeter,
    };

    /// <summary></summary>
    class EnergyDensity : public UnitsNetBase
    {
    public:
        constexpr explicit EnergyDensity(
            const un_scalar_t value,
            const EnergyDensityUnit unit = EnergyDensityUnit::JoulesPerCubicMeter)
        {
            value_ = value;
            value_unit_type_ = unit;
            if(unit == EnergyDensityUnit::JoulesPerCubicMeter)
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

        [[nodiscard]] constexpr un_scalar_t value(const EnergyDensityUnit unit) const
        {
            return convert_from_base(unit);
        }

        [[nodiscard]] constexpr EnergyDensity operator+(const EnergyDensity& other) const noexcept
        {
            return EnergyDensity(base_value() + other.base_value());
        }

        [[nodiscard]] constexpr EnergyDensity operator-(const EnergyDensity& other)const noexcept
        {
            return EnergyDensity(base_value() - other.base_value());
        }

        [[nodiscard]] constexpr EnergyDensity operator*(const un_scalar_t scalar) const noexcept
        {
            return EnergyDensity(base_value() * scalar);
        }

        [[nodiscard]] constexpr EnergyDensity operator/(const un_scalar_t scalar) const noexcept
        {
            return EnergyDensity(base_value() / scalar);
        }

        [[nodiscard]] constexpr bool operator==(const EnergyDensity& other) const noexcept
        {
            return base_value() == other.base_value();
        }

        [[nodiscard]] constexpr bool operator<(const EnergyDensity& other) const noexcept
        {
            return base_value() < other.base_value();
        }
        
        [[nodiscard]] constexpr bool operator>(const EnergyDensity& other) const noexcept
        {
            return base_value() > other.base_value();
        }


        [[nodiscard]] constexpr un_scalar_t joules_per_cubic_meter() const
        {
            return convert_from_base(EnergyDensityUnit::JoulesPerCubicMeter);
        }

        [[nodiscard]] static constexpr EnergyDensity from_joules_per_cubic_meter(const un_scalar_t value)
        {
            return EnergyDensity(value, EnergyDensityUnit::JoulesPerCubicMeter);
        }


        [[nodiscard]] constexpr un_scalar_t kilojoules_per_cubic_meter() const
        {
            return convert_from_base(EnergyDensityUnit::KilojoulesPerCubicMeter);
        }

        [[nodiscard]] static constexpr EnergyDensity from_kilojoules_per_cubic_meter(const un_scalar_t value)
        {
            return EnergyDensity(value, EnergyDensityUnit::KilojoulesPerCubicMeter);
        }


        [[nodiscard]] constexpr un_scalar_t megajoules_per_cubic_meter() const
        {
            return convert_from_base(EnergyDensityUnit::MegajoulesPerCubicMeter);
        }

        [[nodiscard]] static constexpr EnergyDensity from_megajoules_per_cubic_meter(const un_scalar_t value)
        {
            return EnergyDensity(value, EnergyDensityUnit::MegajoulesPerCubicMeter);
        }


        [[nodiscard]] constexpr un_scalar_t gigajoules_per_cubic_meter() const
        {
            return convert_from_base(EnergyDensityUnit::GigajoulesPerCubicMeter);
        }

        [[nodiscard]] static constexpr EnergyDensity from_gigajoules_per_cubic_meter(const un_scalar_t value)
        {
            return EnergyDensity(value, EnergyDensityUnit::GigajoulesPerCubicMeter);
        }


        [[nodiscard]] constexpr un_scalar_t terajoules_per_cubic_meter() const
        {
            return convert_from_base(EnergyDensityUnit::TerajoulesPerCubicMeter);
        }

        [[nodiscard]] static constexpr EnergyDensity from_terajoules_per_cubic_meter(const un_scalar_t value)
        {
            return EnergyDensity(value, EnergyDensityUnit::TerajoulesPerCubicMeter);
        }


        [[nodiscard]] constexpr un_scalar_t petajoules_per_cubic_meter() const
        {
            return convert_from_base(EnergyDensityUnit::PetajoulesPerCubicMeter);
        }

        [[nodiscard]] static constexpr EnergyDensity from_petajoules_per_cubic_meter(const un_scalar_t value)
        {
            return EnergyDensity(value, EnergyDensityUnit::PetajoulesPerCubicMeter);
        }


        [[nodiscard]] constexpr un_scalar_t watt_hours_per_cubic_meter() const
        {
            return convert_from_base(EnergyDensityUnit::WattHoursPerCubicMeter);
        }

        [[nodiscard]] static constexpr EnergyDensity from_watt_hours_per_cubic_meter(const un_scalar_t value)
        {
            return EnergyDensity(value, EnergyDensityUnit::WattHoursPerCubicMeter);
        }


        [[nodiscard]] constexpr un_scalar_t kilowatt_hours_per_cubic_meter() const
        {
            return convert_from_base(EnergyDensityUnit::KilowattHoursPerCubicMeter);
        }

        [[nodiscard]] static constexpr EnergyDensity from_kilowatt_hours_per_cubic_meter(const un_scalar_t value)
        {
            return EnergyDensity(value, EnergyDensityUnit::KilowattHoursPerCubicMeter);
        }


        [[nodiscard]] constexpr un_scalar_t megawatt_hours_per_cubic_meter() const
        {
            return convert_from_base(EnergyDensityUnit::MegawattHoursPerCubicMeter);
        }

        [[nodiscard]] static constexpr EnergyDensity from_megawatt_hours_per_cubic_meter(const un_scalar_t value)
        {
            return EnergyDensity(value, EnergyDensityUnit::MegawattHoursPerCubicMeter);
        }


        [[nodiscard]] constexpr un_scalar_t gigawatt_hours_per_cubic_meter() const
        {
            return convert_from_base(EnergyDensityUnit::GigawattHoursPerCubicMeter);
        }

        [[nodiscard]] static constexpr EnergyDensity from_gigawatt_hours_per_cubic_meter(const un_scalar_t value)
        {
            return EnergyDensity(value, EnergyDensityUnit::GigawattHoursPerCubicMeter);
        }


        [[nodiscard]] constexpr un_scalar_t terawatt_hours_per_cubic_meter() const
        {
            return convert_from_base(EnergyDensityUnit::TerawattHoursPerCubicMeter);
        }

        [[nodiscard]] static constexpr EnergyDensity from_terawatt_hours_per_cubic_meter(const un_scalar_t value)
        {
            return EnergyDensity(value, EnergyDensityUnit::TerawattHoursPerCubicMeter);
        }


        [[nodiscard]] constexpr un_scalar_t petawatt_hours_per_cubic_meter() const
        {
            return convert_from_base(EnergyDensityUnit::PetawattHoursPerCubicMeter);
        }

        [[nodiscard]] static constexpr EnergyDensity from_petawatt_hours_per_cubic_meter(const un_scalar_t value)
        {
            return EnergyDensity(value, EnergyDensityUnit::PetawattHoursPerCubicMeter);
        }


        [[nodiscard]] static constexpr EnergyDensity from_invalid()
        {
            return EnergyDensity(false);
        }
    private:
            
        [[nodiscard]] static constexpr un_scalar_t convert_to_base(un_scalar_t value, EnergyDensityUnit unit)
        {
            switch (unit)
            {

            case EnergyDensityUnit::JoulesPerCubicMeter:
                return value;

            case EnergyDensityUnit::KilojoulesPerCubicMeter:
                return (value * static_cast<un_scalar_t>(1e3));

            case EnergyDensityUnit::MegajoulesPerCubicMeter:
                return (value * static_cast<un_scalar_t>(1e6));

            case EnergyDensityUnit::GigajoulesPerCubicMeter:
                return (value * static_cast<un_scalar_t>(1e9));

            case EnergyDensityUnit::TerajoulesPerCubicMeter:
                return (value * static_cast<un_scalar_t>(1e12));

            case EnergyDensityUnit::PetajoulesPerCubicMeter:
                return (value * static_cast<un_scalar_t>(1e15));

            case EnergyDensityUnit::WattHoursPerCubicMeter:
                return value * static_cast<un_scalar_t>(3.6e+3);

            case EnergyDensityUnit::KilowattHoursPerCubicMeter:
                return (value * static_cast<un_scalar_t>(1e3)) * static_cast<un_scalar_t>(3.6e+3);

            case EnergyDensityUnit::MegawattHoursPerCubicMeter:
                return (value * static_cast<un_scalar_t>(1e6)) * static_cast<un_scalar_t>(3.6e+3);

            case EnergyDensityUnit::GigawattHoursPerCubicMeter:
                return (value * static_cast<un_scalar_t>(1e9)) * static_cast<un_scalar_t>(3.6e+3);

            case EnergyDensityUnit::TerawattHoursPerCubicMeter:
                return (value * static_cast<un_scalar_t>(1e12)) * static_cast<un_scalar_t>(3.6e+3);

            case EnergyDensityUnit::PetawattHoursPerCubicMeter:
                return (value * static_cast<un_scalar_t>(1e15)) * static_cast<un_scalar_t>(3.6e+3);

            }

            throw std::invalid_argument("Unknown EnergyDensity unit.");
        }

        [[nodiscard]] constexpr un_scalar_t convert_from_base(const EnergyDensityUnit unit) const
        {
            if(unit == value_unit_type_)
            {
                return value_;
            }
            
            create_base_value_if_needed();
            
            switch (unit)
            {

            case EnergyDensityUnit::JoulesPerCubicMeter:
                return base_value_;

            case EnergyDensityUnit::KilojoulesPerCubicMeter:
                return (base_value_) / static_cast<un_scalar_t>(1e3);

            case EnergyDensityUnit::MegajoulesPerCubicMeter:
                return (base_value_) / static_cast<un_scalar_t>(1e6);

            case EnergyDensityUnit::GigajoulesPerCubicMeter:
                return (base_value_) / static_cast<un_scalar_t>(1e9);

            case EnergyDensityUnit::TerajoulesPerCubicMeter:
                return (base_value_) / static_cast<un_scalar_t>(1e12);

            case EnergyDensityUnit::PetajoulesPerCubicMeter:
                return (base_value_) / static_cast<un_scalar_t>(1e15);

            case EnergyDensityUnit::WattHoursPerCubicMeter:
                return base_value_ / static_cast<un_scalar_t>(3.6e+3);

            case EnergyDensityUnit::KilowattHoursPerCubicMeter:
                return (base_value_ / static_cast<un_scalar_t>(3.6e+3)) / static_cast<un_scalar_t>(1e3);

            case EnergyDensityUnit::MegawattHoursPerCubicMeter:
                return (base_value_ / static_cast<un_scalar_t>(3.6e+3)) / static_cast<un_scalar_t>(1e6);

            case EnergyDensityUnit::GigawattHoursPerCubicMeter:
                return (base_value_ / static_cast<un_scalar_t>(3.6e+3)) / static_cast<un_scalar_t>(1e9);

            case EnergyDensityUnit::TerawattHoursPerCubicMeter:
                return (base_value_ / static_cast<un_scalar_t>(3.6e+3)) / static_cast<un_scalar_t>(1e12);

            case EnergyDensityUnit::PetawattHoursPerCubicMeter:
                return (base_value_ / static_cast<un_scalar_t>(3.6e+3)) / static_cast<un_scalar_t>(1e15);

            }

            throw std::invalid_argument("Unknown EnergyDensity unit.");
        }

        un_scalar_t value_;
        EnergyDensityUnit value_unit_type_;
        mutable un_scalar_t base_value_;
        mutable bool base_value_exists_ = false;
       
    };
}
