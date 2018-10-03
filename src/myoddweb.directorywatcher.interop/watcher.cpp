//This file is part of Myoddweb.Directorywatcher.
//
//    Myoddweb.Directorywatcher is free software: you can redistribute it and/or modify
//    it under the terms of the GNU General Public License as published by
//    the Free Software Foundation, either version 3 of the License, or
//    (at your option) any later version.
//
//    Myoddweb.Directorywatcher is distributed in the hope that it will be useful,
//    but WITHOUT ANY WARRANTY; without even the implied warranty of
//    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.See the
//    GNU General Public License for more details.
//
//    You should have received a copy of the GNU General Public License
//    along with Myoddweb.Directorywatcher.  If not, see<https://www.gnu.org/licenses/gpl-3.0.en.html>.
#include "stdafx.h"
#include "watcher.h"
#include "core/Importer.h"
#include "core/Request.h"
#include <msclr\marshal_cppstd.h>

namespace myoddweb
{
  namespace directorywatcher
  {
    namespace Interop
    {
      Watcher::Watcher() : _coreWatcher(nullptr)
      {
        _coreWatcher = (Watcher1*)Importer(IID_IWatcher1);
      }

      Watcher::~Watcher()
      {
        this->!Watcher();
      }

      Watcher::!Watcher()
      {
        delete _coreWatcher;
        _coreWatcher = nullptr;
      }

      /**
       * \inheritdoc
       */
      long long Watcher::Add(myoddweb::directorywatcher::interfaces::IRequest^ request)
      {
        auto r = Request();
        r.Path = msclr::interop::marshal_as<std::wstring>(request->Path);
        r.Recursive = request->Recursive;
        return _coreWatcher == nullptr ? -1 : _coreWatcher->Add(r);
      }

      /**
       * \inheritdoc
       */
      bool Watcher::Remove(long long id )
      {
        return _coreWatcher == nullptr ? -1 : _coreWatcher->Remove(id);
      }
    }
  }
}