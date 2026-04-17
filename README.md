# DollmanMute

`DollmanMute` is an ASI mod for `DEATH STRANDING 2 - ON THE BEACH` that mutes Dollman voice lines.

It does not replace game archives or modify packaged assets.

## What It Does

- mutes Dollman voice lines
- keeps ambient/world audio intact
- works as a lightweight native ASI mod

## Requirements

- `DEATH STRANDING 2 - ON THE BEACH`
- no additional tools required for the packaged release

## Installation

1. Copy `DollmanMute.asi` to the game root folder
2. Copy `DollmanMute.ini` to the game root folder
3. Copy `version.dll` to the game root folder

Game root example:

`...\Steam\steamapps\common\DEATH STRANDING 2 - ON THE BEACH\`

## Configuration

`DollmanMute.ini`

- `Enabled=1` enables the mod
- `VerboseLog=0` is recommended for normal use
- `VerboseLog=1` enables extra logging for troubleshooting
- `EnablePlayerVoiceHooks=0` is the recommended default after game updates

## Troubleshooting

If the mod does not seem to load:

1. Make sure the files are in the game root, not inside a subfolder
2. Make sure `version.dll` is present in the game root
3. Launch the game and check whether `DollmanMute.log` appears in the game root

If another mod already installed a working `version.dll`, you usually do not need to replace it.

## After Game Updates

If the game receives an update, check this repository or the latest release page for the newest compatible version of the mod.

## Future Plans

- optional hiding of Dollman-only subtitles without affecting other subtitle lines










List Of Sounds
---------------
Terminal<br />
System menu<br />
Map<br />
Enter facility<br />
Facility scanning<br />
Facility use terminal<br />
Enter private room<br />
Open map<br />
Focusing on icons in map<br />
Zooming in in map<br />
Zooming out in map<br />
getting on a vehicle - bike<br />
getting off a vehicle - bike<br />
normal vehicle speed sound - bike<br />
vehicle boost sound - bike<br />







Tiny Notes
---------------
560195744u bike boost sound
1129849155u	sound of tires moving on the ground
1459707057u getting off bike sound
2927771336u bike retracts after getting off sound
1926977457u getting on bike sound
1502884739u getting on bike (law and order ding ding) sound
2281185168u armor activated on bike mount 1 sound
1409497247u armor activated on bike mount 2 sound
4094584434u armor activated on bike mount 3 sound
1520456362u armor activated on bike mount 4 sound
591947656u armor deactivated on bike unmount 1 sound
1494342936u armor deactivated on bike unmount 2 sound
