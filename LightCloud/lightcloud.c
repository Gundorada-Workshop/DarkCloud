//////////////////////////////////////////////////////////////////////////
// Light Cloud
// Dark Cloud's (TM) .HD2&3/DAT repacker
// Copyright(C) 2014  Luciano Ciccariello (Xeeynamo)
// 
// This program is free software; you can redistribute it and / or
// modify it under the terms of the GNU General Public License
// as published by the Free Software Foundation; either version 2
// of the License, or(at your option) any later version.
// 
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.See the
// GNU General Public License for more details.
// 
// You should have received a copy of the GNU General Public License
// along with this program; if not, write to the Free Software
// Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110 - 1301, USA.

#include "../libDarkCloud/hd2.h"
#include "../libDarkCloud/hd3.h"

int main(int argc, char *argv[])
{
	printf("Light Cloud\n"
		"Developed by Luciano Ciccariello (Xeeynamo)\n\n");

	if (argc == 3)
	{
		int hd2Pos;
		int hd3Pos;
		int datPos;

		hd2Pos = CheckExtension(argv[1], ".HD2") == 0 ? 1 :
			CheckExtension(argv[2], ".HD2") == 0 ? 2 : 0;
		hd3Pos = CheckExtension(argv[1], ".HD3") == 0 ? 1 :
			CheckExtension(argv[2], ".HD3") == 0 ? 2 : 0;
		datPos = CheckExtension(argv[1], ".DAT") == 0 ? 1 :
			CheckExtension(argv[2], ".DAT") == 0 ? 2 : 0;

		if (hd3Pos != 0)
		{
			if (hd3Pos != 0 && datPos != 0 && hd3Pos != datPos)
			{
				char exportDir[MAX_PATH];
				GetFilenameWithoutExt(exportDir, sizeof(exportDir), argv[hd3Pos]);
				return Hd3Repack(argv[datPos], argv[hd2Pos], exportDir);
			}
		}
		else
		{
			if (hd2Pos != 0 && datPos != 0 && hd2Pos != datPos)
			{
				char exportDir[MAX_PATH];
				GetFilenameWithoutExt(exportDir, sizeof(exportDir), argv[hd2Pos]);
				return Hd2Repack(argv[datPos], argv[hd2Pos], exportDir);
			}
		}
	}

	printf("Usage:"
		"\tlightcloud <data.dat> (<data.hd3> | <data.hd2)\n"
		"\tlightcloud (<data.hd3> | <data.hd2) <data.dat>\n");
	return 1;
}
