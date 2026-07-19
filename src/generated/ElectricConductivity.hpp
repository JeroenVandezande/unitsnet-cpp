#pragma once

#include <cstdint>
#include <numbers>
#include <stdexcept>
#include "UnitsNetConfig.h"
#include "UnitsNetBase.h"

namespace unitsnet_cpp
{
    enum class ElectricConductivityUnit : std::uint8_t
    {
        SiemensPerMeter,
        SiemensPerInch,
        SiemensPerFoot,
        SiemensPerCentimeter,
        MicrosiemensPerCentimeter,
        MillisiemensPerCentimeter,
    };

    /// <summary>Electrical conductivity or specific conductance is the reciprocal of electrical resistivity, and measures a material's ability to conduct an electric current.</summary>
    class ElectricConductivity : public UnitsNetBase
    {
    public:
        constexpr explicit ElectricConductivity(
            const un_scalar_t value,
            const ElectricConductivityUnit unit = ElectricConductivityUnit::SiemensPerMeter)
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
           return "ElectricConductivity"; 
        }
        
        [[nodiscard]] constexpr std::string_view unit_name() const noexcept override
        {
            switch (value_unit_type_)
            {

            case ElectricConductivityUnit::SiemensPerMeter:
                return "SiemensPerMeter";

            case ElectricConductivityUnit::SiemensPerInch:
                return "SiemensPerInch";

            case ElectricConductivityUnit::SiemensPerFoot:
                return "SiemensPerFoot";

            case ElectricConductivityUnit::SiemensPerCentimeter:
                return "SiemensPerCentimeter";

            case ElectricConductivityUnit::MicrosiemensPerCentimeter:
                return "MicrosiemensPerCentimeter";

            case ElectricConductivityUnit::MillisiemensPerCentimeter:
                return "MillisiemensPerCentimeter";

            }
            
            return {};
        }
                
        [[nodiscard]] constexpr un_scalar_t base_value() const noexcept
        {
            return convert_to_base(value_, value_unit_type_);    
        }

        [[nodiscard]] constexpr un_scalar_t value(const ElectricConductivityUnit unit) const
        {
            return convert_from_base(unit);
        }

        [[nodiscard]] constexpr ElectricConductivity operator+(const ElectricConductivity& other) const noexcept
        {
            return ElectricConductivity(base_value() + other.base_value());
        }

        [[nodiscard]] constexpr ElectricConductivity operator-(const ElectricConductivity& other)const noexcept
        {
            return ElectricConductivity(base_value() - other.base_value());
        }

        [[nodiscard]] constexpr ElectricConductivity operator*(const un_scalar_t scalar) const noexcept
        {
            return ElectricConductivity(base_value() * scalar);
        }

        [[nodiscard]] constexpr ElectricConductivity operator/(const un_scalar_t scalar) const noexcept
        {
            return ElectricConductivity(base_value() / scalar);
        }

        [[nodiscard]] constexpr bool operator==(const ElectricConductivity& other) const noexcept
        {
            return base_value() == other.base_value();
        }

        [[nodiscard]] constexpr bool operator<(const ElectricConductivity& other) const noexcept
        {
            return base_value() < other.base_value();
        }
        
        [[nodiscard]] constexpr bool operator>(const ElectricConductivity& other) const noexcept
        {
            return base_value() > other.base_value();
        }

        [[nodiscard]] constexpr un_scalar_t siemens_per_meter() const
        {
            return convert_from_base(ElectricConductivityUnit::SiemensPerMeter);
        }

        [[nodiscard]] static constexpr ElectricConductivity from_siemens_per_meter(const un_scalar_t value)
        {
            return ElectricConductivity(value, ElectricConductivityUnit::SiemensPerMeter);
        }

        [[nodiscard]] constexpr un_scalar_t siemens_per_inch() const
        {
            return convert_from_base(ElectricConductivityUnit::SiemensPerInch);
        }

        [[nodiscard]] static constexpr ElectricConductivity from_siemens_per_inch(const un_scalar_t value)
        {
            return ElectricConductivity(value, ElectricConductivityUnit::SiemensPerInch);
        }

        [[nodiscard]] constexpr un_scalar_t siemens_per_foot() const
        {
            return convert_from_base(ElectricConductivityUnit::SiemensPerFoot);
        }

        [[nodiscard]] static constexpr ElectricConductivity from_siemens_per_foot(const un_scalar_t value)
        {
            return ElectricConductivity(value, ElectricConductivityUnit::SiemensPerFoot);
        }

        [[nodiscard]] constexpr un_scalar_t siemens_per_centimeter() const
        {
            return convert_from_base(ElectricConductivityUnit::SiemensPerCentimeter);
        }

        [[nodiscard]] static constexpr ElectricConductivity from_siemens_per_centimeter(const un_scalar_t value)
        {
            return ElectricConductivity(value, ElectricConductivityUnit::SiemensPerCentimeter);
        }

        [[nodiscard]] constexpr un_scalar_t microsiemens_per_centimeter() const
        {
            return convert_from_base(ElectricConductivityUnit::MicrosiemensPerCentimeter);
        }

        [[nodiscard]] static constexpr ElectricConductivity from_microsiemens_per_centimeter(const un_scalar_t value)
        {
            return ElectricConductivity(value, ElectricConductivityUnit::MicrosiemensPerCentimeter);
        }

        [[nodiscard]] constexpr un_scalar_t millisiemens_per_centimeter() const
        {
            return convert_from_base(ElectricConductivityUnit::MillisiemensPerCentimeter);
        }

        [[nodiscard]] static constexpr ElectricConductivity from_millisiemens_per_centimeter(const un_scalar_t value)
        {
            return ElectricConductivity(value, ElectricConductivityUnit::MillisiemensPerCentimeter);
        }

        [[nodiscard]] static constexpr ElectricConductivity from_invalid()
        {
            return ElectricConductivity(false);
        }
    private:
            
        [[nodiscard]] static constexpr un_scalar_t convert_to_base(un_scalar_t value, ElectricConductivityUnit unit)
        {
            switch (unit)
            {

            case ElectricConductivityUnit::SiemensPerMeter:
                return value;

            case ElectricConductivityUnit::SiemensPerInch:
                return value / static_cast<un_scalar_t>(2.54e-2);

            case ElectricConductivityUnit::SiemensPerFoot:
                return value / static_cast<un_scalar_t>(0.3048);

            case ElectricConductivityUnit::SiemensPerCentimeter:
                return value * static_cast<un_scalar_t>(1e2);

            case ElectricConductivityUnit::MicrosiemensPerCentimeter:
                return (value * static_cast<un_scalar_t>(1e-6)) * static_cast<un_scalar_t>(1e2);

            case ElectricConductivityUnit::MillisiemensPerCentimeter:
                return (value * static_cast<un_scalar_t>(1e-3)) * static_cast<un_scalar_t>(1e2);

            }

            throw std::invalid_argument("Unknown ElectricConductivity unit.");
        }

        [[nodiscard]] constexpr un_scalar_t convert_from_base(const ElectricConductivityUnit unit) const
        {
            if(unit == value_unit_type_)
            {
                return value_;
            }
            
            auto base_value = convert_to_base(value_, value_unit_type_);
            
            switch (unit)
            {

            case ElectricConductivityUnit::SiemensPerMeter:
                return base_value;

            case ElectricConductivityUnit::SiemensPerInch:
                return base_value * static_cast<un_scalar_t>(2.54e-2);

            case ElectricConductivityUnit::SiemensPerFoot:
                return base_value * static_cast<un_scalar_t>(0.3048);

            case ElectricConductivityUnit::SiemensPerCentimeter:
                return base_value / static_cast<un_scalar_t>(1e2);

            case ElectricConductivityUnit::MicrosiemensPerCentimeter:
                return (base_value / static_cast<un_scalar_t>(1e2)) / static_cast<un_scalar_t>(1e-6);

            case ElectricConductivityUnit::MillisiemensPerCentimeter:
                return (base_value / static_cast<un_scalar_t>(1e2)) / static_cast<un_scalar_t>(1e-3);

            }

            throw std::invalid_argument("Unknown ElectricConductivity unit.");
        }

        un_scalar_t value_;
        ElectricConductivityUnit value_unit_type_;       
    };
}
