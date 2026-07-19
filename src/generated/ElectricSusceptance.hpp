#pragma once

#include <cstdint>
#include <numbers>
#include <stdexcept>
#include "UnitsNetConfig.h"
#include "UnitsNetBase.h"

namespace unitsnet_cpp
{
    enum class ElectricSusceptanceUnit : std::uint8_t
    {
        Siemens,
        Nanosiemens,
        Microsiemens,
        Millisiemens,
        Kilosiemens,
        Megasiemens,
        Gigasiemens,
        Terasiemens,
        Mhos,
        Nanomhos,
        Micromhos,
        Millimhos,
        Kilomhos,
        Megamhos,
        Gigamhos,
        Teramhos,
    };

    /// <summary>Electrical susceptance is the imaginary part of admittance, where the real part is conductance.</summary>
    class ElectricSusceptance : public UnitsNetBase
    {
    public:
        constexpr explicit ElectricSusceptance(
            const un_scalar_t value,
            const ElectricSusceptanceUnit unit = ElectricSusceptanceUnit::Siemens)
        {
            value_ = value;
            value_unit_type_ = unit;
            if(unit == ElectricSusceptanceUnit::Siemens)
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

        [[nodiscard]] constexpr un_scalar_t value(const ElectricSusceptanceUnit unit) const
        {
            return convert_from_base(unit);
        }

        [[nodiscard]] constexpr ElectricSusceptance operator+(const ElectricSusceptance& other) const noexcept
        {
            return ElectricSusceptance(base_value() + other.base_value());
        }

        [[nodiscard]] constexpr ElectricSusceptance operator-(const ElectricSusceptance& other)const noexcept
        {
            return ElectricSusceptance(base_value() - other.base_value());
        }

        [[nodiscard]] constexpr ElectricSusceptance operator*(const un_scalar_t scalar) const noexcept
        {
            return ElectricSusceptance(base_value() * scalar);
        }

        [[nodiscard]] constexpr ElectricSusceptance operator/(const un_scalar_t scalar) const noexcept
        {
            return ElectricSusceptance(base_value() / scalar);
        }

        [[nodiscard]] constexpr bool operator==(const ElectricSusceptance& other) const noexcept
        {
            return base_value() == other.base_value();
        }

        [[nodiscard]] constexpr bool operator<(const ElectricSusceptance& other) const noexcept
        {
            return base_value() < other.base_value();
        }
        
        [[nodiscard]] constexpr bool operator>(const ElectricSusceptance& other) const noexcept
        {
            return base_value() > other.base_value();
        }


        [[nodiscard]] constexpr un_scalar_t siemens() const
        {
            return convert_from_base(ElectricSusceptanceUnit::Siemens);
        }

        [[nodiscard]] static constexpr ElectricSusceptance from_siemens(const un_scalar_t value)
        {
            return ElectricSusceptance(value, ElectricSusceptanceUnit::Siemens);
        }


        [[nodiscard]] constexpr un_scalar_t nanosiemens() const
        {
            return convert_from_base(ElectricSusceptanceUnit::Nanosiemens);
        }

        [[nodiscard]] static constexpr ElectricSusceptance from_nanosiemens(const un_scalar_t value)
        {
            return ElectricSusceptance(value, ElectricSusceptanceUnit::Nanosiemens);
        }


        [[nodiscard]] constexpr un_scalar_t microsiemens() const
        {
            return convert_from_base(ElectricSusceptanceUnit::Microsiemens);
        }

        [[nodiscard]] static constexpr ElectricSusceptance from_microsiemens(const un_scalar_t value)
        {
            return ElectricSusceptance(value, ElectricSusceptanceUnit::Microsiemens);
        }


        [[nodiscard]] constexpr un_scalar_t millisiemens() const
        {
            return convert_from_base(ElectricSusceptanceUnit::Millisiemens);
        }

        [[nodiscard]] static constexpr ElectricSusceptance from_millisiemens(const un_scalar_t value)
        {
            return ElectricSusceptance(value, ElectricSusceptanceUnit::Millisiemens);
        }


        [[nodiscard]] constexpr un_scalar_t kilosiemens() const
        {
            return convert_from_base(ElectricSusceptanceUnit::Kilosiemens);
        }

        [[nodiscard]] static constexpr ElectricSusceptance from_kilosiemens(const un_scalar_t value)
        {
            return ElectricSusceptance(value, ElectricSusceptanceUnit::Kilosiemens);
        }


        [[nodiscard]] constexpr un_scalar_t megasiemens() const
        {
            return convert_from_base(ElectricSusceptanceUnit::Megasiemens);
        }

        [[nodiscard]] static constexpr ElectricSusceptance from_megasiemens(const un_scalar_t value)
        {
            return ElectricSusceptance(value, ElectricSusceptanceUnit::Megasiemens);
        }


        [[nodiscard]] constexpr un_scalar_t gigasiemens() const
        {
            return convert_from_base(ElectricSusceptanceUnit::Gigasiemens);
        }

        [[nodiscard]] static constexpr ElectricSusceptance from_gigasiemens(const un_scalar_t value)
        {
            return ElectricSusceptance(value, ElectricSusceptanceUnit::Gigasiemens);
        }


        [[nodiscard]] constexpr un_scalar_t terasiemens() const
        {
            return convert_from_base(ElectricSusceptanceUnit::Terasiemens);
        }

        [[nodiscard]] static constexpr ElectricSusceptance from_terasiemens(const un_scalar_t value)
        {
            return ElectricSusceptance(value, ElectricSusceptanceUnit::Terasiemens);
        }


        [[nodiscard]] constexpr un_scalar_t mhos() const
        {
            return convert_from_base(ElectricSusceptanceUnit::Mhos);
        }

        [[nodiscard]] static constexpr ElectricSusceptance from_mhos(const un_scalar_t value)
        {
            return ElectricSusceptance(value, ElectricSusceptanceUnit::Mhos);
        }


        [[nodiscard]] constexpr un_scalar_t nanomhos() const
        {
            return convert_from_base(ElectricSusceptanceUnit::Nanomhos);
        }

        [[nodiscard]] static constexpr ElectricSusceptance from_nanomhos(const un_scalar_t value)
        {
            return ElectricSusceptance(value, ElectricSusceptanceUnit::Nanomhos);
        }


        [[nodiscard]] constexpr un_scalar_t micromhos() const
        {
            return convert_from_base(ElectricSusceptanceUnit::Micromhos);
        }

        [[nodiscard]] static constexpr ElectricSusceptance from_micromhos(const un_scalar_t value)
        {
            return ElectricSusceptance(value, ElectricSusceptanceUnit::Micromhos);
        }


        [[nodiscard]] constexpr un_scalar_t millimhos() const
        {
            return convert_from_base(ElectricSusceptanceUnit::Millimhos);
        }

        [[nodiscard]] static constexpr ElectricSusceptance from_millimhos(const un_scalar_t value)
        {
            return ElectricSusceptance(value, ElectricSusceptanceUnit::Millimhos);
        }


        [[nodiscard]] constexpr un_scalar_t kilomhos() const
        {
            return convert_from_base(ElectricSusceptanceUnit::Kilomhos);
        }

        [[nodiscard]] static constexpr ElectricSusceptance from_kilomhos(const un_scalar_t value)
        {
            return ElectricSusceptance(value, ElectricSusceptanceUnit::Kilomhos);
        }


        [[nodiscard]] constexpr un_scalar_t megamhos() const
        {
            return convert_from_base(ElectricSusceptanceUnit::Megamhos);
        }

        [[nodiscard]] static constexpr ElectricSusceptance from_megamhos(const un_scalar_t value)
        {
            return ElectricSusceptance(value, ElectricSusceptanceUnit::Megamhos);
        }


        [[nodiscard]] constexpr un_scalar_t gigamhos() const
        {
            return convert_from_base(ElectricSusceptanceUnit::Gigamhos);
        }

        [[nodiscard]] static constexpr ElectricSusceptance from_gigamhos(const un_scalar_t value)
        {
            return ElectricSusceptance(value, ElectricSusceptanceUnit::Gigamhos);
        }


        [[nodiscard]] constexpr un_scalar_t teramhos() const
        {
            return convert_from_base(ElectricSusceptanceUnit::Teramhos);
        }

        [[nodiscard]] static constexpr ElectricSusceptance from_teramhos(const un_scalar_t value)
        {
            return ElectricSusceptance(value, ElectricSusceptanceUnit::Teramhos);
        }


        [[nodiscard]] static constexpr ElectricSusceptance from_invalid()
        {
            return ElectricSusceptance(false);
        }
    private:
            
        [[nodiscard]] static constexpr un_scalar_t convert_to_base(un_scalar_t value, ElectricSusceptanceUnit unit)
        {
            switch (unit)
            {

            case ElectricSusceptanceUnit::Siemens:
                return value;

            case ElectricSusceptanceUnit::Nanosiemens:
                return (value * static_cast<un_scalar_t>(1e-9));

            case ElectricSusceptanceUnit::Microsiemens:
                return (value * static_cast<un_scalar_t>(1e-6));

            case ElectricSusceptanceUnit::Millisiemens:
                return (value * static_cast<un_scalar_t>(1e-3));

            case ElectricSusceptanceUnit::Kilosiemens:
                return (value * static_cast<un_scalar_t>(1e3));

            case ElectricSusceptanceUnit::Megasiemens:
                return (value * static_cast<un_scalar_t>(1e6));

            case ElectricSusceptanceUnit::Gigasiemens:
                return (value * static_cast<un_scalar_t>(1e9));

            case ElectricSusceptanceUnit::Terasiemens:
                return (value * static_cast<un_scalar_t>(1e12));

            case ElectricSusceptanceUnit::Mhos:
                return value;

            case ElectricSusceptanceUnit::Nanomhos:
                return (value * static_cast<un_scalar_t>(1e-9));

            case ElectricSusceptanceUnit::Micromhos:
                return (value * static_cast<un_scalar_t>(1e-6));

            case ElectricSusceptanceUnit::Millimhos:
                return (value * static_cast<un_scalar_t>(1e-3));

            case ElectricSusceptanceUnit::Kilomhos:
                return (value * static_cast<un_scalar_t>(1e3));

            case ElectricSusceptanceUnit::Megamhos:
                return (value * static_cast<un_scalar_t>(1e6));

            case ElectricSusceptanceUnit::Gigamhos:
                return (value * static_cast<un_scalar_t>(1e9));

            case ElectricSusceptanceUnit::Teramhos:
                return (value * static_cast<un_scalar_t>(1e12));

            }

            throw std::invalid_argument("Unknown ElectricSusceptance unit.");
        }

        [[nodiscard]] constexpr un_scalar_t convert_from_base(const ElectricSusceptanceUnit unit) const
        {
            if(unit == value_unit_type_)
            {
                return value_;
            }
            
            create_base_value_if_needed();
            
            switch (unit)
            {

            case ElectricSusceptanceUnit::Siemens:
                return base_value_;

            case ElectricSusceptanceUnit::Nanosiemens:
                return (base_value_) / static_cast<un_scalar_t>(1e-9);

            case ElectricSusceptanceUnit::Microsiemens:
                return (base_value_) / static_cast<un_scalar_t>(1e-6);

            case ElectricSusceptanceUnit::Millisiemens:
                return (base_value_) / static_cast<un_scalar_t>(1e-3);

            case ElectricSusceptanceUnit::Kilosiemens:
                return (base_value_) / static_cast<un_scalar_t>(1e3);

            case ElectricSusceptanceUnit::Megasiemens:
                return (base_value_) / static_cast<un_scalar_t>(1e6);

            case ElectricSusceptanceUnit::Gigasiemens:
                return (base_value_) / static_cast<un_scalar_t>(1e9);

            case ElectricSusceptanceUnit::Terasiemens:
                return (base_value_) / static_cast<un_scalar_t>(1e12);

            case ElectricSusceptanceUnit::Mhos:
                return base_value_;

            case ElectricSusceptanceUnit::Nanomhos:
                return (base_value_) / static_cast<un_scalar_t>(1e-9);

            case ElectricSusceptanceUnit::Micromhos:
                return (base_value_) / static_cast<un_scalar_t>(1e-6);

            case ElectricSusceptanceUnit::Millimhos:
                return (base_value_) / static_cast<un_scalar_t>(1e-3);

            case ElectricSusceptanceUnit::Kilomhos:
                return (base_value_) / static_cast<un_scalar_t>(1e3);

            case ElectricSusceptanceUnit::Megamhos:
                return (base_value_) / static_cast<un_scalar_t>(1e6);

            case ElectricSusceptanceUnit::Gigamhos:
                return (base_value_) / static_cast<un_scalar_t>(1e9);

            case ElectricSusceptanceUnit::Teramhos:
                return (base_value_) / static_cast<un_scalar_t>(1e12);

            }

            throw std::invalid_argument("Unknown ElectricSusceptance unit.");
        }

        un_scalar_t value_;
        ElectricSusceptanceUnit value_unit_type_;
        mutable un_scalar_t base_value_;
        mutable bool base_value_exists_ = false;
       
    };
}
