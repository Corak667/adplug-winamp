/*
  Copyright (c) 1999 - 2006 Simon Peter <dn.tlp@gmx.net>
  Copyright (c) 2002 Nikita V. Kalaganov <riven@ok.ru>

  This library is free software; you can redistribute it and/or
  modify it under the terms of the GNU Lesser General Public
  License as published by the Free Software Foundation; either
  version 2.1 of the License, or (at your option) any later version.

  This library is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
  Lesser General Public License for more details.

  You should have received a copy of the GNU Lesser General Public
  License along with this library; if not, write to the Free Software
  Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
*/

// Get rid of VC compiler limitation warnings
#ifdef _MSC_VER
#	pragma warning(disable: 4786)
#endif
#ifndef max
#  define max(a,b) (((a) > (b)) ? (a) : (b))
#endif

// We use some special functions of Internet Explorer 3.x
#define _WIN32_IE	0x0300

// windows
#include <windows.h>
#include <windowsx.h>
#include <commctrl.h>
#include <shlobj.h>
#include <shlwapi.h>
#include <winioctl.h>

// adplug
#include <adplug/adplug.h>
#include <adplug/diskopl.h>
#include <adplug/emuopl.h>
#include <adplug/kemuopl.h>
#include <adplug/realopl.h>
#include <adplug/silentopl.h>
#include <adplug/surroundopl.h>
#include <adplug/wemuopl.h>
#include <adplug/nemuopl.h>

// stl
#include <string>
#include <vector>

using namespace std;

// winamp
#include "frontend.h"
#include "in2.h"

#define WM_WA_MPEG_EOF WM_USER+2

// in_adlib
#include "config.h"
#include "filetypes.h"
#include "player.h"
#include "dlg_about.h"
#include "dlg_config.h"
#include "dlg_info.h"
#include "gui_link.h"
#include "gui_tip.h"

#include "resource.h"
#include "version.h"

#define WM_UPDATE     WM_USER+1
#define WM_UPDATE_ALL WM_USER+2

#define MAX_EMULATORS 4

struct TEmulInfo {
	t_output emul;
	char * name;
	char * description;
	bool s_multi;       /* emulator allows multiple instances */
	bool s_mono;        /* emulator supports mono output */
	bool s_8bit;        /* emulator supports 8-bit PCM output */
};
