#pragma once

#include <cstdint>
#include <numbers>
#include <stdexcept>
#include "UnitsNetConfig.h"
#include "UnitsNetBase.h"

namespace unitsnet_cpp
{
    enum class ElectricAdmittanceUnit : std::uint8_t
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

    /// <summary>Electric admittance is a measure of how easily a circuit or device will allow a current to flow by the combined effect of conductance and susceptance in a circuit. It is defined as the inverse of impedance. The SI unit of admittance is the siemens (symbol S).</summary>
    class ElectricAdmittance : public UnitsNetBase
    {
    public:
        constexpr explicit ElectricAdmittance(
            const un_scalar_t value,
            const ElectricAdmittanceUnit unit = ElectricAdmittanceUnit::Siemens)
        {
            value_ = value;
            value_unit_type_ = unit;
        }
        
        [[nodiscard]] constexpr un_scalar_t stored_value() const noexcept override
        {
           return value_; 
        }
        
        [[nodiscard]] constexpr std::string_view quantity_name() const noexcept override
        {
           return "ElectricAdmittance"; 
        }
        
        [[nodiscard]] constexpr std::string_view unit_name() const noexcept override
        {
            switch (value_unit_type_)
            {

            case ElectricAdmittanceUnit::Siemens:
                return "Siemens";

            case ElectricAdmittanceUnit::Nanosiemens:
                return "Nanosiemens";

            case ElectricAdmittanceUnit::Microsiemens:
                return "Microsiemens";

            case ElectricAdmittanceUnit::Millisiemens:
                return "Millisiemens";

            case ElectricAdmittanceUnit::Kilosiemens:
                return "Kilosiemens";

            case ElectricAdmittanceUnit::Megasiemens:
                return "Megasiemens";

            case ElectricAdmittanceUnit::Gigasiemens:
                return "Gigasiemens";

            case ElectricAdmittanceUnit::Terasiemens:
                return "Terasiemens";

            case ElectricAdmittanceUnit::Mhos:
                return "Mhos";

            case ElectricAdmittanceUnit::Nanomhos:
                return "Nanomhos";

            case ElectricAdmittanceUnit::Micromhos:
                return "Micromhos";

            case ElectricAdmittanceUnit::Millimhos:
                return "Millimhos";

            case ElectricAdmittanceUnit::Kilomhos:
                return "Kilomhos";

            case ElectricAdmittanceUnit::Megamhos:
                return "Megamhos";

            case ElectricAdmittanceUnit::Gigamhos:
                return "Gigamhos";

            case ElectricAdmittanceUnit::Teramhos:
                return "Teramhos";

            }
            
            return {};
        }
                
        [[nodiscard]] constexpr un_scalar_t base_value() const noexcept
        {
            return convert_to_base(value_, value_unit_type_);    
        }

        [[nodiscard]] constexpr un_scalar_t value(const ElectricAdmittanceUnit unit) const
        {
            return convert_from_base(unit);
        }

        [[nodiscard]] constexpr ElectricAdmittance operator+(const ElectricAdmittance& other) const noexcept
        {
            return ElectricAdmittance(base_value() + other.base_value());
        }

        [[nodiscard]] constexpr ElectricAdmittance operator-(const ElectricAdmittance& other)const noexcept
        {
            return ElectricAdmittance(base_value() - other.base_value());
        }

        [[nodiscard]] constexpr ElectricAdmittance operator*(const un_scalar_t scalar) const noexcept
        {
            return ElectricAdmittance(base_value() * scalar);
        }

        [[nodiscard]] constexpr ElectricAdmittance operator/(const un_scalar_t scalar) const noexcept
        {
            return ElectricAdmittance(base_value() / scalar);
        }

        [[nodiscard]] constexpr bool operator==(const ElectricAdmittance& other) const noexcept
        {
            return base_value() == other.base_value();
        }

        [[nodiscard]] constexpr bool operator<(const ElectricAdmittance& other) const noexcept
        {
            return base_value() < other.base_value();
        }
        
        [[nodiscard]] constexpr bool operator>(const ElectricAdmittance& other) const noexcept
        {
            return base_value() > other.base_value();
        }

        [[nodiscard]] constexpr un_scalar_t siemens() const
        {
            return convert_from_base(ElectricAdmittanceUnit::Siemens);
        }

        [[nodiscard]] static constexpr ElectricAdmittance from_siemens(const un_scalar_t value)
        {
            return ElectricAdmittance(value, ElectricAdmittanceUnit::Siemens);
        }

        [[nodiscard]] constexpr un_scalar_t nanosiemens() const
        {
            return convert_from_base(ElectricAdmittanceUnit::Nanosiemens);
        }

        [[nodiscard]] static constexpr ElectricAdmittance from_nanosiemens(const un_scalar_t value)
        {
            return ElectricAdmittance(value, ElectricAdmittanceUnit::Nanosiemens);
        }

        [[nodiscard]] constexpr un_scalar_t microsiemens() const
        {
            return convert_from_base(ElectricAdmittanceUnit::Microsiemens);
        }

        [[nodiscard]] static constexpr ElectricAdmittance from_microsiemens(const un_scalar_t value)
        {
            return ElectricAdmittance(value, ElectricAdmittanceUnit::Microsiemens);
        }

        [[nodiscard]] constexpr un_scalar_t millisiemens() const
        {
            return convert_from_base(ElectricAdmittanceUnit::Millisiemens);
        }

        [[nodiscard]] static constexpr ElectricAdmittance from_millisiemens(const un_scalar_t value)
        {
            return ElectricAdmittance(value, ElectricAdmittanceUnit::Millisiemens);
        }

        [[nodiscard]] constexpr un_scalar_t kilosiemens() const
        {
            return convert_from_base(ElectricAdmittanceUnit::Kilosiemens);
        }

        [[nodiscard]] static constexpr ElectricAdmittance from_kilosiemens(const un_scalar_t value)
        {
            return ElectricAdmittance(value, ElectricAdmittanceUnit::Kilosiemens);
        }

        [[nodiscard]] constexpr un_scalar_t megasiemens() const
        {
            return convert_from_base(ElectricAdmittanceUnit::Megasiemens);
        }

        [[nodiscard]] static constexpr ElectricAdmittance from_megasiemens(const un_scalar_t value)
        {
            return ElectricAdmittance(value, ElectricAdmittanceUnit::Megasiemens);
        }

        [[nodiscard]] constexpr un_scalar_t gigasiemens() const
        {
            return convert_from_base(ElectricAdmittanceUnit::Gigasiemens);
        }

        [[nodiscard]] static constexpr ElectricAdmittance from_gigasiemens(const un_scalar_t value)
        {
            return ElectricAdmittance(value, ElectricAdmittanceUnit::Gigasiemens);
        }

        [[nodiscard]] constexpr un_scalar_t terasiemens() const
        {
            return convert_from_base(ElectricAdmittanceUnit::Terasiemens);
        }

        [[nodiscard]] static constexpr ElectricAdmittance from_terasiemens(const un_scalar_t value)
        {
            return ElectricAdmittance(value, ElectricAdmittanceUnit::Terasiemens);
        }

        [[nodiscard]] constexpr un_scalar_t mhos() const
        {
            return convert_from_base(ElectricAdmittanceUnit::Mhos);
        }

        [[nodiscard]] static constexpr ElectricAdmittance from_mhos(const un_scalar_t value)
        {
            return ElectricAdmittance(value, ElectricAdmittanceUnit::Mhos);
        }

        [[nodiscard]] constexpr un_scalar_t nanomhos() const
        {
            return convert_from_base(ElectricAdmittanceUnit::Nanomhos);
        }

        [[nodiscard]] static constexpr ElectricAdmittance from_nanomhos(const un_scalar_t value)
        {
            return ElectricAdmittance(value, ElectricAdmittanceUnit::Nanomhos);
        }

        [[nodiscard]] constexpr un_scalar_t micromhos() const
        {
            return convert_from_base(ElectricAdmittanceUnit::Micromhos);
        }

        [[nodiscard]] static constexpr ElectricAdmittance from_micromhos(const un_scalar_t value)
        {
            return ElectricAdmittance(value, ElectricAdmittanceUnit::Micromhos);
        }

        [[nodiscard]] constexpr un_scalar_t millimhos() const
        {
            return convert_from_base(ElectricAdmittanceUnit::Millimhos);
        }

        [[nodiscard]] static constexpr ElectricAdmittance from_millimhos(const un_scalar_t value)
        {
            return ElectricAdmittance(value, ElectricAdmittanceUnit::Millimhos);
        }

        [[nodiscard]] constexpr un_scalar_t kilomhos() const
        {
            return convert_from_base(ElectricAdmittanceUnit::Kilomhos);
        }

        [[nodiscard]] static constexpr ElectricAdmittance from_kilomhos(const un_scalar_t value)
        {
            return ElectricAdmittance(value, ElectricAdmittanceUnit::Kilomhos);
        }

        [[nodiscard]] constexpr un_scalar_t megamhos() const
        {
            return convert_from_base(ElectricAdmittanceUnit::Megamhos);
        }

        [[nodiscard]] static constexpr ElectricAdmittance from_megamhos(const un_scalar_t value)
        {
            return ElectricAdmittance(value, ElectricAdmittanceUnit::Megamhos);
        }

        [[nodiscard]] constexpr un_scalar_t gigamhos() const
        {
            return convert_from_base(ElectricAdmittanceUnit::Gigamhos);
        }

        [[nodiscard]] static constexpr ElectricAdmittance from_gigamhos(const un_scalar_t value)
        {
            return ElectricAdmittance(value, ElectricAdmittanceUnit::Gigamhos);
        }

        [[nodiscard]] constexpr un_scalar_t teramhos() const
        {
            return convert_from_base(ElectricAdmittanceUnit::Teramhos);
        }

        [[nodiscard]] static constexpr ElectricAdmittance from_teramhos(const un_scalar_t value)
        {
            return ElectricAdmittance(value, ElectricAdmittanceUnit::Teramhos);
        }

        [[nodiscard]] static constexpr ElectricAdmittance from_invalid()
        {
            return ElectricAdmittance(false);
        }
    private:
            
        [[nodiscard]] static constexpr un_scalar_t convert_to_base(un_scalar_t value, ElectricAdmittanceUnit unit)
        {
            switch (unit)
            {

            case ElectricAdmittanceUnit::Siemens:
                return value;

            case ElectricAdmittanceUnit::Nanosiemens:
                return (value * static_cast<un_scalar_t>(1e-9));

            case ElectricAdmittanceUnit::Microsiemens:
                return (value * static_cast<un_scalar_t>(1e-6));

            case ElectricAdmittanceUnit::Millisiemens:
                return (value * static_cast<un_scalar_t>(1e-3));

            case ElectricAdmittanceUnit::Kilosiemens:
                return (value * static_cast<un_scalar_t>(1e3));

            case ElectricAdmittanceUnit::Megasiemens:
                return (value * static_cast<un_scalar_t>(1e6));

            case ElectricAdmittanceUnit::Gigasiemens:
                return (value * static_cast<un_scalar_t>(1e9));

            case ElectricAdmittanceUnit::Terasiemens:
                return (value * static_cast<un_scalar_t>(1e12));

            case ElectricAdmittanceUnit::Mhos:
                return value;

            case ElectricAdmittanceUnit::Nanomhos:
                return (value * static_cast<un_scalar_t>(1e-9));

            case ElectricAdmittanceUnit::Micromhos:
                return (value * static_cast<un_scalar_t>(1e-6));

            case ElectricAdmittanceUnit::Millimhos:
                return (value * static_cast<un_scalar_t>(1e-3));

            case ElectricAdmittanceUnit::Kilomhos:
                return (value * static_cast<un_scalar_t>(1e3));

            case ElectricAdmittanceUnit::Megamhos:
                return (value * static_cast<un_scalar_t>(1e6));

            case ElectricAdmittanceUnit::Gigamhos:
                return (value * static_cast<un_scalar_t>(1e9));

            case ElectricAdmittanceUnit::Teramhos:
                return (value * static_cast<un_scalar_t>(1e12));

            }

            throw std::invalid_argument("Unknown ElectricAdmittance unit.");
        }

        [[nodiscard]] constexpr un_scalar_t convert_from_base(const ElectricAdmittanceUnit unit) const
        {
            if(unit == value_unit_type_)
            {
                return value_;
            }
            
            auto base_value = convert_to_base(value_, value_unit_type_);
            
            switch (unit)
            {

            case ElectricAdmittanceUnit::Siemens:
                return base_value;

            case ElectricAdmittanceUnit::Nanosiemens:
                return (base_value) / static_cast<un_scalar_t>(1e-9);

            case ElectricAdmittanceUnit::Microsiemens:
                return (base_value) / static_cast<un_scalar_t>(1e-6);

            case ElectricAdmittanceUnit::Millisiemens:
                return (base_value) / static_cast<un_scalar_t>(1e-3);

            case ElectricAdmittanceUnit::Kilosiemens:
                return (base_value) / static_cast<un_scalar_t>(1e3);

            case ElectricAdmittanceUnit::Megasiemens:
                return (base_value) / static_cast<un_scalar_t>(1e6);

            case ElectricAdmittanceUnit::Gigasiemens:
                return (base_value) / static_cast<un_scalar_t>(1e9);

            case ElectricAdmittanceUnit::Terasiemens:
                return (base_value) / static_cast<un_scalar_t>(1e12);

            case ElectricAdmittanceUnit::Mhos:
                return base_value;

            case ElectricAdmittanceUnit::Nanomhos:
                return (base_value) / static_cast<un_scalar_t>(1e-9);

            case ElectricAdmittanceUnit::Micromhos:
                return (base_value) / static_cast<un_scalar_t>(1e-6);

            case ElectricAdmittanceUnit::Millimhos:
                return (base_value) / static_cast<un_scalar_t>(1e-3);

            case ElectricAdmittanceUnit::Kilomhos:
                return (base_value) / static_cast<un_scalar_t>(1e3);

            case ElectricAdmittanceUnit::Megamhos:
                return (base_value) / static_cast<un_scalar_t>(1e6);

            case ElectricAdmittanceUnit::Gigamhos:
                return (base_value) / static_cast<un_scalar_t>(1e9);

            case ElectricAdmittanceUnit::Teramhos:
                return (base_value) / static_cast<un_scalar_t>(1e12);

            }

            throw std::invalid_argument("Unknown ElectricAdmittance unit.");
        }

        un_scalar_t value_;
        ElectricAdmittanceUnit value_unit_type_;       
    };
}
