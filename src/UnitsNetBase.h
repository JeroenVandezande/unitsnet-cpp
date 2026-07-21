#pragma once

namespace unitsnet_cpp
{
    class UnitsNetBase
    {
    public:
        virtual ~UnitsNetBase() = default;

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
            return !_isInvalid;
        }

    protected:

        bool _isInvalid = false;
    };

}
