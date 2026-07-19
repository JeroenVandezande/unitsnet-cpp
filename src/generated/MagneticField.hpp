#pragma once

#include <cstdint>
#include <numbers>
#include <stdexcept>
#include "UnitsNetConfig.h"
#include "UnitsNetBase.h"

namespace unitsnet_cpp
{
    enum class MagneticFieldUnit : std::uint8_t
    {
        Teslas,
        Nanoteslas,
        Microteslas,
        Milliteslas,
        Gausses,
        Milligausses,
    };

    /// <summary>A magnetic field is a force field that is created by moving electric charges (electric currents) and magnetic dipoles, and exerts a force on other nearby moving charges and magnetic dipoles.</summary>
    class MagneticField : public UnitsNetBase
    {
    public:
        constexpr explicit MagneticField(
            const un_scalar_t value,
            const MagneticFieldUnit unit = MagneticFieldUnit::Teslas)
        {
            value_ = value;
            value_unit_type_ = unit;
            if(unit == MagneticFieldUnit::Teslas)
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
            if(!base_value_exists_)
            {
                base_value_ = convert_to_base(value_, value_unit_type_);
                base_value_exists_ = true;
            }
        }
                
        [[nodiscard]] constexpr un_scalar_t base_value() const noexcept
        {
            create_base_value_if_needed();    
            return base_value_;    
        }

        [[nodiscard]] constexpr un_scalar_t value(const MagneticFieldUnit unit) const
        {
            return convert_from_base(unit);
        }

        [[nodiscard]] constexpr MagneticField operator+(const MagneticField& other) const noexcept
        {
            return MagneticField(base_value() + other.base_value());
        }

        [[nodiscard]] constexpr MagneticField operator-(const MagneticField& other)const noexcept
        {
            return MagneticField(base_value() - other.base_value());
        }

        [[nodiscard]] constexpr MagneticField operator*(const un_scalar_t scalar) const noexcept
        {
            return MagneticField(base_value() * scalar);
        }

        [[nodiscard]] constexpr MagneticField operator/(const un_scalar_t scalar) const noexcept
        {
            return MagneticField(base_value() / scalar);
        }

        [[nodiscard]] constexpr bool operator==(const MagneticField& other) const noexcept
        {
            return base_value() == other.base_value();
        }

        [[nodiscard]] constexpr bool operator<(const MagneticField& other) const noexcept
        {
            return base_value() < other.base_value();
        }
        
        [[nodiscard]] constexpr bool operator>(const MagneticField& other) const noexcept
        {
            return base_value() > other.base_value();
        }


        [[nodiscard]] constexpr un_scalar_t teslas() const
        {
            return convert_from_base(MagneticFieldUnit::Teslas);
        }

        [[nodiscard]] static constexpr MagneticField from_teslas(const un_scalar_t value)
        {
            return MagneticField(value, MagneticFieldUnit::Teslas);
        }


        [[nodiscard]] constexpr un_scalar_t nanoteslas() const
        {
            return convert_from_base(MagneticFieldUnit::Nanoteslas);
        }

        [[nodiscard]] static constexpr MagneticField from_nanoteslas(const un_scalar_t value)
        {
            return MagneticField(value, MagneticFieldUnit::Nanoteslas);
        }


        [[nodiscard]] constexpr un_scalar_t microteslas() const
        {
            return convert_from_base(MagneticFieldUnit::Microteslas);
        }

        [[nodiscard]] static constexpr MagneticField from_microteslas(const un_scalar_t value)
        {
            return MagneticField(value, MagneticFieldUnit::Microteslas);
        }


        [[nodiscard]] constexpr un_scalar_t milliteslas() const
        {
            return convert_from_base(MagneticFieldUnit::Milliteslas);
        }

        [[nodiscard]] static constexpr MagneticField from_milliteslas(const un_scalar_t value)
        {
            return MagneticField(value, MagneticFieldUnit::Milliteslas);
        }


        [[nodiscard]] constexpr un_scalar_t gausses() const
        {
            return convert_from_base(MagneticFieldUnit::Gausses);
        }

        [[nodiscard]] static constexpr MagneticField from_gausses(const un_scalar_t value)
        {
            return MagneticField(value, MagneticFieldUnit::Gausses);
        }


        [[nodiscard]] constexpr un_scalar_t milligausses() const
        {
            return convert_from_base(MagneticFieldUnit::Milligausses);
        }

        [[nodiscard]] static constexpr MagneticField from_milligausses(const un_scalar_t value)
        {
            return MagneticField(value, MagneticFieldUnit::Milligausses);
        }


        [[nodiscard]] static constexpr MagneticField from_invalid()
        {
            return MagneticField(false);
        }
    private:
            
        [[nodiscard]] static constexpr un_scalar_t convert_to_base(un_scalar_t value, MagneticFieldUnit unit)
        {
            switch (unit)
            {

            case MagneticFieldUnit::Teslas:
                return value;

            case MagneticFieldUnit::Nanoteslas:
                return (value * static_cast<un_scalar_t>(1e-9));

            case MagneticFieldUnit::Microteslas:
                return (value * static_cast<un_scalar_t>(1e-6));

            case MagneticFieldUnit::Milliteslas:
                return (value * static_cast<un_scalar_t>(1e-3));

            case MagneticFieldUnit::Gausses:
                return value / static_cast<un_scalar_t>(1e4);

            case MagneticFieldUnit::Milligausses:
                return (value * static_cast<un_scalar_t>(1e-3)) / static_cast<un_scalar_t>(1e4);

            }

            throw std::invalid_argument("Unknown MagneticField unit.");
        }

        [[nodiscard]] constexpr un_scalar_t convert_from_base(const MagneticFieldUnit unit) const
        {
            if(unit == value_unit_type_)
            {
                return value_;
            }
            
            create_base_value_if_needed();
            
            switch (unit)
            {

            case MagneticFieldUnit::Teslas:
                return base_value_;

            case MagneticFieldUnit::Nanoteslas:
                return (base_value_) / static_cast<un_scalar_t>(1e-9);

            case MagneticFieldUnit::Microteslas:
                return (base_value_) / static_cast<un_scalar_t>(1e-6);

            case MagneticFieldUnit::Milliteslas:
                return (base_value_) / static_cast<un_scalar_t>(1e-3);

            case MagneticFieldUnit::Gausses:
                return base_value_ * static_cast<un_scalar_t>(1e4);

            case MagneticFieldUnit::Milligausses:
                return (base_value_ * static_cast<un_scalar_t>(1e4)) / static_cast<un_scalar_t>(1e-3);

            }

            throw std::invalid_argument("Unknown MagneticField unit.");
        }

        un_scalar_t value_;
        MagneticFieldUnit value_unit_type_;
        mutable un_scalar_t base_value_;
        mutable bool base_value_exists_ = false;
       
    };
}
