#pragma once

#include <cstdint>
#include <numbers>
#include <stdexcept>
#include "UnitsNetConfig.h"
#include "UnitsNetBase.h"

namespace unitsnet_cpp
{
    enum class ElectricChargeUnit : std::uint8_t
    {
        Coulombs,
        Picocoulombs,
        Nanocoulombs,
        Microcoulombs,
        Millicoulombs,
        Kilocoulombs,
        Megacoulombs,
        AmpereHours,
        MilliampereHours,
        KiloampereHours,
        MegaampereHours,
    };

    /// <summary>Electric charge is the physical property of matter that causes it to experience a force when placed in an electromagnetic field.</summary>
    class ElectricCharge : public UnitsNetBase
    {
    public:
        constexpr explicit ElectricCharge(
            const un_scalar_t value,
            const ElectricChargeUnit unit = ElectricChargeUnit::Coulombs)
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
           return "ElectricCharge"; 
        }
        
        [[nodiscard]] constexpr std::string_view unit_name() const noexcept override
        {
            switch (value_unit_type_)
            {

            case ElectricChargeUnit::Coulombs:
                return "Coulombs";

            case ElectricChargeUnit::Picocoulombs:
                return "Picocoulombs";

            case ElectricChargeUnit::Nanocoulombs:
                return "Nanocoulombs";

            case ElectricChargeUnit::Microcoulombs:
                return "Microcoulombs";

            case ElectricChargeUnit::Millicoulombs:
                return "Millicoulombs";

            case ElectricChargeUnit::Kilocoulombs:
                return "Kilocoulombs";

            case ElectricChargeUnit::Megacoulombs:
                return "Megacoulombs";

            case ElectricChargeUnit::AmpereHours:
                return "AmpereHours";

            case ElectricChargeUnit::MilliampereHours:
                return "MilliampereHours";

            case ElectricChargeUnit::KiloampereHours:
                return "KiloampereHours";

            case ElectricChargeUnit::MegaampereHours:
                return "MegaampereHours";

            }
            
            return {};
        }
                
        [[nodiscard]] constexpr un_scalar_t base_value() const noexcept
        {
            return convert_to_base(value_, value_unit_type_);    
        }

        [[nodiscard]] constexpr un_scalar_t value(const ElectricChargeUnit unit) const
        {
            return convert_from_base(unit);
        }

        [[nodiscard]] constexpr ElectricCharge operator+(const ElectricCharge& other) const noexcept
        {
            return ElectricCharge(base_value() + other.base_value());
        }

        [[nodiscard]] constexpr ElectricCharge operator-(const ElectricCharge& other)const noexcept
        {
            return ElectricCharge(base_value() - other.base_value());
        }

        [[nodiscard]] constexpr ElectricCharge operator*(const un_scalar_t scalar) const noexcept
        {
            return ElectricCharge(base_value() * scalar);
        }

        [[nodiscard]] constexpr ElectricCharge operator/(const un_scalar_t scalar) const noexcept
        {
            return ElectricCharge(base_value() / scalar);
        }

        [[nodiscard]] constexpr bool operator==(const ElectricCharge& other) const noexcept
        {
            return base_value() == other.base_value();
        }

        [[nodiscard]] constexpr bool operator<(const ElectricCharge& other) const noexcept
        {
            return base_value() < other.base_value();
        }
        
        [[nodiscard]] constexpr bool operator>(const ElectricCharge& other) const noexcept
        {
            return base_value() > other.base_value();
        }

        [[nodiscard]] constexpr un_scalar_t coulombs() const
        {
            return convert_from_base(ElectricChargeUnit::Coulombs);
        }

        [[nodiscard]] static constexpr ElectricCharge from_coulombs(const un_scalar_t value)
        {
            return ElectricCharge(value, ElectricChargeUnit::Coulombs);
        }

        [[nodiscard]] constexpr un_scalar_t picocoulombs() const
        {
            return convert_from_base(ElectricChargeUnit::Picocoulombs);
        }

        [[nodiscard]] static constexpr ElectricCharge from_picocoulombs(const un_scalar_t value)
        {
            return ElectricCharge(value, ElectricChargeUnit::Picocoulombs);
        }

        [[nodiscard]] constexpr un_scalar_t nanocoulombs() const
        {
            return convert_from_base(ElectricChargeUnit::Nanocoulombs);
        }

        [[nodiscard]] static constexpr ElectricCharge from_nanocoulombs(const un_scalar_t value)
        {
            return ElectricCharge(value, ElectricChargeUnit::Nanocoulombs);
        }

        [[nodiscard]] constexpr un_scalar_t microcoulombs() const
        {
            return convert_from_base(ElectricChargeUnit::Microcoulombs);
        }

        [[nodiscard]] static constexpr ElectricCharge from_microcoulombs(const un_scalar_t value)
        {
            return ElectricCharge(value, ElectricChargeUnit::Microcoulombs);
        }

        [[nodiscard]] constexpr un_scalar_t millicoulombs() const
        {
            return convert_from_base(ElectricChargeUnit::Millicoulombs);
        }

        [[nodiscard]] static constexpr ElectricCharge from_millicoulombs(const un_scalar_t value)
        {
            return ElectricCharge(value, ElectricChargeUnit::Millicoulombs);
        }

        [[nodiscard]] constexpr un_scalar_t kilocoulombs() const
        {
            return convert_from_base(ElectricChargeUnit::Kilocoulombs);
        }

        [[nodiscard]] static constexpr ElectricCharge from_kilocoulombs(const un_scalar_t value)
        {
            return ElectricCharge(value, ElectricChargeUnit::Kilocoulombs);
        }

        [[nodiscard]] constexpr un_scalar_t megacoulombs() const
        {
            return convert_from_base(ElectricChargeUnit::Megacoulombs);
        }

        [[nodiscard]] static constexpr ElectricCharge from_megacoulombs(const un_scalar_t value)
        {
            return ElectricCharge(value, ElectricChargeUnit::Megacoulombs);
        }

        [[nodiscard]] constexpr un_scalar_t ampere_hours() const
        {
            return convert_from_base(ElectricChargeUnit::AmpereHours);
        }

        [[nodiscard]] static constexpr ElectricCharge from_ampere_hours(const un_scalar_t value)
        {
            return ElectricCharge(value, ElectricChargeUnit::AmpereHours);
        }

        [[nodiscard]] constexpr un_scalar_t milliampere_hours() const
        {
            return convert_from_base(ElectricChargeUnit::MilliampereHours);
        }

        [[nodiscard]] static constexpr ElectricCharge from_milliampere_hours(const un_scalar_t value)
        {
            return ElectricCharge(value, ElectricChargeUnit::MilliampereHours);
        }

        [[nodiscard]] constexpr un_scalar_t kiloampere_hours() const
        {
            return convert_from_base(ElectricChargeUnit::KiloampereHours);
        }

        [[nodiscard]] static constexpr ElectricCharge from_kiloampere_hours(const un_scalar_t value)
        {
            return ElectricCharge(value, ElectricChargeUnit::KiloampereHours);
        }

        [[nodiscard]] constexpr un_scalar_t megaampere_hours() const
        {
            return convert_from_base(ElectricChargeUnit::MegaampereHours);
        }

        [[nodiscard]] static constexpr ElectricCharge from_megaampere_hours(const un_scalar_t value)
        {
            return ElectricCharge(value, ElectricChargeUnit::MegaampereHours);
        }

        [[nodiscard]] static constexpr ElectricCharge from_invalid()
        {
            return ElectricCharge(false);
        }
    private:
            
        [[nodiscard]] static constexpr un_scalar_t convert_to_base(un_scalar_t value, ElectricChargeUnit unit)
        {
            switch (unit)
            {

            case ElectricChargeUnit::Coulombs:
                return value;

            case ElectricChargeUnit::Picocoulombs:
                return (value * static_cast<un_scalar_t>(1e-12));

            case ElectricChargeUnit::Nanocoulombs:
                return (value * static_cast<un_scalar_t>(1e-9));

            case ElectricChargeUnit::Microcoulombs:
                return (value * static_cast<un_scalar_t>(1e-6));

            case ElectricChargeUnit::Millicoulombs:
                return (value * static_cast<un_scalar_t>(1e-3));

            case ElectricChargeUnit::Kilocoulombs:
                return (value * static_cast<un_scalar_t>(1e3));

            case ElectricChargeUnit::Megacoulombs:
                return (value * static_cast<un_scalar_t>(1e6));

            case ElectricChargeUnit::AmpereHours:
                return value * static_cast<un_scalar_t>(3600);

            case ElectricChargeUnit::MilliampereHours:
                return (value * static_cast<un_scalar_t>(1e-3)) * static_cast<un_scalar_t>(3600);

            case ElectricChargeUnit::KiloampereHours:
                return (value * static_cast<un_scalar_t>(1e3)) * static_cast<un_scalar_t>(3600);

            case ElectricChargeUnit::MegaampereHours:
                return (value * static_cast<un_scalar_t>(1e6)) * static_cast<un_scalar_t>(3600);

            }

            throw std::invalid_argument("Unknown ElectricCharge unit.");
        }

        [[nodiscard]] constexpr un_scalar_t convert_from_base(const ElectricChargeUnit unit) const
        {
            if(unit == value_unit_type_)
            {
                return value_;
            }
            
            auto base_value = convert_to_base(value_, value_unit_type_);
            
            switch (unit)
            {

            case ElectricChargeUnit::Coulombs:
                return base_value;

            case ElectricChargeUnit::Picocoulombs:
                return (base_value) / static_cast<un_scalar_t>(1e-12);

            case ElectricChargeUnit::Nanocoulombs:
                return (base_value) / static_cast<un_scalar_t>(1e-9);

            case ElectricChargeUnit::Microcoulombs:
                return (base_value) / static_cast<un_scalar_t>(1e-6);

            case ElectricChargeUnit::Millicoulombs:
                return (base_value) / static_cast<un_scalar_t>(1e-3);

            case ElectricChargeUnit::Kilocoulombs:
                return (base_value) / static_cast<un_scalar_t>(1e3);

            case ElectricChargeUnit::Megacoulombs:
                return (base_value) / static_cast<un_scalar_t>(1e6);

            case ElectricChargeUnit::AmpereHours:
                return base_value / static_cast<un_scalar_t>(3600);

            case ElectricChargeUnit::MilliampereHours:
                return (base_value / static_cast<un_scalar_t>(3600)) / static_cast<un_scalar_t>(1e-3);

            case ElectricChargeUnit::KiloampereHours:
                return (base_value / static_cast<un_scalar_t>(3600)) / static_cast<un_scalar_t>(1e3);

            case ElectricChargeUnit::MegaampereHours:
                return (base_value / static_cast<un_scalar_t>(3600)) / static_cast<un_scalar_t>(1e6);

            }

            throw std::invalid_argument("Unknown ElectricCharge unit.");
        }

        un_scalar_t value_;
        ElectricChargeUnit value_unit_type_;       
    };
}
