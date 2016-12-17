#pragma once

#include "EntryUtils.h"
#include "EntryType.h"

namespace fnx
{
    namespace entry
    {
        class EntryObject : public std::enable_shared_from_this<EntryObject>
        {
        private:
            EntryType  Type_;
            StringType Name_;
            ActionType Action_;
            SharedType Parent_;
            SharedPtrs Children_;

        public:
            EntryObject(StringType const & name, EntryType const type);

        public:
            EntryType const GetType() const;

            StringType const & GetName() const;

            StringType const GetFullName() const;

            SharedType const & GetParent() const;

            void SetParent(SharedType const & parent);

            SharedPtrs const & GetChidren() const;

            SharedType SetAction(ActionType const & action);

            SharedType AddChild(SharedType & child);

            SharedType AddChildren(std::initializer_list<SharedType> list);

            void Execute(VectorArgs const & args) const;

            void Execute() const;

        };


    }
}