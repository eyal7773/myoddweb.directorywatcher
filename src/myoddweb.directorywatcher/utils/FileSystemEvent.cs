﻿//This file is part of Myoddweb.Directorywatcher.
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
using System;
using System.IO;
using myoddweb.directorywatcher.interfaces;

namespace myoddweb.directorywatcher.utils
{
  /// <inheritdoc />
  internal class FileSystemEvent : IFileSystemEvent
  {
    /// <inheritdoc />
    public FileSystemInfo FileSystemInfo { get; }

    /// <inheritdoc />
    public EventAction Action { get; }

    /// <inheritdoc />
    public DateTime DateTimeUtc { get; }

    public FileSystemEvent( IEvent e )
    {
      Action = e.Action;
      FileSystemInfo = new FileInfo( e.Path );
      DateTimeUtc = e.DateTimeUtc;
    }
  }
}
